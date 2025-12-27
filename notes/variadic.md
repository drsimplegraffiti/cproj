# Variadic Functions in C (Single File Example)

Variadic functions are functions that can accept a **variable number of arguments**.
They are commonly used in functions like `printf()`.

In C, variadic functions are implemented using the `<stdarg.h>` library.

---

```c
#include <stdio.h>
#include <stdarg.h>

// Variadic function: calculates sum of given numbers
int sum(int count, ...) {
    int total = 0;

    // Initialize va_list
    va_list args;
    va_start(args, count);

    // Access all arguments
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int); // get next argument
    }

    // Clean up
    va_end(args);

    return total;
}

int main() {
    // Using sum with different number of arguments
    int result1 = sum(3, 10, 20, 30); // 3 arguments
    int result2 = sum(5, 1, 2, 3, 4, 5); // 5 arguments

    printf("Sum of 10,20,30 = %d\n", result1);
    printf("Sum of 1,2,3,4,5 = %d\n", result2);

    // Using printf itself as a variadic function
    printf("Formatted output: %d + %d = %d\n", 5, 7, 5 + 7);

    return 0;
}

