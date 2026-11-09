#ifndef MAP
#define MAP

#include <raylib.h>



typedef struct Map {
	int width;
	int height;
	char* grid;
	int initialPlayerX;
	int initialPlayerY;
} Map;

void DrawMap(Map* map, bool isFinishLineOpened);

Map* createMap(int width, int height, char* grid, int initialPlayerX, int initialPlayerY);





#endif