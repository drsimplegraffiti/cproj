#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Dynamic memory is memory that is allocated after the program starts running.
 * Allocation of dynamic memory can also be referred to as runtime memory
 * allocation. */

/* A struct whose memory we will allocate on the heap. */
struct Student {
    int id;
    char name[20];
    float grade;
};

/* 1. C Memory Management
 * Stack memory is automatic. Heap memory is manual: you allocate it with
 * malloc/calloc and you must release it with free. */
static void memory_management(void) {
    printf("--- 1. Memory Management ---\n");

    int stackVar = 10;                  /* stack: freed automatically */
    int *heapVar = malloc(sizeof(int)); /* heap: you must free it */

    if (heapVar == NULL) {
        printf("Allocation failed\n");
        return;
    }

    *heapVar = 20;
    printf("stack: %d, heap: %d\n", stackVar, *heapVar);

    free(heapVar);
}

/* 2. C Allocate Memory
 * malloc gives uninitialized memory, calloc gives zeroed memory. */
static void allocate_memory(void) {
    printf("\n--- 2. Allocate Memory ---\n");

    int *a = malloc(3 * sizeof(*a));
    int *b = calloc(3, sizeof(*b));

    if (a == NULL || b == NULL) {
        printf("Allocation failed\n");
        free(a);
        free(b);
        return;
    }

    printf("calloc values: %d %d %d\n", b[0], b[1], b[2]);

    free(a);
    free(b);
}

/* 3. C Access Memory
 * Use the pointer like an array, or with pointer arithmetic. */
static void access_memory(void) {
    printf("\n--- 3. Access Memory ---\n");

    int *numbers = malloc(4 * sizeof(*numbers));

    if (numbers == NULL) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        numbers[i] = (i + 1) * 10; /* array style */
    }

    *(numbers + 1) = 25; /* pointer arithmetic style */

    for (int i = 0; i < 4; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    free(numbers);
}

/* 4. C Reallocate Memory
 * Always store the result of realloc in a temporary pointer. If realloc fails
 * it returns NULL and the original block is still valid. */
static void reallocate_memory(void) {
    printf("\n--- 4. Reallocate Memory ---\n");

    int size = 2;
    int *data = malloc(size * sizeof(*data));

    if (data == NULL) {
        return;
    }

    data[0] = 1;
    data[1] = 2;

    size = 5;
    int *temp = realloc(data, size * sizeof(*data));

    if (temp == NULL) {
        printf("Reallocation failed\n");
        free(data);
        return;
    }

    data = temp;

    for (int i = 2; i < size; i++) {
        data[i] = i + 1;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    free(data);
}

/* 5. C Deallocate Memory
 * free() releases the block. Set the pointer to NULL afterwards so it cannot
 * be used or freed again by accident. */
static void deallocate_memory(void) {
    printf("\n--- 5. Deallocate Memory ---\n");

    int *p = malloc(sizeof(*p));

    if (p == NULL) {
        return;
    }

    *p = 99;
    printf("before free: %d\n", *p);

    free(p);
    p = NULL;

    if (p == NULL) {
        printf("pointer is now NULL, safe\n");
    }
}

/* 6. C Structs and Memory
 * Allocate an array of structs and access members with the -> operator. */
static void structs_and_memory(void) {
    printf("\n--- 6. Structs and Memory ---\n");

    int count = 2;
    struct Student *students = malloc(count * sizeof(*students));

    if (students == NULL) {
        return;
    }

    students[0].id = 1;
    strcpy(students[0].name, "Alice");
    students[0].grade = 92.5f;

    struct Student *second = &students[1];
    second->id = 2;
    strcpy(second->name, "Bob");
    second->grade = 85.0f;

    for (int i = 0; i < count; i++) {
        printf("%d %s %.1f\n", students[i].id, students[i].name,
               students[i].grade);
    }

    free(students);
}

/* 7. C Memory Example
 * A small dynamic list that grows as you add values. */
static void memory_example(void) {
    printf("\n--- 7. Memory Example ---\n");

    int capacity = 2;
    int length = 0;
    int *list = malloc(capacity * sizeof(*list));

    if (list == NULL) {
        return;
    }

    for (int value = 10; value <= 50; value += 10) {
        if (length == capacity) {
            capacity *= 2;
            int *temp = realloc(list, capacity * sizeof(*list));

            if (temp == NULL) {
                free(list);
                return;
            }

            list = temp;
        }

        list[length++] = value;
    }

    printf("length = %d, capacity = %d\n", length, capacity);

    for (int i = 0; i < length; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    free(list);
}

/* 8. C Memory Mistakes
 * The bad versions are commented out. Each one shows the fix next to it. */
static void memory_mistakes(void) {
    printf("\n--- 8. Memory Mistakes ---\n");

    /* Mistake 1: not checking malloc.
     *   int *p = malloc(sizeof(int));
     *   *p = 5;               // crash if p is NULL
     * Fix: always test for NULL first. */
    int *p = malloc(sizeof(*p));

    if (p == NULL) {
        return;
    }
    *p = 5;

    /* Mistake 2: use after free.
     *   free(p);
     *   printf("%d", *p);     // undefined behavior
     * Fix: set the pointer to NULL after free. */
    free(p);
    p = NULL;

    /* Mistake 3: double free.
     *   free(p); free(p);     // undefined behavior
     * Fix: free(NULL) is safe, so NULL after free protects you. */
    free(p);

    /* Mistake 4: writing outside the block.
     *   int *arr = malloc(3 * sizeof(int));
     *   arr[3] = 1;           // valid indexes are 0, 1, 2
     * Fix: keep track of the size and stay inside it. */
    int *arr = malloc(3 * sizeof(*arr));

    if (arr == NULL) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        arr[i] = i;
    }

    /* Mistake 5: memory leak.
     *   arr = malloc(10);     // old block lost, never freed
     * Fix: free every block you allocate before losing its pointer. */
    free(arr);

    printf("all mistakes avoided\n");
}

int main() {
    memory_management();
    allocate_memory();
    access_memory();
    reallocate_memory();
    deallocate_memory();
    structs_and_memory();
    memory_example();
    memory_mistakes();

    return 0;
}
