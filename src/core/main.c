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
    InitWindow(1000, 800, "EnergyGame");

	LoadCrystalTexture();
	LoadRecoverTexture();

	char newGrid[10][10] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', 'e', 'e', 'e', 'e', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', '#', 'e', 'e', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', '#', '#', '#', 'e', '#', 'e', '#', '#'},
		{'#', 'e', '#', 'c', '#', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', 'e', 'e', '#', '#', '#', '#', 't', '#'},
		{'#', 'e', '#', 'e', 'e', 'e', 'e', '#', 'e', '#'},
		{'#', 'e', '#', '#', '#', 'e', 'e', '#', 'e', '#'},
		{'#', 'e', 'e', 'e', 'r', 'e', 'e', 'e', 'f', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	};


	Map* map2 = createMap(10, 10, &newGrid[0][0], 1, 1);

	Level* level1 = createLevel(map2, 20, 20, 0);

	Level* level2 = createLevel(map2, 8, 10, 0);
	//Player* player1 = createPlayer(1, 1, 10, 10.0f, createControlKeys(KEY_W, KEY_A, KEY_S, KEY_D));
	GameplayScreenToDraw* gameplayScreenToDraw = playLevel(level1);

	

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
	CloseWindow();
    return 0;
}