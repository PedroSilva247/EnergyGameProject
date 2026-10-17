#include "map.h"
#include "player.h"

#ifndef GAMEPLAY_SCREEN
#define GAMEPLAY_SCREEN
#define N 6

void DrawGameplayScreen(Map* map, Player* player);
void DrawHeader(Player* player);
void DrawEnergy(Player* player);

#endif