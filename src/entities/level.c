#include "../../include/map.h"
#include "../../include/player.h"
#include "../../include/level.h"
#include "../../include/gameplay_screen.h"
#include "../../include/config.h"
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

Level* currentLevel;

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

    currentLevel = levelClone;
    
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

void freeLevel(Level* level) {
    if(level == NULL) {
        return;
    }
    freeMap(level->map);
    free(level);
}

bool isValidChar(char c) {
    if(c == '#' ||  c == '?' || c == 'e' || c == 't' || c == 'r' || c == 'f' || c == 'c') {
        return true;
    } else {
        return false;
    }
}

void readLevels() {
    char path[256];
    int n = 1;
    int levelNumber = 1;
    FILE* file;
    Map* map;
    int totalCrystals, finishLines;
    bool levelError;
    char c;
    char cleaner;
    int widthMap, heigthMap, initialPlayerX, initialPlayerY;
    int initialEnergy, maxEnergy, minCrystals;
    while(true) {
        levelError = false;
        totalCrystals = 0;
        finishLines = 0;

        snprintf(path, sizeof(path) * sizeof(char), "resources/levels/level%d.txt", n);
        
        file = fopen(path, "r");

        if(file == NULL) {
            printf("level%d.txt nao encontrado\n", n);
            break;
        }

        
        fscanf(file, "%d %d\n", &widthMap, &heigthMap);
        char* grid = (char*) malloc(widthMap*heigthMap*sizeof(char));

        for(int i = 0; i < heigthMap; i++) {
            for(int j = 0; j < widthMap; j++) {
                c = fgetc(file);
                if(!isValidChar(c)) {
                    levelError = true;
                    break;
                }
                if(c == 'c') {
                    totalCrystals++;
                }
                if(c == 'f') {
                    finishLines++;
                }
                grid[i*widthMap + j] = c;
            }
            if(levelError) {
                break;
            }
            while ((cleaner = fgetc(file)) != '\n' && cleaner != EOF); // jump line
        }
        fscanf(file, "%d %d\n", &initialPlayerX, &initialPlayerY);
        fscanf(file, "%d\n", &initialEnergy);
        fscanf(file, "%d\n", &maxEnergy);
        fscanf(file, "%d", &minCrystals);

        if(totalCrystals < minCrystals || initialEnergy <= 0 || maxEnergy <= 0 || finishLines != 1) {
            levelError = true;
        }


        if(levelError) {
            printf("Erro ao registrar level%d.txt\n", n);
            free(grid);
        } else {
            map = createMap(widthMap, heigthMap, grid, initialPlayerX, initialPlayerY);
            levels[countLevels] = createLevel(map, initialEnergy, maxEnergy, minCrystals, levelNumber);
            countLevels++;
            levelNumber++;
            printf("level%d.txt registrado\n", n);
        }
        n++;
        fclose(file);  
    }

}