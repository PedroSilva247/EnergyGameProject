#ifndef PLAYER
#define PLAYER

typedef struct {
    int keyUp, keyDown, keyLeft, keyRight;
} ControlKeys;

typedef struct {
	int x;
	int y;
    int energy;
    float radius;
    ControlKeys* controlKeys;
} Player;




void DrawPlayer(Player* player);

Player* createPlayer(int x, int y, int energy, float radius, ControlKeys* controlKeys);

ControlKeys* createControlKeys(int keyUp, int keyLeft, int keyDown, int keyRight);

void updatePlayer(Player* player);

#endif