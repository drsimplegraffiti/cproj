// self calling function
#include <stdio.h>

void rec(int n) {

    // Base Case
    if (n == 6) {
        printf("Bingo hit the base \n");
        return;
    }

    printf("Recursion Level %d\n", n);
    rec(n + 1);
}

int main() {
    rec(1);
    return 0;
}
