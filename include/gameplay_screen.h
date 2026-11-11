#ifndef GAMEPLAY_SCREEN
#define GAMEPLAY_SCREEN

typedef struct Level Level;

typedef struct Player Player;

typedef struct GameplayScreenToDraw {
    void (*func)(Level*, Player*);
    Level* level;
    Player* player;
} GameplayScreenToDraw;

void DrawGameplayScreen(Level* level, Player* player);
void DrawHeader(Player* player, Level* level);
void DrawEnergy(Player* player, Level* level);
void DrawCrystalsCounter(Player* player, Level* level);
void DrawRounds(Level* level);

#endif