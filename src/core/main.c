#include <stdio.h>
#include <raylib.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "../../include/gameplay_screen.h"
#include "../../include/map.h"
#include "../../include/player.h"
#include "../../include/level.h"
#include "../../include/mapElements.h"
#include "../../include/screen.h"
#include "../../include/menu_screen.h"
#include "../../include/start_screen.h"
#include "../../include/config.h"
#include "../../include/ui.h"
#include "../../include/effects.h"


#define N 6
#define MAX_MAP_SIZE 30



int main() {
	srand((unsigned int)time(NULL));

    InitWindow(windowWidth, windowHeight, "EnergyGame");

	
	currentScreen = SCREEN_START;
	
	char folder[30] = "forestTextures";
	
	LoadMapTexturePack(folder);
	LoadUITexturePack();
	LoadEffectsTextures();
	
	Button* startButton = createButton((Rectangle) {windowWidth/2 - buttonTex.width/2, windowHeight - windowHeight/3, buttonTex.width, buttonTex.height}, goToMenu, "JOGAR");
	startScreenButtons[countStartScreenButtons] = startButton;
	countStartScreenButtons++;
	
	fontDefault = LoadFontEx("resources/fonts/font_pixel.ttf", 32, 0, 0);


	char grid1[10][10] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', 'e', 'e', 'e', 'e', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', '#', 'e', 'e', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', '#', '#', '#', 'e', '#', 'e', '#', '#'},
		{'#', 'e', '#', 'c', '#', 'e', '#', 'e', 'e', '#'},
		{'#', 'e', '?', 'c', '#', '#', '#', '#', 't', '#'},
		{'#', 'e', '#', 'c', 'e', 'e', 'e', '#', 'e', '#'},
		{'#', 'e', '#', '#', '#', 'e', 'e', '#', 'e', '#'},
		{'#', 'e', 'e', 'e', 'r', 'e', 'e', 'e', 'f', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	};

	char grid2[20][20] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'e', 'e', '#', '#', 'e', 't', 'e', 'e', 'r', 'e', 'e', 'e', 't', 'e', 'e', 'e', 'e', 'e', '#'},
    {'#', 'e', 'e', 'e', 'e', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', 'c', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', 'e', 'e', 't', 'e', 'e', 'e', 'r', 'e', 'e', 'e', '#', '#', 'e', 'e', 't', 'e', 'e', 'e', '#'},
    {'#', 'e', '#', '#', '#', '#', '#', '#', '#', '#', 'e', 'e', 'e', 'e', '#', '#', '#', '#', 'e', '#'},
    {'#', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'c', '#'},
    {'#', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'e', 'e', 'e', 'e', 't', 'e', '#', '#', 'e', 'r', 'e', 'e', 'e', 'e', 't', 'e', 'e', 'e', '#'},
    {'#', 'e', '#', '#', '#', '#', 'e', 'e', 'e', 'e', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', 'c', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', 'e', 'e', '#', '#', 'e', 't', 'e', 'e', 'r', 'e', 'e', 'e', 't', 'e', 'e', 'e', 'e', 'e', '#'},
    {'#', 'e', 'e', 'e', 'e', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'e', '#'},
    {'#', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'c', '#'},
    {'#', 'e', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'e', 'e', 't', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 't', 'e', 'e', 'r', 'e', 'e', 'e', 'e', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'f', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};


	Map* map1 = createMap(10, 10, &grid1[0][0], 1, 1);

	Map* map2 = createMap(20, 20, &grid2[0][0], 1, 1);

	Level* level1 = createLevel(map1, 20, 20, 3, 1);

	Level* level2 = createLevel(map2, 101, 101, 4, 2);

	Level** levels = (Level**) malloc(sizeof(Level*)*100);
	int countLevels = 0;
	
	levels[countLevels] = level1;
	countLevels++;

	levels[countLevels] = level2;
	countLevels++;

	//Player* player1 = createPlayer(1, 1, 10, 10.0f, createControlKeys(KEY_W, KEY_A, KEY_S, KEY_D));
	//GameplayScreenToDraw* gameplayScreenToDraw = playLevel(level1);

	//gameplayScreenToDraw = playLevel(level2);

	
 
	float unitX;
	float unitY;

    SetTargetFPS(120);
	while(!WindowShouldClose()) {

		unitX = GetWindowScaleDPI().x / 1000;
		unitY = GetWindowScaleDPI().y / 1000;
		
		BeginDrawing();

			ClearBackground(RAYWHITE);
	
			switch(currentScreen) {
				case SCREEN_START:
					DrawStartScreen();
					break;
				case SCREEN_MENU:
					DrawMenuScreen(levels, countLevels);
					break;
				case SCREEN_GAMEPLAY:
					gameplayScreenToDraw->func(gameplayScreenToDraw->level, gameplayScreenToDraw->player);
					if (restartRequested){
						restartRequested = 0;
					}
					break;
			}
			

		EndDrawing();
    }

	UnloadMapTextures();
	UnloadUITextures();
	UnloadEffectsTextures();

	CloseWindow();
    return 0;
}