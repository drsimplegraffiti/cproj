#include <stdio.h>

int main() {

    int a = 90;
    int *ptr_a = &a;
    if (ptr_a == NULL) {
        printf("null pointer \n");
        return 1;
    }
    printf("actual value is : %d\n", a);
    printf("pointer %p\n", (void *)ptr_a);
    /* The memory address is in hexadecimal form (0x..). */
    //  0x7ffe9f2e44cc

    // change the value of a reference
    *ptr_a = 891;

    // dereferenced
    printf("dereferenced %d\n", *ptr_a);

    // declaring a pointer 2 ways
    /* int* my_num; */
    int *my_number = NULL;
    printf("my_number is %p\n", (void *)my_number);
}
