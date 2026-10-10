#include <stdio.h>
#include <raylib.h>
#include <math.h>
#include <stdlib.h>
#include "../../include/gameplay_screen.h"
#include "../../include/map.h"
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
	
	
    InitWindow(1000, 800, "EnergyGame");

    SetTargetFPS(120);
	while(!WindowShouldClose()) {
		BeginDrawing();

			ClearBackground(RAYWHITE);

			DrawGameplayScreen(map2);

		EndDrawing();
    }
    return 0;
}