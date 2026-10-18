#ifndef MAP
#define MAP

typedef struct Player Player;

typedef struct {
	int width;
	int height;
	char* grid;
	int maxEnergy;
	int initialPlayerX;
	int initialPlayerY;
} Map;

void DrawMap(Map* map);

Map* createMap(int width, int height, char* grid, int initialEnergy, int initialPlayerX, int initialPlayerY);

void updateMap(Map* map, Player* player);

#endif