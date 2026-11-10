#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../include/mapElements.h"
#include "../../include/config.h"
#include "../../include/map.h"
#include "../../include/player.h"
#include "../../include/level.h"

static Texture2D crystalTex;

static Texture2D recoverTex;

static Texture2D finishOpenedTex;
static Texture2D finishClosedTex;
static Texture2D floorTex;
static Texture2D wallTex;
static Texture2D trapTex;

void LoadTexturePack(char folder[30]) {
    char path[256];

    snprintf(path, sizeof path, "resources/%s/crystal.png", folder);
    crystalTex = LoadTexture(path);
    SetTextureFilter(crystalTex, TEXTURE_FILTER_POINT);

    snprintf(path, sizeof path, "resources/%s/recover.png", folder);
    recoverTex = LoadTexture(path);
    SetTextureFilter(recoverTex, TEXTURE_FILTER_POINT); 

    snprintf(path, sizeof path, "resources/%s/exit_open.png", folder);
    finishOpenedTex = LoadTexture(path);
    SetTextureFilter(finishOpenedTex, TEXTURE_FILTER_POINT);

    snprintf(path, sizeof path, "resources/%s/exit_closed.png", folder);
    finishClosedTex = LoadTexture(path);
    SetTextureFilter(finishClosedTex, TEXTURE_FILTER_POINT);

    snprintf(path, sizeof path, "resources/%s/floor.png", folder);
    floorTex = LoadTexture(path);
    SetTextureFilter(floorTex, TEXTURE_FILTER_POINT);

    snprintf(path, sizeof path, "resources/%s/wall.png", folder);
    wallTex = LoadTexture(path);
    SetTextureFilter(wallTex, TEXTURE_FILTER_POINT);

    snprintf(path, sizeof path, "resources/%s/trap.png", folder);
    trapTex = LoadTexture(path);
    SetTextureFilter(trapTex, TEXTURE_FILTER_POINT);
}

void UnloadTextures(void) {
    UnloadTexture(crystalTex);
    UnloadTexture(recoverTex);
    UnloadTexture(finishOpenedTex);
    UnloadTexture(finishClosedTex);
    UnloadTexture(floorTex);
    UnloadTexture(wallTex);
    UnloadTexture(trapTex);
}

void DrawCrystal(int x, int y) {

    Rectangle source = { 0, 0, (float)crystalTex.width, (float)crystalTex.height }; //altura do png e largura
    Rectangle dest   = { (float)x, (float)y, (float)tile, (float)tile }; //preencher o tile
    DrawTexturePro(crystalTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void DrawRecover(int x, int y) {
    Rectangle source = { 0, 0, (float)recoverTex.width, (float)recoverTex.height };
    Rectangle dest   = { (float)x, (float)y, (float)tile, (float)tile };
    DrawTexturePro(recoverTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); 
}



void DrawFinishLine(int x, int y, bool isFinishLineOpened) {
    Texture2D finishLineTex;

    if(isFinishLineOpened) {
        finishLineTex = finishOpenedTex;
    } else {
        finishLineTex = finishClosedTex;
    }
    Rectangle source = { 0, 0, (float)finishLineTex.width, (float)finishLineTex.height };
    Rectangle dest   = { (float)x, (float)y, (float)tile, (float)tile }; 
    DrawTexturePro(finishLineTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE);
        
}

void DrawFloor(int currentX, int currentY) {
    Rectangle source = { 0, 0, (float)floorTex.width, (float)floorTex.height }; //altura do png e largura
    Rectangle dest   = { (float)currentX, (float)currentY, (float)tile, (float)tile }; //preencher o tile
    DrawTexturePro(floorTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void DrawWall(int currentX, int currentY) {
    Rectangle source = { 0, 0, (float)wallTex.width, (float)wallTex.height }; //altura do png e largura
    Rectangle dest   = { (float)currentX, (float)currentY, (float)tile, (float)tile }; //preencher o tile
    DrawTexturePro(wallTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void DrawTrap(int currentX, int currentY) {
    Rectangle source = { 0, 0, (float)trapTex.width, (float)trapTex.height }; //altura do png e largura
    Rectangle dest   = { (float)currentX, (float)currentY, (float)tile, (float)tile }; //preencher o tile
    DrawTexturePro(trapTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void updateMapElements(Level* level, Player* player, bool* isFinishLineOpened) {
    if(player->crystals >= level->minCrystals) {
        *isFinishLineOpened = true;
    }

	if(verifyPlayerTile(player, level->map) == 'c') {
		getCrystal(player, level->map);
	}
	if(verifyPlayerTile(player, level->map) == 't') {
		hitTrap(player, level->map);
	}
    if(verifyPlayerTile(player, level->map) == 'r') {
		getRecover(player, level);
	}
}



