#include <raylib.h>
#include "../../include/gameplay_screen.h"
#include "../../include/map.h"
#include "../../include/player.h"
#include "../../include/config.h"
#define N 6

#define MAX_LEVEL_ENERGY 10


void DrawHeader(Player* player) {
	DrawEnergy(player);
}
void DrawEnergy(Player* player){
	DrawText(TextFormat("ENERGIA: %d", player->energy), 30 + 5*tile, 10, 20, BLACK);
	DrawRectangleLinesEx((Rectangle) {10, 10, 5*tile, 0.4*tile}, 5.0F, BLACK);
	DrawRectangle(10+5, 10+5, 5*tile * player->energy / MAX_LEVEL_ENERGY, 0.4*tile - 5 - 5, YELLOW);

}

void DrawGameplayScreen(Map* map, Player *player) {
		verifyKeyboard(player, map);
		DrawHeader(player);
		DrawMap(map);
		DrawPlayer(player);
}

