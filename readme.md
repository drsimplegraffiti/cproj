# Header Files in C — Everything in One Copyable File

This file shows how to create a header file, include it in a `.c` file,
and use it in `main.c`.

---

## Logical Project Structure

project/
├── main.c
├── math_utils.h
└── math_utils.c

---

## math_utils.h (Header File)

```go
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

// PURPOSE:
// Declare functions so other source files can use them

int add(int a, int b);
int multiply(int a, int b);

#endif
```

### in math_utils.c
```go
#include "math_utils.h"

// PURPOSE:
// Provide actual function implementations

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

```

### Then in main.c
```go
#include <stdio.h>
#include "math_utils.h"  // Import declarations

int main(void) {
    int x = 3, y = 4;

    printf("Add: %d\n", add(x, y));
    printf("Multiply: %d\n", multiply(x, y));

    return 0;
}

```

#### compilation
```go
gcc main.c math_utils.c -o program
```
