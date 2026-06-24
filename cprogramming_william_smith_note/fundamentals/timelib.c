#include <stdio.h>
#include <time.h>

/*
========================================================
TIME LIBRARY FUNCTIONS TL;DR
========================================================
- time()     : Get current calendar time (time_t)
- clock()    : Get CPU time used by program (clock_t)
- difftime() : Difference in seconds between two time_t
- asctime()  : Convert struct tm to readable string
========================================================
*/

int main() {
  // 1) Current calendar time
  time_t now = time(NULL);
  printf("Current calendar time (epoch) = %ld\n", now);

  // 2) Processor time used
  clock_t start = clock();
  for (volatile int i = 0; i < 1000000; i++)
    ; // dummy work
  clock_t end = clock();
  double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("CPU time used = %f seconds\n", cpu_time);

  // 3) Difference between two time points
  time_t t1 = time(NULL);
  for (volatile int i = 0; i < 500000; i++)
    ; // dummy work
  time_t t2 = time(NULL);
  double diff = difftime(t2, t1);
  printf("Time elapsed = %f seconds\n", diff);

  // 4) Convert time structure to string
  struct tm *tm_info = localtime(&now);
  printf("Readable time = %s", asctime(tm_info));

  return 0;
}
