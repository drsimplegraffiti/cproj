#include "greetings.h"
// to fix the swiggly line above
// sudo apt install bear
// make clean
// bear -- make
// or just: bear -- make clean all

// or just create .clangd in the root folder and add 
 // CompileFlags:
 //  Add:
 //    - -Iinclude

int main() {

    greet();

  return 0;
}

// gcc -Iinclude src/main.c src/greetings.c -o app
