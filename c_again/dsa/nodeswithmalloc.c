/* Create Nodes With malloc() */
/* In the previous chapter, the nodes were fixed variables in main(). */
/* Real linked lists grow and shrink while the program runs. In this chapter,
 * you create nodes with malloc(), insert them, delete them, and clean up
 * after yourself. */

/* To create a node while the program runs, use malloc(). Put it in a
 * function, so you can call it again and again: */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;           // The value stored in this node
    struct Node *next;  // Pointer to the next node in the list
};

/* Allocate a new node on the heap and store `value` in it.
 * Returns a pointer to the new node, whose next is NULL. */
struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node)); // Allocate memory
    if (newNode == NULL) {                              // Check allocation
        printf("Memory allocation failed\n");
        exit(1); // Exit if malloc failed
    }
    newNode->data = value; // Store the value
    newNode->next = NULL;  // No next node yet
    return newNode;        // Return the new node
}

/* Print every node in the list starting from `head`. */
void printList(struct Node *head) {
    struct Node *current = head; // Start at the head
    while (current != NULL) {    // Until the end of the list
        printf("%d -> ", current->data); // Print this node's value
        current = current->next;         // Move to the next node
    }
    printf("NULL\n"); // End of list marker
}

/* Free every node in the list to avoid memory leaks. */
void freeList(struct Node *head) {
    while (head != NULL) {          // While there are nodes left
        struct Node *next = head->next; // Remember the next node
        free(head);                 // Free the current node
        head = next;                // Move to the next node
    }
}

int main() {
    /* Build a list on the heap: 10 -> 20 -> 30 -> NULL */
    struct Node *head = createNode(10);      // First node
    head->next = createNode(20);             // Second node
    head->next->next = createNode(30);       // Third node

    printList(head);   // Print the list
    freeList(head);    // Free all allocated memory

    return 0;
}
