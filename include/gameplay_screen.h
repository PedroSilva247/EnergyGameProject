#ifndef GAMEPLAY_SCREEN
#define GAMEPLAY_SCREEN

#include <stdbool.h>
#include "screen.h"



extern ScreenGameplay currentScreenGameplay;

typedef struct Level Level;

typedef struct Player Player;

typedef struct GameplayScreenToDraw {
    void (*func)(Level*, Player*);
    Level* level;
    Player* player;
} GameplayScreenToDraw;

void DrawGameplayScreen(Level* level, Player* player);
void DrawHeader(Player* player, Level* level, int x, int y);
void DrawEnergy(Player* player, Level* level, int x, int y);
void DrawCrystalsCounter(Player* player, Level* level, int x, int y);
void DrawRounds(Level* level, int x, int y);
void DrawRestartHint(void);
void DrawPlayerEffects(Player* player, Level* level, bool* isPlayerInvisible);
void finishGame();

#endif