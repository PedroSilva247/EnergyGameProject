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


typedef enum {DIR_UP, DIR_DOWN, DIR_RIGHT, DIR_LEFT};
typedef struct Player {
	int x;
	int y;
    int energy;
    int crystals;                //Cristais do Player
    float radius;
    ControlKeys* controlKeys;
    Vector2* positionPixel;
    Texture2D sprites[4];
    int direction; 
    char effects[MAX_EFFECTS][20];
    int nEffects;
} Player;




void DrawPlayer(Player* player);

Player* createPlayer(int x, int y, int energy, float radius, ControlKeys* controlKeys);

ControlKeys* createControlKeys(int keyUp, int keyLeft, int keyDown, int keyRight);

void updatePlayer(Player* player);

void movePlayer(char axis, int step, Map* map, Player* player);

char verifyPlayerTile(Player* player, Map* map);

void getCrystal(Player* player, Map* map);

void hitTrap(Player* player, Map* map);

void getRecover(Player* player, Level* level);

int generateRandomNumber(int min, int max);

void getRandomEvent(Player* player, Map* map);

bool playerWinLevel(Player* player, Level* level);

#endif