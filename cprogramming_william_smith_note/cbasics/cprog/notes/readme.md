C was design to be a system programming language. It is procedural language, no OOP.
memory management uses :

```bash
malloc()
free()
calloc()
```

Used for:

- Gaming engine
- Operating systems: Windows, Linux, MacOs
- Embedded systems: washing machine, printers, microwaves
- Compilers, Assemblers, Interpreters
- Databases
- Desktops lightweight applications: e.g notepad++
- Automation systems like IoT temperature control

#### install c on your machine

```bash
sudo apt update
sudo apt install build-essential
```

#### verify c

```bash
gcc -v
gcc --version
```

```c
#include <stdio.h> // header file has extension as .h

int main() {
  printf("hello world\n"); // statement
  return 0;
}
```

Other header files

```bash
stddef.h - Defines several useful types and macros.
stdint.h - Defines exact width integer types.
stdio.h - Defines core input and output functions
stdlib.h - Defines numeric conversion functions, pseudo-random number generator, and memory allocation
string.h - Defines string handling functions
math.h - Defines common mathematical functions.
```


#### keywords

![Image](./readme-img/251226-124520.avif)


#### Errors

![Image](./readme-img/251227-084745.avif)


#### file handling exception

![Image](./readme-img/251227-085731.avif)
