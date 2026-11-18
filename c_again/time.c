#include <stdio.h>
#include <time.h>

int main(void) {

    time_t current_time;
    time(&current_time); // get the current time
    printf("time is %s\n", ctime(&current_time));

    time_t now = time(NULL);        // Get current time
    struct tm *t = localtime(&now); // Convert to local time structure

    printf("Year: %d\n", t->tm_year + 1900); // Add 1900 to get the actual year
    printf("Month: %d\n", t->tm_mon + 1);    // Add 1, because months start at 0
    printf("Day: %d\n", t->tm_mday);
    printf("Hour: %d\n", t->tm_hour);
    printf("Minute: %d\n", t->tm_min);
    printf("Second: %d\n", t->tm_sec);

    // format time
    char buffer[100];

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", t);
    printf("Formatted time: %s\n", buffer);
    return 0;
}
