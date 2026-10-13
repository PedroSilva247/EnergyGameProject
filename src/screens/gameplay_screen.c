#include <raylib.h>
#include "../../include/gameplay_screen.h"
#include "../../include/map.h"
#include "../../include/player.h"
#define N 6


void DrawGameplayScreen(Map* map, Player *player) {
		DrawMap(map);
		DrawPlayer(player);
}