#ifndef MAP_ELEMENTS
#define MAP_ELEMENTS

#include <raylib.h>
#include <stdlib.h>

typedef struct Map Map;
typedef struct Player Player;
typedef struct Level Level;

void DrawCrystal(float x, float y);
void DrawWall(float x, float y);
void DrawFinishLine(float x, float y, bool isFinishLineOpened);
void DrawFloor(float x, float y);
void DrawTrap(float x, float y);
void DrawRecover(float x, float y);
void DrawRandomEvent(float x, float y);

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
