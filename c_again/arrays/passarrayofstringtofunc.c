
#include <stdio.h>

// Function that takes an array of strings as an argument
void print(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", *(arr + i));
    }
}

int main(void) {
    char *arr[10] = {"Geek", "Geeks", "Geekfor"};

    // Calculate the number of elements in the array
    /* int len = sizeof(arr) / sizeof(arr[0]); */

    print(arr, 3);

    return 0;
}
