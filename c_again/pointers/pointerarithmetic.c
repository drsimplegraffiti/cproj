
/* Pointer Arithmetic in C with Examples */
/* Last Updated: 11 Jul, 2026 */

/* Pointer arithmetic refers to the valid arithmetic operations that can be
 * performed on pointers in C. Since pointers store memory addresses instead of
 * actual values, only a limited set of arithmetic operations is allowed. */

/* Pointer arithmetic includes operations such as increment/decrement,
 * adding or subtracting an integer, subtracting two pointers, and comparing
 * pointers. */

/* These operations move the pointer based on the size of the data type it
 * points to, not by a single byte. */

/* The memory addresses of pointers may change on each program execution due
 * to ASLR (Address Space Layout Randomization) used by modern operating
 * systems. */

#include <stdio.h>

int main(void) {
    // Pointer increment and decrement.
    // Pointers move by the size of the data type they point to.

    int a = 22;
    int *p = &a;

    printf("p   = %p\n", (void *)p);

    p++;
    printf("p++ = %p\n", (void *)p);

    p--;
    printf("p-- = %p\n", (void *)p);

    float b = 22.22f;
    float *q = &b;

    printf("q   = %p\n", (void *)q);

    q++;
    printf("q++ = %p\n", (void *)q);

    q--;
    printf("q-- = %p\n", (void *)q);

    char c = 'a';
    char *r = &c;

    printf("r   = %p\n", (void *)r);

    r++;
    printf("r++ = %p\n", (void *)r);

    r--;
    printf("r-- = %p\n", (void *)r);

    // substract pointer
    int x = 6;
    int N = 4;

    // Pointer declaration
    int *ptr1, *ptr2;

    // stores address of N
    ptr1 = &N;

    // stores address of x
    ptr2 = &x;

    printf(" ptr1 = %u, ptr2 = %u\n", ptr1, ptr2);
    // %p gives an hexa-decimal value,
    // We convert it into an
    // unsigned int value by using %u

    // Subtraction of ptr2 and ptr1
    x = ptr1 - ptr2;

    // Print x to get the Increment
    // between ptr1 and ptr2
    printf("Subtraction of ptr1 "
           "& ptr2 is %d\n",
           x);

    return 0;
}
