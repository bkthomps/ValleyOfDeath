/**
 * Bailey Thompson
 * Valley Of Death (1.2.13)
 * 23 January 2017
 * Info: This is a scrolling shooter iPhone app.
 */
#include "DragonFireSDK.h"
#include <assert.h>
#include <math.h>

const int SPAWN_TIME = 100, ENEMY_BASE_HEALTH = 3, ENEMY_INCREASE_HEALTH = 1, ENEMY_SHOOT_COOLDOWN_SPEED = 45;
const int SPEED = 15, TIME = 15, ENEMY_FLY_SPEED = 3, ENEMY_BULLET_SPEED = 8;

char font;
int xp, ship, highscore, health, set, level, shipView, mX, mY, newX, newY, music, possibleHealth, shipSpeed, rank;
int width1, width2, text1, text2, text3, imageTorture, hpTorture, textTorture, healthImage, enemyExplosionCounter[10];
int bulletXOffset, bulletYOffset, bulletXOffset2, bulletYOffset2, bulletXOffset3, bulletYOffset3;

namespace Bullets {
    int m1[15], m2[15], m3[15];
    int e1b2[50];
    int e2b2[50];
    int e3b2[50];
    int e4b2[50];
    int e5b1[25], e5b3[25];
    int e6b1[25], e6b3[25];
    int e7b2[25];
    int e8b1[25], e8b2[25], e8b3[25];
    int e9b1[5], e9b2[5], e9b3[5];
    int e10b1[5], e10b2[5], e10b3[5];
}
namespace EnemyShips {
    int e1[10], e2[10], e3[10], e4[10], e5[5], e6[5], e7[5], e8[5], e9[1], e10[1];
    int e1x[10], e2x[10], e3x[10], e4x[10], e5x[5], e6x[5], e7x[5], e8x[5], e9x[1], e10x[1];
    int e1y[10], e2y[10], e3y[10], e4y[10], e5y[5], e6y[5], e7y[5], e8y[5], e9y[1], e10y[1];
    int e1hp[10], e2hp[10], e3hp[10], e4hp[10], e5hp[5], e6hp[5], e7hp[5], e8hp[5], e9hp[1], e10hp[1];
}
namespace Counter {
    int sound, bulletTime, shipMove, bulletMove, hpTorture, torture, shipAction, healthRegen;
}
namespace State {
    bool sound, pause, date, marry, torture, healthUpdate;
}
namespace Container {
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
enum Screen {
    ScreenMenu,
    ScreenPause,
    ScreenEndless,
    ScreenHighscore,
    ScreenDied,
    ScreenStory1a1,
    ScreenStory1a2,
    ScreenStory1s3,
    ScreenStory1p3,
    ScreenStory1a4,
    ScreenStory1r5,
    ScreenStory1e5,
    ScreenStoryBattle1,
    ScreenStory2a1,
    ScreenStory2a2,
    ScreenStory2a3,
    ScreenStory2b4,
    ScreenStory2a5,
    ScreenStory2a6,
    ScreenStory2e7,
    ScreenStory2a7,
    ScreenStoryBattle2,
    ScreenStory3a1,
    ScreenStory3b2,
    ScreenStory3a3,
    ScreenStory3a4,
    ScreenStory3a5,
    ScreenStory3a6,
    ScreenStory3a7,
    ScreenStory3a8,
    ScreenStoryTorture,
    ScreenStory4a1,
    ScreenStory4a2,
    ScreenStory4a3,
    ScreenStory4a4,
    ScreenStory4b5,
    ScreenStory4a6,
    ScreenStory4a7,
    ScreenStory4b7,
    ScreenStory4a8,
    ScreenStoryBattle4,
    ScreenStory5a1,
    ScreenStory5a2,
    ScreenStory5a3,
    ScreenStory5b4,
    ScreenStory5a5,
    ScreenStory5a6,
    ScreenStory5b6,
    ScreenStoryBattle5,
    ScreenStory6a1,
    ScreenStory6a2,
    ScreenStory6a3,
    ScreenStory6b3,
    ScreenStoryBattle6,
    ScreenStory7w1,
    ScreenStory7l1,
    ScreenStory7a2,
    ScreenStory7b2,
    ScreenUnlocks,
    ScreenOptions,
    ScreenDeleteCheckOne,
    ScreenDeleteCheckTwo
};

Screen CurrentScreen, PreviousScreen;
int IntFileToGame(char* buffer) {
    int ret = 0;
    ret += ((int) buffer[0] - '0') * 10000;
    ret += ((int) buffer[1] - '0') * 1000;
    ret += ((int) buffer[2] - '0') * 100;
    ret += ((int) buffer[3] - '0') * 10;
    ret += (int) buffer[4] - '0';
    return ret;
}
bool BoolFileToGame(char* buffer) {
    return buffer[0] == 't';
}
void LoadGame() {
    int fileSound = FileOpen("Sound.txt");
    int fileXp = FileOpen("Xp.txt");
    int fileShip = FileOpen("Ship.txt");
    int fileHighscore = FileOpen("Highscore.txt");
    int fileCounter = FileOpen("Counter.txt");
    char fileBuffer[5];
    if (!fileSound) {
        fileSound = FileCreate("Sound.txt");
        State::sound = true;
    } else {
        fileSound = FileOpen("Sound.txt");
        FileRead(fileSound, fileBuffer, 1);
        State::sound = BoolFileToGame(fileBuffer);
    }
    if (!fileXp) {
        fileXp = FileCreate("Xp.txt");
    } else {
        fileXp = FileOpen("Xp.txt");
        FileRead(fileXp, fileBuffer, 5);
        xp = IntFileToGame(fileBuffer);
    }
    if (!fileShip) {
        fileShip = FileCreate("Ship.txt");
        ship = 1;
    } else {
        fileShip = FileOpen("Ship.txt");
        FileRead(fileShip, fileBuffer, 5);
        ship = IntFileToGame(fileBuffer);
    }
    if (!fileHighscore) {
        fileHighscore = FileCreate("Highscore.txt");
    } else {
        fileHighscore = FileOpen("Highscore.txt");
        FileRead(fileHighscore, fileBuffer, 5);
        highscore = IntFileToGame(fileBuffer);
    }
    if (!fileCounter) {
        fileCounter = FileCreate("Counter.txt");
    } else {
        fileCounter = FileOpen("Counter.txt");
        FileRead(fileCounter, fileBuffer, 5);
        Counter::sound = IntFileToGame(fileBuffer);
    }
    FileClose(fileSound);
    FileClose(fileXp);
    FileClose(fileShip);
    FileClose(fileHighscore);
    FileClose(fileCounter);
}
void Reset() {
    Counter::bulletTime = 0;
    Counter::shipMove = 0;
    mX = 113;
    mY = 380;
    newX = 113;
    newY = 380;
    for (int i = 0; i < 15; i++) {
        ViewSetxy(Bullets::m1[i], -10, -10);
        ViewSetxy(Bullets::m2[i], -20, -20);
        ViewSetxy(Bullets::m3[i], -10, -10);
    }
    for (int i = 0; i < 50; i++) {
        ViewSetxy(Bullets::e1b2[i], 600, 600);
        ViewSetxy(Bullets::e2b2[i], 600, 600);
        ViewSetxy(Bullets::e3b2[i], 600, 600);
        ViewSetxy(Bullets::e4b2[i], 600, 600);
    }
    for (int i = 0; i < 25; i++) {
        ViewSetxy(Bullets::e5b1[i], 600, 600);
        ViewSetxy(Bullets::e5b3[i], 600, 600);
        ViewSetxy(Bullets::e6b1[i], 600, 600);
        ViewSetxy(Bullets::e6b3[i], 600, 600);
        ViewSetxy(Bullets::e7b2[i], 600, 600);
        ViewSetxy(Bullets::e8b1[i], 600, 600);
        ViewSetxy(Bullets::e8b2[i], 600, 600);
        ViewSetxy(Bullets::e8b3[i], 600, 600);
    }
    for (int i = 0; i < 5; i++) {
        ViewSetxy(Bullets::e9b1[i], 600, 600);
        ViewSetxy(Bullets::e9b2[i], 600, 600);
        ViewSetxy(Bullets::e9b3[i], 600, 600);
        ViewSetxy(Bullets::e10b1[i], 600, 600);
        ViewSetxy(Bullets::e10b2[i], 600, 600);
        ViewSetxy(Bullets::e10b3[i], 600, 600);
    }
    int picture, ship;
    for (int i = 0; i < 10; i++) {
        ViewSetxy(EnemyShips::e1[i], 600, 600);
        ship = (EnemyShips::e1[i]);
        picture = ImageAdd("Images/eShip_1.png");
        ViewSetImage(ship, picture);
        ViewSetxy(EnemyShips::e2[i], 600, 600);
        ship = (EnemyShips::e2[i]);
        picture = ImageAdd("Images/eShip_2.png");
        ViewSetImage(ship, picture);
        ViewSetxy(EnemyShips::e3[i], 600, 600);
        ship = (EnemyShips::e3[i]);
        picture = ImageAdd("Images/eShip_3.png");
        ViewSetImage(ship, picture);
        ViewSetxy(EnemyShips::e4[i], 600, 600);
        ship = (EnemyShips::e4[i]);
        picture = ImageAdd("Images/eShip_4.png");
        ViewSetImage(ship, picture);
    }
    for (int i = 0; i < 5; i++) {
        ViewSetxy(EnemyShips::e5[i], 600, 600);
        ship = (EnemyShips::e5[i]);
        picture = ImageAdd("Images/eShip_5.png");
        ViewSetImage(ship, picture);
        ViewSetxy(EnemyShips::e6[i], 600, 600);
        ship = (EnemyShips::e6[i]);
        picture = ImageAdd("Images/eShip_6.png");
        ViewSetImage(ship, picture);
        ViewSetxy(EnemyShips::e7[i], 600, 600);
        ship = (EnemyShips::e7[i]);
        picture = ImageAdd("Images/eShip_7.png");
        ViewSetImage(ship, picture);
        ViewSetxy(EnemyShips::e8[i], 600, 600);
        ship = (EnemyShips::e8[i]);
        picture = ImageAdd("Images/eShip_8.png");
        ViewSetImage(ship, picture);
    }
    ViewSetxy(EnemyShips::e9[0], 600, 600);
    ship = (EnemyShips::e9[0]);
    picture = ImageAdd("Images/eMini-Boss.png");
    ViewSetImage(ship, picture);
    ViewSetxy(EnemyShips::e10[0], 600, 600);
    ship = (EnemyShips::e10[0]);
    picture = ImageAdd("Images/eBoss.png");
    ViewSetImage(ship, picture);
    health = possibleHealth;
    State::healthUpdate = true;
    State::pause = false;
}
void ScreenSwitch() {
    ContainerSetVisible(Container::pause, 0);
    ContainerSetVisible(Container::menu, 0);
    ContainerSetVisible(Container::endless, 0);
    ContainerSetVisible(Container::highscore, 0);
    ContainerSetVisible(Container::died, 0);
    ContainerSetVisible(Container::story1a1, 0);
    ContainerSetVisible(Container::story1a2, 0);
    ContainerSetVisible(Container::story1s3, 0);
    ContainerSetVisible(Container::story1p3, 0);
    ContainerSetVisible(Container::story1a4, 0);
    ContainerSetVisible(Container::story1r5, 0);
    ContainerSetVisible(Container::story1e5, 0);
    ContainerSetVisible(Container::story2a1, 0);
    ContainerSetVisible(Container::story2a2, 0);
    ContainerSetVisible(Container::story2a3, 0);
    ContainerSetVisible(Container::story2b4, 0);
    ContainerSetVisible(Container::story2a5, 0);
    ContainerSetVisible(Container::story2a6, 0);
    ContainerSetVisible(Container::story2e7, 0);
    ContainerSetVisible(Container::story2a7, 0);
    ContainerSetVisible(Container::story3a1, 0);
    ContainerSetVisible(Container::story3b2, 0);
    ContainerSetVisible(Container::story3a3, 0);
    ContainerSetVisible(Container::story3a4, 0);
    ContainerSetVisible(Container::story3a5, 0);
    ContainerSetVisible(Container::story3a6, 0);
    ContainerSetVisible(Container::story3a7, 0);
    ContainerSetVisible(Container::story3a8, 0);
    ContainerSetVisible(Container::storyTorture, 0);
    ContainerSetVisible(Container::story4a1, 0);
    ContainerSetVisible(Container::story4a2, 0);
    ContainerSetVisible(Container::story4a3, 0);
    ContainerSetVisible(Container::story4a4, 0);
    ContainerSetVisible(Container::story4b5, 0);
    ContainerSetVisible(Container::story4a6, 0);
    ContainerSetVisible(Container::story4a7, 0);
    ContainerSetVisible(Container::story4b7, 0);
    ContainerSetVisible(Container::story4a8, 0);
    ContainerSetVisible(Container::story5a1, 0);
    ContainerSetVisible(Container::story5a2, 0);
    ContainerSetVisible(Container::story5a3, 0);
    ContainerSetVisible(Container::story5b4, 0);
    ContainerSetVisible(Container::story5a5, 0);
    ContainerSetVisible(Container::story5a6, 0);
    ContainerSetVisible(Container::story5b6, 0);
    ContainerSetVisible(Container::story6a1, 0);
    ContainerSetVisible(Container::story6a2, 0);
    ContainerSetVisible(Container::story6a3, 0);
    ContainerSetVisible(Container::story6b3, 0);
    ContainerSetVisible(Container::story7w1, 0);
    ContainerSetVisible(Container::story7l1, 0);
    ContainerSetVisible(Container::story7a2, 0);
    ContainerSetVisible(Container::story7b2, 0);
    ContainerSetVisible(Container::unlocks, 0);
    ContainerSetVisible(Container::options, 0);
    ContainerSetVisible(Container::deleteCheckOne, 0);
    ContainerSetVisible(Container::deleteCheckTwo, 0);
    switch (CurrentScreen) {
        case ScreenPause:
            ContainerSetVisible(Container::pause, 1);
            break;
        case ScreenMenu:
            ContainerSetVisible(Container::menu, 1);
            break;
        case ScreenHighscore:
            ContainerSetVisible(Container::highscore, 1);
            break;
        case ScreenDied:
            ContainerSetVisible(Container::died, 1);
            break;
        case ScreenEndless:
            ContainerSetVisible(Container::endless, 1);
            break;
        case ScreenStory1a1:
            ContainerSetVisible(Container::story1a1, 1);
            break;
        case ScreenStory1a2:
            ContainerSetVisible(Container::story1a2, 1);
            break;
        case ScreenStory1s3:
            ContainerSetVisible(Container::story1s3, 1);
            break;
        case ScreenStory1p3:
            ContainerSetVisible(Container::story1p3, 1);
            break;
        case ScreenStory1a4:
            ContainerSetVisible(Container::story1a4, 1);
            break;
        case ScreenStory1r5:
            ContainerSetVisible(Container::story1r5, 1);
            break;
        case ScreenStory1e5:
            ContainerSetVisible(Container::story1e5, 1);
            break;
        case ScreenStoryBattle1:
            ContainerSetVisible(Container::endless, 1);
            break;
        case ScreenStory2a1:
            ContainerSetVisible(Container::story2a1, 1);
            break;
        case ScreenStory2a2:
            ContainerSetVisible(Container::story2a2, 1);
            break;
        case ScreenStory2a3:
            ContainerSetVisible(Container::story2a3, 1);
            break;
        case ScreenStory2b4:
            ContainerSetVisible(Container::story2b4, 1);
            break;
        case ScreenStory2a5:
            ContainerSetVisible(Container::story2a5, 1);
            break;
        case ScreenStory2a6:
            ContainerSetVisible(Container::story2a6, 1);
            break;
        case ScreenStory2e7:
            ContainerSetVisible(Container::story2e7, 1);
            break;
        case ScreenStory2a7:
            ContainerSetVisible(Container::story2a7, 1);
            break;
        case ScreenStoryBattle2:
            ContainerSetVisible(Container::endless, 1);
            break;
        case ScreenStory3a1:
            ContainerSetVisible(Container::story3a1, 1);
            break;
        case ScreenStory3b2:
            ContainerSetVisible(Container::story3b2, 1);
            break;
        case ScreenStory3a3:
            ContainerSetVisible(Container::story3a3, 1);
            break;
        case ScreenStory3a4:
            ContainerSetVisible(Container::story3a4, 1);
            break;
        case ScreenStory3a5:
            ContainerSetVisible(Container::story3a5, 1);
            break;
        case ScreenStory3a6:
            ContainerSetVisible(Container::story3a6, 1);
            break;
        case ScreenStory3a7:
            ContainerSetVisible(Container::story3a7, 1);
            break;
        case ScreenStory3a8:
            ContainerSetVisible(Container::story3a8, 1);
            break;
        case ScreenStoryTorture:
            int ImageTorturing;
            ImageTorturing = ImageAdd("Images/20HP.png");
            ViewSetImage(hpTorture, ImageTorturing);
            Counter::hpTorture = 2000;
            Counter::torture = 0;
            ContainerSetVisible(Container::storyTorture, 1);
            break;
        case ScreenStory4a1:
            ContainerSetVisible(Container::story4a1, 1);
            break;
        case ScreenStory4a2:
            ContainerSetVisible(Container::story4a2, 1);
            break;
        case ScreenStory4a3:
            ContainerSetVisible(Container::story4a3, 1);
            break;
        case ScreenStory4a4:
            ContainerSetVisible(Container::story4a4, 1);
            break;
        case ScreenStory4b5:
            ContainerSetVisible(Container::story4b5, 1);
            break;
        case ScreenStory4a6:
            ContainerSetVisible(Container::story4a6, 1);
            break;
        case ScreenStory4a7:
            ContainerSetVisible(Container::story4a7, 1);
            break;
        case ScreenStory4b7:
            ContainerSetVisible(Container::story4b7, 1);
            break;
        case ScreenStory4a8:
            ContainerSetVisible(Container::story4a8, 1);
            break;
        case ScreenStoryBattle4:
            ContainerSetVisible(Container::endless, 1);
            break;
        case ScreenStory5a1:
            ContainerSetVisible(Container::story5a1, 1);
            break;
        case ScreenStory5a2:
            ContainerSetVisible(Container::story5a2, 1);
            break;
        case ScreenStory5a3:
            ContainerSetVisible(Container::story5a3, 1);
            break;
        case ScreenStory5b4:
            ContainerSetVisible(Container::story5b4, 1);
            break;
        case ScreenStory5a5:
            ContainerSetVisible(Container::story5a5, 1);
            break;
        case ScreenStory5a6:
            ContainerSetVisible(Container::story5a6, 1);
            break;
        case ScreenStory5b6:
            ContainerSetVisible(Container::story5b6, 1);
            break;
        case ScreenStoryBattle5:
            ContainerSetVisible(Container::endless, 1);
            break;
        case ScreenStory6a1:
            ContainerSetVisible(Container::story6a1, 1);
            break;
        case ScreenStory6a2:
            ContainerSetVisible(Container::story6a2, 1);
            break;
        case ScreenStory6a3:
            ContainerSetVisible(Container::story6a3, 1);
            break;
        case ScreenStory6b3:
            ContainerSetVisible(Container::story6b3, 1);
            break;
        case ScreenStoryBattle6:
            ContainerSetVisible(Container::endless, 1);
            break;
        case ScreenStory7w1:
            ContainerSetVisible(Container::story7w1, 1);
            break;
        case ScreenStory7l1:
            ContainerSetVisible(Container::story7l1, 1);
            break;
        case ScreenStory7a2:
            ContainerSetVisible(Container::story7a2, 1);
            break;
        case ScreenStory7b2:
            ContainerSetVisible(Container::story7b2, 1);
            break;
        case ScreenUnlocks:
            ContainerSetVisible(Container::unlocks, 1);
            break;
        case ScreenOptions:
            ContainerSetVisible(Container::options, 1);
            break;
        case ScreenDeleteCheckOne:
            ContainerSetVisible(Container::deleteCheckOne, 1);
            break;
        case ScreenDeleteCheckTwo:
            ContainerSetVisible(Container::deleteCheckTwo, 1);
            break;
    }
}

void DoHighscore() {
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
void DoUpdateHighscore() {
    if (level > highscore) {
        highscore = level;
    }
    DoHighscore();
    assert(health >= 0);
    (health == 0) ? (TextSetText(text1, "\n\nYou Died.")) : (TextSetText(text1, "\n\nYou Left."));
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
    Reset();
}

int OnTorture(int id, int event, int x, int y) {
    if (event == 1 || event == 3) {
        State::torture = !State::torture;
    }
    return 0;
}
int OnHighscore(int id, int event, int x, int y) {
    CurrentScreen = ScreenMenu;
    ScreenSwitch();
    TextSetText(text1, "");
    TextSetText(text2, "");
    TextSetText(text3, "");
    return 0;
}
int OnDied(int id, int event, int x, int y) {
    CurrentScreen = ScreenMenu;
    ScreenSwitch();
    return 0;
}
int OnReturnToMenu(int id, int event, int x, int y) {
    if (event == 3) {
        Reset();
        if (PreviousScreen == ScreenEndless) {
            DoUpdateHighscore();
            CurrentScreen = ScreenHighscore;
        } else if (PreviousScreen == ScreenUnlocks || PreviousScreen == ScreenOptions) {
            CurrentScreen = ScreenMenu;
        } else {
            CurrentScreen = ScreenDied;
        }
        ScreenSwitch();
    }
    return 0;
}
int OnResume(int id, int event, int x, int y) {
    if (event == 3) {
        CurrentScreen = PreviousScreen;
        ScreenSwitch();
        State::pause = false;
    }
    return 0;
}
int OnPause(int id, int event, int x, int y) {
    if (event == 1) {
        PreviousScreen = CurrentScreen;
        CurrentScreen = ScreenPause;
        ScreenSwitch();
        State::pause = true;
    }
    return 0;
}

int OnStoryLevel7(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1) {
            CurrentScreen = ScreenStory7a2;
        } else if (id == 2) {
            const int saveRon = TextAdd(Container::story7b2, 0, 0, "", font);
            if (State::date && !State::marry) {
                TextSetText(saveRon, "\n\nRon: \nThe world will know of your \ngreatness. I will be sure to \ntell "
                    "your girlfriend that you \nwere a great man.");
            } else if (State::date && State::marry) {
                TextSetText(saveRon, "\n\nRon: \nThe world will know of your \ngreatness. I will be sure to \ntell "
                    "your wife that you were a \ngreat man.");
            } else if (!State::date && !State::marry) {
                TextSetText(saveRon, "\n\nRon: \nThe world will know of your \ngreatness.");
            }
            CurrentScreen = ScreenStory7b2;
        } else if (id == 3) {
            xp += 10;
            CurrentScreen = ScreenMenu;
        }
        ScreenSwitch();
    }
    return 0;
}
int OnStoryLevel6(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1) {
            CurrentScreen = ScreenStory6a2;
        } else if (id == 2) {
            CurrentScreen = ScreenStory6a3;
        } else if (id == 3) {
            CurrentScreen = ScreenStory6b3;
        }
        if (id == 4) {
            CurrentScreen = ScreenStoryBattle6;
            ScreenSwitch();
            Reset();
            set = 5;
            level = 1;
        } else {
            ScreenSwitch();
        }
    }
    return 0;
}
int OnStoryLevel5(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1 && !State::date) {
            CurrentScreen = ScreenStory5a3;
        } else if (id == 1 && State::date) {
            CurrentScreen = ScreenStory5a2;
        } else if (id == 2) {
            State::marry = true;
            CurrentScreen = ScreenStory5a3;
        } else if (id == 8) {
            State::marry = false;
            CurrentScreen = ScreenStory5a3;
        } else if (id == 3) {
            CurrentScreen = ScreenStory5b4;
        } else if (id == 4) {
            CurrentScreen = ScreenStory5a5;
        } else if (id == 5) {
            CurrentScreen = ScreenStory5a6;
        } else if (id == 6) {
            CurrentScreen = ScreenStory5b6;
        }
        if (id == 7) {
            CurrentScreen = ScreenStoryBattle5;
            ScreenSwitch();
            Reset();
            set = 4;
            level = 1;
        } else {
            ScreenSwitch();
        }
    }
    return 0;
}
int OnStoryLevel4(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1) {
            CurrentScreen = ScreenDied;
        } else if (id == 2) {
            CurrentScreen = ScreenStory4a2;
        } else if (id == 3) {
            CurrentScreen = ScreenStory4a3;
        } else if (id == 4) {
            CurrentScreen = ScreenStory4a4;
        } else if (id == 5) {
            CurrentScreen = ScreenStory4b5;
        } else if (id == 6) {
            CurrentScreen = ScreenStory4a6;
        } else if (id == 7) {
            CurrentScreen = ScreenStory4a7;
        } else if (id == 8) {
            CurrentScreen = ScreenStory4b7;
        } else if (id == 9) {
            CurrentScreen = ScreenStory4a8;
        }
        if (id == 10) {
            CurrentScreen = ScreenStoryBattle4;
            ScreenSwitch();
            Reset();
            set = 3;
            level = 1;
        } else {
            ScreenSwitch();
        }
    }
    return 0;
}
int OnStoryLevel3(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1) {
            CurrentScreen = ScreenStory3b2;
        } else if (id == 2) {
            CurrentScreen = ScreenStory3a3;
        } else if (id == 3) {
            CurrentScreen = ScreenStory3a4;
        } else if (id == 4) {
            CurrentScreen = ScreenStory3a5;
        } else if (id == 5) {
            CurrentScreen = ScreenStory3a6;
        } else if (id == 6) {
            CurrentScreen = ScreenStory3a7;
        } else if (id == 7) {
            CurrentScreen = ScreenStory3a8;
        } else if (id == 8) {
            CurrentScreen = ScreenStoryTorture;
        }
        ScreenSwitch();
    }
    return 0;
}
int OnStoryLevel2(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1) {
            CurrentScreen = ScreenStory2a2;
        } else if (id == 3) {
            State::date = true;
            CurrentScreen = ScreenStory2a3;
        } else if (id == 4) {
            State::date = false;
            CurrentScreen = ScreenStory2a3;
        } else if (id == 5) {
            CurrentScreen = ScreenStory2a5;
        } else if (id == 6) {
            CurrentScreen = ScreenStory2b4;
        } else if (id == 7) {
            CurrentScreen = ScreenStory2a5;
        } else if (id == 8) {
            CurrentScreen = ScreenStory2a6;
        } else if (id == 9) {
            CurrentScreen = ScreenStory2e7;
        } else if (id == 10) {
            CurrentScreen = ScreenStory2a7;
        }
        if (id == 11) {
            CurrentScreen = ScreenStoryBattle2;
            ScreenSwitch();
            Reset();
            set = 2;
            level = 1;
        } else {
            ScreenSwitch();
        }
    }
    return 0;
}
int OnStoryLevel1(int id, int event, int x, int y) {
    if (event == 3) {
        switch (id) {
            case 1:
                CurrentScreen = ScreenStory1a2;
                break;
            case 3:
                CurrentScreen = ScreenStory1s3;
                break;
            case 4:
                CurrentScreen = ScreenStory1p3;
                break;
            case 5:
                CurrentScreen = ScreenStory1a4;
                break;
            case 6:
                CurrentScreen = ScreenStory1r5;
                break;
            case 7:
                CurrentScreen = ScreenStory1e5;
                break;
        }
        if (id == 8) {
            CurrentScreen = ScreenStoryBattle1;
            ScreenSwitch();
            Reset();
            set = 1;
            level = 1;
        } else if (id != 2) {
            ScreenSwitch();
        }
    }
    return 0;
}
int OnStoryMenuTouch(int id, int event, int x, int y) {
    if (event == 3) {
        CurrentScreen = ScreenStory1a1;
        ScreenSwitch();
    }
    return 0;
}

void ShipType() {
    const int lift = 10;
    ViewSetxy(shipView, -200, -200);
    assert(ship >= 1);
    assert(ship <= 8);
    possibleHealth = 18 + 2 * ship;
    switch (ship) {
        case 1:
            shipView = ViewAdd(Container::endless, "Images/Ship_1.png", -200, -200);
            bulletXOffset = 43;
            bulletYOffset = 11 - lift;
            shipSpeed = 7;
            width1 = 9;
            width2 = 76;
            break;
        case 2:
            shipView = ViewAdd(Container::endless, "Images/Ship_2.png", -200, -200);
            bulletXOffset = 43;
            bulletYOffset = 0 - lift;
            shipSpeed = 7;
            width1 = 15;
            width2 = 69;
            break;
        case 3:
            shipView = ViewAdd(Container::endless, "Images/Ship_3.png", -200, -200);
            bulletXOffset = 43;
            bulletYOffset = 6 - lift;
            shipSpeed = 7;
            width1 = 18;
            width2 = 66;
            break;
        case 4:
            shipView = ViewAdd(Container::endless, "Images/Ship_4.png", -200, -200);
            bulletXOffset = 43;
            bulletYOffset = 0 - lift;
            shipSpeed = 7;
            width1 = -3;
            width2 = 87;
            break;
        case 5:
            shipView = ViewAdd(Container::endless, "Images/Ship_5.png", -200, -200);
            bulletXOffset = 31;
            bulletYOffset = 23 - lift;
            bulletXOffset3 = 54;
            bulletYOffset3 = 23 - lift;
            shipSpeed = 6;
            width1 = 13;
            width2 = 71;
            break;
        case 6:
            shipView = ViewAdd(Container::endless, "Images/Ship_6.png", -200, -200);
            bulletXOffset = 15;
            bulletYOffset = 41 - lift;
            bulletXOffset3 = 68;
            bulletYOffset3 = 41 - lift;
            shipSpeed = 6;
            width1 = 3;
            width2 = 81;
            break;
        case 7:
            shipView = ViewAdd(Container::endless, "Images/Ship_7.png", -200, -200);
            bulletXOffset2 = 42;
            bulletYOffset2 = 11 - lift;
            shipSpeed = 5;
            width1 = -2;
            width2 = 86;
            break;
        case 8:
            shipView = ViewAdd(Container::endless, "Images/Ship_8.png", -200, -200);
            bulletXOffset = 12;
            bulletYOffset = 40 - lift;
            bulletXOffset2 = 42;
            bulletYOffset2 = 2 - lift;
            bulletXOffset3 = 74;
            bulletYOffset3 = 40 - lift;
            shipSpeed = 4;
            width1 = -3;
            width2 = 86;
            break;
    }
    assert(possibleHealth >= 20);
    assert(possibleHealth <= 34);
}
int OnBattleTouch(int id, int event, int x, int y) {
    if (event == 1 || event == 2) {
        newX = x - 47;
        newY = y - 47;
    }
    return 0;
}
int OnEndlessMenuTouch(int id, int event, int x, int y) {
    if (event == 3) {
        Reset();
        health = possibleHealth;
        State::healthUpdate = true;
        level = 1;
        set = 1;
        CurrentScreen = ScreenEndless;
        ScreenSwitch();
    }
    return 0;
}

bool isShipUnlocked(int id) {
    return (id == 1 && rank >= 1) || (id == 2 && rank >= 3) || (id == 3 && rank >= 5) || (id == 4 && rank >= 8) 
        || (id == 5 && rank >= 11) || (id == 6 && rank >= 14) || (id == 7 && rank >= 17) || (id == 8 && rank >= 20);
}
int Unlocks(int id, int event, int x, int y) {
    if (event == 3 && isShipUnlocked(id)) {
            ship = id;
            ShipType();
            CurrentScreen = ScreenMenu;
            ScreenSwitch();
    }
    return 0;
}
int OnUnlocksMenuTouch(int id, int event, int x, int y) {
    int imageUnlocks;
    if (event == 3) {
        assert(rank >= 1);
        assert(rank <= 20);
        const int rankPosition = TextAdd(Container::unlocks, 10, 10, "", font);
        switch (rank) {
            case 1:
                TextSetText(rankPosition, "\n\nLevel 1: Ordinary Shipman");
                break;
            case 2:
                TextSetText(rankPosition, "\n\nLevel 2: Able Shipman");
                break;
            case 3:
                TextSetText(rankPosition, "\n\nLevel 3: Leading Shipman");
                break;
            case 4:
                TextSetText(rankPosition, "\n\nLevel 4: Master Shipman");
                break;
            case 5:
                TextSetText(rankPosition, "\n\nLevel 5: Petty Officer 2nd \n\tClass");
                break;
            case 6:
                TextSetText(rankPosition, "\n\nLevel 6: Petty Officer 1st \n\tClass");
                break;
            case 7:
                TextSetText(rankPosition, "\n\nLevel 7: Chief Petty Officer \n\t2nd Class");
                break;
            case 8:
                TextSetText(rankPosition, "\n\nLevel 8: Chief Petty Officer \n\t1st Class");
                break;
            case 9:
                TextSetText(rankPosition, "\n\nLevel 9: Cadet");
                break;
            case 10:
                TextSetText(rankPosition, "\n\nLevel 10: Ensign");
                break;
            case 11:
                TextSetText(rankPosition, "\n\nLevel 11: Acting \n\t Sub-Lieutenant");
                break;
            case 12:
                TextSetText(rankPosition, "\n\nLevel 12: Sub-Lieutenant");
                break;
            case 13:
                TextSetText(rankPosition, "\n\nLevel 13: Lieutenant");
                break;
            case 14:
                TextSetText(rankPosition, "\n\nLevel 14: Lieutenant \n\t  Commander");
                break;
            case 15:
                TextSetText(rankPosition, "\n\nLevel 15: Commander");
                break;
            case 16:
                TextSetText(rankPosition, "\n\nLevel 16: Captain");
                break;
            case 17:
                TextSetText(rankPosition, "\n\nLevel 17: Commodore");
                break;
            case 18:
                TextSetText(rankPosition, "\n\nLevel 18: Rear-Admiral");
                break;
            case 19:
                TextSetText(rankPosition, "\n\nLevel 19: Vice-Admiral");
                break;
            case 20:
                TextSetText(rankPosition, "\n\nLevel 20: Admiral");
                break;
        }
        imageUnlocks = (rank >= 3) ? (ImageAdd("Unlocks/UnShip_2.png")) : (ImageAdd("Unlocks/LckShip_2.png"));
        ViewSetImage(ViewAdd(Container::unlocks, "Unlocks/LckShip_2.png", 120, 180, Unlocks, 2), imageUnlocks);
        imageUnlocks = (rank >= 5) ? (ImageAdd("Unlocks/UnShip_3.png")) : (ImageAdd("Unlocks/LckShip_3.png"));
        ViewSetImage(ViewAdd(Container::unlocks, "Unlocks/LckShip_3.png", 220, 180, Unlocks, 3), imageUnlocks);
        imageUnlocks = (rank >= 8) ? (ImageAdd("Unlocks/UnShip_4.png")) : (ImageAdd("Unlocks/LckShip_4.png"));
        ViewSetImage(ViewAdd(Container::unlocks, "Unlocks/LckShip_4.png", 20, 280, Unlocks, 4), imageUnlocks);
        imageUnlocks = (rank >= 11) ? (ImageAdd("Unlocks/UnShip_5.png")) : (ImageAdd("Unlocks/LckShip_5.png"));
        ViewSetImage(ViewAdd(Container::unlocks, "Unlocks/LckShip_5.png", 120, 280, Unlocks, 5), imageUnlocks);
        imageUnlocks = (rank >= 14) ? (ImageAdd("Unlocks/UnShip_6.png")) : (ImageAdd("Unlocks/LckShip_6.png"));
        ViewSetImage(ViewAdd(Container::unlocks, "Unlocks/LckShip_6.png", 220, 280, Unlocks, 6), imageUnlocks);
        imageUnlocks = (rank >= 17) ? (ImageAdd("Unlocks/UnShip_7.png")) : (ImageAdd("Unlocks/LckShip_7.png"));
        ViewSetImage(ViewAdd(Container::unlocks, "Unlocks/LckShip_7.png", 60, 380, Unlocks, 7), imageUnlocks);
        imageUnlocks = (rank >= 20) ? (ImageAdd("Unlocks/UnShip_8.png")) : (ImageAdd("Unlocks/LckShip_8.png"));
        ViewSetImage(ViewAdd(Container::unlocks, "Unlocks/LckShip_8.png", 180, 380, Unlocks, 8), imageUnlocks);
        CurrentScreen = ScreenUnlocks;
        ScreenSwitch();
    }
    return 0;
}

int Options(int id, int event, int x, int y) {
    int ImageMusic;
    if (id == 1 && event == 3) {
        if (State::sound) {
            ImageMusic = ImageAdd("Unlocks/MusicOff.png");
            ViewSetImage(music, ImageMusic);
            State::sound = false;
            Mp3Stop();
        } else {
            ImageMusic = ImageAdd("Unlocks/MusicOn.png");
            ViewSetImage(music, ImageMusic);
            State::sound = true;
            if (Counter::sound >= 1 && Counter::sound < 7000) {
                Counter::sound = 7000;
            } else if (Counter::sound >= 7000 && Counter::sound < 13000) {
                Counter::sound = 13000;
            } else if (Counter::sound >= 13000 && Counter::sound < 19000) {
                Counter::sound = 19000;
            } else if (Counter::sound >= 19000 && Counter::sound < 27000) {
                Counter::sound = 27000;
            } else if (Counter::sound >= 27000 && Counter::sound < 34000) {
                Counter::sound = 34000;
            } else if (Counter::sound >= 34000 && Counter::sound < 42000) {
                Counter::sound = 42000;
            } else if (Counter::sound >= 42000 && Counter::sound < 49000) {
                Counter::sound = 49000;
            } else if (Counter::sound >= 49000 && Counter::sound < 55000) {
                Counter::sound = 55000;
            } else if (Counter::sound >= 55000 && Counter::sound < 61000) {
                Counter::sound = 61000;
            } else if (Counter::sound >= 61000 && Counter::sound < 67000) {
                Counter::sound = 67000;
            } else if (Counter::sound >= 67000 && Counter::sound < 73000) {
                Counter::sound = 73000;
            } else if (Counter::sound >= 73000 && Counter::sound < 79000) {
                Counter::sound = 79000;
            } else if (Counter::sound >= 79000) {
                Counter::sound = 1;
            }
        }
    } else if (id == 2 && event == 3) {
        CurrentScreen = ScreenDeleteCheckOne;
        ScreenSwitch();
    } else if (id == 3 && event == 3) {
        CurrentScreen = ScreenDeleteCheckTwo;
        ScreenSwitch();
    } else if (id == 4 && event == 3) {
        xp = 0;
        ship = 1;
        highscore = 0;
        ShipType();
        CurrentScreen = ScreenMenu;
        ScreenSwitch();
    } else if (id == 5 && event == 3) {
        CurrentScreen = ScreenOptions;
        ScreenSwitch();
    }
    return 0;
}
int OnOptionsMenuTouch(int id, int event, int x, int y) {
    if (event == 3) {
        CurrentScreen = ScreenOptions;
        ScreenSwitch();
    }
    return 0;
}

void DeclareContainers() {
    Container::pause = ContainerAdd(0, 0, 0);
    Container::menu = ContainerAdd(0, 0, 0);
    Container::highscore = ContainerAdd(0, 0, 0);
    Container::endless = ContainerAdd(0, 0, 0);
    Container::died = ContainerAdd(0, 0, 0);
    Container::story1a1 = ContainerAdd(0, 0, 0);
    Container::story1a2 = ContainerAdd(0, 0, 0);
    Container::story1s3 = ContainerAdd(0, 0, 0);
    Container::story1p3 = ContainerAdd(0, 0, 0);
    Container::story1a4 = ContainerAdd(0, 0, 0);
    Container::story1r5 = ContainerAdd(0, 0, 0);
    Container::story1e5 = ContainerAdd(0, 0, 0);
    Container::story2a1 = ContainerAdd(0, 0, 0);
    Container::story2a2 = ContainerAdd(0, 0, 0);
    Container::story2a3 = ContainerAdd(0, 0, 0);
    Container::story2b4 = ContainerAdd(0, 0, 0);
    Container::story2a5 = ContainerAdd(0, 0, 0);
    Container::story2a6 = ContainerAdd(0, 0, 0);
    Container::story2e7 = ContainerAdd(0, 0, 0);
    Container::story2a7 = ContainerAdd(0, 0, 0);
    Container::story3a1 = ContainerAdd(0, 0, 0);
    Container::story3b2 = ContainerAdd(0, 0, 0);
    Container::story3a3 = ContainerAdd(0, 0, 0);
    Container::story3a4 = ContainerAdd(0, 0, 0);
    Container::story3a5 = ContainerAdd(0, 0, 0);
    Container::story3a6 = ContainerAdd(0, 0, 0);
    Container::story3a7 = ContainerAdd(0, 0, 0);
    Container::story3a8 = ContainerAdd(0, 0, 0);
    Container::storyTorture = ContainerAdd(0, 0, 0);
    Container::story4a1 = ContainerAdd(0, 0, 0);
    Container::story4a2 = ContainerAdd(0, 0, 0);
    Container::story4a3 = ContainerAdd(0, 0, 0);
    Container::story4a4 = ContainerAdd(0, 0, 0);
    Container::story4b5 = ContainerAdd(0, 0, 0);
    Container::story4a6 = ContainerAdd(0, 0, 0);
    Container::story4a7 = ContainerAdd(0, 0, 0);
    Container::story4b7 = ContainerAdd(0, 0, 0);
    Container::story4a8 = ContainerAdd(0, 0, 0);
    Container::story5a1 = ContainerAdd(0, 0, 0);
    Container::story5a2 = ContainerAdd(0, 0, 0);
    Container::story5a3 = ContainerAdd(0, 0, 0);
    Container::story5b4 = ContainerAdd(0, 0, 0);
    Container::story5a5 = ContainerAdd(0, 0, 0);
    Container::story5a6 = ContainerAdd(0, 0, 0);
    Container::story5b6 = ContainerAdd(0, 0, 0);
    Container::story6a1 = ContainerAdd(0, 0, 0);
    Container::story6a2 = ContainerAdd(0, 0, 0);
    Container::story6a3 = ContainerAdd(0, 0, 0);
    Container::story6b3 = ContainerAdd(0, 0, 0);
    Container::story7w1 = ContainerAdd(0, 0, 0);
    Container::story7l1 = ContainerAdd(0, 0, 0);
    Container::story7a2 = ContainerAdd(0, 0, 0);
    Container::story7b2 = ContainerAdd(0, 0, 0);
    Container::unlocks = ContainerAdd(0, 0, 0);
    Container::options = ContainerAdd(0, 0, 0);
    Container::deleteCheckOne = ContainerAdd(0, 0, 0);
    Container::deleteCheckTwo = ContainerAdd(0, 0, 0);
}
void ContainerSixSeven() {
    //populate Container::story6a1
    ViewAdd(Container::story6a1, "Images/Background.png", 0, 0);
    ViewAdd(Container::story6a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story6a1, "Images/btnOkBig.png", 20, 380, OnStoryLevel6, 1);
    TextAdd(Container::story6a1, 0, 0, "\n\nRon: \nGreat work, now go kill the \nenemy admiral!", font);
    //populate Container::story6a2
    ViewAdd(Container::story6a2, "Images/Background.png", 0, 0);
    ViewAdd(Container::story6a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story6a2, "Images/btnLaugh.png", 20, 380, OnStoryLevel6, 2);
    ViewAdd(Container::story6a2, "Images/btnSo.png", 170, 380, OnStoryLevel6, 3);
    TextAdd(Container::story6a2, 0, 0, "\n\nAdmiral Skerbowh: \nYou will never be able to \ndefeat me. I am simply", 
        font);
    TextAdd(Container::story6a2, 0, 0, "\n\n\n\n\nsmarter, stronger, faster, and \nmore powerful than you.", font);
    //populate Container::story6a3
    ViewAdd(Container::story6a3, "Images/Background.png", 0, 0);
    ViewAdd(Container::story6a3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story6a3, "Images/btnOkSmall.png", 20, 380, OnStoryLevel6, 4);
    ViewAdd(Container::story6a3, "Images/btnLaugh.png", 170, 380, OnStoryLevel6, 4);
    TextAdd(Container::story6a3, 0, 0, "\n\nAdmiral Skerbowh: \nYou laugh in the face of \ndeath? I laugh at your", 
        font);
    TextAdd(Container::story6a3, 0, 0, "\n\n\n\n\nconfidence; however, you \ntruly cannot believe that you \nmay "
        "emerge victorious.", font);
    //populate Container::story6b3
    ViewAdd(Container::story6b3, "Images/Background.png", 0, 0);
    ViewAdd(Container::story6b3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story6b3, "Images/btnOkSmall.png", 20, 380, OnStoryLevel6, 4);
    ViewAdd(Container::story6b3, "Images/btnLaugh.png", 170, 380, OnStoryLevel6, 4);
    TextAdd(Container::story6b3, 0, 0, "\n\nAdmiral Skerbowh: \nSo... You aren't intelligent \nenough to comprehend "
        "your", font);
    TextAdd(Container::story6b3, 0, 0, "\n\n\n\n\ncertain and eventual death.", font);
    //populate Container::story7w1
    ViewAdd(Container::story7w1, "Images/Background.png", 0, 0);
    ViewAdd(Container::story7w1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story7w1, "Images/btnOkBig.png", 20, 380, OnStoryLevel7, 3);
    TextAdd(Container::story7w1, 0, 0, "\n\nRon: \nYou defeated the enemy \nadmiral. The world will know \nof your "
        "greatness.", font);
    //populate Container::story7l1
    ViewAdd(Container::story7l1, "Images/Background.png", 0, 0);
    ViewAdd(Container::story7l1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story7l1, "Images/btnMyself.png", 20, 380, OnStoryLevel7, 1);
    ViewAdd(Container::story7l1, "Images/btnRon.png", 170, 380, OnStoryLevel7, 2);
    TextAdd(Container::story7l1, 0, 0, "\n\nAlex: \nMy ship has sustained critical \ndamage. Every single escape \npod "
        "other than one has been", font);
    TextAdd(Container::story7l1, 0, 0, "\n\n\n\n\n\ntaken or destroyed. Should I \nsave myself or Ron?", font);
    //populate Container::story7a2
    ViewAdd(Container::story7a2, "Images/Background.png", 0, 0);
    ViewAdd(Container::story7a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story7a2, "Images/btnOkBig.png", 20, 380, OnStoryLevel7, 3);
    TextAdd(Container::story7a2, 0, 0, "\n\nExecutioner: \nYou are being executed for \ntreason since you abandoned "
        "\nyour ship and crew to die.", font);
    //populate Container::story7b2
    ViewAdd(Container::story7b2, "Images/Background.png", 0, 0);
    ViewAdd(Container::story7b2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story7b2, "Images/btnOkBig.png", 20, 380, OnStoryLevel7, 3);
}
void ContainerFive() {
    //populate Container::story5a1
    ViewAdd(Container::story5a1, "Images/Background.png", 0, 0);
    ViewAdd(Container::story5a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story5a1, "Images/btnOkSmall.png", 20, 380, OnStoryLevel5, 1);
    ViewAdd(Container::story5a1, "Images/btnThanks.png", 170, 380, OnStoryLevel5, 1);
    TextAdd(Container::story5a1, 0, 0, "\n\nCommodore Bailey: \nCongratulations on your way \nback. For your great "
        "action", font);
    TextAdd(Container::story5a1, 0, 0, "\n\n\n\n\nout there, you have become \npilot of your own ship named \nICC "
        "Kepler.", font);
    //populate Container::story5a2
    ViewAdd(Container::story5a2, "Images/Background.png", 0, 0);
    ViewAdd(Container::story5a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story5a2, "Images/btnYes.png", 20, 380, OnStoryLevel5, 2);
    ViewAdd(Container::story5a2, "Images/btnNo.png", 170, 380, OnStoryLevel5, 8);
    TextAdd(Container::story5a2, 0, 0, "\n\nBecca: \nWill you State::marry me?", font);
    //populate Container::story5a3
    ViewAdd(Container::story5a3, "Images/Background.png", 0, 0);
    ViewAdd(Container::story5a3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story5a3, "Images/btnNo.png", 20, 380, OnStoryLevel5, 3);
    ViewAdd(Container::story5a3, "Images/btnOkSmall.png", 170, 380, OnStoryLevel5, 4);
    TextAdd(Container::story5a3, 0, 0, "\n\nRon: \nWe located the escaped \nenemy. He is an admiral so \nhe is well "
        "guarded, killing him", font);
    TextAdd(Container::story5a3, 0, 0, "\n\n\n\n\n\nwill be no easy feat. I will \ncome with you since I myself \nknow "
        "where the enemy \nadmiral is.", font);
    //populate Container::story5b4
    ViewAdd(Container::story5b4, "Images/Background.png", 0, 0);
    ViewAdd(Container::story5b4, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story5b4, "Images/btnOkSmall.png", 20, 380, OnStoryLevel5, 4);
    ViewAdd(Container::story5b4, "Images/btnSorry.png", 170, 380, OnStoryLevel5, 4);
    TextAdd(Container::story5b4, 0, 0, "\n\nRon: \nFederation orders, sorry \nmate.", font);
    //populate Container::story5a5
    ViewAdd(Container::story5a5, "Images/Background.png", 0, 0);
    ViewAdd(Container::story5a5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story5a5, "Images/btnAround.png", 20, 380, OnStoryLevel5, 5);
    ViewAdd(Container::story5a5, "Images/btnAttack.png", 170, 380, OnStoryLevel5, 6);
    TextAdd(Container::story5a5, 0, 0, "\n\nRon: \nThere's a whole platoon of \nships. Do you go around and \ntry to "
        "avoid them, or do you", font);
    TextAdd(Container::story5a5, 0, 0, "\n\n\n\n\n\nattack?", font);
    //populate Container::story5a6
    ViewAdd(Container::story5a6, "Images/Background.png", 0, 0);
    ViewAdd(Container::story5a6, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story5a6, "Images/btnOkBig.png", 20, 380, OnStoryLevel5, 7);
    TextAdd(Container::story5a6, 0, 0, "\n\nRon: \nThe ships see you before you \nare even able to go around \nand "
        "attack.", font);
    //populate Container::story5b6
    ViewAdd(Container::story5b6, "Images/Background.png", 0, 0);
    ViewAdd(Container::story5b6, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story5b6, "Images/btnOkBig.png", 20, 380, OnStoryLevel5, 7);
    TextAdd(Container::story5b6, 0, 0, "\n\nRon: \nAttacking the ships.", font);
}
void ContainerFour() {
    //populate Container::story4a1
    ViewAdd(Container::story4a1, "Images/Background.png", 0, 0);
    ViewAdd(Container::story4a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story4a1, "Images/btnTakeGun.png", 20, 380, OnStoryLevel4, 2);
    ViewAdd(Container::story4a1, "Images/btnDoNothing.png", 170, 380, OnStoryLevel4, 1);
    TextAdd(Container::story4a1, 0, 0, "\n\nEnemy: \nNow to State::torture you too.", font);
    //populate Container::story4a2
    ViewAdd(Container::story4a2, "Images/Background.png", 0, 0);
    ViewAdd(Container::story4a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story4a2, "Images/btnShoot.png", 20, 380, OnStoryLevel4, 3);
    ViewAdd(Container::story4a2, "Images/btnDoNothing.png", 170, 380, OnStoryLevel4, 1);
    TextAdd(Container::story4a2, 0, 0, "\n\nEnemy: \nYou wouldn't dare shoot!", font);
    //populate Container::story4a3
    ViewAdd(Container::story4a3, "Images/Background.png", 0, 0);
    ViewAdd(Container::story4a3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story4a3, "Images/btnOkBig.png", 20, 380, OnStoryLevel4, 4);
    TextAdd(Container::story4a3, 0, 0, "\n\nAlex: \nHe escaped with an escape \npod!", font);
    //populate Container::story4a4
    ViewAdd(Container::story4a4, "Images/Background.png", 0, 0);
    ViewAdd(Container::story4a4, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story4a4, "Images/btnEnemy.png", 20, 380, OnStoryLevel4, 5);
    ViewAdd(Container::story4a4, "Images/btnMine.png", 170, 380, OnStoryLevel4, 6);
    TextAdd(Container::story4a4, 0, 0, "\n\nAlly: \nYou need to get back. Luckily, \nmy radio signal reaches you. "
		"\nYou can either take the", font);
    TextAdd(Container::story4a4, 0, 0, "\n\n\n\n\n\nenemy ship or try to get back to yours. Also, if you make it back", 
        font);
    TextAdd(Container::story4a4, 0, 0, "\n\n\n\n\n\n\nto your ship, you'll be in \ntemporary command.", font);
    //populate Container::story4b5
    ViewAdd(Container::story4b5, "Images/Background.png", 0, 0);
    ViewAdd(Container::story4b5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story4b5, "Images/btnOkBig.png", 20, 380, OnStoryLevel4, 6);
    TextAdd(Container::story4b5, 0, 0, "\n\nLieutenant Dan: \nThe enemy ship you were \nflying broke down. Luckily,", 
        font);
    TextAdd(Container::story4b5, 0, 0, "\n\n\n\n\nthe crew and I came to save \nyou.", font);
    //populate Container::story4a6
    ViewAdd(Container::story4a6, "Images/Background.png", 0, 0);
    ViewAdd(Container::story4a6, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story4a6, "Images/btnContact.png", 20, 380, OnStoryLevel4, 7);
    ViewAdd(Container::story4a6, "Images/btnShoot.png", 170, 380, OnStoryLevel4, 8);
    TextAdd(Container::story4a6, 0, 0, "\n\nLieutenant Dan: \nYou are in temporary \ncommand. There's ships up "
        "\nahead; do you contact it to", font);
    TextAdd(Container::story4a6, 0, 0, "\n\n\n\n\n\nsee if it's friendly or do you \nshoot at it? There's no way "
        "\naround.", font);
    //populate Container::story4a7
    ViewAdd(Container::story4a7, "Images/Background.png", 0, 0);
    ViewAdd(Container::story4a7, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story4a7, "Images/btnOkBig.png", 20, 380, OnStoryLevel4, 9);
    TextAdd(Container::story4a7, 0, 0, "\n\nLieutenant Dan: \nThe ships say they are \nfriendly, so we went around "
        "\nthem.", font);
    //populate Container::story4b7
    ViewAdd(Container::story4b7, "Images/Background.png", 0, 0);
    ViewAdd(Container::story4b7, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story4b7, "Images/btnOkBig.png", 20, 380, OnStoryLevel4, 10);
    TextAdd(Container::story4b7, 0, 0, "\n\nLieutenant Dan: \nYou shoot at the ships.", font);
    //populate Container::story4a8
    ViewAdd(Container::story4a8, "Images/Background.png", 0, 0);
    ViewAdd(Container::story4a8, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story4a8, "Images/btnOkBig.png", 20, 380, OnStoryLevel4, 10);
    TextAdd(Container::story4a8, 0, 0, "\n\nLieutenant Dan: \nThe ships followed you and \nattack.", font);
}
void ContainerThree() {
    //populate Container::story3a1
    ViewAdd(Container::story3a1, "Images/Background.png", 0, 0);
    ViewAdd(Container::story3a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story3a1, "Images/btnOkSmall.png", 20, 380, OnStoryLevel3, 2);
    ViewAdd(Container::story3a1, "Images/btnNo.png", 170, 380, OnStoryLevel3, 1);
    TextAdd(Container::story3a1, 0, 0, "\n\nCaptain: \nWe should check the \nwreckage.", font);
    //populate Container::story3b2
    ViewAdd(Container::story3b2, "Images/Background.png", 0, 0);
    ViewAdd(Container::story3b2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story3b2, "Images/btnSorry.png", 20, 380, OnStoryLevel3, 2);
    ViewAdd(Container::story3b2, "Images/btnOkSmall.png", 170, 380, OnStoryLevel3, 2);
    TextAdd(Container::story3b2, 0, 0, "\n\nCaptain: \nI'm captain and I say we will, \nso we will.", font);
    //populate Container::story3a3
    ViewAdd(Container::story3a3, "Images/Background.png", 0, 0);
    ViewAdd(Container::story3a3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story3a3, "Images/btnOkSmall.png", 20, 380, OnStoryLevel3, 3);
    ViewAdd(Container::story3a3, "Images/btnNever.png", 170, 380, OnStoryLevel3, 3);
    TextAdd(Container::story3a3, 0, 0, "\n\nEnemy: \nHands up!", font);
    //populate Container::story3a4
    ViewAdd(Container::story3a4, "Images/Background.png", 0, 0);
    ViewAdd(Container::story3a4, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story3a4, "Images/btnWhereAreWe.png", 20, 380, OnStoryLevel3, 4);
    ViewAdd(Container::story3a4, "Images/btnWhereCaptain.png", 170, 380, OnStoryLevel3, 4);
    TextAdd(Container::story3a4, 0, 0, "\n\nEnemy: \nSorry for knocking you out, it \nwas the only way to bring \nyou "
        "here.", font);
    //populate Container::story3a5
    ViewAdd(Container::story3a5, "Images/Background.png", 0, 0);
    ViewAdd(Container::story3a5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story3a5, "Images/btnYes.png", 20, 380, OnStoryLevel3, 5);
    ViewAdd(Container::story3a5, "Images/btnNo.png", 170, 380, OnStoryLevel3, 5);
    TextAdd(Container::story3a5, 0, 0, "\n\nEnemy: \nAre you familiar with State::torture?", font);
    //populate Container::story3a6
    ViewAdd(Container::story3a6, "Images/Background.png", 0, 0);
    ViewAdd(Container::story3a6, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story3a6, "Images/btnOkSmall.png", 20, 380, OnStoryLevel3, 6);
    ViewAdd(Container::story3a6, "Images/btnSo.png", 170, 380, OnStoryLevel3, 6);
    TextAdd(Container::story3a6, 0, 0, "\n\nEnemy: \nTorture is what caused world \nwar 3 on your home planet: "
        "\nEarth.", font);
    //populate Container::story3a7
    ViewAdd(Container::story3a7, "Images/Background.png", 0, 0);
    ViewAdd(Container::story3a7, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story3a7, "Images/btnNo!.png", 20, 380, OnStoryLevel3, 7);
    ViewAdd(Container::story3a7, "Images/btnOkSmall.png", 170, 380, OnStoryLevel3, 7);
    TextAdd(Container::story3a7, 0, 0, "\n\nEnemy: \nI will force you to State::torture your \ncaptain, hopefully "
		"causing a \nwar in the process.", font);
    //populate Container::story3a8
    ViewAdd(Container::story3a8, "Images/Background.png", 0, 0);
    ViewAdd(Container::story3a8, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story3a8, "Images/btnNo!.png", 20, 380, OnStoryLevel3, 8);
    ViewAdd(Container::story3a8, "Images/btnOkSmall.png", 170, 380, OnStoryLevel3, 8);
    TextAdd(Container::story3a8, 0, 0, "\n\nEnemy: \nI will wait for you to State::torture \nhim until you do. There's "
        "\nnothing you can do about it.", font);
    //populate Container::storyTorture
    TouchAdd(Container::storyTorture, 0, 0, 320, 568, OnTorture, 1);
    imageTorture = ViewAdd(Container::storyTorture, "Images/TortureModeOne.png", -2, -2);
    ViewAdd(Container::storyTorture, "Images/Pause.png", 270, 20, OnPause, 1);
    hpTorture = ViewAdd(Container::storyTorture, "Images/20HP.png", 20, 20);
    textTorture = TextAdd(Container::storyTorture, 70, 0, "", FontAdd("Arial", "Regular", 24, 0xDF0101));
}
void ContainerTwo() {
    //populate Container::story2a1
    ViewAdd(Container::story2a1, "Images/Background.png", 0, 0);
    ViewAdd(Container::story2a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story2a1, "Images/btnOkSmall.png", 20, 380, OnStoryLevel2, 1);
    ViewAdd(Container::story2a1, "Images/btnThanks.png", 170, 380, OnStoryLevel2, 1);
    TextAdd(Container::story2a1, 0, 0, "\n\nTeacher: \nThis test was designed to \ndetermine how well cadets \nwould "
        "respond to stressful", font);
    TextAdd(Container::story2a1, 0, 0, "\n\n\n\n\n\nsituations. You passed and \nhave been deemed fit for \nduty.", 
        font);
    //populate Container::story2a2
    ViewAdd(Container::story2a2, "Images/Background.png", 0, 0);
    ViewAdd(Container::story2a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story2a2, "Images/btnSure.png", 20, 380, OnStoryLevel2, 3);
    ViewAdd(Container::story2a2, "Images/btnNo.png", 170, 380, OnStoryLevel2, 4);
    TextAdd(Container::story2a2, 0, 0, "\n\nBecca: \nI heard you're the new soldier \nin town. Do you want to go \nout "
        "to town with me?", font);
    //populate Container::story2a3
    ViewAdd(Container::story2a3, "Images/Background.png", 0, 0);
    ViewAdd(Container::story2a3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story2a3, "Images/btnYes.png", 20, 380, OnStoryLevel2, 5);
    ViewAdd(Container::story2a3, "Images/btnNo.png", 170, 380, OnStoryLevel2, 6);
    TextAdd(Container::story2a3, 0, 0, "\n\nCaptain: \nSon, you have a bright future. \nWould you like to join me on "
        "\nmy voyages?", font);
    //populate Container::story2b4
    ViewAdd(Container::story2b4, "Images/Background.png", 0, 0);
    ViewAdd(Container::story2b4, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story2b4, "Images/btnOkSmall.png", 20, 380, OnStoryLevel2, 7);
    ViewAdd(Container::story2b4, "Images/btnSorry.png", 170, 380, OnStoryLevel2, 7);
    TextAdd(Container::story2b4, 0, 0, "\n\nCaptain: \nFederation orders, you have \nto do it.", font);
    //populate Container::story2a5
    ViewAdd(Container::story2a5, "Images/Background.png", 0, 0);
    ViewAdd(Container::story2a5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story2a5, "Images/btnOkBig.png", 20, 380, OnStoryLevel2, 8);
    TextAdd(Container::story2a5, 0, 0, "\n\nCaptain: \nPrepare your items, we are \nleaving tomorrow.", font);
    //populate Container::story2a6
    ViewAdd(Container::story2a6, "Images/Background.png", 0, 0);
    ViewAdd(Container::story2a6, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story2a6, "Images/btnEngage.png", 20, 380, OnStoryLevel2, 9);
    ViewAdd(Container::story2a6, "Images/btnAround.png", 170, 380, OnStoryLevel2, 10);
    TextAdd(Container::story2a6, 0, 0, "\n\nCaptain: \nThere's ships up ahead. \nShould we engage or go \naround?", 
        font);
    //populate Container::story2e7
    ViewAdd(Container::story2e7, "Images/Background.png", 0, 0);
    ViewAdd(Container::story2e7, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story2e7, "Images/btnOkBig.png", 20, 380, OnStoryLevel2, 11);
    TextAdd(Container::story2e7, 0, 0, "\n\nCaptain: \nHave fun shooting!", font);
    //populate Container::story2a7
    ViewAdd(Container::story2a7, "Images/Background.png", 0, 0);
    ViewAdd(Container::story2a7, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story2a7, "Images/btnOkBig.png", 20, 380, OnStoryLevel2, 11);
    TextAdd(Container::story2a7, 0, 0, "\n\nCaptain: \nThe ships noticed us and are \nattacking!", font);
}
void ContainerOne() {
    //populate Container::highscore
    ViewAdd(Container::highscore, "Images/MenuPause.png", 0, 0);
    ViewAdd(Container::highscore, "Images/btnOkBig.png", 20, 380, OnHighscore, 1);
    text1 = TextAdd(Container::highscore, 20, 0, "", font);
    text2 = TextAdd(Container::highscore, 20, 0, "", font);
    text3 = TextAdd(Container::highscore, 20, 0, "", font);
    //populate Container::pause
    ViewAdd(Container::pause, "Images/MenuPause.png", 0, 0);
    ViewAdd(Container::pause, "Images/ReturnToMenu.png", 20, 120, OnReturnToMenu, 1);
    ViewAdd(Container::pause, "Images/Resume.png", 20, 210, OnResume, 1);
    //populate Container::endless
    ViewAdd(Container::endless, "Images/Background.png", 0, 0, OnBattleTouch, 1);
    healthImage = ViewAdd(Container::endless, "Images/20HP.png", 20, 20);
    ViewAdd(Container::endless, "Images/Pause.png", 270, 20, OnPause, 1);
    //player bullets
    for (int i = 0; i < 15; i++) {
        Bullets::m1[i] = ViewAdd(Container::endless, "Images/Bullet.png", -10, -10);
        Bullets::m2[i] = ViewAdd(Container::endless, "Images/Rocket.png", -20, -20);
        Bullets::m3[i] = ViewAdd(Container::endless, "Images/Bullet.png", -10, -10);
    }
    //enemy bullets
    for (int i = 0; i < 50; i++) {
        Bullets::e1b2[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e2b2[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e3b2[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e4b2[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
    }
    for (int i = 0; i < 25; i++) {
        Bullets::e5b1[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e5b3[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e6b1[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e6b3[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e7b2[i] = ViewAdd(Container::endless, "Images/eRocket.png", 600, 600);
        Bullets::e8b1[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e8b2[i] = ViewAdd(Container::endless, "Images/eRocket.png", 600, 600);
        Bullets::e8b3[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
    }
    for (int i = 0; i < 5; i++) {
        Bullets::e9b1[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e9b2[i] = ViewAdd(Container::endless, "Images/eRocket.png", 600, 600);
        Bullets::e9b3[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e10b1[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
        Bullets::e10b2[i] = ViewAdd(Container::endless, "Images/eRocket.png", 600, 600);
        Bullets::e10b3[i] = ViewAdd(Container::endless, "Images/eBullet.png", 600, 600);
    }
    //ships
    for (int i = 0; i < 10; i++) {
        EnemyShips::e1[i] = ViewAdd(Container::endless, "Images/eShip_1.png", 600, 600);
        EnemyShips::e2[i] = ViewAdd(Container::endless, "Images/eShip_2.png", 600, 600);
        EnemyShips::e3[i] = ViewAdd(Container::endless, "Images/eShip_3.png", 600, 600);
        EnemyShips::e4[i] = ViewAdd(Container::endless, "Images/eShip_4.png", 600, 600);
    }
    for (int i = 0; i < 5; i++) {
        EnemyShips::e5[i] = ViewAdd(Container::endless, "Images/eShip_5.png", 600, 600);
        EnemyShips::e6[i] = ViewAdd(Container::endless, "Images/eShip_6.png", 600, 600);
        EnemyShips::e7[i] = ViewAdd(Container::endless, "Images/eShip_7.png", 600, 600);
        EnemyShips::e8[i] = ViewAdd(Container::endless, "Images/eShip_8.png", 600, 600);
    }
    EnemyShips::e9[0] = ViewAdd(Container::endless, "Images/eMini-Boss.png", 600, 600);
    EnemyShips::e10[0] = ViewAdd(Container::endless, "Images/eBoss.png", 600, 600);
    //populate Container::menu
    ViewAdd(Container::menu, "Images/Background.png", 0, 0);
    ViewAdd(Container::menu, "Images/btnStory.png", 20, 40, OnStoryMenuTouch, 1);
    ViewAdd(Container::menu, "Images/btnEndless.png", 20, 150, OnEndlessMenuTouch, 1);
    ViewAdd(Container::menu, "Images/btnUnlocks.png", 20, 260, OnUnlocksMenuTouch, 1);
    ViewAdd(Container::menu, "Images/btnOptions.png", 20, 370, OnOptionsMenuTouch, 1);
    //populate Container::died
    ViewAdd(Container::died, "Images/Background.png", 0, 0);
    ViewAdd(Container::died, "Images/btnOkBig.png", 20, 380, OnDied, 1);
    TextAdd(Container::died, 0, 0, "\n\nYou died without completing \nyour journey or leaving \nyourself a legacy. "
        "You left no", font);
    TextAdd(Container::died, 0, 0, "\n\n\n\n\nimprint on the world and \nnobody will ever remember \nyou.", font);
    //populate CointainerStory1a1
    ViewAdd(Container::story1a1, "Images/Background.png", 0, 0);
    ViewAdd(Container::story1a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story1a1, "Images/btnOkBig.png", 20, 380, OnStoryLevel1, 1);
    TextAdd(Container::story1a1, 0, 0, "\n\nRon: \nAlex, are you ready for the \nbig test? Remember: We \nadopted the "
        "new cycle", font);
    TextAdd(Container::story1a1, 0, 0, "\n\n\n\n\n\nsystem 93 cycles ago. If we \nstill used the old Earth \nmethod, "
        "it would currently be", font);
    TextAdd(Container::story1a1, 0, 0, "\n\n\n\n\n\n\n\n\nyear 2433.", font);
    //populate Container::story1a2
    ViewAdd(Container::story1a2, "Images/Background.png", 0, 0);
    ViewAdd(Container::story1a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story1a2, "Images/btnStudy.png", 20, 380, OnStoryLevel1, 3);
    ViewAdd(Container::story1a2, "Images/btnParty.png", 170, 380, OnStoryLevel1, 4);
    TextAdd(Container::story1a2, 0, 0, "\n\nRon: \nAlso, you can either \nstudy for the big test \ntomorrow, or go to "
        "a party", font);
    TextAdd(Container::story1a2, 0, 0, "\n\n\n\n\n\nwith the cool guys and I. Just \ntell them Ron invited you.", font);
    //populate Container::story1s3
    ViewAdd(Container::story1s3, "Images/Background.png", 0, 0);
    ViewAdd(Container::story1s3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story1s3, "Images/btnSleep.png", 20, 380, OnStoryLevel1, 5);
    TextAdd(Container::story1s3, 0, 0, "\n\nBook: \nEverybody must listen to \nhigher command at all times. \nAlso, "
        "ship pilots must never", font);
    TextAdd(Container::story1s3, 0, 0, "\n\n\n\n\n\nabandon their ship.", font);
    //populate Container::story1p3
    ViewAdd(Container::story1p3, "Images/Background.png", 0, 0);
    ViewAdd(Container::story1p3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story1p3, "Images/btnSleep.png", 20, 380, OnStoryLevel1, 5);
    TextAdd(Container::story1p3, 0, 0, "\n\nRon: \nHave a great night.", font);
    //populate Container::story1a4
    ViewAdd(Container::story1a4, "Images/Background.png", 0, 0);
    ViewAdd(Container::story1a4, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story1a4, "Images/btnRescue.png", 20, 380, OnStoryLevel1, 6);
    ViewAdd(Container::story1a4, "Images/btnEscape.png", 170, 380, OnStoryLevel1, 7);
    TextAdd(Container::story1a4, 0, 0, "\n\nTeacher: \nThe Kobayashi ship is \ntrapped behind enemy \nlines. What do "
        "you do?", font);
    //populate Container::story1r5
    ViewAdd(Container::story1r5, "Images/Background.png", 0, 0);
    ViewAdd(Container::story1r5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story1r5, "Images/btnOkBig.png", 20, 380, OnStoryLevel1, 8);
    TextAdd(Container::story1r5, 0, 0, "\n\nLieutenant: \nThey ambushed us!", font);
    //populate Container::story1e5
    ViewAdd(Container::story1e5, "Images/Background.png", 0, 0);
    ViewAdd(Container::story1e5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(Container::story1e5, "Images/btnOkBig.png", 20, 380, OnStoryLevel1, 8);
    TextAdd(Container::story1e5, 0, 0, "\n\nLieutenant: \nThey followed us and are \nattacking!", font);
}
void StartupMusic() {
    if (State::sound) {
        if (Counter::sound > 1 && Counter::sound < 7000) {
            Counter::sound = 7000;
        } else if (Counter::sound > 7000 && Counter::sound < 13000) {
            Counter::sound = 13000;
        } else if (Counter::sound > 13000 && Counter::sound < 19000) {
            Counter::sound = 19000;
        } else if (Counter::sound > 19000 && Counter::sound < 27000) {
            Counter::sound = 27000;
        } else if (Counter::sound > 27000 && Counter::sound < 34000) {
            Counter::sound = 34000;
        } else if (Counter::sound > 34000 && Counter::sound < 42000) {
            Counter::sound = 42000;
        } else if (Counter::sound > 42000 && Counter::sound < 49000) {
            Counter::sound = 49000;
        } else if (Counter::sound > 49000 && Counter::sound < 55000) {
            Counter::sound = 55000;
        } else if (Counter::sound > 55000 && Counter::sound < 61000) {
            Counter::sound = 61000;
        } else if (Counter::sound > 61000 && Counter::sound < 67000) {
            Counter::sound = 67000;
        } else if (Counter::sound > 67000 && Counter::sound < 73000) {
            Counter::sound = 73000;
        } else if (Counter::sound > 73000 && Counter::sound < 79000) {
            Counter::sound = 79000;
        } else if (Counter::sound > 79000) {
            Counter::sound = 1;
        }
        if (Counter::sound > 1 && Counter::sound < 7000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/1.mp3"));
        } else if (Counter::sound > 7000 && Counter::sound < 13000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/2.mp3"));
        } else if (Counter::sound > 13000 && Counter::sound < 19000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/3.mp3"));
        } else if (Counter::sound > 19000 && Counter::sound < 27000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/5.mp3"));
        } else if (Counter::sound > 27000 && Counter::sound < 34000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/7.mp3"));
        } else if (Counter::sound > 34000 && Counter::sound < 42000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/8.mp3"));
        } else if (Counter::sound > 42000 && Counter::sound < 49000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/9.mp3"));
        } else if (Counter::sound > 49000 && Counter::sound < 55000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/11.mp3"));
        } else if (Counter::sound > 55000 && Counter::sound < 61000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/12.mp3"));
        } else if (Counter::sound > 61000 && Counter::sound < 67000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/13.mp3"));
        } else if (Counter::sound > 67000 && Counter::sound < 73000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/14.mp3"));
        } else if (Counter::sound > 73000 && Counter::sound < 79000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/15.mp3"));
        }
    } else {
        Mp3Stop();
    }
}
void AppMain() {
    LoadGame();
    DeclareContainers();
    font = FontAdd("Arial", "Regular", 24, 0xA4A4A4);

    ScreenSwitch();
    ContainerOne();
    ContainerTwo();
    ContainerThree();
    ContainerFour();
    ContainerFive();
    ContainerSixSeven();

    //populate Container::unlocks
    ViewAdd(Container::unlocks, "Images/Background.png", 0, 0);
    ViewAdd(Container::unlocks, "Images/Pause.png", 270, 20, OnPause, 1);
    TextAdd(Container::unlocks, 10, 10, "\n\n\n\n\n Pick Your Ship By Clicking", font);
    ViewAdd(Container::unlocks, "Unlocks/UnShip_1.png", 20, 180, Unlocks, 1);
    //populate Container::options
    ViewAdd(Container::options, "Images/Background.png", 0, 0);
    ViewAdd(Container::options, "Images/Pause.png", 270, 20, OnPause, 1);
    char* musicString = (State::sound) ? ("Unlocks/MusicOn.png") : ("Unlocks/MusicOff.png");
    music = ViewAdd(Container::options, musicString, 20, 80, Options, 1);
    TextAdd(Container::options, 20, 320, "\nCreated By \nBailey Thompson", font);
    ViewAdd(Container::options, "Images/btnDelete.png", 20, 200, Options, 2);
    //populate Container::deleteCheckOne
    ViewAdd(Container::deleteCheckOne, "Images/Background.png", 0, 0);
    TextAdd(Container::deleteCheckOne, 20, 20, "Are you sure you want to \nDELETE ALL PLAYER \nDATA including xp, "
		"rank, \nhighscore, and ships?", font);
    ViewAdd(Container::deleteCheckOne, "Images/btnNoDelete.png", 20, 180, Options, 5);
    ViewAdd(Container::deleteCheckOne, "Images/btnYesDelete.png", 20, 300, Options, 3);
    //populate Container::deleteCheckTwo
    ViewAdd(Container::deleteCheckTwo, "Images/Background.png", 0, 0);
    TextAdd(Container::deleteCheckTwo, 20, 20, "Are you really sure you \nwant to DELETE \nEVERYTHING?", font);
    ViewAdd(Container::deleteCheckTwo, "Images/btnNoDelete.png", 20, 300, Options, 5);
    ViewAdd(Container::deleteCheckTwo, "Images/btnYesDelete.png", 20, 180, Options, 4);

    ShipType();
    StartupMusic();
}

void IntGameToFile(int num, char* buffer) {
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
void BoolGameToFile(bool num, char* buffer) {
    buffer[0] = (num) ? ('t') : ('f');
}
void AppExit() {
    Mp3Stop();
    char fileBuffer[5];
    //fileSound
    int fileSound = FileOpen("Sound.txt");
    BoolGameToFile(State::sound, fileBuffer);
    FileWrite(fileSound, fileBuffer, 1);
    FileClose(fileSound);
    //fileXp
    int fileXp = FileOpen("Xp.txt");
    IntGameToFile(xp, fileBuffer);
    FileWrite(fileXp, fileBuffer, 5);
    FileClose(fileXp);
    //fileShip
    int fileShip = FileOpen("Ship.txt");
    IntGameToFile(ship, fileBuffer);
    FileWrite(fileShip, fileBuffer, 5);
    FileClose(fileShip);
    //fileHighscore
    int fileHighscore = FileOpen("Highscore.txt");
    IntGameToFile(highscore, fileBuffer);
    FileWrite(fileHighscore, fileBuffer, 5);
    FileClose(fileHighscore);
    //fileCounter
    int fileCounter = FileOpen("Counter.txt");
    IntGameToFile(Counter::sound, fileBuffer);
    FileWrite(fileCounter, fileBuffer, 5);
    FileClose(fileCounter);
}

bool IsNotActive() {
    return CurrentScreen != ScreenEndless && CurrentScreen != ScreenStoryBattle1
               && CurrentScreen != ScreenStoryBattle2 && CurrentScreen != ScreenStoryBattle4
               && CurrentScreen != ScreenStoryBattle5 && CurrentScreen != ScreenStoryBattle6
               && CurrentScreen != ScreenDied && CurrentScreen != ScreenHighscore;
}
void SoundSwitch() {
    if (State::sound) {
        if (Counter::sound == 1) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/1.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 7000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/2.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 13000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/3.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 19000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/5.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 27000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/7.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 34000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/8.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 42000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/9.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 49000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/11.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 55000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/12.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 61000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/13.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 67000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/14.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound == 73000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/15.mp3"));
            } else {
                Counter::sound--;
            }
        } else if (Counter::sound >= 79000) {
            Counter::sound = 0;
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
void BulletTime() {
    int x, y, x2, y2, x3, y3;
    bool used = false;
    for (int i = 1; i <= 15; i++) {
        if (Counter::bulletTime == i * TIME) {
            used = true;
            if (ship == 8) {
                ViewSetxy(Bullets::m1[i - 1], mX + bulletXOffset, mY + bulletYOffset);
                ViewSetxy(Bullets::m2[i - 1], mX + bulletXOffset2, mY + bulletYOffset2);
                ViewSetxy(Bullets::m3[i - 1], mX + bulletXOffset3, mY + bulletYOffset3);
            } else if (ship == 7) {
                ViewSetxy(Bullets::m2[i - 1], mX + bulletXOffset2, mY + bulletYOffset2);
            } else if (ship == 6 || ship == 5) {
                ViewSetxy(Bullets::m1[i - 1], mX + bulletXOffset, mY + bulletYOffset);
                ViewSetxy(Bullets::m3[i - 1], mX + bulletXOffset3, mY + bulletYOffset3);
            } else {
                ViewSetxy(Bullets::m1[i - 1], mX + bulletXOffset, mY + bulletYOffset);
            }
        }
    }
    if (Counter::bulletTime >= 15 * TIME) {
        Counter::bulletTime = 0;
    }
    if (!used) {
        for (int i = 0; i < 15; i++) {
            x = ViewGetx(Bullets::m1[i]);
            y = ViewGety(Bullets::m1[i]);
            x2 = ViewGetx(Bullets::m2[i]);
            y2 = ViewGety(Bullets::m2[i]);
            x3 = ViewGetx(Bullets::m3[i]);
            y3 = ViewGety(Bullets::m3[i]);
            if (y > -20 || y2 > -20 || y3 > -20) {
                ViewSetxy(Bullets::m1[i], x, y - SPEED);
                ViewSetxy(Bullets::m2[i], x2, y2 - SPEED);
                ViewSetxy(Bullets::m3[i], x3, y3 - SPEED);
            }
            for (int j = 0; j < 10; j++) {
                //ship 1
                if (y > EnemyShips::e1y[j] && y < EnemyShips::e1y[j] + 94 && x > EnemyShips::e1x[j] + 9 
					&& x < EnemyShips::e1x[j] + 76) {
                    ViewSetxy(Bullets::m1[i], -10, -10);
                    EnemyShips::e1hp[j] -= 1;
                }
                if (y2 > EnemyShips::e1y[j] && y2 < EnemyShips::e1y[j] + 94 && x2 > EnemyShips::e1x[j] + 9 
					&& x2 < EnemyShips::e1x[j] + 76) {
                    ViewSetxy(Bullets::m2[i], -20, -20);
                    EnemyShips::e1hp[j] -= 3;
                }
                if (y3 > EnemyShips::e1y[j] && y3 < EnemyShips::e1y[j] + 94 && x3 > EnemyShips::e1x[j] + 9 
					&& x3 < EnemyShips::e1x[j] + 76) {
                    ViewSetxy(Bullets::m3[i], -10, -10);
                    EnemyShips::e1hp[j] -= 1;
                }
                //ship 2
                if (y > EnemyShips::e2y[j] && y < EnemyShips::e2y[j] + 94 && x > EnemyShips::e2x[j] + 15 
					&& x < EnemyShips::e2x[j] + 69) {
                    ViewSetxy(Bullets::m1[i], -10, -10);
                    EnemyShips::e2hp[j] -= 1;
                }
                if (y2 > EnemyShips::e2y[j] && y2 < EnemyShips::e2y[j] + 94 && x2 > EnemyShips::e2x[j] + 15 
					&& x2 < EnemyShips::e2x[j] + 69) {
                    ViewSetxy(Bullets::m2[i], -20, -20);
                    EnemyShips::e2hp[j] -= 3;
                }
                if (y3 > EnemyShips::e2y[j] && y3 < EnemyShips::e2y[j] + 94 && x3 > EnemyShips::e2x[j] + 15 
					&& x3 < EnemyShips::e2x[j] + 69) {
                    ViewSetxy(Bullets::m3[i], -10, -10);
                    EnemyShips::e2hp[j] -= 1;
                }
                //ship 3
                if (y > EnemyShips::e3y[j] && y < EnemyShips::e3y[j] + 94 && x > EnemyShips::e3x[j] + 18 
					&& x < EnemyShips::e3x[j] + 66) {
                    ViewSetxy(Bullets::m1[i], -10, -10);
                    EnemyShips::e3hp[j] -= 1;
                }
                if (y2 > EnemyShips::e3y[j] && y2 < EnemyShips::e3y[j] + 94 && x2 > EnemyShips::e3x[j] + 18 
					&& x2 < EnemyShips::e3x[j] + 66) {
                    ViewSetxy(Bullets::m2[i], -20, -20);
                    EnemyShips::e3hp[j] -= 3;
                }
                if (y3 > EnemyShips::e3y[j] && y3 < EnemyShips::e3y[j] + 94 && x3 > EnemyShips::e3x[j] + 18 
					&& x3 < EnemyShips::e3x[j] + 66) {
                    ViewSetxy(Bullets::m3[i], -10, -10);
                    EnemyShips::e3hp[j] -= 1;
                }
                //ship 4
                if (y > EnemyShips::e4y[j] && y < EnemyShips::e4y[j] + 94 && x > EnemyShips::e4x[j] - 3 
					&& x < EnemyShips::e4x[j] + 87) {
                    ViewSetxy(Bullets::m1[i], -10, -10);
                    EnemyShips::e4hp[j] -= 1;
                }
                if (y2 > EnemyShips::e4y[j] && y2 < EnemyShips::e4y[j] + 94 && x2 > EnemyShips::e4x[j] - 3 
					&& x2 < EnemyShips::e4x[j] + 87) {
                    ViewSetxy(Bullets::m2[i], -20, -20);
                    EnemyShips::e4hp[j] -= 3;
                }
                if (y3 > EnemyShips::e4y[j] && y3 < EnemyShips::e4y[j] + 94 && x3 > EnemyShips::e4x[j] - 3 
					&& x3 < EnemyShips::e4x[j] + 87) {
                    ViewSetxy(Bullets::m3[i], -10, -10);
                    EnemyShips::e4hp[j] -= 1;
                }
            }
            for (int j = 0; j < 5; j++) {
                //ship 5
                if (y > EnemyShips::e5y[j] && y < EnemyShips::e5y[j] + 94 && x > EnemyShips::e5x[j] + 13 
					&& x < EnemyShips::e5x[j] + 71) {
                    ViewSetxy(Bullets::m1[i], -10, -10);
                    EnemyShips::e5hp[j] -= 1;
                }
                if (y2 > EnemyShips::e5y[j] && y2 < EnemyShips::e5y[j] + 94 && x2 > EnemyShips::e5x[j] + 13 
					&& x2 < EnemyShips::e5x[j] + 71) {
                    ViewSetxy(Bullets::m2[i], -20, -20);
                    EnemyShips::e5hp[j] -= 3;
                }
                if (y3 > EnemyShips::e5y[j] && y3 < EnemyShips::e5y[j] + 94 && x3 > EnemyShips::e5x[j] + 13 
					&& x3 < EnemyShips::e5x[j] + 71) {
                    ViewSetxy(Bullets::m3[i], -10, -10);
                    EnemyShips::e5hp[j] -= 1;
                }
                //ship 6
                if (y > EnemyShips::e6y[j] && y < EnemyShips::e6y[j] + 94 && x > EnemyShips::e6x[j] + 3 
					&& x < EnemyShips::e6x[j] + 81) {
                    ViewSetxy(Bullets::m1[i], -10, -10);
                    EnemyShips::e6hp[j] -= 1;
                }
                if (y2 > EnemyShips::e2y[j] && y2 < EnemyShips::e2y[j] + 94 && x2 > EnemyShips::e2x[j] + 3 
					&& x2 < EnemyShips::e2x[j] + 81) {
                    ViewSetxy(Bullets::m2[i], -20, -20);
                    EnemyShips::e2hp[j] -= 3;
                }
                if (y3 > EnemyShips::e6y[j] && y3 < EnemyShips::e6y[j] + 94 && x3 > EnemyShips::e6x[j] + 3 
					&& x3 < EnemyShips::e6x[j] + 81) {
                    ViewSetxy(Bullets::m3[i], -10, -10);
                    EnemyShips::e6hp[j] -= 1;
                }
                //ship 7
                if (y > EnemyShips::e7y[j] && y < EnemyShips::e7y[j] + 94 && x > EnemyShips::e7x[j] - 2 
					&& x < EnemyShips::e7x[j] + 86) {
                    ViewSetxy(Bullets::m1[i], -10, -10);
                    EnemyShips::e7hp[j] -= 1;
                }
                if (y2 > EnemyShips::e7y[j] && y2 < EnemyShips::e7y[j] + 94 && x2 > EnemyShips::e7x[j] - 2 
					&& x2 < EnemyShips::e7x[j] + 86) {
                    ViewSetxy(Bullets::m2[i], -20, -20);
                    EnemyShips::e7hp[j] -= 3;
                }
                if (y3 > EnemyShips::e7y[j] && y3 < EnemyShips::e7y[j] + 94 && x3 > EnemyShips::e7x[j] - 2 
					&& x3 < EnemyShips::e7x[j] + 86) {
                    ViewSetxy(Bullets::m3[i], -10, -10);
                    EnemyShips::e7hp[j] -= 1;
                }
                //ship 8
                if (y > EnemyShips::e8y[j] && y < EnemyShips::e8y[j] + 94 && x > EnemyShips::e8x[j] - 3 
					&& x < EnemyShips::e8x[j] + 86) {
                    ViewSetxy(Bullets::m1[i], -10, -10);
                    EnemyShips::e8hp[j] -= 1;
                }
                if (y2 > EnemyShips::e8y[j] && y2 < EnemyShips::e8y[j] + 94 && x2 > EnemyShips::e8x[j] - 3 
					&& x2 < EnemyShips::e8x[j] + 86) {
                    ViewSetxy(Bullets::m2[i], -20, -20);
                    EnemyShips::e8hp[j] -= 3;
                }
                if (y3 > EnemyShips::e8y[j] && y3 < EnemyShips::e8y[j] + 94 && x3 > EnemyShips::e8x[j] - 3 
					&& x3 < EnemyShips::e8x[j] + 86) {
                    ViewSetxy(Bullets::m3[i], -10, -10);
                    EnemyShips::e8hp[j] -= 1;
                }
            }
            //ship 9
            if (y > EnemyShips::e9y[0] && y < EnemyShips::e9y[0] + 94 && x > EnemyShips::e9x[0] 
				&& x < EnemyShips::e9x[0] + 240) {
                ViewSetxy(Bullets::m1[i], -10, -10);
                EnemyShips::e9hp[0] -= 1;
            }
            if (y2 > EnemyShips::e9y[0] && y2 < EnemyShips::e9y[0] + 94 && x2 > EnemyShips::e9x[0] 
				&& x2 < EnemyShips::e9x[0] + 240) {
                ViewSetxy(Bullets::m2[i], -20, -20);
                EnemyShips::e9hp[0] -= 3;
            }
            if (y3 > EnemyShips::e9y[0] && y3 < EnemyShips::e9y[0] + 94 && x3 > EnemyShips::e9x[0] 
				&& x3 < EnemyShips::e9x[0] + 240) {
                ViewSetxy(Bullets::m3[i], -10, -10);
                EnemyShips::e9hp[0] -= 1;
            }
            //ship 10
            if (y > EnemyShips::e10y[0] && y < EnemyShips::e10y[0] + 94 && x > EnemyShips::e10x[0] 
				&& x < EnemyShips::e10x[0] + 240) {
                ViewSetxy(Bullets::m1[i], -10, -10);
                EnemyShips::e10hp[0] -= 1;
            }
            if (y2 > EnemyShips::e10y[0] && y2 < EnemyShips::e10y[0] + 94 && x2 > EnemyShips::e10x[0] 
				&& x2 < EnemyShips::e10x[0] + 240) {
                ViewSetxy(Bullets::m2[i], -20, -20);
                EnemyShips::e10hp[0] -= 3;
            }
            if (y3 > EnemyShips::e10y[0] && y3 < EnemyShips::e10y[0] + 94 && x3 > EnemyShips::e10x[0] 
				&& x3 < EnemyShips::e10x[0] + 240) {
                ViewSetxy(Bullets::m3[i], -10, -10);
                EnemyShips::e10hp[0] -= 1;
            }
        }
    }
}
void TortureHealth() {
    int ImageTorturing, number = 100;
    if (Counter::hpTorture > number * 20 && State::torture) {
        Counter::hpTorture = number * 20;
    } else if (Counter::hpTorture > number * 40 && !State::torture) {
        CurrentScreen = ScreenDied;
        ScreenSwitch();
    } else if (Counter::hpTorture <= number * 20 && Counter::hpTorture > number * 19) {
        ImageTorturing = ImageAdd("Images/20HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= number * 19 && Counter::hpTorture > number * 18) {
        ImageTorturing = ImageAdd("Images/19HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nStop This Madness!");
    } else if (Counter::hpTorture <= number * 18 && Counter::hpTorture > number * 17) {
        ImageTorturing = ImageAdd("Images/18HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= number * 17 && Counter::hpTorture > number * 16) {
        ImageTorturing = ImageAdd("Images/17HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nDon't Do It!");
    } else if (Counter::hpTorture <= number * 16 && Counter::hpTorture > number * 15) {
        ImageTorturing = ImageAdd("Images/16HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= number * 15 && Counter::hpTorture > number * 14) {
        ImageTorturing = ImageAdd("Images/15HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nI Beg Of You!");
    } else if (Counter::hpTorture <= number * 14 && Counter::hpTorture > number * 13) {
        ImageTorturing = ImageAdd("Images/14HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= number * 13 && Counter::hpTorture > number * 12) {
        ImageTorturing = ImageAdd("Images/13HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nPlease Don't!");
    } else if (Counter::hpTorture <= number * 12 && Counter::hpTorture > number * 11) {
        ImageTorturing = ImageAdd("Images/12HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= number * 11 && Counter::hpTorture > number * 10) {
        ImageTorturing = ImageAdd("Images/11HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nI Order You To Stop!");
    } else if (Counter::hpTorture <= number * 10 && Counter::hpTorture > number * 9) {
        ImageTorturing = ImageAdd("Images/10HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= number * 9 && Counter::hpTorture > number * 8) {
        ImageTorturing = ImageAdd("Images/9HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nI Have A Family!");
    } else if (Counter::hpTorture <= number * 8 && Counter::hpTorture > number * 7) {
        ImageTorturing = ImageAdd("Images/8HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= number * 7 && Counter::hpTorture > number * 6) {
        ImageTorturing = ImageAdd("Images/7HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nDon't Do This!");
    } else if (Counter::hpTorture <= number * 6 && Counter::hpTorture > number * 5) {
        ImageTorturing = ImageAdd("Images/6HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= number * 5 && Counter::hpTorture > number * 4) {
        ImageTorturing = ImageAdd("Images/5HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nWhy Are You \nDoing This!");
    } else if (Counter::hpTorture <= number * 4 && Counter::hpTorture > number * 3) {
        ImageTorturing = ImageAdd("Images/4HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= number * 3 && Counter::hpTorture > number * 2) {
        ImageTorturing = ImageAdd("Images/3HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nYou Will Burn!");
    } else if (Counter::hpTorture <= number * 2 && Counter::hpTorture > number * 1) {
        ImageTorturing = ImageAdd("Images/2HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= number * 1 && Counter::hpTorture > 0) {
        ImageTorturing = ImageAdd("Images/1HP.png");
        ViewSetImage(hpTorture, ImageTorturing);
    } else if (Counter::hpTorture <= 0) {
        State::pause = false;
        CurrentScreen = ScreenStory4a1;
        ScreenSwitch();
    }
}
char* concatHealth(int num) {
    assert(num < 100);
    assert(num >= 0);
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
int round(double num) {
    assert(num >= 0);
    const double frac = num - (int) num;
    assert(frac < 1);
    assert(frac >= 0);
    int ret;
    if (frac > 0.5) {
        ret = (int) (num + 0.5);
    } else if (frac < 0.5) {
        ret = (int) num;
    } else if (frac == 0.5) {
        if ((int) (num + 0.5) % 2 == 0) {
            ret = (int) (num + 0.5);
        } else {
            ret = (int) (num - 0.5);
        }
    }
    return ret;
}
void HealthBar() {
    if (health < 0) {
        health = 0;
    }
    int Image;
    if (State::healthUpdate) {
        const int shipMaxHealth = 18 + 2 * ship;
        const int fracHealth = round(20 * health / shipMaxHealth);
        Image = ImageAdd(concatHealth(fracHealth));
        ViewSetImage(healthImage, Image);
        assert(health >= 0);
        if (health == 0) {
            if (CurrentScreen == ScreenEndless) {
                CurrentScreen = ScreenHighscore;
                DoUpdateHighscore();
            } else if (CurrentScreen == ScreenStoryBattle1) {
                CurrentScreen = ScreenStory2a1;
                Reset();
            } else if (CurrentScreen == ScreenStoryBattle6) {
                CurrentScreen = ScreenStory7l1;
                Reset();
            } else {
                CurrentScreen = ScreenDied;
                Reset();
            }
            ScreenSwitch();
        }
        State::healthUpdate = false;
        Counter::healthRegen = 0;
    }
}
void SetOne() {
    if (Counter::shipMove == 1 * SPAWN_TIME) {
        EnemyShips::e1hp[0] = level + 2;
        ViewSetxy(EnemyShips::e1[0], 113, -94);
    } else if (Counter::shipMove == 2 * SPAWN_TIME) {
        EnemyShips::e1hp[1] = level + 2;
        EnemyShips::e2hp[0] = level + 2;
        ViewSetxy(EnemyShips::e1[1], 33, -94);
        ViewSetxy(EnemyShips::e2[0], 193, -94);
    } else if (Counter::shipMove == 3 * SPAWN_TIME) {
        EnemyShips::e2hp[1] = level + 2;
        ViewSetxy(EnemyShips::e2[1], 113, -94);
    } else if (Counter::shipMove == 4 * SPAWN_TIME) {
        EnemyShips::e2hp[2] = level + 2;
        EnemyShips::e1hp[2] = level + 2;
        ViewSetxy(EnemyShips::e2[2], 33, -94);
        ViewSetxy(EnemyShips::e1[2], 193, -94);
    } else if (Counter::shipMove == 5 * SPAWN_TIME) {
        EnemyShips::e1hp[3] = level + 2;
        EnemyShips::e3hp[0] = level + 2;
        EnemyShips::e2hp[3] = level + 2;
        ViewSetxy(EnemyShips::e1[3], 0, -94);
        ViewSetxy(EnemyShips::e3[0], 113, -94);
        ViewSetxy(EnemyShips::e2[3], 226, -94);
    } else if (Counter::shipMove == 6 * SPAWN_TIME) {
        EnemyShips::e3hp[1] = level + 2;
        EnemyShips::e2hp[4] = level + 2;
        EnemyShips::e3hp[2] = level + 2;
        ViewSetxy(EnemyShips::e3[1], 0, -94);
        ViewSetxy(EnemyShips::e2[4], 113, -94);
        ViewSetxy(EnemyShips::e3[2], 226, -94);
    } else if (Counter::shipMove == 7 * SPAWN_TIME) {
        EnemyShips::e1hp[4] = level + 2;
        EnemyShips::e1hp[5] = level + 2;
        EnemyShips::e2hp[5] = level + 2;
        ViewSetxy(EnemyShips::e1[4], 0, -94);
        ViewSetxy(EnemyShips::e1[5], 113, -94);
        ViewSetxy(EnemyShips::e2[5], 226, -94);
    } else if (Counter::shipMove == 8 * SPAWN_TIME) {
        EnemyShips::e3hp[3] = level + 2;
        EnemyShips::e1hp[6] = level + 2;
        EnemyShips::e1hp[7] = level + 2;
        ViewSetxy(EnemyShips::e3[3], 0, -94);
        ViewSetxy(EnemyShips::e1[6], 113, -94);
        ViewSetxy(EnemyShips::e1[7], 226, -94);
    } else if (Counter::shipMove == 9 * SPAWN_TIME) {
        EnemyShips::e2hp[6] = level + 2;
        EnemyShips::e3hp[4] = level + 2;
        ViewSetxy(EnemyShips::e2[6], 33, -94);
        ViewSetxy(EnemyShips::e3[4], 193, -94);
    } else if (Counter::shipMove == 10 * SPAWN_TIME) {
        EnemyShips::e4hp[0] = level + 2;
        ViewSetxy(EnemyShips::e4[0], 113, -94);
    } else if (Counter::shipMove == 11 * SPAWN_TIME) {
        EnemyShips::e3hp[5] = level + 2;
        EnemyShips::e4hp[1] = level + 2;
        ViewSetxy(EnemyShips::e3[5], 33, -94);
        ViewSetxy(EnemyShips::e4[1], 193, -94);
    } else if (Counter::shipMove == 12 * SPAWN_TIME) {
        EnemyShips::e1hp[8] = level + 2;
        EnemyShips::e2hp[7] = level + 2;
        EnemyShips::e1hp[9] = level + 2;
        ViewSetxy(EnemyShips::e1[8], 0, -94);
        ViewSetxy(EnemyShips::e2[7], 113, -94);
        ViewSetxy(EnemyShips::e1[9], 226, -94);
    } else if (Counter::shipMove == 13 * SPAWN_TIME) {
        EnemyShips::e4hp[2] = level + 2;
        EnemyShips::e1hp[0] = level + 2;
        EnemyShips::e3hp[6] = level + 2;
        ViewSetxy(EnemyShips::e4[2], 0, -94);
        ViewSetxy(EnemyShips::e1[0], 113, -94);
        ViewSetxy(EnemyShips::e3[6], 226, -94);
    } else if (Counter::shipMove == 14 * SPAWN_TIME) {
        EnemyShips::e2hp[8] = level + 2;
        EnemyShips::e4hp[3] = level + 2;
        EnemyShips::e3hp[7] = level + 2;
        ViewSetxy(EnemyShips::e2[8], 0, -94);
        ViewSetxy(EnemyShips::e4[3], 113, -94);
        ViewSetxy(EnemyShips::e3[7], 226, -94);
    } else if (Counter::shipMove == 15 * SPAWN_TIME) {
        EnemyShips::e4hp[4] = level + 2;
        EnemyShips::e4hp[5] = level + 2;
        ViewSetxy(EnemyShips::e4[4], 33, -94);
        ViewSetxy(EnemyShips::e4[5], 193, -94);
    } else if (Counter::shipMove == 16 * SPAWN_TIME) {
        EnemyShips::e2hp[9] = level + 2;
        EnemyShips::e2hp[0] = level + 2;
        EnemyShips::e3hp[8] = level + 2;
        ViewSetxy(EnemyShips::e2[9], 0, -94);
        ViewSetxy(EnemyShips::e2[0], 113, -94);
        ViewSetxy(EnemyShips::e3[8], 226, -94);
    } else if (Counter::shipMove == 17 * SPAWN_TIME) {
        EnemyShips::e3hp[9] = level + 2;
        EnemyShips::e1hp[2] = level + 2;
        EnemyShips::e2hp[1] = level + 2;
        ViewSetxy(EnemyShips::e3[9], 0, -94);
        ViewSetxy(EnemyShips::e1[2], 113, -94);
        ViewSetxy(EnemyShips::e2[1], 226, -94);
    } else if (Counter::shipMove == 18 * SPAWN_TIME) {
        EnemyShips::e4hp[6] = level + 2;
        EnemyShips::e2hp[2] = level + 2;
        ViewSetxy(EnemyShips::e4[6], 33, -94);
        ViewSetxy(EnemyShips::e2[2], 193, -94);
    } else if (Counter::shipMove == 19 * SPAWN_TIME) {
        EnemyShips::e5hp[0] = level + 2;
        ViewSetxy(EnemyShips::e5[0], 113, -94);
    } else if (Counter::shipMove == 20 * SPAWN_TIME) {
        EnemyShips::e2hp[3] = level + 2;
        EnemyShips::e4hp[7] = level + 2;
        ViewSetxy(EnemyShips::e2[3], 33, -94);
        ViewSetxy(EnemyShips::e4[7], 193, -94);
    } else if (Counter::shipMove == 21 * SPAWN_TIME) {
        EnemyShips::e1hp[1] = level + 2;
        EnemyShips::e5hp[1] = level + 2;
        EnemyShips::e1hp[2] = level + 2;
        ViewSetxy(EnemyShips::e1[1], 0, -94);
        ViewSetxy(EnemyShips::e5[1], 113, -94);
        ViewSetxy(EnemyShips::e1[2], 226, -94);
    } else if (Counter::shipMove == 22 * SPAWN_TIME) {
        EnemyShips::e4hp[8] = level + 2;
        EnemyShips::e2hp[4] = level + 2;
        EnemyShips::e4hp[9] = level + 2;
        ViewSetxy(EnemyShips::e4[8], 0, -94);
        ViewSetxy(EnemyShips::e2[4], 113, -94);
        ViewSetxy(EnemyShips::e4[9], 226, -94);
    } else if (Counter::shipMove == 23 * SPAWN_TIME) {
        EnemyShips::e5hp[2] = level + 2;
        EnemyShips::e5hp[3] = level + 2;
        ViewSetxy(EnemyShips::e5[2], 33, -94);
        ViewSetxy(EnemyShips::e5[3], 193, -94);
    } else if (Counter::shipMove == 24 * SPAWN_TIME) {
        EnemyShips::e4hp[0] = level + 2;
        EnemyShips::e5hp[4] = level + 2;
        EnemyShips::e4hp[1] = level + 2;
        ViewSetxy(EnemyShips::e4[0], 0, -94);
        ViewSetxy(EnemyShips::e5[4], 113, -94);
        ViewSetxy(EnemyShips::e4[1], 226, -94);
    } else if (Counter::shipMove == 25 * SPAWN_TIME) {
        EnemyShips::e5hp[0] = level + 2;
        EnemyShips::e1hp[3] = level + 2;
        EnemyShips::e3hp[0] = level + 2;
        ViewSetxy(EnemyShips::e5[0], 0, -94);
        ViewSetxy(EnemyShips::e1[3], 113, -94);
        ViewSetxy(EnemyShips::e3[0], 226, -94);
    } else if (Counter::shipMove == 26 * SPAWN_TIME) {
        EnemyShips::e5hp[1] = level + 2;
        EnemyShips::e5hp[2] = level + 2;
        ViewSetxy(EnemyShips::e5[1], 33, -94);
        ViewSetxy(EnemyShips::e5[2], 193, -94);
    } else if (Counter::shipMove == 27 * SPAWN_TIME) {
        EnemyShips::e1hp[4] = level + 2;
        EnemyShips::e3hp[1] = level + 2;
        EnemyShips::e1hp[1] = level + 2;
        ViewSetxy(EnemyShips::e1[4], 0, -94);
        ViewSetxy(EnemyShips::e3[1], 113, -94);
        ViewSetxy(EnemyShips::e1[1], 226, -94);
    } else if (Counter::shipMove == 28 * SPAWN_TIME) {
        EnemyShips::e4hp[2] = level + 2;
        EnemyShips::e5hp[3] = level + 2;
        EnemyShips::e2hp[5] = level + 2;
        ViewSetxy(EnemyShips::e4[2], 0, -94);
        ViewSetxy(EnemyShips::e5[3], 113, -94);
        ViewSetxy(EnemyShips::e2[5], 226, -94);
    } else if (Counter::shipMove == 29 * SPAWN_TIME) {
        EnemyShips::e1hp[2] = level + 2;
        EnemyShips::e1hp[3] = level + 2;
        ViewSetxy(EnemyShips::e1[2], 33, -94);
        ViewSetxy(EnemyShips::e1[3], 193, -94);
    }
    if (Counter::shipMove == 30 * SPAWN_TIME) {
        if (CurrentScreen != ScreenStoryBattle1) {
            EnemyShips::e9hp[0] = level + 24;
            ViewSetxy(EnemyShips::e9[0], 89, -240);
        }
    } else if (Counter::shipMove == 31 * SPAWN_TIME && CurrentScreen == ScreenStoryBattle1) {
        CurrentScreen = ScreenStory2a1;
        ScreenSwitch();
    }
}
void SetTwo() {
    if (Counter::shipMove == 1 * SPAWN_TIME) {
        EnemyShips::e1hp[0] = level + 2;
        EnemyShips::e2hp[0] = level + 2;
        ViewSetxy(EnemyShips::e1[0], 33, -94);
        ViewSetxy(EnemyShips::e2[0], 193, -94);
    } else if (Counter::shipMove == 2 * SPAWN_TIME) {
        EnemyShips::e4hp[0] = level + 2;
        EnemyShips::e3hp[0] = level + 2;
        ViewSetxy(EnemyShips::e4[0], 33, -94);
        ViewSetxy(EnemyShips::e3[0], 193, -94);
    } else if (Counter::shipMove == 3 * SPAWN_TIME) {
        EnemyShips::e5hp[0] = level + 2;
        ViewSetxy(EnemyShips::e5[0], 113, -94);
    } else if (Counter::shipMove == 4 * SPAWN_TIME) {
        EnemyShips::e3hp[1] = level + 2;
        EnemyShips::e2hp[1] = level + 2;
        ViewSetxy(EnemyShips::e3[1], 33, -94);
        ViewSetxy(EnemyShips::e2[1], 193, -94);
    } else if (Counter::shipMove == 5 * SPAWN_TIME) {
        EnemyShips::e3hp[2] = level + 2;
        EnemyShips::e4hp[1] = level + 2;
        EnemyShips::e3hp[3] = level + 2;
        ViewSetxy(EnemyShips::e3[2], 0, -94);
        ViewSetxy(EnemyShips::e4[1], 113, -94);
        ViewSetxy(EnemyShips::e3[3], 226, -94);
    } else if (Counter::shipMove == 6 * SPAWN_TIME) {
        EnemyShips::e1hp[1] = level + 2;
        EnemyShips::e2hp[2] = level + 2;
        EnemyShips::e2hp[3] = level + 2;
        ViewSetxy(EnemyShips::e1[1], 0, -94);
        ViewSetxy(EnemyShips::e2[2], 113, -94);
        ViewSetxy(EnemyShips::e2[3], 226, -94);
    } else if (Counter::shipMove == 7 * SPAWN_TIME) {
        EnemyShips::e4hp[2] = level + 2;
        EnemyShips::e2hp[4] = level + 2;
        EnemyShips::e3hp[4] = level + 2;
        ViewSetxy(EnemyShips::e4[2], 0, -94);
        ViewSetxy(EnemyShips::e2[4], 113, -94);
        ViewSetxy(EnemyShips::e3[4], 226, -94);
    } else if (Counter::shipMove == 8 * SPAWN_TIME) {
        EnemyShips::e2hp[5] = level + 2;
        EnemyShips::e1hp[2] = level + 2;
        EnemyShips::e1hp[3] = level + 2;
        ViewSetxy(EnemyShips::e2[5], 0, -94);
        ViewSetxy(EnemyShips::e1[2], 113, -94);
        ViewSetxy(EnemyShips::e1[3], 226, -94);
    } else if (Counter::shipMove == 9 * SPAWN_TIME) {
        EnemyShips::e4hp[3] = level + 2;
        EnemyShips::e3hp[5] = level + 2;
        ViewSetxy(EnemyShips::e4[3], 33, -94);
        ViewSetxy(EnemyShips::e3[5], 193, -94);
    } else if (Counter::shipMove == 10 * SPAWN_TIME) {
        EnemyShips::e5hp[1] = level + 2;
        EnemyShips::e5hp[2] = level + 2;
        ViewSetxy(EnemyShips::e5[1], 33, -94);
        ViewSetxy(EnemyShips::e5[2], 193, -94);
    } else if (Counter::shipMove == 11 * SPAWN_TIME) {
        EnemyShips::e4hp[4] = level + 2;
        ViewSetxy(EnemyShips::e4[4], 113, -94);
    } else if (Counter::shipMove == 12 * SPAWN_TIME) {
        EnemyShips::e5hp[3] = level + 2;
        EnemyShips::e2hp[6] = level + 2;
        ViewSetxy(EnemyShips::e5[3], 33, -94);
        ViewSetxy(EnemyShips::e2[6], 193, -94);
    } else if (Counter::shipMove == 13 * SPAWN_TIME) {
        EnemyShips::e3hp[6] = level + 2;
        EnemyShips::e2hp[7] = level + 2;
        EnemyShips::e2hp[8] = level + 2;
        ViewSetxy(EnemyShips::e3[6], 0, -94);
        ViewSetxy(EnemyShips::e2[7], 113, -94);
        ViewSetxy(EnemyShips::e2[8], 226, -94);
    } else if (Counter::shipMove == 14 * SPAWN_TIME) {
        EnemyShips::e2hp[9] = level + 2;
        EnemyShips::e5hp[4] = level + 2;
        EnemyShips::e1hp[4] = level + 2;
        ViewSetxy(EnemyShips::e2[9], 0, -94);
        ViewSetxy(EnemyShips::e5[4], 113, -94);
        ViewSetxy(EnemyShips::e1[4], 226, -94);
    } else if (Counter::shipMove == 15 * SPAWN_TIME) {
        EnemyShips::e5hp[0] = level + 2;
        EnemyShips::e1hp[5] = level + 2;
        EnemyShips::e4hp[5] = level + 2;
        ViewSetxy(EnemyShips::e5[0], 0, -94);
        ViewSetxy(EnemyShips::e1[5], 113, -94);
        ViewSetxy(EnemyShips::e4[5], 226, -94);
    } else if (Counter::shipMove == 16 * SPAWN_TIME) {
        EnemyShips::e1hp[6] = level + 2;
        EnemyShips::e3hp[7] = level + 2;
        ViewSetxy(EnemyShips::e1[6], 33, -94);
        ViewSetxy(EnemyShips::e3[7], 193, -94);
    } else if (Counter::shipMove == 17 * SPAWN_TIME) {
        EnemyShips::e4hp[6] = level + 2;
        EnemyShips::e5hp[1] = level + 2;
        ViewSetxy(EnemyShips::e4[6], 33, -94);
        ViewSetxy(EnemyShips::e5[1], 193, -94);
    } else if (Counter::shipMove == 18 * SPAWN_TIME) {
        EnemyShips::e1hp[7] = level + 2;
        EnemyShips::e5hp[2] = level + 2;
        EnemyShips::e1hp[8] = level + 2;
        ViewSetxy(EnemyShips::e1[7], 0, -94);
        ViewSetxy(EnemyShips::e5[2], 113, -94);
        ViewSetxy(EnemyShips::e1[8], 226, -94);
    } else if (Counter::shipMove == 19 * SPAWN_TIME) {
        EnemyShips::e1hp[9] = level + 2;
        EnemyShips::e3hp[8] = level + 2;
        ViewSetxy(EnemyShips::e1[9], 33, -94);
        ViewSetxy(EnemyShips::e3[8], 193, -94);
    } else if (Counter::shipMove == 20 * SPAWN_TIME) {
        EnemyShips::e6hp[0] = level + 2;
        ViewSetxy(EnemyShips::e6[0], 113, -94);
    } else if (Counter::shipMove == 21 * SPAWN_TIME) {
        EnemyShips::e3hp[9] = level + 2;
        ViewSetxy(EnemyShips::e3[9], 113, -94);
    } else if (Counter::shipMove == 22 * SPAWN_TIME) {
        EnemyShips::e2hp[0] = level + 2;
        EnemyShips::e1hp[0] = level + 2;
        ViewSetxy(EnemyShips::e2[0], 33, -94);
        ViewSetxy(EnemyShips::e1[0], 193, -94);
    } else if (Counter::shipMove == 23 * SPAWN_TIME) {
        EnemyShips::e3hp[0] = level + 2;
        EnemyShips::e5hp[3] = level + 2;
        ViewSetxy(EnemyShips::e3[0], 33, -94);
        ViewSetxy(EnemyShips::e5[3], 193, -94);
    } else if (Counter::shipMove == 24 * SPAWN_TIME) {
        EnemyShips::e6hp[1] = level + 2;
        EnemyShips::e4hp[7] = level + 2;
        EnemyShips::e6hp[2] = level + 2;
        ViewSetxy(EnemyShips::e6[1], 0, -94);
        ViewSetxy(EnemyShips::e4[7], 113, -94);
        ViewSetxy(EnemyShips::e6[2], 226, -94);
    } else if (Counter::shipMove == 25 * SPAWN_TIME) {
        EnemyShips::e4hp[8] = level + 2;
        EnemyShips::e5hp[4] = level + 2;
        EnemyShips::e1hp[2] = level + 2;
        ViewSetxy(EnemyShips::e4[8], 0, -94);
        ViewSetxy(EnemyShips::e5[4], 113, -94);
        ViewSetxy(EnemyShips::e1[2], 226, -94);
    } else if (Counter::shipMove == 26 * SPAWN_TIME) {
        EnemyShips::e6hp[3] = level + 2;
        EnemyShips::e4hp[9] = level + 2;
        EnemyShips::e6hp[4] = level + 2;
        ViewSetxy(EnemyShips::e6[3], 0, -94);
        ViewSetxy(EnemyShips::e4[9], 113, -94);
        ViewSetxy(EnemyShips::e6[4], 226, -94);
    } else if (Counter::shipMove == 27 * SPAWN_TIME) {
        EnemyShips::e4hp[0] = level + 2;
        EnemyShips::e5hp[0] = level + 2;
        ViewSetxy(EnemyShips::e4[0], 33, -94);
        ViewSetxy(EnemyShips::e5[0], 193, -94);
    } else if (Counter::shipMove == 28 * SPAWN_TIME) {
        EnemyShips::e1hp[2] = level + 2;
        EnemyShips::e6hp[0] = level + 2;
        ViewSetxy(EnemyShips::e1[2], 33, -94);
        ViewSetxy(EnemyShips::e6[0], 193, -94);
    } else if (Counter::shipMove == 29 * SPAWN_TIME) {
        EnemyShips::e5hp[1] = level + 2;
        EnemyShips::e3hp[1] = level + 2;
        ViewSetxy(EnemyShips::e5[1], 33, -94);
        ViewSetxy(EnemyShips::e3[1], 193, -94);
    } else if (Counter::shipMove == 30 * SPAWN_TIME) {
        if (CurrentScreen != ScreenStoryBattle2) {
            EnemyShips::e9hp[0] = level + 24;
            ViewSetxy(EnemyShips::e9[0], 89, -240);
        }
    } else if (Counter::shipMove == 31 * SPAWN_TIME && CurrentScreen == ScreenStoryBattle2) {
        CurrentScreen = ScreenStory3a1;
        ScreenSwitch();
    }
}
void SetThree() {
    if (Counter::shipMove == 1 * SPAWN_TIME) {
        EnemyShips::e6hp[0] = level + 2;
        EnemyShips::e2hp[0] = level + 2;
        ViewSetxy(EnemyShips::e6[0], 33, -94);
        ViewSetxy(EnemyShips::e2[0], 193, -94);
    } else if (Counter::shipMove == 2 * SPAWN_TIME) {
        EnemyShips::e3hp[0] = level + 2;
        EnemyShips::e5hp[0] = level + 2;
        ViewSetxy(EnemyShips::e3[0], 33, -94);
        ViewSetxy(EnemyShips::e5[0], 193, -94);
    } else if (Counter::shipMove == 3 * SPAWN_TIME) {
        EnemyShips::e1hp[0] = level + 2;
        EnemyShips::e4hp[0] = level + 2;
        EnemyShips::e4hp[1] = level + 2;
        ViewSetxy(EnemyShips::e1[0], 0, -94);
        ViewSetxy(EnemyShips::e4[0], 113, -94);
        ViewSetxy(EnemyShips::e4[1], 226, -94);
    } else if (Counter::shipMove == 4 * SPAWN_TIME) {
        EnemyShips::e1hp[1] = level + 2;
        EnemyShips::e3hp[1] = level + 2;
        EnemyShips::e4hp[2] = level + 2;
        ViewSetxy(EnemyShips::e1[1], 0, -94);
        ViewSetxy(EnemyShips::e3[1], 113, -94);
        ViewSetxy(EnemyShips::e4[2], 226, -94);
    } else if (Counter::shipMove == 5 * SPAWN_TIME) {
        EnemyShips::e6hp[1] = level + 2;
        ViewSetxy(EnemyShips::e6[1], 113, -94);
    } else if (Counter::shipMove == 6 * SPAWN_TIME) {
        EnemyShips::e3hp[2] = level + 2;
        EnemyShips::e1hp[2] = level + 2;
        ViewSetxy(EnemyShips::e3[2], 33, -94);
        ViewSetxy(EnemyShips::e1[2], 193, -94);
    } else if (Counter::shipMove == 7 * SPAWN_TIME) {
        EnemyShips::e2hp[1] = level + 2;
        EnemyShips::e5hp[1] = level + 2;
        ViewSetxy(EnemyShips::e2[1], 33, -94);
        ViewSetxy(EnemyShips::e5[1], 193, -94);
    } else if (Counter::shipMove == 8 * SPAWN_TIME) {
        EnemyShips::e6hp[2] = level + 2;
        EnemyShips::e2hp[2] = level + 2;
        EnemyShips::e5hp[2] = level + 2;
        ViewSetxy(EnemyShips::e6[2], 0, -94);
        ViewSetxy(EnemyShips::e2[2], 113, -94);
        ViewSetxy(EnemyShips::e5[2], 226, -94);
    } else if (Counter::shipMove == 9 * SPAWN_TIME) {
        EnemyShips::e1hp[3] = level + 2;
        EnemyShips::e4hp[3] = level + 2;
        EnemyShips::e2hp[3] = level + 2;
        ViewSetxy(EnemyShips::e1[3], 0, -94);
        ViewSetxy(EnemyShips::e4[3], 113, -94);
        ViewSetxy(EnemyShips::e2[3], 226, -94);
    } else if (Counter::shipMove == 10 * SPAWN_TIME) {
        EnemyShips::e3hp[3] = level + 2;
        EnemyShips::e1hp[4] = level + 2;
        EnemyShips::e5hp[3] = level + 2;
        ViewSetxy(EnemyShips::e3[3], 0, -94);
        ViewSetxy(EnemyShips::e1[4], 113, -94);
        ViewSetxy(EnemyShips::e5[3], 226, -94);
    } else if (Counter::shipMove == 11 * SPAWN_TIME) {
        EnemyShips::e5hp[4] = level + 2;
        EnemyShips::e2hp[4] = level + 2;
        EnemyShips::e4hp[4] = level + 2;
        ViewSetxy(EnemyShips::e5[4], 0, -94);
        ViewSetxy(EnemyShips::e2[4], 113, -94);
        ViewSetxy(EnemyShips::e4[4], 226, -94);
    } else if (Counter::shipMove == 12 * SPAWN_TIME) {
        EnemyShips::e6hp[3] = level + 2;
        EnemyShips::e3hp[4] = level + 2;
        ViewSetxy(EnemyShips::e6[3], 33, -94);
        ViewSetxy(EnemyShips::e3[4], 193, -94);
    } else if (Counter::shipMove == 13 * SPAWN_TIME) {
        EnemyShips::e1hp[5] = level + 2;
        EnemyShips::e3hp[5] = level + 2;
        ViewSetxy(EnemyShips::e1[5], 33, -94);
        ViewSetxy(EnemyShips::e3[5], 193, -94);
    } else if (Counter::shipMove == 14 * SPAWN_TIME) {
        EnemyShips::e5hp[0] = level + 2;
        EnemyShips::e6hp[4] = level + 2;
        EnemyShips::e5hp[1] = level + 2;
        ViewSetxy(EnemyShips::e5[0], 0, -94);
        ViewSetxy(EnemyShips::e6[4], 113, -94);
        ViewSetxy(EnemyShips::e5[1], 226, -94);
    } else if (Counter::shipMove == 15 * SPAWN_TIME) {
        EnemyShips::e3hp[6] = level + 2;
        EnemyShips::e4hp[5] = level + 2;
        EnemyShips::e2hp[5] = level + 2;
        ViewSetxy(EnemyShips::e3[6], 0, -94);
        ViewSetxy(EnemyShips::e4[5], 113, -94);
        ViewSetxy(EnemyShips::e2[5], 226, -94);
    } else if (Counter::shipMove == 16 * SPAWN_TIME) {
        EnemyShips::e6hp[0] = level + 2;
        EnemyShips::e4hp[6] = level + 2;
        EnemyShips::e6hp[1] = level + 2;
        ViewSetxy(EnemyShips::e6[0], 0, -94);
        ViewSetxy(EnemyShips::e4[6], 113, -94);
        ViewSetxy(EnemyShips::e6[1], 226, -94);
    } else if (Counter::shipMove == 17 * SPAWN_TIME) {
        EnemyShips::e7hp[0] = level + 2;
        ViewSetxy(EnemyShips::e7[0], 113, -94);
    } else if (Counter::shipMove == 18 * SPAWN_TIME) {
        EnemyShips::e7hp[1] = level + 2;
        EnemyShips::e7hp[2] = level + 2;
        ViewSetxy(EnemyShips::e7[1], 33, -94);
        ViewSetxy(EnemyShips::e7[2], 193, -94);
    } else if (Counter::shipMove == 19 * SPAWN_TIME) {
        EnemyShips::e5hp[2] = level + 2;
        EnemyShips::e7hp[3] = level + 2;
        EnemyShips::e4hp[7] = level + 2;
        ViewSetxy(EnemyShips::e5[2], 0, -94);
        ViewSetxy(EnemyShips::e7[3], 113, -94);
        ViewSetxy(EnemyShips::e4[7], 226, -94);
    } else if (Counter::shipMove == 20 * SPAWN_TIME) {
        EnemyShips::e3hp[7] = level + 2;
        EnemyShips::e5hp[3] = level + 2;
        EnemyShips::e2hp[6] = level + 2;
        ViewSetxy(EnemyShips::e3[7], 0, -94);
        ViewSetxy(EnemyShips::e5[3], 113, -94);
        ViewSetxy(EnemyShips::e2[6], 226, -94);
    } else if (Counter::shipMove == 21 * SPAWN_TIME) {
        EnemyShips::e5hp[4] = level + 2;
        EnemyShips::e7hp[4] = level + 2;
        EnemyShips::e4hp[8] = level + 2;
        ViewSetxy(EnemyShips::e5[4], 0, -94);
        ViewSetxy(EnemyShips::e7[4], 113, -94);
        ViewSetxy(EnemyShips::e4[8], 226, -94);
    } else if (Counter::shipMove == 22 * SPAWN_TIME) {
        EnemyShips::e6hp[3] = level + 2;
        EnemyShips::e1hp[6] = level + 2;
        EnemyShips::e3hp[8] = level + 2;
        ViewSetxy(EnemyShips::e6[3], 0, -94);
        ViewSetxy(EnemyShips::e1[6], 113, -94);
        ViewSetxy(EnemyShips::e3[8], 226, -94);
    } else if (Counter::shipMove == 23 * SPAWN_TIME) {
        EnemyShips::e3hp[9] = level + 2;
        EnemyShips::e4hp[9] = level + 2;
        ViewSetxy(EnemyShips::e3[9], 33, -94);
        ViewSetxy(EnemyShips::e4[9], 193, -94);
    } else if (Counter::shipMove == 24 * SPAWN_TIME) {
        EnemyShips::e7hp[0] = level + 2;
        EnemyShips::e6hp[4] = level + 2;
        ViewSetxy(EnemyShips::e7[0], 33, -94);
        ViewSetxy(EnemyShips::e6[4], 193, -94);
    } else if (Counter::shipMove == 25 * SPAWN_TIME) {
        EnemyShips::e6hp[0] = level + 2;
        ViewSetxy(EnemyShips::e6[0], 113, -94);
    } else if (Counter::shipMove == 26 * SPAWN_TIME) {
        EnemyShips::e2hp[7] = level + 2;
        EnemyShips::e1hp[7] = level + 2;
        ViewSetxy(EnemyShips::e2[7], 33, -94);
        ViewSetxy(EnemyShips::e1[7], 193, -94);
    } else if (Counter::shipMove == 27 * SPAWN_TIME) {
        EnemyShips::e6hp[1] = level + 2;
        EnemyShips::e7hp[1] = level + 2;
        ViewSetxy(EnemyShips::e6[1], 33, -94);
        ViewSetxy(EnemyShips::e7[1], 193, -94);
    } else if (Counter::shipMove == 28 * SPAWN_TIME) {
        EnemyShips::e3hp[1] = level + 2;
        EnemyShips::e1hp[8] = level + 2;
        EnemyShips::e2hp[8] = level + 2;
        ViewSetxy(EnemyShips::e3[1], 0, -94);
        ViewSetxy(EnemyShips::e1[8], 113, -94);
        ViewSetxy(EnemyShips::e2[8], 226, -94);
    } else if (Counter::shipMove == 29 * SPAWN_TIME) {
        EnemyShips::e5hp[0] = level + 2;
        EnemyShips::e7hp[2] = level + 2;
        ViewSetxy(EnemyShips::e5[0], 33, -94);
        ViewSetxy(EnemyShips::e7[2], 193, -94);
    } else if (Counter::shipMove == 30 * SPAWN_TIME) {
        EnemyShips::e9hp[0] = level + 24;
        ViewSetxy(EnemyShips::e9[0], 89, -240);
    }
}
void SetFour() {
    if (Counter::shipMove == 1 * SPAWN_TIME) {
        EnemyShips::e1hp[0] = level + 2;
        EnemyShips::e2hp[0] = level + 2;
        ViewSetxy(EnemyShips::e1[0], 33, -94);
        ViewSetxy(EnemyShips::e2[0], 193, -94);
    } else if (Counter::shipMove == 2 * SPAWN_TIME) {
        EnemyShips::e6hp[0] = level + 2;
        EnemyShips::e3hp[0] = level + 2;
        ViewSetxy(EnemyShips::e6[0], 33, -94);
        ViewSetxy(EnemyShips::e3[0], 193, -94);
    } else if (Counter::shipMove == 3 * SPAWN_TIME) {
        EnemyShips::e4hp[0] = level + 2;
        EnemyShips::e5hp[0] = level + 2;
        EnemyShips::e4hp[1] = level + 2;
        ViewSetxy(EnemyShips::e4[0], 0, -94);
        ViewSetxy(EnemyShips::e5[0], 113, -94);
        ViewSetxy(EnemyShips::e4[1], 226, -94);
    } else if (Counter::shipMove == 4 * SPAWN_TIME) {
        EnemyShips::e1hp[1] = level + 2;
        EnemyShips::e7hp[0] = level + 2;
        EnemyShips::e2hp[1] = level + 2;
        ViewSetxy(EnemyShips::e1[1], 0, -94);
        ViewSetxy(EnemyShips::e7[0], 113, -94);
        ViewSetxy(EnemyShips::e2[1], 226, -94);
    } else if (Counter::shipMove == 5 * SPAWN_TIME) {
        EnemyShips::e5hp[1] = level + 2;
        EnemyShips::e3hp[1] = level + 2;
        EnemyShips::e4hp[2] = level + 2;
        ViewSetxy(EnemyShips::e5[1], 0, -94);
        ViewSetxy(EnemyShips::e3[1], 113, -94);
        ViewSetxy(EnemyShips::e4[2], 226, -94);
    } else if (Counter::shipMove == 6 * SPAWN_TIME) {
        EnemyShips::e6hp[1] = level + 2;
        EnemyShips::e7hp[1] = level + 2;
        ViewSetxy(EnemyShips::e6[1], 33, -94);
        ViewSetxy(EnemyShips::e7[1], 193, -94);
    } else if (Counter::shipMove == 7 * SPAWN_TIME) {
        EnemyShips::e6hp[2] = level + 2;
        ViewSetxy(EnemyShips::e6[2], 113, -94);
    } else if (Counter::shipMove == 8 * SPAWN_TIME) {
        EnemyShips::e7hp[2] = level + 2;
        ViewSetxy(EnemyShips::e7[2], 113, -94);
    } else if (Counter::shipMove == 9 * SPAWN_TIME) {
        EnemyShips::e2hp[2] = level + 2;
        EnemyShips::e1hp[2] = level + 2;
        ViewSetxy(EnemyShips::e2[2], 33, -94);
        ViewSetxy(EnemyShips::e1[2], 193, -94);
    } else if (Counter::shipMove == 10 * SPAWN_TIME) {
        EnemyShips::e3hp[2] = level + 2;
        EnemyShips::e5hp[2] = level + 2;
        ViewSetxy(EnemyShips::e3[2], 33, -94);
        ViewSetxy(EnemyShips::e5[2], 193, -94);
    } else if (Counter::shipMove == 11 * SPAWN_TIME) {
        EnemyShips::e6hp[3] = level + 2;
        EnemyShips::e1hp[3] = level + 2;
        EnemyShips::e7hp[3] = level + 2;
        ViewSetxy(EnemyShips::e6[3], 0, -94);
        ViewSetxy(EnemyShips::e1[3], 113, -94);
        ViewSetxy(EnemyShips::e7[3], 226, -94);
    } else if (Counter::shipMove == 12 * SPAWN_TIME) {
        EnemyShips::e4hp[3] = level + 2;
        EnemyShips::e7hp[4] = level + 2;
        EnemyShips::e3hp[3] = level + 2;
        ViewSetxy(EnemyShips::e4[3], 0, -94);
        ViewSetxy(EnemyShips::e7[4], 113, -94);
        ViewSetxy(EnemyShips::e3[3], 226, -94);
    } else if (Counter::shipMove == 13 * SPAWN_TIME) {
        EnemyShips::e1hp[4] = level + 2;
        EnemyShips::e6hp[4] = level + 2;
        EnemyShips::e2hp[3] = level + 2;
        ViewSetxy(EnemyShips::e1[4], 0, -94);
        ViewSetxy(EnemyShips::e6[4], 113, -94);
        ViewSetxy(EnemyShips::e2[3], 226, -94);
    } else if (Counter::shipMove == 14 * SPAWN_TIME) {
        EnemyShips::e7hp[0] = level + 2;
        ViewSetxy(EnemyShips::e7[0], 113, -94);
    } else if (Counter::shipMove == 15 * SPAWN_TIME) {
        EnemyShips::e4hp[4] = level + 2;
        EnemyShips::e3hp[4] = level + 2;
        ViewSetxy(EnemyShips::e4[4], 33, -94);
        ViewSetxy(EnemyShips::e3[4], 193, -94);
    } else if (Counter::shipMove == 16 * SPAWN_TIME) {
        EnemyShips::e1hp[5] = level + 2;
        EnemyShips::e2hp[4] = level + 2;
        ViewSetxy(EnemyShips::e1[5], 33, -94);
        ViewSetxy(EnemyShips::e2[4], 193, -94);
    } else if (Counter::shipMove == 17 * SPAWN_TIME) {
        EnemyShips::e5hp[3] = level + 2;
        EnemyShips::e6hp[0] = level + 2;
        EnemyShips::e5hp[4] = level + 2;
        ViewSetxy(EnemyShips::e5[3], 0, -94);
        ViewSetxy(EnemyShips::e6[0], 113, -94);
        ViewSetxy(EnemyShips::e5[4], 226, -94);
    } else if (Counter::shipMove == 18 * SPAWN_TIME) {
        EnemyShips::e6hp[1] = level + 2;
        EnemyShips::e7hp[1] = level + 2;
        EnemyShips::e3hp[5] = level + 2;
        ViewSetxy(EnemyShips::e6[1], 0, -94);
        ViewSetxy(EnemyShips::e7[1], 113, -94);
        ViewSetxy(EnemyShips::e3[5], 226, -94);
    } else if (Counter::shipMove == 19 * SPAWN_TIME) {
        EnemyShips::e1hp[6] = level + 2;
        EnemyShips::e5hp[0] = level + 2;
        EnemyShips::e2hp[5] = level + 2;
        ViewSetxy(EnemyShips::e1[6], 0, -94);
        ViewSetxy(EnemyShips::e5[0], 113, -94);
        ViewSetxy(EnemyShips::e2[5], 226, -94);
    } else if (Counter::shipMove == 20 * SPAWN_TIME) {
        EnemyShips::e7hp[2] = level + 2;
        EnemyShips::e4hp[5] = level + 2;
        EnemyShips::e5hp[1] = level + 2;
        ViewSetxy(EnemyShips::e7[2], 0, -94);
        ViewSetxy(EnemyShips::e4[5], 113, -94);
        ViewSetxy(EnemyShips::e5[6], 226, -94);
    } else if (Counter::shipMove == 21 * SPAWN_TIME) {
        EnemyShips::e8hp[0] = level + 2;
        ViewSetxy(EnemyShips::e1[0], 113, -94);
    } else if (Counter::shipMove == 22 * SPAWN_TIME) {
        EnemyShips::e7hp[3] = level + 2;
        EnemyShips::e8hp[1] = level + 2;
        ViewSetxy(EnemyShips::e7[3], 33, -94);
        ViewSetxy(EnemyShips::e8[1], 193, -94);
    } else if (Counter::shipMove == 23 * SPAWN_TIME) {
        EnemyShips::e1hp[7] = level + 2;
        EnemyShips::e2hp[6] = level + 2;
        ViewSetxy(EnemyShips::e1[7], 33, -94);
        ViewSetxy(EnemyShips::e2[6], 193, -94);
    } else if (Counter::shipMove == 24 * SPAWN_TIME) {
        EnemyShips::e4hp[6] = level + 2;
        EnemyShips::e3hp[6] = level + 2;
        ViewSetxy(EnemyShips::e4[6], 33, -94);
        ViewSetxy(EnemyShips::e3[6], 193, -94);
    } else if (Counter::shipMove == 25 * SPAWN_TIME) {
        EnemyShips::e7hp[4] = level + 2;
        EnemyShips::e8hp[2] = level + 2;
        EnemyShips::e4hp[7] = level + 2;
        ViewSetxy(EnemyShips::e7[4], 0, -94);
        ViewSetxy(EnemyShips::e8[2], 113, -94);
        ViewSetxy(EnemyShips::e4[7], 226, -94);
    } else if (Counter::shipMove == 26 * SPAWN_TIME) {
        EnemyShips::e6hp[2] = level + 2;
        EnemyShips::e2hp[7] = level + 2;
        EnemyShips::e6hp[3] = level + 2;
        ViewSetxy(EnemyShips::e6[2], 0, -94);
        ViewSetxy(EnemyShips::e2[7], 113, -94);
        ViewSetxy(EnemyShips::e6[3], 226, -94);
    } else if (Counter::shipMove == 27 * SPAWN_TIME) {
        EnemyShips::e1hp[8] = level + 2;
        EnemyShips::e5hp[2] = level + 2;
        EnemyShips::e1hp[9] = level + 2;
        ViewSetxy(EnemyShips::e1[8], 0, -94);
        ViewSetxy(EnemyShips::e5[2], 113, -94);
        ViewSetxy(EnemyShips::e1[9], 226, -94);
    } else if (Counter::shipMove == 28 * SPAWN_TIME) {
        EnemyShips::e8hp[3] = level + 2;
        EnemyShips::e3hp[7] = level + 2;
        EnemyShips::e8hp[4] = level + 2;
        ViewSetxy(EnemyShips::e8[3], 0, -94);
        ViewSetxy(EnemyShips::e3[7], 113, -94);
        ViewSetxy(EnemyShips::e8[4], 226, -94);
    } else if (Counter::shipMove == 29 * SPAWN_TIME) {
        EnemyShips::e5hp[3] = level + 2;
        EnemyShips::e2hp[8] = level + 2;
        ViewSetxy(EnemyShips::e5[3], 33, -94);
        ViewSetxy(EnemyShips::e2[8], 193, -94);
    } else if (Counter::shipMove == 30 * SPAWN_TIME) {
        if (CurrentScreen != ScreenStoryBattle5) {
            EnemyShips::e9hp[0] = level + 24;
            ViewSetxy(EnemyShips::e9[0], 89, -240);
        }
    } else if (Counter::shipMove == 31 * SPAWN_TIME && CurrentScreen == ScreenStoryBattle5) {
        CurrentScreen = ScreenStory6a1;
        ScreenSwitch();
    }
}
void SetFive() {
    if (Counter::shipMove == 1 * SPAWN_TIME) {
        EnemyShips::e6hp[0] = level + 2;
        ViewSetxy(EnemyShips::e6[0], 113, -94);
    } else if (Counter::shipMove == 2 * SPAWN_TIME) {
        EnemyShips::e7hp[0] = level + 2;
        EnemyShips::e2hp[0] = level + 2;
        ViewSetxy(EnemyShips::e7[0], 33, -94);
        ViewSetxy(EnemyShips::e2[0], 193, -94);
    } else if (Counter::shipMove == 3 * SPAWN_TIME) {
        EnemyShips::e1hp[0] = level + 2;
        EnemyShips::e8hp[0] = level + 2;
        ViewSetxy(EnemyShips::e1[0], 33, -94);
        ViewSetxy(EnemyShips::e8[0], 193, -94);
    } else if (Counter::shipMove == 4 * SPAWN_TIME) {
        EnemyShips::e5hp[0] = level + 2;
        EnemyShips::e6hp[1] = level + 2;
        EnemyShips::e4hp[0] = level + 2;
        ViewSetxy(EnemyShips::e5[0], 0, -94);
        ViewSetxy(EnemyShips::e6[1], 113, -94);
        ViewSetxy(EnemyShips::e4[0], 226, -94);
    } else if (Counter::shipMove == 5 * SPAWN_TIME) {
        EnemyShips::e3hp[0] = level + 2;
        EnemyShips::e1hp[1] = level + 2;
        EnemyShips::e7hp[1] = level + 2;
        ViewSetxy(EnemyShips::e3[0], 0, -94);
        ViewSetxy(EnemyShips::e1[1], 113, -94);
        ViewSetxy(EnemyShips::e7[1], 226, -94);
    } else if (Counter::shipMove == 6 * SPAWN_TIME) {
        EnemyShips::e7hp[2] = level + 2;
        EnemyShips::e8hp[1] = level + 2;
        EnemyShips::e6hp[2] = level + 2;
        ViewSetxy(EnemyShips::e7[2], 0, -94);
        ViewSetxy(EnemyShips::e8[1], 113, -94);
        ViewSetxy(EnemyShips::e6[2], 226, -94);
    } else if (Counter::shipMove == 7 * SPAWN_TIME) {
        EnemyShips::e3hp[1] = level + 2;
        EnemyShips::e1hp[2] = level + 2;
        EnemyShips::e4hp[1] = level + 2;
        ViewSetxy(EnemyShips::e3[1], 0, -94);
        ViewSetxy(EnemyShips::e1[2], 113, -94);
        ViewSetxy(EnemyShips::e4[1], 226, -94);
    } else if (Counter::shipMove == 8 * SPAWN_TIME) {
        EnemyShips::e2hp[1] = level + 2;
        EnemyShips::e7hp[3] = level + 2;
        ViewSetxy(EnemyShips::e2[1], 33, -94);
        ViewSetxy(EnemyShips::e7[3], 193, -94);
    } else if (Counter::shipMove == 9 * SPAWN_TIME) {
        EnemyShips::e6hp[3] = level + 2;
        EnemyShips::e3hp[2] = level + 2;
        ViewSetxy(EnemyShips::e6[3], 33, -94);
        ViewSetxy(EnemyShips::e3[2], 193, -94);
    } else if (Counter::shipMove == 10 * SPAWN_TIME) {
        EnemyShips::e6hp[4] = level + 2;
        ViewSetxy(EnemyShips::e6[4], 113, -94);
    } else if (Counter::shipMove == 11 * SPAWN_TIME) {
        EnemyShips::e8hp[2] = level + 2;
        ViewSetxy(EnemyShips::e8[2], 113, -94);
    } else if (Counter::shipMove == 12 * SPAWN_TIME) {
        EnemyShips::e5hp[1] = level + 2;
        EnemyShips::e1hp[3] = level + 2;
        EnemyShips::e6hp[0] = level + 2;
        ViewSetxy(EnemyShips::e5[1], 0, -94);
        ViewSetxy(EnemyShips::e1[3], 113, -94);
        ViewSetxy(EnemyShips::e6[0], 226, -94);
    } else if (Counter::shipMove == 13 * SPAWN_TIME) {
        EnemyShips::e4hp[2] = level + 2;
        EnemyShips::e3hp[3] = level + 2;
        EnemyShips::e5hp[2] = level + 2;
        ViewSetxy(EnemyShips::e4[2], 0, -94);
        ViewSetxy(EnemyShips::e3[3], 113, -94);
        ViewSetxy(EnemyShips::e5[2], 226, -94);
    } else if (Counter::shipMove == 14 * SPAWN_TIME) {
        EnemyShips::e2hp[2] = level + 2;
        EnemyShips::e6hp[1] = level + 2;
        EnemyShips::e3hp[4] = level + 2;
        ViewSetxy(EnemyShips::e2[2], 0, -94);
        ViewSetxy(EnemyShips::e6[1], 113, -94);
        ViewSetxy(EnemyShips::e3[4], 226, -94);
    } else if (Counter::shipMove == 15 * SPAWN_TIME) {
        EnemyShips::e8hp[3] = level + 2;
        EnemyShips::e4hp[3] = level + 2;
        ViewSetxy(EnemyShips::e8[3], 33, -94);
        ViewSetxy(EnemyShips::e4[3], 193, -94);
    } else if (Counter::shipMove == 16 * SPAWN_TIME) {
        EnemyShips::e3hp[5] = level + 2;
        EnemyShips::e6hp[2] = level + 2;
        ViewSetxy(EnemyShips::e3[5], 33, -94);
        ViewSetxy(EnemyShips::e6[2], 193, -94);
    } else if (Counter::shipMove == 17 * SPAWN_TIME) {
        EnemyShips::e8hp[4] = level + 2;
        EnemyShips::e5hp[3] = level + 2;
        EnemyShips::e6hp[3] = level + 2;
        ViewSetxy(EnemyShips::e8[4], 0, -94);
        ViewSetxy(EnemyShips::e5[3], 113, -94);
        ViewSetxy(EnemyShips::e6[3], 226, -94);
    } else if (Counter::shipMove == 18 * SPAWN_TIME) {
        EnemyShips::e7hp[4] = level + 2;
        ViewSetxy(EnemyShips::e7[4], 113, -94);
    } else if (Counter::shipMove == 19 * SPAWN_TIME) {
        EnemyShips::e8hp[0] = level + 2;
        ViewSetxy(EnemyShips::e8[0], 113, -94);
    } else if (Counter::shipMove == 20 * SPAWN_TIME) {
        EnemyShips::e5hp[4] = level + 2;
        EnemyShips::e6hp[4] = level + 2;
        ViewSetxy(EnemyShips::e5[4], 33, -94);
        ViewSetxy(EnemyShips::e6[4], 193, -94);
    } else if (Counter::shipMove == 21 * SPAWN_TIME) {
        EnemyShips::e8hp[1] = level + 2;
        EnemyShips::e6hp[0] = level + 2;
        EnemyShips::e7hp[0] = level + 2;
        ViewSetxy(EnemyShips::e8[1], 0, -94);
        ViewSetxy(EnemyShips::e6[0], 113, -94);
        ViewSetxy(EnemyShips::e7[0], 226, -94);
    } else if (Counter::shipMove == 22 * SPAWN_TIME) {
        EnemyShips::e2hp[3] = level + 2;
        EnemyShips::e4hp[4] = level + 2;
        EnemyShips::e3hp[6] = level + 2;
        ViewSetxy(EnemyShips::e2[3], 0, -94);
        ViewSetxy(EnemyShips::e4[4], 113, -94);
        ViewSetxy(EnemyShips::e3[6], 226, -94);
    } else if (Counter::shipMove == 23 * SPAWN_TIME) {
        EnemyShips::e6hp[1] = level + 2;
        EnemyShips::e2hp[4] = level + 2;
        EnemyShips::e5hp[0] = level + 2;
        ViewSetxy(EnemyShips::e6[1], 0, -94);
        ViewSetxy(EnemyShips::e2[4], 113, -94);
        ViewSetxy(EnemyShips::e5[0], 226, -94);
    } else if (Counter::shipMove == 24 * SPAWN_TIME) {
        EnemyShips::e8hp[2] = level + 2;
        EnemyShips::e7hp[1] = level + 2;
        EnemyShips::e6hp[2] = level + 2;
        ViewSetxy(EnemyShips::e8[2], 0, -94);
        ViewSetxy(EnemyShips::e7[1], 113, -94);
        ViewSetxy(EnemyShips::e6[2], 226, -94);
    } else if (Counter::shipMove == 25 * SPAWN_TIME) {
        EnemyShips::e2hp[5] = level + 2;
        EnemyShips::e7hp[2] = level + 2;
        EnemyShips::e3hp[7] = level + 2;
        ViewSetxy(EnemyShips::e2[5], 0, -94);
        ViewSetxy(EnemyShips::e7[2], 113, -94);
        ViewSetxy(EnemyShips::e3[7], 226, -94);
    } else if (Counter::shipMove == 26 * SPAWN_TIME) {
        EnemyShips::e8hp[3] = level + 2;
        EnemyShips::e1hp[4] = level + 2;
        ViewSetxy(EnemyShips::e8[3], 33, -94);
        ViewSetxy(EnemyShips::e1[4], 193, -94);
    } else if (Counter::shipMove == 27 * SPAWN_TIME) {
        EnemyShips::e2hp[6] = level + 2;
        EnemyShips::e5hp[1] = level + 2;
        EnemyShips::e3hp[8] = level + 2;
        ViewSetxy(EnemyShips::e2[6], 0, -94);
        ViewSetxy(EnemyShips::e5[1], 113, -94);
        ViewSetxy(EnemyShips::e3[8], 226, -94);
    } else if (Counter::shipMove == 28 * SPAWN_TIME) {
        EnemyShips::e7hp[3] = level + 2;
        EnemyShips::e5hp[2] = level + 2;
        EnemyShips::e6hp[3] = level + 2;
        ViewSetxy(EnemyShips::e7[3], 0, -94);
        ViewSetxy(EnemyShips::e5[2], 113, -94);
        ViewSetxy(EnemyShips::e6[3], 226, -94);
    } else if (Counter::shipMove == 29 * SPAWN_TIME) {
        EnemyShips::e6hp[3] = level + 2;
        EnemyShips::e8hp[4] = level + 2;
        ViewSetxy(EnemyShips::e6[3], 33, -94);
        ViewSetxy(EnemyShips::e8[4], 193, -94);
    } else if (Counter::shipMove == 30 * SPAWN_TIME) {
        EnemyShips::e10hp[0] = level + 49;
        ViewSetxy(EnemyShips::e10[0], 85, -240);
    }
}
void EnemyShipMove() {
    for (int i = 0; i < 10; i++) {
        //x cords
        EnemyShips::e1y[i] = ViewGety(EnemyShips::e1[i]);
        EnemyShips::e2y[i] = ViewGety(EnemyShips::e2[i]);
        EnemyShips::e3y[i] = ViewGety(EnemyShips::e3[i]);
        EnemyShips::e4y[i] = ViewGety(EnemyShips::e4[i]);
        //y cords
        EnemyShips::e1x[i] = ViewGetx(EnemyShips::e1[i]);
        EnemyShips::e2x[i] = ViewGetx(EnemyShips::e2[i]);
        EnemyShips::e3x[i] = ViewGetx(EnemyShips::e3[i]);
        EnemyShips::e4x[i] = ViewGetx(EnemyShips::e4[i]);
    }
    for (int i = 0; i < 5; i++) {
        //x cords
        EnemyShips::e5y[i] = ViewGety(EnemyShips::e5[i]);
        EnemyShips::e6y[i] = ViewGety(EnemyShips::e6[i]);
        EnemyShips::e7y[i] = ViewGety(EnemyShips::e7[i]);
        EnemyShips::e8y[i] = ViewGety(EnemyShips::e8[i]);
        //y cords
        EnemyShips::e5x[i] = ViewGetx(EnemyShips::e5[i]);
        EnemyShips::e6x[i] = ViewGetx(EnemyShips::e6[i]);
        EnemyShips::e7x[i] = ViewGetx(EnemyShips::e7[i]);
        EnemyShips::e8x[i] = ViewGetx(EnemyShips::e8[i]);
    }
    //x cords
    EnemyShips::e9x[0] = ViewGetx(EnemyShips::e9[0]);
    //y cords
    EnemyShips::e9y[0] = ViewGety(EnemyShips::e9[0]);
    //x cords
    EnemyShips::e10x[0] = ViewGetx(EnemyShips::e10[0]);
    //y cords
    EnemyShips::e10y[0] = ViewGety(EnemyShips::e10[0]);
    for (int i = 0; i < 10; i++) {
        if (EnemyShips::e1y[i] < 600) {
            ViewSetxy(EnemyShips::e1[i], EnemyShips::e1x[i], EnemyShips::e1y[i] + ENEMY_FLY_SPEED);
        }
        if (EnemyShips::e2y[i] < 600) {
            ViewSetxy(EnemyShips::e2[i], EnemyShips::e2x[i], EnemyShips::e2y[i] + ENEMY_FLY_SPEED);
        }
        if (EnemyShips::e3y[i] < 600) {
            ViewSetxy(EnemyShips::e3[i], EnemyShips::e3x[i], EnemyShips::e3y[i] + ENEMY_FLY_SPEED);
        }
        if (EnemyShips::e4y[i] < 600) {
            ViewSetxy(EnemyShips::e4[i], EnemyShips::e4x[i], EnemyShips::e4y[i] + ENEMY_FLY_SPEED);
        }
    }
    for (int i = 0; i < 5; i++) {
        if (EnemyShips::e5y[i] < 600) {
            ViewSetxy(EnemyShips::e5[i], EnemyShips::e5x[i], EnemyShips::e5y[i] + ENEMY_FLY_SPEED);
        }
        if (EnemyShips::e6y[i] < 600) {
            ViewSetxy(EnemyShips::e6[i], EnemyShips::e6x[i], EnemyShips::e6y[i] + ENEMY_FLY_SPEED);
        }
        if (EnemyShips::e7y[i] < 600) {
            ViewSetxy(EnemyShips::e7[i], EnemyShips::e7x[i], EnemyShips::e7y[i] + ENEMY_FLY_SPEED);
        }
        if (EnemyShips::e8y[i] < 600) {
            ViewSetxy(EnemyShips::e8[i], EnemyShips::e8x[i], EnemyShips::e8y[i] + ENEMY_FLY_SPEED);
        }
    }
    
    bool goRight = false;
    //ship 9
    if (EnemyShips::e9y[0] < 40) {
        ViewSetxy(EnemyShips::e9[0], EnemyShips::e9x[0], EnemyShips::e9y[0] + ENEMY_FLY_SPEED);
    } else if (EnemyShips::e9y[0] >= 40 && EnemyShips::e9y[0] < 600) {
        const int factor = (goRight) ? (1) : (-1);
        ViewSetxy(EnemyShips::e9[0], EnemyShips::e9x[0] + factor, EnemyShips::e9y[0]);
    }
    if (EnemyShips::e9x[0] == 29) {
        goRight = true;
    } else if (EnemyShips::e9x[0] == 149) {
        goRight = false;
    }
    //ship 10
    if (EnemyShips::e10y[0] < 40) {
        ViewSetxy(EnemyShips::e10[0], EnemyShips::e10x[0], EnemyShips::e10y[0] + ENEMY_FLY_SPEED);
    } else if (EnemyShips::e10y[0] >= 40 && EnemyShips::e10y[0] < 600) {
        const int factor = (goRight) ? (1) : (-1);
        ViewSetxy(EnemyShips::e10[0], EnemyShips::e10x[0] + factor, EnemyShips::e10y[0]);
    }
    if (EnemyShips::e10x[0] == 25) {
        goRight = true;
    } else if (EnemyShips::e10x[0] == 145) {
        goRight = false;
    }
}
void DoEnemyShipMove() {
    EnemyShipMove();
    switch (set) {
        case 1:
            SetOne();
            break;
        case 2:
            SetTwo();
            break;
        case 3:
            SetThree();
            break;
        case 4:
            SetFour();
            break;
        case 5:
            SetFive();
            break;
        case 6:
            Counter::shipMove = 0;
            level += 1;
            set = 1;
            break;
    }
}
void DoEnemyShipShoot() {
    int ex, ey, ex2, ey2, ex3, ey3;
    for (int i = 0; i < 5; i++) {
        if (Counter::bulletMove == (i + 1) * ENEMY_SHOOT_COOLDOWN_SPEED) {
            //ship 1-4
            for (int j = 0; j < 10; j++) {
                ViewSetxy(Bullets::e1b2[10 * i + j], EnemyShips::e1x[j] + 43, EnemyShips::e1y[j] + 83);
                ViewSetxy(Bullets::e2b2[10 * i + j], EnemyShips::e2x[j] + 43, EnemyShips::e2y[j] + 94);
                ViewSetxy(Bullets::e3b2[10 * i + j], EnemyShips::e3x[j] + 43, EnemyShips::e3y[j] + 88);
                ViewSetxy(Bullets::e4b2[10 * i + j], EnemyShips::e4x[j] + 43, EnemyShips::e4y[j] + 94);
            }
            //ship 5-8
            for (int j = 0; j < 5; j++) {
                ViewSetxy(Bullets::e5b1[5 * i + j], EnemyShips::e5x[j] + 31, EnemyShips::e5y[j] + 71);
                ViewSetxy(Bullets::e5b3[5 * i + j], EnemyShips::e5x[j] + 54, EnemyShips::e5y[j] + 71);
                ViewSetxy(Bullets::e6b1[5 * i + j], EnemyShips::e6x[j] + 15, EnemyShips::e6y[j] + 53);
                ViewSetxy(Bullets::e6b3[5 * i + j], EnemyShips::e6x[j] + 68, EnemyShips::e6y[j] + 53);
                ViewSetxy(Bullets::e7b2[5 * i + j], EnemyShips::e7x[j] + 42, EnemyShips::e7y[j] + 83);
                ViewSetxy(Bullets::e8b1[5 * i + j], EnemyShips::e8x[j] + 12, EnemyShips::e8y[j] + 54);
                ViewSetxy(Bullets::e8b2[5 * i + j], EnemyShips::e8x[j] + 42, EnemyShips::e8y[j] + 92);
                ViewSetxy(Bullets::e8b3[5 * i + j], EnemyShips::e8x[j] + 74, EnemyShips::e8y[j] + 54);
            }
            //ship 9
            ViewSetxy(Bullets::e9b1[i], EnemyShips::e9x[0] + 3, EnemyShips::e9y[0] + 83);
            ViewSetxy(Bullets::e9b2[i], EnemyShips::e9x[0] + 66, EnemyShips::e9y[0] + 230);
            ViewSetxy(Bullets::e9b3[i], EnemyShips::e9x[0] + 130, EnemyShips::e9y[0] + 83);
            //ship 10
            ViewSetxy(Bullets::e10b1[i], EnemyShips::e10x[0] + 13, EnemyShips::e10y[0] + 83);
            ViewSetxy(Bullets::e10b2[i], EnemyShips::e10x[0] + 69, EnemyShips::e10y[0] + 233);
            ViewSetxy(Bullets::e10b3[i], EnemyShips::e10x[0] + 129, EnemyShips::e10y[0] + 83);
        }
    }
    if (Counter::bulletMove >= 5 * ENEMY_SHOOT_COOLDOWN_SPEED) {
        Counter::bulletMove = 0;
    }
    if (Counter::bulletMove % ENEMY_SHOOT_COOLDOWN_SPEED != 0) {
        //1
        for (int i = 0; i < 50; i++) {
            ex = ViewGetx(Bullets::e1b2[i]);
            ey = ViewGety(Bullets::e1b2[i]);
            if (ey < 600) {
                ViewSetxy(Bullets::e1b2[i], ex, ey + ENEMY_BULLET_SPEED);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e1b2[i], 600, 600);
            }
        }
        //2
        for (int i = 0; i < 50; i++) {
            ex = ViewGetx(Bullets::e2b2[i]);
            ey = ViewGety(Bullets::e2b2[i]);
            if (ey < 600) {
                ViewSetxy(Bullets::e2b2[i], ex, ey + ENEMY_BULLET_SPEED);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e2b2[i], 600, 600);
            }
        }
        //3
        for (int i = 0; i < 50; i++) {
            ex = ViewGetx(Bullets::e3b2[i]);
            ey = ViewGety(Bullets::e3b2[i]);
            if (ey < 600) {
                ViewSetxy(Bullets::e3b2[i], ex, ey + ENEMY_BULLET_SPEED);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e3b2[i], 600, 600);
            }
        }
        //4
        for (int i = 0; i < 50; i++) {
            ex = ViewGetx(Bullets::e4b2[i]);
            ey = ViewGety(Bullets::e4b2[i]);
            if (ey < 600) {
                ViewSetxy(Bullets::e4b2[i], ex, ey + ENEMY_BULLET_SPEED);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e4b2[i], 600, 600);
            }
        }
        //5
        for (int i = 0; i < 25; i++) {
            ex = ViewGetx(Bullets::e5b1[i]);
            ey = ViewGety(Bullets::e5b1[i]);
            ex3 = ViewGetx(Bullets::e5b3[i]);
            ey3 = ViewGety(Bullets::e5b3[i]);
            if (ey < 600 || ey3 < 600) {
                ViewSetxy(Bullets::e5b1[i], ex, ey + ENEMY_BULLET_SPEED);
                ViewSetxy(Bullets::e5b3[i], ex3, ey3 + ENEMY_BULLET_SPEED);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e5b1[i], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e5b3[i], 600, 600);
            }
        }
        //6
        for (int i = 0; i < 25; i++) {
            ex = ViewGetx(Bullets::e6b1[i]);
            ey = ViewGety(Bullets::e6b1[i]);
            ex3 = ViewGetx(Bullets::e6b3[i]);
            ey3 = ViewGety(Bullets::e6b3[i]);
            if (ey < 600 || ey3 < 600) {
                ViewSetxy(Bullets::e6b1[i], ex, ey + ENEMY_BULLET_SPEED);
                ViewSetxy(Bullets::e6b3[i], ex3, ey3 + ENEMY_BULLET_SPEED);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e6b1[i], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e6b3[i], 600, 600);
            }
        }
        //7
        for (int i = 0; i < 25; i++) {
            ex2 = ViewGetx(Bullets::e7b2[i]);
            ey2 = ViewGety(Bullets::e7b2[i]);
            if (ey2 < 600) {
                ViewSetxy(Bullets::e7b2[i], ex2, ey2 + ENEMY_BULLET_SPEED);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e7b2[i], 600, 600);
            }
        }
        //8
        for (int i = 0; i < 25; i++) {
            ex = ViewGetx(Bullets::e8b1[i]);
            ey = ViewGety(Bullets::e8b1[i]);
            ex2 = ViewGetx(Bullets::e8b2[i]);
            ey2 = ViewGety(Bullets::e8b2[i]);
            ex3 = ViewGetx(Bullets::e8b3[i]);
            ey3 = ViewGety(Bullets::e8b3[i]);
            if (ey < 600 || ey2 < 600 || ey3 < 600) {
                ViewSetxy(Bullets::e8b1[i], ex, ey + ENEMY_BULLET_SPEED);
                ViewSetxy(Bullets::e8b2[i], ex2, ey2 + ENEMY_BULLET_SPEED);
                ViewSetxy(Bullets::e8b3[i], ex3, ey3 + ENEMY_BULLET_SPEED);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e8b1[i], 600, 600);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e8b2[i], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e8b3[i], 600, 600);
            }
        }
        //9
        for (int i = 0; i < 5; i++) {
            ex = ViewGetx(Bullets::e9b1[i]);
            ey = ViewGety(Bullets::e9b1[i]);
            ex2 = ViewGetx(Bullets::e9b2[i]);
            ey2 = ViewGety(Bullets::e9b2[i]);
            ex3 = ViewGetx(Bullets::e9b3[i]);
            ey3 = ViewGety(Bullets::e9b3[i]);
            if (ey < 600 || ey2 < 600 || ey3 < 600) {
                ViewSetxy(Bullets::e9b1[i], ex, ey + ENEMY_BULLET_SPEED);
                ViewSetxy(Bullets::e9b2[i], ex2, ey2 + ENEMY_BULLET_SPEED);
                ViewSetxy(Bullets::e9b3[i], ex3, ey3 + ENEMY_BULLET_SPEED);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e9b1[i], 600, 600);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e9b2[i], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e9b3[i], 600, 600);
            }
        }
        //10
        for (int i = 0; i < 5; i++) {
            ex = ViewGetx(Bullets::e10b1[i]);
            ey = ViewGety(Bullets::e10b1[i]);
            ex2 = ViewGetx(Bullets::e10b2[i]);
            ey2 = ViewGety(Bullets::e10b2[i]);
            ex3 = ViewGetx(Bullets::e10b3[i]);
            ey3 = ViewGety(Bullets::e10b3[i]);
            if (ey < 600 || ey2 < 600 || ey3 < 600) {
                ViewSetxy(Bullets::e10b1[i], ex, ey + ENEMY_BULLET_SPEED);
                ViewSetxy(Bullets::e10b2[i], ex2, ey2 + ENEMY_BULLET_SPEED);
                ViewSetxy(Bullets::e10b3[i], ex3, ey3 + ENEMY_BULLET_SPEED);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e10b1[i], 600, 600);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e10b2[i], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                State::healthUpdate = true;
                ViewSetxy(Bullets::e10b3[i], 600, 600);
            }
        }
    }
}
bool ShipInAction(int ship) {
    bool ret = false;
    switch (ship) {
        case 1:
            ret = EnemyShips::e1hp[Counter::shipAction] <= 0 && EnemyShips::e1y[Counter::shipAction] >= 0 
                && EnemyShips::e1x[Counter::shipAction] < 600 && EnemyShips::e1y[Counter::shipAction] >= 0 
                && EnemyShips::e1x[Counter::shipAction] <= 320;
            break;
        case 2:
            ret = EnemyShips::e2hp[Counter::shipAction] <= 0 && EnemyShips::e2y[Counter::shipAction] >= 0 
                && EnemyShips::e2x[Counter::shipAction] < 600 && EnemyShips::e2y[Counter::shipAction] >= 0 
                && EnemyShips::e2x[Counter::shipAction] <= 320;
            break;
        case 3:
            ret = EnemyShips::e3hp[Counter::shipAction] <= 0 && EnemyShips::e3y[Counter::shipAction] >= 0 
                && EnemyShips::e3x[Counter::shipAction] < 600 && EnemyShips::e3y[Counter::shipAction] >= 0 
                && EnemyShips::e3x[Counter::shipAction] <= 320;
            break;
        case 4:
            ret = EnemyShips::e4hp[Counter::shipAction] <= 0 && EnemyShips::e4y[Counter::shipAction] >= 0 
                && EnemyShips::e4x[Counter::shipAction] < 600 && EnemyShips::e4y[Counter::shipAction] >= 0 
                && EnemyShips::e4x[Counter::shipAction] <= 320;
            break;
        case 5:
            ret = EnemyShips::e5hp[Counter::shipAction] <= 0 && EnemyShips::e5y[Counter::shipAction] >= 0 
                && EnemyShips::e5x[Counter::shipAction] < 600 && EnemyShips::e5y[Counter::shipAction] >= 0 
                && EnemyShips::e5x[Counter::shipAction] <= 320;
            break;
        case 6:
            ret = EnemyShips::e6hp[Counter::shipAction] <= 0 && EnemyShips::e6y[Counter::shipAction] >= 0 
                && EnemyShips::e6x[Counter::shipAction] < 600 && EnemyShips::e6y[Counter::shipAction] >= 0 
                && EnemyShips::e6x[Counter::shipAction] <= 320;
            break;
        case 7:
            ret = EnemyShips::e7hp[Counter::shipAction] <= 0 && EnemyShips::e7y[Counter::shipAction] >= 0 
                && EnemyShips::e7x[Counter::shipAction] < 600 && EnemyShips::e7y[Counter::shipAction] >= 0 
                && EnemyShips::e7x[Counter::shipAction] <= 320;
            break;
        case 8:
            ret = EnemyShips::e8hp[Counter::shipAction] <= 0 && EnemyShips::e8y[Counter::shipAction] >= 0 
                && EnemyShips::e8x[Counter::shipAction] < 600 && EnemyShips::e8y[Counter::shipAction] >= 0 
                && EnemyShips::e8x[Counter::shipAction] <= 320;
            break;
        case 9:
            ret = EnemyShips::e9hp[0] <= 0 && EnemyShips::e9y[0] >= 0 && EnemyShips::e9x[0] < 600 
				&& EnemyShips::e9y[0] >= 0 && EnemyShips::e9x[0] <= 320;
            break;
        case 10:
            ret = EnemyShips::e10hp[0] <= 0 && EnemyShips::e10y[0] >= 0 && EnemyShips::e10x[0] < 600 
				&& EnemyShips::e10y[0] >= 0 && EnemyShips::e10x[0] <= 320;
            break;
    }
    return ret;
}
int SetEnemyExplosion(int ship) {
    int explosion;
    switch (ship) {
        case 1:
            explosion = (EnemyShips::e1[Counter::shipAction]);
            break;
        case 2:
            explosion = (EnemyShips::e2[Counter::shipAction]);
            break;
        case 3:
            explosion = (EnemyShips::e3[Counter::shipAction]);
            break;
        case 4:
            explosion = (EnemyShips::e4[Counter::shipAction]);
            break;
        case 5:
            explosion = (EnemyShips::e5[Counter::shipAction]);
            break;
        case 6:
            explosion = (EnemyShips::e6[Counter::shipAction]);
            break;
        case 7:
            explosion = (EnemyShips::e7[Counter::shipAction]);
            break;
        case 8:
            explosion = (EnemyShips::e8[Counter::shipAction]);
            break;
    }
    return explosion;
}
void EnemyDied() {
    int explosion, image;
    for (int i = 1; i <= 4; i++) {
        for (Counter::shipAction = 0; Counter::shipAction < 10; Counter::shipAction++) {
            bool used = false;
            for (int j = 0; j <= 8; j++) {
                if (enemyExplosionCounter[i - 1] == j && ShipInAction(i) && !used) {
                    explosion = SetEnemyExplosion(i);
                    char temp[] = "Images/Explosion_1.png";
                    temp[17] = char(j + 1 + '0');
                    image = ImageAdd(temp);
                    ViewSetImage(explosion, image);
                    enemyExplosionCounter[i - 1] += 1;
                    used = true;
                }
            }
            if (enemyExplosionCounter[i - 1] == 9 && ShipInAction(i)) {
                explosion = SetEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_10.png");
                ViewSetImage(explosion, image);
                enemyExplosionCounter[i - 1] += 1;
            } else if (enemyExplosionCounter[i - 1] == 10 && ShipInAction(i)) {
                explosion = SetEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_11.png");
                ViewSetImage(explosion, image);
                enemyExplosionCounter[i - 1] += 1;
            } else if (enemyExplosionCounter[i - 1] == 11 && ShipInAction(i)) {
                explosion = SetEnemyExplosion(i);
                char tempShip[] = "Images/eShip_1.png";
                tempShip[13] = char(i + '0');
                image = ImageAdd(tempShip);
                ViewSetImage(explosion, image);
                if (i == 1) {
                    ViewSetxy(EnemyShips::e1[Counter::shipAction], 600, 600);
                } else if (i == 2) {
                    ViewSetxy(EnemyShips::e2[Counter::shipAction], 600, 600);
                } else if (i == 3) {
                    ViewSetxy(EnemyShips::e3[Counter::shipAction], 600, 600);
                } else if (i == 4) {
                    ViewSetxy(EnemyShips::e4[Counter::shipAction], 600, 600);
                }
                enemyExplosionCounter[i - 1] = 0;
                xp += 1 * level;
            }
        }
    }

    for (int i = 5; i <= 8; i++) {
        for (Counter::shipAction = 0; Counter::shipAction < 5; Counter::shipAction++) {
            bool used = false;
            for (int j = 0; j <= 8; j++) {
                if (enemyExplosionCounter[i - 1] == j && ShipInAction(i) && !used) {
                    explosion = SetEnemyExplosion(i);
                    char temp[] = "Images/Explosion_1.png";
                    temp[17] = char(j + 1 + '0');
                    image = ImageAdd(temp);
                    ViewSetImage(explosion, image);
                    enemyExplosionCounter[i - 1] += 1;
                    used = true;
                }
            }
            if (enemyExplosionCounter[i - 1] == 9 && ShipInAction(i)) {
                explosion = SetEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_10.png");
                ViewSetImage(explosion, image);
                enemyExplosionCounter[i - 1] += 1;
            } else if (enemyExplosionCounter[i - 1] == 10 && ShipInAction(i)) {
                explosion = SetEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_11.png");
                ViewSetImage(explosion, image);
                enemyExplosionCounter[i - 1] += 1;
            } else if (enemyExplosionCounter[i - 1] == 11 && ShipInAction(i)) {
                explosion = SetEnemyExplosion(i);
                char tempShip[] = "Images/eShip_1.png";
                tempShip[13] = char(i + '0');
                image = ImageAdd(tempShip);
                ViewSetImage(explosion, image);
                if (i == 5) {
                    ViewSetxy(EnemyShips::e5[Counter::shipAction], 600, 600);
                } else if (i == 6) {
                    ViewSetxy(EnemyShips::e6[Counter::shipAction], 600, 600);
                } else if (i == 7) {
                    ViewSetxy(EnemyShips::e7[Counter::shipAction], 600, 600);
                } else if (i == 8) {
                    ViewSetxy(EnemyShips::e8[Counter::shipAction], 600, 600);
                }
                enemyExplosionCounter[i - 1] = 0;
                xp += 2 * level;
            }
        }
    }

    bool used = false;
    for (int j = 0; j <= 8; j++) {
        if (enemyExplosionCounter[8] == j && ShipInAction(9) && !used) {
            explosion = (EnemyShips::e9[0]);
            char temp[] = "Images/BigExplosion_1.png";
            temp[20] = char(j + 1 + '0');
            image = ImageAdd(temp);
            ViewSetImage(explosion, image);
            enemyExplosionCounter[8] += 1;
            used = true;
        }
    }
    if (enemyExplosionCounter[8] == 9 && ShipInAction(9)) {
        explosion = (EnemyShips::e9[0]);
        image = ImageAdd("Images/BigExplosion_10.png");
        ViewSetImage(explosion, image);
        enemyExplosionCounter[8] += 1;
    } else if (enemyExplosionCounter[8] == 10 && ShipInAction(9)) {
        explosion = (EnemyShips::e9[0]);
        image = ImageAdd("Images/BigExplosion_11.png");
        ViewSetImage(explosion, image);
        enemyExplosionCounter[8] += 1;
    } else if (enemyExplosionCounter[8] == 11 && ShipInAction(9)) {
        explosion = (EnemyShips::e9[0]);
        image = ImageAdd("Images/eMini-Boss.png");
        ViewSetImage(explosion, image);
        ViewSetxy(EnemyShips::e9[0], 600, 600);
        enemyExplosionCounter[8] = 0;
        xp += level * 5;
        if (CurrentScreen != ScreenStoryBattle4) {
            set += 1;
            Counter::shipMove = 0;
            health = possibleHealth;
            State::healthUpdate = true;
        } else if (CurrentScreen == ScreenStoryBattle4) {
            CurrentScreen = ScreenStory5a1;
            ScreenSwitch();
        }
    }

    used = false;
    for (int j = 0; j <= 8; j++) {
        if (enemyExplosionCounter[9] == j && ShipInAction(10) && !used) {
            explosion = (EnemyShips::e10[0]);
            char temp[] = "Images/BigExplosion_1.png";
            temp[20] = char(j + 1 + '0');
            image = ImageAdd(temp);
            ViewSetImage(explosion, image);
            enemyExplosionCounter[9] += 1;
            used = true;
        }
    }
    if (enemyExplosionCounter[9] == 9 && ShipInAction(10)) {
        explosion = (EnemyShips::e10[0]);
        image = ImageAdd("Images/BigExplosion_10.png");
        ViewSetImage(explosion, image);
        enemyExplosionCounter[9] += 1;
    } else if (enemyExplosionCounter[9] == 10 && ShipInAction(10)) {
        explosion = (EnemyShips::e10[0]);
        image = ImageAdd("Images/BigExplosion_11.png");
        ViewSetImage(explosion, image);
        enemyExplosionCounter[9] += 1;
    } else if (enemyExplosionCounter[9] == 11 && ShipInAction(10)) {
        explosion = (EnemyShips::e10[0]);
        image = ImageAdd("Images/eBoss.png");
        ViewSetImage(explosion, image);
        ViewSetxy(EnemyShips::e10[0], 600, 600);
        enemyExplosionCounter[9] = 0;
        xp += level * 7;
        if (CurrentScreen != ScreenStoryBattle6) {
            set += 1;
            Counter::shipMove = 0;
            health = possibleHealth;
            State::healthUpdate = true;
        } else if (CurrentScreen == ScreenStoryBattle6) {
            CurrentScreen = ScreenStory7w1;
            ScreenSwitch();
        }
    }
}
void ShipCollision() {
    for (int i = 0; i < 10; i++) {
        //ship 1
        if (mX + width1 < EnemyShips::e1x[i] + 76 && mX + width2 > EnemyShips::e1x[i] + 18 
			&& mY < EnemyShips::e1y[i] + 94 && mY + 94 > EnemyShips::e1y[i]) {
            if (EnemyShips::e1hp[i] > 0) {
                EnemyShips::e1hp[i] -= 2 + level;
                health -= 2 + level;
                State::healthUpdate = true;
            }
        }
        //ship 2
        if (mX + width1 < EnemyShips::e2x[i] + 69 && mX + width2 > EnemyShips::e2x[i] + 24 
			&& mY < EnemyShips::e2y[i] + 94 && mY + 94 > EnemyShips::e2y[i]) {
            if (EnemyShips::e2hp[i] > 0) {
                EnemyShips::e2hp[i] -= 2 + level;
                health -= 2 + level;
                State::healthUpdate = true;
            }
        }
        //ship 3
        if (mX + width1 < EnemyShips::e3x[i] + 66 && mX + width2 > EnemyShips::e3x[i] + 27 
			&& mY < EnemyShips::e3y[i] + 94 && mY + 94 > EnemyShips::e3y[i]) {
            if (EnemyShips::e3hp[i] > 0) {
                EnemyShips::e3hp[i] -= 2 + level;
                health -= 2 + level;
                State::healthUpdate = true;
            }
        }
        //ship 4
        if (mX + width1 < EnemyShips::e4x[i] + 87 && mX + width2 > EnemyShips::e4x[i] + 6 
			&& mY < EnemyShips::e4y[i] + 94 && mY + 94 > EnemyShips::e4y[i]) {
            if (EnemyShips::e4hp[i] > 0) {
                EnemyShips::e4hp[i] -= 2 + level;
                health -= 2 + level;
                State::healthUpdate = true;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        //ship 5
        if (mX + width1 < EnemyShips::e5x[i] + 71 && mX + width2 > EnemyShips::e5x[i] + 22 
			&& mY < EnemyShips::e5y[i] + 94 && mY + 94 > EnemyShips::e5y[i]) {
            if (EnemyShips::e5hp[i] > 0) {
                EnemyShips::e5hp[i] -= 2 + level;
                health -= 2 + level;
                State::healthUpdate = true;
            }
        }
        //ship 6
        if (mX + width1 < EnemyShips::e6x[i] + 81 && mX + width2 > EnemyShips::e6x[i] + 12 
			&& mY < EnemyShips::e6y[i] + 94 && mY + 94 > EnemyShips::e6y[i]) {
            if (EnemyShips::e6hp[i] > 0) {
                EnemyShips::e6hp[i] -= 2 + level;
                health -= 2 + level;
                State::healthUpdate = true;
            }
        }
        //ship 7
        if (mX + width1 < EnemyShips::e7x[i] + 86 && mX + width2 > EnemyShips::e7x[i] + 7 
			&& mY < EnemyShips::e7y[i] + 94 && mY + 94 > EnemyShips::e7y[i]) {
            if (EnemyShips::e7hp[i] > 0) {
                EnemyShips::e7hp[i] -= 2 + level;
                health -= 2 + level;
                State::healthUpdate = true;
            }
        }
        //ship 8
        if (mX + width1 < EnemyShips::e8x[i] + 86 && mX + width2 > EnemyShips::e8x[i] + 6 
			&& mY < EnemyShips::e8y[i] + 94 && mY + 94 > EnemyShips::e8y[i]) {
            if (EnemyShips::e8hp[i] > 0) {
                EnemyShips::e8hp[i] -= 2 + level;
                health -= 2 + level;
                State::healthUpdate = true;
            }
        }
    }
    //ship 9
    if (mX + width1 < EnemyShips::e9x[0] + 142 && mX + width2 > EnemyShips::e9x[0] 
	    && mY < EnemyShips::e9y[0] + 240 && mY + 94 > EnemyShips::e9y[0]) {
        if (EnemyShips::e9hp[0] > 0) {
            EnemyShips::e9hp[0] -= 2 + level;
            health -= 2 + level;
            State::healthUpdate = true;
        }
    }
    //ship 10
    if (mX + width1 < EnemyShips::e10x[0] + 150 && mX + width2 > EnemyShips::e10x[0] 
	    && mY < EnemyShips::e10y[0] + 240 && mY + 94 > EnemyShips::e10y[0]) {
        if (EnemyShips::e10hp[0] > 0) {
            EnemyShips::e10hp[0] -= 2 + level;
            health -= 2 + level;
            State::healthUpdate = true;
        }
    }
}
void Rank() {
    assert(xp >= 0);
    const double inputVal = xp / 50;
    rank = (int) (1.38 * sqrt(inputVal) + 1);
    if (rank > 20) {
        rank = 20;
    }
}
void HealthRegen() {
    if (Counter::healthRegen >= 150) {
        Counter::healthRegen = 0;
        health += 1;
        State::healthUpdate = true;
    }
}
bool CreateMove() {
    return CurrentScreen == ScreenEndless || CurrentScreen == ScreenStoryBattle1
                || CurrentScreen == ScreenStoryBattle2 || CurrentScreen == ScreenStoryBattle4
                || CurrentScreen == ScreenStoryBattle5 || CurrentScreen == ScreenStoryBattle6;
}
void OnTimer() {
    //called 30 times per second - 1800=1min - 10000=5min 36sec
    Rank();
    SoundSwitch();
    if (State::sound) {
        Counter::sound += 1;
    }
    if (!State::pause) {
        if (CreateMove()) {
            Counter::bulletTime += 1;
            Counter::shipMove += 1;
            DoEnemyShipMove();
            Counter::bulletMove += 1;
            DoEnemyShipShoot();
            if (health < possibleHealth / 2) {
                Counter::healthRegen += 1;
            } else {
                Counter::healthRegen = 0;
            }
            HealthRegen();
            BulletTime();
            HealthBar();
            mShipMove();
            EnemyDied();
            ShipCollision();
        } else if (CurrentScreen == ScreenStoryTorture && State::torture) {
            if (Counter::torture == 0) {
                ViewSetxy(imageTorture, -1, -1);
            } else if (Counter::torture == 1) {
                ViewSetxy(imageTorture, 0, 0);
            } else if (Counter::torture == 2) {
                ViewSetxy(imageTorture, -2, -2);
            } else if (Counter::torture == 3) {
                ViewSetxy(imageTorture, -1, -1);
            } else if (Counter::torture == 4) {
                ViewSetxy(imageTorture, -2, 0);
            } else if (Counter::torture == 5) {
                ViewSetxy(imageTorture, 0, -2);
            }
            Counter::hpTorture -= 3;
            Counter::torture += 1;
            if (Counter::torture >= 6) {
                Counter::torture = 0;
            }
            TortureHealth();
        } else if (CurrentScreen == ScreenStoryTorture && !State::torture) {
            Counter::hpTorture += 1;
            TortureHealth();
            TextSetText(textTorture, "");
        }
    }
}
