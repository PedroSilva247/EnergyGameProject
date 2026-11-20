#ifndef START_SCREEN
#define START_SCREEN

#include <raylib.h>
#include "ui.h"

void DrawBackground();

void DrawLogo();

Button* createButton(Rectangle rec, void (*func) (void), char* str);

void DrawButtonFrame(Rectangle* rec, bool hover) ;

void DrawButtonText(Button* button);

void DrawButton(Button* button);



void goToMenu();

void verifyMouseButtons(Button* buttons[30], int countButtons);



void DrawStartScreen();

#endif