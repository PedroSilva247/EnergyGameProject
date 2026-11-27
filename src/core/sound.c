#include "../../include/sound.h"
#include "../../include/config.h"

Sound crystalSound;
Sound defeatSound;
Sound selectSound;
Sound finishLineSound;
Sound recoverSound;


Music gameMusic;
Music menuMusic;



void LoadSounds(void){
    crystalSound = LoadSound("resources/sounds/getCrystal.wav");
    defeatSound = LoadSound("resources/sounds/Defeat.wav");
    selectSound = LoadSound("resources/sounds/Select.wav");
    finishLineSound = LoadSound("resources/sounds/gateOpen.wav");
    recoverSound = LoadSound("resources/sounds/recover.wav");


    menuMusic = LoadMusicStream("resources/sounds/menu.mp3");
    gameMusic = LoadMusicStream("resources/sounds/game.mp3");
}

void UnloadSounds(void){
    UnloadSound(crystalSound);
    UnloadSound(defeatSound);
    UnloadSound(selectSound);
    UnloadSound(finishLineSound);
    UnloadSound(recoverSound);

    UnloadMusicStream(menuMusic);
    UnloadMusicStream(gameMusic);
}

void UpdateMusic(void){
    if (currentScreen == SCREEN_GAMEPLAY){
        if (IsMusicStreamPlaying(menuMusic)) {
            StopMusicStream(menuMusic);
        }
        if (!IsMusicStreamPlaying(gameMusic)) {
            PlayMusicStream(gameMusic);
        }
        UpdateMusicStream(gameMusic);
    } else{
        if (IsMusicStreamPlaying(gameMusic)) {
            StopMusicStream(gameMusic);
        }
        if (!IsMusicStreamPlaying(menuMusic)) {
            PlayMusicStream(menuMusic);
        }
        UpdateMusicStream(menuMusic);
    }
}



