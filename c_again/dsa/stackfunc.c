#include <stdio.h>
#define MAX 5 // Maximum number of items the stack can hold

int stack[MAX]; // Array that holds the stack items
int top = -1;   // Index of the top item; -1 means the stack is empty

/* Add `value` on top of the stack. Do nothing if the stack is full. */
void push(int value) {
    if (top == MAX - 1) {   // Stack is full (overflow)
        printf("Stack is full!\n");
        return;
    }
    top++;         // Move top up one slot
    stack[top] = value; // Place the value at the top
}

/* Remove and return the top item. Return -1 if the stack is empty. */
int pop() {
    if (top == -1) {   // Stack is empty (underflow)
        printf("Stack is empty!\n");
        return -1;
    }
    int value = stack[top]; // Grab the top item
    top--;                  // Move top down one slot
    return value;           // Return the popped item
}

/* Return the top item without removing it. Return -1 if empty. */
int peek() {
    if (top == -1) {   // Stack is empty
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top]; // Return the top item
}

/* Returns 1 (true) if the stack is empty, 0 (false) otherwise. */
int isEmpty() { return top == -1; }

int main() {
    push(10); // Push 10 onto the stack
    push(20); // Push 20 onto the stack
    push(30); // Push 30 onto the stack

    printf("Top item: %d\n", peek()); // Look at the top (30)

    /* Pop items until the stack is empty */
    while (!isEmpty()) {
        printf("Popped: %d\n", pop()); // Remove and print the top item
    }

    return 0;
}
