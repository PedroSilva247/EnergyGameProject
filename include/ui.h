#ifndef UI
#define UI

#include <raylib.h>

extern Texture2D levelButtonFrameTex;
extern Texture2D levelButtonFrameHoverTex;
extern Texture2D backgroundTex;
extern Texture2D logoTex;
extern Texture2D buttonTex;
extern Texture2D buttonHoverTex;



typedef struct struct_button {
    Rectangle* rec;
    void (*func) (void);
    char str[30];
    bool hover;
} Button;

extern Button* startScreenButtons[30];
extern int countStartScreenButtons;

void LoadUITexturePack();

void UnloadUITextures(void);

void DrawBackground();

void DrawLogo();

Button* createButton(Rectangle rec, void (*func) (void), char* str);

void DrawButtonFrame(Rectangle* rec, bool hover) ;

void DrawButtonText(Button* button);

void DrawButton(Button* button);

void goToMenu();

void verifyMouseButtons(Button* buttons[30], int countButtons);


#endif