#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/menu_screen.h"
#include "../../include/gameplay_screen.h"
#include "../../include/level.h"
#include "../../include/config.h"
#include "../../include/screen.h"

void DrawLevelSquare(LevelSquare* levelSquare) {
    char strNumLevel[3];
    sprintf(strNumLevel, "%d", levelSquare->level->numLevel);
    int fontSize = 20;

    Vector2 textSize = MeasureTextEx(GetFontDefault(), strNumLevel, 20, 2);

    Vector2 textPositionPixel;
    textPositionPixel.x = levelSquare->rec->x + (levelSquare->rec->width / 2.0f) - (textSize.x / 2.0f);
    textPositionPixel.y = levelSquare->rec->y + (levelSquare->rec->height / 2.0f) - (textSize.y / 2.0f);

    DrawRectangleRec(*(levelSquare->rec), LIGHTGRAY);
    DrawText(strNumLevel, (int) textPositionPixel.x, (int) textPositionPixel.y, fontSize, BLACK);
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
    Rectangle currentRec = {initialPos.x, initialPos.y, tile*2, tile*2}; 
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
    for(int i = 0; i < countLevels; i++) {
        if(CheckCollisionPointRec(mousePos, *(levelSquares[i]->rec))) {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                gameplayScreenToDraw = playLevel(levelSquares[i]->level);
                currentScreen = SCREEN_GAMEPLAY;
            }
        }
    }


}

void DrawMenuScreen(Level* levels[100], int countLevels) {
    LevelSquare** levelSquareList = createLevelSquareList(levels, countLevels, (Vector2) {10, 10});
    DrawLevelSquareList(levelSquareList, countLevels);
    verifyMouseMenu(levelSquareList, countLevels);
}