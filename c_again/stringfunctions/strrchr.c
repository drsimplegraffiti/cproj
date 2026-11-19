/* strrchr() */

/* The strrchr() function searches for the last occurrence of a specified
 * character in a string. It returns a pointer to the last matching character if
 * found. */

/*     It is declared in the <string.h> header file. */
/*     If the character is not found, the function returns NULL. */

#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Hello, World!";

    // Finding the last occurence of 'o' is string s
    char *res = strrchr(s, 'o');

    if (res != NULL)
        printf("Character found at: %ld index", res - s);
    else
        printf("Character not found\n");
    return 0;
}
