#include <stdio.h>
#include <stdlib.h>

int main() {

    int *arr;
    int size;

    printf("Enter the number of elements you want: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int)); // malloc allocates memory
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit program
    }

    // populate the array manually
    // for (int i = 0; i < size; i++) {
    //   printf("Enter element %d: ", i + 1); // this is for display purpose,
    //   because
    //                                        // ordinarily index starts from 0
    //   scanf("%d", &arr[i]);                // arr[i] == *(arr + i)
    // }

    // or populate automatically
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
        printf("%d ", arr[i]); // Outputs: 10 20 30 40 50
    }
    printf("\n");

    // print the array
    printf("Your array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL; // Erase memory reference

    return 0;
}

//
// #include <stdio.h>
// #include <stdlib.h>
//
// #define MAX_SIZE 4
//
// int main() {
//     int len = MAX_SIZE;
//
//     int *arr = malloc(sizeof(int) * len);
//     char *str = malloc(sizeof(char) * (len + 1));
//
//     if (arr == NULL || str == NULL) {
//         printf("Error mem allocation\n");
//         free(arr);
//         free(str);
//         return 1;
//     }
//
//     for (int i = 0; i < len; i++) {
//         arr[i] = i + 1;
//         str[i] = 'A' + i;
//
//         printf("when arr is %d, string is %c\n", arr[i], str[i]);
//     }
//
//     str[len] = '\0';
//
//     printf("\nComplete string: %s\n", str);
//
//     free(arr);
//     free(str);
//
//     arr = NULL;
//     str = NULL;
//
//     return 0;
// }
