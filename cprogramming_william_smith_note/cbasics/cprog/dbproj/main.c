// #include "db.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
// int main() {
//   Table *table = create_table(4);
//   if (!table) {
//     fprintf(stderr, "Failed to create table\n");
//     return 1;
//   }
//
//   int choice;
//   int id, age;
//   char name[MAX_NAME_LEN];
//
//   while (1) {
//     printf("\n=== In-Memory DB ===\n");
//     printf("1. Insert Record\n");
//     printf("2. Read Record\n");
//     printf("3. Update Record\n");
//     printf("4. Delete Record\n");
//     printf("5. List Records\n");
//     printf("6. Exit\n");
//     printf("Choice: ");
//     scanf("%d", &choice);
//
//     switch (choice) {
//     case 1:
//       printf("ID: ");
//       scanf("%d", &id);
//       printf("Name: ");
//       scanf(" %[^\n]", name);
//       printf("Age: ");
//       scanf("%d", &age);
//       if (insert_record(table, create_record(id, name, age)) == 0)
//         printf("Inserted!\n");
//       else
//         printf("Insert failed!\n");
//       break;
//
//     case 2:
//       printf("ID: ");
//       scanf("%d", &id);
//       {
//         Record *r = read_record(table, id);
//         if (r)
//           printf("ID=%d Name=%s Age=%d\n", r->id, r->name, r->age);
//         else
//           printf("Record not found\n");
//       }
//       break;
//
//     case 3:
//       printf("ID to update: ");
//       scanf("%d", &id);
//       printf("New Name: ");
//       scanf(" %[^\n]", name);
//       printf("New Age: ");
//       scanf("%d", &age);
//       if (update_record(table, id, name, age) == 0)
//         printf("Updated!\n");
//       else
//         printf("Update failed!\n");
//       break;
//
//     case 4:
//       printf("ID to delete: ");
//       scanf("%d", &id);
//       if (delete_record(table, id) == 0)
//         printf("Deleted!\n");
//       else
//         printf("Delete failed!\n");
//       break;
//
//     case 5:
//       list_records(table);
//       break;
//
//     case 6:
//       free_table(table);
//       exit(0);
//
//     default:
//       printf("Invalid choice\n");
//     }
//   }
//
//   return 0;
// }
//
//
#include "db_sqlite.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

int main() {
  Database *db = db_open("students.db");
  if (!db) {
    fprintf(stderr, "Failed to open database\n");
    return 1;
  }

  db_create_table(db);

  int choice;
  int id, age;
  char name[MAX_NAME_LEN];

  while (1) {
    printf("\n=== SQLite DB ===\n");
    printf("1. Insert Record\n");
    printf("2. Read Record\n");
    printf("3. Update Record\n");
    printf("4. Delete Record\n");
    printf("5. List Records\n");
    printf("6. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("ID: ");
      scanf("%d", &id);
      printf("Name: ");
      scanf(" %[^\n]", name);
      printf("Age: ");
      scanf("%d", &age);

      if (db_insert(db, id, name, age) == 0)
        printf("Inserted!\n");
      else
        printf("Insert failed!\n");
      break;

    case 2:
      printf("ID: ");
      scanf("%d", &id);
      db_read(db, id);
      break;

    case 3:
      printf("ID to update: ");
      scanf("%d", &id);
      printf("New Name: ");
      scanf(" %[^\n]", name);
      printf("New Age: ");
      scanf("%d", &age);

      if (db_update(db, id, name, age) == 0)
        printf("Updated!\n");
      else
        printf("Update failed!\n");
      break;

    case 4:
      printf("ID to delete: ");
      scanf("%d", &id);
      if (db_delete(db, id) == 0)
        printf("Deleted!\n");
      else
        printf("Delete failed!\n");
      break;

    case 5:
      db_list(db);
      break;

    case 6:
      db_close(db);
      exit(0);

    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}
//
// sudo apt install sqlite3
// sudo apt install libsqlite3-dev
// gcc main.c db_sqlite.c -lsqlite3 -o sqlite_cli
// ./sqlite_cli
//
//
// with db run:
// gcc -Wall -Wextra main.c db_sqlite.c -lsqlite3 -o sqlite_db
