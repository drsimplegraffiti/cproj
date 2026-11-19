#include <stdio.h>

/* An enum is a special type that represents a group of constants (unchangeable
 * values). */
enum Level { LOW = 1, MEDIUM, HIGH };

enum Level2 { LOW1 = 25, MEDIUM1 = 50, HIGH1 = 75 };

int main() {

    // Create an enum variable and assign a value to it
    enum Level myVar = MEDIUM;
    enum Level myVarLow = LOW;

    // Print the enum variable
    printf("%d\n", myVar);
    printf("%d\n", myVarLow);

    switch (myVar) {
        case 1:
            printf("Low Level");
            break;
        case 2:
            printf("Medium level");
            break;
        case 3:
            printf("High level");
            break;
    }

    enum Level2 myVar2 = MEDIUM1;
    printf("%d", myVar2); // Now outputs 50
    return 0;
}
