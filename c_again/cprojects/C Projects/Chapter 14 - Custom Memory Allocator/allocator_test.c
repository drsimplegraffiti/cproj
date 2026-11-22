/*
 * Chapter 14 - Custom Memory Allocator
 * allocator_test.c - simple test harness for my_malloc / my_free.
 */

#include <stdio.h>
#include <string.h>
#include "allocator.h"

int main(void) {
    printf("Testing custom memory allocator...\n");

    int* a = (int*)my_malloc(sizeof(int));
    int* b = (int*)my_malloc(sizeof(int));
    char* s = (char*)my_malloc(64);

    if (!a || !b || !s) {
        printf("Allocation failed\n");
        return 1;
    }

    *a = 42;
    *b = 100;
    strcpy(s, "Hello from custom allocator");

    printf("a = %d\n", *a);
    printf("b = %d\n", *b);
    printf("s = %s\n", s);

    my_free(a);
    my_free(b);
    my_free(s);

    /* Reuse freed memory */
    int* c = (int*)my_malloc(sizeof(int));
    if (c) {
        *c = 777;
        printf("Reused block c = %d\n", *c);
        my_free(c);
    }

    printf("Allocator test complete.\n");
    return 0;
}
