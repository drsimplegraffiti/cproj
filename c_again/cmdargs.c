#include <stdio.h>
#include <stdlib.h>

/* argc (argument count) is the number of arguments. The program name counts
 * too. */
/* argv (argument vector, which means a list of arguments) holds the arguments
 * as strings, like an array of strings. argv[0] is the program */

/* NOTE: Arguments Are Strings */
int main(int argc, const char *argv[]) {

    printf("argc %d\n", argc);
    if (argc < 2) {
        printf("make args at least 2\n");
        return 1;
    }
    printf("you ran: %s\n", argv[1]);

    int b = atoi(argv[2]);

    printf("int b %d\n", b);
    return 0;
}
