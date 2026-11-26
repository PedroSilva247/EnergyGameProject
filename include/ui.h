#ifndef UI
#define UI

#include <raylib.h>

extern Texture2D levelButtonFrameTex;
extern Texture2D levelButtonFrameHoverTex;
extern Texture2D backgroundStartTex;
extern Texture2D backgroundGreenTreesTex;
extern Texture2D backgroundColorfulTreesTex;
extern Texture2D backgroundDarkTreesTex;
extern Texture2D logoTex;
extern Texture2D buttonTex;
extern Texture2D buttonHoverTex;
extern Texture2D simplePanel;
extern Texture2D victoryPanelTex;
extern Texture2D defeatPanelTex;
extern Texture2D gameplayPanelTex;
extern Texture2D mapFrameTex;



typedef struct struct_button {
    Rectangle* rec;
    void (*func) (void);
    char str[30];
    bool hover;
} Button;

extern Vector2 defaultButtonSize;
extern float defaultCenterButtonX;
extern float defaultButtonGap;

extern float buttonEndGameplayScreenHeight;

extern Button* startScreenButtons[10];
extern int countStartScreenButtons;

extern Button* endGameplayScreenButtons[10];
extern int countEndGameplayScreenButtons;

static inline float max_float(float a, float b) {
    return a > b ? a : b;
}

static inline float min_float(float a, float b) {
    return a < b ? a : b;
}

static inline float clamp(float min, float def, float max) {
    return max_float(min, min_float(max, def*(float)((float)windowWidth/1500.0f)));
};

float clamp(float min, float def, float max);

void LoadUITexturePack();

void UnloadUITextures(void);

void DrawBackground(int n);

void DrawBackgroundDarkFilter();

void DrawSimplePanel(int x, int y, int width);
void DrawGameplayPanel(int x, int y, int width);

void DrawLogo();

Button* createButton(Rectangle rec, void (*func) (void), char* str);

void createButtons();

void DrawButtonFrame(Rectangle* rec, bool hover);

void DrawButtonText(Button* button);

void DrawButton(Button* button);

void updateButton(Button* button, Rectangle rec);

void goToMenu();

void backToMenu();

void playNextLevel();

void playSameLevel();

void verifyMouseButtons(Button* buttons[10], int countButtons);


#endif