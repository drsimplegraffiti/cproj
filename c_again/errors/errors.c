
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/* Common Error Codes */

/* Error constants are defined in <errno.h>. You can compare errno to them to
 * detect specific issues: */
/* Error Code	Meaning */
/* ENOENT	No such file or directory */
/* EACCES	Permission denied */
/* ENOMEM	Not enough memory */
/* EINVAL	Invalid argument */

int main(void) {
    int a = 2;
    int b = 0;

    if (b == 0) {
        fprintf(stderr, "Error: Division by zero is not allowed.\n");
        // or use exit(1);
        //     exit(EXIT_FAILURE); // More readable than exit(1)
        return EXIT_FAILURE;
    }

    int res = a / b;

    printf("Result is %d\n", res);

    FILE *f = fopen("nothing.txt", "r");

    if (f == NULL) {
        if (errno == ENOENT) {
            printf("The file was not found.\n");
        } else {
            printf("Some other file error occurred.\n");
        }
        return 1;
    }

    fclose(f);

    return EXIT_SUCCESS;
}
