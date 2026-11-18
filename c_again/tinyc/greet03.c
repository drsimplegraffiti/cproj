#include <stdio.h>
#include <time.h>

// prototype
// The function returns an integer in the range of 0 to 7
int moon_phase(int year, int month, int day);

char *phase[8] = {
    "waxing crescent", "at first quarter", "waxing gibbous",  "full",
    "waning gibbous",  "at last quarter",  "waning crescent", "new"};

int main(int argc, const char *argv[]) {

    time_t now;
    struct tm *clock;
    char time_string[64];

    time(&now);
    clock = localtime(&now);

    /* check man strftime */
    strftime(time_string, 64,
             "Century is %C, PM/AM is %p, Today is %A, %B %d, %Y%nIt is %r%n",
             clock);
    printf("Greetings");
    if (argc > 1)
        printf(", %s", argv[1]);
    printf("!\n%s", time_string);

    printf("\n\n");
    int mp;
    mp = moon_phase(clock->tm_year + 1900, clock->tm_mon, clock->tm_mday);
    printf("The moon is %s\n", phase[mp]);

    return 0;
}

int moon_phase(int year, int month, int day) {
    int d, g, e;
    d = day;
    if (month == 2)
        d += 31;
    else if (month > 2)
        d += 59 + (month - 3) * 30.6 + 0.5;
    g = (year - 1900) % 19;
    e = (11 * g + 29) % 30;
    if (e == 25 || e == 24)
        ++e;
    return ((((e + d) * 6 + 5) % 177) / 22 & 7);
}

/* A segmentation fault means your program accessed memory it shouldn't. */
/*  [1]    1823867 segmentation fault (core dumped)  ./main james */
/* clang -Wall -Wextra -Wpedantic -g tinyc/greet03.c -o main */
/* sudo apt install gdb */
/* gdb ./main */
/* run james */
/* When it crashes, run backtrace */
/* bt */

/* or better use: */
/* clang -Wall -Wextra -Wpedantic -g \ */
/* -fsanitize=address,undefined \ */
/* -fno-omit-frame-pointer \ */
/* tinyc/greet03.c -o main */

/* then run ./main */
/* gcc -Wall -Wextra -Wpedantic -g \ */
/* -fsanitize=address,undefined \ */
/* -fno-omit-frame-pointer \ */
/* tinyc/greet03.c -o main */
