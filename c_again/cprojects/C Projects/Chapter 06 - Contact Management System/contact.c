/*
 * Chapter 6 - Contact Management System
 * contact.c - dynamic array management, binary file I/O,
 * searching, and sorting.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

/* Global dynamic contact array */
static Contact* contacts = NULL;
static int contact_count = 0;
static int capacity = 0;

static int ensure_capacity(void) {
    if (contact_count < capacity) return 0;
    int new_capacity = (capacity == 0) ? 10 : capacity * 2;
    Contact* tmp = realloc(contacts, sizeof(Contact) * new_capacity);
    if (!tmp) {
        perror("Memory reallocation failed");
        return -1;
    }
    contacts = tmp;
    capacity = new_capacity;
    return 0;
}

void init_contacts(void) {
    if (capacity == 0) {
        contacts = malloc(sizeof(Contact) * 10);
        if (!contacts) {
            perror("Memory allocation failed");
            exit(1);
        }
        capacity = 10;
    }
}

void free_contacts(void) {
    free(contacts);
    contacts = NULL;
    contact_count = 0;
    capacity = 0;
}

int get_count(void) { return contact_count; }
Contact* get_list(void) { return contacts; }

void add_contact(const char* name, const char* phone,
                 const char* email, const char* address) {
    if (ensure_capacity() != 0) return;

    strncpy(contacts[contact_count].name, name, 49);
    contacts[contact_count].name[49] = '\0';
    strncpy(contacts[contact_count].phone, phone, 19);
    contacts[contact_count].phone[19] = '\0';
    strncpy(contacts[contact_count].email, email, 49);
    contacts[contact_count].email[49] = '\0';
    strncpy(contacts[contact_count].address, address, 99);
    contacts[contact_count].address[99] = '\0';
    contact_count++;
}

void view_contacts(void) {
    if (contact_count == 0) {
        printf("No contacts stored.\n");
        return;
    }
    printf("%-4s %-20s %-18s %-30s %-20s\n",
           "ID", "Name", "Phone", "Email", "Address");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%-4d %-20s %-18s %-30s %-20s\n",
               i + 1, contacts[i].name, contacts[i].phone,
               contacts[i].email, contacts[i].address);
    }
}

void search_contacts(const char* query) {
    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strstr(contacts[i].name, query) ||
            strstr(contacts[i].email, query) ||
            strstr(contacts[i].phone, query)) {
            printf("Found %s | %s | %s | %s\n",
                   contacts[i].name, contacts[i].phone,
                   contacts[i].email, contacts[i].address);
            found = 1;
        }
    }
    if (!found) printf("No contacts matching '%s'.\n", query);
}

void sort_contacts(void) {
    for (int i = 0; i < contact_count - 1; i++) {
        for (int j = i + 1; j < contact_count; j++) {
            if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                Contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
}

int save_contacts(const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        perror("Failed to open file for writing");
        return -1;
    }
    fwrite(&contact_count, sizeof(int), 1, fp);
    fwrite(contacts, sizeof(Contact), contact_count, fp);
    fclose(fp);
    printf("Contacts saved to %s\n", filename);
    return 0;
}

int load_contacts(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        contact_count = 0;
        return 0;
    }
    if (fread(&contact_count, sizeof(int), 1, fp) != 1) {
        fclose(fp);
        return -1;
    }
    init_contacts();
    if (contact_count > capacity) {
        Contact* tmp = realloc(contacts, sizeof(Contact) * contact_count);
        if (!tmp) {
            perror("realloc failed");
            fclose(fp);
            return -1;
        }
        contacts = tmp;
        capacity = contact_count;
    }
    fread(contacts, sizeof(Contact), contact_count, fp);
    fclose(fp);
    printf("Loaded %d contacts from %s\n", contact_count, filename);
    return 0;
}
