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
#include "../../include/sound.h"


Texture2D levelButtonFrameTex;
Texture2D levelButtonFrameHoverTex;
Texture2D backgroundStartTex;
Texture2D backgroundGreenTreesTex;
Texture2D backgroundColorfulTreesTex;
Texture2D backgroundDarkTreesTex;
Texture2D logoTex;
Texture2D buttonTex;
Texture2D buttonHoverTex;
Texture2D simplePanel;
Texture2D victoryPanelTex;
Texture2D defeatPanelTex;
Texture2D gameplayPanelTex;
Texture2D mapFrameTex;
Texture2D pausePanelTex;

float defaultCenterButtonX;
float defaultCenterButtonY;
Vector2 defaultButtonSize;
float defaultButtonGap = 20;

float buttonEndGameplayScreenY;


Button* startScreenButtons[10];
int countStartScreenButtons = 0;

Button* endGameplayScreenButtons[10];
int countEndGameplayScreenButtons = 0;

Button* pauseGameplayScreenButtons[10];
int countPauseGameplayScreenButtons = 0;




void LoadUITexturePack() {
    levelButtonFrameTex = LoadTexture("resources/uiTextures/level_button_frame.png");
    SetTextureFilter(levelButtonFrameTex, TEXTURE_FILTER_POINT);

    levelButtonFrameHoverTex = LoadTexture("resources/uiTextures/level_button_frame_hover.png");
    SetTextureFilter(levelButtonFrameTex, TEXTURE_FILTER_POINT);

    backgroundStartTex = LoadTexture("resources/uiTextures/background_start_screen.png");
    SetTextureFilter(backgroundStartTex, TEXTURE_FILTER_POINT);

    backgroundGreenTreesTex = LoadTexture("resources/uiTextures/background_green_trees.png");
    SetTextureFilter(backgroundGreenTreesTex, TEXTURE_FILTER_POINT);

    backgroundColorfulTreesTex = LoadTexture("resources/uiTextures/background_colorful_trees.png");
    SetTextureFilter(backgroundColorfulTreesTex, TEXTURE_FILTER_POINT);

    backgroundDarkTreesTex = LoadTexture("resources/uiTextures/background_dark_trees.png");
    SetTextureFilter(backgroundDarkTreesTex, TEXTURE_FILTER_POINT);

    logoTex = LoadTexture("resources/uiTextures/logo.png");
    SetTextureFilter(logoTex, TEXTURE_FILTER_POINT);

    buttonTex = LoadTexture("resources/uiTextures/button.png");
    SetTextureFilter(buttonTex, TEXTURE_FILTER_POINT);

    buttonHoverTex = LoadTexture("resources/uiTextures/button_hover.png");
    SetTextureFilter(buttonHoverTex, TEXTURE_FILTER_POINT);

    simplePanel = LoadTexture("resources/uiTextures/simple_panel.png");
    SetTextureFilter(simplePanel, TEXTURE_FILTER_POINT);

    victoryPanelTex = LoadTexture("resources/uiTextures/victory_panel.png");
    SetTextureFilter(simplePanel, TEXTURE_FILTER_POINT);

    defeatPanelTex = LoadTexture("resources/uiTextures/defeat_panel.png");
    SetTextureFilter(simplePanel, TEXTURE_FILTER_POINT);

    gameplayPanelTex = LoadTexture("resources/uiTextures/gameplay_panel.png");
    SetTextureFilter(gameplayPanelTex, TEXTURE_FILTER_POINT);

    mapFrameTex = LoadTexture("resources/uiTextures/map_frame.png");
    SetTextureFilter(mapFrameTex, TEXTURE_FILTER_POINT);

    pausePanelTex = LoadTexture("resources/uiTextures/pause_panel.png");
    SetTextureFilter(pausePanelTex, TEXTURE_FILTER_POINT);
}

void UnloadUITextures(void) {
    UnloadTexture(levelButtonFrameTex);
    UnloadTexture(levelButtonFrameHoverTex);
    UnloadTexture(backgroundStartTex);
    UnloadTexture(backgroundGreenTreesTex);
    UnloadTexture(backgroundColorfulTreesTex);
    UnloadTexture(backgroundDarkTreesTex);
    UnloadTexture(logoTex);
    UnloadTexture(simplePanel);
    UnloadTexture(victoryPanelTex);
    UnloadTexture(defeatPanelTex);
    UnloadTexture(gameplayPanelTex);
    UnloadTexture(pausePanelTex);
}

void DrawBackground(int n) {
    Texture2D backgroundTex;
    switch (n) {
        case 0:
            backgroundTex = backgroundStartTex;
            break;
        case 1:
            backgroundTex = backgroundGreenTreesTex;
            break;
        case 2:
            backgroundTex = backgroundColorfulTreesTex;
            break;
        case 3:
            backgroundTex = backgroundDarkTreesTex;
            break;
        default:
            backgroundTex = backgroundStartTex;
            break;
    }
    Rectangle source = { 0, 0, (float)backgroundTex.width, (float)backgroundTex.height }; //altura do png e largura
    Rectangle dest   = { 0.0f, 0.0f, (float)windowWidth, (float)windowHeight };
    DrawTexturePro(backgroundTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void DrawBackgroundDarkFilter() {
    DrawRectangle(0, 0, windowWidth, windowHeight, (Color) {0, 0, 0, 100});
}

void DrawSimplePanel(int x, int y, int width) {
    Rectangle source = { 0, 0, (float)simplePanel.width, (float)simplePanel.height }; //altura do png e largura
    Rectangle dest   = { (float) x, (float) y, (float) width, (float)((float)simplePanel.height/(float)simplePanel.width) * width };
    DrawTexturePro(simplePanel, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
}

void DrawGameplayPanel(int x, int y, int width) {
    Rectangle source = { 0, 0, (float)gameplayPanelTex.width, (float)gameplayPanelTex.height }; //altura do png e largura
    Rectangle dest   = { (float) x, (float) y, (float) width, (float)((float)gameplayPanelTex.height/(float)gameplayPanelTex.width) * width };
    DrawTexturePro(gameplayPanelTex, source, dest, (Vector2){ 0, 0 }, 0.0f, WHITE); //adapta a pixelart para quaisquer alteracoes na resolucao da tela
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

void createButtons() {
    // START
    Button* startButton = createButton((Rectangle) {windowWidth/2 - buttonTex.width/2, windowHeight - windowHeight/3, buttonTex.width, buttonTex.height}, goToMenu, "JOGAR");
	startScreenButtons[countStartScreenButtons] = startButton;
	countStartScreenButtons++;

    // GAMEPLAY END

    Button* playAgainEndGameplayButton = createButton((Rectangle) {windowWidth/2 - buttonTex.width/2 - defaultButtonGap - buttonTex.width, windowHeight - windowHeight/3, buttonTex.width, buttonTex.height}, playSameLevel, "DENOVO");
	endGameplayScreenButtons[countEndGameplayScreenButtons] = playAgainEndGameplayButton;
	countEndGameplayScreenButtons++;

    Button* backToMenuEndGameplayButton = createButton((Rectangle) {windowWidth/2 - buttonTex.width/2, windowHeight - windowHeight/3, buttonTex.width, buttonTex.height}, backToMenu, "MENU");
	endGameplayScreenButtons[countEndGameplayScreenButtons] = backToMenuEndGameplayButton;
	countEndGameplayScreenButtons++;

    Button* playNextLevelEndGameplayButton = createButton((Rectangle) {windowWidth/2 + buttonTex.width/2 + defaultButtonGap, windowHeight - windowHeight/3, buttonTex.width, buttonTex.height}, playNextLevel, "PROXIMA");
	endGameplayScreenButtons[countEndGameplayScreenButtons] = playNextLevelEndGameplayButton;
	countEndGameplayScreenButtons++;

    // GAMEPLAY PAUSE

    Button* resumePauseGameplayButton = createButton((Rectangle) {defaultCenterButtonX, defaultCenterButtonY - defaultButtonGap - defaultButtonSize.y, defaultButtonSize.x, defaultButtonSize.y}, backToGameplay, "CONTINUAR");
	pauseGameplayScreenButtons[countPauseGameplayScreenButtons] = resumePauseGameplayButton;
	countPauseGameplayScreenButtons++;

    Button* giveUpPauseGameplayButton = createButton((Rectangle) {defaultCenterButtonX, defaultCenterButtonY, defaultButtonSize.x, defaultButtonSize.y}, finishGame, "DESISTIR");
	pauseGameplayScreenButtons[countPauseGameplayScreenButtons] = giveUpPauseGameplayButton;
	countPauseGameplayScreenButtons++;

    Button* menuLevelPauseGameplayButton = createButton((Rectangle) {defaultCenterButtonX, defaultCenterButtonY + defaultButtonGap + defaultButtonSize.y, defaultButtonSize.x, defaultButtonSize.y}, backToMenu, "MENU");
	pauseGameplayScreenButtons[countPauseGameplayScreenButtons] = menuLevelPauseGameplayButton;
	countPauseGameplayScreenButtons++;
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
    Vector2 textSize = MeasureTextEx(fontDefault, button->str, buttonTextSize, 2);

    Vector2 textPositionPixel;
    textPositionPixel.x = button->rec->x + (button->rec->width / 2.0f) - (textSize.x / 2.0f);
    textPositionPixel.y = button->rec->y + (button->rec->height / 2.0f) - (textSize.y / 2.0f);

    DrawTextEx(fontDefault, button->str, (Vector2) {textPositionPixel.x + 2, textPositionPixel.y + 2}, buttonTextSize, 2, TEXT_SHADOW_COLOR);
    if(button->hover) {
        DrawTextEx(fontDefault, button->str, (Vector2) {textPositionPixel.x, textPositionPixel.y}, buttonTextSize, 2, TEXT_COLOR_HOVER);
    } else {
        DrawTextEx(fontDefault, button->str, (Vector2) {textPositionPixel.x, textPositionPixel.y}, buttonTextSize, 2, TEXT_COLOR);
    }
}

void updateButton(Button* button, Rectangle rec) {
    button->rec->x = rec.x;
    button->rec->y = rec.y;
    button->rec->width = rec.width;
    button->rec->height = rec.height;
}

void DrawButton(Button* button) {
    //button->rec->x = windowWidth/2 - buttonTex.width/2;
    //button->rec->y = windowHeight - windowHeight/3;

    DrawButtonFrame(button->rec, button->hover);
    
    DrawButtonText(button);

}



void goToMenu() {
    currentScreen = SCREEN_MENU;
    currentScreenGameplay = SCREEN_GAMEPLAY_GAMEPLAY;
}

void goToGameplayScreen() {
    currentScreen = SCREEN_GAMEPLAY;
    currentScreenGameplay = SCREEN_GAMEPLAY_GAMEPLAY;
}

void verifyMouseButtons(Button* buttons[10], int countButtons) {
    if(countButtons < 0) {
        return;
    }
    if(countButtons > 10) {
        countButtons = 10;
    }
    Vector2 mousePos = GetMousePosition();
    for(int i = 0; i < countButtons; i++) {
        if(CheckCollisionPointRec(mousePos, *(buttons[i]->rec))) {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                buttons[i]->func();
                PlaySound(selectSound);
            }
            buttons[i]->hover = true;
        } else {
            buttons[i]->hover = false;
        }
    }
}


void backToMenu() {
    freeLevel(currentLevel);
    goToMenu();
}

void playNextLevel() {
    int levelN = currentLevel->numLevel;
    freeLevel(currentLevel);
    if(levelN + 1 > countLevels) {
        goToMenu();
    } else {
        gameplayScreenToDraw = playLevel(levels[levelN]);
        goToGameplayScreen();
    }
}

void playSameLevel() {
    int levelN = currentLevel->numLevel;
    freeLevel(currentLevel);
    gameplayScreenToDraw = playLevel(levels[levelN-1]);
    goToGameplayScreen();
}