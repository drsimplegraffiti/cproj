
###  GDB
Source: https://sourceware.org/gdb

### Install
```bash
sudo apt install gdb
sudo apt install gcc-multilib
```

### Alternatives: LLDB Debugger
Source: https://lldb.llvm.org
```bash
sudo apt install lldb
```


### GNU Project Debugger
 up                 - go up in the call stack
 down               - go down in the call stack
 bt                 - Back trace, prints out the actual call stack, if mutiple functions calls each other
 start              - begin execution, pause at main, at the first that can be executed
 list               - show source code around current line
 list number        - show source code around current line + the number
 list function_name - show soruce code around the function
 call function_name - e.g with arguments call add(2,4)
 continue / c       - resume execution until next breakpoint
 next / n           - execute next line (skip into functions)
 next 3 or n 3      - next 3
 step / s           - execute next line (step into functions)
 finish             - run until current function returns
 run / r            - run program from beginning
 b printArray       - set breakpoint at function
 b 17               - set breakpoint at line 17
 br 17               - set breakpoint at line 17
 info               - info and press enter to see the options of what we have
 info breakpoints   - list all breakpoints
 info macro         - shows macro used
 info macro log     - show macro logs
 del 4              - delete breakpoint 4
 info locals        - show all local variables in current scope
 info threads       - list all threads
 info scope main    - gets the main scope
 print a            - print value of variable a
 display a          - print a automatically after every step
 whatis a           - show type of variable a
 whatis int         -  show the type of a data type
 whatis 1           -  show the type of a value
 whatis main        - show type of main
 ptype              - Just like whatis with more info
 bt                 - print full call stack
 layout src         - show source code TUI panel
 refresh            - redraw TUI screen
 quit / q           - exit gdb
 exit               - exit gdb
 gdb --tui --silent ./sandbox  - launch gdb with TUI mode
 gdb --tui
 print l->root or print *l.root - you can dereference 
 print &l -> prints the memory address of l
 info types -> list all the types of symbols and data structures in the file
 tbreak line_number -> temporary breakpoint
 tbreak function_name -> temporary breakpoint3
 advance 22 -> jumps to the line
 advance greet -> jumps to the function
 until 3 -> run until you hit line 
 j 1 -> jump to line 1
 watch 1 -> watch the state of the variable
 Enter -> repeat previous command
 rwatch x -> stops execution only when a variable or memory location is read.

 Save breakpoints, enable and disable them
 disable 1 -> disables breakpoint number 1
 disable 2
 save breakpoints debug_session_august.txt
 to open, launch into gdb, then:
 source debug_session_august.txt

display expression
display and undisplay let GDB automatically show the value of an expression
every time execution stops. They're very useful for tracking variables without
repeatedly typing print.
display x -> displays expression
display &p -> displays memory address

info display
info locals
info args
info frame


shrink window
wh src 5 -> wh for window height

```sh

(gdb) n
8       }
1: i = 9
2: 6 = 6
(gdb) info display 
Auto-display expressions now in effect:
Num Enb Expression
1:   y  i
2:   y  6
(gdb) 
```
undisplay 1
undisplay 2

display /b px -> /b is the byte value

```c
#include <stdio.h>

int main(void) {
    int i = 0;

    while (i < 5) {
        i++;
    }

    return 0;
}

```
gcc -g -O0 main.c -o main

Debug:
```sh
(gdb) break 7
(gdb) run
(gdb) display i
1: i = 0
```

Now every time you execute next:
```sh
(gdb) next
1: i = 1

(gdb) next
1: i = 2

(gdb) next
1: i = 3
```


![image](images/paste_1782453716.png)


```bash
~/Downloads/cprog main wip !3 ?6 ❯ gcc sandbox.c -g -o sandbox && gdb --silent ./sandbox                        3m 27s   system
Reading symbols from ./sandbox...
(gdb) info scope main
Scope for main:
Symbol p1 is a complex DWARF expression:
     0: DW_OP_fbreg -48
, length 16.
Symbol p_ptr is a complex DWARF expression:
     0: DW_OP_fbreg -56
, length 8.
(gdb) 
```

### Indenting Source Code
```bash
sudo apt install indent
#then 
indent main.c


# check
man indent to see more options
```

### Errors
### Comipile time error - before our program runs:
- syntax error
- missing files

### Runtime error - while our program is running:
- can be caught with an assert statement
- memory leaks
- segmentation faults: accessing illegal pieces of memory
- performance bugs



![image](images/paste_1782325157.png)

Here's what the compiler does step by step:
1. Lexing (tokenization) — the raw source string is split into tokens: int (keyword), x (identifier), = (operator), 8 (integer literal), ; (punctuator).
2. Parsing (AST construction) — the parser recognizes this as a VarDecl (variable declaration) node, which has two children: a TypeSpec (the type information — int, 4 bytes signed) and an InitExpr (the initializer expression — the literal value 8). The TypeSpec itself holds the identifier x and the type keyword int.
3. What comes next — the compiler walks this tree for semantic analysis (is x already declared? is 8 assignable to int?), then code generation (allocate 4 bytes on the stack, store 0x00000008 there).


#### Compilation warnings
Source: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
```c
#include <stdint.h>
#include <stdio.h>

struct Person {
  int age;
  int height;
  char grade;
};

void printArray() { printf("hello there\n"); }

int main(void) {
  int b;

  struct Person p1;
  printf("size of p1: %lu\n", sizeof(p1));

  int a;
  printf("void pointer: %p\n", (void *)&a);
  printf("void pointer: %p\n", &a);
  return 0;
}
```
```bash
gcc sandbox.c -Wall -Wextra -Wconversion -Werror -o sandbox
-Wall -> enables all errors
-Wconversion -> identifies conversion errors
-Werror -> will treat the warnings as errors
```

### Werror
```bash

sandbox.c: In function ‘main’:
sandbox.c:13:7: error: unused variable ‘b’ [-Werror=unused-variable]
   13 |   int b;
      |       ^
cc1: all warnings being treated as errors
```

You get:
```bash

~/Downloads/cprog main wip !3 ?6 ❯ gcc sandbox.c -Wall -Wextra -o sandbox                                                                 system

sandbox.c: In function ‘main’:
sandbox.c:13:7: warning: unused variable ‘b’ [-Wunused-variable]
   13 |   int b;
      |       ^
```

### Turn Debugger on or off
```c
#include <stdint.h>
#include <stdio.h>

struct Person {
  int age;
  int height;
  char grade;
};

void printArray() { printf("hello there\n"); }


#define DEBUG 0 // on is 1
int main(void) {

  struct Person p1;
  printf("size of p1: %lu\n", sizeof(p1));

  int a;

#if DEBUG
  printf("void pointer: %p\n", (void *)&a);
#endif

  printf("void pointer: %p\n", &a);
  return 0;
}
```

```c
#include <stdio.h>

#define DEBUG 1
// #undef DEBUG //this unset it immediately

int main(void) {
  int age = 10;
  char *name = "jones";

#if DEBUG
  printf("Name: \tname is %s\n", name);
#endif

  printf("Age: \tage is %d\n", age);

  return 0;
}
```

### Turn on debugger from the terminal
```c
#include <stdio.h>


int main(void) {
  int age = 10;
  char *name = "jones";

#if DEBUG
  printf("Name: \tname is %s\n", name);
#endif

  printf("Age: \tage is %d\n", age);

  return 0;
}

// turn on debugger from the terminal
// gcc sandbox.c -Wall -Wextra -Wconversion -Werror -DDEBUG -o sandbox &&
// ./sandbox
```

### Tabbing:
```c
#include <stdio.h>

int main(void) {
  int age = 10;
  char *name = "jones";

  printf("Name: \tname is %s\n", name);
  printf("Age: \tage is %d\n", age);

  return 0;
}
```


### to use gdb 
- Enable the `-g` flag
- `-g` adds debugging symbols, to our compiler code
- Without it you get the "Use file command"

### Optimization
- -O0 -> No optimization
- -O3 -> optimizes the code 

gcc -g -O3 sandbox.c -o sandbox
This can introduce some more codes to your program


### gdb --silent
Removes all the intros and all
```c
gdb --silent ./sandbox
```

### set listsize
```bash
set listsize 50
#sets the lists to have 50 over and under
```
### Passing struct pointer to a function
```c

#include <stdio.h>

struct Person {
  int age;
  char *name;
};

typedef struct {
  int age;
} Student;

void greet(struct Person *ptr) {
  printf("hello you are %s and your age is %d\n", ptr->name, ptr->age);
}

// Tuts
int main(void) {
  int age = 10;
  char *name = "jones";

  printf("Age: \tage is %d\n", age);
  printf("Name: \tname is %s\n", name);

  struct Person person_one = {.age = 19, .name = "jude"};
  printf("%p\n", (void *)&person_one);
  printf("name is %s\n", person_one.name);

  Student s1 = {.age = 0};
  printf("age is %d\n", s1.age);
  printf("m_age is %p\n", &s1.age);

  // -> is used to access the struct members through a pointer
  struct Person *p_ptr = &person_one;
  printf("the dereferenced member [dot annotation] %s\n", (*p_ptr).name);
  printf("the dereferenced member [-> annotation] %s\n", p_ptr->name);

  greet(p_ptr); // pass the pointer
  greet(&person_one); // pass address of the struct
  return 0;
}
```


### TUI 
Text User Interface
```gcc
gdb --tui ./sandbox
help layout


tui layout asm -- Apply the "asm" layout.
tui layout next -- Apply the next TUI layout.
tui layout prev -- Apply the previous TUI layout.
tui layout regs -- Apply the TUI register layout.
tui layout split -- Apply the "split" layout.
tui layout src -- Apply the "src" layout.
```

### swap windows
```bash
#help focus
sometimes this doesnt work in nvim because C-x is used, so :tnoremap <C-x>

Then use:
Ctrl-x 2   # split source + assembly
Ctrl-x 1   # single window
Ctrl-x o   # switch focus between windows
Ctrl-x a   # toggle tui on and off

// Alternatively you can use:

focus cmd
focus src
focus asm
focus regs
```


### resize a particular window
```bash
winheight src -2
winheight src -10
```

### redirect output from GDB to another terminal(window)
Open another terminal and type 
```sh
tty
```

```bash
~/Downloads/cprog main wip !3 ?6 ❯ tty                                                                                                                                               system
/dev/pts/3
```
In the opened `gdb` enter:

```bash
tty /dev/pts/3
```
GDB terminal:

![image](images/paste_1782412485.png)
```bash

(gdb) tty /dev/pts/3
(gdb) r
Starting program: /home/xybug/Downloads/cprog/sandbox 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
[Inferior 1 (process 60451) exited normally]
(gdb) 
```
OTHER Terminal:

![image](images/paste_1782412538.png)

```bash

/dev/pts/3
~/Downloads/cprog main wip !3 ?6 ❮ gdb ./sandbowarning: GDB: Failed to set controlling terminal: Operation not permitted                                                             system
Mem addrs of p1: 0x7fffffffc940
Name is: jude
Age is: 34
Person ptr member name: jude
Person ptr member age: 34
Person ptr member age: 34
hello your name is jude and you are 34
hello your name is jude and you are 34
```

### Method 2 of redirecting
In the gdb cmd console, run:
```sh
run > output.txt
```

### conditional breakpoints
```bash
b 1 if i < 3
b 1 if i < 3 && i < 5
```


```sh
warning: Source file is more recent than executable.
1       #include <stdio.h>
2
3       int main(void) {
4
5         int i = 9;
6         printf("int i = %d\n", i);
7         return 0;
8       }
9
10      // ~/Downloads/cprog main wip !3 ?7 ❯ gcc sandbox.c -g -o sandbox && gdb --silent ./sandbox                                                                                    1m 15s
   system
(gdb) b 5 if i < 3
Breakpoint 1 at 0x1155: file sandbox.c, line 5.
(gdb) info breakpoints 
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000001155 in main at sandbox.c:5
        stop only if i < 3
(gdb) 
```


### Help
man gdb
help
help tui
help focus


### Call stack
![image](images/paste_1782455160.png)

Where you go after each call stack
![image](images/paste_1782455399.png)



### Segmentation fault
Accessing address that you do not own
```c

#include <stdio.h>

int main(void) {

  int a = 90;
  int *ptra = NULL;
  printf("pointer is %d\n", *ptra);
  return 0;
}



Temporary breakpoint 2 at 0x1155: file sandbox.c, line 5.
Starting program: /home/xybug/Downloads/cprog/sandbox 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at sandbox.c:5
5         int a = 90;
(gdb) n
6         int *ptra = NULL;
(gdb) 
7         printf("pointer is %d\n", *ptra);
(gdb) 

Program received signal SIGSEGV, Segmentation fault.
0x0000555555555168 in main () at sandbox.c:7
7         printf("pointer is %d\n", *ptra);
(gdb) p *ptra
Cannot access memory at address 0x0
(gdb) 

```


### Memory Leak
```c
#include <stdlib.h>

int main(){

    while(1){
        int* bytes = malloc(sizeof(int)); // allocates one integer on the heap

        // free(bytes);  //FIX: return memory to the heap
    }
    return 0;
}

What's happening
malloc(sizeof(int)) allocates 4 bytes on the heap and returns a pointer to it. That pointer is stored in bytes.
The problem: free(bytes) is never called, and the loop is infinite — so every iteration:

A new 4-byte chunk is allocated
The previous pointer is overwritten and lost forever
There's now no way to free() that memory — the address is gone

Why it's a leak
The OS gave your process that memory. Without free(), your program never gives
it back. Since the loop runs forever, RAM consumption grows unboundedly until
the OS kills the process or the machine runs out of memory.
```


### Use valgrind to detect leaks
```c
#include <stdlib.h>

int main() {

  int *bytes = malloc(sizeof(int));
  return 0;
}


~/Downloads/cprog main wip !3 ?7 ❯ valgrind --leak-check=full ./sandbox                                                                                                              system
==78395== Memcheck, a memory error detector
==78395== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==78395== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==78395== Command: ./sandbox
==78395== 
==78395== 
==78395== HEAP SUMMARY:
==78395==     in use at exit: 4 bytes in 1 blocks
==78395==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==78395== 
==78395== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==78395==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==78395==    by 0x10915E: main (sandbox.c:5)
==78395== 
==78395== LEAK SUMMARY:
==78395==    definitely lost: 4 bytes in 1 blocks
==78395==    indirectly lost: 0 bytes in 0 blocks
==78395==      possibly lost: 0 bytes in 0 blocks
==78395==    still reachable: 0 bytes in 0 blocks
==78395==         suppressed: 0 bytes in 0 blocks
==78395== 
==78395== For lists of detected and suppressed errors, rerun with: -s
==78395== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```


### Allocate memory on the heap
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *byte = malloc(sizeof(int));
  if (byte == NULL) {
    return 1;
  }

  *byte = 9;

  printf("%d\n", *byte);

  free(byte);
  byte = NULL;

  return 0;
}
```

### stack overflow
```c
#include <stdio.h>

void foo(void) {
    foo();
}

int main(void) {
    foo();
    return 0;
}



~/Downloads/cprog main wip !3 ?7 ❯ valgrind --leak-check=full ./sandbox                                                                                                              system
==82849== Memcheck, a memory error detector
==82849== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==82849== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==82849== Command: ./sandbox
==82849== 
==82849== Stack overflow in thread #1: can't grow stack to 0x1ffe801000
==82849== 
==82849== Process terminating with default action of signal 11 (SIGSEGV)
==82849==  Access not within mapped region at address 0x1FFE801FF8
==82849== Stack overflow in thread #1: can't grow stack to 0x1ffe801000
==82849==    at 0x109131: foo (sandbox.c:4)
==82849==  If you believe this happened as a result of a stack
==82849==  overflow in your program's main thread (unlikely but
==82849==  possible), you can try to increase the size of the
==82849==  main thread stack using the --main-stacksize= flag.
==82849==  The main thread stack size used in this run was 8388608.
==82849== 
==82849== HEAP SUMMARY:
==82849==     in use at exit: 0 bytes in 0 blocks
==82849==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==82849== 
==82849== All heap blocks were freed -- no leaks are possible
==82849== 
==82849== For lists of detected and suppressed errors, rerun with: -s
==82849== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
[1]    82849 segmentation fault (core dumped)  valgrind --leak-check=full ./sandbox
~/Downloads/cprog main wip !3 ?7 ❯                                                                                                                                          ✘ SEGV   system

Each call to foo() creates a new stack frame. Since foo() never returns, the
stack keeps growing until it runs out of space, causing a stack overflow. This
is the canonical example used to demonstrate how the call stack works.
```

### Stack overflow via recursive calls
```c
void counter(int n){
    printf("%d\n", n);
    return counter(n+1);
}

int main(){
    counter(0);
    return 0;
}

```

### Sanitizers
```bash
gcc -g -fsanitize=address sandbox.c -o sandbox && ./sandbox
gcc -g -fsanitize=address,leak sandbox.c -o sandbox && ./sandbox
gcc -g -O0 -Wall -Wextra -fsanitize=address,leak sandbox.c -o sandbox && ./sandbox

~/Downloads/cprog main wip !3 ?8 ❯ gcc -g -O0 -Wall -Wextra -fsanitize=address,leak sandbox.c -o sandbox && ./sandbox                                                        ✘ INT   system

sandbox.c: In function ‘counter’:
sandbox.c:4:6: warning: infinite recursion detected [-Winfinite-recursion]
    4 | void counter(int n){
      |      ^~~~~~~
sandbox.c:6:12: note: recursive call
    6 |     return counter(n+1);
      |            ^~~~~~~~~~~~
^C
```

Ex 2
```c

#include <stdio.h>
#include <stdlib.h>


int main(){

    int* byte = malloc(sizeof(int));
}


~/Downloads/cprog main wip !3 ?8 ❯ gcc -g -O0 -Wall -Wextra -fsanitize=address,leak sandbox.c -o sandbox && ./sandbox                                                        ✘ INT   system

sandbox.c: In function ‘main’:
sandbox.c:7:10: warning: unused variable ‘byte’ [-Wunused-variable]
    7 |     int* byte = malloc(sizeof(int));
      |          ^~~~

=================================================================
==85010==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x74ef3d6fd9c7 in malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:69
    #1 0x604a53c3419e in main /home/xybug/Downloads/cprog/sandbox.c:7
    #2 0x74ef3d22a1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x74ef3d22a28a in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x604a53c340c4 in _start (/home/xybug/Downloads/cprog/sandbox+0x10c4) (BuildId: 3e8a4ef7a678eba3f749a723d0bd7cb6fcb7765b)

SUMMARY: AddressSanitizer: 4 byte(s) leaked in 1 allocation(s).
~/Downloads/cprog main wip !3 ?8 ❯                                                                                                                                                   system

```

### Assert the unit test
```c

#include <assert.h>
#include <stdlib.h>

int main() {

  int *ptr = NULL;
  assert(ptr != NULL);
  return 0;
}



~/Downloads/cprog main wip !3 ?8 ❯ gcc -g -O0 -Wall -Wextra -fsanitize=address,leak sandbox.c -o sandbox && ./sandbox                                                                system

sandbox: sandbox.c:10: main: Assertion `ptr != NULL' failed.
[1]    88171 IOT instruction (core dumped)  ./sandbox
```

### Assertion
```c

#include <assert.h>
#include <stdlib.h>

int main() {

  int *byte = malloc(sizeof(int));
  assert(byte != NULL);
  free(byte);
}

// or:
// #include <assert.h>
//
// int main() {
//   int *byte = new int;
//   assert(byte != NULL);
//   delete byte;
//   return 0;
// }
```

### Asset architecture
```c

#include <assert.h>

int main() {

  assert(sizeof(int) == 5);
}


~/Downloads/cprog main wip !3 ?8 ❯ gcc -g -O0 -Wall -Wextra -fsanitize=address,leak sandbox.c -o sandbox && ./sandbox                                                        ✘ IOT   system

sandbox: sandbox.c:5: main: Assertion `sizeof(int) == 5' failed.
[1]    91325 IOT instruction (core dumped)  ./sandbox

```


### static assertion, for compile error
```c
#include <assert.h>
#include <stdlib.h>

int main() {
  int *ptr = NULL;
  assert(ptr != NULL);
  static_assert(1 == 1, "");
  return 0;
}
```


### call 

```c


#include <stdio.h>
int add(int a, int b) { return a + b; }
int main() {

  int res = add(1, 3);
  printf("res is %d\n", res);

  return 0;
}
```
```bash
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Temporary breakpoint 1, main () at sandbox.c:7
(gdb) call add(1,2)
$1 = 3
(gdb) 

```

![image](images/paste_1782466645.png)


### sleep in C
```c

#include <stdio.h>   // printf
#include <unistd.h>  // sleep, usleep

    int main() {
        printf("sleeping...\n");  // print before sleeping
        sleep(3);                 // sleep for 3 seconds
        printf("woke up!\n");     // print after 3s
        usleep(500000);           // sleep for 500,000 microseconds (0.5s) — 'u' = µ (micro)
        printf("done\n");         // print after 0.5s
        return 0;
    }
```


### ps aux | grep name_of_process
- Step: run the above code in a terminal
```c
#include <stdio.h>  // printf
#include <unistd.h> // sleep, usleep

int main() {
  for (int i = 0; i < 1000; i++) {

    printf("sleeping...\n"); // print before sleeping
    sleep(3);                // sleep for 3 seconds
    printf("woke up!\n");    // print after 3s
    usleep(500000); // sleep for 500,000 microseconds (0.5s) — 'u' = µ (micro)
    printf("done\n"); // print after 0.5s
  }
  return 0;
}
```

```bash
~/Dow/cprog main wip !3 ?8 ❯ gcc -g -O0 -Wall -Wextra -fsanitize=address,leak sandbox.c -o san
dbox &&  ./sandbox
```
Then open another terminal and run
```bash
ps aux | grep [name_of_prog]
ps aux | grep sandbox

# cleaner
ps aux | grep sandbox | grep -v grep
# or cleaner:
pgrep -a sandbox
```

```bash
/Downloads/cprog main wip !3 ?8 ❯ pgrep -a sandbox                                                                                                                                  system
101489 ./sandbox
```

You can attach a running process using the above PID
```bash
gdb -p process_id
gdb -p 101489  
```

You can a message like attaching to the process not allowed so you have 
to be a sudo user before using it

![image](images/paste_1782468937.png)

so do:
```bash

sudo gdb -p 101489  
```

Then you should have this:
```c

~/Downloads/cprog main wip !3 ?8 ❯ pgrep -a sandbox                                                                                                                         1m 46s   system
103542 ./sandbox
~/Downloads/cprog main wip !3 ?8 ❯ sudo gdb -p 103542                                                                                                                                system
[sudo] password for xybug:
GNU gdb (Ubuntu 15.1-1ubuntu1~24.04.1) 15.1
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word".
Attaching to process 103542
Reading symbols from /home/xybug/Downloads/cprog/sandbox...
Reading symbols from /lib/x86_64-linux-gnu/libasan.so.8...
Reading symbols from /lib/x86_64-linux-gnu/libc.so.6...
Reading symbols from /usr/lib/debug/.build-id/8e/9fd827446c24067541ac5390e6f527fb5947bb.debug...
Reading symbols from /lib/x86_64-linux-gnu/libm.so.6...
Reading symbols from /usr/lib/debug/.build-id/05/cb320701679843b2853acf5b62daa306ea930f.debug...
Reading symbols from /lib/x86_64-linux-gnu/libgcc_s.so.1...
(No debugging symbols found in /lib/x86_64-linux-gnu/libgcc_s.so.1)
Reading symbols from /lib64/ld-linux-x86-64.so.2...
Reading symbols from /usr/lib/debug/.build-id/da/07864eb4c1b06504b8688d25d7e84759fe708d.debug...
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
0x0000785bd2ceca7a in __GI___clock_nanosleep (clock_id=clock_id@entry=0, flags=flags@entry=0, req=req@entry=0x7ffee7799260, rem=rem@entry=0x7ffee7799260)
    at ../sysdeps/unix/sysv/linux/clock_nanosleep.c:78

warning: 78     ../sysdeps/unix/sysv/linux/clock_nanosleep.c: No such file or directory
(gdb)

```

To detach:
```bash
detach
```


### When we crash our program we get a core dump/ memory dump/ crash dump
```c
#include <stdio.h>

int main() {
  int* ptr = NULL;
  *ptr = 8; // will cause segmatation error
  return 0;
}
```

gcc -g -O0 -Wall -Wextra -fsanitize=address,leak sandbox.c -o sandbox &&gdb  ./sandbox
# to see core dump
```bash
ulimit -a

# you get

~/Dow/cprog main wip !3 ?8 ❯ ulimit -a                                        ✘ INT   system
-t: cpu time (seconds)              unlimited
-f: file size (blocks)              unlimited
-d: data seg size (kbytes)          unlimited
-s: stack size (kbytes)             8192
-c: core file size (blocks)         0
-m: resident set size (kbytes)      unlimited
-u: processes                       62309
-n: file descriptors                1024
-l: locked-in-memory size (kbytes)  2019192
-v: address space (kbytes)          unlimited
-x: file locks                      unlimited
-i: pending signals                 62309
-q: bytes in POSIX msg queues       819200
-e: max nice                        0
-r: max rt priority                 0
-N 15: rt cpu time (microseconds)   unlimited
~/Downloads/cprog main wip !3 ?8 ❯                                                    system


```
You can set:
```bash
ulimit -c unlimited

# check ulimit
ulimit -c
```

check all
```sh
ulimit -a
# ulimit -c should be unlimited now
```

Then to find the core dump, install systemd-coredump
```bash
sudo apt install systemd-coredump
```

Then type:
```bash
coredumpctl
```


![image](images/paste_1782484789.png)
```c
~/Downloads/cprog main wip !3 ?8 ❯ coredumpctl                                                                                                                                       system

TIME                           PID  UID  GID SIG     COREFILE EXE                                                                            SIZE
Sat 2026-05-23 06:27:11 WAT  86112 1000 1000 SIGILL  missing  /opt/Postman/app/postman                                                          -
Sat 2026-05-23 06:42:01 WAT  92469 1000 1000 SIGABRT missing  /home/linuxbrew/.linuxbrew/Cellar/node/25.2.1/bin/node                            -
Sat 2026-05-23 06:48:03 WAT  93130 1000 1000 SIGABRT missing  /home/linuxbrew/.linuxbrew/Cellar/node/25.2.1/bin/node                            -
Sat 2026-05-23 06:51:05 WAT  94138 1000 1000 SIGABRT missing  /home/linuxbrew/.linuxbrew/Cellar/node/25.2.1/bin/node                            -
Sat 2026-05-23 06:54:02 WAT  94610 1000 1000 SIGABRT missing  /home/linuxbrew/.linuxbrew/Cellar/node/25.2.1/bin/node                            -
Tue 2026-05-26 17:52:38 WAT  24302 1000 1000 SIGTRAP missing  /usr/lib/virtualbox/VirtualBoxVM                                                  -
Thu 2026-06-04 10:20:47 WAT  27610 1000 1000 SIGABRT missing  /home/linuxbrew/.linuxbrew/Cellar/rust-analyzer/2025-12-29/bin/rust-analyzer      -
Sat 2026-06-06 14:40:53 WAT  48374 1000 1000 SIGABRT missing  /home/xybug/Downloads/cpp/build/myproject                                         -
Mon 2026-06-08 08:58:53 WAT  57904 1000 1000 SIGSEGV missing  /home/xybug/Downloads/cpp/main                                                    -
Wed 2026-06-10 14:29:20 WAT  41672 1000 1000 SIGABRT missing  /usr/bin/touchegg                                                                 -
Fri 2026-06-12 09:00:24 WAT  26376 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/main                                              19.7K
Fri 2026-06-12 09:01:04 WAT  26576 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/main                                              19.8K
Fri 2026-06-12 09:01:16 WAT  26635 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/main                                              19.8K
Fri 2026-06-12 18:26:20 WAT 125180 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/08_recursion/main                                305.5K
Sat 2026-06-13 07:18:31 WAT 167556 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/18_pointers_to_structs/main                       19.7K
Sat 2026-06-13 07:19:01 WAT 167716 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/18_pointers_to_structs/main                       19.8K
Sat 2026-06-13 09:30:52 WAT 192731 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/01_hello_argc_argv_atoi/main                     869.6K
Mon 2026-06-15 11:58:34 WAT  35267 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/a.out                                             19.8K
Tue 2026-06-16 07:28:32 WAT  21362 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/a.out                                             19.7K
Tue 2026-06-16 15:24:59 WAT  79614 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/a.out                                             19.7K
Tue 2026-06-16 15:25:02 WAT  79657 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/a.out                                             19.8K
Tue 2026-06-16 15:25:29 WAT  79770 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/a.out                                             19.8K
Tue 2026-06-16 18:52:16 WAT  15753 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/a.out                                             18.8K
Tue 2026-06-16 18:52:43 WAT  15825 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/a.out                                             18.8K
Tue 2026-06-16 18:56:27 WAT  16211 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/a.out                                             22.2K
Tue 2026-06-16 21:10:19 WAT  35308 1000 1000 SIGSEGV present  /home/xybug/Downloads/Cdict/a.out                                             19.9K
Fri 2026-06-19 19:34:10 WAT  41488 1000 1000 SIGABRT present  /home/xybug/Downloads/Cdict/a.out                                             20.2K
Fri 2026-06-19 19:34:36 WAT  41557 1000 1000 SIGFPE  present  /home/xybug/Downloads/Cdict/a.out                                             19.1K
Sun 2026-06-21 17:31:08 WAT  49525 1000 1000 SIGSEGV present  /usr/libexec/xscreensaver/gflux                                                1.4M
Fri 2026-06-26 07:51:38 WAT  76199 1000 1000 SIGSEGV present  /home/xybug/Downloads/cprog/sandbox                                          868.7K
Fri 2026-06-26 07:52:23 WAT  76656 1000 1000 SIGSEGV present  /home/xybug/Downloads/cprog/sandbox                                          868.7K
Fri 2026-06-26 08:30:33 WAT  82849 1000 1000 SIGSEGV present  /usr/libexec/valgrind/memcheck-amd64-linux                                     2.2M
Fri 2026-06-26 08:31:09 WAT  82968 1000 1000 SIGSEGV present  /home/xybug/Downloads/cprog/sandbox                                          384.6K
Fri 2026-06-26 08:36:14 WAT  83570 1000 1000 SIGSEGV present  /home/xybug/Downloads/cprog/sandbox                                          925.4K
Fri 2026-06-26 09:38:16 WAT  88171 1000 1000 SIGABRT present  /home/xybug/Downloads/cprog/sandbox                                          329.9K
Fri 2026-06-26 10:17:43 WAT  91232 1000 1000 SIGABRT present  /home/xybug/Downloads/cprog/sandbox                                          332.6K
Fri 2026-06-26 10:17:57 WAT  91325 1000 1000 SIGABRT present  /home/xybug/Downloads/cprog/sandbox                                          328.5K
Fri 2026-06-26 10:24:07 WAT  92250 1000 1000 SIGABRT present  /home/xybug/Downloads/cprog/sandbox                                          330.0K
~/Downloads/cprog main wip !3 ?8 V                                                                                                                              
```

The last line carries the last dump. You can run 
:

```bash
coredumpctl dump
coredumpctl gdb
```

### gcore
- Generate a core file of a running process

Steps:
```c
#include <stdio.h>
#include <unistd.h>

int main(void) {
    unsigned long long count = 0;

    while (count < 40) {
        printf("Count: %llu\n", count++);
        fflush(stdout);   // Print immediately
        sleep(2);
    }

    printf("Done!\n");

    return 0;
}
```
- run in a terminal (t1)

```bash
gcc -g -o0 sandbox.c -o sandbox &&  ./sandbox
```
- open another terminal(t2) and run 
```bash
ps aux | grep the_name_of_prog
ps aux | grep sandbox

# or
pgrep -a sandbox
```
- get the PID of the running program in t2
- run 

```bash
sudo gcore PID
```

```bash
~/Downloads/cprog main wip !3 ?8 ❯ sudo gcore 148155                                                                                                                                 system
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
0x000077c55f4eca7a in clock_nanosleep () from /lib/x86_64-linux-gnu/libc.so.6
warning: Memory read failed for corefile section, 4096 bytes at 0xffffffffff600000.
Saved corefile core.148155
[Inferior 1 (process 148155) detached]
~/Downloads/cprog main wip !3 ?9 V    
```
You will see :
```bash
-rw-r--r--  1 root  root  587K Jun 26 17:01 core.148155
```

To read it, use:
```bash
gdb -c core.148155
```

![image](images/paste_1782490327.png)

```bash

~/Downloads/cprog main wip !3 ?9 ❯ gdb -c core.148155                                                                                                                          10s   system

GNU gdb (Ubuntu 15.1-1ubuntu1~24.04.1) 15.1
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word".
[New LWP 148155]
Core was generated by `./sandbox'.
#0  0x000077c55f4eca7a in ?? ()
(gdb) bt
#0  0x000077c55f4eca7a in ?? ()
#1  0x00007fff9165c1a0 in ?? ()
#2  0x23fc6ea641a69d00 in ?? ()
#3  0x0000000000600000 in ?? ()
#4  0x0000000000000004 in ?? ()
#5  0x0000000000000005 in ?? ()
#6  0x000077c55f4eca7a in ?? ()
#7  0x0000000000000075 in ?? ()
#8  0x23fc6ea641a69d00 in ?? ()
#9  0x0000000000000800 in ?? ()
#10 0xffffffffffffff88 in ?? ()
#11 0x0000000000000000 in ?? ()
(gdb) up
#1  0x00007fff9165c1a0 in ?? ()
(gdb) up
#2  0x23fc6ea641a69d00 in ?? ()
(gdb) up
#3  0x0000000000600000 in ?? ()
(gdb) up
#4  0x0000000000000004 in ?? ()
(gdb) down
#3  0x0000000000600000 in ?? ()
(gdb) down
#2  0x23fc6ea641a69d00 in ?? ()
(gdb) down
#1  0x00007fff9165c1a0 in ?? ()
(gdb) down
#0  0x000077c55f4eca7a in ?? ()
(gdb)
```


#### Examine Memory (`x` Command)

```c
#include <stdio.h>

struct Student {
    int id;
    char grade;
    double gpa;
};

int main(void) {
    int number = 12345;
    int numbers[] = {10, 20, 30, 40, 50};
    char message[] = "Hello GDB!";
    char *ptr = message;

    struct Student student = {
        .id = 1001,
        .grade = 'A',
        .gpa = 4.0
    };

    printf("Paused here...\n"); // Set a breakpoint here

    return 0;
}
```

Compile with debug symbols:

```bash
gcc -g -O0 -Wall -Wextra sandbox.c -o sandbox
gdb ./sandbox
```

Start the program:

```gdb
start
```

Inspect variable types:

```gdb
whatis ptr
whatis message
whatis number
whatis student
```

Inspect variable addresses:

```gdb
p &number
p &numbers
p &message
p &ptr
p &student
```

Examine memory:

```gdb
x/wd &number        # decimal
x/wx &number        # hexadecimal
x/tw &number        # binary
x/5wd numbers       # array of integers
x/s message         # string
x/10cb message      # characters
x/16xb &student     # raw bytes of the struct
x/8wx &student      # struct as 4-byte words
x/10i $pc           # instructions at the program counter
x/20gx $rsp         # stack contents
```

---

### General Syntax

```text
x/nfu ADDRESS
```

where:

* **n** = number of units to display
* **f** = display format
* **u** = unit size

For example:

```gdb
x/8xb &number
```

means:

* `8` → examine **8** units
* `x` → display in **hexadecimal**
* `b` → each unit is **1 byte**

---

### Format Specifiers (`f`)

| Format | Meaning          |
| ------ | ---------------- |
| `x`    | Hexadecimal      |
| `d`    | Signed decimal   |
| `u`    | Unsigned decimal |
| `o`    | Octal            |
| `t`    | Binary           |
| `a`    | Address          |
| `c`    | Character        |
| `f`    | Floating-point   |
| `s`    | String           |
| `i`    | Instruction      |

Examples:

```gdb
x/4wx &number
x/4wd &number
x/16cb message
x/s message
x/10i $pc
```

---

### Unit Sizes (`u`)

| Unit | Size                 |
| ---- | -------------------- |
| `b`  | Byte (1 byte)        |
| `h`  | Halfword (2 bytes)   |
| `w`  | Word (4 bytes)       |
| `g`  | Giant word (8 bytes) |

Examples:

```gdb
x/8xb &number
x/4xh &number
x/2xw &number
x/1xg &number
```

---

### Common `x` Commands

| Command           | Description                                 |
| ----------------- | ------------------------------------------- |
| `x/wx &number`    | Display one 4-byte word in hexadecimal      |
| `x/wd &number`    | Display one 4-byte word in decimal          |
| `x/gx &number`    | Display one 8-byte value in hexadecimal     |
| `x/16xb &student` | Display 16 bytes of memory                  |
| `x/10cb message`  | Display 10 characters                       |
| `x/s message`     | Display a C string                          |
| `x/10i $pc`       | Display 10 machine instructions             |
| `x/20gx $rsp`     | Display 20 eight-byte values from the stack |
| `x/5wd numbers`   | Display an integer array                    |
| `x/8tb &number`   | Display 8 bytes in binary                   |
| `x/4a &ptr`       | Display addresses                           |

![image](images/paste_1782490824.png)


### commands
it's used to specify a list of commands that GDB should automatically execute whenever a breakpoint is hit.

```c
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 5; i++) {
        printf("%d\n", i);
    }
}
```

(gdb) break 5
Breakpoint 1 at 0x...

(gdb) commands 1
>print i
>continue
>end

You don't have to type continue each time.

### Example 2: Print a backtrace automatically
(gdb) break foo

(gdb) commands
>bt
>continue
>end

Example 3: Log variables
(gdb) break process

(gdb) commands
>silent
>printf "count = %d\n", count
>printf "value = %d\n", value
>continue
>end

Example 4: Modify a variable
(gdb) break main

(gdb) commands
>set var number = 100
>continue
>end

### define your own commands
- in gdb
type `define name_of_commands`


```c
#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 8;
}
```

```bash
(gdb) define lobster
Type commands for definition of "lobster".
End with a line saying just "end".
>print i
>whatis i
>info frame
>bt
>end
(gdb) 
```

Result:
```c
Starting program: /home/xybug/Downloads/cprog/sandbox 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Temporary breakpoint 2, main () at sandbox.c:5
5           int a = 0;
(gdb) lobster
Undefined command: "lobster".  Try "help".
(gdb) define lobster
Type commands for definition of "lobster".
End with a line saying just "end".
>bt
>print a
>whatis a
>end
(gdb) lobster 
#0  main () at sandbox.c:5
$1 = -13688
type = int
(gdb) 

```


you can redefine the name more like an edit
```c
(gdb) lobster 
#0  main () at sandbox.c:5
Ambiguous info command "a": address, all-registers, args, auto-load, auto-load-scripts, auxv.
(gdb) define lobster 
Redefine command "lobster"? (y or n) y
```

FYI: the above will be lost if you reload gdb

### define a script
create or open `nvim ~/.gdbinit`
paste:
```
print("this is lobster from xybug")
define lobster
bt
print $pc
end
```

When you run gdb, you should see:
```bash

For help, type "help".
Type "apropos word" to search for commands related to "word"...
$1 = "this is lobster from xybug"
Reading symbols from ./sandbox...
(gdb) 
```
So if you run:
```c
start
lobster
```

You get:
```c
Reading symbols from ./sandbox...
(gdb) start
Temporary breakpoint 1 at 0x1171: file sandbox.c, line 5.
Starting program: /home/xybug/Downloads/cprog/sandbox 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Temporary breakpoint 1, main () at sandbox.c:5
5           int a = 0;
(gdb) lobster 
#0  main () at sandbox.c:5
$2 = (void (*)()) 0x555555555171 <main+8>
(gdb) 
```


### Makefile
```c

CC=gcc                          # Set the C compiler to gcc
CCFLAGS= -g                     # Set compiler flags: -g enables debug symbols (for gdb/valgrind)

default: prog                   # Default target — running `make` alone will build `prog`

main.o : main.c                 # Rule: main.o depends on main.c
    $(CC) $(CCFLAGS) -c main.c  # Compile main.c into object file main.o (-c = compile only, no linking)

prog: main.o                    # Rule: prog depends on main.o
    $(CC) $(CCFLAGS) main.o -o prog  # Link main.o into final executable named `prog`

clean:                          # Utility target to remove build artifacts
    rm main.o                   # Delete the object file
    rm prog                     # Delete the compiled executable
```

```c
CC=gcc
CCFLAGS= -g

default: prog

main.o : main.c
	$(CC) $(CCFLAGS) -c main.c

prog: main.o
	$(CC) $(CCFLAGS) main.o -o prog

run:
	gdb ./prog

clean:
	rm main.o
	rm prog
```

### Shell commands in gdb
```bash
make prog
make run
```
Then in gdb run:
```bash
# you can also run make directly in gdb
make
shell ls
shell mkdir
shell make
shell make run
shell touch
shell mdkir test
shell rm -rf test
```

```bash
(gdb) shell ls
main.c  main.o  Makefile  prog  readme.md
(gdb) 
```

Make in gdb
```bash

(gdb) make
make[3]: Entering directory '/home/xybug/Downloads/cprog/gdb_udemy'
make[3]: Nothing to be done for 'default'.
make[3]: Leaving directory '/home/xybug/Downloads/cprog/gdb_udemy'
(gdb) 
```
### File command
The file command in gdb loads (or reloads) a binary and its symbol table into the current gdb session.
In your case:
```bash
(gdb) file ./prog
```
It does two things:

- Loads the executable — tells gdb which binary to debug
- Reads the symbol table — maps memory addresses back to your actual C source:
variable names, function names, line numbers, etc.


### Edit source file in gdb
Check the editor set in your terminal first:
```bash
echo $EDITOR
or
echo $VISUAL
```
You should get something like:
```bash
~/Downloads/cprog/gdb_udemy main wip !3 ?9 ❯ echo $EDITOR                                                                                   ✘ INT 8m 3s   system
nvim
```

If not set, set with:
```bash
export EDITOR=nvim
export VISUAL=nvim
source ~/.zshrc   # or ~/.bashrc depending on your shell
```

Then: 
Note: You might need to open in another terminal entirely
```bash
## in gdb run:
edit line_number
edit 5

:wq
start or just use file ./prog to reload the new executable
```


### Use python in gdb
```c
(gdb) python
>print(1+3)
>end
4
(gdb) 
```

or

```c
(gdb) python print("hello")
hello
(gdb) 
```

python interactive command
```bash
## in gdb

(gdb) pi

>>> print(1+2)

3
>>> print("hello")

hello
>>> exit

Use exit() or Ctrl-D (i.e. EOF) to exit
>>> quit

(gdb) 

```

### Python in GDB

GDB has a built-in Python interpreter you can use to script and automate debugging.

#### Basic usage
```bash
(gdb) python print("hello from python")
(gdb) python import gdb
(gdb) python help(gdb)
```

#### Execute GDB commands from Python
```bash
(gdb) python gdb.execute("start")       # start the program
(gdb) python gdb.execute("next 3")      # step over 3 lines
(gdb) python gdb.execute("continue")    # continue execution
(gdb) python gdb.execute("backtrace")   # print call stack
```

#### Breakpoints
```bash
(gdb) python gdb.execute("break main")          # set breakpoint at main
(gdb) python gdb.Breakpoint("main.c:10")        # set breakpoint at line 10
(gdb) python print(gdb.breakpoints())           # list all breakpoints
(gdb) python gdb.breakpoints()[0].delete()      # delete first breakpoint
```

#### Inspect values
```bash
(gdb) python print(gdb.parse_and_eval("a"))     # print value of variable `a`
(gdb) python print(gdb.parse_and_eval("a + b")) # evaluate expression
```

#### Multi-line Python scripts
```bash
(gdb) python
>import gdb
>for bp in gdb.breakpoints():
>    print(bp.location, bp.enabled)
>end
```

#### Run a Python script file
```bash
(gdb) source my_script.py
```

`my_script.py` example:
```python
import gdb

gdb.execute("break main")
gdb.execute("run")

val = gdb.parse_and_eval("a")
print(f"value of a: {val}")

```

```bash

(gdb) source my_script.py 
Breakpoint 1 at 0x1155: file main.c, line 4.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at main.c:4
warning: Source file is more recent than executable.
4           int a = 2;
value of a: -13864
(gdb) 


```

#### Docs
https://sourceware.org/gdb/current/onlinedocs/gdb.html/Python-API.html

Python API for debugger:
https://sourceware.org/gdb/current/onlinedocs/gdb.html/Python-API.html


### Set values in gdb
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void print_employee(Employee *emp) {
    printf("Name: %s, Age: %d, Salary: %.2f\n", emp->name, emp->age, emp->salary);
}

int sum_array(int *arr, int len) {
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += arr[i];
    }
    return total;
}

int main(int argc, char *argv[]) {
    /* --- set variable / set var --- */
    int a = 1;
    int b = 8;

    /* --- set print pretty / struct --- */
    Employee emp = {"Alice", 30, 50000.0};
    print_employee(&emp);

    /* --- set print array / set print elements --- */
    int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int len = sizeof(numbers) / sizeof(numbers[0]);
    int total = sum_array(numbers, len);
    printf("Sum: %d\n", total);

    /* --- set print null-stop --- */
    char greeting[20] = "Hello, GDB!";
    printf("%s\n", greeting);

    /* --- set args --- */
    if (argc > 1) {
        printf("Got arg: %s\n", argv[1]);
    }

    /* --- set environment --- */
    char *env_val = getenv("FOO");
    if (env_val) {
        printf("FOO=%s\n", env_val);
    }

    printf("a=%d, b=%d\n", a, b);
    return 0;
}
```


### Set values in GDB
```sh
#### Set variable values
```bash
(gdb) set variable a = 10          # set variable `a` to 10
(gdb) set variable b = 20          # set variable `b` to 20
(gdb) set var a = 10               # shorthand for set variable
```

#### Set program arguments
```bash
(gdb) set args arg1 arg2           # set arguments passed to the program on run
(gdb) show args                    # show current arguments
```

#### Set environment variables
```bash
(gdb) set environment FOO = bar    # set env var FOO to bar
(gdb) unset environment FOO        # unset env var FOO
(gdb) show environment             # show all env vars
```

#### Set breakpoint pending
```bash
(gdb) set breakpoint pending on    # allow breakpoints on symbols not yet loaded
(gdb) set breakpoint pending off   # disable pending breakpoints
```

#### Set print options
```bash
(gdb) set print pretty on         # pretty print structs
(gdb) set print array on          # print arrays in readable format
(gdb) set print null-stop on      # stop printing char arrays at null terminator
(gdb) set print elements 0        # print unlimited array elements (0 = unlimited)
```

#### Set pagination
```bash
(gdb) set pagination off          # disable "press enter to continue" prompt
(gdb) set pagination on           # re-enable pagination
```

#### Set logging
```bash
(gdb) set logging on              # log gdb output to gdb.txt
(gdb) set logging file debug.log  # change log file name
(gdb) set logging off             # stop logging
```

#### Set follow-fork mode (for forking programs)
```bash
(gdb) set follow-fork-mode child   # follow child process after fork()
(gdb) set follow-fork-mode parent  # follow parent process after fork() (default)
```

#### Show any setting
```bash
(gdb) show variable               # show all settable variables
(gdb) show print                  # show all print settings
```


### Reverse Debugging in GDB

Reverse debugging lets you **run your program backwards** — step back in time to see exactly what changed a value and when.

**`main.c`**
```c
#include <stdio.h>

void corrupt(int *val) {
    *val = 999;   /* bug: overwrites value unexpectedly */
}

int main(void) {
    int a = 1;
    int b = 8;
    int c = a + b;       /* c should be 9 */

    corrupt(&c);         /* c is now 999 — but why? */

    printf("c = %d\n", c);  /* prints 999 instead of 9 */
    return 0;
}
```

**`Makefile`**
```makefile
CC=gcc
CCFLAGS= -g

default: prog

main.o : main.c
	$(CC) $(CCFLAGS) -c main.c

prog: main.o
	$(CC) $(CCFLAGS) main.o -o prog

run:
	gdb ./prog

clean:
	rm main.o prog
```

#### Step 1 — Enable recording
```bash
(gdb) file ./prog
(gdb) break main
(gdb) run
(gdb) record              # start recording execution history, same as (gdb) target record-full

record full is the default recording method — it records every instruction and
the old value of every memory location changed, so it can fully reconstruct any
previous state.

There's also a second method:
(gdb) target record-btrace    # branch trace — uses CPU hardware
```
> Everything after `record` can be replayed backwards.

#### Step 2 — Run forward to the bug
```bash
(gdb) continue            # run until end or next breakpoint
# or step through manually
(gdb) next
(gdb) next
(gdb) next
```

#### Step 3 — Go backwards
```bash
(gdb) reverse-next        # step backwards over a line (rn)
(gdb) reverse-step        # step backwards into a function (rs)
(gdb) reverse-continue    # run backwards until a breakpoint (rc)
(gdb) reverse-finish      # run backwards out of current function
```

#### Step 4 — Catch the exact moment `c` was corrupted
```bash
# set a watchpoint on c, then reverse
(gdb) watch c             # triggers when c changes
(gdb) reverse-continue    # run backwards — gdb stops at the line that changed c
```
You'll land exactly on `*val = 999` inside `corrupt()`.

#### Full session example
```bash
$ make
$ gdb ./prog

(gdb) break main
(gdb) run
(gdb) record

(gdb) next                # int a = 1
(gdb) next                # int b = 8
(gdb) next                # int c = a + b   → c is 9
(gdb) next                # corrupt(&c)     → c becomes 999
(gdb) next                # printf

(gdb) print c             # 999 — wrong!

(gdb) watch c
(gdb) reverse-continue    # gdb rewinds to exact line that changed c

# gdb stops at:
#   *val = 999  inside corrupt()
# Now you know exactly what corrupted c
```

#### All reverse commands

| Command            | Short | What it does                              |
|--------------------|-------|-------------------------------------------|
| `reverse-next`     | `rn`  | Step back one line (no function entry)    |
| `reverse-step`     | `rs`  | Step back into previous function call     |
| `reverse-continue` | `rc`  | Run backwards to last breakpoint/watchpoint |
| `reverse-finish`   | —     | Step backwards out of current function    |
| `record`           | —     | Start recording execution                 |
| `record stop`      | —     | Stop recording                            |
| `set exec-direction reverse` | — | Make `next`/`step`/`continue` go backwards by default |
| `set exec-direction forward` | — | Restore normal direction              |

#### Flip execution direction globally
```bash
(gdb) set exec-direction reverse
(gdb) next        # now goes backwards without typing reverse-next
(gdb) next
(gdb) set exec-direction forward   # back to normal
```

#### Caveats
- `record` has **overhead** — program runs slower while recording
- Recording stops at **syscalls** by default — use `record full` to try to handle them
- Only works on **native** gdb (not remote/embedded targets without support)
- Buffer fills up on long runs — use `set record insn-number-max 200000` to increase it



### Debugging Multi-threaded Programs in C using GDB

**`main.c`**
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int id;
    int value;
} ThreadData;

pthread_mutex_t lock;
int shared = 0;

void *worker(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    pthread_mutex_lock(&lock);
    shared += data->value;          /* critical section */
    printf("Thread %d: shared = %d\n", data->id, shared);
    pthread_mutex_unlock(&lock);

    sleep(1);                       /* simulate work */
    return NULL;
}

int main(void) {
    pthread_t threads[4];
    ThreadData data[4];

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 4; i++) {
        data[i].id    = i;
        data[i].value = (i + 1) * 10;
        pthread_create(&threads[i], NULL, worker, &data[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final shared value: %d\n", shared);
    pthread_mutex_destroy(&lock);
    return 0;
}
```

**`Makefile`**
```makefile
CC=gcc
CCFLAGS= -g -pthread

default: prog

main.o : main.c
	$(CC) $(CCFLAGS) -c main.c

prog: main.o
	$(CC) $(CCFLAGS) main.o -o prog

run:
	gdb ./prog

clean:
	rm main.o prog
```

#### List all threads
```bash
(gdb) info threads
# output:
#   Id   Target Id         Frame
# * 1    Thread 0x... (LWP 12345) "prog" main ()
#   2    Thread 0x... (LWP 12346) "prog" worker ()
#   3    Thread 0x... (LWP 12347) "prog" worker ()
#   4    Thread 0x... (LWP 12348) "prog" worker ()
# * = currently selected thread
```

#### Switch to a specific thread
```bash
(gdb) thread 2            # switch to thread 2
(gdb) thread 3            # switch to thread 3
```

#### Show current thread
```bash
(gdb) thread              # prints which thread you are on
```

#### Backtrace per thread
```bash
(gdb) thread 2
(gdb) backtrace           # call stack of thread 2

# backtrace all threads at once
(gdb) thread apply all backtrace
(gdb) thread apply all bt # shorthand
```

#### Run a command on all threads
```bash
(gdb) thread apply all next          # step all threads one line
(gdb) thread apply all print shared  # print shared var in all threads
(gdb) thread apply 1 2 3 backtrace  # specific threads only
```

#### Set breakpoint on a specific thread
```bash
(gdb) break worker                   # breaks on all threads hitting worker
(gdb) break worker thread 2          # breaks only when thread 2 hits worker
(gdb) break main.c:20 thread 3       # breaks at line 20 only for thread 3
```

#### Lock scheduler (control which thread runs)
```bash
(gdb) set scheduler-locking on       # only current thread runs when you step
(gdb) set scheduler-locking off      # all threads run freely (default)
(gdb) set scheduler-locking step     # lock during step, unlock on continue
```
> `scheduler-locking on` is essential to isolate one thread while stepping
> without other threads racing ahead.

#### Inspect shared variable across threads
```bash
(gdb) break worker                   # break inside worker
(gdb) run

# when a thread hits the breakpoint:
(gdb) print shared                   # value at this point
(gdb) print data->id                 # which thread data
(gdb) print data->value

(gdb) thread apply all print shared  # compare across all threads
```

#### Watch shared variable for changes
```bash
(gdb) watch shared                   # triggers whenever shared changes
(gdb) continue                       # gdb stops at every write to shared
```

#### Detect deadlocks
```bash
# if program hangs, Ctrl+C then:
(gdb) thread apply all backtrace
# look for threads stuck on:
#   pthread_mutex_lock
#   __lll_lock_wait
# those are deadlocked threads
```

#### Full session example
```bash
$ make
$ gdb ./prog

(gdb) break worker
(gdb) run

# thread hits breakpoint
(gdb) info threads                   # see all threads
(gdb) set scheduler-locking on       # freeze other threads
(gdb) next                           # step only this thread
(gdb) print shared                   # inspect shared value
(gdb) print data->id                 # which thread is this

(gdb) thread apply all backtrace     # see all stacks

(gdb) watch shared                   # watch for changes
(gdb) set scheduler-locking off
(gdb) continue                       # let all threads run
# gdb stops every time shared is written
```

#### All thread commands

| Command                          | What it does                                  |
|----------------------------------|-----------------------------------------------|
| `info threads`                   | List all threads                              |
| `thread N`                       | Switch to thread N                            |
| `thread`                         | Show current thread                           |
| `thread apply all bt`            | Backtrace all threads                         |
| `thread apply N cmd`             | Run command on thread N                       |
| `break X thread N`               | Breakpoint only for thread N                  |
| `set scheduler-locking on`       | Only current thread steps                     |
| `set scheduler-locking off`      | All threads run freely                        |
| `set scheduler-locking step`     | Lock on step, unlock on continue              |
| `watch var`                      | Watch a variable for changes across threads   |

#### Caveats
- Compile with `-pthread` flag or linking will fail
- Thread order is non-deterministic — runs may differ each time
- `scheduler-locking on` is your best tool to isolate one thread
- Use `watch` on shared variables to catch race conditions
- For complex race conditions consider also using `valgrind --tool=helgrind ./prog`

### Checkpoints and Bookmarks in GDB

A checkpoint is like `fork()` — it creates a **snapshot/copy of your running program**
at that exact moment in time. You can restore back to it at any point, as many times
as you want, without restarting the program.

**`main.c`**
```c
#include <stdio.h>
#include <stdlib.h>

int counter = 0;

void increment(int steps) {
    for (int i = 0; i < steps; i++) {
        counter++;                    /* we want to snapshot at various points */
        printf("counter = %d\n", counter);
    }
}

int main(void) {
    int a = 10;
    int b = 20;

    increment(5);                     /* counter goes 1..5  */

    a = a * 2;                        /* a = 20 */
    b = b + a;                        /* b = 40 */

    increment(5);                     /* counter goes 6..10 */

    printf("a=%d b=%d counter=%d\n", a, b, counter);
    return 0;
}
```

**`Makefile`**
```makefile
CC=gcc
CCFLAGS= -g

default: prog

main.o : main.c
	$(CC) $(CCFLAGS) -c main.c

prog: main.o
	$(CC) $(CCFLAGS) main.o -o prog

run:
	gdb ./prog

clean:
	rm main.o prog
```

#### How checkpoints work
```c
normal run:   [start] --> [A] --> [B] --> [C] --> [end]

with checkpoints:
              [start] --> [A] --> checkpoint 1
                               --> [B] --> checkpoint 2
                                        --> [C] --> end
                                        <-- restore 2  (jump back to B)
                               <-- restore 1  (jump back to A)
```
> Under the hood gdb calls fork() — your process is literally duplicated.
> The copy is frozen at that point and can be thawed (restored) any time.

#### Create a checkpoint
```c
(gdb) checkpoint              # snapshot current state
# output:
# checkpoint 1: fork returned pid 12345
```

#### List all checkpoints
```c
(gdb) info checkpoints
# output:
#   Id   PID          Frame
#   1    12345        increment () at main.c:8
# * 0    12340        main () at main.c:20      <- * = current
```

#### Restore a checkpoint
```bash
(gdb) restart 1               # jump back to checkpoint 1
                              # all variables, memory, registers restored
```

#### Delete a checkpoint
```bash
(gdb) delete checkpoint 1     # free the forked process
```

#### Full session example
```c
$ make
$ gdb ./prog

(gdb) break main
(gdb) run

# --- at start of main ---
(gdb) checkpoint              # checkpoint 1: beginning of main
(gdb) info checkpoints

(gdb) next                    # int a = 10
(gdb) next                    # int b = 20
(gdb) next                    # increment(5)
(gdb) print counter           # 5

(gdb) checkpoint              # checkpoint 2: after first increment

(gdb) next                    # a = a * 2
(gdb) next                    # b = b + a
(gdb) print a                 # 20
(gdb) print b                 # 40

(gdb) checkpoint              # checkpoint 3: after a and b updated

(gdb) next                    # increment(5) again
(gdb) print counter           # 10

# --- go back and re-examine ---
(gdb) restart 2               # jump back to after first increment
(gdb) print counter           # 5 again
(gdb) print a



### Reload binary
After changing your code in another file, you can reload in gdb(erminal 2)
```

```c
(gdb) file ./prog 
A program is being debugged already.
Are you sure you want to change the file? (y or n) y
Load new symbol table from "./prog"? (y or n) y
Reading symbols from ./prog...
(gdb) 

```



### Enable and Disable breakpoints
```c
# enable / disable control whether breakpoints are active or not
# without deleting them — so you can bring them back later

(gdb) break main       # breakpoint 1
(gdb) break worker     # breakpoint 2
(gdb) break counter    # breakpoint 3

(gdb) info breakpoints # see all — all enabled by default

(gdb) disable 2        # breakpoint 2 still exists but gdb ignores it
(gdb) enable 2         # turn it back on

(gdb) disable          # disable ALL breakpoints at once
(gdb) enable           # enable ALL breakpoints at once

(gdb) disable 1 3      # disable multiple at once
(gdb) enable 1 3       # enable multiple at once

# in info breakpoints output:
# Num  Enb  ...
#  1    y   ...   <- enabled
#  2    n   ...   <- disabled (n = no)
#  3    y   ...   <- enabled
```


### Data display debugger
sudo apt install ddd
ddd ./prog

![image](images/paste_1782566282.png)

Then you can run the normal commands you use to run:

![image](images/paste_1782566343.png)
You can doible click on the *data it will create a section in the view

![image](images/paste_1782566886.png)


### strace
strace traces every system call your program makes — it shows you exactly how your program talks to the Linux kernel.
```bash
strace ./prog
```
You get:
```c
xecve("./prog", ["./prog"], 0x7fffe83ff4b0 /* 80 vars */) = 0
brk(NULL)                               = 0x6114dcc2a000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7d7c67925000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=104407, ...}) = 0
mmap(NULL, 104407, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7d7c6790b000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7d7c67600000
mmap(0x7d7c67628000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7d7c67628000
mmap(0x7d7c677b0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7d7c677b0000
mmap(0x7d7c677ff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7d7c677ff000
mmap(0x7d7c67805000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7d7c67805000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7d7c67908000
arch_prctl(ARCH_SET_FS, 0x7d7c67908740) = 0
set_tid_address(0x7d7c67908a10)         = 39783
set_robust_list(0x7d7c67908a20, 24)     = 0
rseq(0x7d7c67909060, 0x20, 0, 0x53053053) = 0
mprotect(0x7d7c677ff000, 16384, PROT_READ) = 0
mprotect(0x6114b0e6f000, 4096, PROT_READ) = 0
mprotect(0x7d7c67965000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7d7c6790b000, 104407)          = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0x4), ...}) = 0
getrandom("\xd0\xb6\xae\x17\xd0\xd1\x1d\xd2", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x6114dcc2a000
brk(0x6114dcc4b000)                     = 0x6114dcc4b000
write(1, "c = 999\n", 8c = 999
)                = 8
exit_group(0)                           = ?
+++ exited with 0 +++

```


### strace -c the number of system calls
```bash
strace -c ./prog
strace ./prog                    # trace everything
strace -e trace=write ./prog     # only show write() calls
strace -e trace=open,read ./prog # only open and read calls
strace -o log.txt ./prog         # save output to file
strace -p 1234                   # attach to a running process by PID
strace -c ./prog                 # summary: count + time per syscall
```

```c
~/Downloads/cprog/gdb_udemy main wip !3 ?9 ❯ strace -c ./prog                                                                                                                ✘ INT   system

c = 999
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         1           read
  0.00    0.000000           0         1           write
  0.00    0.000000           0         2           close
  0.00    0.000000           0         3           fstat
  0.00    0.000000           0         8           mmap
  0.00    0.000000           0         3           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         2           pread64
  0.00    0.000000           0         1         1 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           arch_prctl
  0.00    0.000000           0         1           set_tid_address
  0.00    0.000000           0         2           openat
  0.00    0.000000           0         1           set_robust_list
  0.00    0.000000           0         1           prlimit64
  0.00    0.000000           0         1           getrandom
  0.00    0.000000           0         1           rseq
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000           0        34         1 total
```

### ltrace
ltrace is a program that simply runs the specified command until it exits. 
```bash
ltrace ./prog
ltrace -c ./prog #summary
```

```c
~/Downloads/cprog/gdb_udemy main wip !3 ?9 ❯ ltrace ./prog                                                                                                                           system
printf("c = %d\n", 999c = 999
)                                                                                              = 8
+++ exited (status 0) +++
```

```c

~/Downloads/cprog/gdb_udemy main wip !3 ?9 ❯ ltrace -c ./prog #summary                                                                                                       ✘ INT   system

c = 999
% time     seconds  usecs/call     calls      function
------ ----------- ----------- --------- --------------------
100.00    0.000196         196         1 printf
------ ----------- ----------- --------- --------------------
100.00    0.000196                     1 total
```
ltrace -c is a quick way to sanity check how many times a library function was called — useful for spotting things like


### Valgrind 
Used for analysing memory leaks
Source https://valgrind.org
code
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr = (int*)malloc(sizeof(int) * 10);
  return 0;
}
```

```bash
valgrind ./prog leak-check=full
```

```c
~/Downloads/cprog/gdb_udemy main wip !3 ?9 ❯ valgrind ./prog leak-check=full                                                                              system

==45101== Memcheck, a memory error detector
==45101== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==45101== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==45101== Command: ./prog leak-check=full
==45101== 
==45101== 
==45101== HEAP SUMMARY:
==45101==     in use at exit: 40 bytes in 1 blocks
==45101==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==45101== 
==45101== LEAK SUMMARY:
==45101==    definitely lost: 40 bytes in 1 blocks
==45101==    indirectly lost: 0 bytes in 0 blocks
==45101==      possibly lost: 0 bytes in 0 blocks
==45101==    still reachable: 0 bytes in 0 blocks
==45101==         suppressed: 0 bytes in 0 blocks
==45101== Rerun with --leak-check=full to see details of leaked memory
==45101== 
==45101== For lists of detected and suppressed errors, rerun with: -s
==45101== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
~/Downloads/cprog/gdb_udemy main wip !3 ?9 ❯                                                                                                              system
```


### cppcheck
# install
sudo apt install cppcheck

# basic check
cppcheck main.c
cppcheck --enable=all main.c 

# more verbose — show all issues
cppcheck --enable=all main.c

# specify C standard
cppcheck --std=c99 main.c
cppcheck --std=c11 main.c

# check entire project directory
cppcheck .

# suppress false positives
cppcheck --suppress=missingIncludeSystem main.c

# output to file
cppcheck --enable=all main.c 2> report.txt


### It catches things like:
- memory leaks
- null pointer dereference
- buffer overflows
- uninitialized variables
- dead code
- integer overflow
- resource leaks (fopen without fclose)

```c

#include <stdio.h>
#include <stdlib.h>

int main() {
  const int *ptr =
      (int *)malloc(sizeof(int) * 10); // int is 4 byte * 10 = 40 bytes
  printf("%d\n", *ptr);
  return 0;
}
```

Response:
```c
~/Downloads/cprog/gdb_udemy main wip !3 ?9 ❯ cppcheck --enable=all main.c                                                                                 system
Checking main.c ...
main.c:1:0: information: Include file: <stdio.h> not found. Please note: Cppcheck does not need standard library headers to get proper results. [missingIncludeSys
tem]
#include <stdio.h>
^
main.c:2:0: information: Include file: <stdlib.h> not found. Please note: Cppcheck does not need standard library headers to get proper results. [missingIncludeSy
stem]
#include <stdlib.h>
^
main.c:8:3: error: Memory leak: ptr [memleak]
  return 0;
  ^
main.c:7:19: error: Memory is allocated but not initialized: ptr [uninitdata]
  printf("%d\n", *ptr);
                  ^
nofile:0:0: information: Active checkers: 106/592 (use --checkers-report=<filename> to see details) [checkersReport]

~/Downloads/cprog/gdb_udemy main wip !3 ?9 ❯                                                                                                              system

```


### macro logs
```c
The symbol `logs' has no definition as a C/C++ preprocessor macro
at <user-defined>:-1
```


### gdb level of information
```makefile

CC=gcc
CCFLAGS= -ggdb3

default: prog

main.o : main.c
	$(CC) $(CCFLAGS) -c main.c

prog: main.o
	$(CC) $(CCFLAGS) main.o -o prog

run:
	gdb ./prog

clean:
	rm main.o
	rm prog

```

### -g levels
-g has levels that control how much debug info is embedded:
# no debug info at all
gcc main.c -o prog

# level 0 — same as no -g, no debug info
gcc -g0 main.c -o prog

# level 1 — minimal: function names, line numbers, no local variables
gcc -g1 main.c -o prog

# level 2 — default when you just write -g
# includes: local variables, full line numbers, function signatures
gcc -g2 main.c -o prog
gcc -g main.c -o prog    # same as -g2

# level 3 — maximum: everything in g2 + macro definitions
# useful if you want gdb to expand macros
gcc -g3 main.c -o prog

### For your Makefile just update CCFLAGS:
CCFLAGS= -g3    # maximum debug info

