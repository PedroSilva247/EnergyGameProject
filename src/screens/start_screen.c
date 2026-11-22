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






void DrawStartScreen() {
    DrawBackground(0);
    DrawLogo();
    DrawButton(startScreenButtons[0]);
    verifyMouseButtons(startScreenButtons, countStartScreenButtons);
}

