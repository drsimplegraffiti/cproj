/* “string tokenizer” */
/* Defined int the <string.h> */

/* char *strtok(char *str, const char *delim); */

/* The first argument, str , is the string to scan. The second argument, delim ,
 * is a string containing the individual */
/* characters that can separate, or delimit, the character chunks you want to
 * parse. The value returned is a char */
/* pointer referencing the character chunk found. For example: */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* Convert a NATO phonetic alphabet word into its corresponding letter. */
int isterm(const char *term) {
    const char *nato[] = {"Alfa",    "Bravo",  "Charlie", "Delta",    "Echo",
                          "Foxtrot", "Golf",   "Hotel",   "India",    "Juliett",
                          "Kilo",    "Lima",   "Mike",    "November", "Oscar",
                          "Papa",    "Quebec", "Romeo",   "Sierra",   "Tango",
                          "Uniform", "Victor", "Whiskey", "Xray",     "Yankee",
                          "Zulu"};

    for (int x = 0; x < 26; x++) {
        const char *n = nato[x];
        const char *t = term;

        /* Compare characters without considering letter case. */
        while (*n && *t &&
               tolower((unsigned char)*n) == tolower((unsigned char)*t)) {
            n++;
            t++;
        }

        /* Both strings must end together for an exact match. */
        if (*n == '\0' && *t == '\0')
            return 'A' + x;
    }

    return '\0';
}

int main(void) {
    char phrase[64];
    char *match;

    printf("NATO word or phrase: ");

    if (fgets(phrase, sizeof(phrase), stdin) == NULL)
        return 1;

    /* Split the input into tokens using common delimiters. */
    match = strtok(phrase, " ,.!?:;\"'\n\t");

    while (match != NULL) {
        int ch = isterm(match);

        if (ch != '\0')
            putchar(ch);

        match = strtok(NULL, " ,.!?:;\"'\n\t");
    }

    putchar('\n');

    return 0;
}

/* int main() { */
/*     char sometext[64]; */
/*     char *match; */
/*     printf("Type some text: "); */
/*     fgets(sometext, 64, stdin); */
/*     /1* match = strtok(sometext, " "); *1/ */
/*     match = strtok(sometext, " ,.!?:;\"'"); */
/*     while (match) { */
/*         printf("%s\n", match); */
/*         match = strtok(NULL, " "); */
/*     } */
/*     return (0); */
/* } */

/* When separators other than the space appear in the string, */
/* they’re included in the character chunk match: */
