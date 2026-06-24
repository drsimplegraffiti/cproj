```c
```

```c
#include <stdio.h>
#include <stdlib.h> // for malloc and free

int main() {

    int sizeint = sizeof(int);
    printf("size of int is %d\n", sizeint);

    // if we have arrays of 4 elements
    // sizeint(4 bytes == 16bits) * 4 ==> 16 bytes
  // array is a collection of elements of the same type stored in consecutive
  // memory locations
  // consecutive mean: placed one after another in memory, with no gaps
  // arr[0] → address 1000
  // arr[1] → address 1004
  // arr[2] → address 1008
  // Just +4, +4, +4 → back-to-back
  //  and accessed through an index

  // array sample
  // data_type array_name[size];

  // in C arrays of c is not built in data type
  // the way around it is either:
  // 2D arrays or character pointer

  // 2D: Fixed-size grid (3 strings, each max 10 chars)
  // Stored contiguously in memory
  // Memory looks like: [monkey____][rabbit____][chicken___]

  // So C allocates:
  // 3 slots (rows)
  // each slot can hold 10 characters

  // Each bracket = one fixed-size string (10 chars)
  // [monkey____]
  // [rabbit____]
  // [chicken___]
  // "monkey" = 6 chars → remaining spaces unused (_)
  // "rabbit" = 6 chars → padded
  // "chicken" = 7 chars → padded
  //
  // 👉 _ just means unused memory (could be \0 nulls)
  char fruits[3][10] = {"monkey", "rabbit", "chicken"};
  printf("%s\n", fruits[0]);
  // C is doing this internally:
  // fruits[0] = {'m','o','n','k','e','y','\0', ?, ?, ?}
  // fruits[1] = {'r','a','b','b','i','t','\0', ?, ?, ?}
  // fruits[2] = {'c','h','i','c','k','e','n','\0', ?, ?}

  char *colors[] = {"red", "blue", "green"};
  printf("%s\n", colors[0]);
  // What it means:
  // Array of pointers → each points to a string literal
  // Strings stored somewhere else in memory
  // Memory looks like:
  // [pointer] → "red"
  // [pointer] → "blue"
  // [pointer] → "green"

  // Pros:
  // Flexible (different string lengths)
  // No wasted space

  // Rules:
  // Use 2D array → when size is fixed and you want performance
  // Use pointer array → when strings vary in length

  // Important gotcha
  // colors[0][0] = 'R'; // may crash (string literal is read-only)
  fruits[0][0] = 'M'; // safe
  printf("%c\n", fruits[0][0]);

  int numbers[5];
  // This creates an array named numbers that can hold 5 integers.

  // Initialization
  // You can initialize arrays when declaring them:
  int numbers1[5] = {1, 2, 3, 4, 5};

  // Or let the compiler infer the size:
  int numbers2[] = {1, 2, 3, 4, 5};

  //   Accessing Elements
  // Array elements are accessed using indices (starting from 0):
  printf("%d", numbers[0]); // prints first

  // Modifying Elements
  numbers[2] = 10; // changes third elemen

  printf("Array elements:\n");
  for (int i = 0; i < 5; i++) {
    printf("nums[%d] = %d\n", i, numbers[i]);
  }
  printf("\n");


    /*=======================================================
    3) Strings
  =======================================================*/
  char name[] = "John"; // String declaration & initialization
  printf("String: %s\n", name);

  // Access individual characters
  char firstLetter = name[0]; // 'J'
  printf("First letter: %c\n", firstLetter);

  // Modifying a string character
  name[0] = 'M';
  printf("Modified string: %s\n", name);


  //   Types of Arrays
  // One-Dimensional Array
  int arr[5];
  // Two-Dimensional Array (Matrix)
  int matrix[3][3];
  // Multi-Dimensional Array
  int arr1[2][3][4];

  // Dynamic arrays
  // It’s called dynamic not because size is unknown,
  // but because the size is decided at runtime (while the program runs).
  // You’re saying:
  // “At runtime, I want space for n elements”
  // Right now n = 5, but it could be:
  // int n;
  // scanf("%d", &n); // user decides size
  int n = 5; // number of elements we want

  // create a pointer that will point to the myarray
  int *myarr;

  // allocate memory for 5 integers on the heap
  // 5 × 4 = 20 bytes
  myarr = (int *)malloc(n * sizeof(int));

  // check if malloc failed (very important in real programs)
  if (myarr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  // assign values to the myarray
  for (int i = 0; i < n; i++) {
    myarr[i] = i + 1; // store values (1, 2, 3, 4, 5)
  }

  // print the values
  for (int i = 0; i < n; i++) {
    printf("%d ", myarr[i]); // access like a normal myarray
  }

  // free the allocated memory (VERY IMPORTANT)
  free(myarr);

  //   Key Ideas (Super Simple)
  // int *arr; → this is a pointer (it will hold the address of the array)
  // malloc(...) → asks the OS for memory
  // arr[i] → works just like a normal array
  // free(arr) → gives memory back to the OS

  // Think of it like this:
  // 👉 malloc = “Hey computer, give me space for 5 integers”
  // 👉 arr = “Here’s the address of that space”
  // 👉 arr[i] = “Go to position i in that space
  return 0;
}
```


