# 4. Structs, Memory Alignment, Computer Architecture Basics & Enums

## 4.1 Structs — Basics
A `struct` groups multiple variables (of possibly different types) under one name.

```c
struct Student {
    char name[30];
    int age;
    float gpa;
};

struct Student s1 = {"Alice", 20, 3.8};
printf("%s is %d\n", s1.name, s1.age);

typedef struct Student Student;   // lets you write "Student" instead of "struct Student"
Student s2 = {"Bob", 22, 3.5};
```

## 4.2 Structs and Pointers
```c
Student *p = &s1;
p->age = 21;          // arrow operator: equivalent to (*p).age = 21
(*p).age = 21;         // same thing, arrow is just cleaner syntax
```

Passing structs to functions:
```c
void printStudent(Student s);       // pass by VALUE — copies the whole struct (slow for big structs)
void printStudent(Student *s);       // pass by POINTER — efficient, and allows modification
```

## 4.3 Nested Structs and Arrays of Structs
```c
struct Address { char city[20]; int zip; };
struct Employee {
    char name[30];
    struct Address addr;   // nested struct
};

struct Employee staff[100];   // array of structs
staff[0].addr.zip = 12345;
```

## 4.4 Structs, Arrays & Dynamic Memory Combined (Project Pattern)
A "School Management System" style project typically combines:
```c
typedef struct {
    char name[30];
    int id;
    float grades[5];
} Student;

Student *roster = malloc(numStudents * sizeof(Student));
// ... populate, process, search, sort ...
free(roster);
```
Typical operations built on top: add/remove records, search by ID/name, sort by
grade, save/load from a file (see Files notes), compute statistics (average, max).

## 4.5 Computer Architecture Basics (Relevant to C)
- **Memory is a sequence of addressable bytes.** Every variable lives at some address.
- **Word size / bus width** (32-bit vs 64-bit) affects pointer size (4 vs 8 bytes) and
  how much data the CPU moves per memory access.
- **Endianness:** the order bytes of a multi-byte value are stored.
  - *Little-endian* (most modern x86/ARM): least significant byte first.
  - *Big-endian*: most significant byte first.
- The **CPU reads memory in aligned chunks** (words) — this is why data alignment
  matters for performance (and on some architectures, correctness).

## 4.6 Struct Memory Alignment & Padding
The compiler may insert **padding bytes** between struct members so that each member
starts at an address that's a multiple of its own size (its "alignment requirement").
This lets the CPU fetch it in a single, efficient memory access.

```c
struct Example {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
};
// sizeof(struct Example) is often 12, not 6!
// Layout: a(1) + padding(3) + b(4) + c(1) + padding(3) = 12
```

Why: `b` (an `int`, needs 4-byte alignment) cannot start right after `a` at offset 1;
the compiler pads to offset 4. At the end, the whole struct is padded so that arrays
of this struct keep every element aligned too.

### Reducing Padding: Reorder Members
```c
struct Better {
    int b;      // 4 bytes
    char a;     // 1 byte
    char c;     // 1 byte
};              // total: 4 + 1 + 1 + 2 padding = 8 bytes
```
**Rule of thumb:** order struct members from largest to smallest type to minimize
padding.

### `sizeof` a struct is NOT the sum of its members' sizes
Always use `sizeof(struct X)`, never manually add up member sizes.

## 4.7 Enums
An `enum` defines a set of named integer constants, improving code readability.

```c
enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
// SUNDAY = 0, MONDAY = 1, ... by default, incrementing from 0

enum Status { OK = 200, NOT_FOUND = 404, SERVER_ERROR = 500 }; // custom values

enum Day today = MONDAY;
if (today == MONDAY) printf("Start of the work week\n");
```
- Enums are just `int`s under the hood — no runtime type safety, but big readability
  win over "magic numbers."
- Common uses: state machines, error/status codes, menu options.

## 4.8 Bit Fields (Preview — see Bitwise notes for full detail)
Structs can also specify member widths in bits, useful for tightly packing flags:
```c
struct Flags {
    unsigned int isActive : 1;
    unsigned int isAdmin  : 1;
    unsigned int level    : 4;
};
```
This packs all three fields into a fraction of a normal int's storage — see the
Bitwise & Bit Fields note for details, layout rules, and portability caveats.
