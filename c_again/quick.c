#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// An array passed to a function becomes a POINTER to its first element.
// That's why we must also pass the size: the function can't know it.
void print_array(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Doubles every element IN PLACE (changes the caller's array)
void double_all(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// Counting characters by walking a pointer through a string
int my_strlen(const char *s) {
    const char *start = s;
    while (*s != '\0') {
        s++; // move the pointer to the next character
    }
    return (int)(s - start); // pointer subtraction = number of elements between
}

void topic_19_arrays_pointers(void) {
    printf("\n--- Topic 19: Arrays and pointers ---\n");

    int nums[5] = {1, 2, 3, 4, 5};
    print_array(nums, 5);
    double_all(nums, 5);
    print_array(nums, 5); // the original array was changed

    // nums[i] is exactly the same as *(nums + i)
    printf("nums[2] = %d, *(nums + 2) = %d\n", nums[2], *(nums + 2));

    printf("my_strlen(\"pointer\") = %d\n", my_strlen("pointer"));
}

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);
    print_array(arr, len);
}
