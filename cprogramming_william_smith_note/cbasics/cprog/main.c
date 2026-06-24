// # == preprocessor are used for include directives or macro
// definitions#include "math_utils.h"#include <inttypes.h> // for portable int64
// printing
#include "math_utils.h" // custom header (must exist)
#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h> // use this instead of the primitives inbuilt types
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for time()

// signed int
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// unsigned int
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

// fractions
typedef float f32;
typedef double f64;

// bools
typedef i8 b8;
typedef i32 b32;

// struct
struct vec2f {
  f32 x;
  f64 y;
};

// typedef with struct
typedef struct {
  i8 a;
  i16 b;
} vec1f;

typedef enum { TYPE_INT, TYPE_FLOAT } Type;

typedef struct {
  Type type;
  union {
    int i;
    float f;
  } value;
} Variant;

#define PI 3.14
#define MAX(x, y) (x > y ? x : y)

typedef enum { POSITION_LOW = 0, POSITION_MID = 1, POSITION_HIGH = 2 } Position;

union Data {
  int i;
  float f;
};

typedef enum { ERR_OK = 0, ERR_NULL_POINTER, ERR_NEGATIVE_INPUT } ErrorCode;

ErrorCode divide_safe(i32 a, i32 b, i32 *result) {
  if (!result)
    return ERR_NULL_POINTER;
  if (b == 0)
    return ERR_NEGATIVE_INPUT;

  *result = a / b;
  return ERR_OK;
}

// c contract -> function prototype
void greet();
void file_example();
void custom_error_example();

int main() {

  // primitives
  int my_age = 19;
  char grade = 'A';

  i32 age = 90;
  i64 weight = 909;

  // using macros
  // the preprocessor will run and insert the actual value
  f32 actual_age = PI;
  printf("Using Macros: %f\n", actual_age);

  i32 num1 = 6;
  i32 num2 = 8;
  printf("max of num1 and num2 is: %d\n", MAX(num1, num2));

  bool is_tall = true;
  printf("tall: %d\n", is_tall);
  b8 is_short = true;

  // Print boolean (C prints as integer 0 or 1)
  printf("short: %d\n", is_short);

  // enums
  printf("\n--- Enums ---\n");

  Position pos;

  // assign using enum constant
  pos = POSITION_HIGH;

  if (pos == POSITION_HIGH) {
    printf("Position is HIGH (%d)\n", pos);
  } else if (pos == POSITION_MID) {
    printf("Position is MID (%d)\n", pos);
  } else if (pos == POSITION_LOW) {
    printf("Position is LOW (%d)\n", pos);
  }

  // random number using the stdlib.h and time
  // Seed random number generator (do this once)
  srand((unsigned int)time(NULL));

  // Generate random numbers
  int random_number = rand();            // 0 to RAND_MAX
  i32 random_0_9 = rand() % 10;          // 0 - 9
  i32 random_1_100 = (rand() % 100) + 1; // 1 - 100

  printf("Random number (0 - RAND_MAX): %d\n", random_number);
  printf("Random number (0 - 9): %d\n", random_0_9);
  printf("Random number (1 - 100): %d\n", random_1_100);
  // struct
  struct vec2f v;
  v.x = 18.0f;
  v.y = 19.0;

  // struct with typedef
  // Designated initializer
  vec1f v1 = {13, 14};
  printf("v1 vector is %d, %d \n", v1.a, v1.b);
  printf("Size of struct: %zu bytes\n", sizeof(v1));
  // x (4 bytes)
  //  y (4 bytes)

  vec1f v3 = {
      .a = 89, // if a is not set it becomes zero automatically
      .b = 89  // positional arguements
  };
  printf("Vector v3= < %d, %d > \n", v3.a, v3.b);

  // Compound literal (NOT a cast)
  v3 = (vec1f){.a = 9, .b = 10};
  printf("Vector v3 after casting= < %d, %d > \n", v3.a, v3.b);

  // Print struct members individually
  printf("vector is (%.2f, %.2lf)\n", v.x, v.y);
  printf("Vector v1 = < %d, %d > \n", v1.a, v1.b);

  printf("age is: %d\n", age);
  printf("Weight is: %" PRId64 "\n", weight);
  // PRId64 expands to either "lld" or "ld" depending on the
  // platform
  // so when you write printf("%" PRId64 "\n", value); the
  // preprocessor changes it to printf("%lld\n", value); or
  // printf("%ld\n", value); PRI → Print d → signed decimal 64 →
  // 64-bit
  //
  //

  // Unions
  union Data d;

  d.i = 10;
  printf("i = %d\n", d.i);

  d.f = 3.14f; // overwrites same memory
  printf("f = %f\n", d.f);

  printf("Size of union: %zu bytes\n", sizeof(d));

  Variant va;

  va.type = TYPE_INT;
  va.value.i = 42;

  if (va.type == TYPE_INT)
    printf("int = %d\n", va.value.i);

  // pointers
  i32 xx = 89; // this has place in memory in the program in your physical ram
               // pointer is a number that points to the address of the variable
  i32 *pxx = &xx; // the * can be close to i32 like i32* or *pxx or i32 * pxx
  printf("memory address of xx is %p and the real value is %d \n", pxx, xx);

  // set another value to the address
  *pxx = 130; // go to where pxx is in memory and override this value of 130
  printf("memory address of xx is %p and the real value is %d \n", pxx, xx);

  // pointer to struct
  vec1f v4 = {.a = 19, .b = 23};
  vec1f *pv4 = &v4;
  // dereference the pointer to get the real value
  printf("initial vector before pointer %d %d\n", v4.a, v4.b);

  // method 1 to dereference and access the member
  // explicit dereference
  // arrow operator
  (*pv4).a = 20;
  (*pv4).b = 16;
  printf("initial vector after pointer %d %d\n", v4.a, v4.b);

  // method 2 to dereference and access the member
  pv4->a = 25;
  pv4->b = 16;
  printf("initial vector after pointer using -> %d %d\n", v4.a, v4.b);

  // arrays
  // here we are allocating memories that we know at compile time
  // stack memory
  i32 numbers[] = {1, 2, 3, 4};
  printf("index 0 is: %d \n", numbers[0]);
  // loop through an array
  for (i32 i = 0; i < 3; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  // in C
  // therefore: *numbers == numbers[0]
  // Is exactly the same as: numbers[0] = 6;
  // Now array becomes: 6 2 3 4
  // array name == pointer to first element
  // Array decay & pointer arithmetic
  *numbers = 6;
  // Pointer Arithmetic
  // numbers + 1   → move 1 element forward
  // Now array becomes: 6 90 3 4
  *(numbers + 1) = 90;

  for (i32 i = 0; i < sizeof(numbers) / sizeof(numbers[0]);
       i++) { // better practice
    printf("%d ", numbers[i]);
  }
  printf("\n");

  // allocating dynamic memory using stdlib.h
  // heap memory
  // dynamic memory allocation (heap) using:
  // malloc
  // calloc
  // realloc
  // free

  printf("\n--- Dynamic Memory (malloc) ---\n");

  i32 count = 4;

  // allocate memory for 4 i32 elements
  i32 *dyn_numbers = malloc(count * sizeof(i32));
  // If i32 = 4 bytes and count = 4
  // malloc(4 * 4) = malloc(16 bytes)

  if (dyn_numbers == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // assign values
  for (i32 i = 0; i < count; i++) {
    dyn_numbers[i] = (i + 1) * 10;
  }

  // print values
  for (i32 i = 0; i < count; i++) {
    printf("%d ", dyn_numbers[i]);
  }
  printf("\n");

  // always free heap memory
  free(dyn_numbers);
  dyn_numbers = NULL; // good practice
                      //
                      //
                      // Using calloc (zero-initialized)
  printf("\n--- Dynamic Memory (calloc) ---\n");

  i32 *zero_numbers = calloc(4, sizeof(i32));

  if (!zero_numbers) {
    printf("Calloc failed!\n");
    return 1; // or return EXIT_FAILURE
  }

  for (i32 i = 0; i < 4; i++) {
    printf("%d ", zero_numbers[i]); // prints 0 0 0 0
  }
  printf("\n");

  free(zero_numbers);
  zero_numbers = NULL;

  // realloc (resize memory)
  printf("\n--- Realloc Example ---\n");

  i32 *resize_array = malloc(2 * sizeof(i32));

  if (!resize_array) {
    perror("malloc failed");
    return -1;
  }

  resize_array[0] = 1;
  resize_array[1] = 2;

  // increase size to 4 elements
  resize_array = realloc(resize_array, 4 * sizeof(i32));
  if (!resize_array) {
    perror("realloc failed");
    free(resize_array); // free original
    return EXIT_FAILURE;
  }

  resize_array[2] = 3;
  resize_array[3] = 4;

  for (i32 i = 0; i < 4; i++) {
    printf("%d ", resize_array[i]);
  }
  printf("\n");

  free(resize_array);
  resize_array = NULL;

  /* ---------------- Functions ---------------- */
  greet();

  // import files from different source
  i32 res = add(2, 5);
  printf("Imported math utility function result: %d\n", res);
  // so in math_utils.h
  // #ifndef MATH_UTILS_H // Include guard (prevents double inclusion)
  // #define MATH_UTILS_H
  //
  // // Function declarations (prototypes)
  // int add(int a, int b);
  // int multiply(int a, int b);
  //
  // #endif
  // and in math_utils.c
  // #include "math_utils.h"

  // Function definitions
  // int add(int a, int b) { return a + b; }
  //
  // int multiply(int a, int b) { return a * b; }
  // run with: gcc main.c math_utils.c -o program && ./program

  file_example();

  return 0;
}

// c processes files from top to bottom, you need a contract to tell c this
// function :    Function Definitions
void greet() { printf("hello there"); }

// error handling
void file_example() {
  printf("\n--- File Error Handling Example ---\n");

  FILE *f = fopen("not_existing.txt", "r");

  if (!f) {
    perror("Failed to open file"); // prints reason using errno
    printf("errno value: %d\n", errno);
    return;
  }

  fclose(f);
}

void custom_error_example() {
  printf("\n--- Custom Error Code Example ---\n");

  i32 result;
  ErrorCode err = divide_safe(10, 0, &result);

  if (err != ERR_OK) {
    printf("Operation failed with error code: %d\n", err);
  }
}

// run with:
//  gcc -Wall -Wextra -g -fsanitize=address -o main main.c && ./main
// What each flag does:
// -Wall → enable common warnings
// -Wextra → more warnings
// -g → include debug symbols
// -fsanitize=address → enable AddressSanitizer
//
// for learning and debugging
// gcc -Wall -Wextra -Werror -O0 -g -fsanitize=address -o main main.c

// Specifiers
// %d → int
// %p → pointer
// %f → float
// %lf → double
// %lld → long long
//
//
// gcc main.c math_utils.c -o program && ./program
// gcc main.c math_utils.c -o -Wall -Wextra -pedantic program && ./program

// struct vs union
// A structure creates a single, cohesive unit where each member has its own
// dedicated and independent memory location. Memory Allocation: Memory is
// allocated for all members, one after another, in contiguous memory.
// Size: The total size of a structure is the sum of the sizes of all its
// members, plus any potential padding the compiler adds for memory alignment.
// Usage: All members of a structure can be accessed simultaneously, making them
// ideal for data records where all properties are needed at once (e.g., student
// details, an employee record, or a point in 2D space).
//
// Union
// A union allows multiple data types to share the same memory location, meaning
// only one member can store a valid value at any given time. Memory Allocation:
// All members share the same starting address in memory. Size: The total size
// of a union is equal to the size of its largest member. Usage: They are useful
// for memory-saving, especially in memory-constrained systems (like embedded
// systems), or when you have a variable that can hold one of several types but
// never more than one at once. Writing to one member will overwrite the value
// of any other previously stored member.
