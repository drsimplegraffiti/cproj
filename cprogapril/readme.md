Splint - an enhanced version of lint(secure programming lint)
https://www.splint.org
```c
sudo apt install splint
splint -version
splint main.c

#useful
splint +weak main.c
#Splint
splint +strict main.c

Very strict (recommended for learning)
splint +bounds main.c

### Recommended
gcc main.c -o main
splint +strict main.c
./main
```

#### Note: 
Modern lsp will flag the errors

### Bound checkers and leaks finders.
Again modern LSPs will flag out of bound errors but old school way

e.g
```bash
#include <stdio.h> //directives

// before C is compiled, it is first edited by a preprocessor
// commands intended for the preprocessor are called `directives`

int main(void) { // { is similar to begin
  printf("hello world");

  int arr[3] = {1, 2, 3};

  printf("%d\n", arr[5]); // ❌ out of bounds
  return 0;
} // this is similar to end

```

#### Tools for this
```bash
valgrind ./main
valgrind --leak-check=full ./main
```
or

```bash
gcc -fsanitize=address main.c -o main

./main
```
These will scream when you:
- go out of bounds
- use invalid memory


#### linking and compiling a C code
- preprocessing
- compiling
- linking
The compiler handles the linking and compiling

cc - traditional C unix compiler


#### directives
Directives does not need ; at the end of the line


Functions are like sub-routines, or procedures in other language
