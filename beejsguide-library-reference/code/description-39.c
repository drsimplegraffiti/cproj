#include <stdio.h>
#include <string.h>

char *ngets(char *s, int size)
{
    char *rv = fgets(s, size, stdin);

    if (rv == NULL)
        return NULL;

    char *p = strchr(s, '\n');  // Find a newline

    if (p != NULL)  // if there's a newline
        *p = '\0';  // truncate the string there

    return s;
}
