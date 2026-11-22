Contents | Next
Beej's Guide to C Programming

Brian “Beej Jorgensen” Hall

v0.11.4, Copyright © November 12, 2026

# Local Layout

- `index.html` — full Beej's Guide to C Programming (downloaded from https://beej.us/guide/bgc/html/)
- `README.md` — this index/contents file
- `code/` — one `.c` file per code sample, named after its section (e.g. `2-2-hello-world.c`, `5-3-dereferencing.c`, `6-1-easy-example.c`)

Build & run a sample:

    gcc -Wall -Wextra -std=c17 -o /tmp/hello code/2-2-hello-world.c
    /tmp/hello

    1 Foreword
        1.1 Audience
        1.2 How to Read This Book
        1.3 Platform and Compiler
        1.4 Official Homepage
        1.5 Email Policy
        1.6 Mirroring
        1.7 Note for Translators
        1.8 Copyright and Distribution
        1.9 Dedication
    2 Hello, World!
        2.1 What to Expect from C
        2.2 Hello, World!
        2.3 Compilation Details
        2.4 Building with gcc
        2.5 Building with clang
        2.6 Building from IDEs
        2.7 C Versions
    3 Variables and Statements
        3.1 Variables
            3.1.1 Variable Names
            3.1.2 Variable Types
            3.1.3 Boolean Types
        3.2 Operators and Expressions
            3.2.1 Arithmetic
            3.2.2 Ternary Operator
            3.2.3 Pre-and-Post Increment-and-Decrement
            3.2.4 The Comma Operator
            3.2.5 Conditional Operators
            3.2.6 Boolean Operators
            3.2.7 The sizeof Operator
        3.3 Flow Control
            3.3.1 The if-else statement
            3.3.2 The while statement
            3.3.3 The do-while statement
            3.3.4 The for statement
            3.3.5 The switch Statement
    4 Functions
        4.1 Passing by Value
        4.2 Function Prototypes
        4.3 Empty Parameter Lists
    5 Pointers—Cower In Fear!
        5.1 Memory and Variables
        5.2 Pointer Types
        5.3 Dereferencing
        5.4 Passing Pointers as Arguments
        5.5 The NULL Pointer
        5.6 A Note on Declaring Pointers
        5.7 sizeof and Pointers
    6 Arrays
        6.1 Easy Example
        6.2 Getting the Length of an Array
        6.3 Array Initializers
        6.4 Out of Bounds!
        6.5 Multidimensional Arrays
        6.6 Arrays and Pointers
            6.6.1 Getting a Pointer to an Array
            6.6.2 Passing Single Dimensional Arrays to Functions
            6.6.3 Changing Arrays in Functions
            6.6.4 Passing Multidimensional Arrays to Functions
    7 Strings
        7.1 String Literals
        7.2 String Variables
        7.3 String Variables as Arrays
        7.4 String Initializers
        7.5 Getting String Length
        7.6 String Termination
        7.7 Copying a String
    8 Structs
        8.1 Declaring a Struct
        8.2 Struct Initializers
        8.3 Passing Structs to Functions
        8.4 The Arrow Operator
        8.5 Copying and Returning structs
        8.6 Comparing structs
    9 File Input/Output
        9.1 The FILE* Data Type
        9.2 Reading Text Files
        9.3 End of File: EOF
            9.3.1 Reading a Line at a Time
        9.4 Formatted Input
        9.5 Writing Text Files
        9.6 Binary File I/O
            9.6.1 struct and Number Caveats
    10 typedef: Making New Types
        10.1 typedef in Theory
            10.1.1 Scoping
        10.2 typedef in Practice
            10.2.1 typedef and structs
            10.2.2 typedef and Other Types
            10.2.3 typedef and Pointers
            10.2.4 typedef and Capitalization
        10.3 Arrays and typedef
    11 Pointers II: Arithmetic
        11.1 Pointer Arithmetic
            11.1.1 Adding to Pointers
            11.1.2 Changing Pointers
            11.1.3 Subtracting Pointers
        11.2 Array/Pointer Equivalence
            11.2.1 Array/Pointer Equivalence in Function Calls
        11.3 void Pointers
    12 Manual Memory Allocation
        12.1 Allocating and Deallocating, malloc() and free()
        12.2 Error Checking
        12.3 Allocating Space for an Array
        12.4 An Alternative: calloc()
        12.5 Changing Allocated Size with realloc()
            12.5.1 Reading in Lines of Arbitrary Length
            12.5.2 realloc() with NULL
        12.6 Aligned Allocations
    13 Scope
        13.1 Block Scope
            13.1.1 Where To Define Variables
            13.1.2 Variable Hiding
        13.2 File Scope
        13.3 for-loop Scope
        13.4 A Note on Function Scope
    14 Types II: Way More Types!
        14.1 Signed and Unsigned Integers
        14.2 Character Types
        14.3 More Integer Types: short, long, long long
        14.4 More Float: double and long double
            14.4.1 How Many Decimal Digits?
            14.4.2 Converting to Decimal and Back
        14.5 Constant Numeric Types
            14.5.1 Hexadecimal and Octal
            14.5.2 Integer Constants
            14.5.3 Floating Point Constants
    15 Types III: Conversions
        15.1 String Conversions
            15.1.1 Numeric Value to String
            15.1.2 String to Numeric Value
        15.2 char Conversions
        15.3 Numeric Conversions
            15.3.1 Boolean
            15.3.2 Integer to Integer Conversions
            15.3.3 Integer and Floating Point Conversions
        15.4 Implicit Conversions
            15.4.1 The Integer Promotions
            15.4.2 The Usual Arithmetic Conversions
            15.4.3 void*
        15.5 Explicit Conversions
            15.5.1 Casting
    16 Types IV: Qualifiers and Specifiers
        16.1 Type Qualifiers
            16.1.1 const
            16.1.2 restrict
            16.1.3 volatile
            16.1.4 _Atomic
        16.2 Storage-Class Specifiers
            16.2.1 auto
            16.2.2 static
            16.2.3 extern
            16.2.4 register
            16.2.5 _Thread_local
    17 Multifile Projects
        17.1 Includes and Function Prototypes
        17.2 Dealing with Repeated Includes
        17.3 static and extern
        17.4 Compiling with Object Files
    18 The Outside Environment
        18.1 Command Line Arguments
            18.1.1 The Last argv is NULL
            18.1.2 The Alternate: char **argv
            18.1.3 Fun Facts
        18.2 Exit Status
            18.2.1 Other Exit Status Values
        18.3 Environment Variables
            18.3.1 Setting Environment Variables
            18.3.2 Unix-like Alternative Environment Variables
    19 The C Preprocessor
        19.1 #include
        19.2 Simple Macros
        19.3 Conditional Compilation
            19.3.1 If Defined, #ifdef and #endif
            19.3.2 If Not Defined, #ifndef
            19.3.3 #else
            19.3.4 Else-If: #elifdef, #elifndef
            19.3.5 General Conditional: #if, #elif
            19.3.6 Losing a Macro: #undef
        19.4 Built-in Macros
            19.4.1 Mandatory Macros
            19.4.2 Optional Macros
        19.5 Macros with Arguments
            19.5.1 Macros with One Argument
            19.5.2 Macros with More than One Argument
            19.5.3 Macros with Variable Arguments
            19.5.4 Stringification
            19.5.5 Concatenation
        19.6 Multiline Macros
        19.7 Example: An Assert Macro
        19.8 The #error Directive
        19.9 The #embed Directive
            19.9.1 #embed Parameters
            19.9.2 The limit() Parameter
            19.9.3 The if_empty Parameter
            19.9.4 The prefix() and suffix() Parameters
            19.9.5 The __has_embed() Identifier
            19.9.6 Other Parameters
            19.9.7 Embedding Multi-Byte Values
        19.10 The #pragma Directive
            19.10.1 Non-Standard Pragmas
            19.10.2 Standard Pragmas
            19.10.3 _Pragma Operator
        19.11 The #line Directive
        19.12 The Null Directive
    20 structs II: More Fun with structs
        20.1 Initializers of Nested structs and Arrays
        20.2 Anonymous structs
        20.3 Self-Referential structs
        20.4 Flexible Array Members
        20.5 Padding Bytes
        20.6 offsetof
        20.7 Fake OOP
        20.8 Bit-Fields
            20.8.1 Non-Adjacent Bit-Fields
            20.8.2 Signed or Unsigned ints
            20.8.3 Unnamed Bit-Fields
            20.8.4 Zero-Width Unnamed Bit-Fields
        20.9 Unions
            20.9.1 Unions and Type Punning
            20.9.2 Pointers to unions
            20.9.3 Common Initial Sequences in Unions
        20.10 Unions and Unnamed Structs
        20.11 Passing and Returning structs and unions
    21 Characters and Strings II
        21.1 Escape Sequences
            21.1.1 Frequently-used Escapes
            21.1.2 Rarely-used Escapes
            21.1.3 Numeric Escapes
    22 Enumerated Types: enum
        22.1 Behavior of enum
            22.1.1 Numbering
            22.1.2 Trailing Commas
            22.1.3 Scope
            22.1.4 Style
        22.2 Your enum is a Type
    23 Pointers III: Pointers to Pointers and More
        23.1 Pointers to Pointers
            23.1.1 Pointer Pointers and const
        23.2 Multibyte Values
        23.3 The NULL Pointer and Zero
        23.4 Pointers as Integers
        23.5 Casting Pointers to other Pointers
        23.6 Pointer Differences
        23.7 Pointers to Functions
    24 Bitwise Operations
        24.1 Bitwise AND, OR, XOR, and NOT
        24.2 Bitwise Shift
    25 Variadic Functions
        25.1 Ellipses in Function Signatures
        25.2 Getting the Extra Arguments
        25.3 va_list Functionality
        25.4 Library Functions That Use va_lists
        25.5 Variadic Macro Gotchas
    26 Locale and Internationalization
        26.1 Setting the Localization, Quick and Dirty
        26.2 Getting the Monetary Locale Settings
            26.2.1 Monetary Digit Grouping
            26.2.2 Separators and Sign Position
            26.2.3 Example Values
        26.3 Localization Specifics
    27 Unicode, Wide Characters, and All That
        27.1 What is Unicode?
        27.2 Code Points
        27.3 Encoding
        27.4 Source and Execution Character Sets
        27.5 Unicode in C
        27.6 A Quick Note on UTF-8 Before We Swerve into the Weeds
        27.7 Different Character Types
            27.7.1 Multibyte Characters
            27.7.2 Wide Characters
        27.8 Using Wide Characters and wchar_t
            27.8.1 Multibyte to wchar_t Conversions
        27.9 Wide Character Functionality
            27.9.1 wint_t
            27.9.2 I/O Stream Orientation
            27.9.3 I/O Functions
            27.9.4 Type Conversion Functions
            27.9.5 String and Memory Copying Functions
            27.9.6 String and Memory Comparing Functions
            27.9.7 String Searching Functions
            27.9.8 Length/Miscellaneous Functions
            27.9.9 Character Classification Functions
        27.10 Parse State, Restartable Functions
        27.11 Unicode Encodings and C
            27.11.1 UTF-8
            27.11.2 UTF-16, UTF-32, char16_t, and char32_t
            27.11.3 Multibyte Conversions
            27.11.4 Third-Party Libraries
    28 Exiting a Program
        28.1 Normal Exits
            28.1.1 Returning From main()
            28.1.2 exit()
            28.1.3 Setting Up Exit Handlers with atexit()
        28.2 Quicker Exits with quick_exit()
        28.3 Nuke it from Orbit: _Exit()
        28.4 Exiting Sometimes: assert()
        28.5 Abnormal Exit: abort()
    29 Signal Handling
        29.1 What Are Signals?
        29.2 Handling Signals with signal()
        29.3 Writing Signal Handlers
        29.4 What Can We Actually Do?
        29.5 Friends Don’t Let Friends signal()
    30 Variable-Length Arrays (VLAs)
        30.1 The Basics
        30.2 sizeof and VLAs
        30.3 Multidimensional VLAs
        30.4 Passing One-Dimensional VLAs to Functions
        30.5 Passing Multi-Dimensional VLAs to Functions
            30.5.1 Partial Multidimensional VLAs
        30.6 Compatibility with Regular Arrays
        30.7 typedef and VLAs
        30.8 Jumping Pitfalls
        30.9 General Issues
    31 goto
        31.1 A Simple Example
        31.2 Labeled continue
        31.3 Bailing Out
        31.4 Labeled break
        31.5 Multi-level Cleanup
        31.6 Tail Call Optimization
        31.7 Restarting Interrupted System Calls
        31.8 goto and Thread Preemption
        31.9 goto and Variable Scope
        31.10 goto and Variable-Length Arrays
    32 Types Part V: Compound Literals and Generic Selections
        32.1 Compound Literals
            32.1.1 Passing Unnamed Objects to Functions
            32.1.2 Unnamed structs
            32.1.3 Pointers to Unnamed Objects
            32.1.4 Unnamed Objects and Scope
            32.1.5 Silly Unnamed Object Example
        32.2 Generic Selections
    33 Arrays Part II
        33.1 Type Qualifiers for Arrays in Parameter Lists
        33.2 static for Arrays in Parameter Lists
        33.3 Equivalent Initializers
    34 Long Jumps with setjmp, longjmp
        34.1 Using setjmp and longjmp
        34.2 Pitfalls
            34.2.1 The Values of Local Variables
            34.2.2 How Much State is Saved?
            34.2.3 You Can’t Name Anything setjmp
            34.2.4 You Can’t setjmp() in a Larger Expression
            34.2.5 When Can’t You longjmp()?
            34.2.6 You Can’t Pass 0 to longjmp()
            34.2.7 longjmp() and Variable Length Arrays
    35 Incomplete Types
        35.1 Use Case: Self-Referential Structures
        35.2 Incomplete Type Error Messages
        35.3 Other Incomplete Types
        35.4 Use Case: Arrays in Header Files
        35.5 Completing Incomplete Types
    36 Complex Numbers
        36.1 Complex Types
        36.2 Assigning Complex Numbers
        36.3 Constructing, Deconstructing, and Printing
        36.4 Complex Arithmetic and Comparisons
        36.5 Complex Math
            36.5.1 Trigonometry Functions
            36.5.2 Exponential and Logarithmic Functions
            36.5.3 Power and Absolute Value Functions
            36.5.4 Manipulation Functions
    37 Fixed Width Integer Types
        37.1 The Bit-Sized Types
        37.2 Maximum Integer Size Type
        37.3 Using Fixed Size Constants
        37.4 Limits of Fixed Size Integers
        37.5 Format Specifiers
    38 Date and Time Functionality
        38.1 Quick Terminology and Information
        38.2 Date Types
        38.3 Initialization and Conversion Between Types
            38.3.1 Converting time_t to struct tm
            38.3.2 Converting struct tm to time_t
        38.4 Formatted Date Output
        38.5 More Resolution with timespec_get()
        38.6 Differences Between Times
    39 Multithreading
        39.1 Background
        39.2 Things You Can Do
        39.3 Data Races and the Standard Library
        39.4 Creating and Waiting for Threads
        39.5 Detaching Threads
        39.6 Thread Local Data
            39.6.1 _Thread_local Storage-Class
            39.6.2 Another Option: Thread-Specific Storage
        39.7 Mutexes
            39.7.1 Different Mutex Types
        39.8 Condition Variables
            39.8.1 Timed Condition Wait
            39.8.2 Broadcast: Wake Up All Waiting Threads
        39.9 Running a Function One Time
    40 Atomics
        40.1 Testing for Atomic Support
        40.2 Atomic Variables
        40.3 Synchronization
        40.4 Acquire and Release
        40.5 Sequential Consistency
        40.6 Atomic Assignments and Operators
        40.7 Library Functions that Automatically Synchronize
        40.8 Atomic Type Specifier, Qualifier
        40.9 Lock-Free Atomic Variables
            40.9.1 Signal Handlers and Lock-Free Atomics
        40.10 Atomic Flags
        40.11 Atomic structs and unions
        40.12 Atomic Pointers
        40.13 Memory Order
            40.13.1 Sequential Consistency
            40.13.2 Acquire
            40.13.3 Release
            40.13.4 Consume
            40.13.5 Acquire/Release
            40.13.6 Relaxed
        40.14 Fences
        40.15 References
    41 Function Specifiers, Alignment Specifiers/Operators
        41.1 Function Specifiers
            41.1.1 inline for Speed—Maybe
            41.1.2 noreturn and _Noreturn
        41.2 Alignment Specifiers and Operators
            41.2.1 alignas and _Alignas
            41.2.2 alignof and _Alignof
        41.3 memalignment() Function

Contents | Next