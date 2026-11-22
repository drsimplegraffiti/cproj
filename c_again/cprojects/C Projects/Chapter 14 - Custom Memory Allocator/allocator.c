/*
 * Chapter 14 - Custom Memory Allocator
 * allocator.c - simplistic malloc/free using a fixed heap and free list.
 */

#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"

#define HEAP_SIZE (1024 * 1024) /* 1 MB simulated heap */

typedef struct Block {
    size_t size;
    struct Block* next;
    int free;
} Block;

static char heap[HEAP_SIZE];
static Block* free_list = NULL;

static void init_heap(void) {
    free_list = (Block*)heap;
    free_list->size = HEAP_SIZE - sizeof(Block);
    free_list->next = NULL;
    free_list->free = 1;
}

void* my_malloc(size_t size) {
    if (size == 0) return NULL;

    /* Align to pointer size */
    size = (size + sizeof(size_t) - 1) & ~(sizeof(size_t) - 1);

    if (free_list == NULL) init_heap();

    Block* current = free_list;

    while (current != NULL) {
        if (current->free && current->size >= size) {
            /* Split if large enough to leave a useful remainder */
            if (current->size > size + sizeof(Block) + 8) {
                Block* remainder = (Block*)((char*)current + sizeof(Block) + size);
                remainder->size = current->size - size - sizeof(Block);
                remainder->next = current->next;
                remainder->free = 1;
                current->size = size;
                current->next = remainder;
            }
            current->free = 0;
            return (void*)((char*)current + sizeof(Block));
        }
        prev = current;
        current = current->next;
    }

    return NULL; /* out of memory */
}

void my_free(void* ptr) {
    if (ptr == NULL) return;
    Block* block = (Block*)((char*)ptr - sizeof(Block));
    block->free = 1;

    /* Coalesce adjacent free blocks */
    Block* current = free_list;
    while (current != NULL) {
        if (current->free && current->next && current->next->free) {
            Block* next = current->next;
            current->size += sizeof(Block) + next->size;
            current->next = next->next;
        }
        prev = current;
        current = current->next;
    }
}
