# C Time Example: Using All Common Time Functions

This example demonstrates **getting current time, formatting, measuring execution time, and delays** in a single C program.

```c
#include <stdio.h>
#include <time.h>
#include <unistd.h> // For sleep()

int main() {
    // 1. Get current time as time_t
    time_t now = time(NULL);
    printf("Raw time (seconds since Epoch): %ld\n", now);

    // 2. Convert to human-readable format using ctime()
    printf("Current time (ctime): %s", ctime(&now));

    // 3. Convert to local time using struct tm
    struct tm *local = localtime(&now);
    printf("Local Date: %02d-%02d-%d\n", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
    printf("Local Time: %02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);

    // 4. Format using strftime()
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%A, %d %B %Y %H:%M:%S", local);
    printf("Formatted time: %s\n", buffer);

    // 5. Measure execution time using clock()
    clock_t start = clock();
    for (long i = 0; i < 100000000; i++); // dummy loop
    clock_t end = clock();
    double cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("CPU time for loop: %f seconds\n", cpu_time);

    // 6. Compute difference between two time points using difftime()
    time_t later = time(NULL);
    double diff = difftime(later, now);
    printf("Elapsed wall-clock time: %.0f seconds\n", diff);

    // 7. Pause execution using sleep()
    printf("Sleeping for 2 seconds...\n");
    sleep(2);
    printf("Awake now!\n");

    return 0;
}

```
