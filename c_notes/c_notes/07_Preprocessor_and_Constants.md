# 7. Preprocessor, Macros & Constants

## 7.1 The Preprocessor
Before compilation, the **preprocessor** performs text substitution on directives
starting with `#`. It runs as a separate pass, purely textual — it has no knowledge
of C syntax or types.

## 7.2 `#define` — Object-like Macros
```c
#define PI 3.14159
#define MAX_SIZE 100

double area = PI * r * r;
int arr[MAX_SIZE];
```
These are simple find-and-replace substitutions performed before compilation.

## 7.3 `#define` — Function-like Macros
```c
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int y = SQUARE(5);        // expands to ((5) * (5)) = 25
int m = MAX(3, 7);         // expands to ((3) > (7) ? (3) : (7)) = 7
```

**Always parenthesize macro parameters and the whole expression** — otherwise
operator precedence can silently break things:
```c
#define BAD_SQUARE(x) x * x
int y = BAD_SQUARE(2 + 3);   // expands to 2 + 3 * 2 + 3 = 11, NOT 25!
```

**Macros vs functions:**
| | Macro | Function |
|---|---|---|
| Type checking | none (pure text substitution) | yes |
| Speed | no call overhead (inlined) | function call overhead |
| Debugging | harder (expanded before compiling) | easier (visible in debugger) |
| Side effects | dangerous if arg used multiple times, e.g. `SQUARE(i++)` | safe |

## 7.4 Conditional Compilation
```c
#define DEBUG 1

#if DEBUG
    printf("Debug: x = %d\n", x);
#endif

#ifdef DEBUG
    // included only if DEBUG is defined (any value)
#endif

#ifndef HEADER_H
#define HEADER_H
// ... header contents ...
#endif
```

### Include Guards
Every header file (`.h`) should use include guards (or `#pragma once`) to prevent
being processed twice if included from multiple places:
```c
#ifndef MYHEADER_H
#define MYHEADER_H
// declarations...
#endif
```

## 7.5 `#include`
```c
#include <stdio.h>    // standard library headers, angle brackets
#include "myheader.h" // your own headers, quotes — searches current directory first
```

## 7.6 Multi-line Macros
```c
#define SWAP(a, b, type) do { \
    type temp = a;             \
    a = b;                     \
    b = temp;                  \
} while(0)
```
The `do { ... } while(0)` wrapper makes the macro behave like a single statement,
even when followed by a semicolon inside an `if`/`else`.

## 7.7 Predefined Macros
| Macro | Meaning |
|---|---|
| `__LINE__` | current line number |
| `__FILE__` | current file name |
| `__DATE__` / `__TIME__` | compilation date/time |
| `__func__` | current function name (C99, not technically a macro but similar use) |

## 7.8 `const` — Compile-Time Constants (Type-Safe Alternative)
```c
const int MAX_SIZE = 100;
```
Unlike `#define`, `const` variables:
- **Have a type** — the compiler can catch type errors.
- **Are visible to the debugger.**
- **Have scope** — respect normal variable scoping rules, unlike macros which are
  globally substituted wherever they appear after their definition.
- Cannot be used directly as an array size in older C standards without VLA support,
  whereas `#define`d constants always work as array bounds.

**Guideline:** prefer `const` for values that should be typed constants and visible
in the debugger; use `#define` (or `enum`) for values needed at preprocessing time
(like array sizes in strict C89) or true compile-time constants shared across files
via headers.

## 7.9 Multi-File Project Organization
Typical structure for a larger C project:
```
project/
├── main.c
├── student.h      // struct definitions + function prototypes
├── student.c      // function implementations
├── file_utils.h
├── file_utils.c
└── Makefile
```

`student.h`:
```c
#ifndef STUDENT_H
#define STUDENT_H

typedef struct { char name[30]; int id; } Student;

void printStudent(Student *s);
Student *createStudent(char *name, int id);

#endif
```

`student.c`:
```c
#include "student.h"
#include <stdio.h>

void printStudent(Student *s) {
    printf("%s (%d)\n", s->name, s->id);
}
```

`main.c`:
```c
#include "student.h"

int main(void) {
    Student s = {"Alice", 1};
    printStudent(&s);
    return 0;
}
```

### Basic Compilation
```bash
gcc -c student.c -o student.o
gcc -c main.c -o main.o
gcc student.o main.o -o program
# or simply:
gcc main.c student.c -o program
```

### Simple Makefile
```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

program: main.o student.o
	$(CC) main.o student.o -o program

main.o: main.c student.h
	$(CC) $(CFLAGS) -c main.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

clean:
	rm -f *.o program
```
