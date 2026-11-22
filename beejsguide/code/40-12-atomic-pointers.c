_Atomic int x;
_Atomic int *p;  // p is a pointer to an atomic int

p = &x;  // OK!
