#include "../../include/map.h"
#include "../../include/player.h"
#include "../../include/level.h"
#include "../../include/gameplay_screen.h"
#include <raylib.h>
#include <stdlib.h>

GameplayScreenToDraw* playLevel(Level* level) {
    Player* player = createPlayer(level->map->initialPlayerX, level->map->initialPlayerY, level->initialEnergy, 10.0f, createControlKeys(KEY_W, KEY_A, KEY_S, KEY_D));
    GameplayScreenToDraw* gameplayScreenToDraw = (GameplayScreenToDraw*) malloc(sizeof(GameplayScreenToDraw));
    gameplayScreenToDraw->func = DrawGameplayScreen;
    gameplayScreenToDraw->level = level;
    gameplayScreenToDraw->player = player;
    
    return gameplayScreenToDraw;
}

Level* createLevel(Map* map, int initialEnergy, int maxEnergy) {
    Level* level = (Level*) malloc(sizeof(Level));
	level->map = map;
    level->initialEnergy = initialEnergy;
    level->maxEnergy = maxEnergy;

	return level;
}