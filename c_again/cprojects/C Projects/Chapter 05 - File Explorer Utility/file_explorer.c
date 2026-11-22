/*
 * Chapter 5 - File Explorer Utility
 * file_explorer.c - terminal file explorer using POSIX directory/file APIs.
 *
 * Features: list entries with type/size/permissions, rename, copy
 * (binary-safe), delete.
 *
 * Compile: gcc file_explorer.c -o file_explorer
 * Run:     ./file_explorer
 */

#include <stdio.h>
#include <string.h>
#include <dirent.h>    /* opendir, readdir, closedir, struct dirent */
#include <sys/stat.h>  /* stat, S_ISDIR, permission bits S_IRUSR etc. */

void list_directory(const char* path) {
    DIR* dir;
    struct dirent* entry;          /* one directory entry (name + type) */
    struct stat fileStat;          /* file metadata: size, permissions, type */
    char fullpath[512];

    dir = opendir(path);           /* open directory stream */
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    printf("Contents of %s\n", path);
    printf("------------------------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {   /* read entries until NULL */
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        if (stat(fullpath, &fileStat) == -1) {
            perror("Stat failed");
            continue;
        }

        printf("%-25s ", entry->d_name);
        if (S_ISDIR(fileStat.st_mode))
            printf("(Directory) ");
        else
            printf("(File)      ");
        printf("%ld bytes  ", (long)fileStat.st_size);
        /* Print owner/group/other rwx permission bits */
        printf("%c%c%c%c%c%c%c%c%c\n",
               (fileStat.st_mode & S_IRUSR) ? 'r' : '-',
               (fileStat.st_mode & S_IWUSR) ? 'w' : '-',
               (fileStat.st_mode & S_IXUSR) ? 'x' : '-',
               (fileStat.st_mode & S_IRGRP) ? 'r' : '-',
               (fileStat.st_mode & S_IWGRP) ? 'w' : '-',
               (fileStat.st_mode & S_IXGRP) ? 'x' : '-',
               (fileStat.st_mode & S_IROTH) ? 'r' : '-',
               (fileStat.st_mode & S_IWOTH) ? 'w' : '-',
               (fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    }

    closedir(dir);
}

void rename_file(const char* oldname, const char* newname) {
    if (rename(oldname, newname) == 0) {
        printf("File renamed successfully.\n");
    } else {
        perror("Error renaming file");
    }
}

void copy_file(const char* source, const char* dest) {
    FILE* src = fopen(source, "rb");   /* binary mode - safe for images/exes */
    FILE* dst = fopen(dest, "wb");
    char buffer[1024];
    size_t bytes;

    if (!src || !dst) {
        perror("Error opening files");
        if (src) fclose(src);
        if (dst) fclose(dst);
        return;
    }

    /* Stream in 1 KB chunks - works for text and binary files alike */
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }

    fclose(src);
    fclose(dst);
    printf("File copied successfully.\n");
}

void delete_file(const char* filename) {
    if (remove(filename) == 0) {
        printf("File deleted.\n");
    } else {
        perror("File deletion failed");
    }
}

int main(void) {
    char command[16];
    char path[256];
    char newname[256];

    printf("Enter starting directory: ");
    if (!fgets(path, sizeof(path), stdin)) return 1;
    path[strcspn(path, "\n")] = 0;

    while (1) {
        list_directory(path);
        printf("\nOptions: [L]ist [R]ename [C]opy [D]elete [Q]uit\n");
        printf("Enter command: ");

        if (!fgets(command, sizeof(command), stdin)) break;

        switch (command[0]) {
            case 'L':
            case 'l':
                continue;   /* re-list (useful after rename/copy/delete) */

            case 'R':
            case 'r':
                printf("Enter file to rename: ");
                if (!fgets(path, sizeof(path), stdin)) break;
                path[strcspn(path, "\n")] = 0;
                printf("Enter new name: ");
                if (!fgets(newname, sizeof(newname), stdin)) break;
                newname[strcspn(newname, "\n")] = 0;
                rename_file(path, newname);
                break;

            case 'C':
            case 'c':
                printf("Enter source file: ");
                if (!fgets(path, sizeof(path), stdin)) break;
                path[strcspn(path, "\n")] = 0;
                printf("Enter destination: ");
                if (!fgets(newname, sizeof(newname), stdin)) break;
                newname[strcspn(newname, "\n")] = 0;
                copy_file(path, newname);
                break;

            case 'D':
            case 'd':
                printf("Enter file to delete: ");
                if (!fgets(path, sizeof(path), stdin)) break;
                path[strcspn(path, "\n")] = 0;
                delete_file(path);
                break;

            case 'Q':
            case 'q':
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Unknown command.\n");
        }
    }

    return 0;
}
