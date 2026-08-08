# C Memory Maps & Valgrind Analysis

This document provides a step-by-step analysis of memory state changes across four C programs: `stack_example.c`, `heap_example.c`, `aliasing_example.c`, and `crash_example.c`. It explicitly tracks Stack frames, Heap allocations, variable lifetimes, and pointer aliasing, and includes documented corrections for common AI memory reasoning errors.

---

## 1. `stack_example.c` — Stack Frames and Recursion

### Memory Map & Lifecycle
* **Stack Memory:** Each recursive call to `walk_stack()` allocates a new Stack frame containing local variables (`marker`), which in turn calls `dump_frame()` creating another Stack frame containing `local_int`, `local_buf`, and `p_local`.
* **Heap Memory:** **0 bytes.** No dynamic allocation (`malloc`/`calloc`) is used.
* **Stack Growth & Lifetimes:**
  * As recursion deepens (`depth=0` $\rightarrow$ `depth=3`), stack addresses decrease (e.g., `&local_int` drops from `0x1fff000224` at `depth=0` to `0x1fff000194` at `depth=3`), showing downward stack growth.
  * When `walk_stack()` returns, its stack frame is popped off and destroyed. The variables within that frame reach the end of their lifetime.

### Valgrind Verification
```text
HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks
total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated

All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
