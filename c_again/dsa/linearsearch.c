#include <stdio.h>

/* Returns the index of `value` in `arr`, or -1 if `value` is not present.
 * `length` is the number of elements in `arr`. */
/* Linear search is the simplest way to find a value: check each item, one by
 * one, from the start. Stop when you find the value or reach the end. */
int linearSearch(int arr[], int length, int value) {
    for (int i = 0; i < length; i++) {   // Visit every index from 0 to length-1
        if (arr[i] == value) {           // Is this item the one we want?
            return i;                    // Yes, return its index
        }
    }
    return -1;                           // Reached the end, not found
}

int main() {
    int numbers[] = {4, 9, 2, 7, 5, 8};  // Unsorted array
    int length = sizeof(numbers) / sizeof(numbers[0]); // Number of elements

    int index = linearSearch(numbers, length, 7); // Search for 7

    if (index != -1) {              // If found
        printf("Found 7 at index %d\n", index);
    } else {                        // If not found
        printf("7 was not found\n");
    }

    return 0;
}
