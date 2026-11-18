/* NATO stands for the North Atlantic Treaty Organization. */
/* ### Table 3.1: The NATO Phonetic Alphabet */

/* | Letter | NATO | Letter | NATO | */
/* |:------:|-------|:------:|-------| */
/* | A | Alfa | N | November | */
/* | B | Bravo | O | Oscar | */
/* | C | Charlie | P | Papa | */
/* | D | Delta | Q | Quebec | */
/* | E | Echo | R | Romeo | */
/* | F | Foxtrot | S | Sierra | */
/* | G | Golf | T | Tango | */
/* | H | Hotel | U | Uniform | */
/* | I | India | V | Victor | */
/* | J | Juliett | W | Whiskey | */
/* | K | Kilo | X | Xray | */
/* | L | Lima | Y | Yankee | */
/* | M | Mike | Z | Zulu | */

/* NATO stands for the North Atlantic Treaty Organization. */

#include <ctype.h> // Provides character functions such as toupper() and isalpha()
#include <stdio.h> // Provides input/output functions such as printf(), fgets(), and putchar()

// Array of strings containing the NATO phonetic alphabet.
// Each index corresponds to a letter: A = 0, B = 1, ..., Z = 25.
const char *nato[] = {
    "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
    "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
    "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
    "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

const char *fuzz[] = {
    "Adam",   "Boy",     "Charles", "David",  "Edward",  "Frank", "George",
    "Henry",  "Ida",     "John",    "King",   "Lincoln", "Mary",  "Nora",
    "Ocean",  "Paul",    "Queen",   "Robert", "Sam",     "Tom",   "Union",
    "Victor", "William", "X-ray",   "Young",  "Zebra"};

int main(void) {
    char phrase[64]; // Character array that stores the user's input (up to 63
                     // characters + '\0')
    char ch;         // Temporarily stores each character being processed
    int i;           // Tracks the current position (index) in the phrase array

    printf("Enter a word phrase: "); // Prompts the user to enter a phrase

    // Reads user input from standard input into phrase.
    // Returns NULL if reading fails.
    if (fgets(phrase, sizeof(phrase), stdin) == NULL) {
        return 1; // Terminates the program if input reading fails
    }

    i = 0; // Initializes the array index to the first character

    // Continues looping until the null terminator '\0' is encountered.
    while (phrase[i]) {
        /* printf("\n character currently:  %c\n", phrase[i]); */

        // Converts the current character to uppercase.
        // The unsigned char cast ensures safe use with toupper().
        ch = (char)toupper((unsigned char)phrase[i]);

        // Checks whether the character is an alphabetic letter.
        if (isalpha((unsigned char)ch)) {

            // Converts the letter into an array index:
            // 'A' - 'A' = 0, 'B' - 'A' = 1, ..., 'Z' - 'A' = 25.
            // Uses that index to retrieve the corresponding NATO word.
            /* printf("\n\n%s we picked:: ", nato[ch - 'A']); */
            printf("%s ", fuzz[ch - 'A']);
            /* printf("%s ", nato[ch - 'A']); */
        }

        i++; // Moves to the next character, even if the current one is a space
             // or punctuation
    }

    putchar('\n'); // Prints a newline after the NATO words

    return 0; // Indicates successful program execution
}
