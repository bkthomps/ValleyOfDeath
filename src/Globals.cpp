/*
 * Global variables which are used by many different functions in many different files.
 */

#include "DragonFireSDK.h"
#include "Ships.h"
#include "Screens.h"
#include "GlobalConstants.h"
#include "GlobalStructs.h"

PlayerShip player;
SingleShip one[AMOUNT_OF_SHIPS_TYPE_1_TO_4];
SingleShip two[AMOUNT_OF_SHIPS_TYPE_1_TO_4];
SingleShip three[AMOUNT_OF_SHIPS_TYPE_1_TO_4];
SingleShip four[AMOUNT_OF_SHIPS_TYPE_1_TO_4];
DoubleShip five[AMOUNT_OF_SHIPS_TYPE_5_TO_8];
DoubleShip six[AMOUNT_OF_SHIPS_TYPE_5_TO_8];
RocketShip seven[AMOUNT_OF_SHIPS_TYPE_5_TO_8];
MasterShip eight[AMOUNT_OF_SHIPS_TYPE_5_TO_8];
MiniBoss nine;
MasterBoss ten;

Screen currentScreen;
Screen previousScreen;

Counters counter;
Containers container;

char font;
bool isSoundEnabled, isPaused, isStoryDate, isStoryMarry, isTorture, isHealthUpdate;
int xp, highscore, set, level, music, rank, text1, text2, text3;
int imageTorture, hpTorture, textTorture, healthImage;
