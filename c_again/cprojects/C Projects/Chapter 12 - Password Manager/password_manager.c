/*
 * Chapter 12 - Password Manager (Encrypted)
 * password_manager.c - stores encrypted website/username/password entries
 * using XOR encryption with a master key.
 *
 * Compile: gcc password_manager.c -o password_manager
 * Run:     ./password_manager
 */

#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_FIELD 100
#define FILENAME "passwords.dat"

typedef struct {
    char website[MAX_FIELD];
    char username[MAX_FIELD];
    char password[MAX_FIELD]; /* encrypted */
} PasswordEntry;

/* XOR encrypt/decrypt (symmetric) */
void xor_crypt(const char* input, const char* key, char* output) {
    int in_len = strlen(input);
    int key_len = strlen(key);
    if (key_len == 0) key_len = 1;
    for (int i = 0; i < in_len; i++) {
        output[i] = (char)(input[i] ^ key[i % key_len]);
    }
    output[in_len] = '\0';
}

int entry_exists(PasswordEntry* entries, int count, const char* website) {
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].website, website) == 0) return i;
    }
    return -1;
}

void save_entries(PasswordEntry* entries, int count, const char* key) {
    FILE* file = fopen(FILENAME, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
    /* Write a temporary array with encrypted passwords */
    PasswordEntry tmp[MAX_ENTRIES];
    for (int i = 0; i < count; i++) {
        tmp[i] = entries[i];
        char encrypted[MAX_FIELD];
        xor_crypt(entries[i].password, key, encrypted);
        strcpy(tmp[i].password, encrypted);
    }
    fwrite(&count, sizeof(int), 1, file);
    fwrite(tmp, sizeof(PasswordEntry), count, file);
    fclose(file);
    printf("Passwords saved to %s\n", FILENAME);
}

int load_entries(PasswordEntry* entries, const char* key) {
    FILE* file = fopen(FILENAME, "rb");
    if (!file) return 0;
    int count = 0;
    if (fread(&count, sizeof(int), 1, file) != 1) {
        fclose(file);
        return 0;
    }
    if (count < 0 || count > MAX_ENTRIES) {
        fclose(file);
        return 0;
    }
    PasswordEntry tmp[MAX_ENTRIES];
    fread(tmp, sizeof(PasswordEntry), count, file);
    fclose(file);
    for (int i = 0; i < count; i++) {
        entries[i] = tmp[i];
        char decrypted[MAX_FIELD];
        xor_crypt(entries[i].password, key, decrypted);
        strcpy(entries[i].password, decrypted);
    }
    return count;
}

static void read_line(char* buf, size_t size) {
    if (fgets(buf, (int)size, stdin)) {
        buf[strcspn(buf, "\n")] = 0;
    }
}

int main(void) {
    PasswordEntry entries[MAX_ENTRIES];
    int count = 0;
    char key[MAX_FIELD];
    int choice;

    printf("=== Encrypted Password Manager ===\n");
    printf("Enter master key: ");
    read_line(key, sizeof(key));

    count = load_entries(entries, key);
    printf("Loaded %d entries.\n", count);

    while (1) {
        printf("\n1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Save and Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;
        getchar();

        switch (choice) {
            case 1: {
                if (count >= MAX_ENTRIES) {
                    printf("Entry list full.\n");
                    break;
                }
                printf("Website: ");
                read_line(entries[count].website, sizeof(entries[count].website));
                printf("Username: ");
                read_line(entries[count].username, sizeof(entries[count].username));
                printf("Password: ");
                read_line(entries[count].password, sizeof(entries[count].password));
                count++;
                printf("Entry added (will be encrypted on save).\n");
                break;
            }
            case 2:
                if (count == 0) {
                    printf("No entries.\n");
                    break;
                }
                for (int i = 0; i < count; i++) {
                    printf("[%d] Website: %s\n    Username: %s\n    Password: %s\n",
                           i + 1, entries[i].website, entries[i].username,
                           entries[i].password);
                }
                break;
            case 3:
                save_entries(entries, count, key);
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
