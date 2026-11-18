#include <stdio.h>

/* The register keyword suggests that the variable should be stored in a CPU
 * register (for faster access). */

/* You cannot take the address of a register variable using &. */
int main(void) {
    register int counter = 0;
    printf("Counter: %d\n", counter);
    /* printf("Counter: %p\n", &counter); */

    return 0;
}
