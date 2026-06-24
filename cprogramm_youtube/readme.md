    C - 1972
- Close to computer hardware because it allows low level access to memory through the use of pointers and memory address.
- rich standard libraries for i/o operations each `stdio.h`
- handle memory management yourself, allocate and free your memory 

### Install C 
- We can't install C directly instead we need a compiler 
- source code -> compiler -> machine code

### compiler
- GNU compiler collection : GCC
- Clang
- MSVC Microsoft C compiler

### installing C compiler on linux
```bash
sudo apt update
sudo apt install build-essential
gcc --version #or gcc -v
```

### installing C compiler on mac 
```bash
xcode-select --install
gcc --version
```

### installing C compiler on Windows
- go to https://www.msys2.org


### Hello world
.c extension 
```c
#include <stdio.h>

int main(){

printf("hello world \n"); //  \n

return 0;
}


```

#### compile and running your source code
```bash
gcc main.c #a.out 
gcc main.c -o main # 2nd approach main.exe
./main

```


### Variables and Datatypes
Variables are containers that hold certain values.
name="abayomi"

```c
data_type name_of_the_variable = value_of_any_data_type;
```

### Types of data types
```c
// whole numbers which are also called Integers: int 
// fractionals: float, double
// char : ''
// boolean : true or false or on or off
```



#### Data types and Variables Part 1
```c

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(){
  // variables and data types
  // variables are containers that holds certain values
  // data_type variable_name = 90;

  // Basic C variables and their data types
  int age = 10;     // whole number or integer
  char grade = 'A'; // char
                    //
  double dd = 90.89;
  printf("%lf\n", dd); // lf is used for double, f is used for float
  // fractional -> decimal points
  double myBalance = 56.78; // double has higher precision compared to float
  float myWalletBalance = 90.89f;

  // boolean -> on or off, true or false, 1 or 0
  bool isTall = true;

  // array of characters
  char name[] = "Abayomi";

  // format specifiers
  // %d or %i for int
  // %s for string
  // %c for characters
  // %f for float/double
  // %zu for size of a data type

  printf("my name is : %s\n", name);
  printf("my age is : %d\n", age);
  printf("my wallet balance is : %f\n", myWalletBalance);
  printf("my balance is : %f\n", myBalance);
  printf("%d\n", isTall);

  // signed and unsigned integers
  // signed = +ve and -ve values
  // unsigned = +ve

  // signed
  short b = 20;
  int a = -10;
  long c = -350;

  // unsigned
  unsigned int d = 10;
  unsigned long e = 400; // cannot hold a -ve value

  // NOTE: unsignedas a higher +ve range compared to signed
  // unsigned : 0 - 4,294, 967, 295
  // signed : -2,147,483,684 to 2,147,483,647

  // variables naming rules
  // use a meaningful name : x = 8; height = 8; weight = 90;
  // cannot start with a number : int 8x = 90;
  // we can't have space between a variable name: int my name =
  // variables are case sensitive i.e my_name, myName, MyName

  // Naming styles
  // snake_case, camelCase, PascalCase
  //

  // Size of a data type
  // %zu
  printf("char : %zu byte(s)\n", sizeof(char));
  printf("int: %zu byte(s)\n", sizeof(int));
  printf("short: %zu byte(s)\n", sizeof(short));
  printf("float: %zu byte(s)\n", sizeof(float));

  // 1 byte = 8 bits (0000, 1111)

  // fixed width for a data types
  int32_t largeNo = -20000000;
  int8_t smallNumber = -122;
  int16_t mediumNumber = -32000;

  printf("int8_t: %zu\n", sizeof(int8_t));
  printf("int16_t: %zu\n", sizeof(int16_t));
  printf("int32_t: %zu\n", sizeof(int32_t));
  printf("int64_t: %zu\n", sizeof(int64_t));

  // complex data types -> union, structs, arrays
  return 0;
}
```


### part 2 b
```c

#include <stdio.h>

// - introduction and installation of C
// variables and data types - part 2a
// part 2b -> variables, datatypes, variants, comments
//

int main() {

  int x = 5, y = 6, z = 7;
  printf("%d %d %d\n", x, y, z);


  // format specifiers
  // i or d for integers
  // d -> float and double
  // lf -> double 
  // f or F -> float
  float weight = 2.5F;
  double height = 9.10;
  printf("%f\n", weight);
  printf("%lf\n", height);


  // controlling the decimal precision
  // floats -> 6-7 decimal digits (default)
  // double -> 15 decimal digits

  float balance = 77.67;
  printf("default %f\n", balance);
  printf("one decimal precision %.1f\n", balance);
  printf("two decimal place %.2f\n", balance);

  // type conversion -> casting
  // promote or demote certain type 
  // int -> float or float <- int
  // explicit and the implicit conversion

  // implicit -> automatic conversion of one type to the other
  // explicit: manual conversion i.e software developer

  int myNo = 5;
  double myDouble = myNo + 2.5; // int + double => double
  printf("implicit conversion %lf\n", myDouble);

  double number = 8.5;
  int result = (int)number;
  printf("explicit conversion/casting %d\n", result);

  // variants of whole numbers
  short int smallInt = -100;  // -2e +2e -> common age of human 120
  long int bigInt = 1234567890;

  // single line comments
  /* multiline comment
   * this is a comment
   * int a = 89;
   * short int smallInt = 90;
   */

  // store characters as numbers using ASCII codes
  char a = 65, b=66, c=67;
  printf("%c %c %c \n", a, b, c);

  return 0;


}
```


#### Part 3
Functions, Structs and typedef
```c

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Using char *brand (pointer in struct)
struct CarOne {
  char *brand;
  int year;
};

struct Car {
  char brand[20]; // Memory is automatically allocated.
  int year;
};

struct Student {
  int age;
  // the memory for the string is stored inside the struct itself.
  // When you use: char *name;
  // the struct only stores a pointer to somewhere else in memory, so you must
  // provide memory for the string separately.
  char name[30];
  bool isTall;
};

/*
STRUCT NOTE (Using Person)

A struct in C is a user-defined data type that groups
different variables under one name.

Example:
Person can contain name, age, and height.

We use typedef so we can write:
    Person p;
instead of:
    struct Person p;
*/

typedef struct {
  char name[50];
  int age;
  float height;
} Person;

/* Function prototypes */
// p receives a copy of the struct.
// Any changes inside printPerson do NOT affect the original struct.
// Safe for reading only.
// printPerson(p1);  // p1 remains unchanged
void printPerson(Person p); // pass struct by value
// p is a pointer to the original struct.
//  Changes made via p->age modify the original struct.
//  Needed when you want to update the struct inside a function.
void updateAge(
    Person *p,
    int age); // pass struct by pointer, updateAge(&p1, 35); // p1.age is now 35
Person createPerson(char name[], int age, float height); // return struct

/* Function that prints struct contents */
void printPerson(Person p) {
  printf("Name: %s\n", p.name);
  printf("Age: %d\n", p.age);
  printf("Height: %.2f\n", p.height);
}

/* Function that modifies struct using pointer */
void updateAge(Person *p, int age) {
  p->age = age; // arrow operator used with pointers
}

/* Function that creates and returns a struct */
Person createPerson(char name[], int age, float height) {
  Person p;

  // Why strcpy is needed
  //  name in Person is declared as an array
  //  Arrays cannot be assigned with = in C:
  //  p.name = name; // ❌ invalid in C
  //  strcpy copies the content of one string into another.
  //  strcpy(dest_array, source_string);
  //  Needed whenever you want to copy a string into a char[], including inside
  //  structs.

  strcpy(p.name, name);
  p.age = age;
  p.height = height;

  return p;
}

int main() {

  // Without designated initializers:
  // Positional initializer: Values are assigned by order of fields in the
  // struct.
  struct Student jim = {89, "Jim", true};

  // Designated initializer: Values are assigned by field name using ..
  // .age is called a designated initializer in C (introduced in C99).
  // It tells the compiler which struct field you are initializing by name,
  // instead of relying on the order of fields.
  struct Student jude = {.age = 89, "Jim", true};

  printf("Name: %s\n", jim.name);
  printf("Age: %d\n", jim.age);
  printf("Is Tall: %d\n", jim.isTall);

  /* Creating struct variables */

  Person p1;                       // using typedef
  Person p2 = {"Alice", 25, 1.65}; // direct initialization

  /* Assigning values */
  // strcpy copies a string from src → dest and returns dest.
  // extern char *strcpy(char *restrict __dest, const char *restrict __src)
  strcpy(p1.name, "John");
  p1.age = 30;
  p1.height = 1.80;

  /* Accessing struct members */

  printf("Person 1:\n");
  printPerson(p1);

  printf("\nPerson 2:\n");
  printPerson(p2);

  /* Passing struct by pointer */

  updateAge(&p1, 35);

  printf("\nAfter updating age:\n");
  printPerson(p1);

  /* Returning struct from function */

  Person p3 = createPerson("David", 40, 1.75);

  printf("\nPerson 3:\n");
  printPerson(p3);

  struct Car car1;

  strcpy(car1.brand, "Toyota");
  car1.year = 2022;

  printf("Brand: %s\n", car1.brand);
  printf("Year: %d\n", car1.year);

  // memory layout:
  // car1
  // ├─ brand[20]  → stored inside struct
  // └─ year
  // So you can safely do:
  // strcpy(car1.brand, "Toyota");

  struct CarOne carone;
  carone.brand = "Toyota"; // pointer to string literal
  carone.year = 2022;

  printf("Brand: %s\n", carone.brand);
  printf("Year: %d\n", carone.year);
  // Memory layout
  // car1
  // ├─ brand → points to "Toyota" in memory
  // └─ year
  // The string is not inside the struct.

  // Simple rule beginners use
  // | Type            | Memory location | Ease                |
  // | --------------- | --------------- | ------------------- |
  // | `char name[20]` | inside struct   | easiest             |
  // | `char *name`    | somewhere else  | flexible but harder |
  //
  // Use char name[10]:
  // When:
  // The maximum size is known
  // The string belongs to the struct/variable
  // You want simple and safe code

  // Use char *name
  // When:
  // The string size is unknown or variable
  // The string comes from somewhere else
  // You want dynamic memory
}
```


#### Part 6
```c 

#include <stdio.h>

int main() {

  // arrays
  // an array is a collection of elements that are of the same type
  // stored in a consective memory.
  // Consecutive: placed after one another with no gaps
  // arr[0] -> address 1000
  // arr[1] -> address 1004
  // arr[2] -> address 1008

  // array sample
  // data_type array_name[size];

  // arrays of fixed size
  //              0 1 2
  int array[3] = {1, 2, 3}; // we have 3 elements with each element of 4 bytes

  // size of each element
  int sizeOfOneArray = sizeof(int);
  printf("size of one element is %d\n", sizeOfOneArray); // 4 bytes
  // we have 3 elemets * 4 bytes = 12bytes

  // access each members/elements of the array using the . operator
  // zero index based
  printf("first index %d\n", array[0]);
  printf("second index %d\n", array[1]);

  // arrays of string
  // 2D arrays or use a character pointer
  // problem like matrix
  int twoDArray[3][4] = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
  printf("%d\n", twoDArray[1][1]);

  // we 3 slots (3 rows)
  // each slot can hold 10 characters
  char animals[3][10] = {"monkey", "rabbit", "chicken"};
  printf("%s\n", animals[1]);
  printf("%c\n", animals[1][2]);

  // character pointer
  char *colors[] = {"red", "blue", "green"};
  // [pointer] -> red
  // [pointer] -> blue
  // [pointer] -> green
  printf("color is : %s\n", colors[2]);

  // initialization
  // you can initialize an array when declaring them
  int numbers[5] = {1, 2, 3, 4, 5}; // array

  // or let the compiler to infer the size
  int numbers2[] = {1, 2, 3, 4, 5}; // slice

  // loops:
  // 0 < 5 =  true
  // 1 < 5 =  true
  // 5 < 5 = false


  // getting the length of an array
  printf("sizeof numbers is: %lu\n", sizeof(numbers));
  printf("sizeof first element in numbers array is: %lu\n", sizeof(numbers[0]));
  int lengthOfNumbers = sizeof(numbers) /sizeof(numbers[0]);
  printf("numbers len: %d\n", lengthOfNumbers);

  for (int i = 0; i < lengthOfNumbers; i++) {
    printf("I am number : %d\n", numbers[i]);
  }

  // strings = arrays of characters
  char name[] = "john";
  // access individual characters
  printf("first letter : %c\n", name[0]);

  // modify character
  name[0] = 'L';

  printf("my name is: %s\n", name);

  // declare a dynamic array using keywords such as:
  // malloc
  //realloc
  // free our memory at the end

  return 0;
}
```


Linkage
```bash
// 📌 Internal vs External Linkage in C (ALL-IN-ONE SUMMARY)

// =========================
// 🔒 INTERNAL LINKAGE
// =========================
// - Only accessible inside the SAME .c file
// - Achieved using "static" keyword
// - Not visible to linker outside this file

// animals.c
static int animals = 8;   // ❌ private to this file

void showAnimals() {
    printf("%d\n", animals); // ✅ OK (same file)
}


// =========================
// 🌍 EXTERNAL LINKAGE
// =========================
// - Accessible across MULTIPLE .c files
// - Default for global variables & functions
// - "extern" is used to access from other files

// animals.c
int dogs = 5;   // ✅ external linkage (default global)

void printDogs() {
    printf("%d\n", dogs);
}


// feed.c
extern int dogs;   // 🔗 refers to variable defined in another file

int main() {
    printf("%d\n", dogs); // ✅ OK (linked from animals.c)
    return 0;
}


// =========================
// ⚙️ FUNCTIONS LINKAGE
// =========================

// external by default
void hello() {
    printf("Hello\n");
}

// internal (private to file)
static void secret() {
    printf("Hidden\n");
}


// =========================
// 🧠 KEY RULES (IMPORTANT)
// =========================
//
// static  → private to file (internal linkage)
// extern  → refers to external definition
// default global variable → external linkage
// linker connects external symbols across files


// =========================
// 🚀 REAL PROJECT IDEA
// =========================
//
// project/
//   animals.c   (defines variables/functions)
//   feed.c      (uses extern to access them)
//
// compile:
// gcc feed.c animals.c -o app
```


#### Internal Linking
Create items.c
```c
# Internal Linkage
#include <stdio.h>

// Variable with internal linkage
static int items = 10;
```
Then create display.c 

```c
#include <stdio.h>

extern int items; // try to access it

int main(){
   printf("total item is: %d", items);
   return 0;
}
```

compile:
gcc display.c items.c -o main

you get: 
undefined reference to `items`
That’s internal linkage working correctly — items is hidden.


/*
TL;DR: INTERNAL LINKAGE (static)

-----------------------------------
WHAT IT MEANS
-----------------------------------
"Only visible inside THIS .c file"

If you write:
static int x = 10;

→ ONLY this file can use x
→ Other .c files CANNOT see it

-----------------------------------
IMPORTANT: EACH .c FILE = TRANSLATION UNIT
-----------------------------------
file1.c  → one translation unit
file2.c  → another translation unit

-----------------------------------
CORRECT EXAMPLE
-----------------------------------

//// file1.c
#include <stdio.h>

static int items = 10;  // internal linkage

void print_items() {
    printf("items: %d\n", items);
}

//// file2.c
#include <stdio.h>

// trying to access items directly ❌
extern int items;   // this WON'T work

int main() {
    // printf("%d\n", items); ❌ ERROR (not visible)

    return 0;
}

-----------------------------------
KEY RULE
-----------------------------------
static = "hide this variable from other files"

-----------------------------------
WHY YOUR EXAMPLE IS CONFUSING
-----------------------------------

#include "items.c"

❌ This is NOT how C is meant to work

When you do this:
→ you literally COPY the code into the same file

So:
display.c + items.c → becomes ONE file

That means:
→ it's the SAME translation unit
→ so static works there

-----------------------------------
REAL WORLD (CORRECT WAY)
-----------------------------------

gcc items.c display.c -o app

Each file is separate

→ static variable in items.c is NOT accessible in display.c

-----------------------------------
MENTAL MODEL
-----------------------------------
static int x;

= "private variable for this file only"
*/


Part 7 Dynamic Memory allocation

```c

#include <stdio.h>
#include <stdlib.h>
#define INITIAL_LENGTH 10


int main(){

    int *ptr = (int *)malloc(sizeof(int) * INITIAL_LENGTH); // allocate 10 units
    if(ptr == NULL){
        printf("malloc failed\n");
        exit(1);
    }

    // assign first value
    *ptr = 10;

    printf("value : %d\n", *ptr);
    printf("address %p\n", (void *)ptr);


    // populate the Memory
    for(int i = 0; i < INITIAL_LENGTH; i++){
        ptr[i] = i + 1;
    }

    //print after manual population
    for(int i = 0; i < INITIAL_LENGTH; i++){
        printf("%d ", ptr[i]);
    }
    // free the allocated Memory
    free(ptr);






    // // malloc, calloc, free, realloc
    // printf("Dynamic Memory: \n");
    //
    // int length = INITIAL_LENGTH;
    //
    // // Calloc
    // // allocate memory for "length" elements and also intialize all elements to 0
    // int sizeofInt = sizeof(int); // will be 4 bytes
    // printf("sizeofInt is : %d\n", sizeofInt);
    //
    // int *mptr = calloc(length, sizeof(int)); // 0 0 0 0 0
    //
    // // check if allocation fails
    // if (mptr == NULL){
    //     printf("calloc allocation failed\n");
    //     exit(1);
    // }
    //
    // // print the initial values
    // printf("print initial values using calloc:\n");
    // for(int i = 0; i < length; i++){
    //     printf("%d ", mptr[i]);
    // }
    //
    // printf("\n");
    //
    // // populate the Memory manually
    // for (int i = 0; i < length; i++){
    //     mptr[i] = i + 1;
    // }
    //
    // printf("print after manual population:\n");
    // for (int i = 0; i < length; i++){
    //     printf("%d ", mptr[i]);
    // }
    //
    // // REALLOC : 5 -> 10
    // int oldLength = length; // 5
    // int newLength = 10;
    //
    // // resize the memory block
    // int *temp = realloc(mptr, newLength * sizeof(int));
    // if(temp == NULL){
    //     printf("Realloc failed\n");
    //     free(mptr);
    //     exit(1);
    // }
    //
    // // update the pointer and the length
    // mptr = temp; // 5 -> 10
    // length = newLength;
    //
    // for(int i = oldLength; i < length; i++){
    //     printf("%d ", mptr[i]);
    // }
    // printf("\n");
    //
    // // free the memory
    // free(mptr);
    //
    // mptr = NULL; // set to NULL to avoid dangling pointer
    //
    return 0;
}
```


#### Part 8
  =======================
  COMPILATION FLOW IN C
  =======================
  The compiler goes through 4 internal stages
  1. Preprocessing
     gcc -E file.c
     -> Handles #include, #define
      -> Removes comments
      e.g
  #include <stdio.h>
  #define X 10

  becomes:
  // contents of stdio.h pasted here
  int main() {
    printf("%d", 10);
  }
  Output is still C code, just expanded


  2. Compilation
     gcc -S file.c
     -> Converts C code to assembly
     -> file.s
     e.g: mov eax, 10, low-level instructions, but still readable

  3. Assembly
     gcc -c file.c
     -> Converts assembly to object file (.o), convert assembly to machine code
     -> This is binary, not human-readable
     -> Not yet executable
     -> Missing external references (like printf)
     View symbols (functions, variables):
     nm file.o
This shows assembly generated from machine code:
objdump -d file.o

  4. Linking
     gcc file.o -o app
     -> Produces executable
  What happens:
  Combines your .o file with libraries
  Resolves things like printf
   Example:

  Your code calls printf
  Linker connects it to the actual implementation
Check linked libraries:
ldd app


  // | File         | Meaning |
  // | ------------ | ----------------------------------------------------------
  |
  // | `filename.i` | Preprocessed source (after `#include`, `#define` expanded)
  |
  // | `filename.s` | Assembly code |
  // | `filename.o` | Object file (machine code before linking) |
  // | `filename`   | Final executable |

  // If you want even more control:
  //
  // -E → only preprocessing
  // -S → stop at assembly
  // -c → stop at object


  // gcc -Wall -save-temps filename.c –o filename
  // gcc main.c -o main -Wall -save-temps
  // include -Wall compiler's warning
  // -save-temps : dont delete intermediate files between the compilation stages

  SUMMARY
  C compilation is not one step — it’s a pipeline:
  Source code → Expanded → Assembly → Object → Executable

  FULL BUILD:
     gcc file.c -o app


#### Inspect Preprocessing
gcc -E file.c > file.i

gcc -v file.c -o app


### Part 9
Makefile:
A Makefile is just a way to automate compilation so you don’t keep typing long gcc commands.
https://www.gnu.org/software/make/manual/make.html


#### 10 compilation flags
gcc file.c -o app -Wall -Wextra -g

| Flag       | Meaning           |
| ---------- | ----------------- |
| `-Wall`    | basic warnings    |
| `-Wextra`  | extra warnings    |
| `-Werror`  | warnings = errors |
| `-g`       | debug info        |
| `-O2`      | optimization      |
| `-c`       | compile only      |
| `-o`       | output name       |
| `-std=c11` | C standard        |

1. Address Sanitizer (MOST IMPORTANT)
-fsanitize=address
Detects:

Buffer overflows
Use-after-free
Heap/stack memory corruption
Invalid memory access

gcc main.c -o app -fsanitize=address -g
./app
If there’s a bug, you’ll get a detailed runtime report


2. Undefined Behavior Sanitizer
-fsanitize=undefined
Detects:

Integer overflow
Null pointer dereference
Invalid shifts
Division by zero

combine both:
gcc main.c -o main -fsanitize=address,undefined -g


3. Stack Protector
-fstack-protector-strong

Detects:
Stack smashing (buffer overflow attacks)

4. Fortify Source (glibc protection)
-D_FORTIFY_SOURCE=2

Adds runtime checks for:
strcpy, sprintf, etc.
Detects unsafe usage

5. Extra warnings (compile-time bugs)
-Wall -Wextra -Wpedantic
Add more strict ones:
-Wshadow        # variable shadowing
-Wconversion    # implicit type conversion issues
-Wformat=2      # printf/scanf bugs


6. Debug symbols (needed for good reports)
-g
Without this, sanitizer output is harder to read


```bash
gcc main.c -o app \
-Wall -Wextra -Wpedantic \
-fsanitize=address,undefined \
-fstack-protector-strong \
-D_FORTIFY_SOURCE=2 \
-g
```


### gdb
To use gdb, use the `-g` flag for debug
gcc main.c -g -o main 
man gdb #for the rest



### convert strings to number
```c 
#include <stdio.h>

int main(){

char *str = "12345";
char *endptr;
long num = strtol(str, &endptr, 10);

if (str == endptr) {
    printf("No conversion performed.\n");
}
}
```


### Multiple Files
```c 
#include "calculate.h"
#include <stdio.h>

int main() {

  int numberOne, numberTwo;
  char opt;

  printf("Enter args (opt, n1, n2): ");
  scanf(" %c %d %d", &opt, &numberOne, &numberTwo);

  int res = calculate(numberOne, numberTwo, opt);
  printf("the result is: %d\n", res);

  // gcc main.c calculate.c -o main
  // gcc main.c -> main.o
  // gcc calculate.c -> calculate.o
  // gcc main.c calculate.c -o main -> link everything together

  return 0;
}
```


### File handling
```c

#include <stdio.h>

// File handling: it is used for storing data permanently in files
// instead of memory
int main() {

  // WRITE
  // FILE *fp = fopen("note.txt", "w");
  // if(fp == NULL){
  //     printf("file cannot be opened");
  //     return 1;
  // }
  //
  // fprintf(fp, "Hello world");
  // fclose(fp);

  // READ
  // char ch;
  // FILE *fp = fopen("note.txt", "r");
  // if (fp == NULL) {
  //   printf("file cannot be opened");
  //   return 1;
  // }
  //
  // while ((ch = fgetc(fp)) != EOF) {
  //   printf("%c", ch);
  // }
  //
  // fclose(fp);

  // APPEND

  FILE *fp = fopen("note.txt", "a");
  if (fp == NULL) {
    printf("file cannot be opened");
    return 1;
  }

  fprintf(fp, "From Abayomi\n");
  fclose(fp);
  return 0;

  // modes:
  // r -> read (file must exist)
  // w -> write (create or overwritr file)
  // a -> append
  // r+ -> read and write
  // w+ -> read + write(overwrite)
  // a+ -> read + append
}
```


#### Error handling
```c

#include <stdio.h>
#include <stdlib.h>

int main() {

    // Error -> when something goes wrong with your program
    // 1. Compilation Error:
    // this happens before the program runs, the compilers catches this error.
    // GCC/ Clang
    // int age = "hello";
    // printf("hello\n")
    // printf("printf\\");

    // 2. Runtime error
    // this kind of error happens when the program is running
    // int a = 10/0;
    // int *p = NULL;
    // *p = 10;
    // printf("%p\n", p);

    // 3. Logical error
    // if (x = 8)
    //   printf("something\n");
    // }


    // Error handling: in C error handling is manual
    // 1. Return codes: (0, 1, EXIT_FAILURE, EXIT_SUCCESS)

    // int denominator = 10;
    // if (denominator == 0) {
    //   printf("Error: division by zero \n");
    //   return EXIT_FAILURE;
    // }
    //
    // printf("all good\n");
    // return EXIT_SUCCESS; // anything non-zero is any error

    // 2. perror (system level error) --> print error
    // use when a system/library calls failes and set errno
    // FILE *file = fopen("data.txt", "r");
    // if(file == NULL){
    //     perror("failed to open file");
    // }
    //
    // fclose(file);
    // return EXIT_SUCCESS;

    // 3. Custom error
// int denominator = 0;
// if(denominator == 0){
//     fprintf(stderr, "invalid input\n");
// }
// return 0;

// 4. exit() immediate termination

int denominator = 0;
if(denominator == 0){
    fprintf(stderr, "FATAL ERROR\n");
    exit(EXIT_FAILURE);
}

// return 0;
}
```
