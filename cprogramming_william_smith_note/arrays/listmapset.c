#include <stdio.h>
#include <string.h>

// ------------------------------
// Map implementation: key-value pair
// ------------------------------
typedef struct {
  char key[20];
  int value;
} KeyValuePair;

int main() {
  // ------------------------------
  // 1. List (ordered collection)
  // ------------------------------
  int list[5] = {1, 2, 3, 4, 5};
  printf("List elements: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");

  // ------------------------------
  // 2. Set (unique elements, simple check)
  // ------------------------------
  int set[5] = {1, 2, 3, 4, 5};
  int valueToCheck = 3;
  int exists = 0;
  for (int i = 0; i < 5; i++) {
    if (set[i] == valueToCheck) {
      exists = 1;
      break;
    }
  }
  if (exists) {
    printf("%d exists in the set\n", valueToCheck);
  } else {
    printf("%d does not exist in the set\n", valueToCheck);
  }

  // ------------------------------
  // 3. Map (key-value pairs)
  // ------------------------------
  KeyValuePair map[2] = {{"apple", 1}, {"banana", 2}};
  char key[20] = "banana";
  int mapValue = 0;

  for (int i = 0; i < 2; i++) {
    if (strcmp(map[i].key, key) == 0) {
      mapValue = map[i].value;
      break;
    }
  }

  if (mapValue != 0) {
    printf("The value of %s is %d\n", key, mapValue);
  } else {
    printf("%s does not exist in the map\n", key);
  }

  return 0;
}
