# 3. Dynamic Memory Allocation (DMA)

## 3.1 Why Dynamic Memory?
Arrays declared normally (`int arr[10];`) have a **fixed size known at compile time**
and live on the stack. Dynamic memory lets you:
- Allocate exactly the amount of memory needed at **runtime**.
- Create data structures whose size is not known until the program runs (based on
  user input, file contents, etc.).
- Allocate memory that outlives the function that created it (heap memory persists
  until explicitly freed).

## 3.2 `<stdlib.h>` Allocation Functions

### malloc — allocate uninitialized memory
```c
int *arr = (int *)malloc(5 * sizeof(int));
if (arr == NULL) {
    // allocation failed — always check!
    exit(1);
}
```
- Returns a `void *`, cast to the desired pointer type (in C, the cast is optional
  but common practice/required by some course conventions).
- Memory content is **garbage** (uninitialized).

### calloc — allocate and zero-initialize
```c
int *arr = (int *)calloc(5, sizeof(int));  // 5 elements, all set to 0
```
- Takes (number of elements, size of each element) — safer against integer overflow
  than `malloc(n * size)`.

### realloc — resize existing allocation
```c
arr = (int *)realloc(arr, 10 * sizeof(int));
```
- May move the block to a new address if it can't grow in place; returns the new
  pointer (or NULL on failure — always assign to a temp variable first!).

```c
int *temp = realloc(arr, newSize);
if (temp == NULL) {
    // realloc failed, original 'arr' is still valid and must be freed eventually
} else {
    arr = temp;
}
```

### free — release memory
```c
free(arr);
arr = NULL;   // good practice: avoid dangling pointer
```

## 3.3 Stack vs Heap
| | Stack | Heap |
|---|---|---|
| Managed by | compiler automatically | programmer manually (`malloc`/`free`) |
| Lifetime | ends when function returns | lives until `free()`d |
| Speed | very fast | slower (bookkeeping overhead) |
| Size | limited (can overflow) | much larger, limited by system memory |
| Fragmentation | none | can fragment over time |

## 3.4 Common Bugs
- **Memory leak** — allocated memory never freed; the pointer goes out of scope and
  the memory becomes unreachable.
- **Dangling pointer** — using a pointer after its memory has been freed.
- **Double free** — calling `free()` twice on the same address (undefined behavior,
  often crashes).
- **Buffer overflow** — writing past the allocated size.

```c
int *p = malloc(sizeof(int) * 5);
free(p);
p[0] = 10;     // BUG: use-after-free
free(p);        // BUG: double free
```

## 3.5 Dynamically Allocated 1D Arrays
```c
int n;
scanf("%d", &n);
int *arr = malloc(n * sizeof(int));
for (int i = 0; i < n; i++)
    arr[i] = i * 2;
// ... use arr ...
free(arr);
```

## 3.6 Dynamically Allocated 2D Arrays (Matrices)
There are two common approaches:

### Approach A: Array of Pointers ("jagged" array)
```c
int rows = 3, cols = 4;
int **matrix = malloc(rows * sizeof(int *));
for (int i = 0; i < rows; i++)
    matrix[i] = malloc(cols * sizeof(int));

matrix[1][2] = 99;    // access like a normal 2D array

// Freeing — must free each row THEN the array of pointers
for (int i = 0; i < rows; i++)
    free(matrix[i]);
free(matrix);
```
- Rows can have different lengths ("jagged arrays") — flexible but has extra pointer
  overhead and rows aren't guaranteed contiguous in memory.

### Approach B: Single Contiguous Block
```c
int *matrix = malloc(rows * cols * sizeof(int));
// access element (i, j) via manual index calculation:
matrix[i * cols + j] = 99;
free(matrix);   // single free call
```
- More cache-friendly (contiguous memory), only one `malloc`/`free` call, but requires
  manual index math and all rows must be the same length.

## 3.7 Growing Arrays Dynamically (Common Pattern)
```c
int capacity = 4, size = 0;
int *arr = malloc(capacity * sizeof(int));

void addElement(int **arr, int *size, int *capacity, int value) {
    if (*size == *capacity) {
        *capacity *= 2;
        int *temp = realloc(*arr, *capacity * sizeof(int));
        if (temp == NULL) return; // handle failure
        *arr = temp;
    }
    (*arr)[(*size)++] = value;
}
```
This is the basic idea behind how a dynamic array / vector grows.

## 3.8 Checklist for Every malloc
1. Did I check the return value for `NULL`?
2. Did I allocate the correct number of bytes (`n * sizeof(type)`, not `n`)?
3. Do I free every allocation exactly once?
4. Am I freeing in the right order (inner allocations before outer ones)?
5. Did I set pointers to `NULL` after freeing?
