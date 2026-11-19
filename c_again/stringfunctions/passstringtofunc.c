#include <stdio.h>

void printStr(char str[]) { printf("%s", str); }

int main() {
    char str[] = "GeeksforGeeks";

    // Passing string to a
    // function
    printStr(str);
    return 0;
}
