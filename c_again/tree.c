
#define _DEFAULT_SOURCE

#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define BLUE "\033[1;34m"
#define RESET "\033[0m"

void print_file(const char *name, int is_dir, int indent) {
    if (indent)
        printf("%*c", indent * 2, ' ');

    if (is_dir)
        printf(BLUE "%s/" RESET "\n", name);
    else
        printf("%s\n", name);
}

int walk(const char *path, int indent) {
    DIR *dir = opendir(path);

    if (!dir) {
        perror(path);
        return 1;
    }

    struct dirent *dp;

    while ((dp = readdir(dir)) != NULL) {
        const char *name = dp->d_name;

        // Ignore current and parent directory entries.
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
            continue;

        if (dp->d_type == DT_DIR) {
            // Print directory.
            print_file(name, 1, indent);

            // Construct the subdirectory path.
            size_t len = strlen(path) + strlen(name) + 2;
            char sub_path[len];

            snprintf(sub_path, len, "%s/%s", path, name);

            // Recursively walk into the subdirectory.
            walk(sub_path, indent + 1);

        } else {
            // Print file.
            print_file(name, 0, indent);
        }
    }

    closedir(dir);
    return 0;
}

int main(int argc, char *argv[]) {
    const char *path = ".";

    if (argc > 1)
        path = argv[1];

    printf("%s\n", path);

    int indent = 0;

    return walk(path, indent);
}
