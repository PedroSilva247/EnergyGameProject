#include <raylib.h>
#include <string.h>

#include "../../include/effects.h"
#include "../../include/config.h"
#include "../../include/player.h"

#define BLINDNESS_DISTANCE 3

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
    float currentX = (float)startMapX;
    float currentY = (float)startMapY;

    for(int i = 0; i < mapHeight; i++) {
        for(int j = 0; j < mapWidth; j++) {
            if(!((i <= playerY + BLINDNESS_DISTANCE && i >= playerY - BLINDNESS_DISTANCE) &&
                 (j <= playerX + BLINDNESS_DISTANCE && j >= playerX - BLINDNESS_DISTANCE))) {
                DrawRectangleRec((Rectangle){currentX, currentY, tile, tile}, BLACK);
            }
            currentX += tile;
        }
        currentX = startMapX;
        currentY += tile;
    }

    float sourceWidth = blindnessFadeTex.width, sourceHeigth = blindnessFadeTex.height, sourceX = 0, sourceY = 0;
    float destWidth = (float)tile * (1 + 2*BLINDNESS_DISTANCE), destHeigth = (float)tile * (1 + 2*BLINDNESS_DISTANCE), destX = (float)playerPositionPixel->x - (tile * (0.5 + BLINDNESS_DISTANCE)), destY = (float)playerPositionPixel->y - (tile * (0.5 + BLINDNESS_DISTANCE));

    float sourceTile = blindnessFadeTex.width / (BLINDNESS_DISTANCE*2 + 1);
    if(playerY < BLINDNESS_DISTANCE) {
        sourceHeigth = (BLINDNESS_DISTANCE + 1 + playerY)*sourceTile;
        sourceY = blindnessFadeTex.height - sourceHeigth;
        destHeigth = (float)tile * (BLINDNESS_DISTANCE + 1 + playerY);
        destY = (float)playerPositionPixel->y - (tile * (0.5 + playerY));
    }
    if(playerY > mapHeight - 1 - BLINDNESS_DISTANCE) {
        sourceHeigth = (BLINDNESS_DISTANCE + 1 + (mapHeight - 1 - playerY))*sourceTile;
        destHeigth = (float)tile * (BLINDNESS_DISTANCE + 1 + (mapHeight - 1 - playerY));
    }
    if(playerX < BLINDNESS_DISTANCE) {
        sourceWidth = (BLINDNESS_DISTANCE + 1 + playerX)*sourceTile;
        sourceX = blindnessFadeTex.width - sourceWidth;
        destWidth = (float)tile * (BLINDNESS_DISTANCE + 1 + playerX);
        destX = (float)playerPositionPixel->x - (tile * (0.5 + playerX));
    }
    if(playerX > mapWidth - 1 - BLINDNESS_DISTANCE) {
        sourceWidth = (BLINDNESS_DISTANCE + 1 + (mapWidth - 1 - playerX))*sourceTile;
        destWidth = (float)tile * (BLINDNESS_DISTANCE + 1 + (mapWidth - 1 - playerX));
    }


    Rectangle source = { sourceX, sourceY, (float)sourceWidth, (float)sourceHeigth }; //altura do png e largura
    Rectangle dest   = { destX, destY, destWidth, destHeigth }; //preencher o tile
    DrawTexturePro(blindnessFadeTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela

}

void LoadEffectsTextures() {
    blindnessFadeTex = LoadTexture("resources/blindness_fade.png");
    SetTextureFilter(blindnessFadeTex, TEXTURE_FILTER_POINT);
}

void UnloadEffectsTextures() {
    UnloadTexture(blindnessFadeTex);
}
