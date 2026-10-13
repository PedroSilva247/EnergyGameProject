#include <raylib.h>
#include <stdlib.h>
#include "../../include/player.h"
#include "../../include/config.h"

Player* createPlayer(int x, int y, int energy, float radius, ControlKeys* controlKeys) {
    Player* player = (Player*) malloc(sizeof(Player));
    player->x = x;
    player->y = y;
    player->energy = energy;
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

void updatePlayer(Player* player) {
    

}