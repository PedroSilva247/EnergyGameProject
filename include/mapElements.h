#ifndef MAPELEMENTS
#define MAPELEMENTS

#include <raylib.h>
#include <stdlib.h>

typedef struct Map Map;
typedef struct Player Player;
typedef struct Level Level;

void DrawCrystal(int x, int y);

void DrawFinishLine(int x, int y);

void DrawTrap(int x, int y);

void DrawRecover(int x, int y);

void updateMapElements(Level* level, Player* player);

void DrawPlayerPortrait()

#endif
