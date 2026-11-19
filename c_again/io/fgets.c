

#include <stdio.h>
int main(void) {

    char name[100]; // jude okafor

    printf("what's your name: ");

    /* char *fgets(char s[restrict .size], int size, FILE *restrict stream); */
    /* scanf("%s", name); //prints out just jude */
    fgets(name, sizeof(name), stdin);

    printf("my is %s\n", name);
}
