#include "../../include/config.h"
#include "../../include/screen.h"
#include <raylib.h>

int startMapX = 100;
int startMapY = 100;
int tile = 50;
int trapDamage = 3;
int recoverEnergy = 5;
int recoverHealsMoreThanMax = 1;
int restartRequested = 0;
Screen currentScreen = SCREEN_MENU;
GameplayScreenToDraw* gameplayScreenToDraw;
Font fontDefault;

float unitX = 0;
float unitY = 0;