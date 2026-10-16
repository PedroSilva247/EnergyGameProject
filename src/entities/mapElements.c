#include <raylib.h>
#include <stdlib.h>
#include "../../include/mapElements.h"
#include "../../include/config.h"


void DrawCrystal(int x,int y) {
    DrawRectangle(
        x + tile/2 - tile/2/2, // x + metade do tile - metade do tamanho do cristal
        y + tile/2 - tile/2/2, // Declaracao do tamanho do crystal
        tile * 0.5,
        tile * 0.5,
        BLACK
    );
}

void DrawFinishLine(int x, int y) {
    DrawRectangle(
        x, 
        y,
        tile,
        tile,
        GREEN
    );
}
