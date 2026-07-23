# 5. Pointers to Functions

## 5.1 What Is a Function Pointer?
Every function lives at an address in memory too. A function pointer stores that
address, letting you call the function indirectly — pass functions as arguments,
store them in arrays/structs, and choose which function to run at runtime.

```c
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int (*operation)(int, int);   // declare a pointer to a function
                               // taking (int, int) and returning int

operation = add;              // assign (no & needed, function name decays like an array)
printf("%d\n", operation(3, 4));   // calls add(3,4) -> 7

operation = sub;
printf("%d\n", operation(3, 4));   // calls sub(3,4) -> -1
```

**Reading the declaration:** `int (*operation)(int, int)` — parentheses around
`*operation` are essential; without them, `int *operation(int, int)` would declare a
function returning `int *`.

## 5.2 Passing Function Pointers as Arguments (Callbacks)
```c
void applyToArray(int arr[], int size, int (*func)(int)) {
    for (int i = 0; i < size; i++)
        arr[i] = func(arr[i]);
}

int square(int x) { return x * x; }
int cube(int x) { return x * x * x; }

applyToArray(arr, 5, square);   // squares every element
applyToArray(arr, 5, cube);     // cubes every element
```
This is exactly how the standard library's `qsort` works:
```c
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
qsort(arr, n, sizeof(int), compare);
```

## 5.3 Arrays of Function Pointers
Useful for menu-driven programs or simple dispatch tables:
```c
int (*ops[4])(int, int) = {add, sub, mul, div};
int choice = 0;   // e.g. user picks "add"
printf("%d\n", ops[choice](5, 3));
```

## 5.4 Function Pointers in Structs
Common in simulating object-oriented behavior in C (e.g., "method tables"):
```c
typedef struct {
    char *name;
    void (*greet)(void);
} Greeter;

void sayHello(void) { printf("Hello!\n"); }

Greeter g = {"Formal", sayHello};
g.greet();   // calls sayHello
```

## 5.5 Typedef for Readability
```c
typedef int (*Operation)(int, int);
Operation op = add;   // much easier to read than int (*op)(int,int)
```

## 5.6 Common Uses
- Sorting/searching with custom comparators (`qsort`, `bsearch`).
- Callback-based event handling.
- State machines (array of function pointers indexed by current state).
- Plugin-style architectures / simple dependency injection in C.
