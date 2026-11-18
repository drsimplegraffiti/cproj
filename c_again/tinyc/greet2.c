#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[]) {
    time_t now;

    struct tm *clock;
    int hour;
    int min;

    time(&now);
    clock = localtime(&now);
    hour = clock->tm_hour;
    min = clock->tm_min;

    /* %02d	Integer padded to 2 digits */
    printf("Clock address: %p\n", (void *)clock);
    printf("Current time: %02d:%02d\n", hour, min);

    printf("Good ");
    if (hour < 12) {
        printf("morning, time is %02d:%02d\n", hour, min);
    } else if (hour < 17) {
        printf("afternoon\n");
    } else {
        printf("evening\n");
    }

    if (argc > 1)
        printf(", %s", argv[1]);

    putchar('\n');
    return 0;
}

/* gcc -Wall -Wextra -Wpedantic main.c -o main */
