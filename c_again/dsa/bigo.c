#include <stdio.h>
#include <time.h>

/* Big O notation describes how an algorithm's runtime (or memory use) grows as
 * the input size n grows. It measures the worst case and ignores constants.
 *
 * Common classes:
 *   O(1)   - constant time:    runtime does not grow with n
 *   O(log n) - logarithmic time: runtime grows slowly (e.g. binary search)
 *   O(n)   - linear time:      runtime grows in direct proportion to n
 *   O(n log n) - linearithmic: e.g. merge sort, heap sort
 *   O(n^2) - quadratic time:   runtime grows with the square of n
 */

/* O(1) - Constant time.
 * Accessing an array element by index takes the same time no matter how large
 * the array is. */
int constantTime(int arr[], int index) {
    return arr[index];
}

/* O(n) - Linear time.
 * Linear search checks every element once, so runtime grows in proportion to n. */
int linearTime(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

/* O(log n) - Logarithmic time.
 * Binary search halves the search range each step, so runtime grows like
 * log2(n). Requires a sorted array. */
int logarithmicTime(int arr[], int low, int high, int value) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

/* O(n^2) - Quadratic time.
 * Nested loops: for each of n elements, we scan up to n elements.
 * Example: bubble sort or checking all pairs. */
void quadraticTime(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* Simple timer helper using clock(). Returns elapsed seconds as a double. */
double elapsedSeconds(clock_t start, clock_t end) {
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int small[] = {10, 20, 30, 40, 50};

    /* O(1) example */
    printf("O(1) constant: arr[2] = %d\n", constantTime(small, 2));

    /* O(n) example */
    printf("O(n) linear: 30 is at index %d\n", linearTime(small, 5, 30));

    /* O(log n) example */
    int sorted[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(sorted) / sizeof(sorted[0]);
    printf("O(log n) binary: 23 is at index %d\n",
           logarithmicTime(sorted, 0, n - 1, 23));

    /* O(n^2) example on a tiny array */
    int dup[] = {5, 2, 9, 1};
    int m = sizeof(dup) / sizeof(dup[0]);
    quadraticTime(dup, m);
    printf("O(n^2) bubble sorted: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", dup[i]);
    }
    printf("\n");

    return 0;
}
