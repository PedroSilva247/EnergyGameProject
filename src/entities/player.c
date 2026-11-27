#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "../../include/player.h"
#include "../../include/config.h"
#include "../../include/map.h"
#include "../../include/level.h"
#include "../../include/gameplay_screen.h"
#include "../../include/mapElements.h"
#include "../../include/effects.h"
#include "../../include/sound.h"


Player* createPlayer(int x, int y, int energy, float radius, ControlKeys* controlKeys) {
    Player* player = (Player*) malloc(sizeof(Player));
    Vector2* positionPixel = (Vector2*) malloc(sizeof(Vector2));
    player->x = x;
    player->y = y;
    player->energy = energy;
    player->crystals = 0;
    player->radius = radius;
    player->controlKeys = controlKeys;
    player->sprites[DIR_DOWN]= LoadTexture("resources/player_pokemon/player_down.png");
    player->sprites[DIR_UP]= LoadTexture("resources/player_pokemon/player_up.png");
    player->sprites[DIR_RIGHT]= LoadTexture("resources/player_pokemon/player_right.png");
    player->sprites[DIR_LEFT]= LoadTexture("resources/player_pokemon/player_left.png");
    for (int i =0; i < 4; i++) SetTextureFilter(player->sprites[i], TEXTURE_FILTER_POINT);
    player->direction = DIR_DOWN;
    positionPixel->x = startMapX + (x * tile) + (tile / 2);
    positionPixel->y = startMapY + (y * tile) + (tile / 2);
    
    player->positionPixel = positionPixel;
    
    for(int i = 0; i < MAX_EFFECTS; i++) {
        strcpy(player->effects[i], "");
    }
    player->nEffects = 0;

    return player;
}

ControlKeys* createControlKeys(int keyUp, int keyLeft, int keyDown, int keyRight) {
    ControlKeys* controlKeys = (ControlKeys*) malloc(sizeof(ControlKeys));
    controlKeys->keyUp = keyUp;
    controlKeys->keyLeft = keyLeft;
    controlKeys->keyDown = keyDown;
    controlKeys->keyRight = keyRight;

    return controlKeys;
}

void DrawPlayer(Player* player) {
    Texture2D tex = player->sprites[player->direction];
    Rectangle source = { 0, 0, (float)tex.width, (float)tex.height };
    Rectangle dest = {
        player->positionPixel->x - tile / 2.0f,
        player->positionPixel->y - tile / 2.0f,
        (float)tile, (float)tile
    };
    DrawTexturePro(tex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE);
}





int isWalkable(Map* map, int x, int y) {
    if(x < 0 || x > map->width || y < 0 || y > map->height) {
        return 0;
    }
    if(map->grid[y*map->width + x] == '#') {
        return 0;
    }
    return 1;
}

void movePlayer(char axis, int step, Map* map, Player* player) {
    int x = player->x;
    int y = player->y;

    if(player->energy > 0) {
        if(axis == 'x') {
            if(isWalkable(map, x + step, y)) {
                player->x += step;
            } else {
                //DrawText("Obstaculo no Caminho", ) //colocar as coordenadas
                return;
            }
        } else if(axis == 'y') {
            if(isWalkable(map, x, y + step)) {
                player->y += step;
            } else {
                //DrawText("Obstaculo no Caminho", ) //colocar as coordenadas
                return;
            }
        }
        player->energy--;
    }

    if(player->energy <= 0) {
        finishGame();
    }
    
}

void verifyKeyboardGameplay(Player* player, Map* map) {
    if (IsKeyPressed(player->controlKeys->keyDown)){
        movePlayer('y', 1, map, player);
        player->direction = DIR_DOWN;
    }
    if (IsKeyPressed(player->controlKeys->keyUp)){
        movePlayer('y', -1, map, player);
        player->direction = DIR_UP;
    }
    if (IsKeyPressed(player->controlKeys->keyRight)){
        movePlayer('x', 1, map, player);
        player->direction = DIR_RIGHT;
    }
    if (IsKeyPressed(player->controlKeys->keyLeft)){
        movePlayer('x', -1, map, player);
        player->direction = DIR_LEFT;
    }  
}

char verifyPlayerTile(Player* player, Map* map) {
    return map->grid[player->y*map->width + player->x];
}

void getCrystal(Player* player, Map* map) {
    player->crystals ++;
    map->grid[player->y*map->width + player->x] = 'e';
    PlaySound(crystalSound);
}

void hitTrap(Player* player, Map* map) {
    player->energy -= trapDamage;
    if(player->energy < 0) {
        player->energy = 0;
    }
    map->grid[player->y*map->width + player->x] = 'e';
}

void getRecover(Player* player, Level* level) {
    player->energy += recoverEnergy;
    PlaySound(recoverSound);
    if(player->energy > level->maxEnergy) {
        if(recoverHealsMoreThanMax) {
            level->maxEnergy = player->energy;
        } else {
            player->energy = level->maxEnergy;
        }
    }
    level->map->grid[player->y*level->map->width + player->x] = 'e';
}

void updatePlayer(Player* player) {
    player->positionPixel->x = startMapX + (player->x * tile) + (tile / 2);
    player->positionPixel->y = startMapY + (player->y * tile) + (tile / 2);
}

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

void getRandomEvent(Player* player, Map* map) {
    switch (generateRandomNumber(0, 1)) {
        case 0:
            applyPlayerEffect(player, "blindness");
            break;
        case 1:
            applyPlayerEffect(player, "invisibility");
            break;
    }
    map->grid[player->y*map->width + player->x] = 'e';
}

bool playerWinLevel(Player* player, Level* level) {
    return player->crystals >= level->minCrystals && level->map->grid[player->y * level->map->width + player->x] == 'f'; 
}

