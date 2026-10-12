#ifndef MAP
#define MAP

typedef struct {
	int width;
	int height;
	char* grid;
} Map;

void DrawMap(Map* map);

Map* createMap(int width, int height, char* grid);

#endif