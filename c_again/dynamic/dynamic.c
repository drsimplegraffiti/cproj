

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // 1. malloc() - Allocate memory (uninitialized)
    int *numbers = malloc(3 * sizeof(int));
    printf("size of int %zu\n", sizeof(int)); // 4 bytes
    printf("size of numbers %zu\n",
           sizeof(numbers)); // 8 bytes because the size of
                             // #numbers and not int

    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;

    printf("=== malloc ===\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\n", numbers[i]);
    }

    // 2. calloc() - Allocate memory (initialized to zero)
    int *values = calloc(3, sizeof(int));

    if (values == NULL) {
        printf("Memory allocation failed\n");
        free(numbers);
        return 1;
    }

    printf("\n=== calloc ===\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\n", values[i]);
    }

    // 3. realloc() - Resize allocated memory
    int *temp = realloc(numbers, 5 * sizeof(int));

    if (temp == NULL) {
        printf("Memory reallocation failed\n");
        free(numbers);
        free(values);
        return 1;
    }

    numbers = temp;

    numbers[3] = 40;
    numbers[4] = 50;

    printf("\n=== realloc ===\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]);
    }

    // 4. free() - Release allocated memory
    free(numbers);
    free(values);

    numbers = NULL;
    values = NULL;

    printf("\nMemory successfully freed!\n");

    return 0;
}
