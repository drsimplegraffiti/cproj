
// Memory Layout of C Programs
// The memory layout of a program shows how its data is stored in memory during
// execution. It helps developers understand and manage memory efficiently.
//     Memory is divided into sections such as code, data, heap, and stack.
//     Knowing the memory layout is useful for optimizing performance, debugging
//     and prevent errors like segmentation fault and memory leak.
//
// Dynamic memory allocation allows a programmer to allocate, resize, and free
// memory at runtime. Key advantages include.
//    Memory is allocated on the heap area instead of stack. Please refer memory
//    layout of C programs for details
// Array size can be increased or decreased as needed.
// Memory persists even after the function that allocated it finishes, allowing
// functions to return pointers to it. This is different from stack allocated
// variables as it is not safe to return address of those variable.
//
//
// malloc()

// The malloc() (stands for memory allocation) function is used to allocate a
// single block of contiguous memory on the heap at runtime. The memory
// allocated by malloc() is uninitialized, meaning it contains garbage values.
//
// Assume that we want to create an array to store 5 integers. Since the size of
// int is 4 bytes, we need 5 * 4 bytes = 20 bytes of memory. This can be done as
// shown:
