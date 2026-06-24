#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n; // number of animals (we don’t know at compile time)
  printf("How many animals? ");
  scanf("%d", &n);

  // Allocate memory for an array of pointers to strings
  // animals is a pointer to a pointer to char: char**
  // - animals[i] will be a pointer to a single string (char*)
  char **animals = malloc(n * sizeof(char *));
  if (!animals) {
    perror("malloc failed");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    // Allocate memory for each animal name
    // Each animals[i] is a char* pointing to the actual string
    animals[i] =
        malloc(50 * sizeof(char)); // max 49 characters + null terminator
    printf("Enter animal %d: ", i + 1);
    scanf("%49s", animals[i]); // read string safely (avoid buffer overflow)
  }

  printf("Animals entered:\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", animals[i]); // print each string
    free(animals[i]);           // free each allocated string
  }

  free(animals); // free the array of pointers
  return 0;
}
