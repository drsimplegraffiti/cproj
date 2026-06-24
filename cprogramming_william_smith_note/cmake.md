### CMake — Static Library (C)
What is Happening?

With CMake you:
Define a static library target
Define an executable target
Link the executable to the library
CMake handles compilation + archiving automatically
Static library result:

Linux → .a
Windows → .lib 

Project Structure:
```text
project/
│
├── CMakeLists.txt
├── main.c
├── mathlib.c
└── mathlib.h
```


### install cmake
```bash
sudo apt update
sudo apt install cmake
cmake --version
```

### Step 1 — Write the Library Code
mathlib.h
```c
#ifndef MATHLIB_H
#define MATHLIB_H

double add(double a, double b);
double subtract(double a, double b);

#endif
```

mathlib.c
```c
#include "mathlib.h"

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}
```

### Step 2 — Write the Main Program
main.c
```c
#include <stdio.h>
#include "mathlib.h"

int main() {
    printf("Result: %.2f\n", add(3.0, 2.0));
    return 0;
}
```

### Step 3 — Create CMakeLists.txt
This is the important part.
```text
cmake_minimum_required(VERSION 3.10)

project(MyProject C)

# Create static library
add_library(mathlib STATIC mathlib.c)

# Tell CMake where the header file is
target_include_directories(mathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Create executable
add_executable(main main.c)

# Link static library to executable
target_link_libraries(main mathlib)
```

What Each Command Does
add_library(mathlib STATIC mathlib.c)
- Creates a static library
- Output:
 -  Linux → libmathlib.a
 - Windows → mathlib.lib

target_include_directories(...)
- Makes header files visible
- PUBLIC means:
  The library uses it
  Anything linking to it also gets it

add_executable(main main.c)
 - Creates executable target

target_link_libraries(main mathlib)
 - Links mathlib into main
 - CMake handles correct linking automatically

### Step 4 — Build the Project
From project folder:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

After build:
Static library is created
Executable is created
The static library is embedded into the executable



### CMake — Dynamic (Shared) Library (C)
What is a Shared Library?

A shared library:
Linux → .so
Windows → .dll
Is loaded at runtime
Is NOT copied into the executable
Makes executable smaller
Must exist when the program runs


### Project Structure
```text
project/
│
├── CMakeLists.txt
├── main.c
├── mathlib.c
└── mathlib.h
```

### Step 1 — Write the Header
mathlib.h
```c
#ifndef MATHLIB_H
#define MATHLIB_H

double add(double a, double b);
double subtract(double a, double b);

#endif
```

### Step 2 — Write the Library Source
mathlib.c
```c
#include "mathlib.h"

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}
```

### Step 3 — Write the Main Program
main.c
```c
#include <stdio.h>
#include "mathlib.h"

int main() {
    printf("Result: %.2f\n", add(5.0, 3.0));
    return 0;
}
```

### Step 4 — CMakeLists.txt (Shared Library)
```text
cmake_minimum_required(VERSION 3.10)

project(MyProject C)

# Create shared library
add_library(mathlib SHARED mathlib.c)

# Make headers visible
target_include_directories(mathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Create executable
add_executable(main main.c)

# Link shared library
target_link_libraries(main mathlib)
```

### Important Difference from Static
Static:
```bash
add_library(mathlib STATIC mathlib.c)
```

Shared:
```bash
add_library(mathlib SHARED mathlib.c)
```

That is the key difference.


### Step 5 — Build
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### What Gets Generated?
Inside build/:
Linux:
```c
libmathlib.so
main
```

Windows:
```bash
mathlib.dll
mathlib.lib
main.exe
```

### Running the Program (Linux)
If the .so is not installed system-wide:
```bash
export LD_LIBRARY_PATH=.
./main
```

Or:
```bash
LD_LIBRARY_PATH=. ./main
```
