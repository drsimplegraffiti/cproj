/* The getchar() function in C is a standard library function used to read a
 * single character from the standard input device (keyboard). It is commonly
 * used for simple character-based input operations. */

/*Reads one character at a time from the standard input stream (stdin). */
/* Defined in the <stdio.h> header file. */

/* #include <stdio.h> */

/* int main(void) { */
/*     int ch; */

/*     printf("Enter a character: "); */

/*     ch = getchar(); */

/*     if (ch != EOF) { */
/*         printf("You entered: %c\n", ch); */
/*     } */

/*     return 0; */
/* } */

/* If you want to read until Enter is pressed */

#include <stdio.h>

int main(void) {
    int ch;

    printf("Enter characters: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        printf("You entered: %c\n", ch);
    }

    /* size_t lu = sizeof("james"); */
    /* printf("size of james is %zu\n", lu); */

    return 0;
}
