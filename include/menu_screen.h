#ifndef MENU_SCREEN
#define MENU_SCREEN

#include <raylib.h>

typedef struct Level Level;

typedef struct LevelSquare {
    Level* level;
    Rectangle* rec;
} LevelSquare;


void DrawLevelSquare(LevelSquare* levelSquare);
void DrawLevelSquareList(LevelSquare** levelSquares, int countLevels) ;
LevelSquare* createLevelSquare(Level* level, Rectangle* rec);
LevelSquare** createLevelSquareList(Level* levels[100], int countLevels, Vector2 initialPos);
void verifyMouseMenu(LevelSquare** levelSquares, int countLevels);
void DrawMenuScreen(Level* levels[100], int countLevels);

#endif