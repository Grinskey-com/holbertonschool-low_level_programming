# AI Memory Visualizer — Memory Maps

## `stack_example.c`

`main()` → `walk_stack(0,3)`, recursing while `depth < 3`, calling `dump_frame("enter"|"exit", depth)` each time. All variables (`marker`, `local_int`, `local_buf`, `p_local`) are **stack-only** — zero heap activity.

**Real addresses confirm:**
- Stack grows **downward**: `&marker` goes `...afb4 → ...af74 → ...af34 → ...aef4` as depth increases.
- `&marker` is identical at "enter" and "exit" for a given depth — correct, since that `walk_stack` frame stays alive across its own recursive call underneath it.
- `&local_int` is also identical between "enter" and "exit" calls at the same depth — but this does **not** mean it's the same variable (see AI critique below).

**Lifetimes:**
- `marker` lives for the entire `walk_stack` call, spanning the recursive call inside it.
- `local_int` / `local_buf` / `p_local` live only for **one call** to `dump_frame` — 8 independent, non-overlapping lifetimes total (2 per depth × 4 depths).
- `p_local = &local_int` is a pointer to a stack local — only meaningful within that one `dump_frame` call.

## `aliasing_example.c`

| Step | State |
|---|---|
| `make_numbers(5)` | heap block allocated; local `arr` (stack) holds it temporarily |
| `a = make_numbers(5)` | `a` (stack, in `main`) now holds the heap address |
| `b = a` | `b` aliases `a` — same heap address, two stack variables |
| `free(a)` | block's lifetime ends **for both** `a` and `b` |
| `b[2]`, `b[3]` used | `b` itself is valid stack memory; the heap memory it points to is not — use-after-free |

**Ownership:** the block belongs to whoever holds the original pointer (`a`). `b` is an alias, not a co-owner.

---

## AI Usage

**Prompt:** *"Here's a recursive program with printed addresses at each depth. Explain the stack frame lifetimes."*

**AI's response:** *"Each call gets its own frame; addresses decrease with depth (normal). Since `local_int`'s address is identical at 'enter' and 'exit', this shows `local_int` persists across the recursive call in between — its value is preserved in that stack slot the whole time."*

**Critique — the persistence claim is wrong:**
`dump_frame` **returns** between "enter" and "exit" at a given depth. `local_int` from "enter" is fully destroyed on return — it does not survive. The "exit" call creates a **brand-new** `local_int`, which happens to reuse the same address (because nothing else disturbs that part of the stack in between) and happens to compute the same value (`100 + depth`, same formula both times). Same address ≠ same variable — it's two independent variables with non-overlapping lifetimes that coincidentally look identical.

**Corrected:** Address reuse across separate calls reflects symmetric stack usage, not variable persistence. Each `dump_frame` call has its own independent locals, scoped strictly to that call.
