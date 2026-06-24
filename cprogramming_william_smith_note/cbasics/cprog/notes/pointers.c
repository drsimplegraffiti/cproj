#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) { return a + b; }

int main() {
  // a pointer stores the memory of another variable
  // Note that we use * for two different purposes in pointers. One is to
  // declare a pointer variable and the other is in an operator to get the value
  // stored at address stored in pointer.

  int num = 90;
  int *pnum = &num; // declare a pointer variable POINTER USAGE 1

  // Dereferencing ptr to access the value
  printf(" dereferenced value: %d\n",
         *pnum);                         // dereferenced value, POINTER USAGE 2
  printf(" memory address: %p\n", &num); // memory address of num

  // Size of Pointers
  //
  //     The size of a pointer in C depends on the
  //     architecture(bit system) of the machine,
  //     not the data type it points to.
  //
  //         On a 32 -
  //         bit system,
  //     all pointers typically occupy 4 bytes.On a 64 - bit system,
  //     all pointers typically occupy 8 bytes.

  int *ptr1;
  char *ptr2;

  // Finding size using sizeof()
  printf("%zu\n", sizeof(ptr1));
  printf("%zu", sizeof(ptr2));

  // There are 4 special types of pointers that used or referred to in different
  // contexts: The NULL Pointers are those pointers that do not point to any
  // memory location.
  //   They can be created by assigning NULL value to the pointer. A pointer of
  //   any type can be assigned the NULL value.
  // This allows us to check whether the pointer is pointing to any valid memory
  // location by checking if it is equal to NULL.
  int *pptr = NULL;

  // Void Pointer
  //
  //   The void pointers in C are the pointers of type void.
  //   It means that they do not have any associated data type.
  //   They are also called generic pointers as they can point to any type and
  //   can be typecasted to any type.
  void *ptr;

  //   Wild Pointers
  //
  // The wild pointers are pointers that have not been initialized with
  // something yet. These types of C-pointers can cause problems in our programs
  // and can eventually cause them to crash. If values are updated using wild
  // pointers, they could cause data abort or data corruption.
  int *ptr_;

  // Dangling Pointer
  //
  //   A pointer pointing to a memory location that has been deleted (or freed)
  //   is called a dangling pointer. Such a situation can lead to unexpected
  //   behavior in the program and also serve as a source of bugs in C programs.
  int *ptr_dangling = (int *)malloc(sizeof(int));

  // After below free call, ptr becomes a dangling pointer
  free(ptr_dangling);
  printf("Memory freed\n");

  // removing Dangling Pointer
  ptr_dangling = NULL;

  //   Constant Pointers
  //
  // In constant pointers, the memory address stored inside the pointer is
  // constant and cannot be modified once it is defined. It will always point to
  // the same memory address.
  int a = 90;
  int b = 50;

  // Creating a constant pointer
  int *const ptr_const = &a;

  // Trying to reassign it to b
  // ptr_const = &b;

  // Pointer to Function
  //
  //     A function pointer is a type of pointer that stores the address of a
  //         function,
  //     allowing functions to be passed as arguments and invoked dynamically.It
  //     is
  //         useful in techniques such as callback functions,
  //     event - driven programs.

  // Declare a function pointer that matches
  // the signature of add() function
  int (*fptr)(int, int);

  // Assign address of add()
  fptr = &add;

  // Call the function via ptr
  printf("%d", fptr(10, 5));

  // MUlti Level
  int var = 10;

  // Pointer to int
  int *ptr3 = &var;

  // Pointer to pointer (double pointer)
  int **ptr4 = &ptr3;

  // Accessing values using all three
  printf("var: %d\n", var);
  printf("*ptr1: %d\n", *ptr3);
  printf("**ptr2: %d", **ptr4);

  return 0;
}

// pointer = *
// memory address = &
