#include <ctype.h>
#include <stdio.h>
#include <string.h>

int countVowels(char text[]) {
    int count = 0;
    for (int i = 0; i < strlen(text); i++) {
        char c = tolower(text[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    printf("%d\n", countVowels("Hello World")); // 3
    printf("%d\n", countVowels("bcd"));         // 0
    printf("%d\n", countVowels(""));            // 0
    printf("%d\n", countVowels("APPLE"));       // 2
    return 0;
}
