#ifndef DB_SQLITE_H
#define DB_SQLITE_H

#include <sqlite3.h> // SQLite database

typedef struct {
  sqlite3 *conn; // SQLite database connection
} Database;

// Open a database (creates file if it doesn't exist)
Database *db_open(const char *filename);

// Close the database
void db_close(Database *db);

// Create a table if it doesn't exist
int db_create_table(Database *db);

// Insert a record
int db_insert(Database *db, int id, const char *name, int age);

// Read a record by id
int db_read(Database *db, int id);

// Update a record by id
int db_update(Database *db, int id, const char *name, int age);

// Delete a record by id
int db_delete(Database *db, int id);

// List all records
int db_list(Database *db);

#endif
