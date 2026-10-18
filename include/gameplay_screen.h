#ifndef GAMEPLAY_SCREEN
#define GAMEPLAY_SCREEN
#define N 6

#include "map.h"
#include "player.h"

void DrawGameplayScreen(Map* map, Player* player);
void DrawHeader(Player* player, Map* map);
void DrawEnergy(Player* player, Map* map);
void DrawCrystalsCounter(Player* player);

#endif