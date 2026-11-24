#include <raylib.h>
#include <string.h>
#include "../../include/gameplay_screen.h"
#include "../../include/map.h"
#include "../../include/level.h"
#include "../../include/player.h"
#include "../../include/config.h"
#include "../../include/mapElements.h"
#include "../../include/ui.h"
#include "../../include/effects.h"
#define N 6

#define MAX_LEVEL_ENERGY 10
static int confirmingrestart = 0;


void DrawHeader(Player* player, Level* level, int x, int y) {
	DrawEnergy(player, level, x, y);
	DrawCrystalsCounter(player, level, x, y + 30);
	DrawRounds(level, x, y + 60);
}
void DrawEnergy(Player* player, Level* level, int x, int y) {
	DrawRectangleLinesEx((Rectangle) {x, y, windowWidth/6, 24}, 5.0F, BLACK);
	DrawRectangle(x+5, y+5, (windowWidth/6 - 5.0 * 2) * player->energy / level->maxEnergy, 24 - 5 - 5, YELLOW);
	DrawText(TextFormat("ENERGIA: %d", player->energy), x + 30 + windowWidth/6, y, 20, BLACK);
}
void DrawCrystalsCounter(Player* player, Level* level, int x, int y) {
	DrawText(TextFormat("CRISTAIS: %d/%d", player->crystals, level->minCrystals), x, y, 20, BLACK);
}

void DrawRounds(Level * level, int x, int y){
	DrawText(TextFormat("Turnos: %d", level->round), x, y, 20, BLACK);
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

void DrawPlayerEffects(Player* player, Level* level, bool* isPlayerInvisible) {
	if(hasPlayerEffect(player, "blindness")) {
		DrawBlindness(level->map->width, level->map->height, player->x, player->y, player->positionPixel);
	}

	if(hasPlayerEffect(player, "invisibility")) {
		*isPlayerInvisible = true;
	}
}


void DrawGameplayScreen(Level* level, Player* player) {
	int oldX = player->x;
	int oldY = player->y;
	bool isFinishLineOpened = false;

	int panelWidth = windowWidth/1.2;
	int panelHeight = (float)((float)simplePanel.height/(float)simplePanel.width) * panelWidth;
	int panelX = windowWidth/2 - panelWidth/2;
	int panelY = windowHeight/2 - panelHeight/2;

	int panelInlinePadding = panelWidth/((float)simplePanel.width/34);  // o numero é o padding em pixels na imagem em tamanho bruto
	int panelBlockPadding = panelHeight/((float)simplePanel.height/34);	// o numero é o padding em pixels na imagem em tamanho bruto

	int headerX = panelX + panelInlinePadding;
	int headerY = panelY + panelBlockPadding;

	int mapY = headerY + 76 + 20;	// o segundo numero é o espaco entre a terceira linha do header e o mapa
	int mapWidth = panelHeight - (mapY - panelY) - panelBlockPadding;

	bool isPlayerInvisible = false;

	tile = mapWidth / level->map->width;

	if (!confirmingrestart){
		verifyKeyboardGameplay(player, level->map);
		verifyKeyboardScreen();
	}
	
	if (player->x != oldX || player->y != oldY) {
		level->round++;	
	}
	DrawBackground(1);
	DrawBackgroundDarkFilter();


	DrawSimplePanel(panelX, panelY, panelWidth);

	DrawHeader(player, level, headerX, headerY);

	updateMapElements(level, player, &isFinishLineOpened);
	updatePlayer(player);

	DrawMap(level->map, isFinishLineOpened, mapWidth, mapY);
	
	
	DrawRestart();

	DrawPlayerEffects(player, level, &isPlayerInvisible);

	if(!isPlayerInvisible) {
		DrawPlayer(player);
	}

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


