#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[]) {

    time_t now;
    time(&now);

    if (argc < 2) {
        puts("Hello handsome");
        printf("time is %ld\n", now);
        printf("time is %s\n", ctime(&now));
    } else {
        printf("hello %s\n", argv[1]);
    }

    return 0;
}
