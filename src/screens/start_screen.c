#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/menu_screen.h"
#include "../../include/gameplay_screen.h"
#include "../../include/level.h"
#include "../../include/config.h"
#include "../../include/screen.h"
#include "../../include/menu_screen.h"
#include "../../include/ui.h"
#define BUTTON_TEXT_SIZE 36



void DrawBackground() {
    Rectangle source = { 0, 0, (float)backgroundTex.width, (float)backgroundTex.height }; //altura do png e largura
    Rectangle dest   = { 0.0f, 0.0f, (float)windowWidth, (float)windowHeight };
    DrawTexturePro(backgroundTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void DrawLogo() {
    Rectangle source = { 0, 0, (float)logoTex.width, (float)logoTex.height }; //altura do png e largura
    Rectangle dest   = { windowWidth/4, windowHeight/10 + 50, (float)windowWidth/2, (float)((float)logoTex.height / (float)logoTex.width)*((float)windowWidth/2.0f) }; //coloca em proporcao
    DrawTexturePro(logoTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

Button* createButton(Rectangle rec, void (*func) (void), char* str) {
    Button* newButton = (Button*) malloc(sizeof(Button));
    Rectangle* newRectangle = (Rectangle*) malloc(sizeof(Rectangle));
    newRectangle->x = rec.x;
    newRectangle->y = rec.y;
    newRectangle->width = rec.width;
    newRectangle->height = rec.height;


    newButton->rec = newRectangle;
    newButton->func = func;
    strcpy(newButton->str, str);
    newButton->hover = false;

    return newButton;
}

void DrawButtonFrame(Rectangle* rec, bool hover) {
    Texture2D frameTex;
    if(hover) {
        frameTex = buttonHoverTex;
    } else {
        frameTex = buttonTex;
    }
    Rectangle source = { 0, 0, (float)frameTex.width, (float)frameTex.height }; //altura do png e largura
    Rectangle dest   = { (float)rec->x, (float)rec->y, (float)rec->width, (float)rec->height }; //preencher o tile
    DrawTexturePro(frameTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void DrawButtonText(Button* button) {
    Vector2 textSize = MeasureTextEx(fontDefault, button->str, BUTTON_TEXT_SIZE, 2);

    Vector2 textPositionPixel;
    textPositionPixel.x = button->rec->x + (button->rec->width / 2.0f) - (textSize.x / 2.0f);
    textPositionPixel.y = button->rec->y + (button->rec->height / 2.0f) - (textSize.y / 2.0f);

    DrawTextEx(fontDefault, button->str, (Vector2) {textPositionPixel.x + 2, textPositionPixel.y + 2}, BUTTON_TEXT_SIZE, 2, TEXT_SHADOW_COLOR);
    if(button->hover) {
        DrawTextEx(fontDefault, button->str, (Vector2) {textPositionPixel.x, textPositionPixel.y}, BUTTON_TEXT_SIZE, 2, TEXT_COLOR_HOVER);
    } else {
        DrawTextEx(fontDefault, button->str, (Vector2) {textPositionPixel.x, textPositionPixel.y}, BUTTON_TEXT_SIZE, 2, TEXT_COLOR);
    }
}

void DrawButton(Button* button) {
    DrawButtonFrame(button->rec, button->hover);
    
    DrawButtonText(button);

}



void goToMenu() {
    currentScreen = SCREEN_MENU;
}

void verifyMouseButtons(Button* buttons[30], int countButtons) {
    Vector2 mousePos = GetMousePosition();
    for(int i = 0; i < countButtons; i++) {
        if(CheckCollisionPointRec(mousePos, *(buttons[i]->rec))) {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                buttons[i]->func();
            }
            buttons[i]->hover = true;
        } else {
            buttons[i]->hover = false;
        }
    }
}


void DrawStartScreen() {
    DrawBackground();
    DrawLogo();
    DrawButton(startScreenButtons[0]);
    verifyMouseButtons(startScreenButtons, countStartScreenButtons);
}

