#ifndef LEVEL
#define LEVEL

#include "map.h"
// #include "gameplay_screen.h"

typedef struct GameplayScreenToDraw GameplayScreenToDraw;

typedef struct Level {
    Map* map;
    int initialEnergy;
    int maxEnergy;
    int round;
} Level;

GameplayScreenToDraw* playLevel(Level* level);

Level* createLevel(Map* map, int initialEnergy, int maxEnergy, int round);

#endif