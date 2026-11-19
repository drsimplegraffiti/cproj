/* strncpy() */

/* The strncpy() function copies at most n characters from the source string to
 * the destination string. It is useful when you want to limit the number of
 * characters copied. */

/* It is declared in the <string.h> header file. */
/* If the source string is shorter than n, the remaining characters in the
 * destination are filled with '\0'. */
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello";
    char dest[20];

    // Copies "Hello" to dest
    strncpy(dest, src, 4);
    printf("%s", dest);
    return 0;
}
