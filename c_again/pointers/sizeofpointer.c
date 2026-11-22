/* On a 32-bit system, all pointers typically occupy 4 bytes. */
/* On a 64-bit system, all pointers typically occupy 8 bytes. */

/* The size remains constant regardless of the data type (int*, char*, float*,
 * etc.). We can verify this using the sizeof operator. */
#include <stdio.h>

int main() {
    int *ptr1;
    char *ptr2;

    // Finding size using sizeof()
    printf("%zu\n", sizeof(ptr1));
    printf("%zu", sizeof(ptr2));

    return 0;
}

/* The reason for the same size is that the pointers store the memory addresses,
 * no matter what type they are. As the space required to store the addresses of
 * the different memory locations is the same, the memory required by one
 * pointer type will be equal to the memory required by other pointer types. */
