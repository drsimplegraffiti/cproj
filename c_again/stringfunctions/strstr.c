/* strstr() */

/* The strstr() function searches for the first occurrence of a substring within
 * another string. It returns a pointer to the beginning of the matched
 * substring if found. */

/*     It is declared in the <string.h> header file. */
/*     If the substring is not found, the function returns NULL. */

#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Hello, Geeks!";

    // Find the occurence of "Geeks" in string s
    char *pos = strstr(s, "Geeks");

    if (pos != NULL)
        printf("Found");
    else
        printf("Not Found");
    return 0;
}
