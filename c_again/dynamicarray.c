#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dynamic integer array.
typedef struct {
    int *data;
    int length;
    int capacity;
} IntArray;

// Create a new dynamic array.
IntArray IntArrayNew(int capacity) {
    IntArray arr;

    arr.data = malloc(sizeof(int) * capacity);
    arr.length = 0;
    arr.capacity = capacity;

    if (arr.data == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    return arr;
}

// Add an item to the array.
void IntArrayPush(IntArray *arr, int value) {
    // Grow the array when it becomes full.
    if (arr->length >= arr->capacity) {
        int new_capacity = arr->capacity == 0 ? 2 : arr->capacity * 2;

        int *new_data = realloc(arr->data, sizeof(int) * new_capacity);

        if (new_data == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        arr->data = new_data;
        arr->capacity = new_capacity;
    }

    arr->data[arr->length] = value;
    arr->length++;
}

int main(void) {
    const char name[] = "janes";
    int len = strnlen(name, 6);

    printf("%s\n", name);
    printf("%d\n", len);

    const int numbers[4] = {1, 2, 3, 4};
    printf("Array index one: %d\n", numbers[0]);

    // Dynamic array.
    IntArray arr = IntArrayNew(2);

    IntArrayPush(&arr, 10);
    IntArrayPush(&arr, 20);
    IntArrayPush(&arr, 30);
    IntArrayPush(&arr, 40);

    // Print array.
    for (int i = 0; i < arr.length; i++) {
        printf("arr[%d] = %d\n", i, arr.data[i]);
    }

    printf("Length: %d\n", arr.length);
    printf("Capacity: %d\n", arr.capacity);

    // Release allocated memory.
    free(arr.data);

    return 0;
}
