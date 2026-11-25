#include "../../include/map.h"
#include "../../include/player.h"
#include "../../include/level.h"
#include "../../include/gameplay_screen.h"
#include <raylib.h>
#include <stdlib.h>

GameplayScreenToDraw* playLevel(Level* level) {
    Player* player = createPlayer(level->map->initialPlayerX, level->map->initialPlayerY, level->initialEnergy, 10.0f, createControlKeys(KEY_W, KEY_A, KEY_S, KEY_D));
    char* gridClone = (char*) malloc(level->map->width*level->map->height*sizeof(char));
    for(int i = 0; i < level->map->height; i++) {
        for(int j = 0; j < level->map->width; j++) {
            gridClone[i*level->map->width + j] = level->map->grid[i*level->map->width + j];
        }
    }
    Map* mapClone = createMap(level->map->width, level->map->height, gridClone, level->map->initialPlayerX, level->map->initialPlayerY);
    Level* levelClone = createLevel(mapClone, level->initialEnergy, level->maxEnergy, level->minCrystals, level->numLevel);
    GameplayScreenToDraw* gameplayScreenToDraw = (GameplayScreenToDraw*) malloc(sizeof(GameplayScreenToDraw));
    gameplayScreenToDraw->func = DrawGameplayScreen;
    gameplayScreenToDraw->level = levelClone;
    gameplayScreenToDraw->player = player;
    
    return gameplayScreenToDraw;
}

Level* createLevel(Map* map, int initialEnergy, int maxEnergy, int minCrystals, int numLevel) {
    Level* level = (Level*) malloc(sizeof(Level));
	level->map = map;
    level->initialEnergy = initialEnergy;
    level->maxEnergy = maxEnergy;
    level->round = 0;
    level->minCrystals = minCrystals;
    level->numLevel = numLevel;

	return level;
}