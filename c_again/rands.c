#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SQUARE(x) ((x) * (x))
#define DEBUG // to switch off comment out

int main(void) {
    // Note: If you run this program several times, you will see the same number
    // each time. This is because we have not set a seed yet.
    int r = rand();
    printf("rand num is %d\n", r);

    /* to sort this */
    srand(time(NULL)); // seed with current time

    int rr = rand();
    printf("rand num is %d\n", rr);

    /* rand() % 10 gives the remainder when the random number is divided by 10,
     * which is always a number from 0 to 9. In general, rand() % n gives a
     * number from 0 to n - 1. */
    int rrr = rand() % 10; // 0 to 9
    printf("rand num is %d\n", rrr);

    // get numbers
    int min = 10;
    int max = 20;
    int x = rand() % (max - min + 1) + min; // 10 to 20

    printf("%d\n", x);

    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;
    printf("You rolled %d and %d (total = %d)\n", dice1, dice2, dice1 + dice2);

    int res = SQUARE(2);
    printf("res is %d\n", res);

#ifdef DEBUG
    printf("Debug mode is ON\n");
#endif

    /* The auto keyword is used for local variables. It is the default for
     * variables declared inside functions, so it's rarely used explicitly. */
    auto int yy = 90;
    printf("auto is %d\n", yy);

    return 0;
}
