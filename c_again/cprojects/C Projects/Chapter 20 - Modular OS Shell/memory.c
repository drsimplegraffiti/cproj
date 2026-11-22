/*
 * Chapter 20 - Modular OS Shell
 * memory.c - memory management module using the standard allocator
 * with safety wrappers (demo of modular memory management).
 */

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        perror("malloc failed");
        return NULL;
    }
    return ptr;
}

void my_free(void* ptr) {
    if (ptr != NULL) {
        free(ptr);
    }
}
