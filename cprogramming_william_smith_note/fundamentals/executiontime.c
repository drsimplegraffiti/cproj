#include <stdio.h>
#include <time.h> // Needed for clock() and CLOCKS_PER_SEC

// Example function whose execution time we want to measure
void example_function() {
  long sum = 0;
  for (long i = 0; i < 100000000000000; i++) {
    sum += i; // Some computation
  }
  // Just to prevent compiler optimizing the loop away
  printf("Sum: %ld\n", sum);
}

int main() {
  // Record the starting clock ticks
  clock_t start = clock();

  // Call the function we want to measure
  example_function();

  // Record the ending clock ticks
  clock_t end = clock();

  // Calculate total clock ticks taken
  clock_t ticks = end - start;

  // Convert clock ticks to seconds
  double time_taken = (double)ticks / CLOCKS_PER_SEC;

  // Print the results
  printf("Clock ticks: %ld\n", ticks);
  printf("Execution time: %.6f seconds\n", time_taken);

  return 0;
}
