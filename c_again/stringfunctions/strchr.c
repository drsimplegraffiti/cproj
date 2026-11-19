/* strchr() */

/* The strchr() function searches for the first occurrence of a specified
 * character in a string. It returns a pointer to the first matching character
 * if found. */

/*     It is declared in the <string.h> header file. */
/*     If the character is not found, the function returns NULL. */

#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Hello, World!";

    // Finding the first occurence of 'o' in string s
    char *res = strchr(s, 'o');
    if (res != NULL)
        printf("Character found at: %ld index", res - s);
    else
        printf("Character not found");
    return 0;
}
