# Linkage and Storage Classes in C (Single File Example)

This example demonstrates **linkage (external, internal, none)** and **storage classes (auto, register, static, extern)** all in one file.

```c
#include <stdio.h>

// -------- Linkage Examples --------

// External linkage (global variable, visible across files)
int global_var = 100;

// Internal linkage (static variable, visible only in this file)
static int static_var = 50;

// Function with external linkage
void external_function() {
    printf("External function called! global_var=%d\n", global_var);
}

// Function with internal linkage
static void internal_function() {
    printf("Internal function called! static_var=%d\n", static_var);
}

// -------- Storage Class Examples --------

void storage_class_demo() {
    auto int local_auto = 5;        // default local variable
    register int local_register = 10; // CPU register hint
    static int local_static = 0;    // retains value across calls

    local_auto += 1;
    local_register += 1;
    local_static += 1;

    printf("auto=%d, register=%d, static=%d\n", local_auto, local_register, local_static);
}

int main() {
    // Local variable with no linkage
    int local_var = 20;
    printf("Local variable: %d\n", local_var);

    // Access global and static variables
    printf("Global variable: %d\n", global_var);
    printf("Static variable: %d\n", static_var);

    // Call functions
    external_function();
    internal_function();

    // Demonstrate storage classes
    storage_class_demo(); // call 1
    storage_class_demo(); // call 2
    storage_class_demo(); // call 3

    // Demonstrate extern usage
    extern int global_var; // refers to the same global_var
    printf("Accessing global_var using extern: %d\n", global_var);

    return 0;
}

