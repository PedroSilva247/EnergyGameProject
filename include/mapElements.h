#ifndef MAPELEMENTS
#define MAPELEMENTS

#include <raylib.h>
#include <stdlib.h>

typedef struct Map Map;
typedef struct Player Player;
typedef struct Level Level;

void DrawCrystal(int x, int y);

void LoadFinishClosedTexture(void);

void LoadFinishOpenedTexture(void);

void DrawFinishLine(int x, int y, bool isFinishLineOpened);

void UnloadFinishOpenedTexture(void);

void UnloadFinishClosedTexture(void);

void DrawTrap(int x, int y);

void LoadCrystalTexture(void);

void UnloadCrystalTexture(void);

void LoadRecoverTexture(void);

void UnloadRecoverTexture(void);

void DrawRecover(int x, int y);

void updateMapElements(Level* level, Player* player, bool* isFinishLineOpened);

void DrawFloor(int currentX, int currentY);

void LoadFloorTexture(void);
void UnloadFloorTexture(void);
#endif
