#include <stdio.h>

int main() {

    int scores[] = {72, 61, 95, 88};
    int length = sizeof(scores) / sizeof(scores[0]);
    int highest = scores[0];

    printf("length : %d\n", length);
    printf("highest: %d\n", highest);

    for (int i = 1; i < length; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }

    printf("Highest score: %d\n", highest);
    return 0;
}
