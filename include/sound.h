#ifndef SOUND_H
#define SOUND_H

#include <raylib.h>

extern Sound crystalSound;
extern Sound defeatSound;
extern Sound selectSound;
extern Sound finishLineSound;
extern Sound recoverSound;


extern Music menuMusic;
extern Music gameMusic;


void LoadSounds(void);
void UnloadSounds(void);
void UpdateMusic(void);


#endif

