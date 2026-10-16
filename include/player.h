#include "map.h"

#ifndef PLAYER
#define PLAYER

typedef struct {
    int keyUp, keyDown, keyLeft, keyRight;
} ControlKeys;

typedef struct {
	int x;
	int y;
    int energy;
    float radius;
    int crystal;                    //Cristais do player
    ControlKeys* controlKeys;
} Player;




void DrawPlayer(Player* player);

Player* createPlayer(int x, int y, int energy, float radius, ControlKeys* controlKeys);

ControlKeys* createControlKeys(int keyUp, int keyLeft, int keyDown, int keyRight);

void updatePlayer(Player* player);

void movePlayer(char axis, int step, Map* map, Player* player);

void verifyKeyboard(Player* player, Map* map);

#endif