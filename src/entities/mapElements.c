#include <raylib.h>
#include <stdlib.h>
#include <string.h>
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


void LoadCrystalTexture(void){
    crystalTex = LoadTexture("resources/crystal.png"); //Faz o load da textura do cristal
    SetTextureFilter(crystalTex, TEXTURE_FILTER_POINT); //adapta pra pixel art
}

void UnloadCrystalTexture(void)
{
    UnloadTexture(crystalTex);
}

void DrawCrystal(int x, int y) {

    Rectangle source = { 0, 0, (float)crystalTex.width, (float)crystalTex.height }; //altura do png e largura
    Rectangle dest   = { (float)x, (float)y, (float)tile, (float)tile }; //preencher o tile
    DrawTexturePro(crystalTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void LoadRecoverTexture(void){
    recoverTex = LoadTexture("resources/recover.png");
    SetTextureFilter(recoverTex, TEXTURE_FILTER_POINT); 
}

void UnloadRecoverTexture(void){
    UnloadTexture(recoverTex);
}
void DrawRecover(int x, int y) {
    Rectangle source = { 0, 0, (float)recoverTex.width, (float)recoverTex.height };
    Rectangle dest   = { (float)x, (float)y, (float)tile, (float)tile };
    DrawTexturePro(recoverTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); 
}



void LoadFinishOpenedTexture(void)
{
    finishOpenedTex = LoadTexture("resources/finishOpened.png"); //Faz o load da textura do alcapao aberto
    SetTextureFilter(finishOpenedTex, TEXTURE_FILTER_POINT); //adapta pra pixel art
}

void LoadFinishClosedTexture(void)
{
    finishClosedTex = LoadTexture("resources/finishClosed.png"); //Faz o load da textura do alcapao fechado
    SetTextureFilter(finishClosedTex, TEXTURE_FILTER_POINT); //adapta pra pixel art
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

void UnloadFinishOpenedTexture(void)
{
    UnloadTexture(finishOpenedTex);
}

void UnloadFinishClosedTexture(void)
{
    UnloadTexture(finishClosedTex);
}

// ----------- FLOOR ----------------


void DrawFloor(int currentX, int currentY) {
    Rectangle source = { 0, 0, (float)floorTex.width, (float)floorTex.height }; //altura do png e largura
    Rectangle dest   = { (float)currentX, (float)currentY, (float)tile, (float)tile }; //preencher o tile
    DrawTexturePro(floorTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void LoadFloorTexture(void){
    floorTex = LoadTexture("resources/floorTexture.png"); //Faz o load da textura do cristal
    SetTextureFilter(floorTex, TEXTURE_FILTER_POINT); //adapta pra pixel art
}

void UnloadFloorTexture(void){
    UnloadTexture(floorTex);
}

void DrawTrap(int x,int y) {
    DrawRectangle(
        x + tile/2 - tile/2/2, // x + metade do tile - metade do tamanho do cristal
        y + tile/2 - tile/2/2, // Declaracao do tamanho do crystal
        tile * 0.5,
        tile * 0.5,
        BROWN
    );
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

