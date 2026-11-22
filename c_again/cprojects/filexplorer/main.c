/* filexplorer - a small interactive command-line file explorer.
 *
 * Commands:
 *   ls          list the current directory
 *   cd <path>   change directory (use ".." to go up)
 *   pwd         print the current working directory
 *   help        show this help
 *   quit/exit   leave the program
 */

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L
#endif

#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#define CMD_SIZE 256
#define MAX_ARGS 8

/* Prints a single directory entry with its type and, for regular files, size.
 */
static void print_entry(const char *dir_path, const char *name) {
    char full_path[PATH_MAX];
    struct stat st;

    if (snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, name) >=
        (int)sizeof(full_path)) {
        fprintf(stderr, "error: path too long: %s/%s\n", dir_path, name);
        return;
    }

    if (stat(full_path, &st) != 0) {
        fprintf(stderr, "error: cannot stat %s: %s\n", full_path,
                strerror(errno));
        return;
    }

    const char *type;
    if (S_ISDIR(st.st_mode))
        type = "[dir]";
    else if (S_ISREG(st.st_mode))
        type = "[file]";
    else
        type = "[other]";

    printf("%-7s %s", type, name);
    if (S_ISREG(st.st_mode))
        printf("  (%lld bytes)", (long long)st.st_size);
    printf("\n");
}

/* Lists every entry in the given directory, skipping "." and "..". */
static void list_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        fprintf(stderr, "error: cannot open directory %s: %s\n", dir_path,
                strerror(errno));
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        print_entry(dir_path, entry->d_name);
    }

    if (closedir(dir) != 0) {
        fprintf(stderr, "warning: failed to close directory %s: %s\n", dir_path,
                strerror(errno));
    }
}

/* Changes the working directory and refreshes cwd.
 * Returns 0 on success, non-zero on error. */
static int change_directory(char *cwd, size_t cwd_size, const char *target) {
    if (target == NULL || *target == '\0') {
        fprintf(stderr, "error: usage: cd <path>\n");
        return 1;
    }

    if (chdir(target) != 0) {
        fprintf(stderr, "error: cannot cd to %s: %s\n", target,
                strerror(errno));
        return 1;
    }

    if (getcwd(cwd, cwd_size) == NULL) {
        fprintf(stderr, "error: cannot get current directory: %s\n",
                strerror(errno));
        return 1;
    }

    return 0;
}

static void print_help(void) {
    printf("Commands:\n");
    printf("  ls          list the current directory\n");
    printf("  cd <path>   change directory (use \"..\" to go up)\n");
    printf("  pwd         print the current working directory\n");
    printf("  help        show this help\n");
    printf("  quit/exit   leave the program\n");
}

int main(void) {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        fprintf(stderr, "error: cannot get current directory: %s\n",
                strerror(errno));
        return 1;
    }

    printf("filexplorer - type 'help' for commands, 'quit' to exit\n");
    printf("Starting in: %s\n\n", cwd);

    char cmd[CMD_SIZE];
    while (1) {
        printf("%s> ", cwd);
        fflush(stdout);

        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            /* EOF (Ctrl-D). */
            printf("\n");
            break;
        }

        /* Strip trailing newline / whitespace. */
        size_t len = strlen(cmd);
        while (len > 0 && (cmd[len - 1] == '\n' || cmd[len - 1] == '\r' ||
                           cmd[len - 1] == ' ' || cmd[len - 1] == '\t')) {
            cmd[--len] = '\0';
        }

        if (len == 0)
            continue;

        /* Split the line into command + arguments. */
        char *argv[MAX_ARGS];
        int argc = 0;
        char *saveptr = NULL;
        char *token = strtok_r(cmd, " \t", &saveptr);
        while (token != NULL && argc < MAX_ARGS) {
            argv[argc++] = token;
            token = strtok_r(NULL, " \t", &saveptr);
        }

        if (strcmp(argv[0], "quit") == 0 || strcmp(argv[0], "exit") == 0 ||
            strcmp(argv[0], "q") == 0) {
            break;
        } else if (strcmp(argv[0], "help") == 0 || strcmp(argv[0], "h") == 0) {
            print_help();
        } else if (strcmp(argv[0], "ls") == 0) {
            list_directory(cwd);
        } else if (strcmp(argv[0], "pwd") == 0) {
            printf("%s\n", cwd);
        } else if (strcmp(argv[0], "cd") == 0) {
            const char *target = (argc > 1) ? argv[1] : NULL;
            if (change_directory(cwd, sizeof(cwd), target) == 0) {
                printf("now in: %s\n", cwd);
                list_directory(cwd);
            }
        } else {
            printf("unknown command: %s (type 'help' for commands)\n", argv[0]);
        }
    }

    printf("goodbye!\n");
    return 0;
}
