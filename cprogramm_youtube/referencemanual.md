### Where to read C documentation
- Books
    - the C bible, KNK
    - C programming A modern approach: K. N. King
    - ISO/IEC 9899, https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2310.pdf

- terminals:
    - man pages: if man page not available sudo apt install manpages-Wdev
    - info

- online:
    - geeksforgeeks
    - tutorial points
    - cppreference: https://cppreference.com/
        - Then use the search button. e.g cppreference printf
- project based:
    https://github.com/codecrafters-io/build-your-own-x
    https://viewsourcecode.org/snaptoken/kilo/
    https://www.reddit.com/r/C_Programming/comments/872rlt/c_project_based_tutorials/
    https://buildyourownlisp.com/

Videoes:
    - CS50
    - FreeCode



Man pages is for:
- systems call
- standard library functions
so `man 3 main` will not work

```bash
    man 3 printf # 3 is for library functions e,g printf, malloc : where to look: man 3
# also use man-like info for keywords
    man gcc # or info gcc
```

### If you want to know the section either 1, 2 or 3 use:
```bash
man -k printf
```


| Section | Meaning                                      |
| ------- | -------------------------------------------- |
| 1       | User commands (e.g. `ls`, `grep`)            |
| 2       | **System calls** (kernel-level)              |
| 3       | **C library functions** (`printf`, `malloc`) |
| 4       | Devices                                      |
| 5       | File formats (`/etc/passwd`)                 |
| 7       | Misc (concepts, protocols)                   |
| 8       | Admin commands                               |

System calls (syscalls)

These are:
functions provided directly by the OS kernel
low-level operations
e.g man 2 open

Low-level:
```bash
int fd = open("file.txt", O_RDONLY);
```

High-level:
```bash
# i.e man 3 fopen
# higher-level C function
# easier to use
FILE *f = fopen("file.txt", "r");
```
### Mental model
man 2 → kernel: system calls (low-level OS functions) 
man 3 → C standard library


