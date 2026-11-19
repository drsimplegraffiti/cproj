/* The strtok() function splits a string into tokens based on specified
 * delimiter characters. It modifies the original string by replacing delimiters
 * with the null character '\0'. */

/*     It is declared in the <string.h> header file. */
/*     Successive calls to strtok() return the next token until no more tokens
 * are found, after which it returns NULL. */

#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Hello, Geeks, C!";

    // Initializing tokens
    char *t = strtok(s, ", ");

    // Printing rest of the tokens
    while (t != NULL) {
        printf("%s\n", t);
        t = strtok(NULL, ", ");
    }
    return 0;
}
