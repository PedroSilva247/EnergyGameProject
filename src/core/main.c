#include <stdio.h>
#include <raylib.h>
#include <math.h>
#include <stdlib.h>
#include "../../include/gameplay_screen.h"
#include "../../include/map.h"
#include "../../include/player.h"
#include "../../include/level.h"
#include "../../include/mapElements.h"
#define N 6
#define MAX_MAP_SIZE 30




int main() {
    InitWindow(1920, 1080, "EnergyGame");

	LoadCrystalTexture();
	LoadRecoverTexture();
	LoadFloorTexture();
	LoadFinishClosedTexture();
	LoadFinishOpenedTexture();


	char grid1[10][10] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', 'e', 'e', 'e', 'e', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', '#', 'e', 'e', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', '#', '#', '#', 'e', '#', 'e', '#', '#'},
		{'#', 'e', '#', 'c', '#', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', 'e', 'c', '#', '#', '#', '#', 't', '#'},
		{'#', 'e', '#', 'c', 'e', 'e', 'e', '#', 'e', '#'},
		{'#', 'e', '#', '#', '#', 'e', 'e', '#', 'e', '#'},
		{'#', 'e', 'e', 'e', 'r', 'e', 'e', 'e', 'f', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	};

	char grid2[20][20] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'e', 'e', '#', '#', 'e', 't', 'e', 'e', 'r', 'e', 'e', 'e', 't', 'e', 'e', 'e', 'e', 'e', '#'},
    {'#', 'e', 'e', 'e', 'e', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', 'c', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', 'e', 'e', 't', 'e', 'e', 'e', 'r', 'e', 'e', 'e', '#', '#', 'e', 'e', 't', 'e', 'e', 'e', '#'},
    {'#', 'e', '#', '#', '#', '#', '#', '#', '#', '#', 'e', 'e', 'e', 'e', '#', '#', '#', '#', 'e', '#'},
    {'#', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'c', '#'},
    {'#', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'e', 'e', 'e', 'e', 't', 'e', '#', '#', 'e', 'r', 'e', 'e', 'e', 'e', 't', 'e', 'e', 'e', '#'},
    {'#', 'e', '#', '#', '#', '#', 'e', 'e', 'e', 'e', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', 'c', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', 'e', 'e', '#', '#', 'e', 't', 'e', 'e', 'r', 'e', 'e', 'e', 't', 'e', 'e', 'e', 'e', 'e', '#'},
    {'#', 'e', 'e', 'e', 'e', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'c', '#'},
    {'#', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'e', 'e', 't', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 't', 'e', 'e', 'r', 'e', 'e', 'e', 'e', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'f', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};


	Map* map1 = createMap(10, 10, &grid1[0][0], 1, 1);

	Map* map2 = createMap(20, 20, &grid2[0][0], 1, 1);

	Level* level1 = createLevel(map1, 20, 20, 3, 1, "forestTextures");

	Level* level2 = createLevel(map2, 101, 101, 4, 2, "forestTextures");
	//Player* player1 = createPlayer(1, 1, 10, 10.0f, createControlKeys(KEY_W, KEY_A, KEY_S, KEY_D));
	GameplayScreenToDraw* gameplayScreenToDraw = playLevel(level1);

	gameplayScreenToDraw = playLevel(level2);

	

	float unitX;
	float unitY;

    SetTargetFPS(120);
	while(!WindowShouldClose()) {

		unitX = GetWindowScaleDPI().x / 1000;
		unitY = GetWindowScaleDPI().y / 1000;
		
		BeginDrawing();

			ClearBackground(RAYWHITE);
	
			gameplayScreenToDraw->func(gameplayScreenToDraw->level, gameplayScreenToDraw->player);

		EndDrawing();
    }
	UnloadCrystalTexture();
	UnloadRecoverTexture();
	UnloadFloorTexture();
	UnloadFinishClosedTexture();
	UnloadFinishOpenedTexture();
	CloseWindow();
    return 0;
}