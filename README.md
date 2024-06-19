# rpg-game-in-c
C program that simulates a simple text-based RPG (Role-Playing Game). In this RPG, the player will navigate through different rooms, encountering monsters and treasure, and making decisions that affect their progress. This program demonstrates basic game mechanics such as navigation, random events, and decision-making.

Explanation:
Room Types (RoomType Enum):

Defines different types of rooms: EMPTY, MONSTER, and TREASURE.
Global Variables:

currentRoom: Tracks the current room the player is in.
health: Player's health points.
coins: Player's coins accumulated.
Functions:

initializeGame(): Welcomes the player and initializes the game state.
playGame(): Main game loop where the player progresses through rooms until the game ends.
enterRoom(): Simulates entering a room with a random room type.
handleEmptyRoom(), handleMonsterRoom(), handleTreasureRoom(): Functions to handle actions based on the room type encountered.
fightMonster(): Simulates a fight with a monster with a 50% chance of winning.
displayStats(): Displays the player's current health and coins.
Main Functionality:

The player progresses through a fixed number of rooms (MAX_ROOMS).
Each room type triggers different actions:
Empty Room: Nothing happens.
Monster Room: Player fights a monster with a chance to win coins or lose health.
Treasure Room: Player gains coins.
The game ends if the player's health reaches zero or after all rooms are explored.
