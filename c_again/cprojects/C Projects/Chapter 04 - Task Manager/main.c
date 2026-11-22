/*
 * Chapter 4 - Task Manager (To-Do App)
 * main.c - interactive menu loop.
 *
 * Loads tasks from "tasks.txt" at startup, saves on exit.
 */

#include <stdio.h>
#include <string.h>
#include "task.h"

extern int task_count;
extern Task task_list[];

void add_task(const char* title);
void list_tasks(void);
void mark_task_done(int id);
void delete_task(int id);
void save_tasks(const char* filename);
void load_tasks(const char* filename);

int main(void) {
    char title[MAX_TITLE_LENGTH];
    int choice, id;

    load_tasks("tasks.txt");

    while (1) {
        printf("\n--- Task Manager ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Done\n");
        printf("4. Delete Task\n");
        printf("5. Save and Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');   /* clear bad input from buffer */
            continue;
        }
        getchar();   /* consume leftover newline after the integer */

        switch (choice) {
            case 1:
                printf("Enter task title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0;   /* remove newline */
                add_task(title);
                break;
            case 2:
                list_tasks();
                break;
            case 3:
                printf("Enter task ID to mark as done: ");
                scanf("%d", &id);
                mark_task_done(id);
                break;
            case 4:
                printf("Enter task ID to delete: ");
                scanf("%d", &id);
                delete_task(id);
                break;
            case 5:
                save_tasks("tasks.txt");
                printf("Tasks saved. Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
