#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/map.h"
#include "../../include/config.h"
#include "../../include/player.h"
#include "../../include/mapElements.h"


Map* createMap(int width, int height, char* grid, int maxEnergy, int initialPlayerX, int initialPlayerY) {
	Map* map = (Map*) malloc(sizeof(Map));
	map->width = width;
	map->height = height;
	map->grid = grid;
	map->maxEnergy = maxEnergy;
	map->initialPlayerX = initialPlayerX;
	map->initialPlayerY = initialPlayerY;

	if(grid[initialPlayerY * width + initialPlayerX] != 'e') {
		printf("Invalid map! The player doesn't spawn on a empty tile.");
	}

	return map;
}




void DrawMap(Map* map) {
	
	int currentX = startMapX;
	int currentY = startMapY;
	for (int i = 0; i < map->height; i++) {
		for (int j = 0; j < map->width; j++) {
			switch (map->grid[i * map->width + j]) {
				case '#':
					DrawRectangle(currentX, currentY, tile, tile, BLUE);
					break;
				case 'c':
					DrawCrystal(currentX, currentY);
					break;
				case 'f':
					DrawFinishLine(currentX, currentY);
					break;
				case 't':
					DrawTrap(currentX, currentY);
					break;
				case 'r':
					DrawRecover(currentX, currentY);
					break;
			}
			currentX += tile;
		}
		currentX = startMapX;
		currentY += tile;
	}
}



void updateMap(Map* map, Player* player) {
	if(verifyPlayerTile(player, map) == 'c') {
		getCrystal(player, map);
	}
}