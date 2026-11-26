#include "panic.h"
#include "types.h"
#include <stdio.h>

/* typedef int *int_ptr; */ // not recommended

int main(void) {
    i32 age = 25;
    u64 population = 2000000;
    f64 balance = 15000.50;
    boolean active = true;

    printf("Age: %d\n", age);
    printf("Population: %llu\n", (unsigned long long)population);
    printf("Balance: %.2f\n", balance);
    printf("Active: %s\n", active ? "true" : "false");

    // math func
    i8 num_one = 9;
    i8 num_two = 0;
    if (num_two == 0) {
        c_panic("cannot divide by zero\n");
    }

    /* ~/Downloads/cprog/c_again/reusabletypealias main gcc main.c panic.c -o
     * main && ./main */

    return 0;
}
