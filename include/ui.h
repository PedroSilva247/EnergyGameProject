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



typedef struct struct_button {
    Rectangle* rec;
    void (*func) (void);
    char str[30];
    bool hover;
} Button;

extern Button* startScreenButtons[10];
extern int countStartScreenButtons;

extern Button* endGameplayScreenButtons[10];
extern int countEndGameplayScreenButtons;

void LoadUITexturePack();

void UnloadUITextures(void);

void DrawBackground(int n);

void DrawBackgroundDarkFilter();

void DrawSimplePanel(int x, int y, int width);

void DrawLogo();

Button* createButton(Rectangle rec, void (*func) (void), char* str);

void createButtons();

void DrawButtonFrame(Rectangle* rec, bool hover);

void DrawButtonText(Button* button);

void DrawButton(Button* button);

void goToMenu();

void verifyMouseButtons(Button* buttons[30], int countButtons);


#endif