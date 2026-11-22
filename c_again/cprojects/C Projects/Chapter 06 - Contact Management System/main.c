/*
 * Chapter 6 - Contact Management System
 * main.c - terminal menu for the contact manager.
 */

#include <stdio.h>
#include <string.h>
#include "contact.h"

void add_contact(const char*, const char*, const char*, const char*);
void view_contacts(void);
void search_contacts(const char*);
void sort_contacts(void);
int save_contacts(const char*);
int load_contacts(const char*);
void free_contacts(void);

static void read_line(char* buf, size_t size) {
    if (fgets(buf, (int)size, stdin)) {
        buf[strcspn(buf, "\n")] = 0;
    }
}

int main(void) {
    int choice;
    char name[50], phone[20], email[50], address[100];
    char query[100];
    const char* filename = "contacts.bin";

    load_contacts(filename);

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Sort Contacts (by Name)\n");
        printf("5. Save and Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar(); /* consume newline */

        switch (choice) {
            case 1:
                printf("Enter name: ");
                read_line(name, sizeof(name));
                printf("Enter phone: ");
                read_line(phone, sizeof(phone));
                printf("Enter email: ");
                read_line(email, sizeof(email));
                printf("Enter address: ");
                read_line(address, sizeof(address));
                add_contact(name, phone, email, address);
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                printf("Enter search query: ");
                read_line(query, sizeof(query));
                search_contacts(query);
                break;
            case 4:
                sort_contacts();
                printf("Contacts sorted by name.\n");
                break;
            case 5:
                save_contacts(filename);
                free_contacts();
                printf("Contacts saved. Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
