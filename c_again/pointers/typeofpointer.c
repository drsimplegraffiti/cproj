#include <stdio.h>
#include <stdlib.h>

/* I want to tell you a secret. Generally speaking, when a C programmer talks
 * about a pointer to an array, they’re talking about a pointer to the first
 * element of the array60. */

/* So let’s get a pointer to the first element of an array. */

int main() {

    /* 1. NULL Pointer */
    /* A NULL Pointers is a pointer that does not point to any valid memory
     * location. It is created by assigning the value NULL to a pointer
     * variable. */
    // Null pointer
    int *ptr = NULL;
    if (ptr == NULL) {
        printf("not enough memory\n");
        return 1;
    }

    /*2. Void Pointer */

    /* The void pointers is a pointer of type void that does not have an
     * associated data type. It is also known as a generic pointer because it
     * can store the address of any data type. */
    /* A void pointer can point to variables of any data type but must be
     * typecast before dereferencing. */
    /* It is commonly used in generic functions and memory management routines
     * where the data type is not known in advance */
    // Void pointer
    void *vptr;

    /* 3. Wild Pointer */

    /* The wild pointer is a pointer that has been declared but not initialized
     * with a valid memory address. Using a wild pointer results in undefined
     * behavior. */

    /*     Dereferencing a wild pointer can cause program crashes, memory
     * corruption, or unexpected results. */
    /*     Always initialize pointers with a valid address or NULL before using
     * them to avoid errors. */
    // Wild Pointer
    int *wptr;

    /* 4. Dangling Pointer */

    /* A dangling pointer is a pointer that refers to a memory location that has
     * already been deallocated or freed. Accessing such a pointer leads to
     * undefined behavior. */

    /*     Dereferencing a dangling pointer can cause program crashes, incorrect
     * results, or memory access errors. */
    /*     Dangling pointers commonly occur when dynamically allocated memory is
     * freed but the pointer is not updated or set to NULL. */

    int *dptr = (int *)malloc(sizeof(int));

    // After below free call, dptr becomes a dangling pointer
    free(dptr);
    printf("Memory freed\n");

    // removing Dangling Pointer
    dptr = NULL;
    return 0;
}
