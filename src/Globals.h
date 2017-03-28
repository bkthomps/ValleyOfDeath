#ifndef GLOBALS_H
#define GLOBALS_H

#include "GlobalConstants.h"
#include "GlobalStructs.h"
#include "Ships.h"
#include "Screens.h"

extern PlayerShip player;
extern SingleShip one[AMOUNT_OF_SHIPS_TYPE_1_TO_4];
extern SingleShip two[AMOUNT_OF_SHIPS_TYPE_1_TO_4];
extern SingleShip three[AMOUNT_OF_SHIPS_TYPE_1_TO_4];
extern SingleShip four[AMOUNT_OF_SHIPS_TYPE_1_TO_4];
extern DoubleShip five[AMOUNT_OF_SHIPS_TYPE_5_TO_8];
extern DoubleShip six[AMOUNT_OF_SHIPS_TYPE_5_TO_8];
extern RocketShip seven[AMOUNT_OF_SHIPS_TYPE_5_TO_8];
extern MasterShip eight[AMOUNT_OF_SHIPS_TYPE_5_TO_8];
extern MiniBoss nine;
extern MasterBoss ten;

extern Screen currentScreen;
extern Screen previousScreen;

extern Counters counter;
extern Containers container;

extern char font;
extern bool isSoundEnabled, isPaused, isStoryDate, isStoryMarry, isTorture, isHealthUpdate;
extern int xp, highscore, set, level, music, rank, text1, text2, text3;
extern int imageTorture, hpTorture, textTorture, healthImage;

#endif /* GLOBALS_H */
