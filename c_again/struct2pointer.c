#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
} Person;

void PersonStruct(Person *p) {
    p->age = 50;
    strcpy(p->name, "Petere");
}

int main(void) {

    Person p;
    p.age = 90;
    strcpy(p.name, "Jude");

    printf("%s:%d\n", p.name, p.age);

    PersonStruct(&p);
    printf("%s:%d\n", p.name, p.age);
}
