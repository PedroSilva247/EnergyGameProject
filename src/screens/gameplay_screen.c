#include <raylib.h>
#include "../../include/gameplay_screen.h"
#include "../../include/map.h"
#include "../../include/level.h"
#include "../../include/player.h"
#include "../../include/config.h"
#include "../../include/mapElements.h"
#define N 6

#define MAX_LEVEL_ENERGY 10
static int confirmingrestart = 0;


void DrawHeader(Player* player, Level* level) {
	DrawEnergy(player, level);
	DrawCrystalsCounter(player, level);
	DrawRounds(level);
}
void DrawEnergy(Player* player, Level* level) {
	DrawRectangleLinesEx((Rectangle) {10, 10, 5*tile, 0.4*tile}, 5.0F, BLACK);
	DrawRectangle(10+5, 10+5, (5*tile - 5.0 * 2) * player->energy / level->maxEnergy, 0.4*tile - 5 - 5, YELLOW);
	DrawText(TextFormat("ENERGIA: %d", player->energy), 30 + 5*tile, 10, 20, BLACK);
}
void DrawCrystalsCounter(Player* player, Level* level) {
	DrawText(TextFormat("CRISTAIS: %d/%d", player->crystals, level->minCrystals), 10, tile, 20, BLACK);
}

void DrawRounds(Level * level){
	DrawText(TextFormat("Turnos: %d", level ->round), 10, 1.5 * tile, 20, BLACK);
}

void DrawRestart(void) {
	DrawText("Reiniciar [R]", 10, GetScreenHeight() - 30, 20, BLACK);
}

void verifyKeyboardScreen(void) {
	if (IsKeyPressed(KEY_R)) {
		confirmingrestart = 1;
	}
}

void DrawRestartScreen(void) {
	int cx = GetScreenWidth() / 2;
	int cy = GetScreenHeight() / 2;

	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(GRAY, 0.6f));                   // fundo translucido
	DrawRectangle(cx - 4*tile, cy - 2*tile, 8*tile, 4*tile, RAYWHITE);                            // caixa
	DrawRectangleLinesEx((Rectangle) {cx - 4*tile, cy - 2*tile, 8*tile, 4*tile}, 5.0f, BLACK);  
	DrawRectangle(cx - 7*tile/2, cy + tile/2, 3*tile, tile, LIGHTGRAY);                           // botao Sim
	DrawRectangleLinesEx((Rectangle) {cx - 7*tile/2, cy + tile/2, 3*tile, tile}, 5.0f, BLACK);    
	DrawRectangle(cx + tile/2, cy + tile/2, 3*tile, tile, LIGHTGRAY);                             // botao Nao
	DrawRectangleLinesEx((Rectangle) {cx + tile/2, cy + tile/2, 3*tile, tile}, 5.0f, BLACK);      

	DrawText("Reiniciar a fase?", cx - MeasureText("Reiniciar a fase?", 30) / 2, cy - 3*tile/2, 30, BLACK);
	DrawText("Sim [S]", cx - 2*tile - MeasureText("Sim [S]", 20) / 2, cy + tile/2 + (tile - 20) / 2, 20, BLACK);
	DrawText("Nao [N]", cx + 2*tile - MeasureText("Nao [N]", 20) / 2, cy + tile/2 + (tile - 20) / 2, 20, BLACK);
}

void DrawGameplayScreen(Level* level, Player* player) {
	int oldX = player->x;
	int oldY = player->y;
	bool isFinishLineOpened = false;

	if (!confirmingrestart){
		verifyKeyboardGameplay(player, level->map);
		verifyKeyboardScreen();
	}




	if (player->x != oldX || player->y != oldY)
	{
		level->round++;	
	}
	DrawHeader(player, level);
	updateMapElements(level, player, &isFinishLineOpened);
	updatePlayer(player);
	DrawMap(level->map, isFinishLineOpened);
	DrawPlayer(player);
	DrawRestart();

	if (confirmingrestart){
		DrawRestartScreen();
		if (IsKeyPressed(KEY_S)){
			restartRequested = 1;
			confirmingrestart = 0;
		}
		if (IsKeyPressed(KEY_N)){
			confirmingrestart = 0;
		}
	}
}


