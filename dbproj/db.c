#include "db.h"     // Include database structures and function declarations
#include <stdio.h>  // For printf()
#include <stdlib.h> // For malloc(), realloc(), free()
#include <string.h> // For strncpy()

// Create a table with initial capacity
Table *create_table(size_t capacity) {

  // Allocate memory for the Table structure itself
  Table *table = malloc(sizeof(Table));

  // If allocation fails, return NULL
  if (!table)
    return NULL;

  // Allocate memory for the dynamic array of records
  // -> means: “Access a struct member through a pointer”
  table->records = malloc(capacity * sizeof(Record));

  // If allocation for records fails
  if (!table->records) {
    free(table); // Free previously allocated table structure
    return NULL; // Signal failure
  }

  // Initialize number of records currently stored
  table->size = 0;

  // Store maximum number of records the table can hold
  table->capacity = capacity;

  // Return pointer to the newly created table
  return table;
}

// Free table memory
void free_table(Table *table) {

  // Check if table pointer is not NULL
  if (table) {

    // Free the dynamically allocated records array
    free(table->records);

    // Free the table structure itself
    free(table);
  }
}

// Create a new record
Record *create_record(int id, const char *name, int age) {

  // Allocate memory for one Record
  Record *r = malloc(sizeof(Record));

  // If allocation fails, return NULL
  if (!r)
    return NULL;

  // Assign ID
  r->id = id;

  // Copy name into record's name buffer safely
  strncpy(r->name, name, MAX_NAME_LEN);

  // Ensure string is null-terminated
  r->name[MAX_NAME_LEN - 1] = '\0';

  // Assign age
  r->age = age;

  // Return pointer to the newly created record
  return r;
}

// Insert record into table
int insert_record(Table *table, Record *record) {

  // If table is full, resize it
  if (table->size == table->capacity) {

    // Double the current capacity
    size_t new_capacity = table->capacity * 2;

    // Reallocate memory for the larger array
    Record *tmp = realloc(table->records, new_capacity * sizeof(Record));

    // If reallocation fails, return error
    if (!tmp)
      return -1;

    // Update table with new memory location
    table->records = tmp;

    // Update table capacity
    table->capacity = new_capacity;
  }

  // Copy record data into the table
  table->records[table->size++] = *record;

  // Free the temporary record allocated earlier
  free(record);

  // Return success
  return 0;
}

// Read record by id
Record *read_record(Table *table, int id) {

  // Iterate through all records
  for (size_t i = 0; i < table->size; i++) {

    // Check if ID matches
    if (table->records[i].id == id)

      // Return pointer to the found record
      return &table->records[i];
  }

  // If not found, return NULL
  return NULL;
}

// Update record by id
int update_record(Table *table, int id, const char *name, int age) {

  // Find the record using its ID
  Record *r = read_record(table, id);

  // If record does not exist, return error
  if (!r)
    return -1;

  // Update name safely
  strncpy(r->name, name, MAX_NAME_LEN);

  // Ensure null termination
  r->name[MAX_NAME_LEN - 1] = '\0';

  // Update age
  r->age = age;

  // Return success
  return 0;
}

// Delete record by id
int delete_record(Table *table, int id) {
  size_t i;

  // Search for the record by ID
  for (i = 0; i < table->size; i++) {
    if (table->records[i].id == id)
      break;
  }

  // If ID was not found
  if (i == table->size)
    return -1;

  // Replace deleted record with the last record
  table->records[i] = table->records[table->size - 1];

  // Decrease record count
  table->size--;

  // Return success
  return 0;
}

// List all records
void list_records(Table *table) {

  // If table has no records
  if (table->size == 0) {
    printf("Table is empty!\n");
    return;
  }

  // Print table header
  printf("ID\tName\tAge\n");
  printf("-------------------\n");

  // Print each record
  for (size_t i = 0; i < table->size; i++) {
    printf("%d\t%s\t%d\n", table->records[i].id, table->records[i].name,
           table->records[i].age);
  }
}
