

#include <errno.h>
#include <fenv.h>
#include <limits.h>
// #include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// cpu clock func
// int frequency_of_primes(int n) {
//   // This function checks the number of
//   // primes less than the given parameter
//   int i, j;
//   int freq = n - 1;
//   for (i = 2; i <= n; ++i)
//     for (j = sqrt(i); j > 1; --j)
//       if (i % j == 0) {
//         --freq;
//         break;
//       }
//   return freq;
// }

// you dont need the struct tm when you have #include <time.h>
// The time.h header file contains time realted operations like getting the
// current time, converting between different time formats. It also contains
// CLOCKS_PER_SEC macro which holds the number of times does the system clock

// ticks per second. struct tm {
//     // seconds,  range 0 to 59
//     int tm_sec;
//
//     // minutes, range 0 to 59
//     int tm_min;
//
//     // hours, range 0 to 23
//     int tm_hour;
//
//     // day of the month, range 1 to 31
//     int tm_mday;
//
//     // month, range 0 to 11
//     int tm_mon;
//
//     // The number of years since 1900
//     int tm_year;
//
//     // day of the week, range 0 to 6
//     int tm_wday;
//
//     // day in the year, range 0 to 365
//     int tm_yday;
//
//     // daylight saving time
//     int tm_isdst;
// }

// Function to display a welcome message
void displayMessage() { printf("Hello! Geek\n"); }

void func1();
void func2();

// // specifying funct1 to execute at start
// #pragma startup func1
//
// // specifying funct2 to execute before end
// #pragma exit func2 // GCC does not support #pragma startup or exit. However,
// you can use the below code for the expected output on GCC compilers.

void __attribute__((constructor)) func1();
void __attribute__((destructor)) func2();

void func1() { printf("Inside func1()\n"); }
void func2() { printf("Inside func2()\n"); }

// Defining a macro for PI
#define PI 3.14159

// macro with parameter
#define AREA(l, b) (l * b)

// Macro Definition
#define LIMIT 5

// #undef LIMIT // this will remove it and make the LIMIT macro undefined
// you get :
// main.c: In function ‘main’:
// main.c:1512:23: error: ‘LIMIT’ undeclared (first use in this function)
//  1512 |   for (int i = 0; i < LIMIT; //     Note There is no semi-colon (;)
//  at the end
//       |                       ^~~~~

jmp_buf recovery;

void handle_divide_by_zero(int sig) {

  // Re-assign the signal handler
  signal(SIGFPE, handle_divide_by_zero);
  printf("Error: Division by zero\n");

  // Jump to the recovery point
  longjmp(recovery, 1);
}

void func() {

  // Stored in the stack
  int local_var = 10;
}

enum Direction { EAST, NORTH, WEST, SOUTH };

union Data {
  int x;
  float y;
  char c;
};

typedef struct {
  int x;
} Point;

// Defining a structure to represent a student
struct Student {
  char name[50];
  int age;
  float grade;
};

// inline int add(int a, int b) { return a + b; }
int add(int a, int b) { return a + b; }

static inline int foo() { return 2; }

void printStr(char str[]) { printf("I just passed ======>>> %s\n", str); }

struct Date {
  unsigned int d : 5; // 0–31 (5 bits)
  unsigned int m : 4; // 0–15 (4 bits)
  unsigned int y;     // normal int
};

struct A {
  char a; // 1 byte
  int b;  // 4 bytes
};

// Packed version (no padding)
#pragma pack(1)
struct AA {
  char a; // 1 byte
  int b;  // 4 bytes
};
// Now size = 5 bytes (no extra space)

// __attribute__((packed)) tells the compiler:
// “Don’t add padding between struct members.”
struct __attribute__((packed)) AAAA {
  char a; // 1 byte
  int b;  // 4 bytes
};

// Structure Pointer
// A pointer to a structure allows us to access structure members using the ( ->
// ) arrow operator instead of the dot operator. Structure declaration
struct Point {
  int x, y;
};

// C standard (C89/C99): does NOT allow nested functions. Only GCC allows them
// as an extension. void outer() {
//     int x = 5;
//
//     void inner() {          // nested function: you get function definition
//     not allowed here
//         printf("x = %d\n", x);
//     }
//
//     inner();                // call inner function
// }

// header file: a file with extension .h
// stdio.h : core input functions
// stdlib.h : malloc,calloc, realloc, numeric converison
// string.h : string manipulation
// stdint.h : exact width integers type

// c - Embedded system, washing machine, printers, ovens
// compilers, interpreters, game engines
// operating systems, IoT, database engines
// desktop applications like notepad++

// install compiler : sudo apt install build-essential

// extern example (defined later)
// extern int g;
//
// void testStatic() {
//   static int x = 0; // static: retains value between calls
//   x++;
//   printf("static x = %d\n", x);
// }

// types of main
// int main(void) { // recommended
//     printf("hello world\n");
//     return 0;
// }

// type 2
// int main() {
//   printf("hello there\n");
//   return 0;
// }

// Global variables (stored in initialized data segment)
int globalVar = 10;
char message[] = "Hello";

// Global uninitialized variables (stored in BSS segment)
int globalVar2;
char message2[50];

int main(int argc, char *argv[]) {

  // standard bool
  _Bool good = 0;
  printf("is the boy good?: %d\n", good);
  _Bool akk = 0;
  _Bool bkk = 1;
  _Bool ckk = 2;
  _Bool dk = -5;

  printf("=============> %d %d %d %d\n", akk, bkk, ckk, dk);

  // use atoi to convert string representation of numbers to number
  char numba[] = "90";
  int stringtoNumber = atoi(numba);
  printf("string to number %d\n", stringtoNumber);

  // ldd main shows which shared libraries your program depends on at runtime.
  // ldd shows the shared libraries your program needs to run and where they are
  // loaded from.
  // ~/Downloads/cprogramm_youtube ❯ ldd main 57m 44s   system
  //         linux-vdso.so.1 (0x000075f69dc84000)
  //         libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x000075f69da00000)
  //         /lib64/ld-linux-x86-64.so.2 (0x000075f69dc86000)

  // char onebyte = 'A';
  // printf("sizeof byte is : %lu\n", sizeof(onebyte));
  // printf("Range: %d to %d\n", CHAR_MIN, CHAR_MAX);
  // INT_MIN, INT_MAX
  // SHRT_MIN, SHRT_MAX
  // LONG_MIN, LONG_MAX

  // floats and double
  // double val = 19.90;
  // float vai = 1.9;
  // printf("float is %f and double %lf\n", val, vai);

  // bool x = true;
  // int y = x;        // automatic type conversion
  // bool z = (bool)y; // manual conversion

  // printf("arg c : %d\n", argc);
  // for (int i = 0; i < argc; i++) {
  //   printf("%s \n", argv[i]);
  // }

  // literals: constant values that are assigned to variables, cannot be
  // modified
  // Strings end with \0, and characters use 1 byte.
  // c implicitly has a "\0" byte (null terminator) at the end , that how c
  // knows it is at the end
  //  constant == literals
  //  integer literal, float literals, char literals, string literals
  // int hex = 0x10; // hex literal (16 in decimal). Prefix of the integer
  // literal indicates the base

  // const float floatVal = 4.14;
  // floatVal = 90.1; // error

  // character literals : can be 'A', '\n', '\t'

  // Decimal: 56
  // Octal: 012 → 10 decimal
  // Hex: 0x10 → 16 decimal
  // Binary: 0b101 → 5 decimal

  // c data types: basic, derived, user-defined
  // basic: int,float, double, char bool, void
  // derived: function, array, pointer
  // user-defined: struct, enum, union
  // NOTE: size and range is dependent on the compiler and system
  // architecture

  // format specifiers:
  // %u - unsigned integers
  // %i and %d - signed integers
  // %f, %e %E - floating points, %e and %E for scientific floats
  //%ld, %li - for long
  // %lf - double
  //%lu - unsigned int or unsigned long
  //%o - unsigned octal
  // %x or %X - unsigned hexadecimal numbers
  // %s - strings e.g char name[] = "john";
  // %p - pointers
  //%% - prints % character
  //%n - prints nothing

  // Scanset: read input only if it matches this character pattern.
  // scanf family: represented by %[]
  // takes a range of characters that we can accept
  // char str[128];
  // printf("please enter a string: ");
  // scanf("%[a-y]", str); // this is saying we can only get alphabet between
  // a-y printf("you printed %s\n", str);
  // use scanf("%d", int); scanf("%c", char);

  // The scanf() function can also be used to read string input from users. But
  // it can only read single words.
  // char str[100]; // Declare an array to hold the input string
  // printf("Enter a string: ");
  // scanf("%s", str); // Reads input until the first space or newline. so if
  // you
  //                   // enter james lee, it will ignore lee
  // // so to fix this we use fgets
  // printf("You entered: %s\n", str);

  // fgets() reads the given number of characters of a line from the input and
  // stores it into the specified string. It can read multiple words at a time.
  // char leader[90];
  // printf("say leader name: ");
  // fgets(leader, sizeof(leader), stdin);
  // printf("Hello, %s", leader);

  // input and output formatting
  // width (20): minimum field width
  // - : left align (default is right align)
  // .5 : print at most 5 characters

  // printf("%20s\n", str);    // right-aligned, padded to width 20
  // printf("%-20s\n", str);   // left-aligned, padded to width 20
  // printf("%20.5s\n", str);  // right-aligned, max 5 chars shown
  // printf("%-20.5s\n", str); // left-aligned, max 5 chars shown

  // %[0-9] → read only digits
  // %[a-zA-Z] → read letters only

  // printf("what is your name: ");
  // char name[50];
  // scanf("%s", name);
  // printf("my name is %s\n", name);

  // storage classess: defines the lifetime, scope, and visibility of variables.
  // how variables are stored and accessed
  //  types:
  //  auto
  //  register
  //  static
  //  extern
  // auto int a = 10;     // auto: default local variable (lives inside block)
  // register int b = 20; // register: suggest CPU register (faster, optional)
  //
  // printf("auto a = %d\n", a);
  // printf("register b = %d\n", b);
  //
  // testStatic(); // 1
  // testStatic(); // 2 (retains value)
  //
  // printf("extern g = %d\n", g); // extern: variable defined elsewhere

  //  auto → normal local variable
  //  register → try store in CPU register
  //  static → keeps value between calls
  //  extern → defined in another file/scope

  // fputs: used to output strings to files and also the screen/console(stdout)
  // fputs("this is my string\n", stdout);

  // arrays are blocks of memory holding 3 integers. Stored contiguously in
  // memory
  // int arr[3] = {10, 20, 30};
  // When you add to a pointer, it moves by the size of the data type—not by 1
  // byte.
  // int *p = arr;
  // p + 1; // moves to next int (not next byte)
  // What actually happens
  // If int = 4 bytes:
  // p → address 1000
  // p + 1 → address 1004
  // p + 2 → address 1008

  // It jumps by sizeof(int)
  // Accessing values
  // *(p + 0) // 10
  // *(p + 1) // 20
  // *(p + 2) // 30

  // *arr        == arr[0]
  // *(arr + 1)  == arr[1]
  // arr points to the first element
  // +1 moves to the next element
  // * dereferences (gets the value)

  // increment
  int a = 8;
  a++;
  printf("a is %d\n", a);
  a--;
  printf("a is %d\n", a);

  // computers store numbers in binary (base 2) instead of decimal (base 10)
  // 5 = 101 (binary)

  // 2 | 5   r1
  // 2 | 2   r0
  // 2 | 1   r1
  //     0
  // Divide by 2 → write remainder → repeat → read bottom to top
  // Bottom → top: 101

  // One quick check
  // 101 = 1*4 + 0*2 + 1*1 = 5

  // Because computers store numbers in fixed sizes (usually 8 bits = 1 byte)
  // So we pad with zeros:
  // 101 → 00000101

  //   00000101
  // & 00000011
  // -----------
  //   00000001  = 1
  // Only 1 if BOTH bits are 1
  printf("a & b: %d\n", 5 & 3);

  //   00000101
  // | 00000011
  // -----------
  //   00000111  = 7

  // Position:   2   1   0
  // Bits:       1   1   1
  // Value:      4   2   1
  // Now add them:
  // 4 + 2 + 1 = 7
  // 00000111 = (1×4) + (1×2) + (1×1) = 7

  // so e.g so 00001111 =(1x8) + (1×4) + (1×2) + (1×1) = 15

  // 1 if ANY bit is 1
  printf("5 | 3: %d\n", 5 | 3);

  //   00000101
  // ^ 00000011
  // -----------
  //   00000110  = 6
  // 1 if bits are DIFFERENT
  printf("5 ^ 3: %d\n", 5 ^ 3);

  printf("%d\n", ~5);
  // 5  = 00000101
  // ~5 = 11111010  (in 8-bit)
  // Flips all bits (be careful: gives negative numbers due to 2’s complement)

  printf("5 << 1: %d\n", 5 << 1);
  // Left Shift <<
  // 00000101 << 1 → 00001010 = 10
  //     Multiply by 2

  // Right Shift >>
  printf("5 >> 1: %d\n", 5 >> 1);
  //   Divide by 2
  // 00000101 >> 1 → 00000010 = 2

  Point p;    // actual object
  Point *ptr; // pointer to object

  p.x = 10; // dot operator on actual object
  ptr = &p;
  ptr->x = 20; // arrow operator on pointer to object

  printf("p.x = %d\n", p.x); // 20

  // goto and label
  //  Use sparingly — can make code messy.
  int i = 0;

start: // label
  printf("%d\n", i);
  i++;
  if (i < 3)
    goto start; // jump back to label

  // Inline vs normal
  // Inline → code inserted directly
  // Normal → function call (stack, jump, return
  // Faster (no function call overhead) --> inline function
  // Only for small functions
  // Compiler may ignore inline
  //  Can increase code size
  // int x = add(2, 3); // becomes: int x = 2 + 3;
  // printf("inline result %d\n", x);

  // use: gcc main.c -o main -O1
  // other levels:
  //   -O0  // no optimization (default → can break inline)
  // -O1  // basic optimization ✅
  // -O2  // more optimization (commonly used)
  // -O3  // aggressive optimization
  // without -01 or the others you get:
  //   ~/Downloads/cprogramm_youtube ❯ gcc main.c -o main   system
  // /usr/bin/ld: /tmp/ccDJajs4.o: in function `main':
  // main.c:(.text+0x162): undefined reference to `add'
  // collect2: error: ld returned 1 exit status

  // alternatively with no optimization flag
  // We can use the static keyword before the inline function. This forces the
  // compiler to treat the function with internal linkage and ensures that it is
  // considered during the linking process, allowing the program to compile and
  // run successfully.

  int y = foo();
  printf("inline static %d\n", y);
  // use: gcc main.c -o main #-01 not needed

  // loops: for, while loops and do while loops
  int wl = 0;
  while (wl <= 2) {
    printf("in a while loop\n");
    wl++;
  }

  // arrays: linear data structure that stores a fixed size
  // array initialization
  int arry[5] = {1, 2, 3}; // size of array arry[3] ===> size of array is 3, the
                           // remaining element will be 0
  int n = sizeof(arry) / sizeof(arry[0]);
  printf("array %d\n", *arry); // 1

  // array traversal
  printf("number of elements in array is %d\n", n); // 3
  for (int i = 0; i < n; i++) {
    printf("i am index %d\n", arry[i]);
  }

  // size of pointers is dependent on architecture (bit system) of the machine
  int *ptr1;
  char *ptr2;
  // Finding size using sizeof()
  printf("size of ptr1: %zu\n", sizeof(ptr1));
  printf("size of ptr2: %zu\n", sizeof(ptr2));
  // The reason for the same size is that the pointers store the memory
  // addresses, no matter what type they are

  // types of pointers
  // NULL pointers:  do not point to any memory location.
  int *nptr = NULL;
  printf("%p\n", nptr); // will give nil

  // void pointers:  means that they do not have any associated data type .are
  // the pointers of type void.
  // Void pointer
  void *vptr;
  printf(" void pointers: %p\n", vptr);

  // Dangling Pointer
  // A pointer pointing to a memory location that has been deleted (or freed) is
  // called a dangling pointer.

  int *dptr = (int *)malloc(sizeof(int));
  // After below free call, ptr becomes a dangling pointer
  free(dptr);
  printf("Memory freed\n");

  // removing Dangling Pointer
  dptr = NULL; // without this you get an error

  // wild pointers
  // The wild pointers are pointers that have not been initialized with
  // something yet. These types of C-pointers can cause problems in our programs
  // and can eventually cause them to crash. If values are updated using wild
  // pointers, they could cause data abort or data corruption.
  int *wptr;
  printf("wild pointers: %p\n", wptr);

  int ab = 91;
  int bc = 50;

  // Creating a constant pointer
  int *const cptr = &ab;
  // Trying to reassign it to b
  // cptr = &bc; // you get an error, cannot be modified

  // Pointer to Function
  // A function pointer is a type of pointer that stores the address of a
  // function, allowing functions to be passed as arguments and invoked
  // dynamically.

  // Declare a function pointer that matches
  // the signature of add() function
  int (*fptr)(int, int);
  // Assign address of add()
  fptr = &add;

  // Call the function via ptr
  printf("%d\n", fptr(10, 5));

  // pointers and double pointers
  int var = 10;       // normal int
  int *ptr3 = &var;   // pointer to var
  int **ptr4 = &ptr3; // pointer to pointer

  printf("var: %d\n", var);       // 10
  printf("*ptr3: %d\n", *ptr3);   // 10 (value via ptr3)
  printf("**ptr4: %d\n", **ptr4); // 10 (value via ptr4 → ptr3 → var)

  // A string in C is an array of characters terminated by a null character
  // '\0'.
  //  The null character '\0' marks the end of the string.
  //  C does not have a built-in string data type.
  //  printf("The string is: %s\n", str);

  // pass strings to function
  char passedstr[] = "GeeksforGeeks";
  // Passing string to a
  // function
  printStr(passedstr);

  // declaring and initializing a string
  char str[] = "Geeks";

  // printing the string
  printf("The string is: %s\n", str);
  // Internally, this creates an array like: { 'G', 'e', 'e', 'k', 's', '\0'}
  printf("string length %lu\n", strlen(str)); // 5 excluding the null character.

  // pointer (read-only string)
  // A string literal is a sequence of characters enclosed in double quotes,
  // like "Hello" or "1234". Internally, it is stored as a constant character
  // array terminated by a null character '\0'.
  // Using const is important because string literals should not be modified.
  // String literals are automatically null-terminated.
  // They are typically stored in read-only memory, so modifying them causes
  // undefined behavior.
  const char *strc = "Hello";
  // strc = "World"; //  OK
  // str[0] = 'h';  ERROR

  // array (modifiable copy)
  char name[] = "Hello";
  name[0] = 'h'; //  OK
                 // name = "World";  ERROR

  // String Pointer
  char strptr[20] = "Geeks";

  // Pointer variable which stores
  // the starting address of
  // the character array str

  char *stringptr = strptr;
  // While loop will run till
  // the character value is not
  // equal to null character
  while (*stringptr != '\0') {
    printf("%c", *stringptr);
    stringptr++; //  correct variable
  }

  // READING INPUT STRINGS METHOD:
  printf("Enter something: ");
  char stri[100];
  // string input Read string  from the user
  // there is a limitation with the scanf() function. scanf() will stop reading
  // input as soon as it encounters a whitespace (space, tab, or newline).
  scanf("%s", stri);

  // Print the string
  printf("%s\n", stri);

  // scanf() with a Scanset: We can also use scanf() to read strings with spaces
  // by utilizing a scanset.
  printf("enter something: ");
  char strset[20];

  // Using scanset in scanf
  // to read until newline
  scanf(" %19[^\n]", strset); // space before the % is important here
  // First scanf leaves \n, second scanf stops immediately → fix by using
  // getchar() or " %..." i.e in between the 2 scanf place: getchar(); //
  // consume leftover '\n'

  // Printing the read string
  printf("%s", strset);

  getchar();

  // Using fgets()
  // If someone wants to read a complete string, including spaces, they should
  // use the fgets() function. Unlike scanf(), fgets() reads the entire line,
  // including spaces, until it encounters a newline.

  printf("enter something lastly: ");
  char strfg[20];

  // Reading the string
  // (with spaces) using fgets
  fgets(strfg, 20, stdin);

  // Displaying the string using puts
  printf("%s", strfg);

  // STRUCTS
  // Structure members cannot be initialized inside the structure definition.
  // However, they can be initialized at the time of declaring a structure
  // variable using initializer lists.

  // Declaring and initializing a structure variable
  // By default, structure members are not automatically initialized to 0 or
  // NULL. Uninitialized structure members will contain garbage values. However,
  // when a structure variable is declared with an initializer, all members not
  // explicitly initialized are zero-initialized.
  struct Student s1 = {"Rahul", 20, 18.5};

  // Designated Initializing another structure
  // Designated Initialization allows structure members to be initialized in any
  // order.
  struct Student s2 = {.age = 18, .name = "Vikas", .grade = 22};

  // Accessing structure members
  printf("%s\t%d\t%.2f\n", s1.name, s1.age, s1.grade);
  printf("%s\t%d\t%.2f\n", s2.name, s2.age, s2.grade);

  // Struct size ≠ sum of members because of padding (extra bytes for
  // alignment).
  //  Packing removes padding to save space.
  printf("with padding: %zu\n", sizeof(struct A));
  // Expected: 1 + 4 = 5
  // Actual: 8 bytes (padding added for alignment)
  // NOTE: Padding = faster access, more space | Packing = less space, possibly
  // slower.

  printf("no padding: %zu\n", sizeof(struct AA));

  printf("No padding : %zu\n", sizeof(struct AAAA)); // → 5

  // A pointer to a structure allows us to access structure members using the (
  // -> ) arrow operator instead of the dot operator.
  struct Point pp = {1, 2};

  // ptr is a pointer to structure p
  struct Point *sptr = &pp;

  // Accessing structure members using structure pointer
  printf("%d %d\n", sptr->x, sptr->y);

  // Bit fields let you store variables using specific number of bits → saves
  // memory.
  struct Date dt = {31, 12, 2024};
  printf("bit fields: ----->  %lu\n",
         sizeof(struct Date)); // smaller than normal struct
  // Bit fields = “store small values in exact number of bits instead of full
  // bytes.” Cannot take address (&) of bit-field
  // main.c:14:1: error: cannot take address of bit-field 'x'
  //   printf("Address of t.x is %p", &t.x);

  //  Union = multiple variables share the same memory.
  //  Changing one member overwrites the others.
  //  Size = size of the largest member.
  union Data d;

  d.x = 10; // stores int
  printf("%d\n", d.x);
  d.y = 5.5; // overwrites x
  // Only one value is valid at a time
  printf("%f\n", d.y);
  printf("%lu\n", sizeof(union Data));

  // Enum = named integers (makes code readable instead of using raw numbers).

  enum Direction dd = NORTH;  // = 1
                              //  Default values: 0, 1, 2, ...
                              //  You can assign manually:
  dd = 1;                     // valid
  enum X { A = 3, B = 2, C }; // C = 3
  // Enums continue from the previous value, not the highest.
  // A = 3
  // B = 2
  // C = B + 1 = 3

  // Memory Layout: The memory layout of a program shows how its data is stored
  // in memory during execution Program memory is split into 4 main parts: Text
  // (Code) → program instructions (read-only) Data → global/static vars
  // Initialized → normal values
  // BSS → uninitialized (auto = 0)
  // Heap → dynamic memory (malloc)
  // Stack → local variables & function calls

  // Initialized Data Segment
  // Variables in this segment retain their values throughout program execution.
  // Static variable (also stored in initialized data segment)
  static int staticVar = 20;

  printf("Global variable: %d\n", globalVar);
  printf("Static variable: %d\n", staticVar);
  printf("Message: %s\n", message);

  // Uninitialized Data Segment (BSS)
  // The uninitialized data segment is often called the BSS segment
  // It stores global and static variables that are not initialized by the
  // programme
  // Static uninitialized variable (also stored in BSS)
  static int staticVar2;

  // Assigning values at runtime
  globalVar2 = 10;
  staticVar2 = 20;
  snprintf(message2, sizeof(message2), "Hello BSS");

  printf("Global variable 2: %d\n", globalVar2);
  printf("Static variable 2: %d\n", staticVar2);
  printf("Message 2: %s\n", message2);

  // Heap Segment
  // The heap segment is used for dynamic memory allocation
  // Memory in the heap is managed using functions like malloc(), realloc(), and
  // free().
  // Create an integer pointer
  int *ptrh = (int *)malloc(sizeof(int) * 10);
  printf("heap stored pointer %p\n", ptrh);

  // Stack Segment
  // The stack stores local variables, function parameters, and return addresses
  // for each function call.
  // Each function call creates a stack frame in this segment
  func();

  // size is not part of your C code
  // It’s a separate tool that inspects the compiled program
  // You must:
  // Compile → gcc file.c -o output
  // Analyze → size output
  // i.e gcc main.c -o main && size main
  // you get:
  // ~/Downloads/cprogramm_youtube ❯ size main   system
  //    text    data     bss     dec     hex filename
  //    5933     696     120    6749    1a5d main
  // text → size of the code segment (machine instructions)
  // data → initialized global/static variables
  // bss → uninitialized global/static variables
  // dec → total size (text + data + bss) in decimal
  // hex → same total in hexadecimal

  // Dynamic memory allocation
  // Array size can be increased or decreased as needed.
  // Memory persists even after the function that allocated it finishes,
  // allowing functions to return pointers to it. This is different from stack
  // allocated variables as it is not safe to return address of those variable.

  // malloc()
  // The malloc() (stands for memory allocation) function is used to allocate a
  // single block of contiguous memory on the heap at runtime. The memory
  // allocated by malloc() is uninitialized, meaning it contains garbage values.

  // Assume that we want to create an array to store 5 integers. Since the size
  // of int is 4 bytes, we need 5 * 4 bytes = 20 bytes of memory. This can be
  // done as shown:
  // int *mptr = (int *)malloc(20); // dont do
  // because  the size of the integer in C depends on the architecture
  // int *mptr; both are doing the same thing
  // int* mptr;
  int *mptr = (int *)malloc(sizeof(int) * 5);
  // if there is no memory available, the malloc will fail and return NULL. So,
  // it is recommended to check for failure by comparing the ptr to NULL.

  // Checking if failed or pass
  if (mptr == NULL) {
    printf("Allocation Failed");
    exit(0);
  }

  // Populate the array
  for (int i = 0; i < 5; i++)
    mptr[i] = i + 1;

  // Print the array
  for (int i = 0; i < 5; i++)
    printf("%d ", mptr[i]);

  // Free the memory after completing
  // operations
  free(mptr);

  // calloc()
  // The calloc() (stands for contiguous allocation) function is similar to
  // malloc(), but it initializes the allocated memory to zero. It is used when
  // you need memory with default zero values.
  printf("\n");
  int *captr = (int *)calloc(5, sizeof(int));

  // Checking if failed or pass
  if (captr == NULL) {
    printf("Allocation Failed");
    exit(0);
  }

  // No need to populate as already
  // initialized to 0

  // Print the array
  for (int i = 0; i < 5; i++)
    printf("%d ", captr[i]);

  // After calling free(), it is a good practice to set the pointer to NULL to
  // avoid using a "dangling pointer," which points to a memory location that
  // has been deallocated.
  // after free: the memory is deallocated, but captr still holds the old
  // address
  // That makes it a dangling pointer (dangerous)
  free(captr);
  captr = NULL;

  // realloc()
  // realloc() function is used to resize a previously allocated memory block.
  // It allows you to change the size of an existing memory allocation without
  // needing to free the old memory and allocate a new block.
  //
  // Suppose we initially allocate memory for 5 integers but later need to
  // expand the array to hold 10 integers. We can use realloc() to resize the
  // memory block:
  int *reptr = (int *)malloc(5 * sizeof(int));

  // Resize the memory block to hold 10 integers
  reptr = (int *)realloc(reptr, 10 * sizeof(int));

  // Check for allocation failure
  if (reptr == NULL) {
    printf("Memory Reallocation Failed");
    exit(0);
  }
  free(reptr);
  reptr = NULL;

  // It is important to note that if realloc() fails and returns NULL, the
  // original memory block is not freed, so you should not overwrite the
  // original pointer until you've successfully allocated a new block. To
  // prevent memory leaks, it’s a good practice to handle the NULL return value
  // carefully:
  int *reaptr = (int *)malloc(5 * sizeof(int));

  // Reallocation
  int *temp = (int *)realloc(reaptr, 10 * sizeof(int));

  // Only update the pointer if reallocation is successful
  if (temp == NULL)
    printf("Memory Reallocation Failed\n");
  else
    reaptr = temp;

  // Memory Leaks
  // Data can be stored in either stack or heap memory. The stack stores local
  // variables and parameters of the function while the heap is used for dynamic
  // memory allocation during runtime.
  //
  // A memory leak occurs when a program dynamically allocates memory but does
  // not release it after it's no longer needed.
  // In C, memory is allocated using malloc() / calloc() and released using
  // free().
  // allocate memory
  int *meleaptr = (int *)malloc(sizeof(int));

  *meleaptr = 10;
  printf("%d\n", *meleaptr);

  // if you forgot to free memory free(ptr), you get memory leak
  free(meleaptr);
  meleaptr = NULL;

  // File handling:
  // in C is the process in which we create, open, read, write, and close
  // operations on a file. C language provides different functions such as
  // fopen(), fwrite(), fread(), fseek(), fprintf(), etc. to perform input,
  // output, and many different C file operations in our program./ FILE HANDLING

  // Opening a file
  // File pointer to store the
  // value returned by fopen
  FILE *ffptr;

  // Opening the file in read mode
  // FILE *fopen(const char *restrict pathname, const char *restrict mode);

  ffptr = fopen("readmej.md", "r");

  // checking if the file is
  // opened successfully
  if (ffptr == NULL) {
    printf("The file is not opened.\n");
  }

  // The file is not opened because it does not exist in the source directory.
  // But the fopen() function is also capable of creating a file if it does not
  // exist.

  // FILE CREATION
  // The fopen() function can not only open a file but also can create a file if
  // it does not exist already. For that, we have to use the modes that allow
  // the creation of a file if not found such as w, w+, wb, wb+, a, a+, ab, and
  // ab+.
  // File pointer
  FILE *fcptr;

  // Creating file using fopen()
  // with access mode "w"
  fcptr = fopen("file.txt", "w");

  // checking if the file is created
  if (fcptr == NULL)
    printf("The file is not opened.");
  else
    printf("The file is created Successfully.");

  // WRITE TO FILE
  // The file write operations can be performed by the functions fprintf() and
  // fputs(). C programming also provides some other functions that can be used
  // to write data to a file such as: Function	Description
  // fprintf()	Similar to printf(), this function uses formatted string and
  // variable arguments list to print output to the file.
  // fputs()	Prints the whole line in the file and a newline at the end.
  // fputc() Prints a single character into the file.
  // fputw()	Prints a number to the file.
  // fwrite() This function writes the specified number of bytes to the binary
  // file.
  // File pointer
  FILE *wfptr;

  // Get the data to be written in file
  char data[50] = "GeeksforGeeks-A Computer "
                  "Science Portal for Geeks";

  // Creating file using fopen()
  // with access mode "w"
  wfptr = fopen("file.txt", "w");

  // Checking if the file is created
  if (wfptr == NULL)
    printf("The file is not opened.");
  else {
    printf("The file is now opened.\n");
    fputs(data, wfptr);
    fputs("\n", wfptr);

    // Closing the file using fclose()
    fclose(wfptr);
    printf("Data successfully written in file "
           "file.txt\n");
    printf("The file is now closed.");
  }

  // Reading From a File
  //
  // The file read operation in C can be performed using functions fscanf() or
  // fgets(). Both the functions performed the same operations as that of
  // scanf() and gets but with an additional parameter, the file pointer. There
  // are also other functions we can use to read from a file. Such functions are
  // listed below:

  // Function	Description
  // fscanf()	Use formatted string and variable arguments list to take input
  // from a file. fgets()	Input the whole line from the file. fgetc()
  // Reads a single character from the file. fgetw()	Reads a number from a
  // file. fread()	Reads the specified bytes of data from a binary file.
  FILE *rrfptr;

  // Declare the character array for the data to be read from file
  char datar[50];
  rrfptr = fopen("file.txt", "r");

  if (rrfptr == NULL) {
    printf("file.txt file failed to open.");
  } else {

    printf("The file is now opened.\n");

    // Read the data from the file
    // using fgets() method
    while (fgets(datar, 50, rrfptr) != NULL) {

      // Print the data
      printf("%s", datar);
    }

    // Closing the file using fclose()
    // The fclose() function is used to close the file. After successful file
    // operations, you must always close a file to remove it from the memor
    fclose(rrfptr);
  }
  // The getc() and some other file reading functions return EOF (End Of File)
  // when they reach the end of the file while reading. EOF indicates the end of
  // the file, and its value is implementation-defined.

  // Move File Pointer
  //
  // File pointer generally points to the position according to the mode or last
  // read/write operation. We can manually move this pointer to any position in
  // the file using fseek() function.
  //
  // Syntax:
  // fseek(fptr, offset, pos);
  //
  // where, pos is the position from where offset is counted and offset is the
  // number of positions to shift from pos (it can be negative or positive).
  //
  // Example:
  // While writing to a file opened in rw+ mode, the file pointer moves to the
  // end of the file. In case where we want to replace a word, then first we
  // have to move the file pointer to the position where that word starts.

  // File pointer
  FILE *seekfptr;

  // Get the data to be written in file
  char dataseek[50] = "GeeksforGeeks-A Computer "
                      "Science Portal for Geeks";

  // Creating file using fopen()
  // with access mode "w"
  seekfptr = fopen("file.txt", "w");

  // Checking if the file is created
  if (seekfptr == NULL)
    printf("The file is not opened.");
  else {
    printf("The file is now opened.\n");
    fputs(dataseek, seekfptr);
    fputs("\n", seekfptr);

    // What it means
    //
    // fseek(file, offset, origin)
    //
    // seekfptr → the file
    // -6 → move 6 bytes backward
    // SEEK_END → start from the end of the file
    //
    //  So this line means:
    //
    // “Move the file pointer to 6 characters before the end of the file”
    fseek(seekfptr, -6, SEEK_END);

    fputs("GeeksforGeeks", seekfptr);

    // Closing the file using fclose()
    fclose(seekfptr);
    printf("Data successfully written in file "
           "file.txt\n");
    printf("The file is now closed.");
  }

  // READ AND WRITE IN BINARY
  // WRITE
  FILE *bfp = fopen("file.bin", "wb"); // write binary
  int arr[3] = {1, 2, 3};
  fwrite(arr, sizeof(int), 3, bfp); // write 3 ints
  fclose(bfp);

  // READ
  FILE *rdfp = fopen("file.bin", "rb"); // read binary
  int arr3[3];
  fread(arr3, sizeof(int), 3, rdfp); // read 3 ints
  fclose(rdfp);
  //  print the values
  for (int i = 0; i < 3; i++) {
    printf("%d ", arr3[i]);
  }

  // ERROR HANDLING IN C
  // C does not provide built-in exception handling like other high-level
  // languages (e.g., try-catch in Java or Python), error handling relies
  // heavily on function return values, global variables, and system calls.
  //
  // lot of C function calls return -1 or NULL or set an in case of an error
  // code as the global variable errno, so quick tests on these values are
  // easily done with an instance of ‘if statement’.

  // What is errno?
  //
  // errno is a global variable defined in the <errno.h> header file that
  // indicates the error that occurred during a function call in C. When a
  // function fails, the errno variable is automatically set to a specific error
  // code, which helps identify the type of error encountered
  //
  // If a file is opened which does not exist,
  // then it will be an error and corresponding
  // errno value will be set
  FILE *fp;

  // opening a file which does not exist
  fp = fopen("gfg.txt", "r");

  // errno value	Error
  // 1 Operation not permitted
  // 2 No such file or directory
  // 3 No such process
  // 4 Interrupted system call
  // 5 I/O error
  // 6 No such device or address
  // 7 The argument list is too long
  // 8 Exec format error
  // 9 Bad file number
  // 10 No child processes
  // 11 Try again
  // 12 Out of memory
  // 13 Permission denied

  printf("Value of errno: %d\n", errno); // you get: Value of errno: 2

  // Error handling methods
  //
  // Using if-else
  // In C, error handling is done manually since there is no built-in try-catch
  // block like in other programming languages. To manage errors, we can use
  // if-else statements to check for conditions and handle any potential errors
  // that may occur during program execution. Example:
  FILE *ffp;

  // opening a file which does not exist
  ffp = fopen("gfg.txt", "r");

  if (ffp == NULL) {
    printf("File opening error");
  } else {
    printf("File open successfully");
  }

  // perror()
  //
  // The perror() function is used to print an error message to the standard
  // error stream (stderr). It helps to display the error string based on the
  // global errno variable, which stores the error code set by system calls and
  // library functions. Example:
  FILE *ppfp;

  // Try opening a non-existent file, which sets errno
  ppfp = fopen("gfg.txt", "r");

  // Print the errno value after failed file opening
  printf("Value of errno: %d\n", errno);
  perror("Message from perror");

  // strerror()
  // The strerror() function is also used to show the error description. This
  // function returns a pointer to the textual representation of the current
  // errno value. Example:

  FILE *sfp;

  // Try opening a non-existent file, setting errno
  sfp = fopen("gfg.txt", "r");

  // Print errno value and corresponding error message
  printf("Value of errno: %d\n", errno);
  printf("The error message is : %s", strerror(errno));

  // ferror()
  //
  // The ferror() function is used to check if an error occurred during a file
  // operation. It returns a non-zero value if there was an error during the
  // file operation. Example:
  FILE *fgfptr = fopen("gfg.txt", "w");

  // Write data to the file
  fprintf(fgfptr, "Hello, GFG!");

  // Check error after writing data into file
  if (ferror(fgfptr) == 0)
    printf("Data written successfully.");
  fclose(fgfptr);

  //  feof()
  //
  // The feof() function checks whether the end of a file has been reached
  // during reading operations. It helps to identify when there is no more data
  // to read from the file. Example:
  FILE *ofp = fopen("gfg.txt", "r");
  if (ofp == NULL)
    return 0;

  do {
    // Taking input single character at a time
    char c = fgetc(ofp);

    // Checking for end of file
    if (feof(ofp))
      break;

    printf("%c", c);
  } while (1);

  fclose(ofp);

  // The clearerr() function is used to clear the error and EOF flags for a
  // stream. It allows recovery from errors and allows the stream to be reused
  // for further operations. Example:
  FILE *jfptr = fopen("gfg.txt", "w+");
  fprintf(jfptr, "GeeksForGeeks!");
  while (fgetc(jfptr) != EOF)
    ;

  if (feof(jfptr)) {
    printf("EOF encounter \n");
  }

  // Reset EOF using clearerr
  clearerr(jfptr);
  if (!feof(jfptr)) {
    printf("Reset the EOF successfully");
  }

  fclose(jfptr);

  // Exit Status
  //
  // C programs use the exit() function to terminate the program and return a
  // status code to the operating system. The C standard specifies two
  // constants: EXIT_SUCCESS and EXIT_FAILURE, that may be passed to exit() to
  // indicate successful or unsuccessful termination, respectively. These are
  // macros defined in <stdlib.h> header file
  FILE *ufp;

  // Attempt to open a non-existent file in binary mode
  ufp = fopen("gfg.txt", "rb");

  if (ufp == NULL) {
    printf("Value of errno: %d\n", errno);
    printf("Error opening the file: %s\n", strerror(errno));
    perror("Error printed by perror");

    // Exit the program with failure status
    exit(EXIT_FAILURE);

    // This line will not be printed because of exit()
    printf("I will not be printed\n");
  }

  // If the file is opened successfully
  else {
    fclose(ufp);
    exit(EXIT_SUCCESS);
    printf("I will not be printed\n");
  }

  // Error Handling without Predefined Methods
  //
  // In the above discussion, we covered error handling using built-in methods,
  // but we can also handle some errors without relying on these methods, such
  // as division by zero, input validation, file opening errors, out-of-range
  // array access, and more.
  //
  // Handling divide by zero errors is essential to avoid program crashes or
  // undefined behavior. You can check for a zero divisor before performing
  // division to prevent this error.
  int num1 = 10, num2 = 0;

  if (num2 == 0)
    printf("Error: Division by zero is not allowed\n");
  else
    printf("Result: %d\n", num1 / num2);

  // GOTO simulating try catch
  int numerator = 10;
  int denominator = 0;
  int result;

  // Check for division by
  // zero using goto
  if (denominator == 0) {

    // Jump to the exception handling
    // section if denominator is 0
    goto excep;
  }
  result = numerator / denominator;
  printf("%d", result);

// Label
excep:
  printf("Exception: Division by "
         "zero is not allowed!");

  // Handling Exception in File Processing
  //
  FILE *file = NULL;
  int resultv = 0;

  file = fopen("example.txt", "r");
  if (file == NULL) {
    printf("Error opening file");

    // Jump to the error label
    // if file cannot be opened
    goto error;
  }

  // Read data
  resultv = fread(NULL, 1, 100, file);
  if (resultv == 0) {
    printf("Error reading file");

    // Jump to error if reading fails
    goto error;
  }

  // Process data
  printf("Successfull");

error:

  // Error handling section
  if (file != NULL) {
    fclose(file);
  }

  // FILE ERRORS
  // Here are some common errors that can occur during file operations:
  // Error	Cause
  // File Not Found	Trying to open a file that doesn’t exist.
  // Permission Denied	Insufficient permissions to access the file.
  // Disk Full	No space left on the disk for writing data.
  // File Already Exists	Attempting to create a file that already exists
  // in w mode. Invalid File Pointer	Using a null or invalid file pointer for
  // file operations. End-of-File (EOF)	Attempting to read past the end of the
  // file. File Not Open	Attempting to perform operations on a file that
  // wasn’t opened successfully.

  // 1. File Not Found Error
  // Try to open file in
  // read mode
  FILE *file404 =
      fopen("file.txt", "r"); // fopen() returns a NULL pointer because the file
                              // is not present in the current directory, then
                              // the perror() function prints the error message.

  // Check if the file
  // is opened/found
  if (file404 == NULL) {
    perror("Error");
    return 1;
  }
  fclose(file404); // you get:     Error: No such file or directory

  //   Handle Permission Denied Error
  // If the file exists but the program lacks the required permissions, fopen()
  // will fail and return NULL pointer. We can change the perror() output to
  // "permission denied" as shown in the below snippet.
  FILE *filep = fopen("/restricted/file.txt", "w");
  if (filep == NULL) {
    perror("Permission denied");
  }

  // Handle Disk Full Error
  // When writing to a file, ensure the disk has enough space. Errors during
  // file operations can be detected using ferror(). In the below program, we
  // assume that there is no space in memory to store any data.
  FILE *dffptr = fopen("file.txt", "w");
  if (dffptr == NULL) {
    perror("Error opening file");
    return 1;
  }

  fprintf(dffptr, "Writing to file");

  // Check error after performing
  // write operation
  if (ferror(dffptr)) {
    perror("Error writing to file");
  }
  fclose(dffptr);

  // Handle File Already Exists
  //
  // When creating a new file with fopen() in w mode, the existing file will be
  // overwritten. To avoid this, we open a new file in wx mode because if file
  // is already present then fopen() return NULL and set the EEXIST value to the
  // errno. In the below program, we assume that "test.text" file is already
  // present in current directory.
  FILE *fptr409;

  // Try to open the file in
  // write mode
  fptr409 = fopen("test.text", "wx");

  if (fptr409 == NULL) {

    // Check if the error is
    // due to file already existing
    if (errno == EEXIST)
      printf("File already exist");
  }

  // If we reach here, the file
  // was created successfully
  fprintf(fptr409, "This is a new file.");
  fclose(fptr409);

  // Handle End-of-File (EOF)
  //
  // When we are reading data from a file and the file pointer reaches the end
  // of the file, we can use the feof() function to handle the end of the file.
  FILE *fileeof = fopen("test.txt", "r");

  // Check for eof while reading
  char ch;
  while ((ch = fgetc(fileeof)) != EOF)
    putchar(ch);

  // Use feof() to make sure
  // EOF occurred or not
  if (feof(fileeof))
    printf("End of file reached.");
  else if (ferror(fileeof))
    printf("Error reading the file.");
  fclose(fileeof);

  // There are 2 methods to handle divide-by-zero exception mentioned below:
  //
  // Manually Checking before Division
  //  Signal handling

  // MANUAL
  float az = 10, bz = 0;
  float res;

  // Check division by zero
  if (bz == 0) {
    printf("Error: Division by zero");
  } else {
    res = az / bz;
    printf("%f", res);
  }

  // Using Signal Handling
  // signal handling can be used to catch runtime exceptions like divide-by-zero
  // errors. In case of floating-point errors, SIGFPE (Floating Point Exception)
  // is raised. We can create a signal handler function and assign it to SIGFPE
  // using signal() function. The setjmp() and longjmp() functions can be used
  // to jump to the previous valid state of the program, allowing you to handle
  // the exception and resume execution. The SIGFPE can be cleared by using the
  // feclearexcept and fetestexcept functions from the fenv.h header
  // include the following:
  // #include <fenv.h>
  // #include <setjmp.h>
  // #include <signal.h>

  double ay = 10, by = 0, resy;
  int recovery_status;

  // Assign the signal handler
  signal(SIGFPE, handle_divide_by_zero);

  // Set a recovery point
  recovery_status = setjmp(recovery);
  if (recovery_status == 0) {
    resy = ay / by;
    if (fetestexcept(FE_DIVBYZERO)) {
      feclearexcept(FE_DIVBYZERO);
      raise(SIGFPE);
    } else {
      printf("%f", resy);
    }
  }

  // The program sets up a signal handler for SIGFPE to catch floating-point
  // exceptions like division by zero. It attempts to divide a by b, where b is
  // 0, which will cause a floating-point exception. If the division by zero
  // exception occurs and raise(SIGFPE) will trigger the signal handler
  // (handle_divide_by_zero()). The signal handler prints an error message and
  // then uses longjmp() to return to the recovery point, avoiding the program
  // crashing. The program can then proceed without further errors (or cleanup
  // operations), as it has recovered from the division by zero.

  // C Preprocessors
  // Preprocessors are programs that process the source code before the actual
  // compilation begins. They are not part of the compilation process but
  // operate separately, allowing programmers to modify the code before
  // compilation
  //
  //
  // types of Preprocessor Directives are
  // Macros,
  // File Inclusion,
  // Conditional Compilation and Other directives like #undef, #pragma, etc.
  // Mainly these directives are used to replace a given section of C code with
  // another C code. For example, if we write "#define PI 3.14", then PI is
  // replaced with 3.14 by the preprocessor.
  //
  // Macros
  // Macros are used to define constants or create functions that are
  // substituted by the preprocessor before the code is compiled. The two
  // preprocessors #define and #undef are used to create and remove macros in C.
  // #define token value
  // #undef token
  for (int i = 0; i < LIMIT; //     Note There is no semi-colon (;) at the end
                             //     of the macro definition. Macro definitions
                             //     do not need a semi-colon to end.
       i++) { // before the compilation begins, the word LIMIT is replaced
              // with 5. The word 'LIMIT' in the macro definition is called a
              // macro template and '5' is macro expansion.
    printf("%d \n", i);
  }

  // We also have predefined macros
  printf("%d", __LINE__); // __LINE__ → current line number
  printf("%s", __FILE__); // __FILE__ → current file name
  printf("%s", __DATE__); // compilation date
  printf("%s", __TIME__); //__TIME__ → compilation time
  printf("%d", __STDC__); //__STDC__ → is standard C (usually 1)
  printf("%d",
         __STDC_HOSTED__); // __STDC_HOSTED__ → hosted environment (usually 1)
  printf(
      "%ld",
      __STDC_VERSION__); // __STDC_VERSION__ → C standard version (e.g. 201112L)

  // Macros With Arguments
  //
  // We can also pass arguments to macros. These macros work similarly to
  // functions. For example,
  //
  //     #define foo(a, b) a + b
  //     #define func(r) r * r
  int ah = 10, bh = 5;

  // Finding area using above macro
  printf("%d", AREA(ah, bh));

  // File Inclusion
  //
  // File inclusion allows you to include external files (header files,
  // libraries, etc.) into the current program. This is typically done using the
  // #include directive, which can include both system and user-defined files.
  //
  // Syntax
  // There are two ways to include header files.
  //     #include <file_name>
  //     #include "filename"
  // The '<' and '>' brackets tell the compiler to look for the file in the
  // standard directory while double quotes ( " " ) tell the compiler to search
  // for the header file in the source file's directory.
  // e.g
  // #include <stdio.h> // Includes the standard I/O library

  // Conditional Compilation
  //
  // Conditional compilation allows you to include or exclude parts of the code
  // depending on certain conditions. This is useful for creating
  // platform-specific code or for debugging. There are the following
  // conditional preprocessor directives: #if, #ifdef, #ifndef, else, #elif and
  // #endif
  //
  //
  // Syntax:
  //     #if
  //         // some code
  //     #elif
  //         // some more code
  //     #else
  //         // Some more code
  //     #endif
  // #endif directive is used to close off the #if, #ifdef, and #ifndef opening
  // directives. Example

// Check if PI is defined using #ifdef
#ifdef PI
  printf("PI is defined\n");

// If PI is not defined, check if SQUARE is defined
#elif defined(SQUARE)
  printf("Square is defined\n");

// If neither PI nor SQUARE is defined, trigger an error
#else
#error "Neither PI nor SQUARE is defined"
#endif

// Check if SQUARE is not defined using #ifndef
#ifndef SQUARE
  printf("Square is not defined");

// If SQUARE is defined, print that it is defined
#else
  printf("Square is defined");
#endif

  // other directives
  // #pragma:
  //
  // Provides specific instructions to the compiler to control its behaviour. It
  // is used to disable warnings, set alignment, etc.
  //
  // Syntax
  // #pragma directive
  // Some of the #pragma directives are discussed below:
  //
  // #pragma startup: These directives help us to specify the functions that
  //     are needed to run before program startup (before the control passes to
  //     main()).
  // #pragma exit: These directives help us to specify the
  //     functions that are needed to run just before the program exit (just
  //     before the control returns from main()).
  void func1();
  void func2();
  printf("Inside main()\n");

  // HEADERS
  // for header files in system/default
  // directory
  // #include <filename.h>

  // for Header files in same directory as
  // source file
  // #include "filename.h" user-defined

  // Standard Header Files in C
  //
  // Standard header files contain the libraries defined in the ISO standard of
  // the C programming language. They are stored in the system directory of the
  // compiler and are present in all the C compilers from any vendor.
  //
  // There are 31 standard header files in the latest version of C language.
  // Following is the list of some commonly used header files in C:

  // Header File
  //
  // Description
  // <assert.h>	It contains information for adding diagnostics that aid program
  // debugging.
  //
  // <errno.h>	It is used to perform error handling operations like errno(),
  // strerror(), etc.
  //
  // <float.h>	It contains a set of various platform-dependent constants
  // related to floating point values. These constants are proposed by ANSI C.
  //
  // They make programs more portable. Some examples of constants included in
  // this header file are- e(exponent), b(base/radix), etc. <math.h>	It is
  // used to perform mathematical operations like sqrt(), log2(), pow(), etc.
  //
  // <setjmp.h> It is used to perform non-local jumps using the setjmp macro and
  // longjmp function, allowing a program to bypass the standard function call
  // and return sequence.
  //
  // <signal.h>	It is used to perform signal handling functions like signal()
  // and raise().
  //
  // <stdarg.h>	It is used to perform standard argument functions like
  // va_start() and va_arg(). It is also used to indicate start of the
  // variable-length argument list and to fetch the arguments from the
  // variable-length argument list in the program respectively.
  //
  // <ctype.h>
  // It contains function prototypes for functions that test characters for
  // certain properties, and also function prototypes for functions that can be
  // used to convert uppercase letters to lowercase letters and vice versa.
  //
  // <stdio.h>	It is used to perform input and output operations using
  // functions like scanf(), printf() and provides error reporting via perror().
  //
  // <stdlib.h>	It contains standard utility functions like malloc(), realloc(),
  // etc. It contains function prototypes for functions that allow bypassing of
  // the usual function call and return sequence.
  //
  // <string.h>	It is used to perform various functionalities related to string
  // manipulation like strlen(), strcmp(), strcpy(), etc.
  //
  // <limits.h>	It determines the various properties of the various variable
  // types. The macros defined in this header limits the values of various
  // variable types like char, int, and long. These limits specify that a
  // variable cannot store any value beyond these limits, for example, an
  // unsigned character can store up to a maximum value of 255.
  //
  // <time.h>It is used to perform functions related to date() and time() like
  // setdate() and getdate(). It is also used to modify the system date and get
  // the CPU time respectively.
  //
  // <stddef.h>	It contains common type definitions used by C for performing
  // calculations.
  //
  // <locale.h>	It contains function prototypes and other information that
  // enables a program to be modified for the current locale on which it’s
  // running. It enables the computer system to handle different conventions for
  // expressing data such as times, dates, or large numbers throughout the
  // world.

  // Non-Standard Header Files
  //
  // Non-standard header files are not part of the language's ISO standard. They
  // are generally all the header files defined by the programmers for purposes
  // like containing custom library functions etc or provided as external
  // libraries by different vendors. They are manually installed by the user or
  // maybe part of the compiler by some specific vendor.
  //
  // There are lots of non-standard libraries for C language. Some commonly used
  // non-standard/user-defined header files are listed below: Header File
  // Description
  // <conio.h>	It contains some useful console functions.
  // <gtk/gtk.h>	It contains GNU's GUI library for C.

  // Using conio.h functions
  // printf("Press any key to print message \n");
  // // Wait for a key press
  // getch(); // you get theis error: ISO C99 and later do not support implicit
  //          // function declarations
  //          // conio.h is NOT part of standard C (C99, C11, etc.)
  // //  It only exists in some compilers (mainly old Turbo C / some Windows
  // //  setups)
  // // Call the additional function after a key press
  // displayMessage();
  // replace with
  printf("Press any key to continue...\n");
  getchar();
  displayMessage();

  // Creating and using a user-defined header in C
  // Create a header file
  //  myheader.h
  // #ifndef MYHEADER_H
  // #define MYHEADER_H
  //
  // void displayMessage();
  // int add(int a, int b);
  //
  // #endif
  // This prevents multiple inclusion (#ifndef guard)

  // Create implementation file
  //  myheader.c
  // #include <stdio.h>
  // #include "myheader.h"
  //
  // void displayMessage() {
  //     printf("Hello from user-defined header!\n");
  // }
  //
  // int add(int a, int b) {
  //     return a + b;
  // }

  // Use it in main.c
  // #include <stdio.h>
  // #include "myheader.h"
  //
  // int main() {
  //     displayMessage();
  //
  //     int sum = add(5, 3);
  //     printf("Sum = %d\n", sum);
  //
  //     return 0;
  // }

  // gcc main.c myheader.c -o app
  // ./app

  // if the h and .c are in another folder e.g
  // project/
  // │
  // ├── main.c
  // │
  // └── include/
  //     └── myheader.h
  // │
  // └── src/
  //     └── myheader.c
  //
  // in main.c
  // Include header from another folder
  // #include "include/myheader.h"
  // This tells the compiler where to find the header.
  // Compile with multiple folders
  // You must tell GCC where headers and source files are:
  // gcc main.c src/myheader.c -o app -Iinclude
  // What -Iinclude means
  // -I = “include path”
  // include = folder where .h files are

  // time.h header file in C
  // contains definitions of functions to get and manipulate date and time
  // information. It also includes functions, types and macros, which are used
  // by programs to measure time, manipulate dates and format time information.
  // It describes three time-related data types.
  //
  // clock_t: clock_t represents the processor time and is used to measure the
  // CPU clock cycles.
  // time_t: time_t represents the clock time as an integer
  // which shows the number of seconds since the beginning of the Unix Epoch (
  // 1st January 1970, UTC), which is a part of the calendar time.
  // struct tm:  struct tm holds the components of date and time such as hours,
  // minutes, seconds, day, month, year. The struct tm contains:

  // What is struct tm?
  // It is a standard time structure used in C (from <time.h>) to store
  // broken-down calendar time.
  // usage:
  time_t t = time(NULL);
  struct tm *info = localtime(&t);
  printf("%d:%d:%d\n", info->tm_hour, info->tm_min, info->tm_sec);

  // Functions in Time Library
  // Function Name	Explanation
  // asctime()	This function returns the date and time in the format
  // day month date hours:minutes:seconds year.
  // Eg: Sat Jul 27 11:26:03 2019.
  // asctime() function returns a string by taking struct tm variable as a
  // parameter. clock()	This function returns the processor time consumed by a
  // // program ctime()	This function returns the date and time in the format
  // day month date hours:minutes:seconds year
  // Eg: Sat Jul 27 11:26:03 2019
  // time is printed based on the pointer returned by Calendar Time
  // difftime()	This function returns the difference between the times provided.
  // gmtime()	This function prints the UTC (Coordinated Universal Time) Time
  // and date. Format for both gmtime() and asctime() is same mktime()	This
  // function returns the calendar-time equivalent using struct tm. time()
  // This function returns the calendar-time equivalent using data-type time_t.
  // strftime()	This function helps to format the string returned by other time
  // functions using different format specifiers

  // Get Current Date and Time
  //
  // To get the current date and time we use the combination of time() ,
  // localtime(), and asctime() functions as shown:
  //
  //     The time() function retrieves the current time since the beginning of
  //     Unix period( 1st Jan, 1970) in the form of time_t value stores it in
  //     the variable pointed by the pointer passed to it as an argument. The
  //     localtime() function to convert the time retrieved by time() function
  //     into local time components such as hours, minutes, seconds, day, month
  //     and year. It takes one parameter which is a pointer to a time value
  //     that is to be converted in local time. The asctime() function to
  //     convert the obtained time into a string representation of the local
  //     time in a human readable format which is "Day Mon Date HH:MM:SS
  //     YYYY\n". The asctime() accepts a pointer to a structure (struct tm)
  //     that contains the time component that is to be converted.

  // C program to get current local time
  // Structure to store local time
  struct tm *ptrt;

  // Variable to store current time
  time_t tuf;

  // Get current time
  tuf = time(NULL);

  // Convert it to local time
  ptrt = localtime(&tuf);

  // Get the string of local time
  printf("%s", asctime(ptrt)); // Tue Apr 15 07:22:42 2025

  // Print Time in UTC (Coordinated Universal Time)
  //
  // To print the UTC time, we use the gmtime() function that converts the time
  // obtained by the time() function into a Coordinated Universal Time (also
  // known as Greenwich Mean Time)
  // Structure to store local time
  struct tm *ptrfg;

  // Variable to store current time
  time_t tfg;

  // Get current time
  tfg = time(NULL);

  // Convert it to UTC time
  ptrfg = gmtime(&tfg);

  // Get the string of local time
  printf("%s", asctime(ptrfg)); // Tue Apr 15 12:44:17 2025

  // TIME DIFFERENCE
  time_t start, end;

  // Record start time
  start = time(NULL);
  int aj, bj;
  scanf("%d %d", &aj, &bj);
  printf("Sum of %d and %d is %d\n", aj, bj, aj + bj);

  // Record endtime
  end = time(NULL);

  // Print time difference
  printf("Time taken to print sum is %.2f seconds",
         difftime(end, start)); // Sum of 0 and 0 is 0 Time taken to print sum
                                // is 0.00 seconds

  // Print Time in hour::minute Format
  //
  // The program uses strftime() function which formats the date and time as
  // string according to the specified format by the user. To define the format
  // for the time the string uses format specifiers such as %l for hour in 12
  // hour format, %M for minutes and %p to for AM or PM.
  time_t rawtime;
  struct tm *timeinfo;

  // Used to store the time
  // returned by localtime() function
  char buffer[80];

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer, 80, "Time is %I:%M %p.", timeinfo);

  // strftime() function stores the current time as Hours : Minutes
  //%I %M and %p-> format specifier
  // of Hours minutes and am/pm respectively*/

  // prints the formatted time
  puts(buffer); // Time is 09:00AM.

  // clock_t tut;
  // int f;
  // tut = clock();
  // f = frequency_of_primes(9999);
  // printf("The number of primes lower"
  //        " than 10, 000 is: %d\n",
  //        f);
  // tut = clock() - tut;
  // printf(
  //     "No. of clicks %ld clicks (%f seconds).\n", tut,
  //     ((float)tut) /
  //         CLOCKS_PER_SEC); // The number of primes lower than 10, 000 is:
  //         1229
  //                          // No. of clicks 2837 clicks (0.002837 seconds).

  // Internal Linkage and External Linkage in C
  // Linkage is the property that determines how identifiers (variables and
  // functions) are connected across different parts of a program.
  //
  // Linkage determines whether an identifier can be shared across files or
  // remains restricted to the file in which it is declared (or a single
  // translation unit). It is different from scope, scope controls visibility,
  // while linkage controls accessibility across files. A translation unit is a
  // source file along with its included header files and dependencies,
  // processed as a single unit by the compiler to generate object code. In a
  // multi-file C program, each source file is compiled separately, and the
  // linker combines multiple object files to produce the final executable.

  // Internal Linkage
  // An identifier implementing internal linkage is not accessible outside the
  // translation unit it is declared in
  // It is implemented by the keyword static
  // An internally linked identifier is stored in initialized or uninitialized
  // segment of RAM
  // Consider a source file: animals.c
  // #include <stdio.h>
  //
  // // Variable with internal linkage
  // static int animals = 8;

  // The above code implements static linkage on identifier animals.
  // Consider another source file: feed.c is located in the same translation
  // unit using #include #include <stdio.h> #include "animals.c"
  //
  // int main() {
  //
  //   	// Accessing variable.
  //     printf("%d", animals);
  //     return 0;
  // }

  // On compiling and executing feed.c using the following command:
  //     gcc feed.c -o feed
  //     ./feed
  // We get the output,
  //     8

  // Now, consider that feed.c is located in a different translation unit (means
  // we are not including the animals.c using #include). Trying to compile it
  // using the following command:
  // we get:
  // gcc feed.c animals.c -o feed
  // ./feed
  // feed.c: In function 'main':
  // feed.c:6:18: error: 'animals' undeclared (first use in this function)
  //     6 |     printf("%d", animals);
  //       |                  ^~~~~~~
  // feed.c:6:18: note: each undeclared identifier is reported only once for
  // each function it appears in

  return 0;
}

// int g = 100; // extern variable definition

// gcc -Wall -save-temps filename.c –o filename
// gcc main.c -o main -Wall -save-temps
// include -Wall compiler's warning
// -save-temps : dont delete intermediate files between the compilation stages

// Compilation process stages includes:
// Preprocessing: expands macros & includes, removal of comments uses the .i
// extension Compilation: converts C → assembly, uses the .s extension Assembly:
// converts assembly → machine code .s is converted to .o extension Linking:
// combines objects + libraries → executable

// | File         | Meaning                                                    |
// | ------------ | ---------------------------------------------------------- |
// | `filename.i` | Preprocessed source (after `#include`, `#define` expanded) |
// | `filename.s` | Assembly code                                              |
// | `filename.o` | Object file (machine code before linking)                  |
// | `filename`   | Final executable                                           |

// If you want even more control:
//
// -E → only preprocessing
// -S → stop at assembly
// -c → stop at object
