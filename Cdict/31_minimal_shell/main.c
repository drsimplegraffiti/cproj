#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[100];

    while (1) {              // infinite loop = shell stays alive
        printf("myshell> "); // print prompt
        fgets(command, sizeof(command), stdin); // read user input
        command[strcspn(command, "\n")] = 0;    // strip trailing \n

        // if (strcmp(command, "exit") == 0) {        // if user types "exit"
        //     break;                                 // kill the loop = exit
        //     shell
        // }

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "ls") == 0) {
            system("ls");

        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("  ls    - list files\n");
            printf("  pwd   - print working directory\n");
            printf("  clear - clear screen\n");
            printf("  exit  - quit shell\n");
        } else if (strcmp(command, "pwd") == 0) {
            system("pwd");
        } else if (strcmp(command, "clear") == 0) {
            system("clear");
        } else {
            // unknown command
            printf("myshell: command not found: %s\n", command);
        }

        // system(command); // run the command via OS
    }

    return 0;
}

//
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
//
// #define MAX_INPUT 100
//
// int main() {
//     char command[MAX_INPUT];
//
//     while (1) {
//         printf("myshell> ");
//         fflush(stdout);
//
//         if (fgets(command, sizeof(command), stdin) == NULL) {
//             printf("\n");
//             break;
//         }
//
//         command[strcspn(command, "\n")] = '\0';
//
//         if (strlen(command) == 0) {
//             continue;
//         }
//
//         if (strcmp(command, "exit") == 0) {
//             break;
//         }
//
//         else if (strcmp(command, "ls") == 0) {
//             system("ls");
//
//         }
//
//         else if (strcmp(command, "pwd") == 0) {
//             system("pwd");
//
//         }
//
//         else if (strcmp(command, "clear") == 0) {
//             system("clear");
//
//         }
//
//         else if (strcmp(command, "whoami") == 0) {
//             system("whoami");
//
//         }
//
//         else if (strcmp(command, "date") == 0) {
//             system("date");
//
//         }
//
//         else if (strcmp(command, "uname") == 0) {
//             system("uname -a");
//
//         }
//
//         else if (strcmp(command, "help") == 0) {
//             printf("Available commands:\n");
//             printf("  ls       - list files\n");
//             printf("  pwd      - print working directory\n");
//             printf("  cd       - change directory\n");
//             printf("  mkdir    - create directory\n");
//             printf("  rmdir    - remove empty directory\n");
//             printf("  whoami   - show current user\n");
//             printf("  date     - show date and time\n");
//             printf("  uname    - show system information\n");
//             printf("  clear    - clear terminal\n");
//             printf("  help     - show available commands\n");
//             printf("  exit     - quit shell\n");
//             printf("\nOther Linux commands are also supported.\n");
//
//         }
//
//         else {
//             system(command);
//         }
//     }
//
//     printf("Exiting myshell...\n");
//
//     return 0;
// }
