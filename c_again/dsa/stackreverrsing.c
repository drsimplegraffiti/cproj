#include <stdio.h>
#include <string.h>

int main() {
    char word[] = "HELLO";
    int length = strlen(word);
    char stack[20];
    int top = -1;

    // Push every letter
    for (int i = 0; i < length; i++) {
        top++;
        stack[top] = word[i];
    }

    // Pop every letter
    printf("Reversed: ");
    while (top != -1) {
        printf("%c", stack[top]);
        top--;
    }
    printf("\n");

    return 0;
}
