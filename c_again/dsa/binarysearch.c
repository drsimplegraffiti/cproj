/* Binary Search */
/* Binary search is much faster than linear search, but it only works on a
 * sorted array. It repeatedly looks at the middle item and discards half of
 * the remaining range until the value is found or the range is empty. */

/* Binary search is much faster, but it only works on a sorted array. Here is
 * how it works: */

/*     Look at the item in the middle. */
/*     If it is the value you want, you are done! */
/*     If the value you want is bigger, search only the right half. If it is
 * smaller, search only the left half. */
/*     Repeat with the half that is left. */

#include <stdio.h>

/* Returns the index of `value` in `arr`, or -1 if `value` is not present.
 * `length` is the number of elements in `arr`. */
int binarySearch(int arr[], int length, int value) {
    int low = 0;           // Start of the search range (first index)
    int high = length - 1; // End of the search range (last index)

    while (low <= high) {              // Keep going while the range is valid
        int middle = (low + high) / 2; // Index of the middle item
        printf("Checking index %d (value %d)\n", middle, arr[middle]);

        if (arr[middle] == value) {       // Found the value
            return middle;                // Return its index
        } else if (arr[middle] < value) { // Value is in the right half
            low = middle + 1;             // Narrow range to the right of middle
        } else {                          // Value is in the left half
            high = middle - 1;            // Narrow range to the left of middle
        }
    }

    return -1; // Value not found in the array
}

int main() {
    int numbers[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; // Sorted array
    int length = sizeof(numbers) / sizeof(numbers[0]);     // Number of elements

    int index = binarySearch(numbers, length, 23); // Search for 23

    if (index != -1) { // If found
        printf("Found 23 at index %d\n", index);
    } else { // If not found
        printf("23 was not found\n");
    }

    return 0;
}
