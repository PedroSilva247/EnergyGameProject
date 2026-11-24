#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/menu_screen.h"
#include "../../include/gameplay_screen.h"
#include "../../include/level.h"
#include "../../include/config.h"
#include "../../include/screen.h"
#include "../../include/ui.h"

#define NUMBER_LEVEL_SIZE 36
#define LEVEL_SQUARE_SIZE (windowWidth / 15.0f)



int levelHover = 0;

void DrawLevelButtonFrame(Rectangle* rec, bool hover) {
    Texture2D frameTex;
    if(hover) {
        frameTex = levelButtonFrameHoverTex;
    } else {
        frameTex = levelButtonFrameTex;
    }
    Rectangle source = { 0, 0, (float)frameTex.width, (float)frameTex.height }; //altura do png e largura
    Rectangle dest   = { (float)rec->x, (float)rec->y, (float)rec->width, (float)rec->height }; //preencher o tile
    DrawTexturePro(frameTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void DrawLevelSquare(LevelSquare* levelSquare) {
    char strNumLevel[3];
    sprintf(strNumLevel, "%d", levelSquare->level->numLevel);

    Vector2 textSize = MeasureTextEx(fontDefault, strNumLevel, NUMBER_LEVEL_SIZE, 2);

    Vector2 textPositionPixel;
    textPositionPixel.x = levelSquare->rec->x + (levelSquare->rec->width / 2.0f) - (textSize.x / 2.0f);
    textPositionPixel.y = levelSquare->rec->y + (levelSquare->rec->height / 2.0f) - (textSize.y / 2.0f);

    if(levelHover == levelSquare->level->numLevel) {
        DrawLevelButtonFrame(levelSquare->rec, true);
        DrawLevelNumber(strNumLevel, (int) textPositionPixel.x, (int) textPositionPixel.y, true);
    } else {
        DrawLevelButtonFrame(levelSquare->rec, false);
        DrawLevelNumber(strNumLevel, (int) textPositionPixel.x, (int) textPositionPixel.y, false);
    }
    

}

void DrawLevelSquareList(LevelSquare** levelSquares, int countLevels) {
    for(int i = 0; i < countLevels; i++) {
        DrawLevelSquare(levelSquares[i]);
    }
}

LevelSquare* createLevelSquare(Level* level, Rectangle* rec) {
    LevelSquare* newLevelSquare = (LevelSquare*) malloc(sizeof(LevelSquare));

    newLevelSquare->level = level;
    newLevelSquare->rec = rec;

    return newLevelSquare;
}

LevelSquare** createLevelSquareList(Level* levels[100], int countLevels, Vector2 initialPos) {
    LevelSquare** newLevelSquareList = (LevelSquare**) malloc(sizeof(LevelSquare*)* countLevels);
    Rectangle currentRec = {initialPos.x, initialPos.y, LEVEL_SQUARE_SIZE, LEVEL_SQUARE_SIZE};
    Rectangle* copyRec;
    for(int i = 0; i < countLevels; i++) {
        copyRec = (Rectangle*) malloc(sizeof(Rectangle));
        *copyRec = currentRec;
        newLevelSquareList[i] = createLevelSquare(levels[i], copyRec);
        currentRec.x += currentRec.width * 1.3; 
    }

    return newLevelSquareList;
}

void verifyMouseMenu(LevelSquare** levelSquares, int countLevels) {
    Vector2 mousePos = GetMousePosition();
    levelHover = 0;
    for(int i = 0; i < countLevels; i++) {
        if(CheckCollisionPointRec(mousePos, *(levelSquares[i]->rec))) {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                gameplayScreenToDraw = playLevel(levelSquares[i]->level);
                currentScreen = SCREEN_GAMEPLAY;
            }
            levelHover = i+1;
        }
    }


}

void DrawLevelNumber(char nChar[3], int posX, int posY, bool hover) {
    DrawTextEx(fontDefault, nChar, (Vector2) {posX + 2, posY + 2}, NUMBER_LEVEL_SIZE, 2, TEXT_SHADOW_COLOR);
    if(hover) {
        DrawTextEx(fontDefault, nChar, (Vector2) {posX, posY}, NUMBER_LEVEL_SIZE, 2, TEXT_COLOR_HOVER);
    } else {
        DrawTextEx(fontDefault, nChar, (Vector2) {posX, posY}, NUMBER_LEVEL_SIZE, 2, TEXT_COLOR);
    }
}

void DrawMenuScreen(Level* levels[100], int countLevels) {

    int panelWidth = windowWidth/1.3;
    int panelHeight = (float)(328.0f/448.0f) * panelWidth;
    int panelX = windowWidth/2 - panelWidth/2;
    int panelY = windowHeight/2 - panelHeight/2;

    LevelSquare** levelSquareList = createLevelSquareList(levels, countLevels, (Vector2) {panelX + panelWidth/13, panelY + panelHeight/9.5});
    DrawBackground(0);
    DrawBackgroundDarkFilter();


    DrawSimplePanel(panelX, panelY, panelWidth);

    DrawLevelSquareList(levelSquareList, countLevels);
    verifyMouseMenu(levelSquareList, countLevels);
}