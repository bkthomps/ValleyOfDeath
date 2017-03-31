/*
 * Bailey Thompson
 * Valley Of Death (1.3.11)
 * 30 March 2017
 * Info: This is a scrolling shooter iPhone app.
 */

#include <math.h>
#include "DragonFireSDK.h"
#include "Globals.h"
#include "ValleyOfDeath.h"
#include "FileIO.h"
#include "CustomMath.h"
#include "ContainerUnits.h"
#include "StateToggle.h"
#include "UserEvent.h"
#include "Sound.h"
#include "ShipAction.h"
#include "ShipSecondaries.h"

void AppMain() {
    loadGame();
    declareContainers();
    font = FontAdd("Arial", "Regular", 24, 0xA4A4A4);

    screenSwitch();
    containerOne();
    containerTwo();
    containerThree();
    containerFour();
    containerFive();
    containerSixSeven();

    // populate unlocks
    ViewAdd(container.unlocks, "Images/Background.png", 0, 0);
    ViewAdd(container.unlocks, "Images/Pause.png", 270, 20, onPause, 1);
    TextAdd(container.unlocks, 10, 10, "\n\n\n\n\n Pick Your Ship By Clicking", font);
    ViewAdd(container.unlocks, "unlocks/UnShip_1.png", 20, 180, unlocks, 1);
    // populate options
    ViewAdd(container.options, "Images/Background.png", 0, 0);
    ViewAdd(container.options, "Images/Pause.png", 270, 20, onPause, 1);
    char *musicString = (isSoundEnabled) ? ("unlocks/MusicOn.png") : ("unlocks/MusicOff.png");
    music = ViewAdd(container.options, musicString, 20, 80, options, 1);
    TextAdd(container.options, 20, 320, "\nCreated By \nBailey Thompson", font);
    ViewAdd(container.options, "Images/btnDelete.png", 20, 200, options, 2);
    // populate deleteCheckOne
    ViewAdd(container.deleteCheckOne, "Images/Background.png", 0, 0);
    TextAdd(container.deleteCheckOne, 20, 20, "Are you sure you want to \nDELETE ALL PLAYER \nDATA including xp, "
            "rank, \nhighscore, and ships?", font);
    ViewAdd(container.deleteCheckOne, "Images/btnNoDelete.png", 20, 180, options, 5);
    ViewAdd(container.deleteCheckOne, "Images/btnYesDelete.png", 20, 300, options, 3);
    // populate deleteCheckTwo
    ViewAdd(container.deleteCheckTwo, "Images/Background.png", 0, 0);
    TextAdd(container.deleteCheckTwo, 20, 20, "Are you really sure you \nwant to DELETE \nEVERYTHING?", font);
    ViewAdd(container.deleteCheckTwo, "Images/btnNoDelete.png", 20, 300, options, 5);
    ViewAdd(container.deleteCheckTwo, "Images/btnYesDelete.png", 20, 180, options, 4);

    shipType();
    startupMusic();
}

void AppExit() {
    Mp3Stop();
    char fileBuffer[5];
    // fileSound
    int fileSound = FileOpen("Sound.txt");
    boolGameToFile(isSoundEnabled, fileBuffer);
    FileWrite(fileSound, fileBuffer, 1);
    FileClose(fileSound);
    // fileXp
    int fileXp = FileOpen("Xp.txt");
    intGameToFile(xp, fileBuffer);
    FileWrite(fileXp, fileBuffer, 5);
    FileClose(fileXp);
    // fileShip
    int fileShip = FileOpen("Ship.txt");
    intGameToFile(player.typeOfShip, fileBuffer);
    FileWrite(fileShip, fileBuffer, 5);
    FileClose(fileShip);
    // fileHighscore
    int fileHighscore = FileOpen("Highscore.txt");
    intGameToFile(highscore, fileBuffer);
    FileWrite(fileHighscore, fileBuffer, 5);
    FileClose(fileHighscore);
    // fileCounter
    int fileCounter = FileOpen("Counter.txt");
    intGameToFile(counter.sound, fileBuffer);
    FileWrite(fileCounter, fileBuffer, 5);
    FileClose(fileCounter);
}

void OnTimer() {
    // called 30 times per second - 1800=1min - 10000=5min 36sec
    rankFromXp();
    soundSwitch();
    if (isSoundEnabled) {
        counter.sound += 1;
    }
    if (!isPaused) {
        if (createMove()) {
            counter.bulletTime += 1;
            counter.shipMove += 1;
            doEnemyShipMove();
            counter.bulletMove += 1;
            doEnemyShipShoot();
            if (player.health < player.possibleHealth / 2) {
                counter.healthRegen += 1;
            } else {
                counter.healthRegen = 0;
            }
            healthRegen();
            bulletTime();
            healthBar();
            playerShipMove();
            enemyDied();
            shipCollision();
        } else if (currentScreen == SCREEN_STORY_TORTURE && isTorture) {
            switch (counter.torture) {
                case 0:
                    ViewSetxy(imageTorture, -1, -1);
                    break;
                case 1:
                    ViewSetxy(imageTorture, 0, 0);
                    break;
                case 2:
                    ViewSetxy(imageTorture, -2, -2);
                    break;
                case 3:
                    ViewSetxy(imageTorture, -1, -1);
                    break;
                case 4:
                    ViewSetxy(imageTorture, -2, 0);
                    break;
                case 5:
                    ViewSetxy(imageTorture, 0, -2);
                    break;
            }
            counter.hpTorture -= 3;
            counter.torture += 1;
            if (counter.torture >= 6) {
                counter.torture = 0;
            }
            tortureHealth();
        } else if (currentScreen == SCREEN_STORY_TORTURE && !isTorture) {
            counter.hpTorture += 1;
            tortureHealth();
            TextSetText(textTorture, "");
        }
    }
}

void rankFromXp() {
    const double INPUT_VAL = xp / 50;
    rank = (int) (1.38 * sqrt(INPUT_VAL) + 1);
    if (rank > 20) {
        rank = 20;
    }
}

void healthRegen() {
    if (counter.healthRegen >= round(150 * 10 / PLAYER_HEALTH_RATIO)) {
        counter.healthRegen = 0;
        player.health += 1;
        isHealthUpdate = true;
    }
}

bool createMove() {
    return currentScreen == SCREEN_ENDLESS || currentScreen == SCREEN_STORY_BATTLE_1
           || currentScreen == SCREEN_STORY_BATTLE_2 || currentScreen == SCREEN_STORY_BATTLE_4
           || currentScreen == SCREEN_STORY_BATTLE_5 || currentScreen == SCREEN_STORY_BATTLE_6;
}
