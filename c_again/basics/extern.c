/* extern */

/* The extern keyword tells the compiler that a variable or function is defined
 * in another file. */

/* It is commonly used when working with multiple source files. */

// main.c File 1: main.c
#include <stdio.h>

extern int shared; // Declared here, defined in another file

int main() {
    printf("shared = %d\n", shared);
    return 0;
}

/* File 2: data.c */
int shared = 50; // Definition of the variable
                 //
/* Compile both files together, like in the Organize Code chapter: */
/* gcc main.c data.c - o program */
