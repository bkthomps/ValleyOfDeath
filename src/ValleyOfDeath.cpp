/*
 * Bailey Thompson
 * Valley Of Death (1.3.4)
 * 24 March 2017
 * Info: This is a scrolling shooter iPhone app.
 */
 
#include "DragonFireSDK.h"
#include <math.h>
#include "Ships.h"
#include "Screens.h"
#include "CustomMath.h"

const int XP_SHIP_DESTROY_1_TO_4 = 1;
const int XP_SHIP_DESTROY_5_TO_8 = 2;
const int XP_SHIP_DESTROY_9 = 5;
const int XP_SHIP_DESTROY_10 = 10;
const int XP_WIN_GAME = 25;
const int XP_INCREASE = 5;

const int ENEMY_SPAWN_TIME = 80;
const int ENEMY_FLY_SPEED = 4;
const int ENEMY_BULLET_SPEED = 10;
const int ENEMY_BULLET_COOLDOWN_SPEED = 38;

const int PLAYER_HEALTH_RATIO = 10;
const int PLAYER_FLY_SPEED_RATIO = 10;
const int PLAYER_BULLET_SPEED = 18;
const int PLAYER_BULLET_COOLDOWN_SPEED = 18;

SingleShip one[10];
SingleShip two[10];
SingleShip three[10];
SingleShip four[10];
DoubleShip five[5];
DoubleShip six[5];
RocketShip seven[5];
MasterShip eight[5];
MiniBoss nine;
MasterBoss ten;

Screen currentScreen, previousScreen;

char font;
int xp, ship, highscore, health, set, level, shipView, mX, mY, newX, newY, music, possibleHealth, shipSpeed, rank;
int bulletXOffset, bulletYOffset, bulletXOffset2, bulletYOffset2, bulletXOffset3, bulletYOffset3;
int width1, width2, text1, text2, text3, imageTorture, hpTorture, textTorture, healthImage;

namespace bullets {
    int m1[15], m2[15], m3[15];
}

namespace counter {
    int sound, bulletTime, shipMove, bulletMove, hpTorture, torture, shipAction, healthRegen, enemyExplosion[10];
}
namespace state {
    bool sound, pause, date, marry, torture, healthUpdate;
}
namespace container {
    int pause, menu, highscore, endless, died;
    int story1a1, story1a2, story1s3, story1p3, story1a4, story1r5, story1e5;
    int story2a1, story2a2, story2a3, story2b4, story2a5, story2a6, story2e7, story2a7;
    int story3a1, story3b2, story3a3, story3a4, story3a5, story3a6, story3a7, story3a8, storyTorture;
    int story4a1, story4a2, story4a3, story4a4, story4b5, story4a6, story4a7, story4b7, story4a8;
    int story5a1, story5a2, story5a3, story5b4, story5a5, story5a6, story5b6;
    int story6a1, story6a2, story6a3, story6b3;
    int story7w1, story7l1, story7a2, story7b2;
    int unlocks, options, deleteCheckOne, deleteCheckTwo;
}

int intFileToGame(char* buffer) {
    int ret = 0;
    ret += ((int) buffer[0] - '0') * 10000;
    ret += ((int) buffer[1] - '0') * 1000;
    ret += ((int) buffer[2] - '0') * 100;
    ret += ((int) buffer[3] - '0') * 10;
    ret += (int) buffer[4] - '0';
    return ret;
}
bool boolFileToGame(char* buffer) {
    return buffer[0] == 't';
}
void loadGame() {
    int fileSound = FileOpen("Sound.txt");
    int fileXp = FileOpen("Xp.txt");
    int fileShip = FileOpen("Ship.txt");
    int fileHighscore = FileOpen("Highscore.txt");
    int fileCounter = FileOpen("Counter.txt");
    char fileBuffer[5];
    if (!fileSound) {
        fileSound = FileCreate("Sound.txt");
        state::sound = true;
    } else {
        FileRead(fileSound, fileBuffer, 1);
        state::sound = boolFileToGame(fileBuffer);
    }
    if (!fileXp) {
        fileXp = FileCreate("Xp.txt");
    } else {
        FileRead(fileXp, fileBuffer, 5);
        xp = intFileToGame(fileBuffer);
    }
    if (!fileShip) {
        fileShip = FileCreate("Ship.txt");
        ship = 1;
    } else {
        FileRead(fileShip, fileBuffer, 5);
        ship = intFileToGame(fileBuffer);
    }
    if (!fileHighscore) {
        fileHighscore = FileCreate("Highscore.txt");
    } else {
        FileRead(fileHighscore, fileBuffer, 5);
        highscore = intFileToGame(fileBuffer);
    }
    if (!fileCounter) {
        fileCounter = FileCreate("Counter.txt");
    } else {
        FileRead(fileCounter, fileBuffer, 5);
        counter::sound = intFileToGame(fileBuffer);
    }
    FileClose(fileSound);
    FileClose(fileXp);
    FileClose(fileShip);
    FileClose(fileHighscore);
    FileClose(fileCounter);
}
void reset() {
    counter::bulletTime = 0;
    counter::shipMove = 0;
    mX = 113;
    mY = 380;
    newX = 113;
    newY = 380;
    for (int i = 0; i < 15; i++) {
        ViewSetxy(bullets::m1[i], -10, -10);
        ViewSetxy(bullets::m2[i], -20, -20);
        ViewSetxy(bullets::m3[i], -10, -10);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            one[j].setBullet(i, 600, 600);
            two[j].setBullet(i, 600, 600);
            three[j].setBullet(i, 600, 600);
            four[j].setBullet(i, 600, 600);
        }
        for (int j = 0; j < 5; j++) {
            five[j].setBulletOne(i, 600, 600);
            five[j].setBulletTwo(i, 600, 600);
            six[j].setBulletOne(i, 600, 600);
            six[j].setBulletTwo(i, 600, 600);
            seven[j].setRocket(i, 600, 600);
            eight[j].setBulletOne(i, 600, 600);
            eight[j].setRocket(i, 600, 600);
            eight[j].setBulletTwo(i, 600, 600);
        }
        nine.setBulletOne(i, 600, 600);
        nine.setRocket(i, 600, 600);
        nine.setBulletTwo(i, 600, 600);
        ten.setBulletOne(i, 600, 600);
        ten.setRocket(i, 600, 600);
        ten.setBulletTwo(i, 600, 600);
    }
    int picture, ship;
    for (int i = 0; i < 10; i++) {
        one[i].setShip(600, 600);
        ship = one[i].getInstance();
        picture = ImageAdd("Images/eShip_1.png");
        ViewSetImage(ship, picture);
        two[i].setShip(600, 600);
        ship = two[i].getInstance();
        picture = ImageAdd("Images/eShip_2.png");
        ViewSetImage(ship, picture);
        three[i].setShip(600, 600);
        ship = three[i].getInstance();
        picture = ImageAdd("Images/eShip_3.png");
        ViewSetImage(ship, picture);
        four[i].setShip(600, 600);
        ship = four[i].getInstance();
        picture = ImageAdd("Images/eShip_4.png");
        ViewSetImage(ship, picture);
    }
    for (int i = 0; i < 5; i++) {
        five[i].setShip(600, 600);
        ship = five[i].getInstance();
        picture = ImageAdd("Images/eShip_5.png");
        ViewSetImage(ship, picture);
        six[i].setShip(600, 600);
        ship = six[i].getInstance();
        picture = ImageAdd("Images/eShip_6.png");
        ViewSetImage(ship, picture);
        seven[i].setShip(600, 600);
        ship = seven[i].getInstance();
        picture = ImageAdd("Images/eShip_7.png");
        ViewSetImage(ship, picture);
        eight[i].setShip(600, 600);
        ship = eight[i].getInstance();
        picture = ImageAdd("Images/eShip_8.png");
        ViewSetImage(ship, picture);
    }
    nine.setShip(600, 600);
    ship = nine.getInstance();
    picture = ImageAdd("Images/eMini-Boss.png");
    ViewSetImage(ship, picture);
    ten.setShip(600, 600);
    ship = ten.getInstance();
    picture = ImageAdd("Images/eBoss.png");
    ViewSetImage(ship, picture);
    health = possibleHealth;
    state::healthUpdate = true;
    state::pause = false;
}
void screenSwitch() {
    ContainerSetVisible(container::pause, 0);
    ContainerSetVisible(container::menu, 0);
    ContainerSetVisible(container::endless, 0);
    ContainerSetVisible(container::highscore, 0);
    ContainerSetVisible(container::died, 0);
    ContainerSetVisible(container::story1a1, 0);
    ContainerSetVisible(container::story1a2, 0);
    ContainerSetVisible(container::story1s3, 0);
    ContainerSetVisible(container::story1p3, 0);
    ContainerSetVisible(container::story1a4, 0);
    ContainerSetVisible(container::story1r5, 0);
    ContainerSetVisible(container::story1e5, 0);
    ContainerSetVisible(container::story2a1, 0);
    ContainerSetVisible(container::story2a2, 0);
    ContainerSetVisible(container::story2a3, 0);
    ContainerSetVisible(container::story2b4, 0);
    ContainerSetVisible(container::story2a5, 0);
    ContainerSetVisible(container::story2a6, 0);
    ContainerSetVisible(container::story2e7, 0);
    ContainerSetVisible(container::story2a7, 0);
    ContainerSetVisible(container::story3a1, 0);
    ContainerSetVisible(container::story3b2, 0);
    ContainerSetVisible(container::story3a3, 0);
    ContainerSetVisible(container::story3a4, 0);
    ContainerSetVisible(container::story3a5, 0);
    ContainerSetVisible(container::story3a6, 0);
    ContainerSetVisible(container::story3a7, 0);
    ContainerSetVisible(container::story3a8, 0);
    ContainerSetVisible(container::storyTorture, 0);
    ContainerSetVisible(container::story4a1, 0);
    ContainerSetVisible(container::story4a2, 0);
    ContainerSetVisible(container::story4a3, 0);
    ContainerSetVisible(container::story4a4, 0);
    ContainerSetVisible(container::story4b5, 0);
    ContainerSetVisible(container::story4a6, 0);
    ContainerSetVisible(container::story4a7, 0);
    ContainerSetVisible(container::story4b7, 0);
    ContainerSetVisible(container::story4a8, 0);
    ContainerSetVisible(container::story5a1, 0);
    ContainerSetVisible(container::story5a2, 0);
    ContainerSetVisible(container::story5a3, 0);
    ContainerSetVisible(container::story5b4, 0);
    ContainerSetVisible(container::story5a5, 0);
    ContainerSetVisible(container::story5a6, 0);
    ContainerSetVisible(container::story5b6, 0);
    ContainerSetVisible(container::story6a1, 0);
    ContainerSetVisible(container::story6a2, 0);
    ContainerSetVisible(container::story6a3, 0);
    ContainerSetVisible(container::story6b3, 0);
    ContainerSetVisible(container::story7w1, 0);
    ContainerSetVisible(container::story7l1, 0);
    ContainerSetVisible(container::story7a2, 0);
    ContainerSetVisible(container::story7b2, 0);
    ContainerSetVisible(container::unlocks, 0);
    ContainerSetVisible(container::options, 0);
    ContainerSetVisible(container::deleteCheckOne, 0);
    ContainerSetVisible(container::deleteCheckTwo, 0);
    switch (currentScreen) {
        case SCREEN_PAUSE:
            ContainerSetVisible(container::pause, 1);
            break;
        case SCREEN_MENU:
            ContainerSetVisible(container::menu, 1);
            break;
        case SCREEN_HIGHSCORE:
            ContainerSetVisible(container::highscore, 1);
            break;
        case SCREEN_DIED:
            ContainerSetVisible(container::died, 1);
            break;
        case SCREEN_ENDLESS:
            ContainerSetVisible(container::endless, 1);
            break;
        case SCREEN_STORY_1A1:
            ContainerSetVisible(container::story1a1, 1);
            break;
        case SCREEN_STORY_1A2:
            ContainerSetVisible(container::story1a2, 1);
            break;
        case SCREEN_STORY_1S3:
            ContainerSetVisible(container::story1s3, 1);
            break;
        case SCREEN_STORY_1P3:
            ContainerSetVisible(container::story1p3, 1);
            break;
        case SCREEN_STORY_1A4:
            ContainerSetVisible(container::story1a4, 1);
            break;
        case SCREEN_STORY_1R5:
            ContainerSetVisible(container::story1r5, 1);
            break;
        case SCREEN_STORY_1E5:
            ContainerSetVisible(container::story1e5, 1);
            break;
        case SCREEN_STORY_BATTLE_1:
            ContainerSetVisible(container::endless, 1);
            break;
        case SCREEN_STORY_2A1:
            ContainerSetVisible(container::story2a1, 1);
            break;
        case SCREEN_STORY_2A2:
            ContainerSetVisible(container::story2a2, 1);
            break;
        case SCREEN_STORY_2A3:
            ContainerSetVisible(container::story2a3, 1);
            break;
        case SCREEN_STORY_2B4:
            ContainerSetVisible(container::story2b4, 1);
            break;
        case SCREEN_STORY_2A5:
            ContainerSetVisible(container::story2a5, 1);
            break;
        case SCREEN_STORY_2A6:
            ContainerSetVisible(container::story2a6, 1);
            break;
        case SCREEN_STORY_2E7:
            ContainerSetVisible(container::story2e7, 1);
            break;
        case SCREEN_STORY_2A7:
            ContainerSetVisible(container::story2a7, 1);
            break;
        case SCREEN_STORY_BATTLE_2:
            ContainerSetVisible(container::endless, 1);
            break;
        case SCREEN_STORY_3A1:
            ContainerSetVisible(container::story3a1, 1);
            break;
        case SCREEN_STORY_3B2:
            ContainerSetVisible(container::story3b2, 1);
            break;
        case SCREEN_STORY_3A3:
            ContainerSetVisible(container::story3a3, 1);
            break;
        case SCREEN_STORY_3A4:
            ContainerSetVisible(container::story3a4, 1);
            break;
        case SCREEN_STORY_3A5:
            ContainerSetVisible(container::story3a5, 1);
            break;
        case SCREEN_STORY_3A6:
            ContainerSetVisible(container::story3a6, 1);
            break;
        case SCREEN_STORY_3A7:
            ContainerSetVisible(container::story3a7, 1);
            break;
        case SCREEN_STORY_3A8:
            ContainerSetVisible(container::story3a8, 1);
            break;
        case SCREEN_STORY_TORTURE:
            int imageTorturing;
            imageTorturing = ImageAdd("Images/20HP.png");
            ViewSetImage(hpTorture, imageTorturing);
            counter::hpTorture = 2000;
            counter::torture = 0;
            ContainerSetVisible(container::storyTorture, 1);
            break;
        case SCREEN_STORY_4A1:
            ContainerSetVisible(container::story4a1, 1);
            break;
        case SCREEN_STORY_4A2:
            ContainerSetVisible(container::story4a2, 1);
            break;
        case SCREEN_STORY_4A3:
            ContainerSetVisible(container::story4a3, 1);
            break;
        case SCREEN_STORY_4A4:
            ContainerSetVisible(container::story4a4, 1);
            break;
        case SCREEN_STORY_4B5:
            ContainerSetVisible(container::story4b5, 1);
            break;
        case SCREEN_STORY_4A6:
            ContainerSetVisible(container::story4a6, 1);
            break;
        case SCREEN_STORY_4A7:
            ContainerSetVisible(container::story4a7, 1);
            break;
        case SCREEN_STORY_4B7:
            ContainerSetVisible(container::story4b7, 1);
            break;
        case SCREEN_STORY_4A8:
            ContainerSetVisible(container::story4a8, 1);
            break;
        case SCREEN_STORY_BATTLE_4:
            ContainerSetVisible(container::endless, 1);
            break;
        case SCREEN_STORY_5A1:
            ContainerSetVisible(container::story5a1, 1);
            break;
        case SCREEN_STORY_5A2:
            ContainerSetVisible(container::story5a2, 1);
            break;
        case SCREEN_STORY_5A3:
            ContainerSetVisible(container::story5a3, 1);
            break;
        case SCREEN_STORY_5B4:
            ContainerSetVisible(container::story5b4, 1);
            break;
        case SCREEN_STORY_5A5:
            ContainerSetVisible(container::story5a5, 1);
            break;
        case SCREEN_STORY_5A6:
            ContainerSetVisible(container::story5a6, 1);
            break;
        case SCREEN_STORY_5B6:
            ContainerSetVisible(container::story5b6, 1);
            break;
        case SCREEN_STORY_BATTLE_5:
            ContainerSetVisible(container::endless, 1);
            break;
        case SCREEN_STORY_6A1:
            ContainerSetVisible(container::story6a1, 1);
            break;
        case SCREEN_STORY_6A2:
            ContainerSetVisible(container::story6a2, 1);
            break;
        case SCREEN_STORY_6A3:
            ContainerSetVisible(container::story6a3, 1);
            break;
        case SCREEN_STORY_6B3:
            ContainerSetVisible(container::story6b3, 1);
            break;
        case SCREEN_STORY_BATTLE_6:
            ContainerSetVisible(container::endless, 1);
            break;
        case SCREEN_STORY_7W1:
            ContainerSetVisible(container::story7w1, 1);
            break;
        case SCREEN_STORY_7L1:
            ContainerSetVisible(container::story7l1, 1);
            break;
        case SCREEN_STORY_7A2:
            ContainerSetVisible(container::story7a2, 1);
            break;
        case SCREEN_STORY_7B2:
            ContainerSetVisible(container::story7b2, 1);
            break;
        case SCREEN_UNLOCKS:
            ContainerSetVisible(container::unlocks, 1);
            break;
        case SCREEN_OPTIONS:
            ContainerSetVisible(container::options, 1);
            break;
        case SCREEN_DELETE_CHECK_ONE:
            ContainerSetVisible(container::deleteCheckOne, 1);
            break;
        case SCREEN_DELETE_CHECK_TWO:
            ContainerSetVisible(container::deleteCheckTwo, 1);
            break;
    }
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
    (health <= 0) ? (TextSetText(text1, "\n\nYou Died.")) : (TextSetText(text1, "\n\nYou Left."));
    char lvl[] = "\n\n\n\n\n\nYou Left At Level   ";
    if (health <= 0) {
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
        (health <= 0) ? (TextSetText(text2, "\n\n\n\n\n\nSurvived To Level 99+")) :
        (TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 99+"));
    }
    reset();
}

int onTorture(int id, int event, int x, int y) {
    if (event == 1 || event == 3) {
        state::torture = !state::torture;
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
int onDied(int id, int event, int x, int y) {
    currentScreen = SCREEN_MENU;
    screenSwitch();
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
int onResume(int id, int event, int x, int y) {
    if (event == 3) {
        currentScreen = previousScreen;
        screenSwitch();
        state::pause = false;
    }
    return 0;
}
int onPause(int id, int event, int x, int y) {
    if (event == 1) {
        previousScreen = currentScreen;
        currentScreen = SCREEN_PAUSE;
        screenSwitch();
        state::pause = true;
    }
    return 0;
}

int onStoryLevelSeven(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1) {
            currentScreen = SCREEN_STORY_7A2;
        } else if (id == 2) {
            const int SAVE_RON = TextAdd(container::story7b2, 0, 0, "", font);
            if (state::date && !state::marry) {
                TextSetText(SAVE_RON, "\n\nRon: \nThe world will know of your \ngreatness. I will be sure to \ntell "
                    "your girlfriend that you \nwere a great man.");
            } else if (state::date && state::marry) {
                TextSetText(SAVE_RON, "\n\nRon: \nThe world will know of your \ngreatness. I will be sure to \ntell "
                    "your wife that you were a \ngreat man.");
            } else if (!state::date && !state::marry) {
                TextSetText(SAVE_RON, "\n\nRon: \nThe world will know of your \ngreatness.");
            }
            currentScreen = SCREEN_STORY_7B2;
        } else if (id == 3) {
            xp += XP_WIN_GAME;
            currentScreen = SCREEN_MENU;
        }
        screenSwitch();
    }
    return 0;
}
int onStoryLevelSix(int id, int event, int x, int y) {
    if (event == 3) {
        switch (id) {
            case 1:
                currentScreen = SCREEN_STORY_6A2;
                break;
            case 2:
                currentScreen = SCREEN_STORY_6A3;
                break;
            case 3:
                currentScreen = SCREEN_STORY_6B3;
                break;
            case 4:
                currentScreen = SCREEN_STORY_BATTLE_6;
                screenSwitch();
                reset();
                set = 5;
                level = 1;
                break;
        }
        if (id != 4) {
            screenSwitch();
        }
    }
    return 0;
}
int onStoryLevelFive(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1 && !state::date) {
            currentScreen = SCREEN_STORY_5A3;
        } else if (id == 1 && state::date) {
            currentScreen = SCREEN_STORY_5A2;
        } else if (id == 2) {
            state::marry = true;
            currentScreen = SCREEN_STORY_5A3;
        } else if (id == 8) {
            state::marry = false;
            currentScreen = SCREEN_STORY_5A3;
        } else if (id == 3) {
            currentScreen = SCREEN_STORY_5B4;
        } else if (id == 4) {
            currentScreen = SCREEN_STORY_5A5;
        } else if (id == 5) {
            currentScreen = SCREEN_STORY_5A6;
        } else if (id == 6) {
            currentScreen = SCREEN_STORY_5B6;
        }
        if (id == 7) {
            currentScreen = SCREEN_STORY_BATTLE_5;
            screenSwitch();
            reset();
            set = 4;
            level = 1;
        } else {
            screenSwitch();
        }
    }
    return 0;
}
int onStoryLevelFour(int id, int event, int x, int y) {
    if (event == 3) {
        switch (id) {
            case 1:
                currentScreen = SCREEN_DIED;
                break;
            case 2:
                currentScreen = SCREEN_STORY_4A2;
                break;
            case 3:
                currentScreen = SCREEN_STORY_4A3;
                break;
            case 4:
                currentScreen = SCREEN_STORY_4A4;
                break;
            case 5:
                currentScreen = SCREEN_STORY_4B5;
                break;
            case 6:
                currentScreen = SCREEN_STORY_4A6;
                break;
            case 7:
                currentScreen = SCREEN_STORY_4A7;
                break;
            case 8:
                currentScreen = SCREEN_STORY_4B7;
                break;
            case 9:
                currentScreen = SCREEN_STORY_4A8;
                break;
            case 10:
                currentScreen = SCREEN_STORY_BATTLE_4;
                screenSwitch();
                reset();
                set = 3;
                level = 1;
                break;
        }
        if (id != 10) {
            screenSwitch();
        }
    }
    return 0;
}
int onStoryLevelThree(int id, int event, int x, int y) {
    if (event == 3) {
        switch (id) {
            case 1:
                currentScreen = SCREEN_STORY_3B2;
                break;
            case 2:
                currentScreen = SCREEN_STORY_3A3;
                break;
            case 3:
                currentScreen = SCREEN_STORY_3A4;
                break;
            case 4:
                currentScreen = SCREEN_STORY_3A5;
                break;
            case 5:
                currentScreen = SCREEN_STORY_3A6;
                break;
            case 6:
                currentScreen = SCREEN_STORY_3A7;
                break;
            case 7:
                currentScreen = SCREEN_STORY_3A8;
                break;
            case 8:
                currentScreen = SCREEN_STORY_TORTURE;
                break;
        }
        screenSwitch();
    }
    return 0;
}
int onStoryLevelTwo(int id, int event, int x, int y) {
    if (event == 3) {
        switch (id) {
            case 1:
                currentScreen = SCREEN_STORY_2A2;
                break;
            case 3:
                state::date = true;
                currentScreen = SCREEN_STORY_2A3;
                break;
            case 4:
                state::date = false;
                currentScreen = SCREEN_STORY_2A3;
                break;
            case 5:
                currentScreen = SCREEN_STORY_2A5;
                break;
            case 6:
                currentScreen = SCREEN_STORY_2B4;
                break;
            case 7:
                currentScreen = SCREEN_STORY_2A5;
                break;
            case 8:
                currentScreen = SCREEN_STORY_2A6;
                break;
            case 9:
                currentScreen = SCREEN_STORY_2E7;
                break;
            case 10:
                currentScreen = SCREEN_STORY_2A7;
                break;
            case 11:
                currentScreen = SCREEN_STORY_BATTLE_2;
                screenSwitch();
                reset();
                set = 2;
                level = 1;
                break;
        }
        if (id != 11) {
            screenSwitch();
        }
    }
    return 0;
}
int onStoryLevelOne(int id, int event, int x, int y) {
    if (event == 3) {
        switch (id) {
            case 1:
                currentScreen = SCREEN_STORY_1A2;
                break;
            case 3:
                currentScreen = SCREEN_STORY_1S3;
                break;
            case 4:
                currentScreen = SCREEN_STORY_1P3;
                break;
            case 5:
                currentScreen = SCREEN_STORY_1A4;
                break;
            case 6:
                currentScreen = SCREEN_STORY_1R5;
                break;
            case 7:
                currentScreen = SCREEN_STORY_1E5;
                break;
            case 8:
                currentScreen = SCREEN_STORY_BATTLE_1;
                screenSwitch();
                reset();
                set = 1;
                level = 1;
                break;
        }
        if (id != 8) {
            screenSwitch();
        }
    }
    return 0;
}
int onStoryMenuTouch(int id, int event, int x, int y) {
    if (event == 3) {
        currentScreen = SCREEN_STORY_1A1;
        screenSwitch();
    }
    return 0;
}

void shipType() {
    const int LIFT = 10;
    ViewSetxy(shipView, -200, -200);
    possibleHealth = round((18 + 2 * ship) * PLAYER_HEALTH_RATIO / 10);
    switch (ship) {
        case 1:
            shipView = ViewAdd(container::endless, "Images/Ship_1.png", -200, -200);
            bulletXOffset = 43;
            bulletYOffset = 11 - LIFT;
            shipSpeed = round(7 * PLAYER_FLY_SPEED_RATIO / 10);
            width1 = 9;
            width2 = 76;
            break;
        case 2:
            shipView = ViewAdd(container::endless, "Images/Ship_2.png", -200, -200);
            bulletXOffset = 43;
            bulletYOffset = 0 - LIFT;
            shipSpeed = round(7 * PLAYER_FLY_SPEED_RATIO / 10);
            width1 = 15;
            width2 = 69;
            break;
        case 3:
            shipView = ViewAdd(container::endless, "Images/Ship_3.png", -200, -200);
            bulletXOffset = 43;
            bulletYOffset = 6 - LIFT;
            shipSpeed = round(7 * PLAYER_FLY_SPEED_RATIO / 10);
            width1 = 18;
            width2 = 66;
            break;
        case 4:
            shipView = ViewAdd(container::endless, "Images/Ship_4.png", -200, -200);
            bulletXOffset = 43;
            bulletYOffset = 0 - LIFT;
            shipSpeed = round(7 * PLAYER_FLY_SPEED_RATIO / 10);
            width1 = -3;
            width2 = 87;
            break;
        case 5:
            shipView = ViewAdd(container::endless, "Images/Ship_5.png", -200, -200);
            bulletXOffset = 31;
            bulletYOffset = 23 - LIFT;
            bulletXOffset3 = 54;
            bulletYOffset3 = 23 - LIFT;
            shipSpeed = round(6 * PLAYER_FLY_SPEED_RATIO / 10);
            width1 = 13;
            width2 = 71;
            break;
        case 6:
            shipView = ViewAdd(container::endless, "Images/Ship_6.png", -200, -200);
            bulletXOffset = 15;
            bulletYOffset = 41 - LIFT;
            bulletXOffset3 = 68;
            bulletYOffset3 = 41 - LIFT;
            shipSpeed = round(6 * PLAYER_FLY_SPEED_RATIO / 10);
            width1 = 3;
            width2 = 81;
            break;
        case 7:
            shipView = ViewAdd(container::endless, "Images/Ship_7.png", -200, -200);
            bulletXOffset2 = 42;
            bulletYOffset2 = 11 - LIFT;
            shipSpeed = round(5 * PLAYER_FLY_SPEED_RATIO / 10);
            width1 = -2;
            width2 = 86;
            break;
        case 8:
            shipView = ViewAdd(container::endless, "Images/Ship_8.png", -200, -200);
            bulletXOffset = 12;
            bulletYOffset = 40 - LIFT;
            bulletXOffset2 = 42;
            bulletYOffset2 = 2 - LIFT;
            bulletXOffset3 = 74;
            bulletYOffset3 = 40 - LIFT;
            shipSpeed = round(4 * PLAYER_FLY_SPEED_RATIO / 10);
            width1 = -3;
            width2 = 86;
            break;
    }
}
int onBattleTouch(int id, int event, int x, int y) {
    if (event == 1 || event == 2) {
        newX = x - 47;
        newY = y - 47;
    }
    return 0;
}
int onEndlessMenuTouch(int id, int event, int x, int y) {
    if (event == 3) {
        reset();
        health = possibleHealth;
        state::healthUpdate = true;
        level = 1;
        set = 1;
        currentScreen = SCREEN_ENDLESS;
        screenSwitch();
    }
    return 0;
}

bool isShipUnlocked(int id) {
    return (id == 1 && rank >= 1) || (id == 2 && rank >= 3) || (id == 3 && rank >= 5) || (id == 4 && rank >= 8) 
        || (id == 5 && rank >= 11) || (id == 6 && rank >= 14) || (id == 7 && rank >= 17) || (id == 8 && rank >= 20);
}
int unlocks(int id, int event, int x, int y) {
    if (event == 3 && isShipUnlocked(id)) {
            ship = id;
            shipType();
            currentScreen = SCREEN_MENU;
            screenSwitch();
    }
    return 0;
}
int onUnlocksMenuTouch(int id, int event, int x, int y) {
    int imageUnlocks;
    if (event == 3) {
        const int RANK_POSITION = TextAdd(container::unlocks, 10, 10, "", font);
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
        ViewSetImage(ViewAdd(container::unlocks, "unlocks/LckShip_2.png", 120, 180, unlocks, 2), imageUnlocks);
        imageUnlocks = (rank >= 5) ? (ImageAdd("unlocks/UnShip_3.png")) : (ImageAdd("unlocks/LckShip_3.png"));
        ViewSetImage(ViewAdd(container::unlocks, "unlocks/LckShip_3.png", 220, 180, unlocks, 3), imageUnlocks);
        imageUnlocks = (rank >= 8) ? (ImageAdd("unlocks/UnShip_4.png")) : (ImageAdd("unlocks/LckShip_4.png"));
        ViewSetImage(ViewAdd(container::unlocks, "unlocks/LckShip_4.png", 20, 280, unlocks, 4), imageUnlocks);
        imageUnlocks = (rank >= 11) ? (ImageAdd("unlocks/UnShip_5.png")) : (ImageAdd("unlocks/LckShip_5.png"));
        ViewSetImage(ViewAdd(container::unlocks, "unlocks/LckShip_5.png", 120, 280, unlocks, 5), imageUnlocks);
        imageUnlocks = (rank >= 14) ? (ImageAdd("unlocks/UnShip_6.png")) : (ImageAdd("unlocks/LckShip_6.png"));
        ViewSetImage(ViewAdd(container::unlocks, "unlocks/LckShip_6.png", 220, 280, unlocks, 6), imageUnlocks);
        imageUnlocks = (rank >= 17) ? (ImageAdd("unlocks/UnShip_7.png")) : (ImageAdd("unlocks/LckShip_7.png"));
        ViewSetImage(ViewAdd(container::unlocks, "unlocks/LckShip_7.png", 60, 380, unlocks, 7), imageUnlocks);
        imageUnlocks = (rank >= 20) ? (ImageAdd("unlocks/UnShip_8.png")) : (ImageAdd("unlocks/LckShip_8.png"));
        ViewSetImage(ViewAdd(container::unlocks, "unlocks/LckShip_8.png", 180, 380, unlocks, 8), imageUnlocks);
        currentScreen = SCREEN_UNLOCKS;
        screenSwitch();
    }
    return 0;
}

int options(int id, int event, int x, int y) {
    int imageMusic;
    if (id == 1 && event == 3) {
        if (state::sound) {
            imageMusic = ImageAdd("unlocks/MusicOff.png");
            ViewSetImage(music, imageMusic);
            state::sound = false;
            Mp3Stop();
        } else {
            imageMusic = ImageAdd("unlocks/MusicOn.png");
            ViewSetImage(music, imageMusic);
            state::sound = true;
            if (counter::sound >= 1 && counter::sound < 7000) {
                counter::sound = 7000;
            } else if (counter::sound >= 7000 && counter::sound < 13000) {
                counter::sound = 13000;
            } else if (counter::sound >= 13000 && counter::sound < 19000) {
                counter::sound = 19000;
            } else if (counter::sound >= 19000 && counter::sound < 27000) {
                counter::sound = 27000;
            } else if (counter::sound >= 27000 && counter::sound < 34000) {
                counter::sound = 34000;
            } else if (counter::sound >= 34000 && counter::sound < 42000) {
                counter::sound = 42000;
            } else if (counter::sound >= 42000 && counter::sound < 49000) {
                counter::sound = 49000;
            } else if (counter::sound >= 49000 && counter::sound < 55000) {
                counter::sound = 55000;
            } else if (counter::sound >= 55000 && counter::sound < 61000) {
                counter::sound = 61000;
            } else if (counter::sound >= 61000 && counter::sound < 67000) {
                counter::sound = 67000;
            } else if (counter::sound >= 67000 && counter::sound < 73000) {
                counter::sound = 73000;
            } else if (counter::sound >= 73000 && counter::sound < 79000) {
                counter::sound = 79000;
            } else if (counter::sound >= 79000) {
                counter::sound = 1;
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
        ship = 1;
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
int onOptionsMenuTouch(int id, int event, int x, int y) {
    if (event == 3) {
        currentScreen = SCREEN_OPTIONS;
        screenSwitch();
    }
    return 0;
}

void declareContainers() {
    container::pause = ContainerAdd(0, 0, 0);
    container::menu = ContainerAdd(0, 0, 0);
    container::highscore = ContainerAdd(0, 0, 0);
    container::endless = ContainerAdd(0, 0, 0);
    container::died = ContainerAdd(0, 0, 0);
    container::story1a1 = ContainerAdd(0, 0, 0);
    container::story1a2 = ContainerAdd(0, 0, 0);
    container::story1s3 = ContainerAdd(0, 0, 0);
    container::story1p3 = ContainerAdd(0, 0, 0);
    container::story1a4 = ContainerAdd(0, 0, 0);
    container::story1r5 = ContainerAdd(0, 0, 0);
    container::story1e5 = ContainerAdd(0, 0, 0);
    container::story2a1 = ContainerAdd(0, 0, 0);
    container::story2a2 = ContainerAdd(0, 0, 0);
    container::story2a3 = ContainerAdd(0, 0, 0);
    container::story2b4 = ContainerAdd(0, 0, 0);
    container::story2a5 = ContainerAdd(0, 0, 0);
    container::story2a6 = ContainerAdd(0, 0, 0);
    container::story2e7 = ContainerAdd(0, 0, 0);
    container::story2a7 = ContainerAdd(0, 0, 0);
    container::story3a1 = ContainerAdd(0, 0, 0);
    container::story3b2 = ContainerAdd(0, 0, 0);
    container::story3a3 = ContainerAdd(0, 0, 0);
    container::story3a4 = ContainerAdd(0, 0, 0);
    container::story3a5 = ContainerAdd(0, 0, 0);
    container::story3a6 = ContainerAdd(0, 0, 0);
    container::story3a7 = ContainerAdd(0, 0, 0);
    container::story3a8 = ContainerAdd(0, 0, 0);
    container::storyTorture = ContainerAdd(0, 0, 0);
    container::story4a1 = ContainerAdd(0, 0, 0);
    container::story4a2 = ContainerAdd(0, 0, 0);
    container::story4a3 = ContainerAdd(0, 0, 0);
    container::story4a4 = ContainerAdd(0, 0, 0);
    container::story4b5 = ContainerAdd(0, 0, 0);
    container::story4a6 = ContainerAdd(0, 0, 0);
    container::story4a7 = ContainerAdd(0, 0, 0);
    container::story4b7 = ContainerAdd(0, 0, 0);
    container::story4a8 = ContainerAdd(0, 0, 0);
    container::story5a1 = ContainerAdd(0, 0, 0);
    container::story5a2 = ContainerAdd(0, 0, 0);
    container::story5a3 = ContainerAdd(0, 0, 0);
    container::story5b4 = ContainerAdd(0, 0, 0);
    container::story5a5 = ContainerAdd(0, 0, 0);
    container::story5a6 = ContainerAdd(0, 0, 0);
    container::story5b6 = ContainerAdd(0, 0, 0);
    container::story6a1 = ContainerAdd(0, 0, 0);
    container::story6a2 = ContainerAdd(0, 0, 0);
    container::story6a3 = ContainerAdd(0, 0, 0);
    container::story6b3 = ContainerAdd(0, 0, 0);
    container::story7w1 = ContainerAdd(0, 0, 0);
    container::story7l1 = ContainerAdd(0, 0, 0);
    container::story7a2 = ContainerAdd(0, 0, 0);
    container::story7b2 = ContainerAdd(0, 0, 0);
    container::unlocks = ContainerAdd(0, 0, 0);
    container::options = ContainerAdd(0, 0, 0);
    container::deleteCheckOne = ContainerAdd(0, 0, 0);
    container::deleteCheckTwo = ContainerAdd(0, 0, 0);
}
void containerSixSeven() {
    //populate container::story6a1
    ViewAdd(container::story6a1, "Images/Background.png", 0, 0);
    ViewAdd(container::story6a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story6a1, "Images/btnOkBig.png", 20, 380, onStoryLevelSix, 1);
    TextAdd(container::story6a1, 0, 0, "\n\nRon: \nGreat work, now go kill the \nenemy admiral!", font);
    //populate container::story6a2
    ViewAdd(container::story6a2, "Images/Background.png", 0, 0);
    ViewAdd(container::story6a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story6a2, "Images/btnLaugh.png", 20, 380, onStoryLevelSix, 2);
    ViewAdd(container::story6a2, "Images/btnSo.png", 170, 380, onStoryLevelSix, 3);
    TextAdd(container::story6a2, 0, 0, "\n\nAdmiral Skerbowh: \nYou will never be able to \ndefeat me. I am simply", 
        font);
    TextAdd(container::story6a2, 0, 0, "\n\n\n\n\nsmarter, stronger, faster, and \nmore powerful than you.", font);
    //populate container::story6a3
    ViewAdd(container::story6a3, "Images/Background.png", 0, 0);
    ViewAdd(container::story6a3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story6a3, "Images/btnOkSmall.png", 20, 380, onStoryLevelSix, 4);
    ViewAdd(container::story6a3, "Images/btnLaugh.png", 170, 380, onStoryLevelSix, 4);
    TextAdd(container::story6a3, 0, 0, "\n\nAdmiral Skerbowh: \nYou laugh in the face of \ndeath? I laugh at your", 
        font);
    TextAdd(container::story6a3, 0, 0, "\n\n\n\n\nconfidence; however, you \ntruly cannot believe that you \nmay "
        "emerge victorious.", font);
    //populate container::story6b3
    ViewAdd(container::story6b3, "Images/Background.png", 0, 0);
    ViewAdd(container::story6b3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story6b3, "Images/btnOkSmall.png", 20, 380, onStoryLevelSix, 4);
    ViewAdd(container::story6b3, "Images/btnLaugh.png", 170, 380, onStoryLevelSix, 4);
    TextAdd(container::story6b3, 0, 0, "\n\nAdmiral Skerbowh: \nSo... You aren't intelligent \nenough to comprehend "
        "your", font);
    TextAdd(container::story6b3, 0, 0, "\n\n\n\n\ncertain and eventual death.", font);
    //populate container::story7w1
    ViewAdd(container::story7w1, "Images/Background.png", 0, 0);
    ViewAdd(container::story7w1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story7w1, "Images/btnOkBig.png", 20, 380, onStoryLevelSeven, 3);
    TextAdd(container::story7w1, 0, 0, "\n\nRon: \nYou defeated the enemy \nadmiral. The world will know \nof your "
        "greatness.", font);
    //populate container::story7l1
    ViewAdd(container::story7l1, "Images/Background.png", 0, 0);
    ViewAdd(container::story7l1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story7l1, "Images/btnMyself.png", 20, 380, onStoryLevelSeven, 1);
    ViewAdd(container::story7l1, "Images/btnRon.png", 170, 380, onStoryLevelSeven, 2);
    TextAdd(container::story7l1, 0, 0, "\n\nAlex: \nMy ship has sustained critical \ndamage. Every single escape \npod "
        "other than one has been", font);
    TextAdd(container::story7l1, 0, 0, "\n\n\n\n\n\ntaken or destroyed. Should I \nsave myself or Ron?", font);
    //populate container::story7a2
    ViewAdd(container::story7a2, "Images/Background.png", 0, 0);
    ViewAdd(container::story7a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story7a2, "Images/btnOkBig.png", 20, 380, onStoryLevelSeven, 3);
    TextAdd(container::story7a2, 0, 0, "\n\nExecutioner: \nYou are being executed for \ntreason since you abandoned "
        "\nyour ship and crew to die.", font);
    //populate container::story7b2
    ViewAdd(container::story7b2, "Images/Background.png", 0, 0);
    ViewAdd(container::story7b2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story7b2, "Images/btnOkBig.png", 20, 380, onStoryLevelSeven, 3);
}
void containerFive() {
    //populate container::story5a1
    ViewAdd(container::story5a1, "Images/Background.png", 0, 0);
    ViewAdd(container::story5a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story5a1, "Images/btnOkSmall.png", 20, 380, onStoryLevelFive, 1);
    ViewAdd(container::story5a1, "Images/btnThanks.png", 170, 380, onStoryLevelFive, 1);
    TextAdd(container::story5a1, 0, 0, "\n\nCommodore Bailey: \nCongratulations on your way \nback. For your great "
        "action", font);
    TextAdd(container::story5a1, 0, 0, "\n\n\n\n\nout there, you have become \npilot of your own ship named \nICC "
        "Kepler.", font);
    //populate container::story5a2
    ViewAdd(container::story5a2, "Images/Background.png", 0, 0);
    ViewAdd(container::story5a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story5a2, "Images/btnYes.png", 20, 380, onStoryLevelFive, 2);
    ViewAdd(container::story5a2, "Images/btnNo.png", 170, 380, onStoryLevelFive, 8);
    TextAdd(container::story5a2, 0, 0, "\n\nBecca: \nWill you state::marry me?", font);
    //populate container::story5a3
    ViewAdd(container::story5a3, "Images/Background.png", 0, 0);
    ViewAdd(container::story5a3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story5a3, "Images/btnNo.png", 20, 380, onStoryLevelFive, 3);
    ViewAdd(container::story5a3, "Images/btnOkSmall.png", 170, 380, onStoryLevelFive, 4);
    TextAdd(container::story5a3, 0, 0, "\n\nRon: \nWe located the escaped \nenemy. He is an admiral so \nhe is well "
        "guarded, killing him", font);
    TextAdd(container::story5a3, 0, 0, "\n\n\n\n\n\nwill be no easy feat. I will \ncome with you since I myself \nknow "
        "where the enemy \nadmiral is.", font);
    //populate container::story5b4
    ViewAdd(container::story5b4, "Images/Background.png", 0, 0);
    ViewAdd(container::story5b4, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story5b4, "Images/btnOkSmall.png", 20, 380, onStoryLevelFive, 4);
    ViewAdd(container::story5b4, "Images/btnSorry.png", 170, 380, onStoryLevelFive, 4);
    TextAdd(container::story5b4, 0, 0, "\n\nRon: \nFederation orders, sorry \nmate.", font);
    //populate container::story5a5
    ViewAdd(container::story5a5, "Images/Background.png", 0, 0);
    ViewAdd(container::story5a5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story5a5, "Images/btnAround.png", 20, 380, onStoryLevelFive, 5);
    ViewAdd(container::story5a5, "Images/btnAttack.png", 170, 380, onStoryLevelFive, 6);
    TextAdd(container::story5a5, 0, 0, "\n\nRon: \nThere's a whole platoon of \nships. Do you go around and \ntry to "
        "avoid them, or do you", font);
    TextAdd(container::story5a5, 0, 0, "\n\n\n\n\n\nattack?", font);
    //populate container::story5a6
    ViewAdd(container::story5a6, "Images/Background.png", 0, 0);
    ViewAdd(container::story5a6, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story5a6, "Images/btnOkBig.png", 20, 380, onStoryLevelFive, 7);
    TextAdd(container::story5a6, 0, 0, "\n\nRon: \nThe ships see you before you \nare even able to go around \nand "
        "attack.", font);
    //populate container::story5b6
    ViewAdd(container::story5b6, "Images/Background.png", 0, 0);
    ViewAdd(container::story5b6, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story5b6, "Images/btnOkBig.png", 20, 380, onStoryLevelFive, 7);
    TextAdd(container::story5b6, 0, 0, "\n\nRon: \nAttacking the ships.", font);
}
void containerFour() {
    //populate container::story4a1
    ViewAdd(container::story4a1, "Images/Background.png", 0, 0);
    ViewAdd(container::story4a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story4a1, "Images/btnTakeGun.png", 20, 380, onStoryLevelFour, 2);
    ViewAdd(container::story4a1, "Images/btnDoNothing.png", 170, 380, onStoryLevelFour, 1);
    TextAdd(container::story4a1, 0, 0, "\n\nEnemy: \nNow to torture you too.", font);
    //populate container::story4a2
    ViewAdd(container::story4a2, "Images/Background.png", 0, 0);
    ViewAdd(container::story4a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story4a2, "Images/btnShoot.png", 20, 380, onStoryLevelFour, 3);
    ViewAdd(container::story4a2, "Images/btnDoNothing.png", 170, 380, onStoryLevelFour, 1);
    TextAdd(container::story4a2, 0, 0, "\n\nEnemy: \nYou wouldn't dare shoot!", font);
    //populate container::story4a3
    ViewAdd(container::story4a3, "Images/Background.png", 0, 0);
    ViewAdd(container::story4a3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story4a3, "Images/btnOkBig.png", 20, 380, onStoryLevelFour, 4);
    TextAdd(container::story4a3, 0, 0, "\n\nAlex: \nHe escaped with an escape \npod!", font);
    //populate container::story4a4
    ViewAdd(container::story4a4, "Images/Background.png", 0, 0);
    ViewAdd(container::story4a4, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story4a4, "Images/btnEnemy.png", 20, 380, onStoryLevelFour, 5);
    ViewAdd(container::story4a4, "Images/btnMine.png", 170, 380, onStoryLevelFour, 6);
    TextAdd(container::story4a4, 0, 0, "\n\nAlly: \nYou need to get back. Luckily, \nmy radio signal reaches you. "
        "\nYou can either take the", font);
    TextAdd(container::story4a4, 0, 0, "\n\n\n\n\n\nenemy ship or try to get back to yours. Also, if you make it back", 
        font);
    TextAdd(container::story4a4, 0, 0, "\n\n\n\n\n\n\nto your ship, you'll be in \ntemporary command.", font);
    //populate container::story4b5
    ViewAdd(container::story4b5, "Images/Background.png", 0, 0);
    ViewAdd(container::story4b5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story4b5, "Images/btnOkBig.png", 20, 380, onStoryLevelFour, 6);
    TextAdd(container::story4b5, 0, 0, "\n\nLieutenant Dan: \nThe enemy ship you were \nflying broke down. Luckily,", 
        font);
    TextAdd(container::story4b5, 0, 0, "\n\n\n\n\nthe crew and I came to save \nyou.", font);
    //populate container::story4a6
    ViewAdd(container::story4a6, "Images/Background.png", 0, 0);
    ViewAdd(container::story4a6, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story4a6, "Images/btnContact.png", 20, 380, onStoryLevelFour, 7);
    ViewAdd(container::story4a6, "Images/btnShoot.png", 170, 380, onStoryLevelFour, 8);
    TextAdd(container::story4a6, 0, 0, "\n\nLieutenant Dan: \nYou are in temporary \ncommand. There's ships up "
        "\nahead; do you contact it to", font);
    TextAdd(container::story4a6, 0, 0, "\n\n\n\n\n\nsee if it's friendly or do you \nshoot at it? There's no way "
        "\naround.", font);
    //populate container::story4a7
    ViewAdd(container::story4a7, "Images/Background.png", 0, 0);
    ViewAdd(container::story4a7, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story4a7, "Images/btnOkBig.png", 20, 380, onStoryLevelFour, 9);
    TextAdd(container::story4a7, 0, 0, "\n\nLieutenant Dan: \nThe ships say they are \nfriendly, so we went around "
        "\nthem.", font);
    //populate container::story4b7
    ViewAdd(container::story4b7, "Images/Background.png", 0, 0);
    ViewAdd(container::story4b7, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story4b7, "Images/btnOkBig.png", 20, 380, onStoryLevelFour, 10);
    TextAdd(container::story4b7, 0, 0, "\n\nLieutenant Dan: \nYou shoot at the ships.", font);
    //populate container::story4a8
    ViewAdd(container::story4a8, "Images/Background.png", 0, 0);
    ViewAdd(container::story4a8, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story4a8, "Images/btnOkBig.png", 20, 380, onStoryLevelFour, 10);
    TextAdd(container::story4a8, 0, 0, "\n\nLieutenant Dan: \nThe ships followed you and \nattack.", font);
}
void containerThree() {
    //populate container::story3a1
    ViewAdd(container::story3a1, "Images/Background.png", 0, 0);
    ViewAdd(container::story3a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story3a1, "Images/btnOkSmall.png", 20, 380, onStoryLevelThree, 2);
    ViewAdd(container::story3a1, "Images/btnNo.png", 170, 380, onStoryLevelThree, 1);
    TextAdd(container::story3a1, 0, 0, "\n\nCaptain: \nWe should check the \nwreckage.", font);
    //populate container::story3b2
    ViewAdd(container::story3b2, "Images/Background.png", 0, 0);
    ViewAdd(container::story3b2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story3b2, "Images/btnSorry.png", 20, 380, onStoryLevelThree, 2);
    ViewAdd(container::story3b2, "Images/btnOkSmall.png", 170, 380, onStoryLevelThree, 2);
    TextAdd(container::story3b2, 0, 0, "\n\nCaptain: \nI'm captain and I say we will, \nso we will.", font);
    //populate container::story3a3
    ViewAdd(container::story3a3, "Images/Background.png", 0, 0);
    ViewAdd(container::story3a3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story3a3, "Images/btnOkSmall.png", 20, 380, onStoryLevelThree, 3);
    ViewAdd(container::story3a3, "Images/btnNever.png", 170, 380, onStoryLevelThree, 3);
    TextAdd(container::story3a3, 0, 0, "\n\nEnemy: \nHands up!", font);
    //populate container::story3a4
    ViewAdd(container::story3a4, "Images/Background.png", 0, 0);
    ViewAdd(container::story3a4, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story3a4, "Images/btnWhereAreWe.png", 20, 380, onStoryLevelThree, 4);
    ViewAdd(container::story3a4, "Images/btnWhereCaptain.png", 170, 380, onStoryLevelThree, 4);
    TextAdd(container::story3a4, 0, 0, "\n\nEnemy: \nSorry for knocking you out, it \nwas the only way to bring \nyou "
        "here.", font);
    //populate container::story3a5
    ViewAdd(container::story3a5, "Images/Background.png", 0, 0);
    ViewAdd(container::story3a5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story3a5, "Images/btnYes.png", 20, 380, onStoryLevelThree, 5);
    ViewAdd(container::story3a5, "Images/btnNo.png", 170, 380, onStoryLevelThree, 5);
    TextAdd(container::story3a5, 0, 0, "\n\nEnemy: \nAre you familiar with torture?", font);
    //populate container::story3a6
    ViewAdd(container::story3a6, "Images/Background.png", 0, 0);
    ViewAdd(container::story3a6, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story3a6, "Images/btnOkSmall.png", 20, 380, onStoryLevelThree, 6);
    ViewAdd(container::story3a6, "Images/btnSo.png", 170, 380, onStoryLevelThree, 6);
    TextAdd(container::story3a6, 0, 0, "\n\nEnemy: \nTorture is what caused world \nwar 3 on your home planet: "
        "\nEarth.", font);
    //populate container::story3a7
    ViewAdd(container::story3a7, "Images/Background.png", 0, 0);
    ViewAdd(container::story3a7, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story3a7, "Images/btnNo!.png", 20, 380, onStoryLevelThree, 7);
    ViewAdd(container::story3a7, "Images/btnOkSmall.png", 170, 380, onStoryLevelThree, 7);
    TextAdd(container::story3a7, 0, 0, "\n\nEnemy: \nI will force you to torture your \ncaptain, hopefully "
        "causing a \nwar in the process.", font);
    //populate container::story3a8
    ViewAdd(container::story3a8, "Images/Background.png", 0, 0);
    ViewAdd(container::story3a8, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story3a8, "Images/btnNo!.png", 20, 380, onStoryLevelThree, 8);
    ViewAdd(container::story3a8, "Images/btnOkSmall.png", 170, 380, onStoryLevelThree, 8);
    TextAdd(container::story3a8, 0, 0, "\n\nEnemy: \nI will wait for you to torture \nhim until you do. There's "
        "\nnothing you can do about it.", font);
    //populate container::storyTorture
    TouchAdd(container::storyTorture, 0, 0, 320, 568, onTorture, 1);
    imageTorture = ViewAdd(container::storyTorture, "Images/TortureModeOne.png", -2, -2);
    ViewAdd(container::storyTorture, "Images/Pause.png", 270, 20, onPause, 1);
    hpTorture = ViewAdd(container::storyTorture, "Images/20HP.png", 20, 20);
    textTorture = TextAdd(container::storyTorture, 70, 0, "", FontAdd("Arial", "Regular", 24, 0xDF0101));
}
void containerTwo() {
    //populate container::story2a1
    ViewAdd(container::story2a1, "Images/Background.png", 0, 0);
    ViewAdd(container::story2a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story2a1, "Images/btnOkSmall.png", 20, 380, onStoryLevelTwo, 1);
    ViewAdd(container::story2a1, "Images/btnThanks.png", 170, 380, onStoryLevelTwo, 1);
    TextAdd(container::story2a1, 0, 0, "\n\nTeacher: \nThis test was designed to \ndetermine how well cadets \nwould "
        "respond to stressful", font);
    TextAdd(container::story2a1, 0, 0, "\n\n\n\n\n\nsituations. You passed and \nhave been deemed fit for \nduty.", 
        font);
    //populate container::story2a2
    ViewAdd(container::story2a2, "Images/Background.png", 0, 0);
    ViewAdd(container::story2a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story2a2, "Images/btnSure.png", 20, 380, onStoryLevelTwo, 3);
    ViewAdd(container::story2a2, "Images/btnNo.png", 170, 380, onStoryLevelTwo, 4);
    TextAdd(container::story2a2, 0, 0, "\n\nBecca: \nI heard you're the new soldier \nin town. Do you want to go \nout "
        "to town with me?", font);
    //populate container::story2a3
    ViewAdd(container::story2a3, "Images/Background.png", 0, 0);
    ViewAdd(container::story2a3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story2a3, "Images/btnYes.png", 20, 380, onStoryLevelTwo, 5);
    ViewAdd(container::story2a3, "Images/btnNo.png", 170, 380, onStoryLevelTwo, 6);
    TextAdd(container::story2a3, 0, 0, "\n\nCaptain: \nSon, you have a bright future. \nWould you like to join me on "
        "\nmy voyages?", font);
    //populate container::story2b4
    ViewAdd(container::story2b4, "Images/Background.png", 0, 0);
    ViewAdd(container::story2b4, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story2b4, "Images/btnOkSmall.png", 20, 380, onStoryLevelTwo, 7);
    ViewAdd(container::story2b4, "Images/btnSorry.png", 170, 380, onStoryLevelTwo, 7);
    TextAdd(container::story2b4, 0, 0, "\n\nCaptain: \nFederation orders, you have \nto do it.", font);
    //populate container::story2a5
    ViewAdd(container::story2a5, "Images/Background.png", 0, 0);
    ViewAdd(container::story2a5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story2a5, "Images/btnOkBig.png", 20, 380, onStoryLevelTwo, 8);
    TextAdd(container::story2a5, 0, 0, "\n\nCaptain: \nPrepare your items, we are \nleaving tomorrow.", font);
    //populate container::story2a6
    ViewAdd(container::story2a6, "Images/Background.png", 0, 0);
    ViewAdd(container::story2a6, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story2a6, "Images/btnEngage.png", 20, 380, onStoryLevelTwo, 9);
    ViewAdd(container::story2a6, "Images/btnAround.png", 170, 380, onStoryLevelTwo, 10);
    TextAdd(container::story2a6, 0, 0, "\n\nCaptain: \nThere's ships up ahead. \nShould we engage or go \naround?", 
        font);
    //populate container::story2e7
    ViewAdd(container::story2e7, "Images/Background.png", 0, 0);
    ViewAdd(container::story2e7, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story2e7, "Images/btnOkBig.png", 20, 380, onStoryLevelTwo, 11);
    TextAdd(container::story2e7, 0, 0, "\n\nCaptain: \nHave fun shooting!", font);
    //populate container::story2a7
    ViewAdd(container::story2a7, "Images/Background.png", 0, 0);
    ViewAdd(container::story2a7, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story2a7, "Images/btnOkBig.png", 20, 380, onStoryLevelTwo, 11);
    TextAdd(container::story2a7, 0, 0, "\n\nCaptain: \nThe ships noticed us and are \nattacking!", font);
}
void containerOne() {
    //populate container::highscore
    ViewAdd(container::highscore, "Images/MenuPause.png", 0, 0);
    ViewAdd(container::highscore, "Images/btnOkBig.png", 20, 380, onHighscore, 1);
    text1 = TextAdd(container::highscore, 20, 0, "", font);
    text2 = TextAdd(container::highscore, 20, 0, "", font);
    text3 = TextAdd(container::highscore, 20, 0, "", font);
    //populate container::pause
    ViewAdd(container::pause, "Images/MenuPause.png", 0, 0);
    ViewAdd(container::pause, "Images/ReturnToMenu.png", 20, 120, onReturnToMenu, 1);
    ViewAdd(container::pause, "Images/Resume.png", 20, 210, onResume, 1);
    //populate container::endless
    ViewAdd(container::endless, "Images/Background.png", 0, 0, onBattleTouch, 1);
    healthImage = ViewAdd(container::endless, "Images/20HP.png", 20, 20);
    ViewAdd(container::endless, "Images/Pause.png", 270, 20, onPause, 1);
    //player bullets
    for (int i = 0; i < 15; i++) {
        bullets::m1[i] = ViewAdd(container::endless, "Images/Bullet.png", -10, -10);
        bullets::m2[i] = ViewAdd(container::endless, "Images/Rocket.png", -20, -20);
        bullets::m3[i] = ViewAdd(container::endless, "Images/Bullet.png", -10, -10);
    }
    //enemy bullets
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            one[j].setBulletInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
            two[j].setBulletInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
            three[j].setBulletInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
            four[j].setBulletInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
        }
        for (int j = 0; j < 5; j++) {
            five[j].setBulletOneInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
            five[j].setBulletTwoInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
            six[j].setBulletOneInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
            six[j].setBulletTwoInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
            seven[j].setRocketInstance(i, ViewAdd(container::endless, "Images/eRocket.png", 600, 600));
            eight[j].setBulletOneInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
            eight[j].setRocketInstance(i, ViewAdd(container::endless, "Images/eRocket.png", 600, 600));
            eight[j].setBulletTwoInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
        }
        nine.setBulletOneInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
        nine.setRocketInstance(i, ViewAdd(container::endless, "Images/eRocket.png", 600, 600));
        nine.setBulletTwoInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
        ten.setBulletOneInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
        ten.setRocketInstance(i, ViewAdd(container::endless, "Images/eRocket.png", 600, 600));
        ten.setBulletTwoInstance(i, ViewAdd(container::endless, "Images/eBullet.png", 600, 600));
    }
    //ships
    for (int i = 0; i < 10; i++) {
        one[i].setInstance(ViewAdd(container::endless, "Images/eShip_1.png", 600, 600));
        two[i].setInstance(ViewAdd(container::endless, "Images/eShip_2.png", 600, 600));
        three[i].setInstance(ViewAdd(container::endless, "Images/eShip_3.png", 600, 600));
        four[i].setInstance(ViewAdd(container::endless, "Images/eShip_4.png", 600, 600));
    }
    for (int i = 0; i < 5; i++) {
        five[i].setInstance(ViewAdd(container::endless, "Images/eShip_5.png", 600, 600));
        six[i].setInstance(ViewAdd(container::endless, "Images/eShip_6.png", 600, 600));
        seven[i].setInstance(ViewAdd(container::endless, "Images/eShip_7.png", 600, 600));
        eight[i].setInstance(ViewAdd(container::endless, "Images/eShip_8.png", 600, 600));
    }
    nine.setInstance(ViewAdd(container::endless, "Images/eMini-Boss.png", 600, 600));
    ten.setInstance(ViewAdd(container::endless, "Images/eBoss.png", 600, 600));
    //populate container::menu
    ViewAdd(container::menu, "Images/Background.png", 0, 0);
    ViewAdd(container::menu, "Images/btnStory.png", 20, 40, onStoryMenuTouch, 1);
    ViewAdd(container::menu, "Images/btnEndless.png", 20, 150, onEndlessMenuTouch, 1);
    ViewAdd(container::menu, "Images/btnUnlocks.png", 20, 260, onUnlocksMenuTouch, 1);
    ViewAdd(container::menu, "Images/btnOptions.png", 20, 370, onOptionsMenuTouch, 1);
    //populate container::died
    ViewAdd(container::died, "Images/Background.png", 0, 0);
    ViewAdd(container::died, "Images/btnOkBig.png", 20, 380, onDied, 1);
    TextAdd(container::died, 0, 0, "\n\nYou died without completing \nyour journey or leaving \nyourself a legacy. "
        "You left no", font);
    TextAdd(container::died, 0, 0, "\n\n\n\n\nimprint on the world and \nnobody will ever remember \nyou.", font);
    //populate CointainerStory1a1
    ViewAdd(container::story1a1, "Images/Background.png", 0, 0);
    ViewAdd(container::story1a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story1a1, "Images/btnOkBig.png", 20, 380, onStoryLevelOne, 1);
    TextAdd(container::story1a1, 0, 0, "\n\nRon: \nAlex, are you ready for the \nbig test? Remember: We \nadopted the "
        "new cycle", font);
    TextAdd(container::story1a1, 0, 0, "\n\n\n\n\n\nsystem 93 cycles ago. If we \nstill used the old Earth \nmethod, "
        "it would currently be", font);
    TextAdd(container::story1a1, 0, 0, "\n\n\n\n\n\n\n\n\nyear 2433.", font);
    //populate container::story1a2
    ViewAdd(container::story1a2, "Images/Background.png", 0, 0);
    ViewAdd(container::story1a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story1a2, "Images/btnStudy.png", 20, 380, onStoryLevelOne, 3);
    ViewAdd(container::story1a2, "Images/btnParty.png", 170, 380, onStoryLevelOne, 4);
    TextAdd(container::story1a2, 0, 0, "\n\nRon: \nAlso, you can either \nstudy for the big test \ntomorrow, or go to "
        "a party", font);
    TextAdd(container::story1a2, 0, 0, "\n\n\n\n\n\nwith the cool guys and I. Just \ntell them Ron invited you.", font);
    //populate container::story1s3
    ViewAdd(container::story1s3, "Images/Background.png", 0, 0);
    ViewAdd(container::story1s3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story1s3, "Images/btnSleep.png", 20, 380, onStoryLevelOne, 5);
    TextAdd(container::story1s3, 0, 0, "\n\nBook: \nEverybody must listen to \nhigher command at all times. \nAlso, "
        "ship pilots must never", font);
    TextAdd(container::story1s3, 0, 0, "\n\n\n\n\n\nabandon their ship.", font);
    //populate container::story1p3
    ViewAdd(container::story1p3, "Images/Background.png", 0, 0);
    ViewAdd(container::story1p3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story1p3, "Images/btnSleep.png", 20, 380, onStoryLevelOne, 5);
    TextAdd(container::story1p3, 0, 0, "\n\nRon: \nHave a great night.", font);
    //populate container::story1a4
    ViewAdd(container::story1a4, "Images/Background.png", 0, 0);
    ViewAdd(container::story1a4, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story1a4, "Images/btnRescue.png", 20, 380, onStoryLevelOne, 6);
    ViewAdd(container::story1a4, "Images/btnEscape.png", 170, 380, onStoryLevelOne, 7);
    TextAdd(container::story1a4, 0, 0, "\n\nTeacher: \nThe Kobayashi ship is \ntrapped behind enemy \nlines. What do "
        "you do?", font);
    //populate container::story1r5
    ViewAdd(container::story1r5, "Images/Background.png", 0, 0);
    ViewAdd(container::story1r5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story1r5, "Images/btnOkBig.png", 20, 380, onStoryLevelOne, 8);
    TextAdd(container::story1r5, 0, 0, "\n\nLieutenant: \nThey ambushed us!", font);
    //populate container::story1e5
    ViewAdd(container::story1e5, "Images/Background.png", 0, 0);
    ViewAdd(container::story1e5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container::story1e5, "Images/btnOkBig.png", 20, 380, onStoryLevelOne, 8);
    TextAdd(container::story1e5, 0, 0, "\n\nLieutenant: \nThey followed us and are \nattacking!", font);
}
void startupMusic() {
    if (state::sound) {
        if (counter::sound > 1 && counter::sound < 7000) {
            counter::sound = 7000;
        } else if (counter::sound > 7000 && counter::sound < 13000) {
            counter::sound = 13000;
        } else if (counter::sound > 13000 && counter::sound < 19000) {
            counter::sound = 19000;
        } else if (counter::sound > 19000 && counter::sound < 27000) {
            counter::sound = 27000;
        } else if (counter::sound > 27000 && counter::sound < 34000) {
            counter::sound = 34000;
        } else if (counter::sound > 34000 && counter::sound < 42000) {
            counter::sound = 42000;
        } else if (counter::sound > 42000 && counter::sound < 49000) {
            counter::sound = 49000;
        } else if (counter::sound > 49000 && counter::sound < 55000) {
            counter::sound = 55000;
        } else if (counter::sound > 55000 && counter::sound < 61000) {
            counter::sound = 61000;
        } else if (counter::sound > 61000 && counter::sound < 67000) {
            counter::sound = 67000;
        } else if (counter::sound > 67000 && counter::sound < 73000) {
            counter::sound = 73000;
        } else if (counter::sound > 73000 && counter::sound < 79000) {
            counter::sound = 79000;
        } else if (counter::sound > 79000) {
            counter::sound = 1;
        }
        if (counter::sound > 1 && counter::sound < 7000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/1.mp3"));
        } else if (counter::sound > 7000 && counter::sound < 13000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/2.mp3"));
        } else if (counter::sound > 13000 && counter::sound < 19000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/3.mp3"));
        } else if (counter::sound > 19000 && counter::sound < 27000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/5.mp3"));
        } else if (counter::sound > 27000 && counter::sound < 34000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/7.mp3"));
        } else if (counter::sound > 34000 && counter::sound < 42000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/8.mp3"));
        } else if (counter::sound > 42000 && counter::sound < 49000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/9.mp3"));
        } else if (counter::sound > 49000 && counter::sound < 55000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/11.mp3"));
        } else if (counter::sound > 55000 && counter::sound < 61000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/12.mp3"));
        } else if (counter::sound > 61000 && counter::sound < 67000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/13.mp3"));
        } else if (counter::sound > 67000 && counter::sound < 73000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/14.mp3"));
        } else if (counter::sound > 73000 && counter::sound < 79000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/15.mp3"));
        }
    } else {
        Mp3Stop();
    }
}
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

    //populate container::unlocks
    ViewAdd(container::unlocks, "Images/Background.png", 0, 0);
    ViewAdd(container::unlocks, "Images/Pause.png", 270, 20, onPause, 1);
    TextAdd(container::unlocks, 10, 10, "\n\n\n\n\n Pick Your Ship By Clicking", font);
    ViewAdd(container::unlocks, "unlocks/UnShip_1.png", 20, 180, unlocks, 1);
    //populate container::options
    ViewAdd(container::options, "Images/Background.png", 0, 0);
    ViewAdd(container::options, "Images/Pause.png", 270, 20, onPause, 1);
    char* musicString = (state::sound) ? ("unlocks/MusicOn.png") : ("unlocks/MusicOff.png");
    music = ViewAdd(container::options, musicString, 20, 80, options, 1);
    TextAdd(container::options, 20, 320, "\nCreated By \nBailey Thompson", font);
    ViewAdd(container::options, "Images/btnDelete.png", 20, 200, options, 2);
    //populate container::deleteCheckOne
    ViewAdd(container::deleteCheckOne, "Images/Background.png", 0, 0);
    TextAdd(container::deleteCheckOne, 20, 20, "Are you sure you want to \nDELETE ALL PLAYER \nDATA including xp, "
        "rank, \nhighscore, and ships?", font);
    ViewAdd(container::deleteCheckOne, "Images/btnNoDelete.png", 20, 180, options, 5);
    ViewAdd(container::deleteCheckOne, "Images/btnYesDelete.png", 20, 300, options, 3);
    //populate container::deleteCheckTwo
    ViewAdd(container::deleteCheckTwo, "Images/Background.png", 0, 0);
    TextAdd(container::deleteCheckTwo, 20, 20, "Are you really sure you \nwant to DELETE \nEVERYTHING?", font);
    ViewAdd(container::deleteCheckTwo, "Images/btnNoDelete.png", 20, 300, options, 5);
    ViewAdd(container::deleteCheckTwo, "Images/btnYesDelete.png", 20, 180, options, 4);

    shipType();
    startupMusic();
}

void intGameToFile(int num, char* buffer) {
    int numToSave = num;
    buffer[0] = char(numToSave / 10000 + '0');
    numToSave %= 10000;
    buffer[1] = char(numToSave / 1000 + '0');
    numToSave %= 1000;
    buffer[2] = char(numToSave / 100 + '0');
    numToSave %= 100;
    buffer[3] = char(numToSave / 10 + '0');
    numToSave %= 10;
    buffer[4] = char(numToSave + '0');
}
void boolGameToFile(bool num, char* buffer) {
    buffer[0] = (num) ? ('t') : ('f');
}
void AppExit() {
    Mp3Stop();
    char fileBuffer[5];
    //fileSound
    int fileSound = FileOpen("Sound.txt");
    boolGameToFile(state::sound, fileBuffer);
    FileWrite(fileSound, fileBuffer, 1);
    FileClose(fileSound);
    //fileXp
    int fileXp = FileOpen("Xp.txt");
    intGameToFile(xp, fileBuffer);
    FileWrite(fileXp, fileBuffer, 5);
    FileClose(fileXp);
    //fileShip
    int fileShip = FileOpen("Ship.txt");
    intGameToFile(ship, fileBuffer);
    FileWrite(fileShip, fileBuffer, 5);
    FileClose(fileShip);
    //fileHighscore
    int fileHighscore = FileOpen("Highscore.txt");
    intGameToFile(highscore, fileBuffer);
    FileWrite(fileHighscore, fileBuffer, 5);
    FileClose(fileHighscore);
    //fileCounter
    int fileCounter = FileOpen("Counter.txt");
    intGameToFile(counter::sound, fileBuffer);
    FileWrite(fileCounter, fileBuffer, 5);
    FileClose(fileCounter);
}

bool isNotActive() {
    return currentScreen != SCREEN_ENDLESS && currentScreen != SCREEN_STORY_BATTLE_1
               && currentScreen != SCREEN_STORY_BATTLE_2 && currentScreen != SCREEN_STORY_BATTLE_4
               && currentScreen != SCREEN_STORY_BATTLE_5 && currentScreen != SCREEN_STORY_BATTLE_6
               && currentScreen != SCREEN_DIED && currentScreen != SCREEN_HIGHSCORE;
}
void soundSwitch() {
    if (state::sound) {
        if (counter::sound == 1) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/1.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 7000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/2.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 13000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/3.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 19000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/5.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 27000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/7.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 34000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/8.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 42000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/9.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 49000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/11.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 55000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/12.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 61000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/13.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 67000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/14.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound == 73000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/15.mp3"));
            } else {
                counter::sound--;
            }
        } else if (counter::sound >= 79000) {
            counter::sound = 0;
        }
    } else {
        Mp3Stop();
    }
}
void mShipMove() {
    //move x
    if (newX > mX + shipSpeed / 2) {
        mX += shipSpeed;
    } else if (newX + shipSpeed / 2 < mX) {
        mX -= shipSpeed;
    }
    //move y
    if (newY > mY + shipSpeed / 2) {
        mY += shipSpeed;
    } else if (newY + shipSpeed / 2 < mY) {
        mY -= shipSpeed;
    }
    //stop x
    if (mX < 0) {
        mX = 0;
    } else if (mX > 226) {
        mX = 226;
    }
    //stop y
    if (mY < 50) {
        mY = 50;
    } else if (mY > 386) {
        mY = 386;
    }
    //set ship view
    ViewSetxy(shipView, mX, mY);
}
void bulletTime() {
    int x, y, x2, y2, x3, y3;
    bool used = false;
    for (int i = 1; i <= 15; i++) {
        if (counter::bulletTime == i * PLAYER_BULLET_COOLDOWN_SPEED) {
            used = true;
            if (ship == 8) {
                ViewSetxy(bullets::m1[i - 1], mX + bulletXOffset, mY + bulletYOffset);
                ViewSetxy(bullets::m2[i - 1], mX + bulletXOffset2, mY + bulletYOffset2);
                ViewSetxy(bullets::m3[i - 1], mX + bulletXOffset3, mY + bulletYOffset3);
            } else if (ship == 7) {
                ViewSetxy(bullets::m2[i - 1], mX + bulletXOffset2, mY + bulletYOffset2);
            } else if (ship == 6 || ship == 5) {
                ViewSetxy(bullets::m1[i - 1], mX + bulletXOffset, mY + bulletYOffset);
                ViewSetxy(bullets::m3[i - 1], mX + bulletXOffset3, mY + bulletYOffset3);
            } else {
                ViewSetxy(bullets::m1[i - 1], mX + bulletXOffset, mY + bulletYOffset);
            }
        }
    }
    if (counter::bulletTime >= 15 * PLAYER_BULLET_COOLDOWN_SPEED) {
        counter::bulletTime = 0;
    }
    if (!used) {
        for (int i = 0; i < 15; i++) {
            x = ViewGetx(bullets::m1[i]);
            y = ViewGety(bullets::m1[i]);
            x2 = ViewGetx(bullets::m2[i]);
            y2 = ViewGety(bullets::m2[i]);
            x3 = ViewGetx(bullets::m3[i]);
            y3 = ViewGety(bullets::m3[i]);
            if (y > -20 || y2 > -20 || y3 > -20) {
                ViewSetxy(bullets::m1[i], x, y - PLAYER_BULLET_SPEED);
                ViewSetxy(bullets::m2[i], x2, y2 - PLAYER_BULLET_SPEED);
                ViewSetxy(bullets::m3[i], x3, y3 - PLAYER_BULLET_SPEED);
            }
            for (int j = 0; j < 10; j++) {
                //ship 1
                const int enemy1x = one[j].getXCoord();
                const int enemy1y = one[j].getYCoord();
                if (y > enemy1y && y < enemy1y + 94 && x > enemy1x + 9 && x < enemy1x + 76) {
                    ViewSetxy(bullets::m1[i], -10, -10);
                    one[j].damage(1);
                }
                if (y2 > enemy1y && y2 < enemy1y + 94 && x2 > enemy1x + 9 && x2 < enemy1x + 76) {
                    ViewSetxy(bullets::m2[i], -20, -20);
                    one[j].damage(3);
                }
                if (y3 > enemy1y && y3 < enemy1y + 94 && x3 > enemy1x + 9 && x3 < enemy1x + 76) {
                    ViewSetxy(bullets::m3[i], -10, -10);
                    one[j].damage(1);
                }
                //ship 2
                const int enemy2x = two[j].getXCoord();
                const int enemy2y = two[j].getYCoord();
                if (y > enemy2y && y < enemy2y + 94 && x > enemy2x + 15 && x < enemy2x + 69) {
                    ViewSetxy(bullets::m1[i], -10, -10);
                    two[j].damage(1);
                }
                if (y2 > enemy2y && y2 < enemy2y + 94 && x2 > enemy2x + 15 && x2 < enemy2x + 69) {
                    ViewSetxy(bullets::m2[i], -20, -20);
                    two[j].damage(3);
                }
                if (y3 > enemy2y && y3 < enemy2y + 94 && x3 > enemy2x + 15 && x3 < enemy2x + 69) {
                    ViewSetxy(bullets::m3[i], -10, -10);
                    two[j].damage(1);
                }
                //ship 3
                const int enemy3x = three[j].getXCoord();
                const int enemy3y = three[j].getYCoord();
                if (y > enemy3y && y < enemy3y + 94 && x > enemy3x + 18 && x < enemy3x + 66) {
                    ViewSetxy(bullets::m1[i], -10, -10);
                    three[j].damage(1);
                }
                if (y2 > enemy3y && y2 < enemy3y + 94 && x2 > enemy3x + 18 && x2 < enemy3x + 66) {
                    ViewSetxy(bullets::m2[i], -20, -20);
                    three[j].damage(3);
                }
                if (y3 > enemy3y && y3 < enemy3y + 94 && x3 > enemy3x + 18 && x3 < enemy3x + 66) {
                    ViewSetxy(bullets::m3[i], -10, -10);
                    three[j].damage(1);
                }
                //ship 4
                const int enemy4x = four[j].getXCoord();
                const int enemy4y = four[j].getYCoord();
                if (y > enemy4y && y < enemy4y + 94 && x > enemy4x - 3 && x < enemy4x + 87) {
                    ViewSetxy(bullets::m1[i], -10, -10);
                    four[j].damage(1);
                }
                if (y2 > enemy4y && y2 < enemy4y + 94 && x2 > enemy4x - 3 && x2 < enemy4x + 87) {
                    ViewSetxy(bullets::m2[i], -20, -20);
                    four[j].damage(3);
                }
                if (y3 > enemy4y && y3 < enemy4y + 94 && x3 > enemy4x - 3 && x3 < enemy4x + 87) {
                    ViewSetxy(bullets::m3[i], -10, -10);
                    four[j].damage(1);
                }
            }
            for (int j = 0; j < 5; j++) {
                //ship 5
                const int enemy5x = five[j].getXCoord();
                const int enemy5y = five[j].getYCoord();
                if (y > enemy5y && y < enemy5y + 94 && x > enemy5x + 13 && x < enemy5x + 71) {
                    ViewSetxy(bullets::m1[i], -10, -10);
                    five[j].damage(1);
                }
                if (y2 > enemy5y && y2 < enemy5y + 94 && x2 > enemy5x + 13 && x2 < enemy5x + 71) {
                    ViewSetxy(bullets::m2[i], -20, -20);
                    five[j].damage(3);
                }
                if (y3 > enemy5y && y3 < enemy5y + 94 && x3 > enemy5x + 13 && x3 < enemy5x + 71) {
                    ViewSetxy(bullets::m3[i], -10, -10);
                    five[j].damage(1);
                }
                //ship 6
                const int enemy6x = six[j].getXCoord();
                const int enemy6y = six[j].getYCoord();
                if (y > enemy6y && y < enemy6y + 94 && x > enemy6x + 3 && x < enemy6x + 81) {
                    ViewSetxy(bullets::m1[i], -10, -10);
                    six[j].damage(1);
                }
                if (y2 > enemy6y && y2 < enemy6y + 94 && x2 > enemy6x + 3 && x2 < enemy6x + 81) {
                    ViewSetxy(bullets::m2[i], -20, -20);
                    six[j].damage(3);
                }
                if (y3 > enemy6y && y3 < enemy6y + 94 && x3 > enemy6x + 3 && x3 < enemy6x + 81) {
                    ViewSetxy(bullets::m3[i], -10, -10);
                    six[j].damage(1);
                }
                //ship 7
                const int enemy7x = seven[j].getXCoord();
                const int enemy7y = seven[j].getYCoord();
                if (y > enemy7y && y < enemy7y + 94 && x > enemy7x - 2 && x < enemy7x + 86) {
                    ViewSetxy(bullets::m1[i], -10, -10);
                    seven[j].damage(1);
                }
                if (y2 > enemy7y && y2 < enemy7y + 94 && x2 > enemy7x - 2 && x2 < enemy7x + 86) {
                    ViewSetxy(bullets::m2[i], -20, -20);
                    seven[j].damage(3);
                }
                if (y3 > enemy7y && y3 < enemy7y + 94 && x3 > enemy7x - 2 && x3 < enemy7x + 86) {
                    ViewSetxy(bullets::m3[i], -10, -10);
                    seven[j].damage(1);
                }
                //ship 8
                const int enemy8x = eight[j].getXCoord();
                const int enemy8y = eight[j].getYCoord();
                if (y > enemy8y && y < enemy8y + 94 && x > enemy8x - 3 && x < enemy8x + 86) {
                    ViewSetxy(bullets::m1[i], -10, -10);
                    eight[j].damage(1);
                }
                if (y2 > enemy8y && y2 < enemy8y + 94 && x2 > enemy8x - 3 && x2 < enemy8x + 86) {
                    ViewSetxy(bullets::m2[i], -20, -20);
                    eight[j].damage(3);
                }
                if (y3 > enemy8y && y3 < enemy8y + 94 && x3 > enemy8x - 3 && x3 < enemy8x + 86) {
                    ViewSetxy(bullets::m3[i], -10, -10);
                    eight[j].damage(1);
                }
            }
            //ship 9
            const int enemy9x = nine.getXCoord();
            const int enemy9y = nine.getYCoord();
            if (y > enemy9y && y < enemy9y + 94 && x > enemy9x && x < enemy9x + 240) {
                ViewSetxy(bullets::m1[i], -10, -10);
                nine.damage(1);
            }
            if (y2 > enemy9y && y2 < enemy9y + 94 && x2 > enemy9x && x2 < enemy9x + 240) {
                ViewSetxy(bullets::m2[i], -20, -20);
                nine.damage(3);
            }
            if (y3 > enemy9y && y3 < enemy9y + 94 && x3 > enemy9x && x3 < enemy9x + 240) {
                ViewSetxy(bullets::m3[i], -10, -10);
                nine.damage(1);
            }
            //ship 10
            const int enemy10x = ten.getXCoord();
            const int enemy10y = ten.getYCoord();
            if (y > enemy10y && y < enemy10y + 94 && x > enemy10x && x < enemy10x + 240) {
                ViewSetxy(bullets::m1[i], -10, -10);
                ten.damage(1);
            }
            if (y2 > enemy10y && y2 < enemy10y + 94 && x2 > enemy10x && x2 < enemy10x + 240) {
                ViewSetxy(bullets::m2[i], -20, -20);
                ten.damage(3);
            }
            if (y3 > enemy10y && y3 < enemy10y + 94 && x3 > enemy10x && x3 < enemy10x + 240) {
                ViewSetxy(bullets::m3[i], -10, -10);
                ten.damage(1);
            }
        }
    }
}
void tortureHealth() {
    int imageTorturing, number = 100;
    if (counter::hpTorture > number * 20 && state::torture) {
        counter::hpTorture = number * 20;
    } else if (counter::hpTorture > number * 40 && !state::torture) {
        currentScreen = SCREEN_DIED;
        screenSwitch();
    } else if (counter::hpTorture <= number * 20 && counter::hpTorture > number * 19) {
        imageTorturing = ImageAdd("Images/20HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= number * 19 && counter::hpTorture > number * 18) {
        imageTorturing = ImageAdd("Images/19HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nStop This Madness!");
    } else if (counter::hpTorture <= number * 18 && counter::hpTorture > number * 17) {
        imageTorturing = ImageAdd("Images/18HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= number * 17 && counter::hpTorture > number * 16) {
        imageTorturing = ImageAdd("Images/17HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nDon't Do It!");
    } else if (counter::hpTorture <= number * 16 && counter::hpTorture > number * 15) {
        imageTorturing = ImageAdd("Images/16HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= number * 15 && counter::hpTorture > number * 14) {
        imageTorturing = ImageAdd("Images/15HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nI Beg Of You!");
    } else if (counter::hpTorture <= number * 14 && counter::hpTorture > number * 13) {
        imageTorturing = ImageAdd("Images/14HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= number * 13 && counter::hpTorture > number * 12) {
        imageTorturing = ImageAdd("Images/13HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nPlease Don't!");
    } else if (counter::hpTorture <= number * 12 && counter::hpTorture > number * 11) {
        imageTorturing = ImageAdd("Images/12HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= number * 11 && counter::hpTorture > number * 10) {
        imageTorturing = ImageAdd("Images/11HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nI Order You To Stop!");
    } else if (counter::hpTorture <= number * 10 && counter::hpTorture > number * 9) {
        imageTorturing = ImageAdd("Images/10HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= number * 9 && counter::hpTorture > number * 8) {
        imageTorturing = ImageAdd("Images/9HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nI Have A Family!");
    } else if (counter::hpTorture <= number * 8 && counter::hpTorture > number * 7) {
        imageTorturing = ImageAdd("Images/8HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= number * 7 && counter::hpTorture > number * 6) {
        imageTorturing = ImageAdd("Images/7HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nDon't Do This!");
    } else if (counter::hpTorture <= number * 6 && counter::hpTorture > number * 5) {
        imageTorturing = ImageAdd("Images/6HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= number * 5 && counter::hpTorture > number * 4) {
        imageTorturing = ImageAdd("Images/5HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nWhy Are You \nDoing This!");
    } else if (counter::hpTorture <= number * 4 && counter::hpTorture > number * 3) {
        imageTorturing = ImageAdd("Images/4HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= number * 3 && counter::hpTorture > number * 2) {
        imageTorturing = ImageAdd("Images/3HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nYou Will Burn!");
    } else if (counter::hpTorture <= number * 2 && counter::hpTorture > number * 1) {
        imageTorturing = ImageAdd("Images/2HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= number * 1 && counter::hpTorture > 0) {
        imageTorturing = ImageAdd("Images/1HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter::hpTorture <= 0) {
        state::pause = false;
        currentScreen = SCREEN_STORY_4A1;
        screenSwitch();
    }
}
char* concatHealth(int num) {
    if (num <= 0) {
        num = 1;
    } else if (num > 20) {
        num = 20;
    }
    if (num >= 10) {
        char ret[] = "Images/00HP.png";
        ret[7] = char(num / 10 + '0');
        ret[8] = char(num % 10 + '0');
        return ret;
    } else {
        char ret[] = "Images/0HP.png";
        ret[7] = char(num + '0');
        return ret;
    }
}
void healthBar() {
    if (health < 0) {
        health = 0;
    }
    int image;
    if (state::healthUpdate) {
        const int FRAC_HEALTH = round(20 * health / possibleHealth);
        image = ImageAdd(concatHealth(FRAC_HEALTH));
        ViewSetImage(healthImage, image);
        if (health <= 0) {
            if (currentScreen == SCREEN_ENDLESS) {
                currentScreen = SCREEN_HIGHSCORE;
                doUpdateHighscore();
            } else if (currentScreen == SCREEN_STORY_BATTLE_1) {
                currentScreen = SCREEN_STORY_2A1;
                reset();
            } else if (currentScreen == SCREEN_STORY_BATTLE_6) {
                currentScreen = SCREEN_STORY_7L1;
                reset();
            } else {
                currentScreen = SCREEN_DIED;
                reset();
            }
            screenSwitch();
        }
        state::healthUpdate = false;
        counter::healthRegen = 0;
    }
}
void setOne() {
    if (counter::shipMove == 1 * ENEMY_SPAWN_TIME) {
        one[0].resetHealth(level);
        ViewSetxy(one[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 2 * ENEMY_SPAWN_TIME) {
        one[1].resetHealth(level);
        two[0].resetHealth(level);
        ViewSetxy(one[1].getInstance(), 33, -94);
        ViewSetxy(two[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 3 * ENEMY_SPAWN_TIME) {
        two[1].resetHealth(level);
        ViewSetxy(two[1].getInstance(), 113, -94);
    } else if (counter::shipMove == 4 * ENEMY_SPAWN_TIME) {
        two[2].resetHealth(level);
        one[2].resetHealth(level);
        ViewSetxy(two[2].getInstance(), 33, -94);
        ViewSetxy(one[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 5 * ENEMY_SPAWN_TIME) {
        one[3].resetHealth(level);
        three[0].resetHealth(level);
        two[3].resetHealth(level);
        ViewSetxy(one[3].getInstance(), 0, -94);
        ViewSetxy(three[0].getInstance(), 113, -94);
        ViewSetxy(two[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 6 * ENEMY_SPAWN_TIME) {
        three[1].resetHealth(level);
        two[4].resetHealth(level);
        three[2].resetHealth(level);
        ViewSetxy(three[1].getInstance(), 0, -94);
        ViewSetxy(two[4].getInstance(), 113, -94);
        ViewSetxy(three[2].getInstance(), 226, -94);
    } else if (counter::shipMove == 7 * ENEMY_SPAWN_TIME) {
        one[4].resetHealth(level);
        one[5].resetHealth(level);
        two[5].resetHealth(level);
        ViewSetxy(one[4].getInstance(), 0, -94);
        ViewSetxy(one[5].getInstance(), 113, -94);
        ViewSetxy(two[5].getInstance(), 226, -94);
    } else if (counter::shipMove == 8 * ENEMY_SPAWN_TIME) {
        three[3].resetHealth(level);
        one[6].resetHealth(level);
        one[7].resetHealth(level);
        ViewSetxy(three[3].getInstance(), 0, -94);
        ViewSetxy(one[6].getInstance(), 113, -94);
        ViewSetxy(one[7].getInstance(), 226, -94);
    } else if (counter::shipMove == 9 * ENEMY_SPAWN_TIME) {
        two[6].resetHealth(level);
        three[4].resetHealth(level);
        ViewSetxy(two[6].getInstance(), 33, -94);
        ViewSetxy(three[4].getInstance(), 193, -94);
    } else if (counter::shipMove == 10 * ENEMY_SPAWN_TIME) {
        four[0].resetHealth(level);
        ViewSetxy(four[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 11 * ENEMY_SPAWN_TIME) {
        three[5].resetHealth(level);
        four[1].resetHealth(level);
        ViewSetxy(three[5].getInstance(), 33, -94);
        ViewSetxy(four[1].getInstance(), 193, -94);
    } else if (counter::shipMove == 12 * ENEMY_SPAWN_TIME) {
        one[8].resetHealth(level);
        two[7].resetHealth(level);
        one[9].resetHealth(level);
        ViewSetxy(one[8].getInstance(), 0, -94);
        ViewSetxy(two[7].getInstance(), 113, -94);
        ViewSetxy(one[9].getInstance(), 226, -94);
    } else if (counter::shipMove == 13 * ENEMY_SPAWN_TIME) {
        four[2].resetHealth(level);
        one[0].resetHealth(level);
        three[6].resetHealth(level);
        ViewSetxy(four[2].getInstance(), 0, -94);
        ViewSetxy(one[0].getInstance(), 113, -94);
        ViewSetxy(three[6].getInstance(), 226, -94);
    } else if (counter::shipMove == 14 * ENEMY_SPAWN_TIME) {
        two[8].resetHealth(level);
        four[3].resetHealth(level);
        three[7].resetHealth(level);
        ViewSetxy(two[8].getInstance(), 0, -94);
        ViewSetxy(four[3].getInstance(), 113, -94);
        ViewSetxy(three[7].getInstance(), 226, -94);
    } else if (counter::shipMove == 15 * ENEMY_SPAWN_TIME) {
        four[4].resetHealth(level);
        four[5].resetHealth(level);
        ViewSetxy(four[4].getInstance(), 33, -94);
        ViewSetxy(four[5].getInstance(), 193, -94);
    } else if (counter::shipMove == 16 * ENEMY_SPAWN_TIME) {
        two[9].resetHealth(level);
        two[0].resetHealth(level);
        three[8].resetHealth(level);
        ViewSetxy(two[9].getInstance(), 0, -94);
        ViewSetxy(two[0].getInstance(), 113, -94);
        ViewSetxy(three[8].getInstance(), 226, -94);
    } else if (counter::shipMove == 17 * ENEMY_SPAWN_TIME) {
        three[9].resetHealth(level);
        one[2].resetHealth(level);
        two[1].resetHealth(level);
        ViewSetxy(three[9].getInstance(), 0, -94);
        ViewSetxy(one[2].getInstance(), 113, -94);
        ViewSetxy(two[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 18 * ENEMY_SPAWN_TIME) {
        four[6].resetHealth(level);
        two[2].resetHealth(level);
        ViewSetxy(four[6].getInstance(), 33, -94);
        ViewSetxy(two[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 19 * ENEMY_SPAWN_TIME) {
        five[0].resetHealth(level);
        ViewSetxy(five[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 20 * ENEMY_SPAWN_TIME) {
        two[3].resetHealth(level);
        four[7].resetHealth(level);
        ViewSetxy(two[3].getInstance(), 33, -94);
        ViewSetxy(four[7].getInstance(), 193, -94);
    } else if (counter::shipMove == 21 * ENEMY_SPAWN_TIME) {
        one[1].resetHealth(level);
        five[1].resetHealth(level);
        one[2].resetHealth(level);
        ViewSetxy(one[1].getInstance(), 0, -94);
        ViewSetxy(five[1].getInstance(), 113, -94);
        ViewSetxy(one[2].getInstance(), 226, -94);
    } else if (counter::shipMove == 22 * ENEMY_SPAWN_TIME) {
        four[8].resetHealth(level);
        two[4].resetHealth(level);
        four[9].resetHealth(level);
        ViewSetxy(four[8].getInstance(), 0, -94);
        ViewSetxy(two[4].getInstance(), 113, -94);
        ViewSetxy(four[9].getInstance(), 226, -94);
    } else if (counter::shipMove == 23 * ENEMY_SPAWN_TIME) {
        five[2].resetHealth(level);
        five[3].resetHealth(level);
        ViewSetxy(five[2].getInstance(), 33, -94);
        ViewSetxy(five[3].getInstance(), 193, -94);
    } else if (counter::shipMove == 24 * ENEMY_SPAWN_TIME) {
        four[0].resetHealth(level);
        five[4].resetHealth(level);
        four[1].resetHealth(level);
        ViewSetxy(four[0].getInstance(), 0, -94);
        ViewSetxy(five[4].getInstance(), 113, -94);
        ViewSetxy(four[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 25 * ENEMY_SPAWN_TIME) {
        five[0].resetHealth(level);
        one[3].resetHealth(level);
        three[0].resetHealth(level);
        ViewSetxy(five[0].getInstance(), 0, -94);
        ViewSetxy(one[3].getInstance(), 113, -94);
        ViewSetxy(three[0].getInstance(), 226, -94);
    } else if (counter::shipMove == 26 * ENEMY_SPAWN_TIME) {
        five[1].resetHealth(level);
        five[2].resetHealth(level);
        ViewSetxy(five[1].getInstance(), 33, -94);
        ViewSetxy(five[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 27 * ENEMY_SPAWN_TIME) {
        one[4].resetHealth(level);
        three[1].resetHealth(level);
        one[1].resetHealth(level);
        ViewSetxy(one[4].getInstance(), 0, -94);
        ViewSetxy(three[1].getInstance(), 113, -94);
        ViewSetxy(one[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 28 * ENEMY_SPAWN_TIME) {
        four[2].resetHealth(level);
        five[3].resetHealth(level);
        two[5].resetHealth(level);
        ViewSetxy(four[2].getInstance(), 0, -94);
        ViewSetxy(five[3].getInstance(), 113, -94);
        ViewSetxy(two[5].getInstance(), 226, -94);
    } else if (counter::shipMove == 29 * ENEMY_SPAWN_TIME) {
        one[2].resetHealth(level);
        one[3].resetHealth(level);
        ViewSetxy(one[2].getInstance(), 33, -94);
        ViewSetxy(one[3].getInstance(), 193, -94);
    }
    if (counter::shipMove == 30 * ENEMY_SPAWN_TIME) {
        if (currentScreen != SCREEN_STORY_BATTLE_1) {
            nine.resetHealth(level);
            ViewSetxy(nine.getInstance(), 89, -240);
        }
    } else if (counter::shipMove == 31 * ENEMY_SPAWN_TIME && currentScreen == SCREEN_STORY_BATTLE_1) {
        currentScreen = SCREEN_STORY_2A1;
        screenSwitch();
    }
}
void setTwo() {
    if (counter::shipMove == 1 * ENEMY_SPAWN_TIME) {
        one[0].resetHealth(level);
        two[0].resetHealth(level);
        ViewSetxy(one[0].getInstance(), 33, -94);
        ViewSetxy(two[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 2 * ENEMY_SPAWN_TIME) {
        four[0].resetHealth(level);
        three[0].resetHealth(level);
        ViewSetxy(four[0].getInstance(), 33, -94);
        ViewSetxy(three[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 3 * ENEMY_SPAWN_TIME) {
        five[0].resetHealth(level);
        ViewSetxy(five[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 4 * ENEMY_SPAWN_TIME) {
        three[1].resetHealth(level);
        two[1].resetHealth(level);
        ViewSetxy(three[1].getInstance(), 33, -94);
        ViewSetxy(two[1].getInstance(), 193, -94);
    } else if (counter::shipMove == 5 * ENEMY_SPAWN_TIME) {
        three[2].resetHealth(level);
        four[1].resetHealth(level);
        three[3].resetHealth(level);
        ViewSetxy(three[2].getInstance(), 0, -94);
        ViewSetxy(four[1].getInstance(), 113, -94);
        ViewSetxy(three[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 6 * ENEMY_SPAWN_TIME) {
        one[1].resetHealth(level);
        two[2].resetHealth(level);
        two[3].resetHealth(level);
        ViewSetxy(one[1].getInstance(), 0, -94);
        ViewSetxy(two[2].getInstance(), 113, -94);
        ViewSetxy(two[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 7 * ENEMY_SPAWN_TIME) {
        four[2].resetHealth(level);
        two[4].resetHealth(level);
        three[4].resetHealth(level);
        ViewSetxy(four[2].getInstance(), 0, -94);
        ViewSetxy(two[4].getInstance(), 113, -94);
        ViewSetxy(three[4].getInstance(), 226, -94);
    } else if (counter::shipMove == 8 * ENEMY_SPAWN_TIME) {
        two[5].resetHealth(level);
        one[2].resetHealth(level);
        one[3].resetHealth(level);
        ViewSetxy(two[5].getInstance(), 0, -94);
        ViewSetxy(one[2].getInstance(), 113, -94);
        ViewSetxy(one[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 9 * ENEMY_SPAWN_TIME) {
        four[3].resetHealth(level);
        three[5].resetHealth(level);
        ViewSetxy(four[3].getInstance(), 33, -94);
        ViewSetxy(three[5].getInstance(), 193, -94);
    } else if (counter::shipMove == 10 * ENEMY_SPAWN_TIME) {
        five[1].resetHealth(level);
        five[2].resetHealth(level);
        ViewSetxy(five[1].getInstance(), 33, -94);
        ViewSetxy(five[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 11 * ENEMY_SPAWN_TIME) {
        four[4].resetHealth(level);
        ViewSetxy(four[4].getInstance(), 113, -94);
    } else if (counter::shipMove == 12 * ENEMY_SPAWN_TIME) {
        five[3].resetHealth(level);
        two[6].resetHealth(level);
        ViewSetxy(five[3].getInstance(), 33, -94);
        ViewSetxy(two[6].getInstance(), 193, -94);
    } else if (counter::shipMove == 13 * ENEMY_SPAWN_TIME) {
        three[6].resetHealth(level);
        two[7].resetHealth(level);
        two[8].resetHealth(level);
        ViewSetxy(three[6].getInstance(), 0, -94);
        ViewSetxy(two[7].getInstance(), 113, -94);
        ViewSetxy(two[8].getInstance(), 226, -94);
    } else if (counter::shipMove == 14 * ENEMY_SPAWN_TIME) {
        two[9].resetHealth(level);
        five[4].resetHealth(level);
        one[4].resetHealth(level);
        ViewSetxy(two[9].getInstance(), 0, -94);
        ViewSetxy(five[4].getInstance(), 113, -94);
        ViewSetxy(four[4].getInstance(), 226, -94);
    } else if (counter::shipMove == 15 * ENEMY_SPAWN_TIME) {
        five[0].resetHealth(level);
        one[5].resetHealth(level);
        four[5].resetHealth(level);
        ViewSetxy(five[0].getInstance(), 0, -94);
        ViewSetxy(one[5].getInstance(), 113, -94);
        ViewSetxy(four[5].getInstance(), 226, -94);
    } else if (counter::shipMove == 16 * ENEMY_SPAWN_TIME) {
        one[6].resetHealth(level);
        three[7].resetHealth(level);
        ViewSetxy(one[6].getInstance(), 33, -94);
        ViewSetxy(three[7].getInstance(), 193, -94);
    } else if (counter::shipMove == 17 * ENEMY_SPAWN_TIME) {
        four[6].resetHealth(level);
        five[1].resetHealth(level);
        ViewSetxy(four[6].getInstance(), 33, -94);
        ViewSetxy(five[1].getInstance(), 193, -94);
    } else if (counter::shipMove == 18 * ENEMY_SPAWN_TIME) {
        one[7].resetHealth(level);
        five[2].resetHealth(level);
        one[8].resetHealth(level);
        ViewSetxy(one[7].getInstance(), 0, -94);
        ViewSetxy(five[2].getInstance(), 113, -94);
        ViewSetxy(one[8].getInstance(), 226, -94);
    } else if (counter::shipMove == 19 * ENEMY_SPAWN_TIME) {
        one[9].resetHealth(level);
        three[8].resetHealth(level);
        ViewSetxy(one[9].getInstance(), 33, -94);
        ViewSetxy(three[8].getInstance(), 193, -94);
    } else if (counter::shipMove == 20 * ENEMY_SPAWN_TIME) {
        six[0].resetHealth(level);
        ViewSetxy(six[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 21 * ENEMY_SPAWN_TIME) {
        three[9].resetHealth(level);
        ViewSetxy(three[9].getInstance(), 113, -94);
    } else if (counter::shipMove == 22 * ENEMY_SPAWN_TIME) {
        two[0].resetHealth(level);
        one[0].resetHealth(level);
        ViewSetxy(two[0].getInstance(), 33, -94);
        ViewSetxy(one[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 23 * ENEMY_SPAWN_TIME) {
        three[0].resetHealth(level);
        five[3].resetHealth(level);
        ViewSetxy(three[0].getInstance(), 33, -94);
        ViewSetxy(five[3].getInstance(), 193, -94);
    } else if (counter::shipMove == 24 * ENEMY_SPAWN_TIME) {
        six[1].resetHealth(level);
        four[7].resetHealth(level);
        six[2].resetHealth(level);
        ViewSetxy(six[1].getInstance(), 0, -94);
        ViewSetxy(four[7].getInstance(), 113, -94);
        ViewSetxy(six[2].getInstance(), 226, -94);
    } else if (counter::shipMove == 25 * ENEMY_SPAWN_TIME) {
        four[8].resetHealth(level);
        five[4].resetHealth(level);
        one[2].resetHealth(level);
        ViewSetxy(four[8].getInstance(), 0, -94);
        ViewSetxy(five[4].getInstance(), 113, -94);
        ViewSetxy(one[2].getInstance(), 226, -94);
    } else if (counter::shipMove == 26 * ENEMY_SPAWN_TIME) {
        six[3].resetHealth(level);
        four[9].resetHealth(level);
        six[4].resetHealth(level);
        ViewSetxy(six[3].getInstance(), 0, -94);
        ViewSetxy(four[9].getInstance(), 113, -94);
        ViewSetxy(six[4].getInstance(), 226, -94);
    } else if (counter::shipMove == 27 * ENEMY_SPAWN_TIME) {
        four[0].resetHealth(level);
        five[0].resetHealth(level);
        ViewSetxy(four[0].getInstance(), 33, -94);
        ViewSetxy(five[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 28 * ENEMY_SPAWN_TIME) {
        one[2].resetHealth(level);
        six[0].resetHealth(level);
        ViewSetxy(one[2].getInstance(), 33, -94);
        ViewSetxy(six[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 29 * ENEMY_SPAWN_TIME) {
        five[1].resetHealth(level);
        three[1].resetHealth(level);
        ViewSetxy(five[1].getInstance(), 33, -94);
        ViewSetxy(three[1].getInstance(), 193, -94);
    } else if (counter::shipMove == 30 * ENEMY_SPAWN_TIME) {
        if (currentScreen != SCREEN_STORY_BATTLE_2) {
            nine.resetHealth(level);
            ViewSetxy(nine.getInstance(), 89, -240);
        }
    } else if (counter::shipMove == 31 * ENEMY_SPAWN_TIME && currentScreen == SCREEN_STORY_BATTLE_2) {
        currentScreen = SCREEN_STORY_3A1;
        screenSwitch();
    }
}
void setThree() {
    if (counter::shipMove == 1 * ENEMY_SPAWN_TIME) {
        six[0].resetHealth(level);
        two[0].resetHealth(level);
        ViewSetxy(six[0].getInstance(), 33, -94);
        ViewSetxy(two[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 2 * ENEMY_SPAWN_TIME) {
        three[0].resetHealth(level);
        five[0].resetHealth(level);
        ViewSetxy(three[0].getInstance(), 33, -94);
        ViewSetxy(five[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 3 * ENEMY_SPAWN_TIME) {
        one[0].resetHealth(level);
        four[0].resetHealth(level);
        four[1].resetHealth(level);
        ViewSetxy(one[0].getInstance(), 0, -94);
        ViewSetxy(four[0].getInstance(), 113, -94);
        ViewSetxy(four[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 4 * ENEMY_SPAWN_TIME) {
        one[1].resetHealth(level);
        three[1].resetHealth(level);
        four[2].resetHealth(level);
        ViewSetxy(one[1].getInstance(), 0, -94);
        ViewSetxy(three[1].getInstance(), 113, -94);
        ViewSetxy(four[2].getInstance(), 226, -94);
    } else if (counter::shipMove == 5 * ENEMY_SPAWN_TIME) {
        six[1].resetHealth(level);
        ViewSetxy(six[1].getInstance(), 113, -94);
    } else if (counter::shipMove == 6 * ENEMY_SPAWN_TIME) {
        three[2].resetHealth(level);
        one[2].resetHealth(level);
        ViewSetxy(three[2].getInstance(), 33, -94);
        ViewSetxy(one[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 7 * ENEMY_SPAWN_TIME) {
        two[1].resetHealth(level);
        five[1].resetHealth(level);
        ViewSetxy(two[1].getInstance(), 33, -94);
        ViewSetxy(five[1].getInstance(), 193, -94);
    } else if (counter::shipMove == 8 * ENEMY_SPAWN_TIME) {
        six[2].resetHealth(level);
        two[2].resetHealth(level);
        five[2].resetHealth(level);
        ViewSetxy(six[2].getInstance(), 0, -94);
        ViewSetxy(two[2].getInstance(), 113, -94);
        ViewSetxy(five[2].getInstance(), 226, -94);
    } else if (counter::shipMove == 9 * ENEMY_SPAWN_TIME) {
        one[3].resetHealth(level);
        four[3].resetHealth(level);
        two[3].resetHealth(level);
        ViewSetxy(one[3].getInstance(), 0, -94);
        ViewSetxy(four[3].getInstance(), 113, -94);
        ViewSetxy(two[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 10 * ENEMY_SPAWN_TIME) {
        three[3].resetHealth(level);
        one[4].resetHealth(level);
        five[3].resetHealth(level);
        ViewSetxy(three[3].getInstance(), 0, -94);
        ViewSetxy(one[4].getInstance(), 113, -94);
        ViewSetxy(five[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 11 * ENEMY_SPAWN_TIME) {
        five[4].resetHealth(level);
        two[4].resetHealth(level);
        four[4].resetHealth(level);
        ViewSetxy(five[4].getInstance(), 0, -94);
        ViewSetxy(two[4].getInstance(), 113, -94);
        ViewSetxy(four[4].getInstance(), 226, -94);
    } else if (counter::shipMove == 12 * ENEMY_SPAWN_TIME) {
        six[3].resetHealth(level);
        three[4].resetHealth(level);
        ViewSetxy(six[3].getInstance(), 33, -94);
        ViewSetxy(three[4].getInstance(), 193, -94);
    } else if (counter::shipMove == 13 * ENEMY_SPAWN_TIME) {
        one[5].resetHealth(level);
        three[5].resetHealth(level);
        ViewSetxy(one[5].getInstance(), 33, -94);
        ViewSetxy(three[5].getInstance(), 193, -94);
    } else if (counter::shipMove == 14 * ENEMY_SPAWN_TIME) {
        five[0].resetHealth(level);
        six[4].resetHealth(level);
        five[1].resetHealth(level);
        ViewSetxy(five[0].getInstance(), 0, -94);
        ViewSetxy(six[4].getInstance(), 113, -94);
        ViewSetxy(five[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 15 * ENEMY_SPAWN_TIME) {
        three[6].resetHealth(level);
        four[5].resetHealth(level);
        two[5].resetHealth(level);
        ViewSetxy(three[6].getInstance(), 0, -94);
        ViewSetxy(four[5].getInstance(), 113, -94);
        ViewSetxy(two[5].getInstance(), 226, -94);
    } else if (counter::shipMove == 16 * ENEMY_SPAWN_TIME) {
        six[0].resetHealth(level);
        four[6].resetHealth(level);
        six[1].resetHealth(level);
        ViewSetxy(six[0].getInstance(), 0, -94);
        ViewSetxy(four[6].getInstance(), 113, -94);
        ViewSetxy(six[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 17 * ENEMY_SPAWN_TIME) {
        seven[0].resetHealth(level);
        ViewSetxy(seven[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 18 * ENEMY_SPAWN_TIME) {
        seven[1].resetHealth(level);
        seven[2].resetHealth(level);
        ViewSetxy(seven[1].getInstance(), 33, -94);
        ViewSetxy(seven[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 19 * ENEMY_SPAWN_TIME) {
        five[2].resetHealth(level);
        seven[3].resetHealth(level);
        four[7].resetHealth(level);
        ViewSetxy(five[2].getInstance(), 0, -94);
        ViewSetxy(seven[3].getInstance(), 113, -94);
        ViewSetxy(four[7].getInstance(), 226, -94);
    } else if (counter::shipMove == 20 * ENEMY_SPAWN_TIME) {
        three[7].resetHealth(level);
        five[3].resetHealth(level);
        two[6].resetHealth(level);
        ViewSetxy(three[7].getInstance(), 0, -94);
        ViewSetxy(five[3].getInstance(), 113, -94);
        ViewSetxy(two[6].getInstance(), 226, -94);
    } else if (counter::shipMove == 21 * ENEMY_SPAWN_TIME) {
        five[4].resetHealth(level);
        seven[4].resetHealth(level);
        four[8].resetHealth(level);
        ViewSetxy(five[4].getInstance(), 0, -94);
        ViewSetxy(seven[4].getInstance(), 113, -94);
        ViewSetxy(four[8].getInstance(), 226, -94);
    } else if (counter::shipMove == 22 * ENEMY_SPAWN_TIME) {
        six[3].resetHealth(level);
        one[6].resetHealth(level);
        three[8].resetHealth(level);
        ViewSetxy(six[3].getInstance(), 0, -94);
        ViewSetxy(one[6].getInstance(), 113, -94);
        ViewSetxy(three[8].getInstance(), 226, -94);
    } else if (counter::shipMove == 23 * ENEMY_SPAWN_TIME) {
        three[9].resetHealth(level);
        four[9].resetHealth(level);
        ViewSetxy(three[9].getInstance(), 33, -94);
        ViewSetxy(four[9].getInstance(), 193, -94);
    } else if (counter::shipMove == 24 * ENEMY_SPAWN_TIME) {
        seven[0].resetHealth(level);
        six[4].resetHealth(level);
        ViewSetxy(seven[0].getInstance(), 33, -94);
        ViewSetxy(six[4].getInstance(), 193, -94);
    } else if (counter::shipMove == 25 * ENEMY_SPAWN_TIME) {
        six[0].resetHealth(level);
        ViewSetxy(six[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 26 * ENEMY_SPAWN_TIME) {
        two[7].resetHealth(level);
        one[7].resetHealth(level);
        ViewSetxy(two[7].getInstance(), 33, -94);
        ViewSetxy(one[7].getInstance(), 193, -94);
    } else if (counter::shipMove == 27 * ENEMY_SPAWN_TIME) {
        six[1].resetHealth(level);
        seven[1].resetHealth(level);
        ViewSetxy(six[1].getInstance(), 33, -94);
        ViewSetxy(seven[1].getInstance(), 193, -94);
    } else if (counter::shipMove == 28 * ENEMY_SPAWN_TIME) {
        three[1].resetHealth(level);
        one[8].resetHealth(level);
        two[8].resetHealth(level);
        ViewSetxy(three[1].getInstance(), 0, -94);
        ViewSetxy(one[8].getInstance(), 113, -94);
        ViewSetxy(two[8].getInstance(), 226, -94);
    } else if (counter::shipMove == 29 * ENEMY_SPAWN_TIME) {
        five[0].resetHealth(level);
        seven[2].resetHealth(level);
        ViewSetxy(five[0].getInstance(), 33, -94);
        ViewSetxy(seven[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 30 * ENEMY_SPAWN_TIME) {
        nine.resetHealth(level);
        ViewSetxy(nine.getInstance(), 89, -240);
    }
}
void setFour() {
    if (counter::shipMove == 1 * ENEMY_SPAWN_TIME) {
        one[0].resetHealth(level);
        two[0].resetHealth(level);
        ViewSetxy(one[0].getInstance(), 33, -94);
        ViewSetxy(two[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 2 * ENEMY_SPAWN_TIME) {
        six[0].resetHealth(level);
        three[0].resetHealth(level);
        ViewSetxy(six[0].getInstance(), 33, -94);
        ViewSetxy(three[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 3 * ENEMY_SPAWN_TIME) {
        four[0].resetHealth(level);
        five[0].resetHealth(level);
        four[1].resetHealth(level);
        ViewSetxy(four[0].getInstance(), 0, -94);
        ViewSetxy(five[0].getInstance(), 113, -94);
        ViewSetxy(four[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 4 * ENEMY_SPAWN_TIME) {
        one[1].resetHealth(level);
        seven[0].resetHealth(level);
        two[1].resetHealth(level);
        ViewSetxy(one[1].getInstance(), 0, -94);
        ViewSetxy(seven[0].getInstance(), 113, -94);
        ViewSetxy(two[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 5 * ENEMY_SPAWN_TIME) {
        five[1].resetHealth(level);
        three[1].resetHealth(level);
        four[2].resetHealth(level);
        ViewSetxy(five[1].getInstance(), 0, -94);
        ViewSetxy(three[1].getInstance(), 113, -94);
        ViewSetxy(four[2].getInstance(), 226, -94);
    } else if (counter::shipMove == 6 * ENEMY_SPAWN_TIME) {
        six[1].resetHealth(level);
        seven[1].resetHealth(level);
        ViewSetxy(six[1].getInstance(), 33, -94);
        ViewSetxy(seven[1].getInstance(), 193, -94);
    } else if (counter::shipMove == 7 * ENEMY_SPAWN_TIME) {
        six[2].resetHealth(level);
        ViewSetxy(six[2].getInstance(), 113, -94);
    } else if (counter::shipMove == 8 * ENEMY_SPAWN_TIME) {
        seven[2].resetHealth(level);
        ViewSetxy(seven[2].getInstance(), 113, -94);
    } else if (counter::shipMove == 9 * ENEMY_SPAWN_TIME) {
        two[2].resetHealth(level);
        one[2].resetHealth(level);
        ViewSetxy(two[2].getInstance(), 33, -94);
        ViewSetxy(one[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 10 * ENEMY_SPAWN_TIME) {
        three[2].resetHealth(level);
        five[2].resetHealth(level);
        ViewSetxy(three[2].getInstance(), 33, -94);
        ViewSetxy(five[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 11 * ENEMY_SPAWN_TIME) {
        six[3].resetHealth(level);
        one[3].resetHealth(level);
        seven[3].resetHealth(level);
        ViewSetxy(six[3].getInstance(), 0, -94);
        ViewSetxy(one[3].getInstance(), 113, -94);
        ViewSetxy(seven[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 12 * ENEMY_SPAWN_TIME) {
        four[3].resetHealth(level);
        seven[4].resetHealth(level);
        three[3].resetHealth(level);
        ViewSetxy(four[3].getInstance(), 0, -94);
        ViewSetxy(seven[4].getInstance(), 113, -94);
        ViewSetxy(three[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 13 * ENEMY_SPAWN_TIME) {
        one[4].resetHealth(level);
        six[4].resetHealth(level);
        two[3].resetHealth(level);
        ViewSetxy(one[4].getInstance(), 0, -94);
        ViewSetxy(six[4].getInstance(), 113, -94);
        ViewSetxy(two[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 14 * ENEMY_SPAWN_TIME) {
        seven[0].resetHealth(level);
        ViewSetxy(seven[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 15 * ENEMY_SPAWN_TIME) {
        four[4].resetHealth(level);
        three[4].resetHealth(level);
        ViewSetxy(four[4].getInstance(), 33, -94);
        ViewSetxy(three[4].getInstance(), 193, -94);
    } else if (counter::shipMove == 16 * ENEMY_SPAWN_TIME) {
        one[5].resetHealth(level);
        two[4].resetHealth(level);
        ViewSetxy(one[5].getInstance(), 33, -94);
        ViewSetxy(two[4].getInstance(), 193, -94);
    } else if (counter::shipMove == 17 * ENEMY_SPAWN_TIME) {
        five[3].resetHealth(level);
        six[0].resetHealth(level);
        five[4].resetHealth(level);
        ViewSetxy(five[3].getInstance(), 0, -94);
        ViewSetxy(six[0].getInstance(), 113, -94);
        ViewSetxy(five[4].getInstance(), 226, -94);
    } else if (counter::shipMove == 18 * ENEMY_SPAWN_TIME) {
        six[1].resetHealth(level);
        seven[1].resetHealth(level);
        three[5].resetHealth(level);
        ViewSetxy(six[1].getInstance(), 0, -94);
        ViewSetxy(seven[1].getInstance(), 113, -94);
        ViewSetxy(three[5].getInstance(), 226, -94);
    } else if (counter::shipMove == 19 * ENEMY_SPAWN_TIME) {
        one[6].resetHealth(level);
        five[0].resetHealth(level);
        two[5].resetHealth(level);
        ViewSetxy(one[6].getInstance(), 0, -94);
        ViewSetxy(five[0].getInstance(), 113, -94);
        ViewSetxy(two[5].getInstance(), 226, -94);
    } else if (counter::shipMove == 20 * ENEMY_SPAWN_TIME) {
        seven[2].resetHealth(level);
        four[5].resetHealth(level);
        five[1].resetHealth(level);
        ViewSetxy(seven[2].getInstance(), 0, -94);
        ViewSetxy(four[5].getInstance(), 113, -94);
        ViewSetxy(five[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 21 * ENEMY_SPAWN_TIME) {
        eight[0].resetHealth(level);
        ViewSetxy(eight[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 22 * ENEMY_SPAWN_TIME) {
        seven[3].resetHealth(level);
        eight[1].resetHealth(level);
        ViewSetxy(seven[3].getInstance(), 33, -94);
        ViewSetxy(eight[1].getInstance(), 193, -94);
    } else if (counter::shipMove == 23 * ENEMY_SPAWN_TIME) {
        one[7].resetHealth(level);
        two[6].resetHealth(level);
        ViewSetxy(one[7].getInstance(), 33, -94);
        ViewSetxy(two[6].getInstance(), 193, -94);
    } else if (counter::shipMove == 24 * ENEMY_SPAWN_TIME) {
        four[6].resetHealth(level);
        three[6].resetHealth(level);
        ViewSetxy(four[6].getInstance(), 33, -94);
        ViewSetxy(three[6].getInstance(), 193, -94);
    } else if (counter::shipMove == 25 * ENEMY_SPAWN_TIME) {
        seven[4].resetHealth(level);
        eight[2].resetHealth(level);
        four[7].resetHealth(level);
        ViewSetxy(seven[4].getInstance(), 0, -94);
        ViewSetxy(eight[2].getInstance(), 113, -94);
        ViewSetxy(four[7].getInstance(), 226, -94);
    } else if (counter::shipMove == 26 * ENEMY_SPAWN_TIME) {
        six[2].resetHealth(level);
        two[7].resetHealth(level);
        six[3].resetHealth(level);
        ViewSetxy(six[2].getInstance(), 0, -94);
        ViewSetxy(two[7].getInstance(), 113, -94);
        ViewSetxy(six[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 27 * ENEMY_SPAWN_TIME) {
        one[8].resetHealth(level);
        five[2].resetHealth(level);
        one[9].resetHealth(level);
        ViewSetxy(one[8].getInstance(), 0, -94);
        ViewSetxy(five[2].getInstance(), 113, -94);
        ViewSetxy(one[9].getInstance(), 226, -94);
    } else if (counter::shipMove == 28 * ENEMY_SPAWN_TIME) {
        eight[3].resetHealth(level);
        three[7].resetHealth(level);
        eight[4].resetHealth(level);
        ViewSetxy(eight[3].getInstance(), 0, -94);
        ViewSetxy(three[7].getInstance(), 113, -94);
        ViewSetxy(eight[4].getInstance(), 226, -94);
    } else if (counter::shipMove == 29 * ENEMY_SPAWN_TIME) {
        five[3].resetHealth(level);
        two[8].resetHealth(level);
        ViewSetxy(five[3].getInstance(), 33, -94);
        ViewSetxy(two[8].getInstance(), 193, -94);
    } else if (counter::shipMove == 30 * ENEMY_SPAWN_TIME) {
        if (currentScreen != SCREEN_STORY_BATTLE_5) {
            nine.resetHealth(level);
            ViewSetxy(nine.getInstance(), 89, -240);
        }
    } else if (counter::shipMove == 31 * ENEMY_SPAWN_TIME && currentScreen == SCREEN_STORY_BATTLE_5) {
        currentScreen = SCREEN_STORY_6A1;
        screenSwitch();
    }
}
void setFive() {
    if (counter::shipMove == 1 * ENEMY_SPAWN_TIME) {
        six[0].resetHealth(level);
        ViewSetxy(six[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 2 * ENEMY_SPAWN_TIME) {
        seven[0].resetHealth(level);
        two[0].resetHealth(level);
        ViewSetxy(seven[0].getInstance(), 33, -94);
        ViewSetxy(two[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 3 * ENEMY_SPAWN_TIME) {
        one[0].resetHealth(level);
        eight[0].resetHealth(level);
        ViewSetxy(one[0].getInstance(), 33, -94);
        ViewSetxy(eight[0].getInstance(), 193, -94);
    } else if (counter::shipMove == 4 * ENEMY_SPAWN_TIME) {
        five[0].resetHealth(level);
        six[1].resetHealth(level);
        four[0].resetHealth(level);
        ViewSetxy(five[0].getInstance(), 0, -94);
        ViewSetxy(six[1].getInstance(), 113, -94);
        ViewSetxy(four[0].getInstance(), 226, -94);
    } else if (counter::shipMove == 5 * ENEMY_SPAWN_TIME) {
        three[0].resetHealth(level);
        one[1].resetHealth(level);
        seven[1].resetHealth(level);
        ViewSetxy(three[0].getInstance(), 0, -94);
        ViewSetxy(one[1].getInstance(), 113, -94);
        ViewSetxy(seven[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 6 * ENEMY_SPAWN_TIME) {
        seven[2].resetHealth(level);
        eight[1].resetHealth(level);
        six[2].resetHealth(level);
        ViewSetxy(seven[2].getInstance(), 0, -94);
        ViewSetxy(eight[1].getInstance(), 113, -94);
        ViewSetxy(six[2].getInstance(), 226, -94);
    } else if (counter::shipMove == 7 * ENEMY_SPAWN_TIME) {
        three[1].resetHealth(level);
        one[2].resetHealth(level);
        four[1].resetHealth(level);
        ViewSetxy(three[1].getInstance(), 0, -94);
        ViewSetxy(one[2].getInstance(), 113, -94);
        ViewSetxy(four[1].getInstance(), 226, -94);
    } else if (counter::shipMove == 8 * ENEMY_SPAWN_TIME) {
        two[1].resetHealth(level);
        seven[3].resetHealth(level);
        ViewSetxy(two[1].getInstance(), 33, -94);
        ViewSetxy(seven[3].getInstance(), 193, -94);
    } else if (counter::shipMove == 9 * ENEMY_SPAWN_TIME) {
        six[3].resetHealth(level);
        three[2].resetHealth(level);
        ViewSetxy(six[3].getInstance(), 33, -94);
        ViewSetxy(three[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 10 * ENEMY_SPAWN_TIME) {
        six[4].resetHealth(level);
        ViewSetxy(six[4].getInstance(), 113, -94);
    } else if (counter::shipMove == 11 * ENEMY_SPAWN_TIME) {
        eight[2].resetHealth(level);
        ViewSetxy(eight[2].getInstance(), 113, -94);
    } else if (counter::shipMove == 12 * ENEMY_SPAWN_TIME) {
        five[1].resetHealth(level);
        one[3].resetHealth(level);
        six[0].resetHealth(level);
        ViewSetxy(five[1].getInstance(), 0, -94);
        ViewSetxy(one[3].getInstance(), 113, -94);
        ViewSetxy(six[0].getInstance(), 226, -94);
    } else if (counter::shipMove == 13 * ENEMY_SPAWN_TIME) {
        four[2].resetHealth(level);
        three[3].resetHealth(level);
        five[2].resetHealth(level);
        ViewSetxy(four[2].getInstance(), 0, -94);
        ViewSetxy(three[3].getInstance(), 113, -94);
        ViewSetxy(five[2].getInstance(), 226, -94);
    } else if (counter::shipMove == 14 * ENEMY_SPAWN_TIME) {
        two[2].resetHealth(level);
        six[1].resetHealth(level);
        three[4].resetHealth(level);
        ViewSetxy(two[2].getInstance(), 0, -94);
        ViewSetxy(six[1].getInstance(), 113, -94);
        ViewSetxy(three[4].getInstance(), 226, -94);
    } else if (counter::shipMove == 15 * ENEMY_SPAWN_TIME) {
        eight[3].resetHealth(level);
        four[3].resetHealth(level);
        ViewSetxy(eight[3].getInstance(), 33, -94);
        ViewSetxy(four[3].getInstance(), 193, -94);
    } else if (counter::shipMove == 16 * ENEMY_SPAWN_TIME) {
        three[5].resetHealth(level);
        six[2].resetHealth(level);
        ViewSetxy(three[5].getInstance(), 33, -94);
        ViewSetxy(six[2].getInstance(), 193, -94);
    } else if (counter::shipMove == 17 * ENEMY_SPAWN_TIME) {
        eight[4].resetHealth(level);
        five[3].resetHealth(level);
        six[3].resetHealth(level);
        ViewSetxy(eight[4].getInstance(), 0, -94);
        ViewSetxy(five[3].getInstance(), 113, -94);
        ViewSetxy(six[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 18 * ENEMY_SPAWN_TIME) {
        seven[4].resetHealth(level);
        ViewSetxy(seven[4].getInstance(), 113, -94);
    } else if (counter::shipMove == 19 * ENEMY_SPAWN_TIME) {
        eight[0].resetHealth(level);
        ViewSetxy(eight[0].getInstance(), 113, -94);
    } else if (counter::shipMove == 20 * ENEMY_SPAWN_TIME) {
        five[4].resetHealth(level);
        six[4].resetHealth(level); 
        ViewSetxy(five[4].getInstance(), 33, -94);
        ViewSetxy(six[4].getInstance(), 193, -94);
    } else if (counter::shipMove == 21 * ENEMY_SPAWN_TIME) {
        eight[1].resetHealth(level);
        six[0].resetHealth(level);
        seven[0].resetHealth(level);
        ViewSetxy(eight[1].getInstance(), 0, -94);
        ViewSetxy(six[0].getInstance(), 113, -94);
        ViewSetxy(seven[0].getInstance(), 226, -94);
    } else if (counter::shipMove == 22 * ENEMY_SPAWN_TIME) {
        two[3].resetHealth(level);
        four[4].resetHealth(level);
        three[6].resetHealth(level);
        ViewSetxy(two[3].getInstance(), 0, -94);
        ViewSetxy(four[4].getInstance(), 113, -94);
        ViewSetxy(three[6].getInstance(), 226, -94);
    } else if (counter::shipMove == 23 * ENEMY_SPAWN_TIME) {
        six[1].resetHealth(level);
        two[4].resetHealth(level);
        five[0].resetHealth(level);
        ViewSetxy(six[1].getInstance(), 0, -94);
        ViewSetxy(two[4].getInstance(), 113, -94);
        ViewSetxy(five[0].getInstance(), 226, -94);
    } else if (counter::shipMove == 24 * ENEMY_SPAWN_TIME) {
        eight[2].resetHealth(level);
        seven[1].resetHealth(level);
        six[2].resetHealth(level);
        ViewSetxy(eight[2].getInstance(), 0, -94);
        ViewSetxy(seven[1].getInstance(), 113, -94);
        ViewSetxy(six[2].getInstance(), 226, -94);
    } else if (counter::shipMove == 25 * ENEMY_SPAWN_TIME) {
        two[5].resetHealth(level);
        seven[2].resetHealth(level);
        three[7].resetHealth(level);
        ViewSetxy(two[5].getInstance(), 0, -94);
        ViewSetxy(seven[2].getInstance(), 113, -94);
        ViewSetxy(three[7].getInstance(), 226, -94);
    } else if (counter::shipMove == 26 * ENEMY_SPAWN_TIME) {
        eight[3].resetHealth(level);
        one[4].resetHealth(level);
        ViewSetxy(eight[3].getInstance(), 33, -94);
        ViewSetxy(one[4].getInstance(), 193, -94);
    } else if (counter::shipMove == 27 * ENEMY_SPAWN_TIME) {
        two[6].resetHealth(level);
        five[1].resetHealth(level);
        three[8].resetHealth(level);
        ViewSetxy(two[6].getInstance(), 0, -94);
        ViewSetxy(five[1].getInstance(), 113, -94);
        ViewSetxy(three[8].getInstance(), 226, -94);
    } else if (counter::shipMove == 28 * ENEMY_SPAWN_TIME) {
        seven[3].resetHealth(level);
        five[2].resetHealth(level);
        six[3].resetHealth(level);
        ViewSetxy(seven[3].getInstance(), 0, -94);
        ViewSetxy(five[2].getInstance(), 113, -94);
        ViewSetxy(six[3].getInstance(), 226, -94);
    } else if (counter::shipMove == 29 * ENEMY_SPAWN_TIME) {
        six[3].resetHealth(level);
        eight[4].resetHealth(level);
        ViewSetxy(six[3].getInstance(), 33, -94);
        ViewSetxy(eight[4].getInstance(), 193, -94);
    } else if (counter::shipMove == 30 * ENEMY_SPAWN_TIME) {
        ten.resetHealth(level);
        ViewSetxy(ten.getInstance(), 85, -240);
    }
}
void enemyShipMove() {
    for (int i = 0; i < 10; i++) {
        //y cords
        one[i].setYCoord(ViewGety(one[i].getInstance()));
        two[i].setYCoord(ViewGety(two[i].getInstance()));
        three[i].setYCoord(ViewGety(three[i].getInstance()));
        four[i].setYCoord(ViewGety(four[i].getInstance()));
        //x cords
        one[i].setXCoord(ViewGetx(one[i].getInstance()));
        two[i].setXCoord(ViewGetx(two[i].getInstance()));
        three[i].setXCoord(ViewGetx(three[i].getInstance()));
        four[i].setXCoord(ViewGetx(four[i].getInstance()));
    }
    for (int i = 0; i < 5; i++) {
        //y cords
        five[i].setYCoord(ViewGety(five[i].getInstance()));
        six[i].setYCoord(ViewGety(six[i].getInstance()));
        seven[i].setYCoord(ViewGety(seven[i].getInstance()));
        eight[i].setYCoord(ViewGety(eight[i].getInstance()));
        //x cords
        five[i].setXCoord(ViewGetx(five[i].getInstance()));
        six[i].setXCoord(ViewGetx(six[i].getInstance()));
        seven[i].setXCoord(ViewGetx(seven[i].getInstance()));
        eight[i].setXCoord(ViewGetx(eight[i].getInstance()));
    }
    //x cords
    nine.setXCoord(ViewGetx(nine.getInstance()));
    //y cords
    nine.setYCoord(ViewGety(nine.getInstance()));
    //x cords
    ten.setXCoord(ViewGetx(ten.getInstance()));
    //y cords
    ten.setYCoord(ViewGety(ten.getInstance()));
    for (int i = 0; i < 10; i++) {
        if (one[i].getYCoord() < 600) {
            ViewSetxy(one[i].getInstance(), one[i].getXCoord(), one[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (two[i].getYCoord() < 600) {
            ViewSetxy(two[i].getInstance(), two[i].getXCoord(), two[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (three[i].getYCoord() < 600) {
            ViewSetxy(three[i].getInstance(), three[i].getXCoord(), three[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (four[i].getYCoord() < 600) {
            ViewSetxy(four[i].getInstance(), four[i].getXCoord(), four[i].getYCoord() + ENEMY_FLY_SPEED);
        }
    }
    for (int i = 0; i < 5; i++) {
        if (five[i].getYCoord() < 600) {
            ViewSetxy(five[i].getInstance(), five[i].getXCoord(), five[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (six[i].getYCoord() < 600) {
            ViewSetxy(six[i].getInstance(), six[i].getXCoord(), six[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (seven[i].getYCoord() < 600) {
            ViewSetxy(seven[i].getInstance(), seven[i].getXCoord(), seven[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (eight[i].getYCoord() < 600) {
            ViewSetxy(eight[i].getInstance(), eight[i].getXCoord(), eight[i].getYCoord() + ENEMY_FLY_SPEED);
        }
    }
    
    static bool goRight = false;
    //ship 9
    if (nine.getYCoord() < 40) {
        ViewSetxy(nine.getInstance(), nine.getXCoord(), nine.getYCoord() + ENEMY_FLY_SPEED);
    } else if (nine.getYCoord() >= 40 && nine.getYCoord() < 600) {
        const int FACTOR = (goRight) ? (1) : (-1);
        ViewSetxy(nine.getInstance(), nine.getXCoord() + FACTOR, nine.getYCoord());
    }
    if (nine.getXCoord() == 29) {
        goRight = true;
    } else if (nine.getXCoord() == 149) {
        goRight = false;
    }
    //ship 10
    if (ten.getYCoord() < 40) {
        ViewSetxy(ten.getInstance(), ten.getXCoord(), ten.getYCoord() + ENEMY_FLY_SPEED);
    } else if (ten.getYCoord() >= 40 && ten.getYCoord() < 600) {
        const int FACTOR = (goRight) ? (1) : (-1);
        ViewSetxy(ten.getInstance(), ten.getXCoord() + FACTOR, ten.getYCoord());
    }
    if (ten.getXCoord() == 25) {
        goRight = true;
    } else if (ten.getXCoord() == 145) {
        goRight = false;
    }
}
void doEnemyShipMove() {
    enemyShipMove();
    switch (set) {
        case 1:
            setOne();
            break;
        case 2:
            setTwo();
            break;
        case 3:
            setThree();
            break;
        case 4:
            setFour();
            break;
        case 5:
            setFive();
            break;
        case 6:
            counter::shipMove = 0;
            level += 1;
            set = 1;
            break;
    }
}
void doEnemyShipShoot() {
    for (int i = 0; i < 5; i++) {
        if (counter::bulletMove == (i + 1) * ENEMY_BULLET_COOLDOWN_SPEED) {
            //ship 1-4
            for (int j = 0; j < 10; j++) {
                one[j].setBullet(i, one[j].getXCoord() + 43, one[j].getYCoord() + 83);
                two[j].setBullet(i, two[j].getXCoord() + 43, two[j].getYCoord() + 94);
                three[j].setBullet(i, three[j].getXCoord() + 43, three[j].getYCoord() + 88);
                four[j].setBullet(i, four[j].getXCoord() + 43, four[j].getYCoord() + 94);
            }
            //ship 5-8
            for (int j = 0; j < 5; j++) {
                five[j].setBulletOne(i, five[j].getXCoord() + 31, five[j].getYCoord() + 71);
                five[j].setBulletTwo(i, five[j].getXCoord() + 54, five[j].getYCoord() + 71);
                six[j].setBulletOne(i, six[j].getXCoord() + 15, six[j].getYCoord() + 53);
                six[j].setBulletTwo(i, six[j].getXCoord() + 68, six[j].getYCoord() + 53);
                seven[j].setRocket(i, seven[j].getXCoord() + 42, seven[j].getYCoord() + 83);
                eight[j].setBulletOne(i, eight[j].getXCoord() + 12, eight[j].getYCoord() + 54);
                eight[j].setRocket(i, eight[j].getXCoord() + 42, eight[j].getYCoord() + 92);
                eight[j].setBulletTwo(i, eight[j].getXCoord() + 74, eight[j].getYCoord() + 54);
            }
            //ship 9
            nine.setBulletOne(i, nine.getXCoord() + 3, nine.getYCoord() + 83);
            nine.setRocket(i, nine.getXCoord() + 66, nine.getYCoord() + 230);
            nine.setBulletTwo(i, nine.getXCoord() + 130, nine.getYCoord() + 83);
            //ship 10
            ten.setBulletOne(i, ten.getXCoord() + 13, ten.getYCoord() + 83);
            ten.setRocket(i, ten.getXCoord() + 69, ten.getYCoord() + 233);
            ten.setBulletTwo(i, ten.getXCoord() + 129, ten.getYCoord() + 83);
        }
    }
    if (counter::bulletMove >= 5 * ENEMY_BULLET_COOLDOWN_SPEED) {
        counter::bulletMove = 0;
    }
    if (counter::bulletMove % ENEMY_BULLET_COOLDOWN_SPEED != 0) {
        //1
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoord = ViewGetx(one[i].getBullet(j));
                const int yCoord = ViewGety(one[i].getBullet(j));
                if (yCoord < 600) {
                    one[i].setBullet(j, xCoord, yCoord + ENEMY_BULLET_SPEED);
                }
                if (yCoord > mY && yCoord < mY + 94 && xCoord > mX + width1 && xCoord < mX + width2) {
                    health -= 1;
                    state::healthUpdate = true;
                    one[i].setBullet(j, 600, 600);
                }
            }
        }
        //2
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoord = ViewGetx(two[i].getBullet(j));
                const int yCoord = ViewGety(two[i].getBullet(j));
                if (yCoord < 600) {
                    two[i].setBullet(j, xCoord, yCoord + ENEMY_BULLET_SPEED);
                }
                if (yCoord > mY && yCoord < mY + 94 && xCoord > mX + width1 && xCoord < mX + width2) {
                    health -= 1;
                    state::healthUpdate = true;
                    two[i].setBullet(j, 600, 600);
                }
            }
        }
        //3
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoord = ViewGetx(three[i].getBullet(j));
                const int yCoord = ViewGety(three[i].getBullet(j));
                if (yCoord < 600) {
                    three[i].setBullet(j, xCoord, yCoord + ENEMY_BULLET_SPEED);
                }
                if (yCoord > mY && yCoord < mY + 94 && xCoord > mX + width1 && xCoord < mX + width2) {
                    health -= 1;
                    state::healthUpdate = true;
                    three[i].setBullet(j, 600, 600);
                }
            }
        }
        //4
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoord = ViewGetx(four[i].getBullet(j));
                const int yCoord = ViewGety(four[i].getBullet(j));
                if (yCoord < 600) {
                    four[i].setBullet(j, xCoord, yCoord + ENEMY_BULLET_SPEED);
                }
                if (yCoord > mY && yCoord < mY + 94 && xCoord > mX + width1 && xCoord < mX + width2) {
                    health -= 1;
                    state::healthUpdate = true;
                    four[i].setBullet(j, 600, 600);
                }
            }
        }
        //5
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoordOne = ViewGetx(five[i].getBulletOne(j));
                const int yCoordOne = ViewGety(five[i].getBulletOne(j));
                const int xCoordThree = ViewGetx(five[i].getBulletTwo(j));
                const int yCoordThree = ViewGety(five[i].getBulletTwo(j));
                if (yCoordOne < 600 || yCoordThree < 600) {
                    five[i].setBulletOne(j, xCoordOne, yCoordOne + ENEMY_BULLET_SPEED);
                    five[i].setBulletTwo(j, xCoordThree, yCoordThree + ENEMY_BULLET_SPEED);
                }
                if (yCoordOne > mY && yCoordOne < mY + 94 && xCoordOne > mX + width1 && xCoordOne < mX + width2) {
                    health -= 1;
                    state::healthUpdate = true;
                    five[i].setBulletOne(j, 600, 600);
                }
                if (yCoordThree > mY && yCoordThree < mY + 94 && xCoordThree > mX + width1 && xCoordThree < mX + width2) {
                    health -= 1;
                    state::healthUpdate = true;
                    five[i].setBulletTwo(j, 600, 600);
                }
            }
        }
        //6
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoordOne = ViewGetx(six[i].getBulletOne(j));
                const int yCoordOne = ViewGety(six[i].getBulletOne(j));
                const int xCoordThree = ViewGetx(six[i].getBulletTwo(j));
                const int yCoordThree = ViewGety(six[i].getBulletTwo(j));
                if (yCoordOne < 600 || yCoordThree < 600) {
                    six[i].setBulletOne(j, xCoordOne, yCoordOne + ENEMY_BULLET_SPEED);
                    six[i].setBulletTwo(j, xCoordThree, yCoordThree + ENEMY_BULLET_SPEED);
                }
                if (yCoordOne > mY && yCoordOne < mY + 94 && xCoordOne > mX + width1 && xCoordOne < mX + width2) {
                    health -= 1;
                    state::healthUpdate = true;
                    six[i].setBulletOne(j, 600, 600);
                }
                if (yCoordThree > mY && yCoordThree < mY + 94 && xCoordThree > mX + width1 && xCoordThree < mX + width2) {
                    health -= 1;
                    state::healthUpdate = true;
                    six[i].setBulletTwo(j, 600, 600);
                }
            }
        }
        //7
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoordTwo = ViewGetx(seven[i].getRocket(j));
                const int yCoordTwo = ViewGety(seven[i].getRocket(j));
                if (yCoordTwo < 600) {
                    seven[i].setRocket(j, xCoordTwo, yCoordTwo + ENEMY_BULLET_SPEED);
                }
                if (yCoordTwo > mY && yCoordTwo < mY + 94 && xCoordTwo > mX + width1 && xCoordTwo < mX + width2) {
                    health -= 3;
                    state::healthUpdate = true;
                    seven[i].setRocket(j, 600, 600);
                }
            }
        }
        //8
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoordOne = ViewGetx(eight[i].getBulletOne(j));
                const int yCoordOne = ViewGety(eight[i].getBulletOne(j));
                const int xCoordTwo = ViewGetx(eight[i].getRocket(j));
                const int yCoordTwo = ViewGety(eight[i].getRocket(j));
                const int xCoordThree = ViewGetx(eight[i].getBulletTwo(j));
                const int yCoordThree = ViewGety(eight[i].getBulletTwo(j));
                if (yCoordOne < 600 || yCoordTwo < 600 || yCoordThree < 600) {
                    eight[i].setBulletOne(j, xCoordOne, yCoordOne + ENEMY_BULLET_SPEED);
                    eight[i].setRocket(j, xCoordTwo, yCoordTwo + ENEMY_BULLET_SPEED);
                    eight[i].setBulletTwo(j, xCoordThree, yCoordThree + ENEMY_BULLET_SPEED);
                }
                if (yCoordOne > mY && yCoordOne < mY + 94 && xCoordOne > mX + width1 && xCoordOne < mX + width2) {
                    health -= 1;
                    state::healthUpdate = true;
                    eight[i].setBulletOne(j, 600, 600);
                }
                if (yCoordTwo > mY && yCoordTwo < mY + 94 && xCoordTwo > mX + width1 && xCoordTwo < mX + width2) {
                    health -= 3;
                    state::healthUpdate = true;
                    eight[i].setRocket(j, 600, 600);
                }
                if (yCoordThree > mY && yCoordThree < mY + 94 && xCoordThree > mX + width1 && xCoordThree < mX + width2) {
                    health -= 1;
                    state::healthUpdate = true;
                    eight[i].setBulletTwo(j, 600, 600);
                }
            }
        }
        //9
        for (int j = 0; j < 5; j++) {
            const int xCoordOne = ViewGetx(nine.getBulletOne(j));
            const int yCoordOne = ViewGety(nine.getBulletOne(j));
            const int xCoordTwo = ViewGetx(nine.getRocket(j));
            const int yCoordTwo = ViewGety(nine.getRocket(j));
            const int xCoordThree = ViewGetx(nine.getBulletTwo(j));
            const int yCoordThree = ViewGety(nine.getBulletTwo(j));
            if (yCoordOne < 600 || yCoordTwo < 600 || yCoordThree < 600) {
                nine.setBulletOne(j, xCoordOne, yCoordOne + ENEMY_BULLET_SPEED);
                nine.setRocket(j, xCoordTwo, yCoordTwo + ENEMY_BULLET_SPEED);
                nine.setBulletTwo(j, xCoordThree, yCoordThree + ENEMY_BULLET_SPEED);
            }
            if (yCoordOne > mY && yCoordOne < mY + 94 && xCoordOne > mX + width1 && xCoordOne < mX + width2) {
                health -= 1;
                state::healthUpdate = true;
                nine.setBulletOne(j, 600, 600);
            }
            if (yCoordTwo > mY && yCoordTwo < mY + 94 && xCoordTwo > mX + width1 && xCoordTwo < mX + width2) {
                health -= 3;
                state::healthUpdate = true;
                nine.setRocket(j, 600, 600);
            }
            if (yCoordThree > mY && yCoordThree < mY + 94 && xCoordThree > mX + width1 && xCoordThree < mX + width2) {
                health -= 1;
                state::healthUpdate = true;
                nine.setBulletTwo(j, 600, 600);
            }
        }
        //10
        for (int j = 0; j < 5; j++) {
            const int xCoordOne = ViewGetx(ten.getBulletOne(j));
            const int yCoordOne = ViewGety(ten.getBulletOne(j));
            const int xCoordTwo = ViewGetx(ten.getRocket(j));
            const int yCoordTwo = ViewGety(ten.getRocket(j));
            const int xCoordThree = ViewGetx(ten.getBulletTwo(j));
            const int yCoordThree = ViewGety(ten.getBulletTwo(j));
            if (yCoordOne < 600 || yCoordTwo < 600 || yCoordThree < 600) {
                ten.setBulletOne(j, xCoordOne, yCoordOne + ENEMY_BULLET_SPEED);
                ten.setRocket(j, xCoordTwo, yCoordTwo + ENEMY_BULLET_SPEED);
                ten.setBulletTwo(j, xCoordThree, yCoordThree + ENEMY_BULLET_SPEED);
            }
            if (yCoordOne > mY && yCoordOne < mY + 94 && xCoordOne > mX + width1 && xCoordOne < mX + width2) {
                health -= 1;
                state::healthUpdate = true;
                ten.setBulletOne(j, 600, 600);
            }
            if (yCoordTwo > mY && yCoordTwo < mY + 94 && xCoordTwo > mX + width1 && xCoordTwo < mX + width2) {
                health -= 3;
                state::healthUpdate = true;
                ten.setRocket(j, 600, 600);
            }
            if (yCoordThree > mY && yCoordThree < mY + 94 && xCoordThree > mX + width1 && xCoordThree < mX + width2) {
                health -= 1;
                state::healthUpdate = true;
                ten.setBulletTwo(j, 600, 600);
            }
        }
    }
}
bool shipInAction(int ship) {
    const int i = counter::shipAction;
    bool ret = false;
    switch (ship) {
        case 1:
            ret = one[i].getHealth() <= 0 && one[i].getYCoord() >= 0 && one[i].getXCoord() < 600 
                && one[i].getYCoord() >= 0 && one[i].getXCoord() <= 320;
            break;
        case 2:
            ret = two[i].getHealth() <= 0 && two[i].getYCoord() >= 0 && two[i].getXCoord() < 600 
                && two[i].getYCoord() >= 0 && two[i].getXCoord() <= 320;
            break;
        case 3:
            ret = three[i].getHealth() <= 0 && three[i].getYCoord() >= 0 && three[i].getXCoord() < 600 
                && three[i].getYCoord() >= 0 && three[i].getXCoord() <= 320;
            break;
        case 4:
            ret = four[i].getHealth() <= 0 && four[i].getYCoord() >= 0 && four[i].getXCoord() < 600 
                && four[i].getYCoord() >= 0 && four[i].getXCoord() <= 320;
            break;
        case 5:
            ret = five[i].getHealth() <= 0 && five[i].getYCoord() >= 0 && five[i].getXCoord() < 600 
                && five[i].getYCoord() >= 0 && five[i].getXCoord() <= 320;
            break;
        case 6:
            ret = six[i].getHealth() <= 0 && six[i].getYCoord() >= 0 && six[i].getXCoord() < 600 
                && six[i].getYCoord() >= 0 && six[i].getXCoord() <= 320;
            break;
        case 7:
            ret = seven[i].getHealth() <= 0 && seven[i].getYCoord() >= 0 && seven[i].getXCoord() < 600 
                && seven[i].getYCoord() >= 0 && seven[i].getXCoord() <= 320;
            break;
        case 8:
            ret = eight[i].getHealth() <= 0 && eight[i].getYCoord() >= 0 && eight[i].getXCoord() < 600 
                && eight[i].getYCoord() >= 0 && eight[i].getXCoord() <= 320;
            break;
        case 9:
            ret = nine.getHealth() <= 0 && nine.getYCoord() >= 0 && nine.getXCoord() < 600 
                && nine.getYCoord() >= 0 && nine.getXCoord() <= 320;
            break;
        case 10:
            ret = ten.getHealth() <= 0 && ten.getYCoord() >= 0 && ten.getXCoord() < 600 
                && ten.getYCoord() >= 0 && ten.getXCoord() <= 320;
            break;
    }
    return ret;
}
int setEnemyExplosion(int ship) {
    const int i = counter::shipAction;
    int explosion;
    switch (ship) {
        case 1:
            explosion = one[i].getInstance();
            break;
        case 2:
            explosion = two[i].getInstance();
            break;
        case 3:
            explosion = three[i].getInstance();
            break;
        case 4:
            explosion = four[i].getInstance();
            break;
        case 5:
            explosion = five[i].getInstance();
            break;
        case 6:
            explosion = six[i].getInstance();
            break;
        case 7:
            explosion = seven[i].getInstance();
            break;
        case 8:
            explosion = eight[i].getInstance();
            break;
    }
    return explosion;
}
void enemyDied() {
    int explosion, image;
    for (int i = 1; i <= 4; i++) {
        for (counter::shipAction = 0; counter::shipAction < 10; counter::shipAction++) {
            bool used = false;
            for (int j = 0; j <= 8; j++) {
                if (counter::enemyExplosion[i - 1] == j && shipInAction(i) && !used) {
                    explosion = setEnemyExplosion(i);
                    char temp[] = "Images/Explosion_1.png";
                    temp[17] = char(j + 1 + '0');
                    image = ImageAdd(temp);
                    ViewSetImage(explosion, image);
                    counter::enemyExplosion[i - 1] += 1;
                    used = true;
                }
            }
            if (counter::enemyExplosion[i - 1] == 9 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_10.png");
                ViewSetImage(explosion, image);
                counter::enemyExplosion[i - 1] += 1;
            } else if (counter::enemyExplosion[i - 1] == 10 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_11.png");
                ViewSetImage(explosion, image);
                counter::enemyExplosion[i - 1] += 1;
            } else if (counter::enemyExplosion[i - 1] == 11 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                char tempShip[] = "Images/eShip_1.png";
                tempShip[13] = char(i + '0');
                image = ImageAdd(tempShip);
                ViewSetImage(explosion, image);
                if (i == 1) {
                    ViewSetxy(one[counter::shipAction].getInstance(), 600, 600);
                } else if (i == 2) {
                    ViewSetxy(two[counter::shipAction].getInstance(), 600, 600);
                } else if (i == 3) {
                    ViewSetxy(three[counter::shipAction].getInstance(), 600, 600);
                } else if (i == 4) {
                    ViewSetxy(four[counter::shipAction].getInstance(), 600, 600);
                }
                counter::enemyExplosion[i - 1] = 0;
                xp += XP_SHIP_DESTROY_1_TO_4 + round(level / XP_INCREASE);
            }
        }
    }

    for (int i = 5; i <= 8; i++) {
        for (counter::shipAction = 0; counter::shipAction < 5; counter::shipAction++) {
            bool used = false;
            for (int j = 0; j <= 8; j++) {
                if (counter::enemyExplosion[i - 1] == j && shipInAction(i) && !used) {
                    explosion = setEnemyExplosion(i);
                    char temp[] = "Images/Explosion_1.png";
                    temp[17] = char(j + 1 + '0');
                    image = ImageAdd(temp);
                    ViewSetImage(explosion, image);
                    counter::enemyExplosion[i - 1] += 1;
                    used = true;
                }
            }
            if (counter::enemyExplosion[i - 1] == 9 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_10.png");
                ViewSetImage(explosion, image);
                counter::enemyExplosion[i - 1] += 1;
            } else if (counter::enemyExplosion[i - 1] == 10 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_11.png");
                ViewSetImage(explosion, image);
                counter::enemyExplosion[i - 1] += 1;
            } else if (counter::enemyExplosion[i - 1] == 11 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                char tempShip[] = "Images/eShip_1.png";
                tempShip[13] = char(i + '0');
                image = ImageAdd(tempShip);
                ViewSetImage(explosion, image);
                if (i == 5) {
                    ViewSetxy(five[counter::shipAction].getInstance(), 600, 600);
                } else if (i == 6) {
                    ViewSetxy(six[counter::shipAction].getInstance(), 600, 600);
                } else if (i == 7) {
                    ViewSetxy(seven[counter::shipAction].getInstance(), 600, 600);
                } else if (i == 8) {
                    ViewSetxy(eight[counter::shipAction].getInstance(), 600, 600);
                }
                counter::enemyExplosion[i - 1] = 0;
                xp += XP_SHIP_DESTROY_5_TO_8 + round(level / XP_INCREASE);
            }
        }
    }

    bool used = false;
    for (int j = 0; j <= 8; j++) {
        if (counter::enemyExplosion[8] == j && shipInAction(9) && !used) {
            explosion = nine.getInstance();
            char temp[] = "Images/BigExplosion_1.png";
            temp[20] = char(j + 1 + '0');
            image = ImageAdd(temp);
            ViewSetImage(explosion, image);
            counter::enemyExplosion[8] += 1;
            used = true;
        }
    }
    if (counter::enemyExplosion[8] == 9 && shipInAction(9)) {
        explosion = nine.getInstance();
        image = ImageAdd("Images/BigExplosion_10.png");
        ViewSetImage(explosion, image);
        counter::enemyExplosion[8] += 1;
    } else if (counter::enemyExplosion[8] == 10 && shipInAction(9)) {
        explosion = nine.getInstance();
        image = ImageAdd("Images/BigExplosion_11.png");
        ViewSetImage(explosion, image);
        counter::enemyExplosion[8] += 1;
    } else if (counter::enemyExplosion[8] == 11 && shipInAction(9)) {
        explosion = nine.getInstance();
        image = ImageAdd("Images/eMini-Boss.png");
        ViewSetImage(explosion, image);
        ViewSetxy(nine.getInstance(), 600, 600);
        counter::enemyExplosion[8] = 0;
        xp += XP_SHIP_DESTROY_9 + round(2 * level / XP_INCREASE);
        if (currentScreen != SCREEN_STORY_BATTLE_4) {
            set += 1;
            counter::shipMove = 0;
            health = possibleHealth;
            state::healthUpdate = true;
        } else if (currentScreen == SCREEN_STORY_BATTLE_4) {
            currentScreen = SCREEN_STORY_5A1;
            screenSwitch();
        }
    }

    used = false;
    for (int j = 0; j <= 8; j++) {
        if (counter::enemyExplosion[9] == j && shipInAction(10) && !used) {
            explosion = ten.getInstance();
            char temp[] = "Images/BigExplosion_1.png";
            temp[20] = char(j + 1 + '0');
            image = ImageAdd(temp);
            ViewSetImage(explosion, image);
            counter::enemyExplosion[9] += 1;
            used = true;
        }
    }
    if (counter::enemyExplosion[9] == 9 && shipInAction(10)) {
        explosion = ten.getInstance();
        image = ImageAdd("Images/BigExplosion_10.png");
        ViewSetImage(explosion, image);
        counter::enemyExplosion[9] += 1;
    } else if (counter::enemyExplosion[9] == 10 && shipInAction(10)) {
        explosion = ten.getInstance();
        image = ImageAdd("Images/BigExplosion_11.png");
        ViewSetImage(explosion, image);
        counter::enemyExplosion[9] += 1;
    } else if (counter::enemyExplosion[9] == 11 && shipInAction(10)) {
        explosion = ten.getInstance();
        image = ImageAdd("Images/eBoss.png");
        ViewSetImage(explosion, image);
        ViewSetxy(ten.getInstance(), 600, 600);
        counter::enemyExplosion[9] = 0;
        xp += XP_SHIP_DESTROY_10 + round(2 * level / XP_INCREASE);
        if (currentScreen != SCREEN_STORY_BATTLE_6) {
            set += 1;
            counter::shipMove = 0;
            health = possibleHealth;
            state::healthUpdate = true;
        } else if (currentScreen == SCREEN_STORY_BATTLE_6) {
            currentScreen = SCREEN_STORY_7W1;
            screenSwitch();
        }
    }
}
void shipCollision() {
    for (int i = 0; i < 10; i++) {
        //ship 1
        if (mX + width1 < one[i].getXCoord() + 76 && mX + width2 > one[i].getXCoord() + 18 
            && mY < one[i].getYCoord() + 94 && mY + 94 > one[i].getYCoord()) {
            if (one[i].getHealth() > 0) {
                one[i].damage(3);
                health -= 3;
                state::healthUpdate = true;
            }
        }
        //ship 2
        if (mX + width1 < two[i].getXCoord() + 69 && mX + width2 > two[i].getXCoord() + 24 
            && mY < two[i].getYCoord() + 94 && mY + 94 > two[i].getYCoord()) {
            if (two[i].getHealth() > 0) {
                two[i].damage(3);
                health -= 3;
                state::healthUpdate = true;
            }
        }
        //ship 3
        if (mX + width1 < three[i].getXCoord() + 66 && mX + width2 > three[i].getXCoord() + 27 
            && mY < three[i].getYCoord() + 94 && mY + 94 > three[i].getYCoord()) {
            if (three[i].getHealth() > 0) {
                three[i].damage(3);
                health -= 3;
                state::healthUpdate = true;
            }
        }
        //ship 4
        if (mX + width1 < four[i].getXCoord() + 87 && mX + width2 > four[i].getXCoord() + 6 
            && mY < four[i].getYCoord() + 94 && mY + 94 > four[i].getYCoord()) {
            if (four[i].getHealth() > 0) {
                four[i].damage(3);
                health -= 3;
                state::healthUpdate = true;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        //ship 5
        if (mX + width1 < five[i].getXCoord() + 71 && mX + width2 > five[i].getXCoord() + 22 
            && mY < five[i].getYCoord() + 94 && mY + 94 > five[i].getYCoord()) {
            if (five[i].getHealth() > 0) {
                five[i].damage(3);
                health -= 3;
                state::healthUpdate = true;
            }
        }
        //ship 6
        if (mX + width1 < six[i].getXCoord() + 81 && mX + width2 > six[i].getXCoord() + 12 
            && mY < six[i].getYCoord() + 94 && mY + 94 > six[i].getYCoord()) {
            if (six[i].getHealth() > 0) {
                six[i].damage(3);
                health -= 3;
                state::healthUpdate = true;
            }
        }
        //ship 7
        if (mX + width1 < seven[i].getXCoord() + 86 && mX + width2 > seven[i].getXCoord() + 7 
            && mY < seven[i].getYCoord() + 94 && mY + 94 > seven[i].getYCoord()) {
            if (seven[i].getHealth() > 0) {
                seven[i].damage(3);
                health -= 3;
                state::healthUpdate = true;
            }
        }
        //ship 8
        if (mX + width1 < eight[i].getXCoord() + 86 && mX + width2 > eight[i].getXCoord() + 6 
            && mY < eight[i].getYCoord() + 94 && mY + 94 > eight[i].getYCoord()) {
            if (eight[i].getHealth() > 0) {
                eight[i].damage(3);
                health -= 3;
                state::healthUpdate = true;
            }
        }
    }
    //ship 9
    if (mX + width1 < nine.getXCoord() + 142 && mX + width2 > nine.getXCoord() 
        && mY < nine.getYCoord() + 240 && mY + 94 > nine.getYCoord()) {
        if (nine.getHealth() > 0) {
            nine.damage(3);
            health = 0;
            state::healthUpdate = true;
        }
    }
    //ship 10
    if (mX + width1 < ten.getXCoord() + 150 && mX + width2 > ten.getXCoord() 
        && mY < ten.getYCoord() + 240 && mY + 94 > ten.getYCoord()) {
        if (ten.getHealth() > 0) {
            ten.damage(3);
            health = 0;
            state::healthUpdate = true;
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
    if (counter::healthRegen >= round(150 * 10 / PLAYER_HEALTH_RATIO)) {
        counter::healthRegen = 0;
        health += 1;
        state::healthUpdate = true;
    }
}
bool createMove() {
    return currentScreen == SCREEN_ENDLESS || currentScreen == SCREEN_STORY_BATTLE_1
                || currentScreen == SCREEN_STORY_BATTLE_2 || currentScreen == SCREEN_STORY_BATTLE_4
                || currentScreen == SCREEN_STORY_BATTLE_5 || currentScreen == SCREEN_STORY_BATTLE_6;
}
void OnTimer() {
    //called 30 times per second - 1800=1min - 10000=5min 36sec
    rankFromXp();
    soundSwitch();
    if (state::sound) {
        counter::sound += 1;
    }
    if (!state::pause) {
        if (createMove()) {
            counter::bulletTime += 1;
            counter::shipMove += 1;
            doEnemyShipMove();
            counter::bulletMove += 1;
            doEnemyShipShoot();
            if (health < possibleHealth / 2) {
                counter::healthRegen += 1;
            } else {
                counter::healthRegen = 0;
            }
            healthRegen();
            bulletTime();
            healthBar();
            mShipMove();
            enemyDied();
            shipCollision();
        } else if (currentScreen == SCREEN_STORY_TORTURE && state::torture) {
            if (counter::torture == 0) {
                ViewSetxy(imageTorture, -1, -1);
            } else if (counter::torture == 1) {
                ViewSetxy(imageTorture, 0, 0);
            } else if (counter::torture == 2) {
                ViewSetxy(imageTorture, -2, -2);
            } else if (counter::torture == 3) {
                ViewSetxy(imageTorture, -1, -1);
            } else if (counter::torture == 4) {
                ViewSetxy(imageTorture, -2, 0);
            } else if (counter::torture == 5) {
                ViewSetxy(imageTorture, 0, -2);
            }
            counter::hpTorture -= 3;
            counter::torture += 1;
            if (counter::torture >= 6) {
                counter::torture = 0;
            }
            tortureHealth();
        } else if (currentScreen == SCREEN_STORY_TORTURE && !state::torture) {
            counter::hpTorture += 1;
            tortureHealth();
            TextSetText(textTorture, "");
        }
    }
}
