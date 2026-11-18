#include <stdio.h>   // #include directive tells c preprocessor to include files
                     // from other library into your program
#include <stdbool.h> // not needed in C23
#include <stdint.h>
#include <string.h>
/*
   sandbox.c
*/
// /* */ this called a diagraph

typedef int64_t i64;
typedef bool b32;
typedef char *string;
typedef uint64_t u64;
typedef uint16_t u16;
typedef uint32_t u32;
typedef float f32;

// prototype/definition
int increment(int *a);
void greet(void);

struct car {
  char *name;
  i64 age;
};


void parser(struct car *c, float price);



int main(void) {
  printf("\n Variables: \n"); // man 3 printf

  u32 a = 90;
  b32 tall = true;
  f32 height = 9.1f;
  string name = "jude";
  char grade = 'A';

  // printf("i+=3 : %d\n", i+=3);

  u32 i = 9;       // i starts as 9
  u32 j = 5 + i++; // j = 5 + 9   (i++ yields 9, the OLD value)
  printf("i is: %u and j is: %u\n", i, j); //  i becomes 10 (side effect happens
                                           //  after the value is used)

  u32 k = 9;
  u32 l = 5 + ++k; // here k becomes 10 first, then l = 5 + 10
  printf("k is: %u and l is: %u\n", k, l);

  printf("height is %.2f\n", height);
  printf("a is %u, character is %c, is_tall is %d and name is %s\n", a, grade,
         tall, name);

  // u32 x = (1, 2, 3); // 2 and 3 will be unused
  // printf("x is the value of the rigth most element %u\n", x);

  // size in bytes
  unsigned long i_size = sizeof(i64); // sizeof data type cant be negative
  printf(
      "size of i64 in bytes is %zu\n",
      i_size); // except for char size, byte size varies from system to systems

  // or use the specialized size_t
  size_t u_size = sizeof(u16); // format specifier for size_t is %zu. to print
                               // negative size_t use %zd
  printf(
      "size of u16 in bytes is %zu\n",
      u_size); // except for char size, byte size varies from system to systems

  int aug = 3;
  int *aug_ptr = &aug;
  if (aug_ptr == NULL) {
    printf("error alloc\n");
    return 1;
  }
  // compiler can't auto-convert types for you
  // %p expects a void *
  printf("memory address of aug is %p\n", (void *)&aug);
  int res = increment(aug_ptr);
  printf("res is %d\n", res);

  // Prints size of an 'int'
  printf("%zu\n", sizeof(int));

  // p is type 'int *', so prints size of 'int*'
  printf("%zu\n", sizeof aug_ptr);

  // *p is type 'int', so prints size of 'int'
  printf("%zu\n", sizeof *aug_ptr);

  // strings are pointers
  char name_str[] = "james";
  char *name_ptr = "james"; // Actually "james\0" behind the scenes
  char namearr[10] = "lovelyday\0";
  printf("%s %s %s \n", name_ptr, name_str, namearr);

  // char aj = name_ptr[0]; // will not work
  for (int i = 0; i < 6; i++) {
    printf("index of i is %c\n", name_ptr[i]);
  }

  size_t string_len = strlen(name_ptr);
  printf("string length is %zu\n", string_len);

  struct car c = {.name = "james", .age = 90};
  printf("car name is %s\n", c.name);

  parser(&c, 1.90);

  return 0;
}

void parser(struct car *c, float price){}

void greet(void) { printf("hello there ->\n"); }

// declaration
int increment(int *a) { return *a * 2; } // deference first before multiplying

// c23 -> the most recent
// gcc sandbox.c -g -Wall -Wextra -Werror  -std=c2x -fsanitize=address -pedantic
// -o main && ./main
