# 9. Debugging Techniques & Practice Guide

## 9.1 Compiling with Warnings On
Always compile with warnings enabled — most bugs show up as warnings before they
become crashes:
```bash
gcc -Wall -Wextra -g -std=c11 program.c -o program
```
- `-Wall -Wextra`: enable most useful warnings.
- `-g`: include debug symbols (needed for `gdb`).

## 9.2 Using a Debugger (GDB)
```bash
gdb ./program
(gdb) break main            # set a breakpoint at main
(gdb) run                    # start the program
(gdb) next                   # step over (execute line, don't enter functions)
(gdb) step                   # step into a function call
(gdb) print x                # inspect a variable's value
(gdb) print *ptr              # dereference and print
(gdb) backtrace               # show the call stack (great for finding a crash's origin)
(gdb) continue                # resume until next breakpoint
```
Debugging a crash (segfault): run in `gdb`, let it crash, then run `backtrace` to see
exactly which line and call chain caused it.

## 9.3 Detecting Memory Errors: Valgrind
```bash
valgrind --leak-check=full ./program
```
Reports memory leaks, invalid reads/writes (buffer overruns), use of uninitialized
memory, and double frees — invaluable when working with pointers and dynamic memory.

## 9.4 Common Bugs Checklist
| Symptom | Likely Cause |
|---|---|
| Segmentation fault | dereferencing NULL/uninitialized/dangling pointer, out-of-bounds array access, stack overflow (deep/infinite recursion) |
| Garbage values printed | uninitialized variable, `malloc` without initialization, reading past array bounds |
| Program hangs | infinite loop, missing loop increment, recursion without proper base case |
| Wrong output only sometimes | uninitialized memory (undefined behavior can appear to "work" by luck) |
| Off-by-one errors | `<=` vs `<` in loop conditions, array size vs last valid index confusion |
| Memory leak (valgrind reports) | missing `free()`, losing the only pointer to allocated memory before freeing |
| Data corruption after `free` | use-after-free, double free, writing past allocated bounds |

## 9.5 Defensive Programming Habits
- Initialize every variable and pointer at declaration.
- Check every `malloc`/`calloc`/`realloc`/`fopen` return value.
- Match every `malloc` with exactly one `free`.
- Use `const` wherever a value/pointer shouldn't change — lets the compiler catch
  mistakes.
- Keep functions small and single-purpose — easier to test and debug in isolation.
- Add `assert()` statements (from `<assert.h>`) to catch invalid states early:
```c
#include <assert.h>
assert(size > 0);   // program aborts with a clear message if this is false
```

## 9.6 General Study/Practice Strategy
1. **Master pointers first** — nearly everything else in C (arrays, strings, dynamic
   memory, structs passed efficiently, function callbacks) builds on understanding
   memory addresses and dereferencing.
2. **Draw memory diagrams** — box-and-arrow diagrams of stack/heap variables and what
   they point to are the single best debugging/learning tool for pointer bugs.
3. **Reimplement standard library functions** (`strlen`, `strcpy`, `strcmp`, a simple
   `malloc`-based dynamic array) — this cements how pointers and memory really work.
4. **Read compiler warnings as if they were errors** — treat every warning as a bug
   until proven otherwise.
5. **Trace code by hand** before running it, especially for pointer arithmetic and
   recursive functions — predicting the output and then checking is the fastest way
   to fix wrong mental models.
6. **Practice explaining `sizeof`, pointer decay, and struct padding out loud** — these
   three topics are the most common sources of subtle bugs and exam questions in a
   course like this one.

## 9.7 Suggested Practice Problems (by Topic)
- **Pointers:** write functions that swap variables, that return multiple values via
  output parameters, and that modify an array in place.
- **Arrays/Strings:** reimplement `strlen`, `strcpy`, `strcat`, `strstr`; reverse a
  string in place; check if a string is a palindrome.
- **Dynamic Memory:** build a dynamic array that grows with `realloc`; build and free
  a dynamically allocated 2D matrix both ways (array-of-pointers and contiguous
  block).
- **Structs:** build a small "database" of records (e.g., students/employees) with
  add/search/sort/print operations, backed by a dynamically allocated array.
- **Files:** save/load that same database to a binary file; implement updating a
  single record in place using `fseek`.
- **Function Pointers:** implement a small calculator dispatch table, or a generic
  `sortArray(arr, n, compareFunc)`.
- **Bitwise:** implement set/clear/toggle/check-bit helper functions; count set bits;
  pack several boolean flags into a single byte using bit fields.
