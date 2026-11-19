- Preprocessing: Processes header files, macros, and conditional compilation directives.
- Compilation: Converts preprocessed C code into assembly code.
- Assembly: Converts assembly code into machine-code object files.
- Linking: Combines object files and resolves references to external functions and variables to produce an executable.

| File        | Description                              |
|-------------|------------------------------------------|
| `filename.c` | Original C source code                    |
| `filename.i` | Preprocessed C source code                |
| `filename.s` | Assembly code                             |
| `filename.o` | Object file containing machine code      |
| `filename`   | Final executable program                 |

## Preprocessing

Preprocessing is the first stage of the compilation process. The preprocessor handles directives that begin with # before the compiler processes the C code.

The main tasks performed during preprocessing are:
- Removes comments from the source code.
- Expands macros defined using #define.
- Processes header files included using #include.
- Handles conditional compilation directives such as #ifdef and #ifndef.

Consider:
```c
#include <stdio.h>

#define VALUE 10

int main(){
    
    printf("%d\n", VALUE);
    return 0;
}
```

During preprocessing, VALUE is replaced with 10, and the contents of the included header file are
processed. To generate the preprocessed output separately, use:

```bash
gcc -E filename.c -o filename.i
```

You can inspect the file using:
```bash
less filename.i
```
The filename.i file contains preprocessed C code that is passed to the compilation stage.


### 2. Compilation

In this stage, the compiler processes the preprocessed source code, performs language analysis and
optimization as applicable, and generates assembly code. The compiler checks the program for errors
such as invalid syntax and incompatible types.

To generate the assembly file, use:

```bash
gcc -S filename.i -o filename.s
```

The assembly code represents low-level instructions that can be translated into machine code by an
assembler.


## 3. Assembly

The assembler converts the assembly code into machine instructions and produces an object file. To
generate the object file, use: 

```bash
gcc -c filename.s -o filename.o
```

The generated filename.o file contains machine code along with information needed for linking.
At this stage:
Assembly instructions are converted into machine code.
Symbol and relocation information is stored in the object file.
References to external functions, such as printf(), may remain unresolved until linking.

## 4. Linking

Linking is the final stage of the compilation process. The linker combines object files with the
required libraries and resolves references to external functions and variables.

For example, when a program uses printf(), the linker processes the reference to the function
provided by the C standard library.

To link the object file, use:
```bash
gcc filename.o -o filename
```
The resulting filename file is an executable program.

### The linking process generally performs the following tasks:
- Combines object files into an executable.
- Resolves references to functions and variables across files.
- Incorporates required runtime startup code and library dependencies.

