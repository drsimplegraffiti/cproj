
/* Stack Overflow and Underflow */
/* Two things can go wrong with a stack: */
/*     Overflow - you push onto a stack that is already full. */
/*     Underflow - you pop from a stack that is already empty. */
/* Without a check, the program would read or write outside the array. This is
 * a serious bug that can crash your program. That is why push() and pop()
 * always check first. */
/* In this example, the stack only has room for 3 items: */
#include <stdio.h>
#define MAX 3 // Maximum number of items the stack can hold

int stack[MAX]; // Array that holds the stack items
int top = -1;   // Index of the top item; -1 means the stack is empty

/* Push `value` onto the stack. Print overflow if the stack is full. */
void push(int value) {
    if (top == MAX - 1) {   // Stack is full -> overflow
        printf("Overflow! Cannot push %d\n", value);
        return;
    }
    top++;           // Move top up one slot
    stack[top] = value; // Place the value at the top
    printf("Pushed %d\n", value);
}

/* Pop the top item from the stack. Print underflow if the stack is empty. */
int pop() {
    if (top == -1) {   // Stack is empty -> underflow
        printf("Underflow! The stack is empty\n");
        return -1;
    }
    int value = stack[top]; // Grab the top item
    top--;                  // Move top down one slot
    printf("Popped %d\n", value);
    return value;           // Return the popped item
}

int main() {
    push(1); // Stack: [1]
    push(2); // Stack: [1, 2]
    push(3); // Stack: [1, 2, 3] (full)
    push(4); // Overflow! The stack is full

    pop();   // Pop 3 -> Stack: [1, 2]
    pop();   // Pop 2 -> Stack: [1]
    pop();   // Pop 1 -> Stack: [] (empty)
    pop();   // Underflow! The stack is empty

    return 0;
}
