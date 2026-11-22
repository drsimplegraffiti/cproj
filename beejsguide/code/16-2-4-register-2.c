register int a[] = {11, 22, 33, 44, 55};
int *p = a;       // Undefined behavior!
int b = *(a + 2); // Undefined behavior!
int c = a[2];     // Undefined behavior!
