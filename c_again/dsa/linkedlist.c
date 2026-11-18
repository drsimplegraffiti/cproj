/* What is a Linked List? */
/* Think of a train. Each car is hooked to the next car. To add a new car, you
 * just hook it on. You do not need to move the other cars. */

/* A linked list works the same way. Its "cars" are connected with pointers. */

/* A linked list stores items in nodes. Each node holds two things: */
/*     data - the value */
/*     next - a pointer to the next node */

/* The first node is called the head. The last node points to NULL, which means
 * "this is the end of the list". */

/* Linked Lists vs. Arrays */
/* A linked list is similar to an array, but it stores its values in a
 * different way. */
/* Both store many values. But they are good at different things: */
/* 	Array 		Linked List */
/* Size 		Fixed when created 	Grows and shrinks while the program runs */
/* In memory 	Items side by side 	Items anywhere, connected by pointers */
/* Get item 5 	Fast: jump straight 	Slower: start at head, follow pointers */
/* Add at start 	Slower: move others 	Fast: change one pointer */

/* In C, a node is a structure with a value and a pointer: */
/* struct Node { */
/*     int data; */
/*     struct Node *next; */
/* }; */

/* Let's create three nodes and link them. Then we "walk" through the list and
 * print each value: */
#include <stdio.h>

struct Node {
    int data;      // The value stored in this node
    struct Node *next; // Pointer to the next node in the list
};

int main() {
    /* Create three nodes as local variables */
    struct Node a, b, c;
    a.data = 10;   // Node a holds value 10
    b.data = 20;   // Node b holds value 20
    c.data = 30;   // Node c holds value 30

    /* Link them together: a -> b -> c -> NULL */
    a.next = &b;   // a's next points to b
    b.next = &c;   // b's next points to c
    c.next = NULL; // c is the last node, so next is NULL (end of list)

    /* Walk through the list and print each value */
    struct Node *current = &a; // Start at the head (node a)
    while (current != NULL) {  // While we haven't reached the end
        printf("%d -> ", current->data); // Print this node's value
        current = current->next;         // Move to the next node
    }
    printf("NULL\n"); // Mark the end of the list

    return 0;
}
