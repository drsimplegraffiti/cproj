#include <stdio.h>

// Passing as a pointer to the first element
void times2(int *a, int len) {
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 2);
}

// Same thing, but using array notation
void times3(int a[], int len) {
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 3);
}

// Same thing, but using array notation with size
void times4(int a[5], int len) {
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 4);
}

int main(void) {

    int a = 9;
    int *ptr_a = &a;
    printf("actual value of a is %d\n", a);
    printf("memory address of the value a is %p\n", (void *)ptr_a);
    printf("memory address of the value a is %p\n", &a);

    // pointers to array
    // Generally speaking, when a C programmer talks about a pointer to an
    // array, they’re talking about a pointer to the first element of the
    // array60.

    /* So let’s get a pointer to the first element of an array. */
    int arr[3] = {6, 3, 5};
    int *arr_ptr = &arr[0];
    printf("this will print the first index %d\n", *arr_ptr); // dereferencing

    int x[5] = {11, 22, 33, 44, 55};

    times2(x, 5);
    times3(x, 5);
    times4(x, 5);

    return 0;
}
