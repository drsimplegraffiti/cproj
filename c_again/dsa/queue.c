/* What is a Queue? */
/* Think of people waiting in a line at a shop. New people join at the back.
 * The person at the front is served first. */
/* Nobody can skip ahead. That is exactly how a queue works in programming. */

/* A queue is a data structure where you add items at the back (the rear) and
 * remove items from the front. */
/* The first item you add is the first item you remove. This rule is called
 * FIFO (First In, First Out). */
/* Operation 	What It Does */
/* enqueue 	Adds an item at the rear */
/* dequeue 	Removes the item at the front */
/* peek 	Looks at the front item, without removing it */
/* isEmpty 	Checks if the queue has no items */

/* In C, we build a queue with a fixed-size array. Enqueue adds a value at the
 * rear, and dequeue removes the value at the front. We wrap around the array
 * using modulo so the rear can return to the start after reaching the end. */

#include <stdio.h>
#define MAX 3 // Maximum number of items the queue can hold

int queue[MAX]; // The array that holds the queue items
int front = 0;  // Index of the first item (to dequeue next)
int rear = -1;  // Index of the last item (-1 means empty)
int count = 0;  // How many items are currently in the queue

/* Add `value` at the rear of the queue. */
void enqueue(int value) {
    if (count == MAX) { // Queue is full
        printf("Queue is full!\n");
        return;
    }
    rear = (rear + 1) % MAX; // Move rear forward, wrapping around
    queue[rear] = value;     // Store the value at the rear
    count++;                 // One more item in the queue
}

/* Remove and return the item at the front of the queue. */
int dequeue() {
    if (count == 0) { // Queue is empty
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue[front];  // Grab the front item
    front = (front + 1) % MAX; // Move front forward, wrapping around
    count--;                   // One fewer item in the queue
    return value;              // Return the dequeued item
}

int main() {
    /* Three players join the game (enqueue at the rear) */
    enqueue(1);
    enqueue(2);
    enqueue(3);

    /* Play 7 turns: dequeue the front player, then enqueue them at the rear */
    for (int turn = 1; turn <= 7; turn++) {
        int player = dequeue(); // The player at the front plays
        printf("Turn %d: Player %d\n", turn, player);
        enqueue(player); // Then goes to the back of the queue
    }

    return 0;
}
