/* Sorting means putting values in order, for example from smallest to largest.
 */

/* Compare the first two values. If the first one is bigger, swap them. */
/* Move one step to the right, and compare the next two values. Keep going to
 * the end of the array. */
/* Now the biggest value has "bubbled up" to the end. It is in the right place.
 */
/* Repeat for the rest of the array. */

/* One trip through the array is called a pass.Here is the first pass, */
/* step by step : */
#include <stdio.h>

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    /* int numbers[] = {10, 9, 4, 3, 5}; */
  int numbers[] = {5, 3, 8, 1, 4};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < length - 1; i++) {
        int swapped = 0; // No swaps yet in this pass

        for (int j = 0; j < length - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swapped = 1;
            }
        }

        printf("Pass %d: ", i + 1);
        printArray(numbers, length);

        if (swapped == 0) {
            printf("No swaps, so the array is sorted. Stop!\n");
            break;
        }
    }

    return 0;
}

/* | Array State | Comparison | Action | */
/* |---|---|---| */
/* | `5  3  8  1  4` | `5 > 3` | Swap | */
/* | `3  5  8  1  4` | `5 < 8` | No swap | */
/* | `3  5  8  1  4` | `8 > 1` | Swap | */
/* | `3  5  1  8  4` | `8 > 4` | Swap | */
/* | `3  5  1  4  8` | `8` is in place! | Done | */



/* #include <stdio.h> */

/* void printArray(int arr[], int length) { */
/*   for (int i = 0; i < length; i++) { */
/*     printf("%d ", arr[i]); */
/*   } */
/*   printf("\n"); */
/* } */

/* int main() { */
/*   int numbers[] = {5, 3, 8, 1, 4}; */
/*   int length = sizeof(numbers) / sizeof(numbers[0]); */

/*   printf("Start:  "); */
/*   printArray(numbers, length); */

/*   for (int i = 0; i < length - 1; i++) { */
/*     // Compare each pair of neighbors */
/*     for (int j = 0; j < length - 1 - i; j++) { */
/*       if (numbers[j] > numbers[j + 1]) { */
/*         // Swap them */
/*         int temp = numbers[j]; */
/*         numbers[j] = numbers[j + 1]; */
/*         numbers[j + 1] = temp; */
/*       } */
/*     } */
/*     printf("Pass %d: ", i + 1); */
/*     printArray(numbers, length); */
/*   } */

/*   return 0; */
/* } */
