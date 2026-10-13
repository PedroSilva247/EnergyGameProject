#include <stdio.h>
#include <raylib.h>
#include <math.h>
#include <stdlib.h>
#include "../../include/gameplay_screen.h"
#include "../../include/map.h"
#include "../../include/player.h"
#define N 6
#define MAX_MAP_SIZE 30








int main() {
	char newGrid[10][10] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', 'e', 'e', 'e', 'e', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', '#', 'e', 'e', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', '#', '#', '#', 'e', '#', 'e', '#', '#'},
		{'#', 'e', '#', 'e', '#', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', 'e', 'e', '#', '#', '#', '#', 'e', '#'},
		{'#', 'e', '#', 'e', 'e', 'e', 'e', '#', 'e', '#'},
		{'#', 'e', '#', '#', '#', 'e', 'e', '#', 'e', '#'},
		{'#', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	};
	Map* map2 = createMap(10, 10, &newGrid[0][0]);

	Player* player1 = createPlayer(1, 1, 10, 10.0f, createControlKeys(KEY_W, KEY_A, KEY_S, KEY_D));
	

    InitWindow(1000, 800, "EnergyGame");

    SetTargetFPS(120);
	while(!WindowShouldClose()) {
		BeginDrawing();

			ClearBackground(RAYWHITE);

			DrawGameplayScreen(map2, player1);

			

		EndDrawing();
    }
    return 0;
}