/* Sort the Easy Way: qsort() */

/* Bubble sort is great for learning, but it is slow for large arrays. In real
 * programs, use the qsort() function from <stdlib.h>. It is fast, and it is
 * already written for you! */

/* You only need to give qsort() a small callback function that compares two
 * values: */
#include <stdio.h>
#include <stdlib.h>

// Tells qsort() how to compare two numbers
int compare(const void *a, const void *b) {
    /* printf(" %d\n", *(int *)a - *(int *)b); */
    return (*(int *)a - *(int *)b);
}
/* qsort() needs four things: the array, the number of items, the size of one
 * item, and the compare function. */

/* (int*)a turns the general pointer a into an int pointer, and reads the number
 * it points to. */
/* The compare function returns a negative number if a should come first, a
 * positive number if b should come first, and 0 if they are equal. */

int main() {
    int numbers[] = {64, 25, 12, 22, 11};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    qsort(numbers, length, sizeof(int), compare);

    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
