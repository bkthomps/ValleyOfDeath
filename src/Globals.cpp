#include "DragonFireSDK.h"
#include "Ships.h"
#include "Screens.h"
#include "GlobalConstants.h"
#include "GlobalStructs.h"

PlayerShip player;
SingleShip one[AMOUNT_OF_TYPE_ONE_SHIPS];
SingleShip two[AMOUNT_OF_TYPE_ONE_SHIPS];
SingleShip three[AMOUNT_OF_TYPE_ONE_SHIPS];
SingleShip four[AMOUNT_OF_TYPE_ONE_SHIPS];
DoubleShip five[AMOUNT_OF_TYPE_TWO_SHIPS];
DoubleShip six[AMOUNT_OF_TYPE_TWO_SHIPS];
RocketShip seven[AMOUNT_OF_TYPE_TWO_SHIPS];
MasterShip eight[AMOUNT_OF_TYPE_TWO_SHIPS];
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
