#include <stdint.h>
#include <stdio.h>

typedef int32_t i32;
typedef int64_t i64;
typedef int8_t i8;

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

struct animal {
    char *name;
    int leg_count, speed;
};

//  original name      new name
//            |         |
//            v         v
//      |-----------| |----|
typedef struct animal animal;

//  original name
//            |
//            v
//      |-----------|
typedef struct animal_one {
    char *name;
    int leg_count, speed;
} animal_one; // <-- new name

struct animal_one y; // This works
animal_one z;        // This also works because "animal_one" is an alias

int main(void) {
    struct animal y; // This works
    animal z;        // This also works because "animal" is an alias

    // Assign values
    y.name = "Lion";
    y.leg_count = 4;
    y.speed = 80;

    z.name = "Cheetah";
    z.leg_count = 4;
    z.speed = 120;

    printf("Animal Y: %s\n", y.name);
    printf("Legs: %d\n", y.leg_count);
    printf("Speed: %d km/h\n", y.speed);

    printf("\nAnimal Z: %s\n", z.name);
    printf("Legs: %d\n", z.leg_count);
    printf("Speed: %d km/h\n", z.speed);

    return 0;
}
