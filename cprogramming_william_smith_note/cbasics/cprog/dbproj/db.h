#ifndef DB_H // Include guard: ensures this header is only included once
#define DB_H

#include <stddef.h> // Needed for size_t type

#define MAX_NAME_LEN 50 // Maximum length for a record's name

// Structure to represent a single record in the table
typedef struct {
  int id;                  // Unique identifier for the record
  char name[MAX_NAME_LEN]; // Name of the record (string)
  int age;                 // Age of the record
} Record;

// Structure to represent a table of records (dynamic array)
// In C, typedef means “create a new name (alias) for a type.”
// After this, you can use new_name instead of existing_type.
typedef struct {
  Record *records; // Pointer to dynamically allocated array of records
  size_t size;     // Current number of records in the table
  size_t capacity; // Maximum allocated capacity for the array
} Table;

// Database operations

// Create a new table with a given initial capacity
Table *create_table(size_t capacity);

// Free all memory used by the table
void free_table(Table *table);

// Create a new record with the given id, name, and age
Record *create_record(int id, const char *name, int age);

// Insert a record into the table; returns 0 on success, -1 on failure
int insert_record(Table *table, Record *record);

// Read (find) a record by id; returns pointer to record or NULL if not found
Record *read_record(Table *table, int id);

// Update an existing record by id; returns 0 on success, -1 if not found
int update_record(Table *table, int id, const char *name, int age);

// Delete a record by id; returns 0 on success, -1 if not found
int delete_record(Table *table, int id);

// Print all records in the table
void list_records(Table *table);

#endif // End of include guard
