/*
 * Chapter 14 - Custom Memory Allocator
 * allocator.h - interface for a simple custom malloc/free implementation.
 */

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>

void* my_malloc(size_t size);
void  my_free(void* ptr);

#endif
