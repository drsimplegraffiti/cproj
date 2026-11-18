
#include <stdio.h>
#include <string.h>

int main(void) {
    int number = 0;
    char name[100];
    char input[100];

    // =========================================
    // 1. Read a number between 1 and 5
    // =========================================

    do {
        printf("Choose a number between 1 and 5: ");

        if (scanf("%d", &number) != 1) {
            number = 0;
        }

        // Clear the input buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

    } while (number < 1 || number > 5);

    printf("You chose: %d\n\n", number);

    // =========================================
    // 2. Read the user's name
    // =========================================

    do {
        printf("Enter your name: ");

        if (fgets(name, sizeof(name), stdin) == NULL) {
            return 1;
        }

        // Remove trailing newline
        name[strcspn(name, "\n")] = '\0';

    } while (strlen(name) == 0);

    printf("Hello, %s\n\n", name);

    // =========================================
    // 3. Read a valid integer using fgets()
    // =========================================

    while (1) {
        printf("Enter a number: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            return 1;
        }

        // Try converting input to an integer
        if (sscanf(input, "%d", &number) == 1) {
            break;
        }

        printf("Invalid input. Please enter an integer.\n");
    }

    printf("You entered: %d\n", number);

    return 0;
}
