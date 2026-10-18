#include <raylib.h>
#include "../../include/gameplay_screen.h"
#include "../../include/map.h"
#include "../../include/player.h"
#include "../../include/config.h"
#define N 6

#define MAX_LEVEL_ENERGY 10


void DrawHeader(Player* player, Map* map) {
	DrawEnergy(player, map);
	DrawCrystalsCounter(player);
}
void DrawEnergy(Player* player, Map* map) {
	DrawRectangleLinesEx((Rectangle) {10, 10, 5*tile, 0.4*tile}, 5.0F, BLACK);
	DrawRectangle(10+5, 10+5, (5*tile - 5.0 * 2) * player->energy / map->maxEnergy, 0.4*tile - 5 - 5, YELLOW);
	DrawText(TextFormat("ENERGIA: %d", player->energy), 30 + 5*tile, 10, 20, BLACK);
}
void DrawCrystalsCounter(Player* player) {
	DrawText(TextFormat("CRISTAIS: %d", player->crystals), 10, tile, 20, BLACK);
}

void DrawGameplayScreen(Map* map, Player *player) {
		verifyKeyboard(player, map);
		DrawHeader(player, map);
		updateMap(map, player);
		DrawMap(map);
		DrawPlayer(player);
}

