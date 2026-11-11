#include "../../include/config.h"
#include "../../include/screen.h"

int startMapX = 100;
int startMapY = 100;
int tile = 50;
int trapDamage = 3;
int recoverEnergy = 5;
int recoverHealsMoreThanMax = 1;
Screen currentScreen = SCREEN_MENU;
GameplayScreenToDraw* gameplayScreenToDraw;

float unitX = 0;
float unitY = 0;