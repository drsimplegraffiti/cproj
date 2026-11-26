
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;

    int x = 32;
    fp = fopen("data.txt", "w"); // send to the file
    /* fp = stdout; // this will output to the console */
    if (fp == NULL) {
        return EXIT_FAILURE;
    }

    char c = 'B';
    fputc(c, fp);
    fputc('\n', fp);
    fprintf(fp, "x = %d\n", x);
    fputs("Hello, world!\n", fp);
    fclose(fp);
}
