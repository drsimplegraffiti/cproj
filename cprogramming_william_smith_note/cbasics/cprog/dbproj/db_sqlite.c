#include "db_sqlite.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Open SQLite database
Database *db_open(const char *filename) {
  Database *db = malloc(sizeof(Database));
  if (!db)
    return NULL;

  if (sqlite3_open(filename, &db->conn)) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db->conn));
    free(db);
    return NULL;
  }

  return db;
}

// Close SQLite database
void db_close(Database *db) {
  if (!db)
    return;
  sqlite3_close(db->conn);
  free(db);
}

// Create table
int db_create_table(Database *db) {
  const char *sql = "CREATE TABLE IF NOT EXISTS students ("
                    "id INTEGER PRIMARY KEY, "
                    "name TEXT NOT NULL, "
                    "age INTEGER NOT NULL);";

  char *err_msg = NULL;
  int rc = sqlite3_exec(db->conn, sql, 0, 0, &err_msg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", err_msg);
    sqlite3_free(err_msg);
    return rc;
  }
  return 0;
}

// Insert record
int db_insert(Database *db, int id, const char *name, int age) {
  const char *sql = "INSERT INTO students(id, name, age) VALUES(?, ?, ?);";
  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(db->conn, sql, -1, &stmt, 0);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db->conn));
    return rc;
  }

  sqlite3_bind_int(stmt, 1, id);
  sqlite3_bind_text(stmt, 2, name, -1, SQLITE_STATIC);
  sqlite3_bind_int(stmt, 3, age);

  rc = sqlite3_step(stmt);
  sqlite3_finalize(stmt);

  return rc == SQLITE_DONE ? 0 : rc;
}

// Read record by id
int db_read(Database *db, int id) {
  const char *sql = "SELECT id, name, age FROM students WHERE id = ?;";
  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(db->conn, sql, -1, &stmt, 0);
  if (rc != SQLITE_OK)
    return rc;

  sqlite3_bind_int(stmt, 1, id);

  rc = sqlite3_step(stmt);
  if (rc == SQLITE_ROW) {
    printf("ID: %d, Name: %s, Age: %d\n", sqlite3_column_int(stmt, 0),
           sqlite3_column_text(stmt, 1), sqlite3_column_int(stmt, 2));
  } else {
    printf("Record not found.\n");
  }

  sqlite3_finalize(stmt);
  return 0;
}

// Update record
int db_update(Database *db, int id, const char *name, int age) {
  const char *sql = "UPDATE students SET name = ?, age = ? WHERE id = ?;";
  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(db->conn, sql, -1, &stmt, 0);
  if (rc != SQLITE_OK)
    return rc;

  sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
  sqlite3_bind_int(stmt, 2, age);
  sqlite3_bind_int(stmt, 3, id);

  rc = sqlite3_step(stmt);
  sqlite3_finalize(stmt);
  return rc == SQLITE_DONE ? 0 : rc;
}

// Delete record
int db_delete(Database *db, int id) {
  const char *sql = "DELETE FROM students WHERE id = ?;";
  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(db->conn, sql, -1, &stmt, 0);
  if (rc != SQLITE_OK)
    return rc;

  sqlite3_bind_int(stmt, 1, id);

  rc = sqlite3_step(stmt);
  sqlite3_finalize(stmt);
  return rc == SQLITE_DONE ? 0 : rc;
}

// List all records
int db_list(Database *db) {
  const char *sql = "SELECT id, name, age FROM students;";
  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(db->conn, sql, -1, &stmt, 0);
  if (rc != SQLITE_OK)
    return rc;

  printf("ID\tName\tAge\n");
  printf("------------------------\n");

  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    printf("%d\t%s\t%d\n", sqlite3_column_int(stmt, 0),
           sqlite3_column_text(stmt, 1), sqlite3_column_int(stmt, 2));
  }

  sqlite3_finalize(stmt);
  return 0;
}

// run: gcc -Wall -Wextra main.c db_sqlite.c -lsqlite3 -o sqlite_db
