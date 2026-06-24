#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("How many numbers? ");
  scanf("%d", &n);

  // Allocate memory for n integers
  int *numbers = malloc(n * sizeof(int)); // numbers is a pointer to int
  if (!numbers) {
    perror("malloc failed");
    return 1;
  }

  // Read numbers from user
  for (int i = 0; i < n; i++) {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &numbers[i]);
  }

  // Print numbers
  printf("Numbers entered:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  free(numbers); // free the allocated memory
  return 0;
}
