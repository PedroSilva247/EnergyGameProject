#ifndef CONFIG
#define CONFIG

#include "screen.h"
#include "gameplay_screen.h"
#include <raylib.h>

#define TEXT_COLOR (Color) {252, 242, 216, 255}
#define TEXT_SHADOW_COLOR (Color) {46, 28, 22, 255}
#define TEXT_COLOR_HOVER (Color) {255, 224, 104, 255}

static inline float max_float(float a, float b) {
    return a > b ? a : b;
}

static inline float min_float(float a, float b) {
    return a < b ? a : b;
}

extern int buttonTextSize;

extern int windowWidth;
extern int windowHeight;

extern float unitY;
extern float unitX;
extern int trapDamage;
extern int recoverEnergy;
extern int recoverHealsMoreThanMax;
extern Screen currentScreen;
extern Font fontDefault;

extern GameplayScreenToDraw* gameplayScreenToDraw;

extern int startMapX;
extern int startMapY;
extern float tile;
extern int restartRequested;
#endif