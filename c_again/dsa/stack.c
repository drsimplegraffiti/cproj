/* A stack is a data structure where you add and remove items at the same end:
 * the top. */
/* The last item you add is the first item you remove. This rule is called LIFO
 * (Last In, First Out). */
/* Think of a stack of plates: you add a plate on top and take the top plate
 * off first. */

/* Think of a stack of plates. You put a new plate on the top. When you need a
 * plate, you take the one on the top. */
/* The last plate you put on is the first plate you take off. That is exactly
 * how a stack works in programming. */
/* A stack is a data structure where you add and remove items at the same end:
 * the top. */
/* The last item you add is the first item you remove. This rule is called LIFO
 * (Last In, First Out). */

/* You use stacks every day, maybe without knowing it: */

/*     The Undo button in a text editor removes your last change first. */
/*     The Back button in a web browser goes to the page you visited last. */
/*     C itself uses a stack to remember which function to return to when a
 * function call ends. */

/* Create a Stack With an Array */
#include <stdio.h>

int main() {
    int stack[5]; // Array that holds the stack items (max 5)
    int top = -1; // Index of the top item; -1 means the stack is empty

    /* Push 10, 20 and 30 (add each on top) */
    top++; // Move top up one slot
    printf("top is now index: %d\n", top);
    stack[top] = 10; // Place 10 at the top
    top++;
    printf("top is now index: %d\n", top);
    stack[top] = 20; // Place 20 at the top
    top++;
    printf("top is now index: %d\n", top);
    stack[top] = 30; // Place 30 at the top

    printf("Top item: %d\n", stack[top]); // Look at the top without removing

    /* Pop the top item (remove it) */
    printf("Popped: %d\n", stack[top]); // Show what is being removed
    top--;                              // Move top down one slot

    printf("Top item now: %d\n", stack[top]); // New top after pop

    return 0;
}

/* Stack Operations */

/* A stack has a few basic operations: */
/* Operation 	What It Does */
/* push 	Adds an item to the top */
/* pop 	Removes the item from the top */
/* peek 	Looks at the top item, without removing it */
/* isEmpty 	Checks if the stack has no items */
