#include "math.h"
#include "types.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include -> are preprocessor that runs before the file is compiled

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef i8 b8;
typedef i32 b32;
typedef bool b_std;
typedef int8_t b_8;
typedef int32_t b_32;

struct vec2f {
  f32 x;
  f64 y;
};

typedef struct {
  i8 r_angle;
  i16 r_hyp;
} vec_d;

typedef struct {
  u32 size;  // how many elements are in the array
  u32 *nums; // pointer to the first element of a dynamically allocated array
} num_array;

#define MAX 10
#define min(a, b) (a < b ? a : b)
#define BUFFER_SIZE 1024
#define DEBUG
#define ABS(n) ((n) < 0 ? -(n) : (n))
#define SIGN(n) ((n) < 0 ? -1 : 1)

typedef struct Node {
  int value;
  struct Node *next;
} Node;

#define PUSH_FRONT(head, node)                                                 \
  do {                                                                         \
    (node)->next = (head);                                                     \
    (head) = (node);                                                           \
  } while (0)

typedef enum {

  SHAPE_SQUARE,
  SHAPE_TRIANGLE,
  SHAPE_RECTANGLE
} ShapeKind;

int main() {

  ShapeKind kind = SHAPE_SQUARE;
  printf("kind is :%d\n", kind);

  Node n1 = {10, NULL};
  Node n2 = {20, NULL};

  Node *head = &n1;

  PUSH_FRONT(head, &n2);

  // Print the linked list
  Node *current = head;

  printf("\n");
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }

  printf("NULL\n");

  f32 weight = 19.0;
  b8 is_tall = true;
  b_std rich = true;

  printf("Variables with typedef: \n");
  printf("float is %.2f\n", weight);
  printf("tall?: %d\n", is_tall);
  printf("rich?: %d\n", rich);

  struct vec2f v;
  v.x = 1.0;
  v.y = 2.1;

  struct vec2f v1 = {1.1, 2.1};
  printf("printing vX: %.2f\n", v1.x);
  printf("printing vY: %.2f\n", v1.y);

  vec_d vd = {4, 8};
  vec_d vx = {
      .r_angle = 9,
      .r_hyp = 99,
  }; // if you omit .rhyp it will
     // initialize it as 0
  printf("vector d is %d\n", vd.r_angle);
  printf("vector d is %d %d\n", vx.r_angle, vx.r_hyp);

  // reuse vx/ reinitialize vx
  vx = (vec_d){.r_angle = 1, .r_hyp = 2};
  printf("vector d is %d %d\n", vx.r_angle, vx.r_hyp);

  // pointers
  i32 num = 123;
  i32 *ptr_num = &num; // the * can be on *ptr_num or on i32*
  printf("memory address of num is %ls\n",
         ptr_num); // memory address of num is 0x7ffdda59ddb8

  // modify the value at the address in memory
  *ptr_num = 321;
  printf("modified value is : %d\n", *ptr_num);

  // pointer to a struct
  vec_d vector = {2, 5};
  vec_d *p_vector = &vector;
  printf("memory address to vector: %p\n", p_vector);

  // access struct pointer member
  // first dereference
  // method 1
  (*p_vector).r_angle = 78;
  (*p_vector).r_hyp = 98;

  printf("New value of fields in vector vec_d : %d, %d\n", vector.r_angle,
         vector.r_hyp);

  // method 2
  p_vector->r_angle = 100;
  p_vector->r_hyp = 124;

  printf("New value of fields in vector vec_d : %d, %d\n", vector.r_angle,
         vector.r_hyp);

  // ARRAYS
  i64 nums[] = {1, 2, 3, 4}; // nums is an array of 4 i64 values

  size_t nums_elements = sizeof(nums) / sizeof(i64);
  size_t nums_size = sizeof(nums);
  size_t i64_size = sizeof(i64);

  printf("\nNumber of elements in nums array is: %zu\n"
         "sizeof(nums) = %zu bytes\n"
         "sizeof(i64) = %zu bytes\n",
         nums_elements, nums_size, i64_size);

  // Loop through the array

  for (i64 i = 0; i < nums_elements; i++) {
    printf("%lu ", nums[i]);
  }
  printf("\n");

  for (i64 i = 0; i < nums_elements; i++) {
    printf("index is %lu and value is %lu\n", i, nums[i]);
  }

  // Pointer arithmetic on arrays
  // The array name 'nums' decays to a pointer to its first element (i64 *)
  *nums = 9;        // Same as nums[0] = 9;, will only change the first element
                    // of the array i.e index 0
  *(nums + 1) = 10; // Same as nums[1] = 10;
  *(nums + 2) = 11; // Same as nums[2] = 11;
  *(nums + 3) = 12; // Same as nums[3] = 12;

  for (i64 i = 0; i < nums_elements; i++) {
    printf("index is %lu and value is %lu\n", i, nums[i]);
  }

  // You can also read values using pointer arithmetic.
  printf("\nUsing pointer arithmetic:\n");
  for (size_t i = 0; i < nums_elements; i++) {
    printf("index %zu -> value %ld\n", i, *(nums + i));
  }

  // allocate
  num_array arr;
  arr.size = 4;
  arr.nums = malloc(arr.size * sizeof(u32));

  for (u32 i = 0; i < arr.size; i++) {
    arr.nums[i] = (i + 1) * 10; // first time it will (0 + 1) * 10 = 10
  }

  for (u32 i = 0; i < arr.size; i++) {
    printf("%u ", arr.nums[i]);
  }
  printf("\n");

  // Use AddressSanitizer (ASan) to detect memory errors such as
  // memory leaks, buffer overflows, use-after-free, and more.
  //
  // Compile with AddressSanitizer:
  // gcc main.c -fsanitize=address -o main && ./main
  //
  // Compile with debugging symbols (recommended):
  // gcc main.c -fsanitize=address -g -o main && ./main
  // gcc main.c -fsanitize=address -Wall -Wextra -pedantic -g -o main && ./main
  //
  // Compile with debugging symbols and disable optimizations (best for
  // debugging): gcc main.c -fsanitize=address -g -O0 -o main && ./main
  //
  // Flags:
  //   -fsanitize=address  Enable AddressSanitizer.
  //   -g                  Generate debugging symbols for GDB and ASan reports.
  //   -O0                 Disable compiler optimizations to make debugging
  //   easier.

  free(arr.nums);
  arr.nums = NULL;
  arr.size = 0;

  // malloc with struct
  u32 num_vec = 3;
  vec_d *vects = (vec_d *)malloc(sizeof(vec_d) * num_vec);

  if (vects == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }

  // Initialize each struct in the dynamically allocated array
  for (u32 i = 0; i < num_vec; i++) {
    vects[i].r_angle = i;   // Same as i * 1
    vects[i].r_hyp = i * 2; // Example values
  }

  // Print each struct
  for (u32 i = 0; i < num_vec; i++) {
    printf("vects[%u] = { r_angle = %d, r_hyp = %d }\n", i, vects[i].r_angle,
           vects[i].r_hyp);
  }

  free(vects);
  vects = NULL;

  // gcc main.c math.c -fsanitize=address -g -O0 -o main && ./main
  i32 add_res = add(3, 5);
  printf("\naddition response is: %d\n", add_res);

  i32 max_ = 3 * MAX;
  printf("\n learning macro define: %d\n", max_);

  int min_res = min(2, 6);
  printf("\n parameter taking macro define: %d\n", min_res);

  char buffer[BUFFER_SIZE]; // you create an array of characters.

#ifdef DEBUG
  // strcpy(buffer, "judah"); // unsafe
  strncpy(buffer, "judah", BUFFER_SIZE - 1);
  buffer[BUFFER_SIZE - 1] = '\0'; // Ensure null termination
  printf("buffer = %s\n", buffer);
#endif

  // pointer to strings
  char *str = "Judah";
  printf("pointer literal: %s\n", str); // you create a pointer that can point
                                        // to a string literal or another
                                        // character array.

  i32 xx = 9;
  i32 absine = ABS(xx);
  printf("ABS: %d\n", absine);

  i32 xy = -9;
  i32 absine_negative = ABS(xy);
  printf("ABS: %d\n", absine_negative);

  i32 xw = 9;
  i32 absine_w = ABS(xw);
  printf("SIGN: %d\n", absine_w);

  i32 xh = -9;
  i32 absine_h = ABS(xh);
  printf("SIGN: %d\n", absine_h);

  return 0;
}
