

#include <stdio.h>

int main(void) {
    int age = 25;

    switch (age) {
        case 20:
            printf("You are 20 years old.\n");
            break;

        case 25:
            printf("You are 25 years old.\n");
            [[fallthrough]];

        case 10:
            printf("You are 10 years old.\n");
            [[fallthrough]];

        default:
            printf("Unknown case.\n");
            break;
    }

    return 0;
}
