
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("a is %d and b is %d\n", *a, *b);
}

int main(void) {
    int a = 8;
    int b = 9;

    printf("a is %d and b is %d\n", a, b);
    swap(&a, &b);

    return 0;
}
