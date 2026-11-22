/*
 * Chapter 4 - Task Manager (To-Do App)
 * task.h - task data structure and limits.
 */

#ifndef TASK_H
#define TASK_H

#define MAX_TITLE_LENGTH 100 /* max chars per task title */
#define MAX_TASKS 100        /* fixed capacity of in-memory task array */

typedef struct {
    int id; /* unique task identifier */
    char title[MAX_TITLE_LENGTH];
    int completed; /* 0 = false, 1 = true */
} Task;

#endif
