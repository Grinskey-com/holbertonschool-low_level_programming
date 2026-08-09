# Valgrind & AI Memory Tracer — Analysis

## `aliasing_example.c`

**Setup:** `make_numbers()` heap-allocates a 5-int array, returns it to `a`. `main` does `b = a;` — `b` and `a` alias the same block. `free(a)` runs once; `b` is then used afterward.

| # | Line | Type | Offset | Why |
|---|---|---|---|---|
| 1 | 42 (`b[2]`) | Invalid read (UAF) | 8 bytes in | `free(a)` at line 38 ends the block's lifetime for **every** alias, including `b`. Reading `b[2]` accesses memory whose lifetime is over. |
| 2 | 44 (`b[3] = 1234`) | Invalid write (UAF) | 12 bytes in | Same cause, worse severity — writing into freed memory can silently corrupt a future unrelated `malloc()` if the allocator reissues this block. |
| 3 | 45 (`b[3]`) | Invalid read (UAF) | 12 bytes in | Reads back the illegal write from #2; same root cause. |

**No leak:** `free()` was called exactly once for the one allocation — ownership was released correctly. The bug is *continued use after a correct free*, not a missing free.

**Ownership:** the block belongs to whoever holds the original pointer (`a`). `b` is an alias, not a co-owner — freeing through `a` invalidates `b` too, since they're the same address.

---

## `heap_example.c`

**Setup:** `person_new()` does 2 allocations per `Person` — the struct, and a separate name buffer. `bob` is freed correctly (`free(bob->name); free(bob);`). `alice` is freed via `person_free_partial()`, which only frees the struct.

**Leak:**
```
6 bytes in 1 blocks are definitely lost
  by person_new (heap_example.c:21)
  by main (heap_example.c:51)
```
- **Object:** `alice->name` (6 bytes = "Alice" + `\0`)
- **Why "definitely lost":** `person_free_partial(alice)` frees the struct without reading/freeing `alice->name` first. Once the struct is gone, no pointer anywhere in the program can reach that buffer again.
- **Root cause:** `person_free_partial()` only releases the struct's ownership, not the separate string allocation it points to — two independent lifetimes, only one respected.

**Sanity check:** 5 allocs (alice struct, alice name, bob struct, bob name, stdio buffer). 4 frees (alice struct, bob name, bob struct, stdio auto-release at exit). The 5th allocation — `alice->name` — is the only one never freed, matching the 6-byte leak.

---

## AI Usage

**Prompt:** *"I ran Valgrind on this program and got 3 errors, all 'Invalid read/write... free'd'. Here's the code. What's causing these?"*

**AI's response:** *"These happen because `b` is a dangling pointer — after `free(a)`, `b` still holds the old address. Fix: set `b = NULL` after freeing, or avoid using `b` after the free."*

**Critique — incomplete, not wrong:**
- Never names the *aliasing* relationship (`b = a`) as the root cause — makes it sound like `b` is independently stale, not that freeing through `a` poisoned every pointer sharing that address.
- Treats all 3 errors as one bug; doesn't distinguish the write (line 44) as more dangerous than the reads.
- "Set b to NULL" only patches this one alias — doesn't address the general problem of tracking ownership across aliases.

**Corrected:** All 3 errors trace to one cause — `b = a` created an alias, and `free(a)` ended the block's lifetime for both pointers simultaneously.
