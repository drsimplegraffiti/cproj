# Compilation Options (Flags) in C

Compilation options (flags) in C control how a compiler—most commonly GCC or Clang—processes, optimizes, checks, and builds your source code into an executable.

## 1. Output & Compilation Stages

C compilation happens in four stages:

1. Preprocessing
2. Compilation
3. Assembly
4. Linking

You can stop at any stage or specify your output filename.

| Flag | Description | | --------------- | ----------------------------------------------------------------------------- |
| `-o <filename>` | Names the output executable (defaults to `a.out` on Linux/macOS). |
| `-E` | Stops after preprocessing and outputs expanded macros and headers. |
| `-S` | Stops after compilation and outputs assembly code (`.s` file). |
| `-c` | Stops after assembly and produces an unlinked object file (`.o` file). |
| `-save-temps` | Keeps intermediate `.i`, `.s`, and `.o` files alongside the final executable. |

**References:**

- [GCC Documentation](https://web.mit.edu/gnu/doc/html/gcc_6.html)
- [Compiling a C Program Behind the Scenes](https://www.geeksforgeeks.org/c/compiling-a-c-program-behind-the-scenes/)

## 2. Warnings & Error Checking

Compilers ignore many potential bugs unless you explicitly enable warnings.

Combining strict warning flags helps catch subtle mistakes early.

| Flag        | Description                                                                    |
| ----------- | ------------------------------------------------------------------------------ |
| `-Wall`     | Enables a core set of common, helpful warnings.                                |
| `-Wextra`   | Enables additional warnings not covered by `-Wall`, such as unused parameters. |
| `-Werror`   | Treats every warning as a fatal error, halting compilation until fixed.        |
| `-pedantic` | Enforces strict compliance with the chosen ISO C standard.                     |

**References:**

- [Useful GCC Flags for C](https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c)
- [Compiling a C Program Behind the Scenes](https://www.geeksforgeeks.org/c/compiling-a-c-program-behind-the-scenes/)

## 3. Optimization Levels

Optimization flags balance compilation speed, debugging ease, execution speed, and binary size.

| Flag  | Goal                                                                | Best Used For                                    |
| ----- | ------------------------------------------------------------------- | ------------------------------------------------ |
| `-O0` | No optimization (default).                                          | Debugging and step-by-step code inspection.      |
| `-O1` | Basic optimizations.                                                | Fast builds with modest performance gains.       |
| `-O2` | Standard production optimizations.                                  | Release builds with good performance.            |
| `-O3` | Aggressive optimizations, such as loop unrolling and vectorization. | Compute-heavy applications.                      |
| `-Os` | Optimizes for minimal binary size.                                  | Embedded systems and memory-constrained devices. |

## 4. Debugging & Runtime Sanitizers

When troubleshooting crashes, memory leaks, and undefined behavior, use debugging flags alongside `-O0`.

| Flag                   | Description                                                                                         |
| ---------------------- | --------------------------------------------------------------------------------------------------- |
| `-g`                   | Embeds debug symbols into the binary for debuggers like GDB or LLDB.                                |
| `-fsanitize=address`   | Detects out-of-bounds memory accesses and use-after-free bugs at runtime.                           |
| `-fsanitize=undefined` | Catches undefined behavior, such as signed integer overflow and certain invalid pointer operations. |

**References:**

- [Useful GCC Flags for C](https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c)
- [Compiler Options](https://software.codidact.com/posts/282565)

## 5. Language Standards & Linking

| Flag       | Description                                                                   |
| ---------- | ----------------------------------------------------------------------------- |
| `-std=c11` | Specifies the C11 language standard.                                          |
| `-std=c17` | Specifies the C17 language standard.                                          |
| `-std=c23` | Specifies the C23 language standard.                                          |
| `-I<dir>`  | Adds a directory to search for `#include` header files.                       |
| `-L<dir>`  | Adds a directory to search for external libraries.                            |
| `-l<name>` | Links a specific library. For example, `-lm` links the math library (`libm`). |

**Example:**

```bash
gcc -std=c17 -Wall -Wextra -Werror -Iinclude main.c calculator.c -lm -o main
```

## **6. Common Usage Examples**

### **A. Active Development & Debugging**

Use this configuration when developing and debugging C programs.

```
gcc -std=c17 -Wall -Wextra -g -O0 -fsanitize=address main.c -o app
```

### **B. Strict Compilation**

Use this configuration to catch warnings and enforce stricter compilation.

```
gcc -std=c17 -Wall -Wextra -Werror -pedantic main.c -o app
```

### **C. Fast Production Release**

Use this configuration when compiling a program for production.

```
gcc -std=c17 -Wall -O2 main.c -o app
```

### **D. Compile Multiple Source Files Separately**

Compile each source file into an object file.

```
gcc -std=c17 -Wall -Wextra -c main.c -o main.o
gcc -std=c17 -Wall -Wextra -c calculator.c -o calculator.o
```

Link the object files into an executable.

```
gcc main.o calculator.o -lm -o app
```

## **7. GCC vs. MSVC**

GCC and Clang generally use hyphen-prefixed flags, while Microsoft's MSVC compiler uses slash-prefixed options.

Examples:

| MSVC Flag | Description            |
| --------- | ---------------------- |
| `/O2`     | Optimizes for speed.   |
| `/Od`     | Disables optimization. |

**Reference:** [Microsoft Learn - Compiler Options](https://learn.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-by-category?view=msvc-170&utm_source=chatgpt.com)

## **8. Recommended GCC Command**

For everyday C development, I recommend starting with:

```
gcc -std=c17 -Wall -Wextra -Werror -pedantic -g -O0 main.c -o main
```

This enables:

- `-std=c17`: Uses the C17 standard.
- `-Wall`: Enables common warnings.
- `-Wextra`: Enables additional warnings.
- `-Werror`: Treats warnings as errors.
- `-pedantic`: Enforces stricter standard compliance.
- `-g`: Generates debugging information.
- `-O0`: Disables optimization for easier debugging.
- `-o main`: Names the executable `main`.

**Note:** If you use Microsoft's MSVC compiler on Windows instead of GCC/Clang, use its corresponding compiler options.

## **References**

1. [GCC Documentation](https://web.mit.edu/gnu/doc/html/gcc_6.html?utm_source=chatgpt.com)
2. [Compiling a C Program Behind the Scenes - GeeksforGeeks](https://www.geeksforgeeks.org/c/compiling-a-c-program-behind-the-scenes/?utm_source=chatgpt.com)
3. [GCC Compiler Flags - Stack Overflow](https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c?utm_source=chatgpt.com)
4. [Compiler Options - Microsoft Learn](https://learn.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-by-category?view=msvc-170&utm_source=chatgpt.com)
