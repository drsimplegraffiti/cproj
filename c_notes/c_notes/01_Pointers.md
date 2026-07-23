# 1. Pointers

## 1.1 What is a Pointer?
A pointer is a variable that stores the **memory address** of another variable, rather
than a value directly.

```c
int x = 10;
int *p = &x;   // p holds the address of x
```

- `&x` — "address of" operator, gives the address of `x`.
- `*p` — "dereference" operator, gives the value stored at the address `p` holds.
- The type of the pointer (`int *`, `char *`, etc.) tells the compiler how many bytes
  to read/write and how to interpret pointer arithmetic.

```c
printf("%d\n", x);   // 10
printf("%d\n", *p);  // 10 (value at address p)
printf("%p\n", (void*)p); // the address itself
*p = 20;             // changes x to 20, because p points to x
```

## 1.2 Declaring Pointers
```c
int *p1;        // pointer to int
char *p2;       // pointer to char
double *p3;     // pointer to double
int **pp;       // pointer to pointer to int
```
The `*` binds to the variable name, not the type — `int* a, b;` makes `a` a pointer
but `b` a plain `int`. Prefer `int *a, *b;` for clarity.

## 1.3 NULL Pointers and Uninitialized Pointers
- An uninitialized pointer holds a **garbage address**. Dereferencing it is undefined
  behavior (can crash or corrupt memory).
- Always initialize pointers, e.g. `int *p = NULL;`
- Check before use: `if (p != NULL) { ... }`
- Dereferencing `NULL` (`*p` when `p == NULL`) causes a segmentation fault.

## 1.4 Pointer Arithmetic
Pointer arithmetic is scaled by the size of the pointed-to type.

```c
int arr[5] = {10, 20, 30, 40, 50};
int *p = arr;       // arr decays to pointer to arr[0]

p + 1;              // address of arr[1], NOT p's address + 1 byte
                     // it moves forward sizeof(int) bytes (usually 4)
*(p + 2);            // 30, same as arr[2]
p++;                 // now points to arr[1]
```

Rules:
- `p + n` moves the pointer by `n * sizeof(*p)` bytes.
- `p2 - p1` (two pointers into the same array) gives the number of elements between them.
- You can compare pointers (`<`, `>`, `==`) only when they point into the same array.
- Adding two pointers together is illegal; you may add an integer to a pointer.

## 1.5 `sizeof` Operator
`sizeof` is a **compile-time** operator (not a function) that returns the size, in
bytes, of a type or variable, as a `size_t` (unsigned integer).

```c
sizeof(int);        // typically 4
sizeof(char);        // always 1
sizeof(double);      // typically 8
sizeof(int *);       // size of a pointer itself (8 on 64-bit systems, 4 on 32-bit)

int arr[10];
sizeof(arr);         // 40 (10 * 4) — size of WHOLE array, only works if arr
                     // hasn't decayed to a pointer (e.g., inside the same scope
                     // it was declared, not after being passed to a function)
sizeof(arr) / sizeof(arr[0]);  // classic idiom to get number of elements = 10
```

**Common trap:** once an array is passed to a function, it decays into a pointer, and
`sizeof` inside that function returns the pointer's size, not the array's size.

```c
void f(int arr[]) {
    printf("%zu\n", sizeof(arr)); // size of a pointer (e.g. 8), NOT 40!
}
```

## 1.6 Pointers and Arrays
- An array name, when used in most expressions, **decays** into a pointer to its
  first element.
- `arr[i]` is defined as `*(arr + i)` — array indexing is literally pointer arithmetic.
- Because of this, `arr[i]` and `i[arr]` are equivalent (rarely used, but shows the
  equivalence).

```c
int arr[3] = {1,2,3};
int *p = arr;      // valid: arr decays to &arr[0]
p[1];              // 2, pointer can also use [] syntax
```

**Key differences between arrays and pointers:**
| | Array | Pointer |
|---|---|---|
| Memory | allocated for all elements | allocated only for the address |
| `sizeof` | size of entire block | size of the pointer (e.g. 8 bytes) |
| Reassignment | cannot point elsewhere | can be reassigned to any address |

## 1.7 Pointers to Pointers
```c
int x = 5;
int *p = &x;
int **pp = &p;

**pp;     // 5 (dereference twice)
*pp;      // the address stored in p
```
Common uses: dynamically allocated 2D arrays, modifying a pointer inside a function
(passing `int **` so the function can change what the caller's pointer points to),
arrays of strings (`char **argv`).

## 1.8 Pointers and Function Parameters (Pass by Reference)
C is strictly pass-by-value — but passing a **pointer** lets a function modify the
caller's variable, simulating pass-by-reference.

```c
void increment(int *p) {
    (*p)++;
}
int main(void) {
    int x = 5;
    increment(&x);   // x becomes 6
}
```

To let a function change a pointer itself (not just what it points to), pass a
pointer to a pointer:

```c
void allocate(int **p) {
    *p = malloc(sizeof(int));
    **p = 42;
}
```

## 1.9 `const` with Pointers
```c
const int *p;        // pointer to const int — can't change *p, can reassign p
int * const p;        // const pointer to int — can change *p, can't reassign p
const int * const p;  // both are constant
```
Read right-to-left starting from the variable name for clarity.

## 1.10 Common Pointer Pitfalls
- **Dangling pointer:** pointer that still holds the address of memory that was freed
  or went out of scope (e.g., returning the address of a local variable).
- **Memory leak:** losing the only pointer to allocated memory before freeing it.
- **Wild pointer:** pointer never initialized.
- **Double free:** calling `free()` twice on the same pointer.
- Always set a pointer to `NULL` after `free()`ing it to avoid accidental reuse.

```c
int *danger(void) {
    int local = 10;
    return &local;   // BUG: local's storage is gone after the function returns
}
```

## 1.11 Void Pointers
`void *` is a generic pointer that can hold the address of any type, but **cannot be
dereferenced directly** — it must be cast first.

```c
void *generic;
int x = 5;
generic = &x;
printf("%d\n", *(int *)generic);
```
Used heavily in generic functions like `malloc`, `memcpy`, `qsort`.
