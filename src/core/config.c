#include "../../include/config.h"
#include "../../include/screen.h"
#include <raylib.h>




int windowWidth = 1000*1.5;
int windowHeight = 800*1.5;

int countLevels = 0;
Level** levels;

int buttonTextSize = 36;

int startMapX = 100;
int startMapY = 100;
float tile = 50.0f;
int trapDamage = 3;
int recoverEnergy = 5;
int recoverHealsMoreThanMax = 1;
int restartRequested = 0;
Screen currentScreen = SCREEN_MENU;
GameplayScreenToDraw* gameplayScreenToDraw;
Font fontDefault;

float unitX = 0;
float unitY = 0;