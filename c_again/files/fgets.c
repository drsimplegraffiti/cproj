#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp;
    char buf[1024];
    int linecount;

    fp = fopen("data.txt", "r");
    if (fp == NULL)
        return 1;
    while (fgets(buf, sizeof buf, fp) != NULL) {
        printf("%d: %s", ++linecount, buf);
    }

    fclose(fp);
    return 0;
}

/* #include <stdio.h> */
/* #include <stdlib.h> */

/* int main(int argc, char *argv[]) { */

/*     if (argc != 2) { */
/*         fprintf(stderr, "Usage: %s <filename>\n", argv[0]); */
/*         return EXIT_FAILURE; */
/*     } */

/*     FILE *fp = fopen(argv[1], "r"); */

/*     if (fp == NULL) { */
/*         perror(argv[1]); */
/*         return EXIT_FAILURE; */
/*     } */

/*     char buf[1024]; */
/*     int linecount = 0; */

/*     while (fgets(buf, sizeof buf, fp) != NULL) { */
/*         printf("%d: %s", ++linecount, buf); */
/*     } */

/*     if (ferror(fp)) { */
/*         perror("Error reading file"); */
/*         fclose(fp); */
/*         return EXIT_FAILURE; */
/*     } */

/*     fclose(fp); */

/*     return EXIT_SUCCESS; */
/* } */
