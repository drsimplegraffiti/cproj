
#include <stdio.h>
#define NAME_SIZE 30

void topicoutput(void) {

    /* For readonly use: */
    const char *name = "james";
    printf("name is %s\n", name);

    /* The size must fit the text plus the \0 */
    /* for mutable */
    char my_name[50] = "james\0";
    char c_name[] =
        "some name"; // size is 10, picked automatically, still mutable
    /* But this array has no spare space, so strcat onto it would overflow. If
     * you plan to append or replace with longer text, give it a larger explicit
     * size, like char name[50] = "some name";. */

    int size = 30;
    /* char name[size] = "some name";   // error: a variable-length array can't
     * be initialized this way */
    char my_f_name[NAME_SIZE] = "Zebuchadnezzer\n";
    printf("my_f_name: %s\n", my_f_name);

    /* Read-only has two forms */
    /* const char *name = "somename";    // pointer to a read-only literal */
    /* const char name[] = "somename";   // your own array copy, but the
     * compiler stops you from changing it */
}

int main(void) {
    topicoutput();
    return 0;
}
