#ifndef TASK_H
#define TASK_H

#define MAX_TITLE_LENGTH 100

#define MAX_TASKS 100

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    int completed; /* 0 = false, 1 = true */
} Task;

void add_task(const char *title);
void list_tasks(void);
void mark_task_done(int id);
void delete_task(int id);
void save_tasks(const char *filename);
void load_tasks(const char *filename);
void db_close(void);

#endif
