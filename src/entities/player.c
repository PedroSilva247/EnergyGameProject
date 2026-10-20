#include <raylib.h>
#include <stdlib.h>
#include "../../include/player.h"
#include "../../include/config.h"
#include "../../include/map.h"
#include "../../include/level.h"


Player* createPlayer(int x, int y, int energy, float radius, ControlKeys* controlKeys) {
    Player* player = (Player*) malloc(sizeof(Player));
    player->x = x;
    player->y = y;
    player->energy = energy;
    player->crystals = 0;
    player->radius = radius;
    player->controlKeys = controlKeys;

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
    DrawCircle(
        startMapX + (player->x * tile) + (tile / 2),
        startMapY + (player->y * tile) + (tile / 2),
        player->radius,
        RED
    );
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
                return;
            }
        } else if(axis == 'y') {
            if(isWalkable(map, x, y + step)) {
                player->y += step;
            } else {
                return;
            }
        }
        player->energy--;
    }


    
}

void verifyKeyboard(Player* player, Map* map) {
    if (IsKeyPressed(player->controlKeys->keyDown)){
        movePlayer('y', 1, map, player);
    }
    if (IsKeyPressed(player->controlKeys->keyUp)){
        movePlayer('y', -1, map, player);
    }
    if (IsKeyPressed(player->controlKeys->keyRight)){
        movePlayer('x', 1, map, player);
    }
    if (IsKeyPressed(player->controlKeys->keyLeft)){
        movePlayer('x', -1, map, player);
    }
}

char verifyPlayerTile(Player* player, Map* map) {
    return map->grid[player->y*map->width + player->x];
}

void getCrystal(Player* player, Map* map) {
    player->crystals ++;
    map->grid[player->y*map->width + player->x] = 'e';
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
    
}