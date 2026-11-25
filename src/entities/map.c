#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/map.h"
#include "../../include/config.h"
#include "../../include/player.h"
#include "../../include/mapElements.h"
#include "../../include/ui.h"






Map* createMap(int width, int height, char* grid, int initialPlayerX, int initialPlayerY) {
	Map* map = (Map*) malloc(sizeof(Map));
	map->width = width;
	map->height = height;
	map->grid = grid;
	map->initialPlayerX = initialPlayerX;
	map->initialPlayerY = initialPlayerY;

	if(grid[initialPlayerY * width + initialPlayerX] != 'e') {
		printf("Invalid map! The player doesn't spawn on a empty tile.");
	}

	return map;
}


void DrawMapFrame(int width, int x, int y) {
	Rectangle source = { 0, 0, (float)mapFrameTex.width, (float)mapFrameTex.height }; //altura do png e largura
    Rectangle dest   = { (float) x, (float) y, (float) width, (float) width };
    DrawTexturePro(mapFrameTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}


void DrawMap(Map* map, bool isFinishLineOpened, int frameWidth, int y) {
	float mapFrameThickness = 20.0f/540.0f * (float) frameWidth;

	float startMapFrameX = windowWidth/2 - frameWidth/2;
	float startMapFrameY = y;

	
	tile = (float)((frameWidth - mapFrameThickness*2) / map->width);
	
	startMapX = startMapFrameX + mapFrameThickness;
	startMapY = startMapFrameY + mapFrameThickness;
	
	float currentX = (float)startMapX;
	float currentY = (float)startMapY;
	

	for (int i = 0; i < map->height; i++) {
		for (int j = 0; j < map->width; j++) {
			if(map->grid[i * map->width + j] != '#') {
				DrawFloor(currentX, currentY);
			}
			
			switch (map->grid[i * map->width + j]) {
				case '#':
					DrawWall(currentX, currentY);
					break;
				case 'c':
					DrawCrystal(currentX, currentY);
					break;
				case 'f':
					DrawFinishLine(currentX, currentY, isFinishLineOpened);
					break;
				case 't':
					DrawTrap(currentX, currentY);
					break;
				case 'r':
					DrawRecover(currentX, currentY);
					break;
				case '?':
					DrawRandomEvent(currentX, currentY);
					break;
			}
			currentX += tile;
		}
		currentX = startMapX;
		currentY += tile;
	}
	DrawMapFrame(frameWidth, startMapFrameX, startMapFrameY);
}



