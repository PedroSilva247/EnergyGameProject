#ifndef LEVEL
#define LEVEL

#include <stdbool.h>
#include "map.h"
// #include "gameplay_screen.h"

typedef struct GameplayScreenToDraw GameplayScreenToDraw;

typedef struct Level {
    Map* map;
    int initialEnergy;
    int maxEnergy;
    int round;
    int minCrystals;
    int numLevel;
    bool finishLineSoundPlayed;
} Level;

extern Level* currentLevel;


GameplayScreenToDraw* playLevel(Level* level);

Level* createLevel(Map* map, int initialEnergy, int maxEnergy, int minCrystals, int numLevel);

void freeLevel(Level* level);

void readLevels();

#endif