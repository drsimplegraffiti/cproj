#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *s;
    size_t len;
    size_t cap;
} string;

void panic(char *message) {
    puts(message);
    exit(1);
}

string string_new(char *text) {
    if (text == NULL)
        panic("error: NULL passed to string_new()");

    string s = {0};

    s.len = strlen(text);
    s.cap = sizeof(char) * (s.len + 1);
    s.s = malloc(s.cap);
    if (s.s == NULL) {
        panic("error: Memory allocation failed!");
    }

    strcpy(s.s, text);

    return s;
}

void string_free(string *s) {
    if (s == NULL)
        return;

    s->len = 0;
    s->cap = 0;
    free(s->s);
    s->s = NULL;
}

int main(void) {
    string name = string_new("King Nyaomaru");

    printf("Welcome %s!\n", name.s);
    string_free(&name);

    string student = string_new("John Doe");
    printf("Student: %s\n", student.s);
    string_free(&student);

    return 0;
}
