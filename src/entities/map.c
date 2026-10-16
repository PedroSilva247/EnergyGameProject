#include <raylib.h>
#include <stdlib.h>
#include "../../include/map.h"
#include "../../include/config.h"
#include "../../include/mapElements.h"


Map* createMap(int width, int height, char* grid) {
	Map* map = (Map*) malloc(sizeof(Map));
	map->width = width;
	map->height = height;
	map->grid = grid;

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