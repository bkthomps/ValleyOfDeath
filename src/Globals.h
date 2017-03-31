/*
 * Whichever files include this one can use the following global variables.
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#include "GlobalConstants.h"
#include "GlobalStructs.h"
#include "Ships.h"
#include "Screens.h"

extern PlayerShip player;
extern SingleShip one[];
extern SingleShip two[];
extern SingleShip three[];
extern SingleShip four[];
extern DoubleShip five[];
extern DoubleShip six[];
extern RocketShip seven[];
extern MasterShip eight[];
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
