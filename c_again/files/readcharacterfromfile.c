
#include <stdio.h>
#include <string.h>

// Read on character at a time from a file
int main(void) {

    FILE *fp;
    int c;
    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("error opening file\n");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);
    return 0;
}
