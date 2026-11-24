#include <raylib.h>
#include <string.h>

#include "../../include/effects.h"
#include "../../include/config.h"
#include "../../include/player.h"

#define BLINDNESS_DISTANCE 1

static Texture2D blindnessFadeTex;

void applyPlayerEffect(Player* player, const char* effect) {
    if(player->nEffects < MAX_EFFECTS) {
        strcpy(player->effects[player->nEffects], effect);
        player->nEffects++;
    }
}

bool hasPlayerEffect(Player* player, const char* effect) {
    for(int i = 0; i < player->nEffects; i++) {
        if(strcmp(player->effects[i], effect) == 0) {
            return true;
        }
    }
    return false;
}

void DrawBlindness(int mapWidth, int mapHeight, int playerX, int playerY, Vector2* playerPositionPixel) {
    int currentX = startMapX;
    int currentY = startMapY;

    for(int i = 0; i < mapHeight; i++) {
        for(int j = 0; j < mapWidth; j++) {
            if(!((i <= playerY + BLINDNESS_DISTANCE && i >= playerY - BLINDNESS_DISTANCE) &&
                 (j <= playerX + BLINDNESS_DISTANCE && j >= playerX - BLINDNESS_DISTANCE))) {
                DrawRectangle(currentX, currentY, tile, tile, BLACK);
            }
            currentX += tile;
        }
        currentX = startMapX;
        currentY += tile;
    }

    Rectangle source = { 0, 0, (float)blindnessFadeTex.width, (float)blindnessFadeTex.height }; //altura do png e largura
    Rectangle dest   = { (float)playerPositionPixel->x - (tile * (0.5 + BLINDNESS_DISTANCE)), (float)playerPositionPixel->y - (tile * (0.5 + BLINDNESS_DISTANCE)), (float)tile * (1 + 2*BLINDNESS_DISTANCE), (float)tile * (1 + 2*BLINDNESS_DISTANCE) }; //preencher o tile
    DrawTexturePro(blindnessFadeTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela

}

void LoadEffectsTextures() {
    blindnessFadeTex = LoadTexture("resources/blindness_fade.png");
    SetTextureFilter(blindnessFadeTex, TEXTURE_FILTER_POINT);
}

void UnloadEffectsTextures() {
    UnloadTexture(blindnessFadeTex);
}
