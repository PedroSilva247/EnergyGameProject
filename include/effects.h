#ifndef EFFECTS
#define EFFECTS

#include <raylib.h>

#include "player.h"

void applyPlayerEffect(Player* player, const char* effect);
bool hasPlayerEffect(Player* player, const char* effect);
void DrawBlindness(int mapWidth, int mapHeight, int playerX, int playerY, Vector2* playerPositionPixel);

void LoadEffectsTextures();

void UnloadEffectsTextures();


#endif
