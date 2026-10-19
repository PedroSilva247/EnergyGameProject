#ifndef MAP
#define MAP

typedef struct Player Player;

typedef struct Map {
	int width;
	int height;
	char* grid;
	int initialPlayerX;
	int initialPlayerY;
} Map;

void DrawMap(Map* map);

Map* createMap(int width, int height, char* grid, int initialPlayerX, int initialPlayerY);

void updateMap(Map* map, Player* player);

#endif