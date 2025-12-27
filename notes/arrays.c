#include <stddef.h>
#include <stdio.h>

int main() {

  // Arrays are fixed size, known size
  int array[] = {1, 2, 3, 4, 5, 6};

  // array[7] = 19; // 1. clang: Array index 7 is past the end of the array
  // (that has type 'int[6]') [-Warray-bounds]
  array[5] = 19; // last element
  printf("Index four: %d \n", array[5]);

  size_t size_of_array = sizeof(array); // 6 elements * 4 byte each = 24
  size_t size_of_array_index = sizeof(array[0]); // index 0 is 4

  printf("%zu\n", size_of_array);
  printf("%zu\n", size_of_array_index);
  int n = sizeof(array) / sizeof(array[0]); // 24/4
  printf("Array lenght is : %d\n", n);      // 6
  //
  //
  // Print array elements
  for (int i = 0; i < n; i++) {
    printf("Element : %d\n", array[i]);
  }

  // array declaration and initialization
  int arr[5] = {2, 4, 8, 12, 16};

  // accessing element at index 2 i.e 3rd element
  printf("Index two: %d \n", arr[2]);

  // accessing element at index 4 i.e last element
  printf("Index 4 : %d \n", arr[4]);

  // accessing element at index 0 i.e first element
  printf("Index 0: %d \n", arr[0]);

  return 0;
}
