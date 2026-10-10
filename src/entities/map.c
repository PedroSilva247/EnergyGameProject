#include <raylib.h>
#include <stdlib.h>
#include "../../include/map.h"
#define N 6



Map* createMap(int width, int height, char* grid) {
	Map* map = (Map*) malloc(sizeof(Map));
	map->width = width;
	map->height = height;
	map->grid = grid;

	return map;
}


int tile = 50;

void DrawMap(Map* map) {
	int startX = 100;
	int startY = 100;
	int currentX = startX;
	int currentY = startY;
	for (int i = 0; i < map->height; i++) {
		for (int j = 0; j < map->width; j++) {
			switch (map->grid[i * map->width + j]) {
				case '#':
					DrawRectangle(currentX, currentY, tile, tile, BLUE);
					break;
			}
			currentX += tile;
		}
		currentX = startX;
		currentY += tile;
	}
}