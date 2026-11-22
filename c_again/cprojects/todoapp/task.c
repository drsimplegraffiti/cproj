
#include "task.h"

#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

int task_count = 0;

Task task_list[MAX_TASKS];

/* SQLite database connection (opened by load_tasks / save_tasks). */
static sqlite3 *db = NULL;

/* Open the SQLite database and make sure the tasks table exists. */
static int db_open(const char *path) {
    int rc = sqlite3_open(path, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        db = NULL;
        return -1;
    }

    char *err = NULL;
    rc = sqlite3_exec(db,
        "CREATE TABLE IF NOT EXISTS tasks ("
        "id INTEGER PRIMARY KEY,"
        "title TEXT NOT NULL,"
        "completed INTEGER NOT NULL DEFAULT 0"
        ")",
        NULL, NULL, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
        sqlite3_close(db);
        db = NULL;
        return -1;
    }
    return 0;
}

/* Persist the entire in-memory task list to the database. */
static void db_save_all(void) {
    if (!db) {
        return;
    }

    char *err = NULL;
    if (sqlite3_exec(db, "DELETE FROM tasks", NULL, NULL, &err) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
        return;
    }

    sqlite3_stmt *stmt = NULL;
    const char *sql =
        "INSERT INTO tasks (id, title, completed) VALUES (?, ?, ?)";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return;
    }

    for (int i = 0; i < task_count; i++) {
        sqlite3_reset(stmt);
        sqlite3_clear_bindings(stmt);
        sqlite3_bind_int(stmt, 1, task_list[i].id);
        sqlite3_bind_text(stmt, 2, task_list[i].title, -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 3, task_list[i].completed);
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            fprintf(stderr, "Insert failed: %s\n", sqlite3_errmsg(db));
            break;
        }
    }

    sqlite3_finalize(stmt);
}

/* Add a new task to the task list and persist it to the database. */
void add_task(const char *title) {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }

    task_list[task_count].id = task_count + 1;

    strncpy(task_list[task_count].title, title, MAX_TITLE_LENGTH - 1);
    task_list[task_count].title[MAX_TITLE_LENGTH - 1] = '\0';

    task_list[task_count].completed = 0;

    task_count++;

    if (!db) {
        /* database will be opened on the next save/load */
    }
    db_save_all();
}

/* Display all tasks. */
void list_tasks(void) {
    if (task_count == 0) {
        printf("No tasks to show.\n");
        return;
    }

    for (int i = 0; i < task_count; i++) {
        printf("%d. [%c] %s\n", task_list[i].id,
               task_list[i].completed ? 'X' : ' ', task_list[i].title);
    }
}

/* Mark a task as completed using its ID and persist to the database. */
void mark_task_done(int id) {
    if (id <= 0 || id > task_count) {
        printf("Invalid Task ID.\n");
        return;
    }

    task_list[id - 1].completed = 1;
    db_save_all();
}

/* Delete a task and shift remaining tasks. Persists to the database. */
void delete_task(int id) {
    if (id <= 0 || id > task_count) {
        printf("Invalid Task ID.\n");
        return;
    }

    for (int i = id - 1; i < task_count - 1; i++) {
        task_list[i] = task_list[i + 1];
        task_list[i].id = i + 1;
    }

    task_count--;
    db_save_all();
}

/* Load tasks from the SQLite database into memory. */
void load_tasks(const char *filename) {
    if (db_open(filename) != 0) {
        return;
    }

    task_count = 0;

    sqlite3_stmt *stmt = NULL;
    const char *sql =
        "SELECT id, title, completed FROM tasks ORDER BY id";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW && task_count < MAX_TASKS) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *title_uc = sqlite3_column_text(stmt, 1);
        const char *title = (const char *)(title_uc ? title_uc : (const unsigned char *)"");
        int completed = sqlite3_column_int(stmt, 2);

        task_list[task_count].id = id;
        strncpy(task_list[task_count].title, title, MAX_TITLE_LENGTH - 1);
        task_list[task_count].title[MAX_TITLE_LENGTH - 1] = '\0';
        task_list[task_count].completed = completed;
        task_count++;
    }

    sqlite3_finalize(stmt);
}

/* Save all tasks to the SQLite database. */
void save_tasks(const char *filename) {
    if (!db) {
        if (db_open(filename) != 0) {
            return;
        }
    }
    db_save_all();
    printf("Tasks saved to database '%s'.\n", filename);
}

/* Close the SQLite database connection. */
void db_close(void) {
    if (db) {
        sqlite3_close(db);
        db = NULL;
    }
}
