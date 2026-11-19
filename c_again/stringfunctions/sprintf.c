/* The sprintf() function formats data and stores the resulting string in a
 * character buffer. It works like printf(), but writes the output to a string
 * instead of displaying it on the screen. */

/*     It is declared in the <stdio.h> header file. */
/*     Ensure the destination buffer is large enough to hold the formatted
 * string to avoid buffer overflow. */

#include <stdio.h>

int main() {
    char s[50];
    int n = 10;

    // Output formatted string into string bugger s
    sprintf(s, "The value is %d", n);
    printf("%s", s);
    return 0;
}
