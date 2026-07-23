# 2. Arrays, Strings & the Standard String Library

## 2.1 Arrays Recap
```c
int arr[5] = {1, 2, 3, 4, 5};
int matrix[3][4];     // 2D array, 3 rows, 4 columns
```
- Arrays are stored contiguously in memory.
- Array indices start at 0; last valid index is `size - 1`.
- C does **not** perform bounds checking — reading/writing outside the array is
  undefined behavior (a very common source of bugs).

## 2.2 Arrays as Function Parameters
When an array is passed to a function, only a pointer to its first element is passed
(it decays). Because of this, the function has no way to know the array's length —
you must pass the size explicitly as another parameter.

```c
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
```

## 2.3 Swapping Elements (Classic Exercise)
Swapping needs pointers because C is pass-by-value:

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
swap(&arr[0], &arr[1]);
```

Reversing an array in place (two-pointer technique):
```c
void reverse(int arr[], int size) {
    int i = 0, j = size - 1;
    while (i < j) {
        swap(&arr[i], &arr[j]);
        i++; j--;
    }
}
```

## 2.4 Strings in C
A C string is just a `char` array terminated by a null character `'\0'`.

```c
char s1[] = "Hello";       // 6 bytes: H e l l o \0
char s2[10] = "Hi";        // remaining bytes are 0
char *s3 = "Hello";        // pointer to a string literal (read-only!)
```

**Important:** `s3` above points to a literal stored in read-only memory. Attempting
`s3[0] = 'h';` is undefined behavior. Only `char arr[]` copies are writable.

## 2.5 Common String Operations Manually
```c
int my_strlen(char *s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

void my_strcpy(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int my_strcmp(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return a[i] - b[i];
        i++;
    }
    return a[i] - b[i];  // handles different lengths
}
```

## 2.6 `<string.h>` Library Functions
| Function | Purpose |
|---|---|
| `strlen(s)` | length of string, excluding `\0` |
| `strcpy(dest, src)` | copies src into dest (unsafe: no bounds check) |
| `strncpy(dest, src, n)` | copies at most n chars (safer, but may not null-terminate) |
| `strcat(dest, src)` | appends src to end of dest |
| `strncat(dest, src, n)` | appends at most n chars |
| `strcmp(a, b)` | lexicographic comparison, 0 if equal |
| `strncmp(a, b, n)` | compares first n characters |
| `strchr(s, c)` | pointer to first occurrence of char c, or NULL |
| `strrchr(s, c)` | pointer to last occurrence of char c |
| `strstr(a, b)` | pointer to first occurrence of substring b in a |
| `strtok(s, delim)` | splits a string by delimiters (modifies the string!) |
| `sprintf(buf, fmt, ...)` | formats into a string buffer |
| `sscanf(buf, fmt, ...)` | parses values out of a string |

**Reimplementing library functions** is a classic exercise to understand pointer
manipulation deeply — build your own `strlen`, `strcpy`, `strcat`, `strcmp`, `strstr`.

## 2.7 Arrays of Strings
```c
char *names[] = {"Alice", "Bob", "Charlie"};   // array of pointers to string literals
char names2[3][20] = {"Alice", "Bob", "Charlie"}; // 2D char array, fixed-size rows
```
- `names` is an array of pointers — each element can point to strings of different
  lengths, more memory-efficient but each string is separately allocated.
- `names2` reserves fixed space per row — simpler but can waste memory if names are
  much shorter than 20 characters.

## 2.8 2D Arrays and Pointer Notation
```c
int matrix[3][4];
matrix[i][j];              // standard access
*(*(matrix + i) + j);       // equivalent pointer form
```
- `matrix` decays to a pointer to an array of 4 ints (`int (*)[4]`), not `int **`.
- This is why a true 2D array and a dynamically-allocated "array of pointers" (see
  Dynamic Memory notes) are NOT interchangeable in function signatures.

```c
void printMatrix(int m[][4], int rows) {   // column size MUST be specified
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 4; j++)
            printf("%d ", m[i][j]);
}
```
