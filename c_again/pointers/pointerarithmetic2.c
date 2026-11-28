#include <stdio.h>
#include <string.h>

int my_strlen(char *s) {
    // Start scanning from the beginning of the string
    char *p = s;

    // Scan until we find the NUL character
    while (*p != '\0') {
        /* printf("dereferenced pointer %c\n", *p); */
        p++;
    }

    // Return the difference in pointers
    return p - s;
}

int main(void) {
    int a[5] = {1, 8, 3, 4, 5};
    int *ptr = &a[0]; // same as int *ptr = a;
    printf("pointer m1 %p\n", ptr);
    printf("pointer m2 %p\n", (void *)ptr);
    printf("pointer m3 %p\n", &a[0]);

    printf("actual value, first elem: %d\n", *ptr);
    printf("actual value, first elem: %d\n", *(ptr + 0));

    // next 1
    printf("next one, first elem: %d\n", *(ptr + 1));
    printf("next one, first elem: %d\n", *(ptr + 2));

    for (int i = 0; i < 5; i++) {
        printf("i am number: %d\n", *(ptr + i));
    }

    printf("%d\n", my_strlen("Hello, world!")); // Prints "13"
    printf("%ld\n", strlen("Hello, world!"));   // Prints "13"

    int nums[] = {1, 3, 10};
    int *nums_ptr = nums; // points to the first elem
    printf("nums_ptr is %d\n", *nums_ptr);

    for (int i = 0; i < 5; i++)
        printf("%d\n", nums_ptr[i]); // Array notation with nums_ptr

    for (int i = 0; i < 5; i++)
        printf("%d\n", nums[i]); // Array notation with nums

    return 0;
}
