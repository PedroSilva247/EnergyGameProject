#ifndef PLAYER
#define PLAYER

#include "map.h"
#include <raylib.h>

typedef struct Level Level;

typedef struct {
    int keyUp, keyDown, keyLeft, keyRight;
} ControlKeys;

typedef struct Player {
	int x;
	int y;
    int energy;
    int crystals;                //Cristais do Player
    float radius;                    
    ControlKeys* controlKeys;
} Player;




void DrawPlayer(Player* player);

Player* createPlayer(int x, int y, int energy, float radius, ControlKeys* controlKeys);

ControlKeys* createControlKeys(int keyUp, int keyLeft, int keyDown, int keyRight);

void updatePlayer(Player* player);

void movePlayer(char axis, int step, Map* map, Player* player);

void verifyKeyboard(Player* player, Map* map);

char verifyPlayerTile(Player* player, Map* map);

void getCrystal(Player* player, Map* map);

void hitTrap(Player* player, Map* map);

void getRecover(Player* player, Level* level);

#endif