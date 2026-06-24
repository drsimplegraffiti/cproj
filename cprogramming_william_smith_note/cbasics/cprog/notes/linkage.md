# Linkage in C

**Linkage** in C determines the **visibility and lifetime** of variables and functions across multiple files (translation units).
It tells the compiler **whether an identifier can be shared across files** or is limited to a single file.

---

## Types of Linkage

1. **External Linkage**
   - Identifier is **visible across multiple files**.
   - Default for global variables and functions.
   - Use keyword: `extern` (optional for functions).

2. **Internal Linkage**
   - Identifier is **limited to the file** it is declared in.
   - Use keyword: `static`.

3. **No Linkage**
   - Identifier is **local to the block or function**.
   - Local variables inside functions have no linkage.

---

## Example: Demonstrating Linkage

```go
#include <stdio.h>

// External linkage by default
int global_var = 100; // visible across files

// Internal linkage
static int static_var = 50; // only visible in this file

// Function with external linkage
void external_function() {
    printf("External function called! global_var=%d\n", global_var);
}

// Function with internal linkage
static void internal_function() {
    printf("Internal function called! static_var=%d\n", static_var);
}

int main() {
    int local_var = 10; // no linkage
    printf("Local variable: %d\n", local_var);

    // Access global variable
    printf("Global variable: %d\n", global_var);

    // Access static variable
    printf("Static variable: %d\n", static_var);

    // Call functions
    external_function();
    internal_function();

    return 0;
}
```

