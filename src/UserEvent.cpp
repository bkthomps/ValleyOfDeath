#include "DragonFireSDK.h"
#include "Globals.h"
#include "UserEvent.h"
#include "StateToggle.h"

int onPause(int id, int event, int x, int y) {
    if (event == 1) {
        previousScreen = currentScreen;
        currentScreen = SCREEN_PAUSE;
        screenSwitch();
        isPaused = true;
    }
    return 0;
}

int onResume(int id, int event, int x, int y) {
    if (event == 3) {
        currentScreen = previousScreen;
        screenSwitch();
        isPaused = false;
    }
    return 0;
}

int onReturnToMenu(int id, int event, int x, int y) {
    if (event == 3) {
        reset();
        if (previousScreen == SCREEN_ENDLESS) {
            doUpdateHighscore();
            currentScreen = SCREEN_HIGHSCORE;
        } else if (previousScreen == SCREEN_UNLOCKS || previousScreen == SCREEN_OPTIONS) {
            currentScreen = SCREEN_MENU;
        } else {
            currentScreen = SCREEN_DIED;
        }
        screenSwitch();
    }
    return 0;
}

int onDied(int id, int event, int x, int y) {
    currentScreen = SCREEN_MENU;
    screenSwitch();
    return 0;
}

int onTorture(int id, int event, int x, int y) {
    if (event == 1 || event == 3) {
        isTorture = !isTorture;
    }
    return 0;
}

int onHighscore(int id, int event, int x, int y) {
    currentScreen = SCREEN_MENU;
    screenSwitch();
    TextSetText(text1, "");
    TextSetText(text2, "");
    TextSetText(text3, "");
    return 0;
}

void doHighscore() {
    char lvl[] = "\n\n\n\n\n\n\n\n\n\nHighest Level:   ";
    if (highscore <= 9) {
        lvl[25] = char(highscore + '0');
        TextSetText(text3, lvl);
    } else if (highscore >= 10 && highscore <= 99) {
        int one = highscore / 10;
        int two = highscore % 10;
        lvl[25] = char(one + '0');
        lvl[26] = char(two + '0');
        TextSetText(text3, lvl);
    } else {
        TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 99+");
    }
}

void doUpdateHighscore() {
    if (level > highscore) {
        highscore = level;
    }
    doHighscore();
    (player.health <= 0) ? (TextSetText(text1, "\n\nYou Died.")) : (TextSetText(text1, "\n\nYou Left."));
    char lvl[] = "\n\n\n\n\n\nYou Left At Level   ";
    if (player.health <= 0) {
        char temp[] = "\n\n\n\n\n\nSurvived To";
        for (int i = 0; i < 17; i++) {
            lvl[i] = temp[i];
        }
    }
    if (level <= 9) {
        lvl[25] = char(level + '0');
        TextSetText(text2, lvl);
    } else if (level >= 10 && level <= 99) {
        int one = level / 10;
        int two = level % 10;
        lvl[24] = char(one + '0');
        lvl[25] = char(two + '0');
        TextSetText(text2, lvl);
    } else {
        (player.health <= 0) ? (TextSetText(text2, "\n\n\n\n\n\nSurvived To Level 99+")) :
        (TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 99+"));
    }
    reset();
}

int onOptionsMenuTouch(int id, int event, int x, int y) {
    if (event == 3) {
        currentScreen = SCREEN_OPTIONS;
        screenSwitch();
    }
    return 0;
}

int options(int id, int event, int x, int y) {
    int imageMusic;
    if (id == 1 && event == 3) {
        if (isSoundEnabled) {
            imageMusic = ImageAdd("unlocks/MusicOff.png");
            ViewSetImage(music, imageMusic);
            isSoundEnabled = false;
            Mp3Stop();
        } else {
            imageMusic = ImageAdd("unlocks/MusicOn.png");
            ViewSetImage(music, imageMusic);
            isSoundEnabled = true;
            if (counter.sound >= 1 && counter.sound < 7000) {
                counter.sound = 7000;
            } else if (counter.sound >= 7000 && counter.sound < 13000) {
                counter.sound = 13000;
            } else if (counter.sound >= 13000 && counter.sound < 19000) {
                counter.sound = 19000;
            } else if (counter.sound >= 19000 && counter.sound < 27000) {
                counter.sound = 27000;
            } else if (counter.sound >= 27000 && counter.sound < 34000) {
                counter.sound = 34000;
            } else if (counter.sound >= 34000 && counter.sound < 42000) {
                counter.sound = 42000;
            } else if (counter.sound >= 42000 && counter.sound < 49000) {
                counter.sound = 49000;
            } else if (counter.sound >= 49000 && counter.sound < 55000) {
                counter.sound = 55000;
            } else if (counter.sound >= 55000 && counter.sound < 61000) {
                counter.sound = 61000;
            } else if (counter.sound >= 61000 && counter.sound < 67000) {
                counter.sound = 67000;
            } else if (counter.sound >= 67000 && counter.sound < 73000) {
                counter.sound = 73000;
            } else if (counter.sound >= 73000 && counter.sound < 79000) {
                counter.sound = 79000;
            } else if (counter.sound >= 79000) {
                counter.sound = 1;
            }
        }
    } else if (id == 2 && event == 3) {
        currentScreen = SCREEN_DELETE_CHECK_ONE;
        screenSwitch();
    } else if (id == 3 && event == 3) {
        currentScreen = SCREEN_DELETE_CHECK_TWO;
        screenSwitch();
    } else if (id == 4 && event == 3) {
        xp = 0;
        player.typeOfShip = 1;
        highscore = 0;
        shipType();
        currentScreen = SCREEN_MENU;
        screenSwitch();
    } else if (id == 5 && event == 3) {
        currentScreen = SCREEN_OPTIONS;
        screenSwitch();
    }
    return 0;
}

int onUnlocksMenuTouch(int id, int event, int x, int y) {
    int imageUnlocks;
    if (event == 3) {
        const int RANK_POSITION = TextAdd(container.unlocks, 10, 10, "", font);
        switch (rank) {
            case 1:
                TextSetText(RANK_POSITION, "\n\nLevel 1: Ordinary Shipman");
                break;
            case 2:
                TextSetText(RANK_POSITION, "\n\nLevel 2: Able Shipman");
                break;
            case 3:
                TextSetText(RANK_POSITION, "\n\nLevel 3: Leading Shipman");
                break;
            case 4:
                TextSetText(RANK_POSITION, "\n\nLevel 4: Master Shipman");
                break;
            case 5:
                TextSetText(RANK_POSITION, "\n\nLevel 5: Petty Officer 2nd \n\tClass");
                break;
            case 6:
                TextSetText(RANK_POSITION, "\n\nLevel 6: Petty Officer 1st \n\tClass");
                break;
            case 7:
                TextSetText(RANK_POSITION, "\n\nLevel 7: Chief Petty Officer \n\t2nd Class");
                break;
            case 8:
                TextSetText(RANK_POSITION, "\n\nLevel 8: Chief Petty Officer \n\t1st Class");
                break;
            case 9:
                TextSetText(RANK_POSITION, "\n\nLevel 9: Cadet");
                break;
            case 10:
                TextSetText(RANK_POSITION, "\n\nLevel 10: Ensign");
                break;
            case 11:
                TextSetText(RANK_POSITION, "\n\nLevel 11: Acting \n\t Sub-Lieutenant");
                break;
            case 12:
                TextSetText(RANK_POSITION, "\n\nLevel 12: Sub-Lieutenant");
                break;
            case 13:
                TextSetText(RANK_POSITION, "\n\nLevel 13: Lieutenant");
                break;
            case 14:
                TextSetText(RANK_POSITION, "\n\nLevel 14: Lieutenant \n\t  Commander");
                break;
            case 15:
                TextSetText(RANK_POSITION, "\n\nLevel 15: Commander");
                break;
            case 16:
                TextSetText(RANK_POSITION, "\n\nLevel 16: Captain");
                break;
            case 17:
                TextSetText(RANK_POSITION, "\n\nLevel 17: Commodore");
                break;
            case 18:
                TextSetText(RANK_POSITION, "\n\nLevel 18: Rear-Admiral");
                break;
            case 19:
                TextSetText(RANK_POSITION, "\n\nLevel 19: Vice-Admiral");
                break;
            case 20:
                TextSetText(RANK_POSITION, "\n\nLevel 20: Admiral");
                break;
        }
        imageUnlocks = (rank >= 3) ? (ImageAdd("unlocks/UnShip_2.png")) : (ImageAdd("unlocks/LckShip_2.png"));
        ViewSetImage(ViewAdd(container.unlocks, "unlocks/LckShip_2.png", 120, 180, unlocks, 2), imageUnlocks);
        imageUnlocks = (rank >= 5) ? (ImageAdd("unlocks/UnShip_3.png")) : (ImageAdd("unlocks/LckShip_3.png"));
        ViewSetImage(ViewAdd(container.unlocks, "unlocks/LckShip_3.png", 220, 180, unlocks, 3), imageUnlocks);
        imageUnlocks = (rank >= 8) ? (ImageAdd("unlocks/UnShip_4.png")) : (ImageAdd("unlocks/LckShip_4.png"));
        ViewSetImage(ViewAdd(container.unlocks, "unlocks/LckShip_4.png", 20, 280, unlocks, 4), imageUnlocks);
        imageUnlocks = (rank >= 11) ? (ImageAdd("unlocks/UnShip_5.png")) : (ImageAdd("unlocks/LckShip_5.png"));
        ViewSetImage(ViewAdd(container.unlocks, "unlocks/LckShip_5.png", 120, 280, unlocks, 5), imageUnlocks);
        imageUnlocks = (rank >= 14) ? (ImageAdd("unlocks/UnShip_6.png")) : (ImageAdd("unlocks/LckShip_6.png"));
        ViewSetImage(ViewAdd(container.unlocks, "unlocks/LckShip_6.png", 220, 280, unlocks, 6), imageUnlocks);
        imageUnlocks = (rank >= 17) ? (ImageAdd("unlocks/UnShip_7.png")) : (ImageAdd("unlocks/LckShip_7.png"));
        ViewSetImage(ViewAdd(container.unlocks, "unlocks/LckShip_7.png", 60, 380, unlocks, 7), imageUnlocks);
        imageUnlocks = (rank >= 20) ? (ImageAdd("unlocks/UnShip_8.png")) : (ImageAdd("unlocks/LckShip_8.png"));
        ViewSetImage(ViewAdd(container.unlocks, "unlocks/LckShip_8.png", 180, 380, unlocks, 8), imageUnlocks);
        currentScreen = SCREEN_UNLOCKS;
        screenSwitch();
    }
    return 0;
}

int unlocks(int id, int event, int x, int y) {
    if (event == 3 && isShipUnlocked(id)) {
            player.typeOfShip = id;
            shipType();
            currentScreen = SCREEN_MENU;
            screenSwitch();
    }
    return 0;
}

bool isShipUnlocked(int id) {
    return (id == 1 && rank >= 1) || (id == 2 && rank >= 3) || (id == 3 && rank >= 5) || (id == 4 && rank >= 8) 
        || (id == 5 && rank >= 11) || (id == 6 && rank >= 14) || (id == 7 && rank >= 17) || (id == 8 && rank >= 20);
}

int onEndlessMenuTouch(int id, int event, int x, int y) {
    if (event == 3) {
        reset();
        player.health = player.possibleHealth;
        isHealthUpdate = true;
        level = 1;
        set = 1;
        currentScreen = SCREEN_ENDLESS;
        screenSwitch();
    }
    return 0;
}

int onBattleTouch(int id, int event, int x, int y) {
    if (event == 1 || event == 2) {
        player.newXCoord = x - 47;
        player.newYCoord = y - 47;
    }
    return 0;
}
