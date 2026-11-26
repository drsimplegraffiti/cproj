
#include <stdio.h>

void changeArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        /* arr[i] = i * 2; */
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int main(void) {
    int arr[5] = {1, 3, 4, 6, 9};

    int len = sizeof(arr) / sizeof(arr[0]);

    changeArray(arr, len);

    printf("\nUpdated array:\n");

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
