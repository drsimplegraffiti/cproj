#include <stdio.h>

/* We can also use scanf() to read strings with spaces by utilizing a scanset. A
 * scanset in scanf() allows specifying the characters to include or exclude
 * from the input. */

int main() {
    char str[20];

    printf("Enter your name: ");
    // Using scanset in scanf
    // to read until newline
    scanf("%19[^\n]", str);

    // Printing the read string
    printf("%s\n", str);

    return 0;
}
