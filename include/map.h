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

void DrawMap(Map* map, bool isFinishLineOpened, int width, int y);

Map* createMap(int width, int height, char* grid, int initialPlayerX, int initialPlayerY);

void freeMap(Map* map);



#endif