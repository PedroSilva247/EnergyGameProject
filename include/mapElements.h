#ifndef MAPELEMENTS
#define MAPELEMENTS

#include <raylib.h>
#include <stdlib.h>

typedef struct Map Map;
typedef struct Player Player;
typedef struct Level Level;

void DrawCrystal(int x, int y);

void LoadFinishClosedTexture(char folder[30]);

void LoadFinishOpenedTexture(char folder[30]);

void DrawFinishLine(int x, int y, bool isFinishLineOpened);

void UnloadFinishOpenedTexture(void);

void UnloadFinishClosedTexture(void);

void DrawTrap(int x, int y);

void LoadCrystalTexture(char folder[30]);

void UnloadCrystalTexture(void);

void LoadRecoverTexture(char folder[30]);

void UnloadRecoverTexture(void);

void DrawRecover(int x, int y);

void updateMapElements(Level* level, Player* player, bool* isFinishLineOpened);

void DrawFloor(int currentX, int currentY);

void LoadFloorTexture(char folder[30]);
void UnloadFloorTexture(void);

void DrawWall(int currentX, int currentY);

void LoadWallTexture(char folder[30]);

void UnloadWallTexture(void);

void DrawTrap(int currentX, int currentY);

void LoadTrapTexture(char folder[30]);

void UnloadTrapTexture(void);

#endif
