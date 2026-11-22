#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {

    int numbers[] = {1, 2, 3};
    printf("numers is %d\n", numbers[0]);

    int si = sizeof(numbers) / sizeof(numbers[0]);
    printf("size of t is %d\n", si);

    for (int i = 0; i < si; i++) {
        printf("i is %d\n", i);
    }

    char name[] = "james";
    /* Every string in C ends with a special character called null character */

    int size_name = sizeof(name); // instead of 5 we have 6 with null character
    printf("size of string %d\n", size_name);

    char greetings[] = {'h', 'e', 'l', 'l', 'o', '\0'}; // without the \0 you
                                                        // get a buffer
                                                        // overflow
    printf("greetings is %c\n", greetings[0]);
    printf("greetings is %s\n", greetings);

    int ln = strlen(greetings);
    printf("string length is %d\n", ln);

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%zu\n", strlen(alphabet)); // 26
    printf("%zu\n",
           sizeof(alphabet)); // 27 sizeof includes the \0 when counting

    // It is also important that you know that sizeof will always return the
    // memory size (in bytes), and not the actual string length:

    /* concat */
    char charone[120] = "Hello";
    char chartwo[120] = " there";
    strcat(charone, chartwo);
    printf("charones is %s\n", charone);
    /* strncat() */

    /* The strncat() function appends at most n characters from the source
     * string to the end of the destination string. It automatically adds a null
     * terminator after the appended characters. */

    /*     It is declared in the <string.h> header file. */
    /*     The destination array must have enough space to store the resulting
     * string. */
    /* char s1[30] = "Hello, "; */
    /*     char s2[] = "Geeks!"; */

    /*     // Appends "Geeks!" to "Hello, " */
    /*     strncat(s1, s2, 4); */
    /*     printf("%s", s1); */

    char str1[20] = "Hello there";
    char str2[30];

    strcpy(str2, str1);
    printf("%s\n", str2);

    printf("compared: %d\n", strcmp(charone, chartwo));

    // character function
    char c = ' ';
    if (isdigit(c)) {
        printf("is a digit \n");
    } else if (isalpha(c) && islower(c)) {
        printf("is alphabet and lower \n");
    } else if (isupper(c)) {
        printf("is upper\n");
    } else if (isspace(c)) {
        printf("is white space \n");
    }

    // change characters
    char my_grade = 'a';
    char toupper_grade = toupper(my_grade);
    char tolower_grade = tolower(my_grade);
    printf("%c %c \n", tolower_grade, toupper_grade);

    // array of strings
    /* The first number (3) is how many strings the array can hold. The second
     * number (10) is the size of */
    /*     each string, including the \0 at the end (see The Null Character). So
     * each fruit can have up */
    /*     to 9 letters. */

    char fruits[3][10] = {"Apple", "Banana", "Cherry"};

    printf("%s\n", fruits[0]);

    // pointer to pointer
    int m = 90;        // normal variable
    int *ptr = &m;     // pointer to int
    int **pptr = &ptr; //  pointer to pointer

    printf("%d\n", m);
    printf("*ptr: %d\n", *ptr);
    printf("**ptr %d\n", **pptr);
}

//
// gcc main.c -g -Wall -Wextra -Werror  -std=c2x -fsanitize=address -pedantic -o
// main && ./main

// gcc -Wall -Wextra -Wpedantic -std=c11 -o program program.c
// Treat warnings as errors. If you get a segfault, run it under:
// valgrind --leak-check=full ./program
// or compile with:
// gcc -fsanitize=address,undefined -g ...
//
