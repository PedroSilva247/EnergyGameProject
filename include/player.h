#ifndef PLAYER
#define PLAYER

#include "map.h"
#include "config.h"
#include <raylib.h>


#define MAX_EFFECTS 5

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
    Vector2* positionPixel;
    Texture2D sprite; //Load dos sprites do player
    char effects[20][MAX_EFFECTS];
    int nEffects;
} Player;




void DrawPlayer(Player* player);

Player* createPlayer(int x, int y, int energy, float radius, ControlKeys* controlKeys);

ControlKeys* createControlKeys(int keyUp, int keyLeft, int keyDown, int keyRight);

void updatePlayer(Player* player);

void movePlayer(char axis, int step, Map* map, Player* player);

void verifyKeyboardGameplay(Player* player, Map* map);

char verifyPlayerTile(Player* player, Map* map);

void getCrystal(Player* player, Map* map);

void hitTrap(Player* player, Map* map);

void getRecover(Player* player, Level* level);

int generateRandomNumber(int min, int max);

void getRandomEvent(Player* player, Map* map);

void applyPlayerEffect(Player* player, char* effect);

void DrawBlindness(int mapWidth, int mapHeight, int playerX, int playerY);

#endif