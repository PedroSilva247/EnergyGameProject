#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/menu_screen.h"
#include "../../include/gameplay_screen.h"
#include "../../include/level.h"
#include "../../include/config.h"
#include "../../include/screen.h"
#include "../../include/menu_screen.h"
#include "../../include/ui.h"

Texture2D levelButtonFrameTex;
Texture2D levelButtonFrameHoverTex;
Texture2D backgroundTex;
Texture2D logoTex;
Texture2D buttonTex;
Texture2D buttonHoverTex;

Button* startScreenButtons[30];
int countStartScreenButtons = 0;


void LoadUITexturePack() {
    levelButtonFrameTex = LoadTexture("resources/uiTextures/level_button_frame.png");
    SetTextureFilter(levelButtonFrameTex, TEXTURE_FILTER_POINT);

    levelButtonFrameHoverTex = LoadTexture("resources/uiTextures/level_button_frame_hover.png");
    SetTextureFilter(levelButtonFrameTex, TEXTURE_FILTER_POINT);

    backgroundTex = LoadTexture("resources/uiTextures/background_start_screen.png");
    SetTextureFilter(backgroundTex, TEXTURE_FILTER_POINT);

    logoTex = LoadTexture("resources/uiTextures/logo.png");
    SetTextureFilter(logoTex, TEXTURE_FILTER_POINT);

    buttonTex = LoadTexture("resources/uiTextures/button.png");
    SetTextureFilter(buttonTex, TEXTURE_FILTER_POINT);

    buttonHoverTex = LoadTexture("resources/uiTextures/button_hover.png");
    SetTextureFilter(buttonHoverTex, TEXTURE_FILTER_POINT);
}

void UnloadUITextures(void) {
    UnloadTexture(levelButtonFrameTex);
    UnloadTexture(levelButtonFrameHoverTex);
    UnloadTexture(backgroundTex);
    UnloadTexture(logoTex);
}