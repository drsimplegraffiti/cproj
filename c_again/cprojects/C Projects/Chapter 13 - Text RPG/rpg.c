/*
 * Chapter 13 - Text-Based RPG Game
 * rpg.c - character creation, combat, items, experience & leveling.
 *
 * Compile: gcc rpg.c -o rpg
 * Run:     ./rpg
 */

#include <stdio.h>

typedef struct {
    char name[100];
    int health;
    int mana;
    int strength;
    int intelligence;
    int experience;
    int level;
} Player;

typedef struct {
    char name[100];
    int health;
    int strength;
} Enemy;

typedef struct {
    char name[100];
    int health_restoration;
    int mana_restoration;
} Item;

void create_character(Player* player) {
    printf("Enter your character's name: ");
    scanf("%99s", player->name);
    player->health = 100;
    player->mana = 50;
    player->strength = 10;
    player->intelligence = 10;
    player->experience = 0;
    player->level = 1;
    printf("Character created: %s\n", player->name);
}

void combat(Player* player, Enemy* enemy) {
    int action;
    while (player->health > 0 && enemy->health > 0) {
        printf("\nPlayer HP: %d  Mana: %d  |  Enemy %s HP: %d\n",
               player->health, player->mana, enemy->name, enemy->health);
        printf("Choose an action:\n1. Attack\n2. Use Health Potion\n3. Run\n> ");
        if (scanf("%d", &action) != 1) break;

        switch (action) {
            case 1:
                printf("You attack the enemy!\n");
                enemy->health -= player->strength;
                break;
            case 2:
                printf("You use a health potion!\n");
                player->health += 30;
                if (player->health > 100) player->health = 100;
                break;
            case 3:
                printf("You run away!\n");
                return;
            default:
                printf("Invalid action!\n");
        }

        if (enemy->health > 0) {
            printf("The enemy attacks!\n");
            player->health -= enemy->strength;
        }
    }

    if (player->health > 0) {
        printf("\nYou defeated the enemy!\n");
        player->experience += 50;
        if (player->experience >= 100) {
            player->level++;
            player->experience = 0;
            player->strength += 5;
            player->mana += 10;
            printf("You leveled up! New level: %d\n", player->level);
        }
    } else {
        printf("\nYou were defeated!\n");
    }
}

void level_up(Player* player) {
    if (player->experience >= 100) {
        player->level++;
        player->experience = 0;
        player->strength += 5;
        player->mana += 10;
        printf("Congratulations! You leveled up to level %d!\n", player->level);
    }
}

void use_item(Player* player, const Item* item) {
    player->health += item->health_restoration;
    player->mana += item->mana_restoration;
    printf("You used a %s. Health: %d, Mana: %d\n",
           item->name, player->health, player->mana);
}

int main(void) {
    Player player;
    Enemy enemy = {"Goblin", 40, 8};

    create_character(&player);

    printf("\nA wild %s appears!\n", enemy.name);
    combat(&player, &enemy);

    printf("\nFinal stats - %s: Level %d, HP %d, Mana %d, Strength %d, XP %d\n",
           player.name, player.level, player.health, player.mana,
           player.strength, player.experience);

    return 0;
}
