## Program under test: `programs/crash_example.c`

Commands run:
```
./crash_example
echo "exit code: $?"
valgrind ./crash_example
```

Note: line numbers below are taken from Valgrind's output against the actual
file on disk (confirmed with `cat -n crash_example.c`), not from a
re-pasted/re-typed copy of the source, since the two can drift by a few
lines.

---

## 1. Description of the crash

Running the program prints:
```
crash_example: deterministic NULL dereference (segmentation fault)
  requesting n=0
Segmentation fault (core dumped)
```
and exits with code `139` (128 + signal 11 = SIGSEGV).

Valgrind confirms the same failure with a precise diagnosis:
```
Invalid write of size 4
   at 0x10928A: main (crash_example.c:32)
Address 0x0 is not stack'd, malloc'd or (recently) free'd
...
Access not within mapped region at address 0x0
```

The crash is a **NULL pointer dereference on a write**, occurring at
`main()` line 32 (`nums[0] = 42;`).

---

## 2. Root cause analysis

Call chain, in execution order:

1. `main()` sets `int n = 0;` (line 20).
2. `main()` calls `nums = allocate_numbers(n);` (line 23), i.e.
   `allocate_numbers(0)`.
3. Inside `allocate_numbers()`, the guard `if (n <= 0) return NULL;`
   (line 8) is true for `n == 0`, so the function returns `NULL`
   **immediately**. The `malloc()` call on line 9 is never reached and no
   heap allocation for the array ever happens.
4. Back in `main()`, `nums` is now `NULL`. There is no check on the return
   value of `allocate_numbers()` before it is used.
5. `nums[0] = 42;` (line 32) is equivalent to `*(nums + 0) = 42;`, which
   attempts to write 4 bytes starting at address `0x0`.
6. Address `0x0` is never mapped into the process's address space (it is
   deliberately kept unmapped by the OS specifically so that NULL
   dereferences fault instead of silently corrupting memory). The CPU/MMU
   raises a hardware page fault, the kernel delivers `SIGSEGV` to the
   process, and the process terminates.

**Root cause:** a function that can legitimately return `NULL`
(`allocate_numbers`) has its return value used without a NULL check.

---

## 3. Why this specific memory access is invalid

This is **not** a stack or heap memory violation in the usual sense (no
use-after-free, no out-of-bounds index into a real allocation). The pointer
`nums` never pointed at valid stack or heap memory in this run at all — it
holds the value `0` (NULL), which is not an address of anything.

- **Category of undefined behavior:** NULL pointer dereference (writing
  through a null pointer).
- **Memory region involved:** Neither stack nor heap — address `0x0` is
  outside every mapped region of the process. Valgrind states this
  explicitly: `Address 0x0 is not stack'd, malloc'd or (recently) free'd`.
- **Why it's deterministic, not random:** `n = 0` is a hard-coded literal
  in `main()`. Every single run takes the exact same branch
  (`n <= 0` → return `NULL`), so `nums` is NULL on every run, and the crash
  happens at the same line every time. There is no timing dependency, no
  uninitialized value, and no reliance on whatever garbage happened to be
  on the stack — this is 100% reproducible by static reading of the code,
  which is the point of the exercise.

---

## 4. The heap allocation shown by Valgrind (and why it's a red herring)

Valgrind's heap summary shows:
```
HEAP SUMMARY:
    in use at exit: 1,024 bytes in 1 blocks
    total heap usage: 1 allocs, 0 frees, 1,024 bytes allocated
```

This looks like it could be the array from `allocate_numbers()`, but it
is not. Given the causal chain above, `allocate_numbers(0)` returns before
ever calling `malloc()`. This 1,024-byte allocation is `still reachable`
(not leaked) and comes from glibc's internal buffering for `stdio` — it is
allocated automatically the first time `printf()` is called, and is
released automatically at process exit / by the OS. It is unrelated to the
crash and should not be cited as evidence of a leak or of the array being
allocated.

---

## 5. AI Usage Documentation

### Prompt given to the AI

> "This C program segfaults. Here's the code and the Valgrind output.
> `Invalid write of size 4, Address 0x0 is not stack'd, malloc'd or
> (recently) free'd`, and the heap summary shows 1 alloc, 0 frees, 1024
> bytes. What's causing the crash, and how would I fix it?"

### AI's response (as given)

> "The crash is a classic NULL pointer dereference — `nums` is NULL when
> you write to `nums[0]`. Looking at the heap summary, it seems your
> `allocate_numbers` function successfully allocated 1024 bytes but never
> freed it, which combined with the NULL write suggests the array pointer
> was allocated but something went wrong to make `nums` NULL by the time
> you use it, possibly an issue with how the return value is being
> assigned or copied. To fix it, add a NULL check after calling
> `allocate_numbers`, and also make sure to call `free()` to avoid leaking
> the 1024 bytes."

### Critique of the AI's response

The NULL-check fix suggestion is correct, but the AI's *reasoning about the
heap summary is wrong*, and this matters for the assignment:

1. **The AI incorrectly attributes the 1,024-byte allocation to
   `allocate_numbers()`.** Tracing the actual control flow shows
   `allocate_numbers(0)` returns `NULL` at the very first `if` check and
   never reaches `malloc()`. The 1,024-byte block is glibc's internal
   `stdio` buffer from the `printf()` calls, not the requested `int` array.
   The AI pattern-matched "there's a malloc in this function and a heap
   allocation in the summary" without checking whether that specific
   function's `malloc()` line was actually reachable for `n = 0`.
2. **The AI invents a leak that doesn't exist**, telling me to add
   `free()` "to avoid leaking the 1024 bytes." Valgrind's own leak summary
   would show this memory as `still reachable`, not `definitely lost` —
   it is not a leak in the sense this assignment cares about, and no
   `free()` call in my code would even target it, since I never have a
   pointer to glibc's internal buffer.
3. **The AI is correct about the core mechanism** (NULL pointer dereference
   caused by an unchecked return value) and the primary fix (add a NULL
   check). That part required no correction.

### Corrected explanation

The crash is a deterministic NULL pointer dereference: `allocate_numbers(0)`
returns `NULL` before ever allocating memory, `main()` doesn't check for
that, and `nums[0] = 42;` writes to address `0x0`, which is unmapped in the
process. The 1,024-byte block Valgrind reports is unrelated `stdio`
buffering, not a leaked array, and no `free()`-related fix is needed or
possible for it.

---

## 6. Suggested fix (optional, clearly labeled)

**Suggested fix:** check the return value of `allocate_numbers()` before
using it, and handle the `n <= 0` case explicitly in `main()`:

```c
nums = allocate_numbers(n);
if (nums == NULL)
{
    fprintf(stderr, "allocate_numbers failed for n=%d\n", n);
    return 1;
}
nums[0] = 42;
```

This does not change the fact that `allocate_numbers(0)` legitimately
returns `NULL` by design (the `n <= 0` guard is intentional, not itself a
bug) — the actual defect is that the caller in `main()` never checked for
that documented failure case.
