/*
 * c_basics_tour.c - Learn C one topic at a time
 *
 * Each topic is its own function (topic_1_..., topic_2_...).
 * Read them in order. Run the program and compare the output
 * with the code.
 *
 * Compile:  gcc c_basics_tour.c -o tour
 * Run:      ./tour        (Windows: tour.exe)
 */

#include <stdio.h>  // printf, scanf
#include <string.h> // strlen, strcpy, strcmp, strcat

/* ============================================================
 * TOPIC 1: Output with printf
 * ============================================================ */
void topic_1_output(void) {
    printf("--- Topic 1: Output ---\n");

    printf("Hello, World!\n");  // \n = new line
    printf("Tab:\tindented\n"); // \t = tab
    printf("Quote: \"hi\"\n");  // \" prints a double quote
}

/* ============================================================
 * TOPIC 2: Variables and data types
 * ============================================================ */
void topic_2_variables(void) {
    printf("\n--- Topic 2: Variables and data types ---\n");

    int age = 25;           // whole number
    float height = 1.75f;   // decimal number (less precise)
    double pi = 3.14159265; // decimal number (more precise)
    char grade = 'A';       // ONE character, in single quotes

    // Format specifiers tell printf how to show each value:
    // %d int   %f float/double   %c char   %s string
    printf("age = %d\n", age);
    printf("height = %.2f\n", height); // %.2f = 2 decimal places
    printf("pi = %.4f\n", pi);
    printf("grade = %c\n", grade);

    // sizeof tells you how many bytes a type uses
    printf("int uses %zu bytes, double uses %zu bytes\n", sizeof(int),
           sizeof(double));

    // 'const' = value can never change
    const int DAYS_IN_WEEK = 7;
    printf("days in a week = %d\n", DAYS_IN_WEEK);
}

/* ============================================================
 * TOPIC 3: Operators
 * ============================================================ */
void topic_3_operators(void) {
    printf("\n--- Topic 3: Operators ---\n");

    int a = 17, b = 5;

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n",
           a / b); // integer division: 17/5 = 3 (decimals dropped!)
    printf("a %% b = %d\n",
           a % b); // modulo = remainder (17 % 5 = 2). Use %% to print a %

    // To get a decimal result, convert one side to double first
    printf("a / b (real) = %.2f\n", (double)a / b);

    // Shortcuts
    int x = 10;
    x += 5; // same as x = x + 5
    x++;    // same as x = x + 1
    printf("x = %d\n", x);

    // Comparison operators give 1 (true) or 0 (false)
    printf("a > b is %d\n", a > b);
    printf("a == b is %d\n", a == b); // == compares, = assigns!

    // Logical operators: && (and), || (or), ! (not)
    printf("a > 10 && b > 10 is %d\n", a > 10 && b > 10);
    printf("a > 10 || b > 10 is %d\n", a > 10 || b > 10);
}

/* ============================================================
 * TOPIC 4: Input with scanf
 * ============================================================ */
void topic_4_input(void) {
    printf("\n--- Topic 4: Input ---\n");

    int age;
    char name[30]; // room for 29 characters + the end marker

    printf("Enter your name: ");
    scanf("%29s", name); // no & for arrays; %29s limits the length
    printf("Enter your age: ");
    scanf("%d",
          &age); // & = "address of age", so scanf can store the value there

    printf("Nice to meet you, %s! Next year you will be %d.\n", name, age + 1);
}

/* ============================================================
 * TOPIC 5: Conditions (if / else / switch)
 * ============================================================ */
void topic_5_conditions(void) {
    printf("\n--- Topic 5: Conditions ---\n");

    int score = 85;

    if (score >= 90) {
        printf("Grade A\n");
    } else if (score >= 80) {
        printf("Grade B\n");
    } else {
        printf("Grade C or lower\n");
    }

    // switch compares one value against several fixed cases
    int day = 3;
    switch (day) {
        case 1:
            printf("Monday\n");
            break; // break stops it from running into the next case
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        default:
            printf("Another day\n"); // runs if nothing matched
    }

    // Ternary operator: condition ? value_if_true : value_if_false
    printf("%d is %s\n", score, score >= 50 ? "a pass" : "a fail");
}

/* ============================================================
 * TOPIC 6: Loops
 * ============================================================ */
void topic_6_loops(void) {
    printf("\n--- Topic 6: Loops ---\n");

    // for: use when you know how many times to repeat
    // (start; keep going while true; step after each round)
    printf("for:   ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }

    // while: repeat while the condition is true (checked BEFORE each round)
    printf("\nwhile: ");
    int n = 5;
    while (n > 0) {
        printf("%d ", n);
        n--;
    }

    // do-while: always runs at least once (checked AFTER each round)
    printf("\ndo:    ");
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= 3);

    // break leaves the loop, continue skips to the next round
    printf("\nskip 3, stop at 6: ");
    for (int i = 1; i <= 10; i++) {
        if (i == 3)
            continue;
        if (i == 6)
            break;
        printf("%d ", i);
    }
    printf("\n");
}

/* ============================================================
 * TOPIC 7: Arrays
 * ============================================================ */
void topic_7_arrays(void) {
    printf("\n--- Topic 7: Arrays ---\n");

    int numbers[5] = {10, 20, 30, 40, 50}; // 5 ints stored side by side

    // Indexes start at 0, so the last one is size - 1
    printf("first = %d, last = %d\n", numbers[0], numbers[4]);

    numbers[1] = 99; // change one element

    // sizeof(array) / sizeof(one element) = number of elements
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int sum = 0;
    for (int i = 0; i < size; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
        sum += numbers[i];
    }
    printf("sum = %d\n", sum);

    // 2D array: a grid with rows and columns
    int grid[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("grid[1][2] = %d\n", grid[1][2]); // row 1, column 2 -> 6
}

/* ============================================================
 * TOPIC 8: Strings
 * ============================================================ */
void topic_8_strings(void) {
    printf("\n--- Topic 8: Strings ---\n");

    // A string is a char array that ends with '\0' (added for you)
    char word[20] = "Hello";

    printf("word = %s, length = %zu\n", word, strlen(word));

    strcat(word, " C"); // append text (the array must have enough room)
    printf("after strcat: %s\n", word);

    char copy[20];
    strcpy(copy, word); // you can't copy strings with '=' - use strcpy
    printf("copy = %s\n", copy);

    // You also can't compare strings with '==' - use strcmp.
    // strcmp returns 0 when both strings are equal.
    if (strcmp(word, copy) == 0) {
        printf("The strings are equal\n");
    }
}

/* ============================================================
 * TOPIC 9: Functions
 * ============================================================ */

// return type, name, (parameters)
int add(int a, int b) {
    return a + b; // send a value back to the caller
}

// 'void' = returns nothing
void greet(const char *name) { printf("Hello, %s!\n", name); }

// Recursion: a function that calls itself (needs a stopping case)
int factorial(int n) {
    if (n <= 1)
        return 1;                // stopping case
    return n * factorial(n - 1); // 5! = 5 * 4 * 3 * 2 * 1
}

void topic_9_functions(void) {
    printf("\n--- Topic 9: Functions ---\n");

    printf("add(3, 4) = %d\n", add(3, 4));
    greet("Anna");
    printf("factorial(5) = %d\n", factorial(5));
}

/* ============================================================
 * TOPIC 10: Pointers
 * ============================================================ */

// Parameters are COPIES, so changing them here would not change the
// caller's variables. Pointers fix that: we receive addresses instead.
void swap(int *a, int *b) {
    int temp = *a; // *a = "the value at the address a"
    *a = *b;
    *b = temp;
}

void topic_10_pointers(void) {
    printf("\n--- Topic 10: Pointers ---\n");

    int number = 42;
    int *ptr = &number; // ptr stores the ADDRESS of number (& = "address of")

    printf("number = %d\n", number);
    printf("address of number = %p\n", (void *)ptr);
    printf("value through pointer = %d\n", *ptr); // * = "go to that address"

    *ptr = 100; // changing the value through the pointer...
    printf("number is now %d\n", number); // ...changes the original

    int x = 1, y = 2;
    swap(&x, &y);
    printf("after swap: x = %d, y = %d\n", x, y);

    // Arrays and pointers are closely related:
    // the array name is the address of its first element
    int arr[3] = {10, 20, 30};
    int *p = arr;
    printf("*p = %d, *(p + 1) = %d\n", *p,
           *(p + 1)); // p + 1 moves to the next int
}

/* ============================================================
 * TOPIC 11: Structs
 * ============================================================ */

// A struct bundles different variables into one custom type
struct Person {
    char name[30];
    int age;
};

void topic_11_structs(void) {
    printf("\n--- Topic 11: Structs ---\n");

    struct Person p1 = {"Ben", 30};
    printf("%s is %d\n", p1.name, p1.age); // '.' accesses a member

    p1.age = 31;
    strcpy(p1.name, "Benjamin"); // strings need strcpy to change
    printf("%s is %d\n", p1.name, p1.age);

    // Pointer to a struct: use '->' instead of '.'
    struct Person *ptr = &p1;
    printf("via pointer: %s\n", ptr->name); // same as (*ptr).name
}

/* ============================================================
 * TOPIC 12: Memory allocation (malloc / free)
 * ============================================================ */
#include <stdlib.h> // malloc, free (includes can also sit here)

void topic_12_memory(void) {
    printf("\n--- Topic 12: Dynamic memory ---\n");

    int count = 4;

    // malloc asks the computer for memory while the program runs.
    // Here: room for 4 ints. It returns the address, or NULL if it fails.
    int *data = malloc(count * sizeof(int));
    if (data == NULL) {
        printf("Out of memory!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        data[i] = (i + 1) * 10; // use it just like an array
        printf("data[%d] = %d\n", i, data[i]);
    }

    free(data); // ALWAYS give memory back when you're done
}

/* ============================================================
 * main: runs every topic in order
 * ============================================================ */
int main(void) {
    topic_1_output();
    topic_2_variables();
    topic_3_operators();
    topic_4_input();
    topic_5_conditions();
    topic_6_loops();
    topic_7_arrays();
    topic_8_strings();
    topic_9_functions();
    topic_10_pointers();
    topic_11_structs();
    topic_12_memory();

    return 0; // 0 = program finished successfully
}
