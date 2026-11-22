/*
 * Chapter 4 - Task Manager (To-Do App)
 * task.c - core task operations and file persistence.
 *
 * Tasks live in a fixed-size global array; id is assigned sequentially and
 * renumbered on delete so ids stay contiguous. File format: id|completed|title
 */

#include <stdio.h>
#include <string.h>
#include "task.h"

int task_count = 0;
Task task_list[MAX_TASKS];

void add_task(const char* title) {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
    task_list[task_count].id = task_count + 1;
    strncpy(task_list[task_count].title, title, MAX_TITLE_LENGTH - 1);
    task_list[task_count].title[MAX_TITLE_LENGTH - 1] = '\0';
    task_list[task_count].completed = 0;
    task_count++;
}

void list_tasks(void) {
    if (task_count == 0) {
        printf("No tasks to show.\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        printf("%d. [%c] %s\n", task_list[i].id,
               task_list[i].completed ? 'X' : ' ',
               task_list[i].title);
    }
}

void mark_task_done(int id) {
    if (id <= 0 || id > task_count) {
        printf("Invalid Task ID.\n");
        return;
    }
    task_list[id - 1].completed = 1;   /* ids are 1-based, array is 0-based */
}

void delete_task(int id) {
    if (id <= 0 || id > task_count) {
        printf("Invalid Task ID.\n");
        return;
    }
    /* Shift later tasks down by one and renumber ids */
    for (int i = id - 1; i < task_count - 1; i++) {
        task_list[i] = task_list[i + 1];
        task_list[i].id = i + 1;
    }
    task_count--;
}

void save_tasks(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file for saving.\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d|%d|%s\n", task_list[i].id,
                task_list[i].completed, task_list[i].title);
    }
    fclose(file);
}

void load_tasks(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return;   /* no file yet on first run - that's fine */
    while (fscanf(file, "%d|%d|%[^\n]\n",
                  &task_list[task_count].id,
                  &task_list[task_count].completed,
                  task_list[task_count].title) == 3) {
        task_count++;
    }
    fclose(file);
}
