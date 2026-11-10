#ifndef MAPELEMENTS
#define MAPELEMENTS

#include <raylib.h>
#include <stdlib.h>

typedef struct Map Map;
typedef struct Player Player;
typedef struct Level Level;

void DrawCrystal(int x, int y);
void DrawWall(int currentX, int currentY);
void DrawFinishLine(int x, int y, bool isFinishLineOpened);
void DrawFloor(int currentX, int currentY);
void DrawTrap(int x, int y);
void DrawTrap(int currentX, int currentY);
void DrawRecover(int x, int y);

void LoadTexturePack(char folder[30]);
void UnloadTextures(void);

void UnloadFinishOpenedTexture(void);
void UnloadFinishClosedTexture(void);
void UnloadCrystalTexture(void);
void UnloadRecoverTexture(void);
void UnloadTrapTexture(void);
void UnloadFloorTexture(void);
void UnloadWallTexture(void);





void updateMapElements(Level* level, Player* player, bool* isFinishLineOpened);
#endif
