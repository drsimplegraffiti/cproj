#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A hash table stores key-value pairs and uses a hash function to turn a key
 * into an array index. Lookup, insert, and delete are O(1) on average.
 * Collisions (two keys hashing to the same index) are handled with chaining:
 * each bucket holds a linked list of entries. */

#define TABLE_SIZE 10

struct Entry {
    char *key;
    int value;
    struct Entry *next;
};

struct HashTable {
    struct Entry *buckets[TABLE_SIZE];
};

/* Simple hash function: sum the bytes of the key and take modulo TABLE_SIZE.
 * Returns an index in [0, TABLE_SIZE). */
unsigned int hash(const char *key) {
    unsigned int sum = 0;
    while (*key) {
        sum += (unsigned char)*key;
        key++;
    }
    return sum % TABLE_SIZE;
}

/* Create a new hash table with all buckets set to NULL. */
struct HashTable *createTable() {
    struct HashTable *table = malloc(sizeof(struct HashTable));
    if (table == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

/* Insert or update a key-value pair.
 * Hash the key to find the bucket, then walk the chain:
 * - if the key already exists, update its value;
 * - otherwise, prepend a new entry to the chain. */
void insert(struct HashTable *table, const char *key, int value) {
    unsigned int index = hash(key);
    struct Entry *current = table->buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    struct Entry *newEntry = malloc(sizeof(struct Entry));
    if (newEntry == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = table->buckets[index];
    table->buckets[index] = newEntry;
}

/* Search for a key and return its value, or -1 if not found.
 * Hash the key, walk the chain, and compare keys with strcmp. */
int search(struct HashTable *table, const char *key) {
    unsigned int index = hash(key);
    struct Entry *current = table->buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

/* Delete a key-value pair from the table.
 * Hash the key, walk the chain keeping track of the previous entry,
 * unlink the matching node, and free its memory. */
void delete(struct HashTable *table, const char *key) {
    unsigned int index = hash(key);
    struct Entry *current = table->buckets[index];
    struct Entry *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                table->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

/* Print the whole table: for each non-empty bucket, walk the chain and
 * show each key-value pair. */
void printTable(struct HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Entry *current = table->buckets[i];
        while (current != NULL) {
            printf("[%s: %d] ", current->key, current->value);
            current = current->next;
        }
    }
    printf("\n");
}

/* Free every entry in every bucket, then the table itself. */
void freeTable(struct HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Entry *current = table->buckets[i];
        while (current != NULL) {
            struct Entry *next = current->next;
            free(current->key);
            free(current);
            current = next;
        }
    }
    free(table);
}

int main() {
    struct HashTable *table = createTable();

    insert(table, "apple", 1);
    insert(table, "banana", 2);
    insert(table, "cherry", 3);

    printf("Table contents: ");
    printTable(table);

    printf("Value for 'banana': %d\n", search(table, "banana"));
    printf("Value for 'grape': %d\n", search(table, "grape"));

    delete(table, "banana");
    printf("After deleting 'banana': ");
    printTable(table);

    freeTable(table);

    return 0;
}
