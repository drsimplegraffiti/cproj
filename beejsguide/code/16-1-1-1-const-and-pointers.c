int x[] = {10, 20};
const int *p = x; 

p++;  // We can modify p, no problem

*p = 30; // Compiler error! Can't change what it points to
