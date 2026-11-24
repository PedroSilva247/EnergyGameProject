#ifndef MAP_ELEMENTS
#define MAP_ELEMENTS

#include <raylib.h>
#include <stdlib.h>

typedef struct Map Map;
typedef struct Player Player;
typedef struct Level Level;

void DrawCrystal(int x, int y);
void DrawWall(int x, int y);
void DrawFinishLine(int x, int y, bool isFinishLineOpened);
void DrawFloor(int x, int y);
void DrawTrap(int x, int y);
void DrawTrap(int x, int y);
void DrawRecover(int x, int y);
void DrawRandomEvent(int x, int y);

void LoadMapTexturePack(char folder[30]);
void UnloadMapTextures(void);

void UnloadFinishOpenedTexture(void);
void UnloadFinishClosedTexture(void);
void UnloadCrystalTexture(void);
void UnloadRecoverTexture(void);
void UnloadTrapTexture(void);
void UnloadFloorTexture(void);
void UnloadWallTexture(void);





void updateMapElements(Level* level, Player* player, bool* isFinishLineOpened);
#endif
