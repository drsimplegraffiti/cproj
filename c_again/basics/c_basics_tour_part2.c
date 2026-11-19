/*
 * c_basics_tour_part2.c - More C topics (continues part 1)
 *
 * Topics 13-24: safe input, scope, enums, typedef, unions, bitwise
 * operators, math, characters, pointers with arrays, function pointers,
 * sorting, linked lists, files, macros, random numbers, command-line args.
 *
 * Compile:  gcc c_basics_tour_part2.c -o tour2 -lm
 *           (-lm links the math library; needed for sqrt, pow, ...)
 * Run:      ./tour2 hello world
 */

#include <ctype.h> // toupper, isdigit, ...
#include <math.h>  // sqrt, pow, ...
#include <stdio.h>
#include <stdlib.h> // malloc, free, atoi, rand, srand
#include <string.h>
#include <time.h> // time (used to seed random numbers)

/* ============================================================
 * TOPIC 13: Safe input with fgets
 * scanf("%s") stops at spaces. fgets reads a whole line.
 * ============================================================ */
void topic_13_fgets(void) {
    printf("--- Topic 13: Reading a whole line ---\n");

    char name[50];
    char age_text[20];

    printf("Full name: ");
    fgets(name, sizeof(name), stdin); // reads at most 49 characters + '\0'
    name[strcspn(name, "\n")] = '\0'; // remove the '\n' that fgets keeps

    printf("Age: ");
    fgets(age_text, sizeof(age_text), stdin);
    int age = atoi(age_text); // atoi converts text "25" to number 25

    printf("Hello %s, in 10 years you will be %d.\n", name, age + 10);
}

/* ============================================================
 * TOPIC 14: Scope and static variables
 * ============================================================ */
int global_count = 0; // global: visible to every function below

void count_calls(void) {
    static int calls = 0; // static: created once, KEEPS its value between calls
    int normal = 0;       // normal local: reset to 0 on every call

    calls++;
    normal++;
    global_count++;
    printf("calls (static) = %d, normal = %d, global = %d\n", calls, normal,
           global_count);
}

void topic_14_scope(void) {
    printf("\n--- Topic 14: Scope and static ---\n");

    count_calls();
    count_calls();
    count_calls();

    // A variable declared inside { } only exists inside those braces
    {
        int inner = 5;
        printf("inner = %d\n", inner);
    }
    // printf("%d", inner);   <- would NOT compile: inner is out of scope here
}

/* ============================================================
 * TOPIC 15: enum, typedef and union
 * ============================================================ */

// enum: a set of named integer constants (RED=0, GREEN=1, BLUE=2)
enum Color { RED, GREEN, BLUE };

// typedef: gives a type a shorter name, so you can write Point
// instead of "struct Point"
typedef struct {
    int x;
    int y;
} Point;

// union: all members share the SAME memory; only one is valid at a time
union Number {
    int i;
    float f;
};

void topic_15_enum_typedef(void) {
    printf("\n--- Topic 15: enum, typedef, union ---\n");

    enum Color c = GREEN;
    if (c == GREEN) {
        printf("Color is green (value %d)\n", c);
    }

    Point p = {3, 4};
    printf("Point = (%d, %d)\n", p.x, p.y);

    union Number n;
    n.i = 10;
    printf("as int: %d\n", n.i);
    n.f = 2.5f; // overwrites the same memory, so n.i is now garbage
    printf("as float: %.1f\n", n.f);
}

/* ============================================================
 * TOPIC 16: Bitwise operators
 * Work on the individual 0s and 1s of a number.
 * ============================================================ */
void topic_16_bitwise(void) {
    printf("\n--- Topic 16: Bitwise operators ---\n");

    unsigned int a = 6; // binary 0110
    unsigned int b = 3; // binary 0011

    printf("a & b  = %u\n",
           a & b); // AND: 1 only if both bits are 1 -> 0010 = 2
    printf("a | b  = %u\n",
           a | b); // OR : 1 if either bit is 1      -> 0111 = 7
    printf("a ^ b  = %u\n",
           a ^ b); // XOR: 1 if the bits differ      -> 0101 = 5
    printf("a << 1 = %u\n",
           a << 1); // shift left = multiply by 2     -> 1100 = 12
    printf("a >> 1 = %u\n",
           a >> 1); // shift right = divide by 2      -> 0011 = 3

    // Common use: check if a certain bit is set
    int flags = 5; // binary 101
    printf("bit 0 set? %s\n", (flags & 1) ? "yes" : "no");
    printf("bit 1 set? %s\n", (flags & 2) ? "yes" : "no");
}

/* ============================================================
 * TOPIC 17: Math library
 * ============================================================ */
void topic_17_math(void) {
    printf("\n--- Topic 17: Math ---\n");

    printf("sqrt(16)     = %.1f\n", sqrt(16.0));
    printf("pow(2, 10)   = %.0f\n", pow(2.0, 10.0)); // 2 to the power of 10
    printf("fabs(-7.5)   = %.1f\n", fabs(-7.5)); // absolute value of a double
    printf("ceil(2.1)    = %.0f\n", ceil(2.1));  // round up
    printf("floor(2.9)   = %.0f\n", floor(2.9)); // round down
    printf("round(2.5)   = %.0f\n", round(2.5)); // round to nearest
}

/* ============================================================
 * TOPIC 18: Characters (ctype.h)
 * ============================================================ */
void topic_18_chars(void) {
    printf("\n--- Topic 18: Characters ---\n");

    char text[] = "Hello World 2026!";
    int letters = 0, digits = 0, spaces = 0;

    // Loop until we reach the end marker '\0'
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i]))
            letters++;
        else if (isdigit(text[i]))
            digits++;
        else if (isspace(text[i]))
            spaces++;
    }
    printf("letters=%d digits=%d spaces=%d\n", letters, digits, spaces);

    // Convert to uppercase one character at a time
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = (char)toupper(text[i]);
    }
    printf("uppercase: %s\n", text);

    // A char is really a small number (its ASCII code)
    printf("'A' = %d, 'a' = %d\n", 'A', 'a');
    printf("'A' + 2 = %c\n", 'A' + 2); // prints C
}

/* ============================================================
 * TOPIC 19: Arrays and pointers together
 * ============================================================ */

// An array passed to a function becomes a POINTER to its first element.
// That's why we must also pass the size: the function can't know it.
void print_array(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Doubles every element IN PLACE (changes the caller's array)
void double_all(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// Counting characters by walking a pointer through a string
int my_strlen(const char *s) {
    const char *start = s;
    while (*s != '\0') {
        s++; // move the pointer to the next character
    }
    return (int)(s - start); // pointer subtraction = number of elements between
}

void topic_19_arrays_pointers(void) {
    printf("\n--- Topic 19: Arrays and pointers ---\n");

    int nums[5] = {1, 2, 3, 4, 5};
    int len_arr = sizeof(nums) / sizeof(int);

    print_array(nums, 5); // you can replace 5 eith len_arr
    double_all(nums, 5);
    print_array(nums, 5); // the original array was changed

    // nums[i] is exactly the same as *(nums + i)
    printf("nums[2] = %d, *(nums + 2) = %d\n", nums[2], *(nums + 2));

    printf("my_strlen(\"pointer\") = %d\n", my_strlen("pointer"));
}

/* ============================================================
 * TOPIC 20: Function pointers
 * A variable that stores WHICH function to call.
 * ============================================================ */
int plus(int a, int b) { return a + b; }
int times(int a, int b) { return a * b; }

// 'operation' is a pointer to any function taking two ints and returning an int
int apply(int (*operation)(int, int), int x, int y) { return operation(x, y); }

void topic_20_function_pointers(void) {
    printf("\n--- Topic 20: Function pointers ---\n");

    printf("apply(plus, 3, 4)  = %d\n", apply(plus, 3, 4));
    printf("apply(times, 3, 4) = %d\n", apply(times, 3, 4));

    int (*chosen)(int, int) = times; // store a function in a variable
    printf("chosen(5, 6) = %d\n", chosen(5, 6));
}

/* ============================================================
 * TOPIC 21: Sorting (bubble sort)
 * ============================================================ */
void bubble_sort(int arr[], int size) {
    // Each pass "bubbles" the largest remaining value to the end
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - 1 - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i]; // swap neighbours that are out of order
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

void topic_21_sorting(void) {
    printf("\n--- Topic 21: Sorting ---\n");

    int data[6] = {42, 7, 19, 3, 88, 25};
    printf("before: ");
    print_array(data, 6);

    bubble_sort(data, 6);
    printf("after:  ");
    print_array(data, 6);
}

/* ============================================================
 * TOPIC 22: Linked list
 * Nodes linked by pointers; the list can grow while running.
 * ============================================================ */
struct Node {
    int value;
    struct Node *next; // address of the next node (NULL = end of list)
};

// Create a node, put it in front of the list, return the new front.
struct Node *add_front(struct Node *head, int value) {
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL)
        return head;     // out of memory: leave list unchanged
    node->value = value; // '->' accesses a member through a pointer
    node->next = head;
    return node;
}

void print_list(const struct Node *head) {
    for (const struct Node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d -> ", cur->value);
    }
    printf("NULL\n");
}

void free_list(struct Node *head) {
    while (head != NULL) {
        struct Node *next = head->next; // save it BEFORE freeing the node
        free(head);
        head = next;
    }
}

void topic_22_linked_list(void) {
    printf("\n--- Topic 22: Linked list ---\n");

    struct Node *list = NULL; // empty list
    list = add_front(list, 3);
    list = add_front(list, 2);
    list = add_front(list, 1);

    print_list(list); // 1 -> 2 -> 3 -> NULL
    free_list(list);
}

/* ============================================================
 * TOPIC 23: Files
 * ============================================================ */
void topic_23_files(void) {
    printf("\n--- Topic 23: Files ---\n");

    // "w" = write (creates/overwrites the file)
    FILE *file = fopen("demo.txt", "w");
    if (file == NULL) { // ALWAYS check that opening worked
        printf("Could not open file for writing\n");
        return;
    }
    fprintf(file, "Line one\n"); // like printf, but writes to the file
    fprintf(file, "Line two: %d\n", 42);
    fclose(file); // ALWAYS close when done

    // "r" = read
    file = fopen("demo.txt", "r");
    if (file == NULL) {
        printf("Could not open file for reading\n");
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file) !=
           NULL) { // returns NULL at end of file
        printf("read: %s", line);
    }
    fclose(file);

    remove("demo.txt"); // delete the demo file again
}

/* ============================================================
 * TOPIC 24: Macros, random numbers and command-line arguments
 * ============================================================ */

// A macro is text replaced before compiling. Extra brackets protect
// against surprises like SQUARE(1 + 2).
#define SQUARE(x) ((x) * (x))
#define PI 3.14159

void topic_24_misc(int argc, char *argv[]) {
    printf("\n--- Topic 24: Macros, random, arguments ---\n");

    printf("SQUARE(1 + 2) = %d\n", SQUARE(1 + 2));
    printf("circle area (r=2) = %.2f\n", PI * SQUARE(2.0));

    srand((unsigned int)time(
        NULL)); // seed: otherwise you get the same numbers every run
    printf("dice rolls: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", rand() % 6 + 1); // rand() % 6 gives 0-5, so +1 gives 1-6
    }
    printf("\n");

    // argc = number of arguments, argv = the arguments as strings.
    // argv[0] is the program's own name.
    printf("argc = %d\n", argc);
    for (int i = 1; i < argc; i++) {
        printf("argument %d: %s\n", i, argv[i]);
    }
}

/* ============================================================
 * main
 * ============================================================ */
int main(int argc, char *argv[]) {
    topic_13_fgets();
    topic_14_scope();
    topic_15_enum_typedef();
    topic_16_bitwise();
    topic_17_math();
    topic_18_chars();
    topic_19_arrays_pointers();
    topic_20_function_pointers();
    topic_21_sorting();
    topic_22_linked_list();
    topic_23_files();
    topic_24_misc(argc, argv);

    return 0;
}
