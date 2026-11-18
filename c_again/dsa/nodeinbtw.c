#include <stdio.h>

struct Node {
    int data;           // The value stored in this node
    struct Node *next;  // Pointer to the next node in the list
};

/* Print every node in the list starting from `head`. */
void printList(struct Node *head) {
    struct Node *current = head; // Start walking from the head
    while (current != NULL) {    // Until we reach the end
        printf("%d -> ", current->data); // Print this node's value
        current = current->next;         // Advance to the next node
    }
    printf("NULL\n"); // End of list marker
}

int main() {
    /* Create three nodes and link them: a -> b -> c -> NULL */
    struct Node a, b, c;
    a.data = 10;
    b.data = 20;
    c.data = 30;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    printList(&a); // Print the list before inserting

    /* Put a new node (15) between 10 and 20:
     *   Before: a(10) -> b(20) -> c(30) -> NULL
     *   After:  a(10) -> d(15) -> b(20) -> c(30) -> NULL */
    struct Node d;
    d.data = 15;    // New node holds value 15
    d.next = &b;    // 15 points to 20 (node b)
    a.next = &d;    // 10 now points to 15 (node d) instead of b

    printList(&a); // Print the list after inserting

    return 0;
}
