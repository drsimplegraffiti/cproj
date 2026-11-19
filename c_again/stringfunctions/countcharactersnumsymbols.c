#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    printf("\n--- Topic 18: Characters ---\n");

    char text[] = "Hello World 2026!@";
    int letters = 0, digits = 0, spaces = 0, symbols = 0;

    int len = strlen(text);
    printf("len is %d\n", len);

    // Loop until we reach the end marker '\0'
    for (int i = 0; text[i] != '\0'; i++) {

        printf("%c ", text[i]);

        if (isalpha(text[i]))
            letters++;
        else if (isdigit(text[i]))
            digits++;
        else if (isspace(text[i]))
            spaces++;
        else if (ispunct(text[i]))
            symbols++; // check for symbols
    }
    printf("letters=%d digits=%d spaces=%d symbols=%d\n", letters, digits,
           spaces, symbols);

    // Convert to uppercase one character at a time
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = (char)toupper(text[i]);
    }
    printf("uppercase: %s\n", text);

    // A char is really a small number (its ASCII code)
    printf("'A' = %d, 'a' = %d\n", 'A', 'a');
    printf("'A' + 2 = %c\n", 'A' + 2); // prints C
}
