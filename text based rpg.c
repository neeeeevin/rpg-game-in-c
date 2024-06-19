#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5

// Enum for different room types
typedef enum {
    EMPTY,
    MONSTER,
    TREASURE
} RoomType;

// Function prototypes
void initializeGame();
void playGame();
RoomType enterRoom();
void handleEmptyRoom();
void handleMonsterRoom();
void handleTreasureRoom();
int fightMonster();
void displayStats();

// Global variables
int currentRoom = 0;
int health = 100;
int coins = 0;

int main() {
    initializeGame();
    playGame();
    return 0;
}

// Initialize game state
void initializeGame() {
    printf("Welcome to the Text RPG Game!\n");
    printf("You have %d health and %d coins.\n", health, coins);
    srand(time(NULL));  // Seed random number generator
}

// Main game loop
void playGame() {
    while (currentRoom < MAX_ROOMS) {
        printf("\n--- Room %d ---\n", currentRoom + 1);
        RoomType roomType = enterRoom();

        switch (roomType) {
            case EMPTY:
                handleEmptyRoom();
                break;
            case MONSTER:
                handleMonsterRoom();
                break;
            case TREASURE:
                handleTreasureRoom();
                break;
            default:
                printf("Invalid room type.\n");
                break;
        }

        if (health <= 0) {
            printf("Game Over! You have run out of health.\n");
            break;
        }

        currentRoom++;
    }

    printf("\nGame finished! Final stats:\n");
    displayStats();
}

// Player enters a room (simulate room type randomly)
RoomType enterRoom() {
    int random = rand() % 3;  // Random number between 0 and 2
    return (RoomType)random;
}

// Handle actions for an empty room
void handleEmptyRoom() {
    printf("You entered an empty room. Nothing happens.\n");
}

// Handle actions for a monster room
void handleMonsterRoom() {
    printf("A monster appears!\n");
    int result = fightMonster();
    if (result) {
        printf("You defeated the monster! +10 coins.\n");
        coins += 10;
    } else {
        printf("The monster defeated you! -20 health.\n");
        health -= 20;
    }
    displayStats();
}

// Handle actions for a treasure room
void handleTreasureRoom() {
    printf("You found a treasure chest! +20 coins.\n");
    coins += 20;
    displayStats();
}

// Simulate a fight with a monster (50% chance to win)
int fightMonster() {
    int outcome = rand() % 2;  // 0 or 1
    return outcome;  // 1 for win, 0 for lose
}

// Display player's current stats (health and coins)
void displayStats() {
    printf("Current Stats: Health = %d, Coins = %d\n", health, coins);
}
