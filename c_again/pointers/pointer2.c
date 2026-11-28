#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *x;
    if ((x = malloc(sizeof(int) * 3)) == NULL) {
        printf("error allocating memory\n");
    }

    printf("x is %d\n", *x);

    int *p = (int *)malloc(sizeof(int) * 3);
    if (p == NULL) {
        printf("error allocating\n");
        free(p);
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        p[i] = i;
    }

    // Print all values 0, 5, 3, 15, ..., 40, 45
    for (int i = 0; i < 3; i++)
        printf("%d\n", p[i]);

    free(x);
    free(p);

    // Allocate space for 3 ints with calloc(), initialized to 0:
    int *px = calloc(3, sizeof(int));
    if (px == NULL) {
        printf("error allocating\n");
        return 0;
    }

    for (int i = 0; i < 3; i++)
        printf("%d\n", px[i]);

    return 0;
}
