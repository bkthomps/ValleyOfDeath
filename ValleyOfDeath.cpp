/**
 * Bailey Thompson
 * Valley Of Death (1.1.18)
 * 2 January 2017
 * Info: This is a scrolling shooter iPhone app.
 */
#include "DragonFireSDK.h"
bool sound, UpdateHighscore;
int xp, ship, highscore;
int counter;
bool pause, date, marry;
int health, set, level;
int counter2, counter3, counter4, counter5[10];
int ShipView, mX, mY, newX, newY;
int mBullet1[15], mBullet2[15], mBullet3[15];
int HpCounterTorture;
int e1Bullet1[50];
int e2Bullet1[50];
int e3Bullet1[50];
int e4Bullet1[50];
int e5Bullet1[25], e5Bullet3[25];
int e6Bullet1[25], e6Bullet3[25];
int e7Bullet2[25];
int e8Bullet1[25], e8Bullet2[25], e8Bullet3[25];
int e9Bullet1[5], e9Bullet2[5], e9Bullet3[5];
int e10Bullet1[5], e10Bullet2[5], e10Bullet3[5];
int eShip1[10], eShip2[10], eShip3[10], eShip4[10], eShip5[5], eShip6[5], eShip7[5], eShip8[5], eShip9, eShip10;
int eShipX1[10], eShipX2[10], eShipX3[10], eShipX4[10], eShipX5[5], eShipX6[5], eShipX7[5], eShipX8[5], eShipX9, eShipX10;
int eShipY1[10], eShipY2[10], eShipY3[10], eShipY4[10], eShipY5[5], eShipY6[5], eShipY7[5], eShipY8[5], eShipY9, eShipY10;
int eShip1Health[10], eShip2Health[10], eShip3Health[10], eShip4Health[10], eShip5Health[5];
int eShip6Health[5], eShip7Health[5], eShip8Health[5], eShip9Health, eShip10Health;
int FileSound, FileUpdateHighscore;
int FileXp, FileShip, FileHighscore;
int FileCounter;
char FileBuffer[5];
bool BoolTempNum;
int IntTempNum;
int Mp3Handle;
char font, FontTorture;
int width1, width2, HP, text1, text2, text3;
bool torture;
int CounterTorture, ImageTorture, HpTorture, TextTorture;
int counter8, counter10, counter12;
int r, s2, s3, s4, s5, s6, s7, s8, music;
int PossibleHealth, ShipSpeed, SaveRon, rank;
int BulletXOffset, BulletYOffset, BulletXOffset2, BulletYOffset2, BulletXOffset3, BulletYOffset3;
const int e1BulletXOffset = 43, e1BulletYOffset = 83, e2BulletXOffset = 43, e2BulletYOffset = 94;
const int e3BulletXOffset = 43, e3BulletYOffset = 88, e4BulletXOffset = 43, e4BulletYOffset = 94;
const int e5BulletXOffset = 31, e5BulletYOffset = 71, e5BulletXOffset3 = 54, e5BulletYOffset3 = 71;
const int e6BulletXOffset = 15, e6BulletYOffset = 53, e6BulletXOffset3 = 68, e6BulletYOffset3 = 53;
const int e7BulletXOffset2 = 42, e7BulletYOffset2 = 83;
const int e8BulletXOffset = 12, e8BulletYOffset = 54, e8BulletXOffset2 = 42, e8BulletYOffset2 = 92, e8BulletXOffset3 = 74, e8BulletYOffset3 = 54;
const int e9BulletXOffset = 3, e9BulletYOffset = 83, e9BulletXOffset2 = 66, e9BulletYOffset2 = 230, e9BulletXOffset3 = 130, e9BulletYOffset3 = 83;
const int e10BulletXOffset = 13, e10BulletYOffset = 83, e10BulletXOffset2 = 69, e10BulletYOffset2 = 233, e10BulletXOffset3 = 129, e10BulletYOffset3 = 83;
const int speed = 15, time = 15;
const int SpawnTime = 100, EnemyBaseHealth = 3, EnemyIncreaseHealth = 1, EnemyShootCooldownSpeed = 45, EnemyFlySpeed = 3, EnemyBulletSpeed = 8;
bool HealthUpdate, GoRight;
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
Screen CurrentScreen;
Screen PreviousScreen;

int ContainerPause;
int ContainerMenu;
int ContainerHighscore;
int ContainerEndless;
int ContainerDied;
int ContainerStory1a1;
int ContainerStory1a2;
int ContainerStory1s3;
int ContainerStory1p3;
int ContainerStory1a4;
int ContainerStory1r5;
int ContainerStory1e5;
int ContainerStory2a1;
int ContainerStory2a2;
int ContainerStory2a3;
int ContainerStory2b4;
int ContainerStory2a5;
int ContainerStory2a6;
int ContainerStory2e7;
int ContainerStory2a7;
int ContainerStory3a1;
int ContainerStory3b2;
int ContainerStory3a3;
int ContainerStory3a4;
int ContainerStory3a5;
int ContainerStory3a6;
int ContainerStory3a7;
int ContainerStory3a8;
int ContainerStoryTorture;
int ContainerStory4a1;
int ContainerStory4a2;
int ContainerStory4a3;
int ContainerStory4a4;
int ContainerStory4b5;
int ContainerStory4a6;
int ContainerStory4a7;
int ContainerStory4b7;
int ContainerStory4a8;
int ContainerStory5a1;
int ContainerStory5a2;
int ContainerStory5a3;
int ContainerStory5b4;
int ContainerStory5a5;
int ContainerStory5a6;
int ContainerStory5b6;
int ContainerStory6a1;
int ContainerStory6a2;
int ContainerStory6a3;
int ContainerStory6b3;
int ContainerStory7w1;
int ContainerStory7l1;
int ContainerStory7a2;
int ContainerStory7b2;
int ContainerUnlocks;
int ContainerOptions;
int ContainerDeleteCheckOne;
int ContainerDeleteCheckTwo;

void IntFileToGame() {
    IntTempNum = 0;
    IntTempNum += ((int) FileBuffer[0] - '0') * 10000;
    IntTempNum += ((int) FileBuffer[1] - '0') * 1000;
    IntTempNum += ((int) FileBuffer[2] - '0') * 100;
    IntTempNum += ((int) FileBuffer[3] - '0') * 10;
    IntTempNum += (int) FileBuffer[4] - '0';
}
void BoolFileToGame() {
    BoolTempNum = (FileBuffer[0] == 't') ? (true) : (false);
}
void LoadGame() {
    FileSound = FileOpen("Sound.txt");
    FileUpdateHighscore = FileOpen("UpdateHighscore.txt");
    FileXp = FileOpen("Xp.txt");
    FileShip = FileOpen("Ship.txt");
    FileHighscore = FileOpen("Highscore.txt");
    FileCounter = FileOpen("Counter.txt");
    if (!FileSound) {
        FileSound = FileCreate("Sound.txt");
        sound = true;
    } else {
        FileSound = FileOpen("Sound.txt");
        FileRead(FileSound, FileBuffer, 1);
        BoolFileToGame();
        sound = BoolTempNum;
    }
    if (!FileUpdateHighscore) {
        FileUpdateHighscore = FileCreate("UpdateHighscore.txt");
    } else {
        FileUpdateHighscore = FileOpen("UpdateHighscore.txt");
        FileRead(FileUpdateHighscore, FileBuffer, 1);
        BoolFileToGame();
        UpdateHighscore = BoolTempNum;
    }
    if (!FileXp) {
        FileXp = FileCreate("Xp.txt");
    } else {
        FileXp = FileOpen("Xp.txt");
        FileRead(FileXp, FileBuffer, 5);
        IntFileToGame();
        xp = IntTempNum;
    }
    if (!FileShip) {
        FileShip = FileCreate("Ship.txt");
        ship = 1;
    } else {
        FileShip = FileOpen("Ship.txt");
        FileRead(FileShip, FileBuffer, 5);
        IntFileToGame();
        ship = IntTempNum;
    }
    if (!FileHighscore) {
        FileHighscore = FileCreate("Highscore.txt");
    } else {
        FileHighscore = FileOpen("Highscore.txt");
        FileRead(FileHighscore, FileBuffer, 5);
        IntFileToGame();
        highscore = IntTempNum;
    }
    if (!FileCounter) {
        FileCounter = FileCreate("Counter.txt");
    } else {
        FileCounter = FileOpen("Counter.txt");
        FileRead(FileCounter, FileBuffer, 5);
        IntFileToGame();
        counter = IntTempNum;
    }
    FileClose(FileSound);
    FileClose(FileUpdateHighscore);
    FileClose(FileXp);
    FileClose(FileShip);
    FileClose(FileHighscore);
    FileClose(FileCounter);
}
void Reset() {
    int picture, ship;
    HealthUpdate = true;
    counter2 = 0;
    counter3 = 0;
    mX = 113;
    mY = 380;
    newX = 113;
    newY = 380;
    for (int i = 0; i < 15; i++) {
        ViewSetxy(mBullet1[i], -10, -10);
        ViewSetxy(mBullet2[i], -20, -20);
        ViewSetxy(mBullet3[i], -10, -10);
    }
    for (int i = 0; i < 50; i++) {
        ViewSetxy(e1Bullet1[i], 600, 600);
        ViewSetxy(e2Bullet1[i], 600, 600);
        ViewSetxy(e3Bullet1[i], 600, 600);
        ViewSetxy(e4Bullet1[i], 600, 600);
    }
    for (int i = 0; i < 25; i++) {
        ViewSetxy(e5Bullet1[i], 600, 600);
        ViewSetxy(e5Bullet3[i], 600, 600);
        ViewSetxy(e6Bullet1[i], 600, 600);
        ViewSetxy(e6Bullet3[i], 600, 600);
        ViewSetxy(e7Bullet2[i], 600, 600);
        ViewSetxy(e8Bullet1[i], 600, 600);
        ViewSetxy(e8Bullet2[i], 600, 600);
        ViewSetxy(e8Bullet3[i], 600, 600);
    }
    for (int i = 0; i < 5; i++) {
        ViewSetxy(e9Bullet1[i], 600, 600);
        ViewSetxy(e9Bullet2[i], 600, 600);
        ViewSetxy(e9Bullet3[i], 600, 600);
        ViewSetxy(e10Bullet1[i], 600, 600);
        ViewSetxy(e10Bullet2[i], 600, 600);
        ViewSetxy(e10Bullet3[i], 600, 600);
    }
    for (int i = 0; i < 10; i++) {
        ViewSetxy(eShip1[i], 600, 600);
        ship = (eShip1[i]);
        picture = ImageAdd("Images/eShip_1.png");
        ViewSetImage(ship, picture);
        ViewSetxy(eShip2[i], 600, 600);
        ship = (eShip2[i]);
        picture = ImageAdd("Images/eShip_2.png");
        ViewSetImage(ship, picture);
        ViewSetxy(eShip3[i], 600, 600);
        ship = (eShip3[i]);
        picture = ImageAdd("Images/eShip_3.png");
        ViewSetImage(ship, picture);
        ViewSetxy(eShip4[i], 600, 600);
        ship = (eShip4[i]);
        picture = ImageAdd("Images/eShip_4.png");
        ViewSetImage(ship, picture);
    }
    for (int i = 0; i < 5; i++) {
        ViewSetxy(eShip5[i], 600, 600);
        ship = (eShip5[i]);
        picture = ImageAdd("Images/eShip_5.png");
        ViewSetImage(ship, picture);
        ViewSetxy(eShip6[i], 600, 600);
        ship = (eShip6[i]);
        picture = ImageAdd("Images/eShip_6.png");
        ViewSetImage(ship, picture);
        ViewSetxy(eShip7[i], 600, 600);
        ship = (eShip7[i]);
        picture = ImageAdd("Images/eShip_7.png");
        ViewSetImage(ship, picture);
        ViewSetxy(eShip8[i], 600, 600);
        ship = (eShip8[i]);
        picture = ImageAdd("Images/eShip_8.png");
        ViewSetImage(ship, picture);
    }
    ViewSetxy(eShip9, 600, 600);
    ship = (eShip9);
    picture = ImageAdd("Images/eMini-Boss.png");
    ViewSetImage(ship, picture);
    ViewSetxy(eShip10, 600, 600);
    ship = (eShip10);
    picture = ImageAdd("Images/eBoss.png");
    ViewSetImage(ship, picture);
    health = PossibleHealth;
    HealthUpdate = true;
    pause = false;
}
void ScreenSwitch() {
    ContainerSetVisible(ContainerPause, 0);
    ContainerSetVisible(ContainerMenu, 0);
    ContainerSetVisible(ContainerEndless, 0);
    ContainerSetVisible(ContainerHighscore, 0);
    ContainerSetVisible(ContainerDied, 0);
    ContainerSetVisible(ContainerStory1a1, 0);
    ContainerSetVisible(ContainerStory1a2, 0);
    ContainerSetVisible(ContainerStory1s3, 0);
    ContainerSetVisible(ContainerStory1p3, 0);
    ContainerSetVisible(ContainerStory1a4, 0);
    ContainerSetVisible(ContainerStory1r5, 0);
    ContainerSetVisible(ContainerStory1e5, 0);
    ContainerSetVisible(ContainerStory2a1, 0);
    ContainerSetVisible(ContainerStory2a2, 0);
    ContainerSetVisible(ContainerStory2a3, 0);
    ContainerSetVisible(ContainerStory2b4, 0);
    ContainerSetVisible(ContainerStory2a5, 0);
    ContainerSetVisible(ContainerStory2a6, 0);
    ContainerSetVisible(ContainerStory2e7, 0);
    ContainerSetVisible(ContainerStory2a7, 0);
    ContainerSetVisible(ContainerStory3a1, 0);
    ContainerSetVisible(ContainerStory3b2, 0);
    ContainerSetVisible(ContainerStory3a3, 0);
    ContainerSetVisible(ContainerStory3a4, 0);
    ContainerSetVisible(ContainerStory3a5, 0);
    ContainerSetVisible(ContainerStory3a6, 0);
    ContainerSetVisible(ContainerStory3a7, 0);
    ContainerSetVisible(ContainerStory3a8, 0);
    ContainerSetVisible(ContainerStoryTorture, 0);
    ContainerSetVisible(ContainerStory4a1, 0);
    ContainerSetVisible(ContainerStory4a2, 0);
    ContainerSetVisible(ContainerStory4a3, 0);
    ContainerSetVisible(ContainerStory4a4, 0);
    ContainerSetVisible(ContainerStory4b5, 0);
    ContainerSetVisible(ContainerStory4a6, 0);
    ContainerSetVisible(ContainerStory4a7, 0);
    ContainerSetVisible(ContainerStory4b7, 0);
    ContainerSetVisible(ContainerStory4a8, 0);
    ContainerSetVisible(ContainerStory5a1, 0);
    ContainerSetVisible(ContainerStory5a2, 0);
    ContainerSetVisible(ContainerStory5a3, 0);
    ContainerSetVisible(ContainerStory5b4, 0);
    ContainerSetVisible(ContainerStory5a5, 0);
    ContainerSetVisible(ContainerStory5a6, 0);
    ContainerSetVisible(ContainerStory5b6, 0);
    ContainerSetVisible(ContainerStory6a1, 0);
    ContainerSetVisible(ContainerStory6a2, 0);
    ContainerSetVisible(ContainerStory6a3, 0);
    ContainerSetVisible(ContainerStory6b3, 0);
    ContainerSetVisible(ContainerStory7w1, 0);
    ContainerSetVisible(ContainerStory7l1, 0);
    ContainerSetVisible(ContainerStory7a2, 0);
    ContainerSetVisible(ContainerStory7b2, 0);
    ContainerSetVisible(ContainerUnlocks, 0);
    ContainerSetVisible(ContainerOptions, 0);
    ContainerSetVisible(ContainerDeleteCheckOne, 0);
    ContainerSetVisible(ContainerDeleteCheckTwo, 0);
    switch (CurrentScreen) {
        case ScreenPause:
            ContainerSetVisible(ContainerPause, 1);
            break;
        case ScreenMenu:
            ContainerSetVisible(ContainerMenu, 1);
            break;
        case ScreenHighscore:
            ContainerSetVisible(ContainerHighscore, 1);
            break;
        case ScreenDied:
            ContainerSetVisible(ContainerDied, 1);
            break;
        case ScreenEndless:
            ContainerSetVisible(ContainerEndless, 1);
            break;
        case ScreenStory1a1:
            ContainerSetVisible(ContainerStory1a1, 1);
            break;
        case ScreenStory1a2:
            ContainerSetVisible(ContainerStory1a2, 1);
            break;
        case ScreenStory1s3:
            ContainerSetVisible(ContainerStory1s3, 1);
            break;
        case ScreenStory1p3:
            ContainerSetVisible(ContainerStory1p3, 1);
            break;
        case ScreenStory1a4:
            ContainerSetVisible(ContainerStory1a4, 1);
            break;
        case ScreenStory1r5:
            ContainerSetVisible(ContainerStory1r5, 1);
            break;
        case ScreenStory1e5:
            ContainerSetVisible(ContainerStory1e5, 1);
            break;
        case ScreenStoryBattle1:
            ContainerSetVisible(ContainerEndless, 1);
            break;
        case ScreenStory2a1:
            ContainerSetVisible(ContainerStory2a1, 1);
            break;
        case ScreenStory2a2:
            ContainerSetVisible(ContainerStory2a2, 1);
            break;
        case ScreenStory2a3:
            ContainerSetVisible(ContainerStory2a3, 1);
            break;
        case ScreenStory2b4:
            ContainerSetVisible(ContainerStory2b4, 1);
            break;
        case ScreenStory2a5:
            ContainerSetVisible(ContainerStory2a5, 1);
            break;
        case ScreenStory2a6:
            ContainerSetVisible(ContainerStory2a6, 1);
            break;
        case ScreenStory2e7:
            ContainerSetVisible(ContainerStory2e7, 1);
            break;
        case ScreenStory2a7:
            ContainerSetVisible(ContainerStory2a7, 1);
            break;
        case ScreenStoryBattle2:
            ContainerSetVisible(ContainerEndless, 1);
            break;
        case ScreenStory3a1:
            ContainerSetVisible(ContainerStory3a1, 1);
            break;
        case ScreenStory3b2:
            ContainerSetVisible(ContainerStory3b2, 1);
            break;
        case ScreenStory3a3:
            ContainerSetVisible(ContainerStory3a3, 1);
            break;
        case ScreenStory3a4:
            ContainerSetVisible(ContainerStory3a4, 1);
            break;
        case ScreenStory3a5:
            ContainerSetVisible(ContainerStory3a5, 1);
            break;
        case ScreenStory3a6:
            ContainerSetVisible(ContainerStory3a6, 1);
            break;
        case ScreenStory3a7:
            ContainerSetVisible(ContainerStory3a7, 1);
            break;
        case ScreenStory3a8:
            ContainerSetVisible(ContainerStory3a8, 1);
            break;
        case ScreenStoryTorture:
            int ImageTorturing;
            ImageTorturing = ImageAdd("Images/20HP.png");
            ViewSetImage(HpTorture, ImageTorturing);
            HpCounterTorture = 2000;
            CounterTorture = 0;
            ContainerSetVisible(ContainerStoryTorture, 1);
            break;
        case ScreenStory4a1:
            ContainerSetVisible(ContainerStory4a1, 1);
            break;
        case ScreenStory4a2:
            ContainerSetVisible(ContainerStory4a2, 1);
            break;
        case ScreenStory4a3:
            ContainerSetVisible(ContainerStory4a3, 1);
            break;
        case ScreenStory4a4:
            ContainerSetVisible(ContainerStory4a4, 1);
            break;
        case ScreenStory4b5:
            ContainerSetVisible(ContainerStory4b5, 1);
            break;
        case ScreenStory4a6:
            ContainerSetVisible(ContainerStory4a6, 1);
            break;
        case ScreenStory4a7:
            ContainerSetVisible(ContainerStory4a7, 1);
            break;
        case ScreenStory4b7:
            ContainerSetVisible(ContainerStory4b7, 1);
            break;
        case ScreenStory4a8:
            ContainerSetVisible(ContainerStory4a8, 1);
            break;
        case ScreenStoryBattle4:
            ContainerSetVisible(ContainerEndless, 1);
            break;
        case ScreenStory5a1:
            ContainerSetVisible(ContainerStory5a1, 1);
            break;
        case ScreenStory5a2:
            ContainerSetVisible(ContainerStory5a2, 1);
            break;
        case ScreenStory5a3:
            ContainerSetVisible(ContainerStory5a3, 1);
            break;
        case ScreenStory5b4:
            ContainerSetVisible(ContainerStory5b4, 1);
            break;
        case ScreenStory5a5:
            ContainerSetVisible(ContainerStory5a5, 1);
            break;
        case ScreenStory5a6:
            ContainerSetVisible(ContainerStory5a6, 1);
            break;
        case ScreenStory5b6:
            ContainerSetVisible(ContainerStory5b6, 1);
            break;
        case ScreenStoryBattle5:
            ContainerSetVisible(ContainerEndless, 1);
            break;
        case ScreenStory6a1:
            ContainerSetVisible(ContainerStory6a1, 1);
            break;
        case ScreenStory6a2:
            ContainerSetVisible(ContainerStory6a2, 1);
            break;
        case ScreenStory6a3:
            ContainerSetVisible(ContainerStory6a3, 1);
            break;
        case ScreenStory6b3:
            ContainerSetVisible(ContainerStory6b3, 1);
            break;
        case ScreenStoryBattle6:
            ContainerSetVisible(ContainerEndless, 1);
            break;
        case ScreenStory7w1:
            ContainerSetVisible(ContainerStory7w1, 1);
            break;
        case ScreenStory7l1:
            ContainerSetVisible(ContainerStory7l1, 1);
            break;
        case ScreenStory7a2:
            ContainerSetVisible(ContainerStory7a2, 1);
            break;
        case ScreenStory7b2:
            ContainerSetVisible(ContainerStory7b2, 1);
            break;
        case ScreenUnlocks:
            ContainerSetVisible(ContainerUnlocks, 1);
            break;
        case ScreenOptions:
            ContainerSetVisible(ContainerOptions, 1);
            break;
        case ScreenDeleteCheckOne:
            ContainerSetVisible(ContainerDeleteCheckOne, 1);
            break;
        case ScreenDeleteCheckTwo:
            ContainerSetVisible(ContainerDeleteCheckTwo, 1);
            break;
    }
}

int OnTorture(int id, int event, int x, int y) {
    if (event == 1 || event == 3) {
        torture = !torture;
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
            UpdateHighscore = true;
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
        pause = false;
    }
    return 0;
}
int OnPause(int id, int event, int x, int y) {
    if (event == 1) {
        PreviousScreen = CurrentScreen;
        CurrentScreen = ScreenPause;
        ScreenSwitch();
        pause = true;
    }
    return 0;
}

int OnStoryLevel7(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1) {
            CurrentScreen = ScreenStory7a2;
        } else if (id == 2) {
            if (date && !marry) {
                TextSetText(SaveRon, "\n\nRon: \nThe world will know of your \ngreatness. I will be sure to \ntell your girlfriend that you \nwere a great man.");
            } else if (date && marry) {
                TextSetText(SaveRon, "\n\nRon: \nThe world will know of your \ngreatness. I will be sure to \ntell your wife that you were a \ngreat man.");
            } else if (!date && !marry) {
                TextSetText(SaveRon, "\n\nRon: \nThe world will know of your \ngreatness.");
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
        if (id == 1 && !date) {
            CurrentScreen = ScreenStory5a3;
        } else if (id == 1 && date) {
            CurrentScreen = ScreenStory5a2;
        } else if (id == 2) {
            marry = true;
            CurrentScreen = ScreenStory5a3;
        } else if (id == 8) {
            marry = false;
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
            date = true;
            CurrentScreen = ScreenStory2a3;
        } else if (id == 4) {
            date = false;
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
        if (id == 1) {
            CurrentScreen = ScreenStory1a2;
        } else if (id == 3) {
            CurrentScreen = ScreenStory1s3;
        } else if (id == 4) {
            CurrentScreen = ScreenStory1p3;
        } else if (id == 5) {
            CurrentScreen = ScreenStory1a4;
        } else if (id == 6) {
            CurrentScreen = ScreenStory1r5;
        } else if (id == 7) {
            CurrentScreen = ScreenStory1e5;
        }
        if (id == 8) {
            CurrentScreen = ScreenStoryBattle1;
            ScreenSwitch();
            Reset();
            set = 1;
            level = 1;
        } else {
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
    static const int lift = 10;
    ViewSetxy(ShipView, -200, -200);
    switch (ship) {
        case 1:
            ShipView = ViewAdd(ContainerEndless, "Images/Ship_1.png", -200, -200);
            BulletXOffset = 43;
            BulletYOffset = 11 - lift;
            ShipSpeed = 7;
            PossibleHealth = 20;
            width1 = 9;
            width2 = 76;
            break;
        case 2:
            ShipView = ViewAdd(ContainerEndless, "Images/Ship_2.png", -200, -200);
            BulletXOffset = 43;
            BulletYOffset = 0 - lift;
            ShipSpeed = 7;
            PossibleHealth = 22;
            width1 = 15;
            width2 = 69;
            break;
        case 3:
            ShipView = ViewAdd(ContainerEndless, "Images/Ship_3.png", -200, -200);
            BulletXOffset = 43;
            BulletYOffset = 6 - lift;
            ShipSpeed = 7;
            PossibleHealth = 24;
            width1 = 18;
            width2 = 66;
            break;
        case 4:
            ShipView = ViewAdd(ContainerEndless, "Images/Ship_4.png", -200, -200);
            BulletXOffset = 43;
            BulletYOffset = 0 - lift;
            ShipSpeed = 7;
            PossibleHealth = 26;
            width1 = -3;
            width2 = 87;
            break;
        case 5:
            ShipView = ViewAdd(ContainerEndless, "Images/Ship_5.png", -200, -200);
            BulletXOffset = 31;
            BulletYOffset = 23 - lift;
            BulletXOffset3 = 54;
            BulletYOffset3 = 23 - lift;
            ShipSpeed = 6;
            PossibleHealth = 28;
            width1 = 13;
            width2 = 71;
            break;
        case 6:
            ShipView = ViewAdd(ContainerEndless, "Images/Ship_6.png", -200, -200);
            BulletXOffset = 15;
            BulletYOffset = 41 - lift;
            BulletXOffset3 = 68;
            BulletYOffset3 = 41 - lift;
            ShipSpeed = 6;
            PossibleHealth = 30;
            width1 = 3;
            width2 = 81;
            break;
        case 7:
            ShipView = ViewAdd(ContainerEndless, "Images/Ship_7.png", -200, -200);
            BulletXOffset2 = 42;
            BulletYOffset2 = 11 - lift;
            ShipSpeed = 5;
            PossibleHealth = 32;
            width1 = -2;
            width2 = 86;
            break;
        case 8:
            ShipView = ViewAdd(ContainerEndless, "Images/Ship_8.png", -200, -200);
            BulletXOffset = 12;
            BulletYOffset = 40 - lift;
            BulletXOffset2 = 42;
            BulletYOffset2 = 2 - lift;
            BulletXOffset3 = 74;
            BulletYOffset3 = 40 - lift;
            ShipSpeed = 4;
            PossibleHealth = 34;
            width1 = -3;
            width2 = 86;
            break;
    }
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
        health = PossibleHealth;
        HealthUpdate = true;
        level = 1;
        set = 1;
        CurrentScreen = ScreenEndless;
        ScreenSwitch();
    }
    return 0;
}

int Unlocks(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1 && rank >= 1) {
            ship = 1;
            ShipType();
            CurrentScreen = ScreenMenu;
            ScreenSwitch();
        } else if (id == 2 && rank >= 3) {
            ship = 2;
            ShipType();
            CurrentScreen = ScreenMenu;
            ScreenSwitch();
        } else if (id == 3 && rank >= 5) {
            ship = 3;
            ShipType();
            CurrentScreen = ScreenMenu;
            ScreenSwitch();
        } else if (id == 4 && rank >= 8) {
            ship = 4;
            ShipType();
            CurrentScreen = ScreenMenu;
            ScreenSwitch();
        } else if (id == 5 && rank >= 11) {
            ship = 5;
            ShipType();
            CurrentScreen = ScreenMenu;
            ScreenSwitch();
        } else if (id == 6 && rank >= 14) {
            ship = 6;
            ShipType();
            CurrentScreen = ScreenMenu;
            ScreenSwitch();
        } else if (id == 7 && rank >= 17) {
            ship = 7;
            ShipType();
            CurrentScreen = ScreenMenu;
            ScreenSwitch();
        } else if (id == 8 && rank >= 20) {
            ship = 8;
            ShipType();
            CurrentScreen = ScreenMenu;
            ScreenSwitch();
        }
    }
    return 0;
}
int OnUnlocksMenuTouch(int id, int event, int x, int y) {
    int ImageUnlocks;
    if (event == 3) {
        if (rank == 1) {
            TextSetText(r, "\n\nLevel 1: Ordinary Shipman");
        } else if (rank == 2) {
            TextSetText(r, "\n\nLevel 2: Able Shipman");
        } else if (rank == 3) {
            TextSetText(r, "\n\nLevel 3: Leading Shipman");
        } else if (rank == 4) {
            TextSetText(r, "\n\nLevel 4: Master Shipman");
        } else if (rank == 5) {
            TextSetText(r, "\n\nLevel 5: Petty Officer 2nd \n\tClass");
        } else if (rank == 6) {
            TextSetText(r, "\n\nLevel 6: Petty Officer 1st \n\tClass");
        } else if (rank == 7) {
            TextSetText(r, "\n\nLevel 7: Chief Petty Officer \n\t2nd Class");
        } else if (rank == 8) {
            TextSetText(r, "\n\nLevel 8: Chief Petty Officer \n\t1st Class");
        } else if (rank == 9) {
            TextSetText(r, "\n\nLevel 9: Cadet");
        } else if (rank == 10) {
            TextSetText(r, "\n\nLevel 10: Ensign");
        } else if (rank == 11) {
            TextSetText(r, "\n\nLevel 11: Acting \n\t Sub-Lieutenant");
        } else if (rank == 12) {
            TextSetText(r, "\n\nLevel 12: Sub-Lieutenant");
        } else if (rank == 13) {
            TextSetText(r, "\n\nLevel 13: Lieutenant");
        } else if (rank == 14) {
            TextSetText(r, "\n\nLevel 14: Lieutenant \n\t  Commander");
        } else if (rank == 15) {
            TextSetText(r, "\n\nLevel 15: Commander");
        } else if (rank == 16) {
            TextSetText(r, "\n\nLevel 16: Captain");
        } else if (rank == 17) {
            TextSetText(r, "\n\nLevel 17: Commodore");
        } else if (rank == 18) {
            TextSetText(r, "\n\nLevel 18: Rear-Admiral");
        } else if (rank == 19) {
            TextSetText(r, "\n\nLevel 19: Vice-Admiral");
        } else if (rank == 20) {
            TextSetText(r, "\n\nLevel 20: Admiral");
        }
        ImageUnlocks = (rank >= 3) ? (ImageAdd("Unlocks/UnShip_2.png")) : (ImageAdd("Unlocks/LckShip_2.png"));
        ViewSetImage(s2, ImageUnlocks);
        ImageUnlocks = (rank >= 5) ? (ImageAdd("Unlocks/UnShip_3.png")) : (ImageAdd("Unlocks/LckShip_3.png"));
        ViewSetImage(s3, ImageUnlocks);
        ImageUnlocks = (rank >= 8) ? (ImageAdd("Unlocks/UnShip_4.png")) : (ImageAdd("Unlocks/LckShip_4.png"));
        ViewSetImage(s4, ImageUnlocks);
        ImageUnlocks = (rank >= 11) ? (ImageAdd("Unlocks/UnShip_5.png")) : (ImageAdd("Unlocks/LckShip_5.png"));
        ViewSetImage(s5, ImageUnlocks);
        ImageUnlocks = (rank >= 14) ? (ImageAdd("Unlocks/UnShip_6.png")) : (ImageAdd("Unlocks/LckShip_6.png"));
        ViewSetImage(s6, ImageUnlocks);
        ImageUnlocks = (rank >= 17) ? (ImageAdd("Unlocks/UnShip_7.png")) : (ImageAdd("Unlocks/LckShip_7.png"));
        ViewSetImage(s7, ImageUnlocks);
        ImageUnlocks = (rank >= 20) ? (ImageAdd("Unlocks/UnShip_8.png")) : (ImageAdd("Unlocks/LckShip_8.png"));
        ViewSetImage(s8, ImageUnlocks);
        CurrentScreen = ScreenUnlocks;
        ScreenSwitch();
    }
    return 0;
}

int Options(int id, int event, int x, int y) {
    int ImageMusic;
    if (event == 3 && id == 1) {
        if (sound) {
            ImageMusic = ImageAdd("Unlocks/MusicOff.png");
            ViewSetImage(music, ImageMusic);
            sound = false;
            Mp3Stop();
        } else {
            ImageMusic = ImageAdd("Unlocks/MusicOn.png");
            ViewSetImage(music, ImageMusic);
            sound = true;
            if (counter >= 1 && counter < 7000) {
                counter = 7000;
            } else if (counter >= 7000 && counter < 13000) {
                counter = 13000;
            } else if (counter >= 13000 && counter < 19000) {
                counter = 19000;
            } else if (counter >= 19000 && counter < 27000) {
                counter = 27000;
            } else if (counter >= 27000 && counter < 34000) {
                counter = 34000;
            } else if (counter >= 34000 && counter < 42000) {
                counter = 42000;
            } else if (counter >= 42000 && counter < 49000) {
                counter = 49000;
            } else if (counter >= 49000 && counter < 55000) {
                counter = 55000;
            } else if (counter >= 55000 && counter < 61000) {
                counter = 61000;
            } else if (counter >= 61000 && counter < 67000) {
                counter = 67000;
            } else if (counter >= 67000 && counter < 73000) {
                counter = 73000;
            } else if (counter >= 73000 && counter < 79000) {
                counter = 79000;
            } else if (counter >= 79000) {
                counter = 1;
            }
        }
    } else if (event == 3 && id == 2) {
        CurrentScreen = ScreenDeleteCheckOne;
        ScreenSwitch();
    } else if (event == 3 && id == 3) {
        CurrentScreen = ScreenDeleteCheckTwo;
        ScreenSwitch();
    } else if (event == 3 && id == 4) {
        xp = 0;
        ship = 1;
        highscore = 0;
        ShipType();
        CurrentScreen = ScreenMenu;
        ScreenSwitch();
    } else if (event == 3 && id == 5) {
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
    ContainerPause = ContainerAdd(0, 0, 0);
    ContainerMenu = ContainerAdd(0, 0, 0);
    ContainerHighscore = ContainerAdd(0, 0, 0);
    ContainerEndless = ContainerAdd(0, 0, 0);
    ContainerDied = ContainerAdd(0, 0, 0);
    ContainerStory1a1 = ContainerAdd(0, 0, 0);
    ContainerStory1a2 = ContainerAdd(0, 0, 0);
    ContainerStory1s3 = ContainerAdd(0, 0, 0);
    ContainerStory1p3 = ContainerAdd(0, 0, 0);
    ContainerStory1a4 = ContainerAdd(0, 0, 0);
    ContainerStory1r5 = ContainerAdd(0, 0, 0);
    ContainerStory1e5 = ContainerAdd(0, 0, 0);
    ContainerStory2a1 = ContainerAdd(0, 0, 0);
    ContainerStory2a2 = ContainerAdd(0, 0, 0);
    ContainerStory2a3 = ContainerAdd(0, 0, 0);
    ContainerStory2b4 = ContainerAdd(0, 0, 0);
    ContainerStory2a5 = ContainerAdd(0, 0, 0);
    ContainerStory2a6 = ContainerAdd(0, 0, 0);
    ContainerStory2e7 = ContainerAdd(0, 0, 0);
    ContainerStory2a7 = ContainerAdd(0, 0, 0);
    ContainerStory3a1 = ContainerAdd(0, 0, 0);
    ContainerStory3b2 = ContainerAdd(0, 0, 0);
    ContainerStory3a3 = ContainerAdd(0, 0, 0);
    ContainerStory3a4 = ContainerAdd(0, 0, 0);
    ContainerStory3a5 = ContainerAdd(0, 0, 0);
    ContainerStory3a6 = ContainerAdd(0, 0, 0);
    ContainerStory3a7 = ContainerAdd(0, 0, 0);
    ContainerStory3a8 = ContainerAdd(0, 0, 0);
    ContainerStoryTorture = ContainerAdd(0, 0, 0);
    ContainerStory4a1 = ContainerAdd(0, 0, 0);
    ContainerStory4a2 = ContainerAdd(0, 0, 0);
    ContainerStory4a3 = ContainerAdd(0, 0, 0);
    ContainerStory4a4 = ContainerAdd(0, 0, 0);
    ContainerStory4b5 = ContainerAdd(0, 0, 0);
    ContainerStory4a6 = ContainerAdd(0, 0, 0);
    ContainerStory4a7 = ContainerAdd(0, 0, 0);
    ContainerStory4b7 = ContainerAdd(0, 0, 0);
    ContainerStory4a8 = ContainerAdd(0, 0, 0);
    ContainerStory5a1 = ContainerAdd(0, 0, 0);
    ContainerStory5a2 = ContainerAdd(0, 0, 0);
    ContainerStory5a3 = ContainerAdd(0, 0, 0);
    ContainerStory5b4 = ContainerAdd(0, 0, 0);
    ContainerStory5a5 = ContainerAdd(0, 0, 0);
    ContainerStory5a6 = ContainerAdd(0, 0, 0);
    ContainerStory5b6 = ContainerAdd(0, 0, 0);
    ContainerStory6a1 = ContainerAdd(0, 0, 0);
    ContainerStory6a2 = ContainerAdd(0, 0, 0);
    ContainerStory6a3 = ContainerAdd(0, 0, 0);
    ContainerStory6b3 = ContainerAdd(0, 0, 0);
    ContainerStory7w1 = ContainerAdd(0, 0, 0);
    ContainerStory7l1 = ContainerAdd(0, 0, 0);
    ContainerStory7a2 = ContainerAdd(0, 0, 0);
    ContainerStory7b2 = ContainerAdd(0, 0, 0);
    ContainerUnlocks = ContainerAdd(0, 0, 0);
    ContainerOptions = ContainerAdd(0, 0, 0);
    ContainerDeleteCheckOne = ContainerAdd(0, 0, 0);
    ContainerDeleteCheckTwo = ContainerAdd(0, 0, 0);
}
void ContainerSixSeven() {
    //populate ContainerStory6a1
    ViewAdd(ContainerStory6a1, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory6a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory6a1, "Images/btnOkBig.png", 20, 380, OnStoryLevel6, 1);
    TextAdd(ContainerStory6a1, 0, 0, "\n\nRon: \nGreat work, now go kill the \nenemy admiral!", font);
    //populate ContainerStory6a2
    ViewAdd(ContainerStory6a2, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory6a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory6a2, "Images/btnLaugh.png", 20, 380, OnStoryLevel6, 2);
    ViewAdd(ContainerStory6a2, "Images/btnSo.png", 170, 380, OnStoryLevel6, 3);
    TextAdd(ContainerStory6a2, 0, 0, "\n\nAdmiral Skerbowh: \nYou will never be able to \ndefeat me. I am simply", font);
    TextAdd(ContainerStory6a2, 0, 0, "\n\n\n\n\nsmarter, stronger, faster, and \nmore powerful than you.", font);
    //populate ContainerStory6a3
    ViewAdd(ContainerStory6a3, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory6a3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory6a3, "Images/btnOkSmall.png", 20, 380, OnStoryLevel6, 4);
    ViewAdd(ContainerStory6a3, "Images/btnLaugh.png", 170, 380, OnStoryLevel6, 4);
    TextAdd(ContainerStory6a3, 0, 0, "\n\nAdmiral Skerbowh: \nYou laugh in the face of \ndeath? I laugh at your", font);
    TextAdd(ContainerStory6a3, 0, 0, "\n\n\n\n\nconfidence; however, you \ntruly cannot believe that you \nmay emerge victorious.", font);
    //populate ContainerStory6b3
    ViewAdd(ContainerStory6b3, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory6b3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory6b3, "Images/btnOkSmall.png", 20, 380, OnStoryLevel6, 4);
    ViewAdd(ContainerStory6b3, "Images/btnLaugh.png", 170, 380, OnStoryLevel6, 4);
    TextAdd(ContainerStory6b3, 0, 0, "\n\nAdmiral Skerbowh: \nSo... You aren't intelligent \nenough to comprehend your", font);
    TextAdd(ContainerStory6b3, 0, 0, "\n\n\n\n\ncertain and eventual death.", font);
    //populate ContainerStory7w1
    ViewAdd(ContainerStory7w1, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory7w1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory7w1, "Images/btnOkBig.png", 20, 380, OnStoryLevel7, 3);
    TextAdd(ContainerStory7w1, 0, 0, "\n\nRon: \nYou defeated the enemy \nadmiral. The world will know \nof your greatness.", font);
    //populate ContainerStory7l1
    ViewAdd(ContainerStory7l1, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory7l1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory7l1, "Images/btnMyself.png", 20, 380, OnStoryLevel7, 1);
    ViewAdd(ContainerStory7l1, "Images/btnRon.png", 170, 380, OnStoryLevel7, 2);
    TextAdd(ContainerStory7l1, 0, 0, "\n\nAlex: \nMy ship has sustained critical \ndamage. Every single escape \npod other than one has been", font);
    TextAdd(ContainerStory7l1, 0, 0, "\n\n\n\n\n\ntaken or destroyed. Should I \nsave myself or Ron?", font);
    //populate ContainerStory7a2
    ViewAdd(ContainerStory7a2, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory7a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory7a2, "Images/btnOkBig.png", 20, 380, OnStoryLevel7, 3);
    TextAdd(ContainerStory7a2, 0, 0, "\n\nExecutioner: \nYou are being executed for \ntreason since you abandoned \nyour ship and crew to die.", font);
    //populate ContainerStory7b2
    ViewAdd(ContainerStory7b2, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory7b2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory7b2, "Images/btnOkBig.png", 20, 380, OnStoryLevel7, 3);
    SaveRon = TextAdd(ContainerStory7b2, 0, 0, "", font);
}
void ContainerFive() {
    //populate ContainerStory5a1
    ViewAdd(ContainerStory5a1, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory5a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory5a1, "Images/btnOkSmall.png", 20, 380, OnStoryLevel5, 1);
    ViewAdd(ContainerStory5a1, "Images/btnThanks.png", 170, 380, OnStoryLevel5, 1);
    TextAdd(ContainerStory5a1, 0, 0, "\n\nCommodore Bailey: \nCongratulations on your way \nback. For your great action", font);
    TextAdd(ContainerStory5a1, 0, 0, "\n\n\n\n\nout there, you have become \npilot of your own ship named \nICC Kepler.", font);
    //populate ContainerStory5a2
    ViewAdd(ContainerStory5a2, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory5a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory5a2, "Images/btnYes.png", 20, 380, OnStoryLevel5, 2);
    ViewAdd(ContainerStory5a2, "Images/btnNo.png", 170, 380, OnStoryLevel5, 8);
    TextAdd(ContainerStory5a2, 0, 0, "\n\nBecca: \nWill you marry me?", font);
    //populate ContainerStory5a3
    ViewAdd(ContainerStory5a3, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory5a3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory5a3, "Images/btnNo.png", 20, 380, OnStoryLevel5, 3);
    ViewAdd(ContainerStory5a3, "Images/btnOkSmall.png", 170, 380, OnStoryLevel5, 4);
    TextAdd(ContainerStory5a3, 0, 0, "\n\nRon: \nWe located the escaped \nenemy. He is an admiral so \nhe is well guarded, killing him", font);
    TextAdd(ContainerStory5a3, 0, 0, "\n\n\n\n\n\nwill be no easy feat. I will \ncome with you since I myself \nknow where the enemy \nadmiral is.", font);
    //populate ContainerStory5b4
    ViewAdd(ContainerStory5b4, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory5b4, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory5b4, "Images/btnOkSmall.png", 20, 380, OnStoryLevel5, 4);
    ViewAdd(ContainerStory5b4, "Images/btnSorry.png", 170, 380, OnStoryLevel5, 4);
    TextAdd(ContainerStory5b4, 0, 0, "\n\nRon: \nFederation orders, sorry \nmate.", font);
    //populate ContainerStory5a5
    ViewAdd(ContainerStory5a5, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory5a5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory5a5, "Images/btnAround.png", 20, 380, OnStoryLevel5, 5);
    ViewAdd(ContainerStory5a5, "Images/btnAttack.png", 170, 380, OnStoryLevel5, 6);
    TextAdd(ContainerStory5a5, 0, 0, "\n\nRon: \nThere's a whole platoon of \nships. Do you go around and \ntry to avoid them, or do you", font);
    TextAdd(ContainerStory5a5, 0, 0, "\n\n\n\n\n\nattack?", font);
    //populate ContainerStory5a6
    ViewAdd(ContainerStory5a6, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory5a6, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory5a6, "Images/btnOkBig.png", 20, 380, OnStoryLevel5, 7);
    TextAdd(ContainerStory5a6, 0, 0, "\n\nRon: \nThe ships see you before you \nare even able to go around \nand attack.", font);
    //populate ContainerStory5b6
    ViewAdd(ContainerStory5b6, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory5b6, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory5b6, "Images/btnOkBig.png", 20, 380, OnStoryLevel5, 7);
    TextAdd(ContainerStory5b6, 0, 0, "\n\nRon: \nAttacking the ships.", font);
}
void ContainerFour() {
    //populate ContainerStory4a1
    ViewAdd(ContainerStory4a1, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory4a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory4a1, "Images/btnTakeGun.png", 20, 380, OnStoryLevel4, 2);
    ViewAdd(ContainerStory4a1, "Images/btnDoNothing.png", 170, 380, OnStoryLevel4, 1);
    TextAdd(ContainerStory4a1, 0, 0, "\n\nEnemy: \nNow to torture you too.", font);
    //populate ContainerStory4a2
    ViewAdd(ContainerStory4a2, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory4a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory4a2, "Images/btnShoot.png", 20, 380, OnStoryLevel4, 3);
    ViewAdd(ContainerStory4a2, "Images/btnDoNothing.png", 170, 380, OnStoryLevel4, 1);
    TextAdd(ContainerStory4a2, 0, 0, "\n\nEnemy: \nYou wouldn't dare shoot!", font);
    //populate ContainerStory4a3
    ViewAdd(ContainerStory4a3, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory4a3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory4a3, "Images/btnOkBig.png", 20, 380, OnStoryLevel4, 4);
    TextAdd(ContainerStory4a3, 0, 0, "\n\nAlex: \nHe escaped with an escape \npod!", font);
    //populate ContainerStory4a4
    ViewAdd(ContainerStory4a4, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory4a4, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory4a4, "Images/btnEnemy.png", 20, 380, OnStoryLevel4, 5);
    ViewAdd(ContainerStory4a4, "Images/btnMine.png", 170, 380, OnStoryLevel4, 6);
    TextAdd(ContainerStory4a4, 0, 0, "\n\nAlly: \nYou need to get back. Luckily, \nmy radio signal reaches you. \nYou can either take the", font);
    TextAdd(ContainerStory4a4, 0, 0, "\n\n\n\n\n\nenemy ship or try to get back to yours. Also, if you make it back", font);
    TextAdd(ContainerStory4a4, 0, 0, "\n\n\n\n\n\n\nto your ship, you'll be in \ntemporary command.", font);
    //populate ContainerStory4b5
    ViewAdd(ContainerStory4b5, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory4b5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory4b5, "Images/btnOkBig.png", 20, 380, OnStoryLevel4, 6);
    TextAdd(ContainerStory4b5, 0, 0, "\n\nLieutenant Dan: \nThe enemy ship you were \nflying broke down. Luckily,", font);
    TextAdd(ContainerStory4b5, 0, 0, "\n\n\n\n\nthe crew and I came to save \nyou.", font);
    //populate ContainerStory4a6
    ViewAdd(ContainerStory4a6, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory4a6, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory4a6, "Images/btnContact.png", 20, 380, OnStoryLevel4, 7);
    ViewAdd(ContainerStory4a6, "Images/btnShoot.png", 170, 380, OnStoryLevel4, 8);
    TextAdd(ContainerStory4a6, 0, 0, "\n\nLieutenant Dan: \nYou are in temporary \ncommand. There's ships up \nahead; do you contact it to", font);
    TextAdd(ContainerStory4a6, 0, 0, "\n\n\n\n\n\nsee if it's friendly or do you \nshoot at it? There's no way \naround.", font);
    //populate ContainerStory4a7
    ViewAdd(ContainerStory4a7, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory4a7, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory4a7, "Images/btnOkBig.png", 20, 380, OnStoryLevel4, 9);
    TextAdd(ContainerStory4a7, 0, 0, "\n\nLieutenant Dan: \nThe ships say they are \nfriendly, so we went around \nthem.", font);
    //populate ContainerStory4b7
    ViewAdd(ContainerStory4b7, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory4b7, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory4b7, "Images/btnOkBig.png", 20, 380, OnStoryLevel4, 10);
    TextAdd(ContainerStory4b7, 0, 0, "\n\nLieutenant Dan: \nYou shoot at the ships.", font);
    //populate ContainerStory4a8
    ViewAdd(ContainerStory4a8, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory4a8, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory4a8, "Images/btnOkBig.png", 20, 380, OnStoryLevel4, 10);
    TextAdd(ContainerStory4a8, 0, 0, "\n\nLieutenant Dan: \nThe ships followed you and \nattack.", font);
}
void ContainerThree() {
    //populate ContainerStory3a1
    ViewAdd(ContainerStory3a1, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory3a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory3a1, "Images/btnOkSmall.png", 20, 380, OnStoryLevel3, 2);
    ViewAdd(ContainerStory3a1, "Images/btnNo.png", 170, 380, OnStoryLevel3, 1);
    TextAdd(ContainerStory3a1, 0, 0, "\n\nCaptain: \nWe should check the \nwreckage.", font);
    //populate ContainerStory3b2
    ViewAdd(ContainerStory3b2, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory3b2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory3b2, "Images/btnSorry.png", 20, 380, OnStoryLevel3, 2);
    ViewAdd(ContainerStory3b2, "Images/btnOkSmall.png", 170, 380, OnStoryLevel3, 2);
    TextAdd(ContainerStory3b2, 0, 0, "\n\nCaptain: \nI'm captain and I say we will, \nso we will.", font);
    //populate ContainerStory3a3
    ViewAdd(ContainerStory3a3, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory3a3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory3a3, "Images/btnOkSmall.png", 20, 380, OnStoryLevel3, 3);
    ViewAdd(ContainerStory3a3, "Images/btnNever.png", 170, 380, OnStoryLevel3, 3);
    TextAdd(ContainerStory3a3, 0, 0, "\n\nEnemy: \nHands up!", font);
    //populate ContainerStory3a4
    ViewAdd(ContainerStory3a4, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory3a4, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory3a4, "Images/btnWhereAreWe.png", 20, 380, OnStoryLevel3, 4);
    ViewAdd(ContainerStory3a4, "Images/btnWhereCaptain.png", 170, 380, OnStoryLevel3, 4);
    TextAdd(ContainerStory3a4, 0, 0, "\n\nEnemy: \nSorry for knocking you out, it \nwas the only way to bring \nyou here.", font);
    //populate ContainerStory3a5
    ViewAdd(ContainerStory3a5, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory3a5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory3a5, "Images/btnYes.png", 20, 380, OnStoryLevel3, 5);
    ViewAdd(ContainerStory3a5, "Images/btnNo.png", 170, 380, OnStoryLevel3, 5);
    TextAdd(ContainerStory3a5, 0, 0, "\n\nEnemy: \nAre you familiar with torture?", font);
    //populate ContainerStory3a6
    ViewAdd(ContainerStory3a6, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory3a6, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory3a6, "Images/btnOkSmall.png", 20, 380, OnStoryLevel3, 6);
    ViewAdd(ContainerStory3a6, "Images/btnSo.png", 170, 380, OnStoryLevel3, 6);
    TextAdd(ContainerStory3a6, 0, 0, "\n\nEnemy: \nTorture is what caused world \nwar 3 on your home planet: \nEarth.", font);
    //populate ContainerStory3a7
    ViewAdd(ContainerStory3a7, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory3a7, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory3a7, "Images/btnNo!.png", 20, 380, OnStoryLevel3, 7);
    ViewAdd(ContainerStory3a7, "Images/btnOkSmall.png", 170, 380, OnStoryLevel3, 7);
    TextAdd(ContainerStory3a7, 0, 0, "\n\nEnemy: \nI will force you to torture your \ncaptain, hopefully causing a \nwar in the process.", font);
    //populate ContainerStory3a8
    ViewAdd(ContainerStory3a8, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory3a8, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory3a8, "Images/btnNo!.png", 20, 380, OnStoryLevel3, 8);
    ViewAdd(ContainerStory3a8, "Images/btnOkSmall.png", 170, 380, OnStoryLevel3, 8);
    TextAdd(ContainerStory3a8, 0, 0, "\n\nEnemy: \nI will wait for you to torture \nhim until you do. There's \nnothing you can do about it.", font);
    //populate ContainerStoryTorture
    TouchAdd(ContainerStoryTorture, 0, 0, 320, 568, OnTorture, 1);
    ImageTorture = ViewAdd(ContainerStoryTorture, "Images/TortureModeOne.png", -2, -2);
    ViewAdd(ContainerStoryTorture, "Images/Pause.png", 270, 20, OnPause, 1);
    HpTorture = ViewAdd(ContainerStoryTorture, "Images/20HP.png", 20, 20);
    //ViewAdd(ContainerStoryTorture, "Images/infToggle.png", 20, 380);
    TextTorture = TextAdd(ContainerStoryTorture, 70, 0, "", FontTorture);
}
void ContainerTwo() {
    //populate ContainerStory2a1
    ViewAdd(ContainerStory2a1, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory2a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory2a1, "Images/btnOkSmall.png", 20, 380, OnStoryLevel2, 1);
    ViewAdd(ContainerStory2a1, "Images/btnThanks.png", 170, 380, OnStoryLevel2, 1);
    TextAdd(ContainerStory2a1, 0, 0, "\n\nTeacher: \nThis test was designed to \ndetermine how well cadets \nwould respond to stressful", font);
    TextAdd(ContainerStory2a1, 0, 0, "\n\n\n\n\n\nsituations. You passed and \nhave been deemed fit for \nduty.", font);
    //populate ContainerStory2a2
    ViewAdd(ContainerStory2a2, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory2a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory2a2, "Images/btnSure.png", 20, 380, OnStoryLevel2, 3);
    ViewAdd(ContainerStory2a2, "Images/btnNo.png", 170, 380, OnStoryLevel2, 4);
    TextAdd(ContainerStory2a2, 0, 0, "\n\nBecca: \nI heard you're the new soldier \nin town. Do you want to go \nout to town with me?", font);
    //populate ContainerStory2a3
    ViewAdd(ContainerStory2a3, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory2a3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory2a3, "Images/btnYes.png", 20, 380, OnStoryLevel2, 5);
    ViewAdd(ContainerStory2a3, "Images/btnNo.png", 170, 380, OnStoryLevel2, 6);
    TextAdd(ContainerStory2a3, 0, 0, "\n\nCaptain: \nSon, you have a bright future. \nWould you like to join me on \nmy voyages?", font);
    //populate ContainerStory2b4
    ViewAdd(ContainerStory2b4, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory2b4, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory2b4, "Images/btnOkSmall.png", 20, 380, OnStoryLevel2, 7);
    ViewAdd(ContainerStory2b4, "Images/btnSorry.png", 170, 380, OnStoryLevel2, 7);
    TextAdd(ContainerStory2b4, 0, 0, "\n\nCaptain: \nFederation orders, you have \nto do it.", font);
    //populate ContainerStory2a5
    ViewAdd(ContainerStory2a5, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory2a5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory2a5, "Images/btnOkBig.png", 20, 380, OnStoryLevel2, 8);
    TextAdd(ContainerStory2a5, 0, 0, "\n\nCaptain: \nPrepare your items, we are \nleaving tomorrow.", font);
    //populate ContainerStory2a6
    ViewAdd(ContainerStory2a6, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory2a6, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory2a6, "Images/btnEngage.png", 20, 380, OnStoryLevel2, 9);
    ViewAdd(ContainerStory2a6, "Images/btnAround.png", 170, 380, OnStoryLevel2, 10);
    TextAdd(ContainerStory2a6, 0, 0, "\n\nCaptain: \nThere's ships up ahead. \nShould we engage or go \naround?", font);
    //populate ContainerStory2e7
    ViewAdd(ContainerStory2e7, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory2e7, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory2e7, "Images/btnOkBig.png", 20, 380, OnStoryLevel2, 11);
    TextAdd(ContainerStory2e7, 0, 0, "\n\nCaptain: \nHave fun shooting!", font);
    //populate ContainerStory2a7
    ViewAdd(ContainerStory2a7, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory2a7, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory2a7, "Images/btnOkBig.png", 20, 380, OnStoryLevel2, 11);
    TextAdd(ContainerStory2a7, 0, 0, "\n\nCaptain: \nThe ships noticed us and are \nattacking!", font);
}
void ContainerOne() {
    //populate ContainerHighscore
    ViewAdd(ContainerHighscore, "Images/MenuPause.png", 0, 0);
    ViewAdd(ContainerHighscore, "Images/btnOkBig.png", 20, 380, OnHighscore, 1);
    text1 = TextAdd(ContainerHighscore, 20, 0, "", font);
    text2 = TextAdd(ContainerHighscore, 20, 0, "", font);
    text3 = TextAdd(ContainerHighscore, 20, 0, "", font);
    //populate ContainerPause
    ViewAdd(ContainerPause, "Images/MenuPause.png", 0, 0);
    ViewAdd(ContainerPause, "Images/ReturnToMenu.png", 20, 120, OnReturnToMenu, 1);
    ViewAdd(ContainerPause, "Images/Resume.png", 20, 210, OnResume, 1);
    //populate ContainerEndless
    ViewAdd(ContainerEndless, "Images/Background.png", 0, 0, OnBattleTouch, 1);
    ViewAdd(ContainerEndless, "Images/Pause.png", 270, 20, OnPause, 1);
    HP = ViewAdd(ContainerEndless, "Images/20HP.png", 20, 20);
    //player bullets
    for (int i = 0; i < 15; i++) {
        mBullet1[i] = ViewAdd(ContainerEndless, "Images/Bullet.png", -10, -10);
        mBullet2[i] = ViewAdd(ContainerEndless, "Images/Rocket.png", -20, -20);
        mBullet3[i] = ViewAdd(ContainerEndless, "Images/Bullet.png", -10, -10);
    }
    //enemy bullets
    for (int i = 0; i < 50; i++) {
        e1Bullet1[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e2Bullet1[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e3Bullet1[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e4Bullet1[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
    }
    for (int i = 0; i < 25; i++) {
        e5Bullet1[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e5Bullet3[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e6Bullet1[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e6Bullet3[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e7Bullet2[i] = ViewAdd(ContainerEndless, "Images/eRocket.png", 600, 600);
        e8Bullet1[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e8Bullet2[i] = ViewAdd(ContainerEndless, "Images/eRocket.png", 600, 600);
        e8Bullet3[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
    }
    for (int i = 0; i < 5; i++) {
        e9Bullet1[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e9Bullet2[i] = ViewAdd(ContainerEndless, "Images/eRocket.png", 600, 600);
        e9Bullet3[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e10Bullet1[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e10Bullet2[i] = ViewAdd(ContainerEndless, "Images/eRocket.png", 600, 600);
        e10Bullet3[i] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
    }
    //ships
    for (int i = 0; i < 10; i++) {
        eShip1[i] = ViewAdd(ContainerEndless, "Images/eShip_1.png", 600, 600);
        eShip2[i] = ViewAdd(ContainerEndless, "Images/eShip_2.png", 600, 600);
        eShip3[i] = ViewAdd(ContainerEndless, "Images/eShip_3.png", 600, 600);
        eShip4[i] = ViewAdd(ContainerEndless, "Images/eShip_4.png", 600, 600);
    }
    for (int i = 0; i < 5; i++) {
        eShip5[i] = ViewAdd(ContainerEndless, "Images/eShip_5.png", 600, 600);
        eShip6[i] = ViewAdd(ContainerEndless, "Images/eShip_6.png", 600, 600);
        eShip7[i] = ViewAdd(ContainerEndless, "Images/eShip_7.png", 600, 600);
        eShip8[i] = ViewAdd(ContainerEndless, "Images/eShip_8.png", 600, 600);
    }
    eShip9 = ViewAdd(ContainerEndless, "Images/eMini-Boss.png", 600, 600);
    eShip10 = ViewAdd(ContainerEndless, "Images/eBoss.png", 600, 600);
    //populate ContainerMenu
    ViewAdd(ContainerMenu, "Images/Background.png", 0, 0);
    ViewAdd(ContainerMenu, "Images/btnStory.png", 20, 40, OnStoryMenuTouch, 1);
    ViewAdd(ContainerMenu, "Images/btnEndless.png", 20, 150, OnEndlessMenuTouch, 1);
    ViewAdd(ContainerMenu, "Images/btnUnlocks.png", 20, 260, OnUnlocksMenuTouch, 1);
    ViewAdd(ContainerMenu, "Images/btnOptions.png", 20, 370, OnOptionsMenuTouch, 1);
    //populate ContainerDied
    ViewAdd(ContainerDied, "Images/Background.png", 0, 0);
    ViewAdd(ContainerDied, "Images/btnOkBig.png", 20, 380, OnDied, 1);
    TextAdd(ContainerDied, 0, 0, "\n\nYou died without completing \nyour journey or leaving \nyourself a legacy. You left no", font);
    TextAdd(ContainerDied, 0, 0, "\n\n\n\n\nimprint on the world and \nnobody will ever remember \nyou.", font);
    //populate CointainerStory1a1
    ViewAdd(ContainerStory1a1, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory1a1, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory1a1, "Images/btnOkBig.png", 20, 380, OnStoryLevel1, 1);
    TextAdd(ContainerStory1a1, 0, 0, "\n\nRon: \nAlex, are you ready for the \nbig test? Remember: We \nadopted the new cycle", font);
    TextAdd(ContainerStory1a1, 0, 0, "\n\n\n\n\n\nsystem 93 cycles ago. If we \nstill used the old Earth \nmethod, it would currently be", font);
    TextAdd(ContainerStory1a1, 0, 0, "\n\n\n\n\n\n\n\n\nyear 2433.", font);
    //populate ContainerStory1a2
    ViewAdd(ContainerStory1a2, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory1a2, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory1a2, "Images/btnStudy.png", 20, 380, OnStoryLevel1, 3);
    ViewAdd(ContainerStory1a2, "Images/btnParty.png", 170, 380, OnStoryLevel1, 4);
    TextAdd(ContainerStory1a2, 0, 0, "\n\nRon: \nAlso, you can either \nstudy for the big test \ntomorrow, or go to a party", font);
    TextAdd(ContainerStory1a2, 0, 0, "\n\n\n\n\n\nwith the cool guys and I. Just \ntell them Ron invited you.", font);
    //populate ContainerStory1s3
    ViewAdd(ContainerStory1s3, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory1s3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory1s3, "Images/btnSleep.png", 20, 380, OnStoryLevel1, 5);
    TextAdd(ContainerStory1s3, 0, 0, "\n\nBook: \nEverybody must listen to \nhigher command at all times. \nAlso, ship pilots must never", font);
    TextAdd(ContainerStory1s3, 0, 0, "\n\n\n\n\n\nabandon their ship.", font);
    //populate ContainerStory1p3
    ViewAdd(ContainerStory1p3, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory1p3, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory1p3, "Images/btnSleep.png", 20, 380, OnStoryLevel1, 5);
    TextAdd(ContainerStory1p3, 0, 0, "\n\nRon: \nHave a great night.", font);
    //populate ContainerStory1a4
    ViewAdd(ContainerStory1a4, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory1a4, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory1a4, "Images/btnRescue.png", 20, 380, OnStoryLevel1, 6);
    ViewAdd(ContainerStory1a4, "Images/btnEscape.png", 170, 380, OnStoryLevel1, 7);
    TextAdd(ContainerStory1a4, 0, 0, "\n\nTeacher: \nThe Kobayashi ship is \ntrapped behind enemy \nlines. What do you do?", font);
    //populate ContainerStory1r5
    ViewAdd(ContainerStory1r5, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory1r5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory1r5, "Images/btnOkBig.png", 20, 380, OnStoryLevel1, 8);
    TextAdd(ContainerStory1r5, 0, 0, "\n\nLieutenant: \nThey ambushed us!", font);
    //populate ContainerStory1e5
    ViewAdd(ContainerStory1e5, "Images/Background.png", 0, 0);
    ViewAdd(ContainerStory1e5, "Images/Pause.png", 270, 20, OnPause, 1);
    ViewAdd(ContainerStory1e5, "Images/btnOkBig.png", 20, 380, OnStoryLevel1, 8);
    TextAdd(ContainerStory1e5, 0, 0, "\n\nLieutenant: \nThey followed us and are \nattacking!", font);
}
void StartupMusic() {
    if (sound) {
        if (counter > 1 && counter < 7000) {
            counter = 7000;
        } else if (counter > 7000 && counter < 13000) {
            counter = 13000;
        } else if (counter > 13000 && counter < 19000) {
            counter = 19000;
        } else if (counter > 19000 && counter < 27000) {
            counter = 27000;
        } else if (counter > 27000 && counter < 34000) {
            counter = 34000;
        } else if (counter > 34000 && counter < 42000) {
            counter = 42000;
        } else if (counter > 42000 && counter < 49000) {
            counter = 49000;
        } else if (counter > 49000 && counter < 55000) {
            counter = 55000;
        } else if (counter > 55000 && counter < 61000) {
            counter = 61000;
        } else if (counter > 61000 && counter < 67000) {
            counter = 67000;
        } else if (counter > 67000 && counter < 73000) {
            counter = 73000;
        } else if (counter > 73000 && counter < 79000) {
            counter = 79000;
        } else if (counter > 79000) {
            counter = 1;
        }
        if (counter > 1 && counter < 7000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/1.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 7000 && counter < 13000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/2.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 13000 && counter < 19000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/3.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 19000 && counter < 27000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/5.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 27000 && counter < 34000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/7.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 34000 && counter < 42000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/8.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 42000 && counter < 49000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/9.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 49000 && counter < 55000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/11.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 55000 && counter < 61000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/12.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 61000 && counter < 67000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/13.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 67000 && counter < 73000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/14.mp3");
            Mp3Loop(Mp3Handle);
        } else if (counter > 73000 && counter < 79000) {
            Mp3Stop();
            Mp3Handle = Mp3Add("Sounds/15.mp3");
            Mp3Loop(Mp3Handle);
        }
    } else {
        Mp3Stop();
    }
}
void AppMain() {
    LoadGame();
    DeclareContainers();
    font = FontAdd("Arial", "Regular", 24, 0xA4A4A4);
    FontTorture = FontAdd("Arial", "Regular", 24, 0xDF0101);

    ScreenSwitch();
    ContainerOne();
    ContainerTwo();
    ContainerThree();
    ContainerFour();
    ContainerFive();
    ContainerSixSeven();

    //populate ContainerUnlocks
    ViewAdd(ContainerUnlocks, "Images/Background.png", 0, 0);
    ViewAdd(ContainerUnlocks, "Images/Pause.png", 270, 20, OnPause, 1);
    r = TextAdd(ContainerUnlocks, 10, 10, "", font);
    TextAdd(ContainerUnlocks, 10, 10, "\n\n\n\n\n Pick Your Ship By Clicking", font);
    ViewAdd(ContainerUnlocks, "Unlocks/UnShip_1.png", 20, 180, Unlocks, 1);
    s2 = ViewAdd(ContainerUnlocks, "Unlocks/LckShip_2.png", 120, 180, Unlocks, 2);
    s3 = ViewAdd(ContainerUnlocks, "Unlocks/LckShip_3.png", 220, 180, Unlocks, 3);
    s4 = ViewAdd(ContainerUnlocks, "Unlocks/LckShip_4.png", 20, 280, Unlocks, 4);
    s5 = ViewAdd(ContainerUnlocks, "Unlocks/LckShip_5.png", 120, 280, Unlocks, 5);
    s6 = ViewAdd(ContainerUnlocks, "Unlocks/LckShip_6.png", 220, 280, Unlocks, 6);
    s7 = ViewAdd(ContainerUnlocks, "Unlocks/LckShip_7.png", 60, 380, Unlocks, 7);
    s8 = ViewAdd(ContainerUnlocks, "Unlocks/LckShip_8.png", 180, 380, Unlocks, 8);
    //populate ContainerOptions
    ViewAdd(ContainerOptions, "Images/Background.png", 0, 0);
    ViewAdd(ContainerOptions, "Images/Pause.png", 270, 20, OnPause, 1);
    char* musicString = (sound) ? ("Unlocks/MusicOn.png") : ("Unlocks/MusicOff.png");
    music = ViewAdd(ContainerOptions, musicString, 20, 80, Options, 1);
    TextAdd(ContainerOptions, 20, 320, "Credits: \nThis Game Was Created \nBy Bailey Thompson", font);
    ViewAdd(ContainerOptions, "Images/btnDelete.png", 20, 200, Options, 2);
    //populate ContainerDeleteCheckOne
    ViewAdd(ContainerDeleteCheckOne, "Images/Background.png", 0, 0);
    TextAdd(ContainerDeleteCheckOne, 20, 20, "Are you sure you want to \nDELETE ALL PLAYER \nDATA including xp, rank, \nhighscore, and ships?", font);
    ViewAdd(ContainerDeleteCheckOne, "Images/btnNoDelete.png", 20, 180, Options, 5);
    ViewAdd(ContainerDeleteCheckOne, "Images/btnYesDelete.png", 20, 300, Options, 3);
    //populate ContainerDeleteCheckTwo
    ViewAdd(ContainerDeleteCheckTwo, "Images/Background.png", 0, 0);
    TextAdd(ContainerDeleteCheckTwo, 20, 20, "Are you really sure you \nwant to DELETE \nEVERYTHING?", font);
    ViewAdd(ContainerDeleteCheckTwo, "Images/btnNoDelete.png", 20, 300, Options, 5);
    ViewAdd(ContainerDeleteCheckTwo, "Images/btnYesDelete.png", 20, 180, Options, 4);
    //ship picture
    ShipType();
    //startup music
    StartupMusic();
}

void IntGameToFile() {
    FileBuffer[0] = char(IntTempNum / 10000 + '0');
    IntTempNum %= 10000;
    FileBuffer[1] = char(IntTempNum / 1000 + '0');
    IntTempNum %= 1000;
    FileBuffer[2] = char(IntTempNum / 100 + '0');
    IntTempNum %= 100;
    FileBuffer[3] = char(IntTempNum / 10 + '0');
    IntTempNum %= 10;
    FileBuffer[4] = char(IntTempNum + '0');
    IntTempNum = 0;
}
void BoolGameToFile() {
    FileBuffer[0] = (BoolTempNum) ? ('t') : ('f');
}
void AppExit() {
    Mp3Stop();
    //FileSound
    FileSound = FileOpen("Sound.txt");
    BoolTempNum = sound;
    BoolGameToFile();
    FileWrite(FileSound, FileBuffer, 1);
    FileClose(FileSound);
    //FileUpdateHighscore
    FileUpdateHighscore = FileOpen("UpdateHighscore.txt");
    BoolTempNum = UpdateHighscore;
    BoolGameToFile();
    FileWrite(FileUpdateHighscore, FileBuffer, 1);
    FileClose(FileUpdateHighscore);
    //FileXp
    FileXp = FileOpen("Xp.txt");
    IntTempNum = xp;
    IntGameToFile();
    FileWrite(FileXp, FileBuffer, 5);
    FileClose(FileXp);
    //FileShip
    FileShip = FileOpen("Ship.txt");
    IntTempNum = ship;
    IntGameToFile();
    FileWrite(FileShip, FileBuffer, 5);
    FileClose(FileShip);
    //FileHighscore
    FileHighscore = FileOpen("Highscore.txt");
    IntTempNum = highscore;
    IntGameToFile();
    FileWrite(FileHighscore, FileBuffer, 5);
    FileClose(FileHighscore);
    //FileCounter
    FileCounter = FileOpen("Counter.txt");
    IntTempNum = counter;
    IntGameToFile();
    FileWrite(FileCounter, FileBuffer, 5);
    FileClose(FileCounter);
}

bool IsNotActive() {
    bool ret = CurrentScreen != ScreenEndless && CurrentScreen != ScreenStoryBattle1
               && CurrentScreen != ScreenStoryBattle2 && CurrentScreen != ScreenStoryBattle4
               && CurrentScreen != ScreenStoryBattle5 && CurrentScreen != ScreenStoryBattle6
               && CurrentScreen != ScreenDied && CurrentScreen != ScreenHighscore;
    return ret;
}
void SoundSwitch() {
    if (sound) {
        if (counter == 1) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/1.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 0;
            }
        } else if (counter == 7000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/2.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 6999;
            }
        } else if (counter == 13000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/3.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 12999;
            }
        } else if (counter == 19000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/5.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 18999;
            }
        } else if (counter == 27000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/7.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 26999;
            }
        } else if (counter == 34000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/8.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 33999;
            }
        } else if (counter == 42000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/9.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 41999;
            }
        } else if (counter == 49000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/11.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 48999;
            }
        } else if (counter == 55000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/12.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 54999;
            }
        } else if (counter == 61000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/13.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 60999;
            }
        } else if (counter == 67000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/14.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 66999;
            }
        } else if (counter == 73000) {
            if (IsNotActive()) {
                Mp3Stop();
                Mp3Handle = Mp3Add("Sounds/15.mp3");
                Mp3Loop(Mp3Handle);
            } else {
                counter = 72999;
            }
        } else if (counter >= 79000) {
            counter = 0;
        }
    } else {
        Mp3Stop();
    }
}
void mShipMove() {
    //move x
    if (newX > mX + ShipSpeed / 2) {
        mX += ShipSpeed;
    } else if (newX + ShipSpeed / 2 < mX) {
        mX -= ShipSpeed;
    }
    //move y
    if (newY > mY + ShipSpeed / 2) {
        mY += ShipSpeed;
    } else if (newY + ShipSpeed / 2 < mY) {
        mY -= ShipSpeed;
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
    ViewSetxy(ShipView, mX, mY);
}
void BulletTime() {
    int x, y, x2, y2, x3, y3;
    bool used = false;
    for (int i = 1; i <= 15; i++) {
        if (counter2 == i * time) {
            used = true;
            if (ship == 8) {
                ViewSetxy(mBullet1[i - 1], mX + BulletXOffset, mY + BulletYOffset);
                ViewSetxy(mBullet2[i - 1], mX + BulletXOffset2, mY + BulletYOffset2);
                ViewSetxy(mBullet3[i - 1], mX + BulletXOffset3, mY + BulletYOffset3);
            } else if (ship == 7) {
                ViewSetxy(mBullet2[i - 1], mX + BulletXOffset2, mY + BulletYOffset2);
            } else if (ship == 6 || ship == 5) {
                ViewSetxy(mBullet1[i - 1], mX + BulletXOffset, mY + BulletYOffset);
                ViewSetxy(mBullet3[i - 1], mX + BulletXOffset3, mY + BulletYOffset3);
            } else {
                ViewSetxy(mBullet1[i - 1], mX + BulletXOffset, mY + BulletYOffset);
            }
        }
    }
    if (counter2 >= 15 * time) {
        counter2 = 0;
    }
    if (!used) {
        for (int i = 0; i < 15; i++) {
			x = ViewGetx(mBullet1[i]);
			y = ViewGety(mBullet1[i]);
			x2 = ViewGetx(mBullet2[i]);
			y2 = ViewGety(mBullet2[i]);
			x3 = ViewGetx(mBullet3[i]);
			y3 = ViewGety(mBullet3[i]);
			if (y > -20 || y2 > -20 || y3 > -20) {
				ViewSetxy(mBullet1[i], x, y - speed);
				ViewSetxy(mBullet2[i], x2, y2 - speed);
				ViewSetxy(mBullet3[i], x3, y3 - speed);
			}
			for (int j = 0; j < 10; j++) {
				//ship 1
				if (y > eShipY1[j] && y < eShipY1[j] + 94 && x > eShipX1[j] + 9 && x < eShipX1[j] + 76) {
					ViewSetxy(mBullet1[i], -10, -10);
					eShip1Health[j] -= 1;
				}
				if (y2 > eShipY1[j] && y2 < eShipY1[j] + 94 && x2 > eShipX1[j] + 9 && x2 < eShipX1[j] + 76) {
					ViewSetxy(mBullet2[i], -20, -20);
					eShip1Health[j] -= 3;
				}
				if (y3 > eShipY1[j] && y3 < eShipY1[j] + 94 && x3 > eShipX1[j] + 9 && x3 < eShipX1[j] + 76) {
					ViewSetxy(mBullet3[i], -10, -10);
					eShip1Health[j] -= 1;
				}
				//ship 2
				if (y > eShipY2[j] && y < eShipY2[j] + 94 && x > eShipX2[j] + 15 && x < eShipX2[j] + 69) {
					ViewSetxy(mBullet1[i], -10, -10);
					eShip2Health[j] -= 1;
				}
				if (y2 > eShipY2[j] && y2 < eShipY2[j] + 94 && x2 > eShipX2[j] + 15 && x2 < eShipX2[j] + 69) {
					ViewSetxy(mBullet2[i], -20, -20);
					eShip2Health[j] -= 3;
				}
				if (y3 > eShipY2[j] && y3 < eShipY2[j] + 94 && x3 > eShipX2[j] + 15 && x3 < eShipX2[j] + 69) {
					ViewSetxy(mBullet3[i], -10, -10);
					eShip2Health[j] -= 1;
				}
				//ship 3
				if (y > eShipY3[j] && y < eShipY3[j] + 94 && x > eShipX3[j] + 18 && x < eShipX3[j] + 66) {
					ViewSetxy(mBullet1[i], -10, -10);
					eShip3Health[j] -= 1;
				}
				if (y2 > eShipY3[j] && y2 < eShipY3[j] + 94 && x2 > eShipX3[j] + 18 && x2 < eShipX3[j] + 66) {
					ViewSetxy(mBullet2[i], -20, -20);
					eShip3Health[j] -= 3;
				}
				if (y3 > eShipY3[j] && y3 < eShipY3[j] + 94 && x3 > eShipX3[j] + 18 && x3 < eShipX3[j] + 66) {
					ViewSetxy(mBullet3[i], -10, -10);
					eShip3Health[j] -= 1;
				}
				//ship 4
				if (y > eShipY4[j] && y < eShipY4[j] + 94 && x > eShipX4[j] - 3 && x < eShipX4[j] + 87) {
					ViewSetxy(mBullet1[i], -10, -10);
					eShip4Health[j] -= 1;
				}
				if (y2 > eShipY4[j] && y2 < eShipY4[j] + 94 && x2 > eShipX4[j] - 3 && x2 < eShipX4[j] + 87) {
					ViewSetxy(mBullet2[i], -20, -20);
					eShip4Health[j] -= 3;
				}
				if (y3 > eShipY4[j] && y3 < eShipY4[j] + 94 && x3 > eShipX4[j] - 3 && x3 < eShipX4[j] + 87) {
					ViewSetxy(mBullet3[i], -10, -10);
					eShip4Health[j] -= 1;
				}
			}
			for (int j = 0; j < 5; j++) {
				//ship 5
				if (y > eShipY5[j] && y < eShipY5[j] + 94 && x > eShipX5[j] + 13 && x < eShipX5[j] + 71) {
					ViewSetxy(mBullet1[i], -10, -10);
					eShip5Health[j] -= 1;
				}
				if (y2 > eShipY5[j] && y2 < eShipY5[j] + 94 && x2 > eShipX5[j] + 13 && x2 < eShipX5[j] + 71) {
					ViewSetxy(mBullet2[i], -20, -20);
					eShip5Health[j] -= 3;
				}
				if (y3 > eShipY5[j] && y3 < eShipY5[j] + 94 && x3 > eShipX5[j] + 13 && x3 < eShipX5[j] + 71) {
					ViewSetxy(mBullet3[i], -10, -10);
					eShip5Health[j] -= 1;
				}
				//ship 6
				if (y > eShipY6[j] && y < eShipY6[j] + 94 && x > eShipX6[j] + 3 && x < eShipX6[j] + 81) {
					ViewSetxy(mBullet1[i], -10, -10);
					eShip6Health[j] -= 1;
				}
				if (y2 > eShipY2[j] && y2 < eShipY2[j] + 94 && x2 > eShipX2[j] + 3 && x2 < eShipX2[j] + 81) {
					ViewSetxy(mBullet2[i], -20, -20);
					eShip2Health[j] -= 3;
				}
				if (y3 > eShipY6[j] && y3 < eShipY6[j] + 94 && x3 > eShipX6[j] + 3 && x3 < eShipX6[j] + 81) {
					ViewSetxy(mBullet3[i], -10, -10);
					eShip6Health[j] -= 1;
				}
				//ship 7
				if (y > eShipY7[j] && y < eShipY7[j] + 94 && x > eShipX7[j] - 2 && x < eShipX7[j] + 86) {
					ViewSetxy(mBullet1[i], -10, -10);
					eShip7Health[j] -= 1;
				}
				if (y2 > eShipY7[j] && y2 < eShipY7[j] + 94 && x2 > eShipX7[j] - 2 && x2 < eShipX7[j] + 86) {
					ViewSetxy(mBullet2[i], -20, -20);
					eShip7Health[j] -= 3;
				}
				if (y3 > eShipY7[j] && y3 < eShipY7[j] + 94 && x3 > eShipX7[j] - 2 && x3 < eShipX7[j] + 86) {
					ViewSetxy(mBullet3[i], -10, -10);
					eShip7Health[j] -= 1;
				}
				//ship 8
				if (y > eShipY8[j] && y < eShipY8[j] + 94 && x > eShipX8[j] - 3 && x < eShipX8[j] + 86) {
					ViewSetxy(mBullet1[i], -10, -10);
					eShip8Health[j] -= 1;
				}
				if (y2 > eShipY8[j] && y2 < eShipY8[j] + 94 && x2 > eShipX8[j] - 3 && x2 < eShipX8[j] + 86) {
					ViewSetxy(mBullet2[i], -20, -20);
					eShip8Health[j] -= 3;
				}
				if (y3 > eShipY8[j] && y3 < eShipY8[j] + 94 && x3 > eShipX8[j] - 3 && x3 < eShipX8[j] + 86) {
					ViewSetxy(mBullet3[i], -10, -10);
					eShip8Health[j] -= 1;
				}
			}
			//ship 9
			if (y > eShipY9 && y < eShipY9 + 94 && x > eShipX9 && x < eShipX9 + 240) {
				ViewSetxy(mBullet1[i], -10, -10);
				eShip9Health -= 1;
			}
			if (y2 > eShipY9 && y2 < eShipY9 + 94 && x2 > eShipX9 && x2 < eShipX9 + 240) {
				ViewSetxy(mBullet2[i], -20, -20);
				eShip9Health -= 3;
			}
			if (y3 > eShipY9 && y3 < eShipY9 + 94 && x3 > eShipX9 && x3 < eShipX9 + 240) {
				ViewSetxy(mBullet3[i], -10, -10);
				eShip9Health -= 1;
			}
			//ship 10
			if (y > eShipY10 && y < eShipY10 + 94 && x > eShipX10 && x < eShipX10 + 240) {
				ViewSetxy(mBullet1[i], -10, -10);
				eShip10Health -= 1;
			}
			if (y2 > eShipY10 && y2 < eShipY10 + 94 && x2 > eShipX10 && x2 < eShipX10 + 240) {
				ViewSetxy(mBullet2[i], -20, -20);
				eShip10Health -= 3;
			}
			if (y3 > eShipY10 && y3 < eShipY10 + 94 && x3 > eShipX10 && x3 < eShipX10 + 240) {
				ViewSetxy(mBullet3[i], -10, -10);
				eShip10Health -= 1;
			}
        }
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
    if (UpdateHighscore) {
        if (level > highscore) {
            highscore = level;
        }
        DoHighscore();
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
            lvl[25] = char(one + '0');
            lvl[26] = char(two + '0');
            TextSetText(text2, lvl);
        } else {
            (health <= 0) ? (TextSetText(text2, "\n\n\n\n\n\nSurvived To Level 99+")) :
            (TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 99+"));
        }

        Reset();
        UpdateHighscore = false;
    }
}
void TortureHealth() {
    int ImageTorturing, number = 100;
    if (HpCounterTorture > number * 20 && torture) {
        HpCounterTorture = number * 20;
    } else if (HpCounterTorture > number * 40 && !torture) {
        CurrentScreen = ScreenDied;
        ScreenSwitch();
    } else if (HpCounterTorture <= number * 20 && HpCounterTorture > number * 19) {
        ImageTorturing = ImageAdd("Images/20HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= number * 19 && HpCounterTorture > number * 18) {
        ImageTorturing = ImageAdd("Images/19HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
        TextSetText(TextTorture, "\n\n\n\n\n\nStop This Madness!");
    } else if (HpCounterTorture <= number * 18 && HpCounterTorture > number * 17) {
        ImageTorturing = ImageAdd("Images/18HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= number * 17 && HpCounterTorture > number * 16) {
        ImageTorturing = ImageAdd("Images/17HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
        TextSetText(TextTorture, "\n\n\n\n\n\nDon't Do It!");
    } else if (HpCounterTorture <= number * 16 && HpCounterTorture > number * 15) {
        ImageTorturing = ImageAdd("Images/16HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= number * 15 && HpCounterTorture > number * 14) {
        ImageTorturing = ImageAdd("Images/15HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
        TextSetText(TextTorture, "\n\n\n\n\n\nI Beg Of You!");
    } else if (HpCounterTorture <= number * 14 && HpCounterTorture > number * 13) {
        ImageTorturing = ImageAdd("Images/14HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= number * 13 && HpCounterTorture > number * 12) {
        ImageTorturing = ImageAdd("Images/13HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
        TextSetText(TextTorture, "\n\n\n\n\n\nPlease Don't!");
    } else if (HpCounterTorture <= number * 12 && HpCounterTorture > number * 11) {
        ImageTorturing = ImageAdd("Images/12HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= number * 11 && HpCounterTorture > number * 10) {
        ImageTorturing = ImageAdd("Images/11HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
        TextSetText(TextTorture, "\n\n\n\n\n\nI Order You To Stop!");
    } else if (HpCounterTorture <= number * 10 && HpCounterTorture > number * 9) {
        ImageTorturing = ImageAdd("Images/10HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= number * 9 && HpCounterTorture > number * 8) {
        ImageTorturing = ImageAdd("Images/9HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
        TextSetText(TextTorture, "\n\n\n\n\n\nI Have A Family!");
    } else if (HpCounterTorture <= number * 8 && HpCounterTorture > number * 7) {
        ImageTorturing = ImageAdd("Images/8HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= number * 7 && HpCounterTorture > number * 6) {
        ImageTorturing = ImageAdd("Images/7HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
        TextSetText(TextTorture, "\n\n\n\n\n\nDon't Do This!");
    } else if (HpCounterTorture <= number * 6 && HpCounterTorture > number * 5) {
        ImageTorturing = ImageAdd("Images/6HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= number * 5 && HpCounterTorture > number * 4) {
        ImageTorturing = ImageAdd("Images/5HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
        TextSetText(TextTorture, "\n\n\n\n\n\nWhy Are You \nDoing This!");
    } else if (HpCounterTorture <= number * 4 && HpCounterTorture > number * 3) {
        ImageTorturing = ImageAdd("Images/4HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= number * 3 && HpCounterTorture > number * 2) {
        ImageTorturing = ImageAdd("Images/3HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
        TextSetText(TextTorture, "\n\n\n\n\n\nYou Will Burn!");
    } else if (HpCounterTorture <= number * 2 && HpCounterTorture > number * 1) {
        ImageTorturing = ImageAdd("Images/2HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= number * 1 && HpCounterTorture > 0) {
        ImageTorturing = ImageAdd("Images/1HP.png");
        ViewSetImage(HpTorture, ImageTorturing);
    } else if (HpCounterTorture <= 0) {
        pause = false;
        CurrentScreen = ScreenStory4a1;
        ScreenSwitch();
    }
}
void HealthBar() {
    int Image;
    if (HealthUpdate) {
        if (ship == 8) {
            switch (health) {
                case 34:
                    Image = ImageAdd("Images/20HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 32:
                    Image = ImageAdd("Images/19HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 30:
                    Image = ImageAdd("Images/18HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 28:
                    Image = ImageAdd("Images/17HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 26:
                    Image = ImageAdd("Images/16HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 24:
                    Image = ImageAdd("Images/15HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 22:
                    Image = ImageAdd("Images/14HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 20:
                    Image = ImageAdd("Images/13HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 18:
                    Image = ImageAdd("Images/12HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 16:
                    Image = ImageAdd("Images/11HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 14:
                    Image = ImageAdd("Images/10HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 12:
                    Image = ImageAdd("Images/9HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 10:
                    Image = ImageAdd("Images/8HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 8:
                    Image = ImageAdd("Images/7HP.png");
                    ViewSetImage(HP, Image);
                    break;
            }
            if (health <= 6) {
                char one[] = "Images/0HP.png";
                one[7] = char(health + '0');
                Image = ImageAdd(one);
                ViewSetImage(HP, Image);
            }
        } else if (ship == 7) {
            switch (health) {
                case 32:
                    Image = ImageAdd("Images/20HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 30:
                    Image = ImageAdd("Images/19HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 28:
                    Image = ImageAdd("Images/18HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 26:
                    Image = ImageAdd("Images/17HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 24:
                    Image = ImageAdd("Images/16HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 22:
                    Image = ImageAdd("Images/15HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 20:
                    Image = ImageAdd("Images/14HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 18:
                    Image = ImageAdd("Images/13HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 16:
                    Image = ImageAdd("Images/12HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 14:
                    Image = ImageAdd("Images/11HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 12:
                    Image = ImageAdd("Images/10HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 10:
                    Image = ImageAdd("Images/9HP.png");
                    ViewSetImage(HP, Image);
                    break;
            }
            if (health <= 8) {
                char one[] = "Images/0HP.png";
                one[7] = char(health + '0');
                Image = ImageAdd(one);
                ViewSetImage(HP, Image);
            }
        } else if (ship == 6) {
            switch (health) {
                case 30:
                    Image = ImageAdd("Images/20HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 28:
                    Image = ImageAdd("Images/19HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 26:
                    Image = ImageAdd("Images/18HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 24:
                    Image = ImageAdd("Images/17HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 22:
                    Image = ImageAdd("Images/16HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 20:
                    Image = ImageAdd("Images/15HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 18:
                    Image = ImageAdd("Images/14HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 16:
                    Image = ImageAdd("Images/13HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 14:
                    Image = ImageAdd("Images/12HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 12:
                    Image = ImageAdd("Images/11HP.png");
                    ViewSetImage(HP, Image);
                    break;
            }
            if (health <= 10) {
                char one[] = "Images/0HP.png";
                char two[] = "Images/00HP.png";
                if (health >= 10) {
                    int tmpOne = health / 10;
                    int tmpTwo = health % 10;
                    two[7] = char(tmpOne + '0');
                    two[8] = char(tmpTwo + '0');
                    Image = ImageAdd(two);
                } else {
                    one[7] = char(health + '0');
                    Image = ImageAdd(one);
                }
                ViewSetImage(HP, Image);
            }
        } else if (ship == 5) {
            switch (health) {
                case 28:
                    Image = ImageAdd("Images/20HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 26:
                    Image = ImageAdd("Images/19HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 24:
                    Image = ImageAdd("Images/18HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 22:
                    Image = ImageAdd("Images/17HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 20:
                    Image = ImageAdd("Images/16HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 18:
                    Image = ImageAdd("Images/15HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 16:
                    Image = ImageAdd("Images/14HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 14:
                    Image = ImageAdd("Images/13HP.png");
                    ViewSetImage(HP, Image);
                    break;
            }
            if (health <= 12) {
                char one[] = "Images/0HP.png";
                char two[] = "Images/00HP.png";
                if (health >= 10) {
                    int tmpOne = health / 10;
                    int tmpTwo = health % 10;
                    two[7] = char(tmpOne + '0');
                    two[8] = char(tmpTwo + '0');
                    Image = ImageAdd(two);
                } else {
                    one[7] = char(health + '0');
                    Image = ImageAdd(one);
                }
                ViewSetImage(HP, Image);
            }
        } else if (ship == 4) {
            switch (health) {
                case 26:
                    Image = ImageAdd("Images/20HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 24:
                    Image = ImageAdd("Images/19HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 22:
                    Image = ImageAdd("Images/18HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 20:
                    Image = ImageAdd("Images/17HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 18:
                    Image = ImageAdd("Images/16HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 16:
                    Image = ImageAdd("Images/15HP.png");
                    ViewSetImage(HP, Image);
                    break;
            }
            if (health <= 14) {
                char one[] = "Images/0HP.png";
                char two[] = "Images/00HP.png";
                if (health >= 10) {
                    int tmpOne = health / 10;
                    int tmpTwo = health % 10;
                    two[7] = char(tmpOne + '0');
                    two[8] = char(tmpTwo + '0');
                    Image = ImageAdd(two);
                } else {
                    one[7] = char(health + '0');
                    Image = ImageAdd(one);
                }
                ViewSetImage(HP, Image);
            }
        } else if (ship == 3) {
            switch (health) {
                case 24:
                    Image = ImageAdd("Images/20HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 22:
                    Image = ImageAdd("Images/19HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 20:
                    Image = ImageAdd("Images/18HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 18:
                    Image = ImageAdd("Images/17HP.png");
                    ViewSetImage(HP, Image);
                    break;
            }
            if (health <= 16) {
                char one[] = "Images/0HP.png";
                char two[] = "Images/00HP.png";
                if (health >= 10) {
                    int tmpOne = health / 10;
                    int tmpTwo = health % 10;
                    two[7] = char(tmpOne + '0');
                    two[8] = char(tmpTwo + '0');
                    Image = ImageAdd(two);
                } else {
                    one[7] = char(health + '0');
                    Image = ImageAdd(one);
                }
                ViewSetImage(HP, Image);
            }
        } else if (ship == 2) {
            switch (health) {
                case 22:
                    Image = ImageAdd("Images/20HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 20:
                    Image = ImageAdd("Images/19HP.png");
                    ViewSetImage(HP, Image);
                    break;
            }
            if (health <= 18) {
                char one[] = "Images/0HP.png";
                char two[] = "Images/00HP.png";
                if (health >= 10) {
                    int tmpOne = health / 10;
                    int tmpTwo = health % 10;
                    two[7] = char(tmpOne + '0');
                    two[8] = char(tmpTwo + '0');
                    Image = ImageAdd(two);
                } else {
                    one[7] = char(health + '0');
                    Image = ImageAdd(one);
                }
                ViewSetImage(HP, Image);
            }
        } else if (ship == 1) {
            char one[] = "Images/0HP.png";
            char two[] = "Images/00HP.png";
            if (health >= 10) {
                int tmpOne = health / 10;
                int tmpTwo = health % 10;
                two[7] = char(tmpOne + '0');
                two[8] = char(tmpTwo + '0');
                Image = ImageAdd(two);
            } else {
                one[7] = char(health + '0');
                Image = ImageAdd(one);
            }
            ViewSetImage(HP, Image);
        }
        if (health <= 0) {
            if (CurrentScreen == ScreenEndless) {
                CurrentScreen = ScreenHighscore;
                UpdateHighscore = true;
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
        HealthUpdate = false;
        counter12 = 0;
    }
}
void SetOne() {
    if (counter3 == 1 * SpawnTime) {
        eShip1Health[0] = level + 2;
        ViewSetxy(eShip1[0], 113, -94);
    } else if (counter3 == 2 * SpawnTime) {
        eShip1Health[1] = level + 2;
        eShip2Health[0] = level + 2;
        ViewSetxy(eShip1[1], 33, -94);
        ViewSetxy(eShip2[0], 193, -94);
    } else if (counter3 == 3 * SpawnTime) {
        eShip2Health[1] = level + 2;
        ViewSetxy(eShip2[1], 113, -94);
    } else if (counter3 == 4 * SpawnTime) {
        eShip2Health[2] = level + 2;
        eShip1Health[2] = level + 2;
        ViewSetxy(eShip2[2], 33, -94);
        ViewSetxy(eShip1[2], 193, -94);
    } else if (counter3 == 5 * SpawnTime) {
        eShip1Health[3] = level + 2;
        eShip3Health[0] = level + 2;
        eShip2Health[3] = level + 2;
        ViewSetxy(eShip1[3], 0, -94);
        ViewSetxy(eShip3[0], 113, -94);
        ViewSetxy(eShip2[3], 226, -94);
    } else if (counter3 == 6 * SpawnTime) {
        eShip3Health[1] = level + 2;
        eShip2Health[4] = level + 2;
        eShip3Health[2] = level + 2;
        ViewSetxy(eShip3[1], 0, -94);
        ViewSetxy(eShip2[4], 113, -94);
        ViewSetxy(eShip3[2], 226, -94);
    } else if (counter3 == 7 * SpawnTime) {
        eShip1Health[4] = level + 2;
        eShip1Health[5] = level + 2;
        eShip2Health[5] = level + 2;
        ViewSetxy(eShip1[4], 0, -94);
        ViewSetxy(eShip1[5], 113, -94);
        ViewSetxy(eShip2[5], 226, -94);
    } else if (counter3 == 8 * SpawnTime) {
        eShip3Health[3] = level + 2;
        eShip1Health[6] = level + 2;
        eShip1Health[7] = level + 2;
        ViewSetxy(eShip3[3], 0, -94);
        ViewSetxy(eShip1[6], 113, -94);
        ViewSetxy(eShip1[7], 226, -94);
    } else if (counter3 == 9 * SpawnTime) {
        eShip2Health[6] = level + 2;
        eShip3Health[4] = level + 2;
        ViewSetxy(eShip2[6], 33, -94);
        ViewSetxy(eShip3[4], 193, -94);
    } else if (counter3 == 10 * SpawnTime) {
        eShip4Health[0] = level + 2;
        ViewSetxy(eShip4[0], 113, -94);
    } else if (counter3 == 11 * SpawnTime) {
        eShip3Health[5] = level + 2;
        eShip4Health[1] = level + 2;
        ViewSetxy(eShip3[5], 33, -94);
        ViewSetxy(eShip4[1], 193, -94);
    } else if (counter3 == 12 * SpawnTime) {
        eShip1Health[8] = level + 2;
        eShip2Health[7] = level + 2;
        eShip1Health[9] = level + 2;
        ViewSetxy(eShip1[8], 0, -94);
        ViewSetxy(eShip2[7], 113, -94);
        ViewSetxy(eShip1[9], 226, -94);
    } else if (counter3 == 13 * SpawnTime) {
        eShip4Health[2] = level + 2;
        eShip1Health[0] = level + 2;
        eShip3Health[6] = level + 2;
        ViewSetxy(eShip4[2], 0, -94);
        ViewSetxy(eShip1[0], 113, -94);
        ViewSetxy(eShip3[6], 226, -94);
    } else if (counter3 == 14 * SpawnTime) {
        eShip2Health[8] = level + 2;
        eShip4Health[3] = level + 2;
        eShip3Health[7] = level + 2;
        ViewSetxy(eShip2[8], 0, -94);
        ViewSetxy(eShip4[3], 113, -94);
        ViewSetxy(eShip3[7], 226, -94);
    } else if (counter3 == 15 * SpawnTime) {
        eShip4Health[4] = level + 2;
        eShip4Health[5] = level + 2;
        ViewSetxy(eShip4[4], 33, -94);
        ViewSetxy(eShip4[5], 193, -94);
    } else if (counter3 == 16 * SpawnTime) {
        eShip2Health[9] = level + 2;
        eShip2Health[0] = level + 2;
        eShip3Health[8] = level + 2;
        ViewSetxy(eShip2[9], 0, -94);
        ViewSetxy(eShip2[0], 113, -94);
        ViewSetxy(eShip3[8], 226, -94);
    } else if (counter3 == 17 * SpawnTime) {
        eShip3Health[9] = level + 2;
        eShip1Health[2] = level + 2;
        eShip2Health[1] = level + 2;
        ViewSetxy(eShip3[9], 0, -94);
        ViewSetxy(eShip1[2], 113, -94);
        ViewSetxy(eShip2[1], 226, -94);
    } else if (counter3 == 18 * SpawnTime) {
        eShip4Health[6] = level + 2;
        eShip2Health[2] = level + 2;
        ViewSetxy(eShip4[6], 33, -94);
        ViewSetxy(eShip2[2], 193, -94);
    } else if (counter3 == 19 * SpawnTime) {
        eShip5Health[0] = level + 2;
        ViewSetxy(eShip5[0], 113, -94);
    } else if (counter3 == 20 * SpawnTime) {
        eShip2Health[3] = level + 2;
        eShip4Health[7] = level + 2;
        ViewSetxy(eShip2[3], 33, -94);
        ViewSetxy(eShip4[7], 193, -94);
    } else if (counter3 == 21 * SpawnTime) {
        eShip1Health[1] = level + 2;
        eShip5Health[1] = level + 2;
        eShip1Health[2] = level + 2;
        ViewSetxy(eShip1[1], 0, -94);
        ViewSetxy(eShip5[1], 113, -94);
        ViewSetxy(eShip1[2], 226, -94);
    } else if (counter3 == 22 * SpawnTime) {
        eShip4Health[8] = level + 2;
        eShip2Health[4] = level + 2;
        eShip4Health[9] = level + 2;
        ViewSetxy(eShip4[8], 0, -94);
        ViewSetxy(eShip2[4], 113, -94);
        ViewSetxy(eShip4[9], 226, -94);
    } else if (counter3 == 23 * SpawnTime) {
        eShip5Health[2] = level + 2;
        eShip5Health[3] = level + 2;
        ViewSetxy(eShip5[2], 33, -94);
        ViewSetxy(eShip5[3], 193, -94);
    } else if (counter3 == 24 * SpawnTime) {
        eShip4Health[0] = level + 2;
        eShip5Health[4] = level + 2;
        eShip4Health[1] = level + 2;
        ViewSetxy(eShip4[0], 0, -94);
        ViewSetxy(eShip5[4], 113, -94);
        ViewSetxy(eShip4[1], 226, -94);
    } else if (counter3 == 25 * SpawnTime) {
        eShip5Health[0] = level + 2;
        eShip1Health[3] = level + 2;
        eShip3Health[0] = level + 2;
        ViewSetxy(eShip5[0], 0, -94);
        ViewSetxy(eShip1[3], 113, -94);
        ViewSetxy(eShip3[0], 226, -94);
    } else if (counter3 == 26 * SpawnTime) {
        eShip5Health[1] = level + 2;
        eShip5Health[2] = level + 2;
        ViewSetxy(eShip5[1], 33, -94);
        ViewSetxy(eShip5[2], 193, -94);
    } else if (counter3 == 27 * SpawnTime) {
        eShip1Health[4] = level + 2;
        eShip3Health[1] = level + 2;
        eShip1Health[1] = level + 2;
        ViewSetxy(eShip1[4], 0, -94);
        ViewSetxy(eShip3[1], 113, -94);
        ViewSetxy(eShip1[1], 226, -94);
    } else if (counter3 == 28 * SpawnTime) {
        eShip4Health[2] = level + 2;
        eShip5Health[3] = level + 2;
        eShip2Health[5] = level + 2;
        ViewSetxy(eShip4[2], 0, -94);
        ViewSetxy(eShip5[3], 113, -94);
        ViewSetxy(eShip2[5], 226, -94);
    } else if (counter3 == 29 * SpawnTime) {
        eShip1Health[2] = level + 2;
        eShip1Health[3] = level + 2;
        ViewSetxy(eShip1[2], 33, -94);
        ViewSetxy(eShip1[3], 193, -94);
    }
    if (counter3 == 30 * SpawnTime) {
        if (CurrentScreen != ScreenStoryBattle1) {
            eShip9Health = level + 24;
            ViewSetxy(eShip9, 89, -240);
        }
    } else if (counter3 == 31 * SpawnTime && CurrentScreen == ScreenStoryBattle1) {
        CurrentScreen = ScreenStory2a1;
        ScreenSwitch();
    }
}
void SetTwo() {
    if (counter3 == 1 * SpawnTime) {
        eShip1Health[0] = level + 2;
        eShip2Health[0] = level + 2;
        ViewSetxy(eShip1[0], 33, -94);
        ViewSetxy(eShip2[0], 193, -94);
    } else if (counter3 == 2 * SpawnTime) {
        eShip4Health[0] = level + 2;
        eShip3Health[0] = level + 2;
        ViewSetxy(eShip4[0], 33, -94);
        ViewSetxy(eShip3[0], 193, -94);
    } else if (counter3 == 3 * SpawnTime) {
        eShip5Health[0] = level + 2;
        ViewSetxy(eShip5[0], 113, -94);
    } else if (counter3 == 4 * SpawnTime) {
        eShip3Health[1] = level + 2;
        eShip2Health[1] = level + 2;
        ViewSetxy(eShip3[1], 33, -94);
        ViewSetxy(eShip2[1], 193, -94);
    } else if (counter3 == 5 * SpawnTime) {
        eShip3Health[2] = level + 2;
        eShip4Health[1] = level + 2;
        eShip3Health[3] = level + 2;
        ViewSetxy(eShip3[2], 0, -94);
        ViewSetxy(eShip4[1], 113, -94);
        ViewSetxy(eShip3[3], 226, -94);
    } else if (counter3 == 6 * SpawnTime) {
        eShip1Health[1] = level + 2;
        eShip2Health[2] = level + 2;
        eShip2Health[3] = level + 2;
        ViewSetxy(eShip1[1], 0, -94);
        ViewSetxy(eShip2[2], 113, -94);
        ViewSetxy(eShip2[3], 226, -94);
    } else if (counter3 == 7 * SpawnTime) {
        eShip4Health[2] = level + 2;
        eShip2Health[4] = level + 2;
        eShip3Health[4] = level + 2;
        ViewSetxy(eShip4[2], 0, -94);
        ViewSetxy(eShip2[4], 113, -94);
        ViewSetxy(eShip3[4], 226, -94);
    } else if (counter3 == 8 * SpawnTime) {
        eShip2Health[5] = level + 2;
        eShip1Health[2] = level + 2;
        eShip1Health[3] = level + 2;
        ViewSetxy(eShip2[5], 0, -94);
        ViewSetxy(eShip1[2], 113, -94);
        ViewSetxy(eShip1[3], 226, -94);
    } else if (counter3 == 9 * SpawnTime) {
        eShip4Health[3] = level + 2;
        eShip3Health[5] = level + 2;
        ViewSetxy(eShip4[3], 33, -94);
        ViewSetxy(eShip3[5], 193, -94);
    } else if (counter3 == 10 * SpawnTime) {
        eShip5Health[1] = level + 2;
        eShip5Health[2] = level + 2;
        ViewSetxy(eShip5[1], 33, -94);
        ViewSetxy(eShip5[2], 193, -94);
    } else if (counter3 == 11 * SpawnTime) {
        eShip4Health[4] = level + 2;
        ViewSetxy(eShip4[4], 113, -94);
    } else if (counter3 == 12 * SpawnTime) {
        eShip5Health[3] = level + 2;
        eShip2Health[6] = level + 2;
        ViewSetxy(eShip5[3], 33, -94);
        ViewSetxy(eShip2[6], 193, -94);
    } else if (counter3 == 13 * SpawnTime) {
        eShip3Health[6] = level + 2;
        eShip2Health[7] = level + 2;
        eShip2Health[8] = level + 2;
        ViewSetxy(eShip3[6], 0, -94);
        ViewSetxy(eShip2[7], 113, -94);
        ViewSetxy(eShip2[8], 226, -94);
    } else if (counter3 == 14 * SpawnTime) {
        eShip2Health[9] = level + 2;
        eShip5Health[4] = level + 2;
        eShip1Health[4] = level + 2;
        ViewSetxy(eShip2[9], 0, -94);
        ViewSetxy(eShip5[4], 113, -94);
        ViewSetxy(eShip1[4], 226, -94);
    } else if (counter3 == 15 * SpawnTime) {
        eShip5Health[0] = level + 2;
        eShip1Health[5] = level + 2;
        eShip4Health[5] = level + 2;
        ViewSetxy(eShip5[0], 0, -94);
        ViewSetxy(eShip1[5], 113, -94);
        ViewSetxy(eShip4[5], 226, -94);
    } else if (counter3 == 16 * SpawnTime) {
        eShip1Health[6] = level + 2;
        eShip3Health[7] = level + 2;
        ViewSetxy(eShip1[6], 33, -94);
        ViewSetxy(eShip3[7], 193, -94);
    } else if (counter3 == 17 * SpawnTime) {
        eShip4Health[6] = level + 2;
        eShip5Health[1] = level + 2;
        ViewSetxy(eShip4[6], 33, -94);
        ViewSetxy(eShip5[1], 193, -94);
    } else if (counter3 == 18 * SpawnTime) {
        eShip1Health[7] = level + 2;
        eShip5Health[2] = level + 2;
        eShip1Health[8] = level + 2;
        ViewSetxy(eShip1[7], 0, -94);
        ViewSetxy(eShip5[2], 113, -94);
        ViewSetxy(eShip1[8], 226, -94);
    } else if (counter3 == 19 * SpawnTime) {
        eShip1Health[9] = level + 2;
        eShip3Health[8] = level + 2;
        ViewSetxy(eShip1[9], 33, -94);
        ViewSetxy(eShip3[8], 193, -94);
    } else if (counter3 == 20 * SpawnTime) {
        eShip6Health[0] = level + 2;
        ViewSetxy(eShip6[0], 113, -94);
    } else if (counter3 == 21 * SpawnTime) {
        eShip3Health[9] = level + 2;
        ViewSetxy(eShip3[9], 113, -94);
    } else if (counter3 == 22 * SpawnTime) {
        eShip2Health[0] = level + 2;
        eShip1Health[0] = level + 2;
        ViewSetxy(eShip2[0], 33, -94);
        ViewSetxy(eShip1[0], 193, -94);
    } else if (counter3 == 23 * SpawnTime) {
        eShip3Health[0] = level + 2;
        eShip5Health[3] = level + 2;
        ViewSetxy(eShip3[0], 33, -94);
        ViewSetxy(eShip5[3], 193, -94);
    } else if (counter3 == 24 * SpawnTime) {
        eShip6Health[1] = level + 2;
        eShip4Health[7] = level + 2;
        eShip6Health[2] = level + 2;
        ViewSetxy(eShip6[1], 0, -94);
        ViewSetxy(eShip4[7], 113, -94);
        ViewSetxy(eShip6[2], 226, -94);
    } else if (counter3 == 25 * SpawnTime) {
        eShip4Health[8] = level + 2;
        eShip5Health[4] = level + 2;
        eShip1Health[2] = level + 2;
        ViewSetxy(eShip4[8], 0, -94);
        ViewSetxy(eShip5[4], 113, -94);
        ViewSetxy(eShip1[2], 226, -94);
    } else if (counter3 == 26 * SpawnTime) {
        eShip6Health[3] = level + 2;
        eShip4Health[9] = level + 2;
        eShip6Health[4] = level + 2;
        ViewSetxy(eShip6[3], 0, -94);
        ViewSetxy(eShip4[9], 113, -94);
        ViewSetxy(eShip6[4], 226, -94);
    } else if (counter3 == 27 * SpawnTime) {
        eShip4Health[0] = level + 2;
        eShip5Health[0] = level + 2;
        ViewSetxy(eShip4[0], 33, -94);
        ViewSetxy(eShip5[0], 193, -94);
    } else if (counter3 == 28 * SpawnTime) {
        eShip1Health[2] = level + 2;
        eShip6Health[0] = level + 2;
        ViewSetxy(eShip1[2], 33, -94);
        ViewSetxy(eShip6[0], 193, -94);
    } else if (counter3 == 29 * SpawnTime) {
        eShip5Health[1] = level + 2;
        eShip3Health[1] = level + 2;
        ViewSetxy(eShip5[1], 33, -94);
        ViewSetxy(eShip3[1], 193, -94);
    } else if (counter3 == 30 * SpawnTime) {
        if (CurrentScreen != ScreenStoryBattle2) {
            eShip9Health = level + 24;
            ViewSetxy(eShip9, 89, -240);
        }
    } else if (counter3 == 31 * SpawnTime && CurrentScreen == ScreenStoryBattle2) {
        CurrentScreen = ScreenStory3a1;
        ScreenSwitch();
    }
}
void SetThree() {
    if (counter3 == 1 * SpawnTime) {
        eShip6Health[0] = level + 2;
        eShip2Health[0] = level + 2;
        ViewSetxy(eShip6[0], 33, -94);
        ViewSetxy(eShip2[0], 193, -94);
    } else if (counter3 == 2 * SpawnTime) {
        eShip3Health[0] = level + 2;
        eShip5Health[0] = level + 2;
        ViewSetxy(eShip3[0], 33, -94);
        ViewSetxy(eShip5[0], 193, -94);
    } else if (counter3 == 3 * SpawnTime) {
        eShip1Health[0] = level + 2;
        eShip4Health[0] = level + 2;
        eShip4Health[1] = level + 2;
        ViewSetxy(eShip1[0], 0, -94);
        ViewSetxy(eShip4[0], 113, -94);
        ViewSetxy(eShip4[1], 226, -94);
    } else if (counter3 == 4 * SpawnTime) {
        eShip1Health[1] = level + 2;
        eShip3Health[1] = level + 2;
        eShip4Health[2] = level + 2;
        ViewSetxy(eShip1[1], 0, -94);
        ViewSetxy(eShip3[1], 113, -94);
        ViewSetxy(eShip4[2], 226, -94);
    } else if (counter3 == 5 * SpawnTime) {
        eShip6Health[1] = level + 2;
        ViewSetxy(eShip6[1], 113, -94);
    } else if (counter3 == 6 * SpawnTime) {
        eShip3Health[2] = level + 2;
        eShip1Health[2] = level + 2;
        ViewSetxy(eShip3[2], 33, -94);
        ViewSetxy(eShip1[2], 193, -94);
    } else if (counter3 == 7 * SpawnTime) {
        eShip2Health[1] = level + 2;
        eShip5Health[1] = level + 2;
        ViewSetxy(eShip2[1], 33, -94);
        ViewSetxy(eShip5[1], 193, -94);
    } else if (counter3 == 8 * SpawnTime) {
        eShip6Health[2] = level + 2;
        eShip2Health[2] = level + 2;
        eShip5Health[2] = level + 2;
        ViewSetxy(eShip6[2], 0, -94);
        ViewSetxy(eShip2[2], 113, -94);
        ViewSetxy(eShip5[2], 226, -94);
    } else if (counter3 == 9 * SpawnTime) {
        eShip1Health[3] = level + 2;
        eShip4Health[3] = level + 2;
        eShip2Health[3] = level + 2;
        ViewSetxy(eShip1[3], 0, -94);
        ViewSetxy(eShip4[3], 113, -94);
        ViewSetxy(eShip2[3], 226, -94);
    } else if (counter3 == 10 * SpawnTime) {
        eShip3Health[3] = level + 2;
        eShip1Health[4] = level + 2;
        eShip5Health[3] = level + 2;
        ViewSetxy(eShip3[3], 0, -94);
        ViewSetxy(eShip1[4], 113, -94);
        ViewSetxy(eShip5[3], 226, -94);
    } else if (counter3 == 11 * SpawnTime) {
        eShip5Health[4] = level + 2;
        eShip2Health[4] = level + 2;
        eShip4Health[4] = level + 2;
        ViewSetxy(eShip5[4], 0, -94);
        ViewSetxy(eShip2[4], 113, -94);
        ViewSetxy(eShip4[4], 226, -94);
    } else if (counter3 == 12 * SpawnTime) {
        eShip6Health[3] = level + 2;
        eShip3Health[4] = level + 2;
        ViewSetxy(eShip6[3], 33, -94);
        ViewSetxy(eShip3[4], 193, -94);
    } else if (counter3 == 13 * SpawnTime) {
        eShip1Health[5] = level + 2;
        eShip3Health[5] = level + 2;
        ViewSetxy(eShip1[5], 33, -94);
        ViewSetxy(eShip3[5], 193, -94);
    } else if (counter3 == 14 * SpawnTime) {
        eShip5Health[0] = level + 2;
        eShip6Health[4] = level + 2;
        eShip5Health[1] = level + 2;
        ViewSetxy(eShip5[0], 0, -94);
        ViewSetxy(eShip6[4], 113, -94);
        ViewSetxy(eShip5[1], 226, -94);
    } else if (counter3 == 15 * SpawnTime) {
        eShip3Health[6] = level + 2;
        eShip4Health[5] = level + 2;
        eShip2Health[5] = level + 2;
        ViewSetxy(eShip3[6], 0, -94);
        ViewSetxy(eShip4[5], 113, -94);
        ViewSetxy(eShip2[5], 226, -94);
    } else if (counter3 == 16 * SpawnTime) {
        eShip6Health[0] = level + 2;
        eShip4Health[6] = level + 2;
        eShip6Health[1] = level + 2;
        ViewSetxy(eShip6[0], 0, -94);
        ViewSetxy(eShip4[6], 113, -94);
        ViewSetxy(eShip6[1], 226, -94);
    } else if (counter3 == 17 * SpawnTime) {
        eShip7Health[0] = level + 2;
        ViewSetxy(eShip7[0], 113, -94);
    } else if (counter3 == 18 * SpawnTime) {
        eShip7Health[1] = level + 2;
        eShip7Health[2] = level + 2;
        ViewSetxy(eShip7[1], 33, -94);
        ViewSetxy(eShip7[2], 193, -94);
    } else if (counter3 == 19 * SpawnTime) {
        eShip5Health[2] = level + 2;
        eShip7Health[3] = level + 2;
        eShip4Health[7] = level + 2;
        ViewSetxy(eShip5[2], 0, -94);
        ViewSetxy(eShip7[3], 113, -94);
        ViewSetxy(eShip4[7], 226, -94);
    } else if (counter3 == 20 * SpawnTime) {
        eShip3Health[7] = level + 2;
        eShip5Health[3] = level + 2;
        eShip2Health[6] = level + 2;
        ViewSetxy(eShip3[7], 0, -94);
        ViewSetxy(eShip5[3], 113, -94);
        ViewSetxy(eShip2[6], 226, -94);
    } else if (counter3 == 21 * SpawnTime) {
        eShip5Health[4] = level + 2;
        eShip7Health[4] = level + 2;
        eShip4Health[8] = level + 2;
        ViewSetxy(eShip5[4], 0, -94);
        ViewSetxy(eShip7[4], 113, -94);
        ViewSetxy(eShip4[8], 226, -94);
    } else if (counter3 == 22 * SpawnTime) {
        eShip6Health[3] = level + 2;
        eShip1Health[6] = level + 2;
        eShip3Health[8] = level + 2;
        ViewSetxy(eShip6[3], 0, -94);
        ViewSetxy(eShip1[6], 113, -94);
        ViewSetxy(eShip3[8], 226, -94);
    } else if (counter3 == 23 * SpawnTime) {
        eShip3Health[9] = level + 2;
        eShip4Health[9] = level + 2;
        ViewSetxy(eShip3[9], 33, -94);
        ViewSetxy(eShip4[9], 193, -94);
    } else if (counter3 == 24 * SpawnTime) {
        eShip7Health[0] = level + 2;
        eShip6Health[4] = level + 2;
        ViewSetxy(eShip7[0], 33, -94);
        ViewSetxy(eShip6[4], 193, -94);
    } else if (counter3 == 25 * SpawnTime) {
        eShip6Health[0] = level + 2;
        ViewSetxy(eShip6[0], 113, -94);
    } else if (counter3 == 26 * SpawnTime) {
        eShip2Health[7] = level + 2;
        eShip1Health[7] = level + 2;
        ViewSetxy(eShip2[7], 33, -94);
        ViewSetxy(eShip1[7], 193, -94);
    } else if (counter3 == 27 * SpawnTime) {
        eShip6Health[1] = level + 2;
        eShip7Health[1] = level + 2;
        ViewSetxy(eShip6[1], 33, -94);
        ViewSetxy(eShip7[1], 193, -94);
    } else if (counter3 == 28 * SpawnTime) {
        eShip3Health[1] = level + 2;
        eShip1Health[8] = level + 2;
        eShip2Health[8] = level + 2;
        ViewSetxy(eShip3[1], 0, -94);
        ViewSetxy(eShip1[8], 113, -94);
        ViewSetxy(eShip2[8], 226, -94);
    } else if (counter3 == 29 * SpawnTime) {
        eShip5Health[0] = level + 2;
        eShip7Health[2] = level + 2;
        ViewSetxy(eShip5[0], 33, -94);
        ViewSetxy(eShip7[2], 193, -94);
    } else if (counter3 == 30 * SpawnTime) {
        eShip9Health = level + 24;
        ViewSetxy(eShip9, 89, -240);
    }
}
void SetFour() {
    if (counter3 == 1 * SpawnTime) {
        eShip1Health[0] = level + 2;
        eShip2Health[0] = level + 2;
        ViewSetxy(eShip1[0], 33, -94);
        ViewSetxy(eShip2[0], 193, -94);
    } else if (counter3 == 2 * SpawnTime) {
        eShip6Health[0] = level + 2;
        eShip3Health[0] = level + 2;
        ViewSetxy(eShip6[0], 33, -94);
        ViewSetxy(eShip3[0], 193, -94);
    } else if (counter3 == 3 * SpawnTime) {
        eShip4Health[0] = level + 2;
        eShip5Health[0] = level + 2;
        eShip4Health[1] = level + 2;
        ViewSetxy(eShip4[0], 0, -94);
        ViewSetxy(eShip5[0], 113, -94);
        ViewSetxy(eShip4[1], 226, -94);
    } else if (counter3 == 4 * SpawnTime) {
        eShip1Health[1] = level + 2;
        eShip7Health[0] = level + 2;
        eShip2Health[1] = level + 2;
        ViewSetxy(eShip1[1], 0, -94);
        ViewSetxy(eShip7[0], 113, -94);
        ViewSetxy(eShip2[1], 226, -94);
    } else if (counter3 == 5 * SpawnTime) {
        eShip5Health[1] = level + 2;
        eShip3Health[1] = level + 2;
        eShip4Health[2] = level + 2;
        ViewSetxy(eShip5[1], 0, -94);
        ViewSetxy(eShip3[1], 113, -94);
        ViewSetxy(eShip4[2], 226, -94);
    } else if (counter3 == 6 * SpawnTime) {
        eShip6Health[1] = level + 2;
        eShip7Health[1] = level + 2;
        ViewSetxy(eShip6[1], 33, -94);
        ViewSetxy(eShip7[1], 193, -94);
    } else if (counter3 == 7 * SpawnTime) {
        eShip6Health[2] = level + 2;
        ViewSetxy(eShip6[2], 113, -94);
    } else if (counter3 == 8 * SpawnTime) {
        eShip7Health[2] = level + 2;
        ViewSetxy(eShip7[2], 113, -94);
    } else if (counter3 == 9 * SpawnTime) {
        eShip2Health[2] = level + 2;
        eShip1Health[2] = level + 2;
        ViewSetxy(eShip2[2], 33, -94);
        ViewSetxy(eShip1[2], 193, -94);
    } else if (counter3 == 10 * SpawnTime) {
        eShip3Health[2] = level + 2;
        eShip5Health[2] = level + 2;
        ViewSetxy(eShip3[2], 33, -94);
        ViewSetxy(eShip5[2], 193, -94);
    } else if (counter3 == 11 * SpawnTime) {
        eShip6Health[3] = level + 2;
        eShip1Health[3] = level + 2;
        eShip7Health[3] = level + 2;
        ViewSetxy(eShip6[3], 0, -94);
        ViewSetxy(eShip1[3], 113, -94);
        ViewSetxy(eShip7[3], 226, -94);
    } else if (counter3 == 12 * SpawnTime) {
        eShip4Health[3] = level + 2;
        eShip7Health[4] = level + 2;
        eShip3Health[3] = level + 2;
        ViewSetxy(eShip4[3], 0, -94);
        ViewSetxy(eShip7[4], 113, -94);
        ViewSetxy(eShip3[3], 226, -94);
    } else if (counter3 == 13 * SpawnTime) {
        eShip1Health[4] = level + 2;
        eShip6Health[4] = level + 2;
        eShip2Health[3] = level + 2;
        ViewSetxy(eShip1[4], 0, -94);
        ViewSetxy(eShip6[4], 113, -94);
        ViewSetxy(eShip2[3], 226, -94);
    } else if (counter3 == 14 * SpawnTime) {
        eShip7Health[0] = level + 2;
        ViewSetxy(eShip7[0], 113, -94);
    } else if (counter3 == 15 * SpawnTime) {
        eShip4Health[4] = level + 2;
        eShip3Health[4] = level + 2;
        ViewSetxy(eShip4[4], 33, -94);
        ViewSetxy(eShip3[4], 193, -94);
    } else if (counter3 == 16 * SpawnTime) {
        eShip1Health[5] = level + 2;
        eShip2Health[4] = level + 2;
        ViewSetxy(eShip1[5], 33, -94);
        ViewSetxy(eShip2[4], 193, -94);
    } else if (counter3 == 17 * SpawnTime) {
        eShip5Health[3] = level + 2;
        eShip6Health[0] = level + 2;
        eShip5Health[4] = level + 2;
        ViewSetxy(eShip5[3], 0, -94);
        ViewSetxy(eShip6[0], 113, -94);
        ViewSetxy(eShip5[4], 226, -94);
    } else if (counter3 == 18 * SpawnTime) {
        eShip6Health[1] = level + 2;
        eShip7Health[1] = level + 2;
        eShip3Health[5] = level + 2;
        ViewSetxy(eShip6[1], 0, -94);
        ViewSetxy(eShip7[1], 113, -94);
        ViewSetxy(eShip3[5], 226, -94);
    } else if (counter3 == 19 * SpawnTime) {
        eShip1Health[6] = level + 2;
        eShip5Health[0] = level + 2;
        eShip2Health[5] = level + 2;
        ViewSetxy(eShip1[6], 0, -94);
        ViewSetxy(eShip5[0], 113, -94);
        ViewSetxy(eShip2[5], 226, -94);
    } else if (counter3 == 20 * SpawnTime) {
        eShip7Health[2] = level + 2;
        eShip4Health[5] = level + 2;
        eShip5Health[1] = level + 2;
        ViewSetxy(eShip7[2], 0, -94);
        ViewSetxy(eShip4[5], 113, -94);
        ViewSetxy(eShip5[6], 226, -94);
    } else if (counter3 == 21 * SpawnTime) {
        eShip8Health[0] = level + 2;
        ViewSetxy(eShip1[0], 113, -94);
    } else if (counter3 == 22 * SpawnTime) {
        eShip7Health[3] = level + 2;
        eShip8Health[1] = level + 2;
        ViewSetxy(eShip7[3], 33, -94);
        ViewSetxy(eShip8[1], 193, -94);
    } else if (counter3 == 23 * SpawnTime) {
        eShip1Health[7] = level + 2;
        eShip2Health[6] = level + 2;
        ViewSetxy(eShip1[7], 33, -94);
        ViewSetxy(eShip2[6], 193, -94);
    } else if (counter3 == 24 * SpawnTime) {
        eShip4Health[6] = level + 2;
        eShip3Health[6] = level + 2;
        ViewSetxy(eShip4[6], 33, -94);
        ViewSetxy(eShip3[6], 193, -94);
    } else if (counter3 == 25 * SpawnTime) {
        eShip7Health[4] = level + 2;
        eShip8Health[2] = level + 2;
        eShip4Health[7] = level + 2;
        ViewSetxy(eShip7[4], 0, -94);
        ViewSetxy(eShip8[2], 113, -94);
        ViewSetxy(eShip4[7], 226, -94);
    } else if (counter3 == 26 * SpawnTime) {
        eShip6Health[2] = level + 2;
        eShip2Health[7] = level + 2;
        eShip6Health[3] = level + 2;
        ViewSetxy(eShip6[2], 0, -94);
        ViewSetxy(eShip2[7], 113, -94);
        ViewSetxy(eShip6[3], 226, -94);
    } else if (counter3 == 27 * SpawnTime) {
        eShip1Health[8] = level + 2;
        eShip5Health[2] = level + 2;
        eShip1Health[9] = level + 2;
        ViewSetxy(eShip1[8], 0, -94);
        ViewSetxy(eShip5[2], 113, -94);
        ViewSetxy(eShip1[9], 226, -94);
    } else if (counter3 == 28 * SpawnTime) {
        eShip8Health[3] = level + 2;
        eShip3Health[7] = level + 2;
        eShip8Health[4] = level + 2;
        ViewSetxy(eShip8[3], 0, -94);
        ViewSetxy(eShip3[7], 113, -94);
        ViewSetxy(eShip8[4], 226, -94);
    } else if (counter3 == 29 * SpawnTime) {
        eShip5Health[3] = level + 2;
        eShip2Health[8] = level + 2;
        ViewSetxy(eShip5[3], 33, -94);
        ViewSetxy(eShip2[8], 193, -94);
    } else if (counter3 == 30 * SpawnTime) {
        if (CurrentScreen != ScreenStoryBattle5) {
            eShip9Health = level + 24;
            ViewSetxy(eShip9, 89, -240);
        }
    } else if (counter3 == 31 * SpawnTime && CurrentScreen == ScreenStoryBattle5) {
        CurrentScreen = ScreenStory6a1;
        ScreenSwitch();
    }
}
void SetFive() {
    if (counter3 == 1 * SpawnTime) {
        eShip6Health[0] = level + 2;
        ViewSetxy(eShip6[0], 113, -94);
    } else if (counter3 == 2 * SpawnTime) {
        eShip7Health[0] = level + 2;
        eShip2Health[0] = level + 2;
        ViewSetxy(eShip7[0], 33, -94);
        ViewSetxy(eShip2[0], 193, -94);
    } else if (counter3 == 3 * SpawnTime) {
        eShip1Health[0] = level + 2;
        eShip8Health[0] = level + 2;
        ViewSetxy(eShip1[0], 33, -94);
        ViewSetxy(eShip8[0], 193, -94);
    } else if (counter3 == 4 * SpawnTime) {
        eShip5Health[0] = level + 2;
        eShip6Health[1] = level + 2;
        eShip4Health[0] = level + 2;
        ViewSetxy(eShip5[0], 0, -94);
        ViewSetxy(eShip6[1], 113, -94);
        ViewSetxy(eShip4[0], 226, -94);
    } else if (counter3 == 5 * SpawnTime) {
        eShip3Health[0] = level + 2;
        eShip1Health[1] = level + 2;
        eShip7Health[1] = level + 2;
        ViewSetxy(eShip3[0], 0, -94);
        ViewSetxy(eShip1[1], 113, -94);
        ViewSetxy(eShip7[1], 226, -94);
    } else if (counter3 == 6 * SpawnTime) {
        eShip7Health[2] = level + 2;
        eShip8Health[1] = level + 2;
        eShip6Health[2] = level + 2;
        ViewSetxy(eShip7[2], 0, -94);
        ViewSetxy(eShip8[1], 113, -94);
        ViewSetxy(eShip6[2], 226, -94);
    } else if (counter3 == 7 * SpawnTime) {
        eShip3Health[1] = level + 2;
        eShip1Health[2] = level + 2;
        eShip4Health[1] = level + 2;
        ViewSetxy(eShip3[1], 0, -94);
        ViewSetxy(eShip1[2], 113, -94);
        ViewSetxy(eShip4[1], 226, -94);
    } else if (counter3 == 8 * SpawnTime) {
        eShip2Health[1] = level + 2;
        eShip7Health[3] = level + 2;
        ViewSetxy(eShip2[1], 33, -94);
        ViewSetxy(eShip7[3], 193, -94);
    } else if (counter3 == 9 * SpawnTime) {
        eShip6Health[3] = level + 2;
        eShip3Health[2] = level + 2;
        ViewSetxy(eShip6[3], 33, -94);
        ViewSetxy(eShip3[2], 193, -94);
    } else if (counter3 == 10 * SpawnTime) {
        eShip6Health[4] = level + 2;
        ViewSetxy(eShip6[4], 113, -94);
    } else if (counter3 == 11 * SpawnTime) {
        eShip8Health[2] = level + 2;
        ViewSetxy(eShip8[2], 113, -94);
    } else if (counter3 == 12 * SpawnTime) {
        eShip5Health[1] = level + 2;
        eShip1Health[3] = level + 2;
        eShip6Health[0] = level + 2;
        ViewSetxy(eShip5[1], 0, -94);
        ViewSetxy(eShip1[3], 113, -94);
        ViewSetxy(eShip6[0], 226, -94);
    } else if (counter3 == 13 * SpawnTime) {
        eShip4Health[2] = level + 2;
        eShip3Health[3] = level + 2;
        eShip5Health[2] = level + 2;
        ViewSetxy(eShip4[2], 0, -94);
        ViewSetxy(eShip3[3], 113, -94);
        ViewSetxy(eShip5[2], 226, -94);
    } else if (counter3 == 14 * SpawnTime) {
        eShip2Health[2] = level + 2;
        eShip6Health[1] = level + 2;
        eShip3Health[4] = level + 2;
        ViewSetxy(eShip2[2], 0, -94);
        ViewSetxy(eShip6[1], 113, -94);
        ViewSetxy(eShip3[4], 226, -94);
    } else if (counter3 == 15 * SpawnTime) {
        eShip8Health[3] = level + 2;
        eShip4Health[3] = level + 2;
        ViewSetxy(eShip8[3], 33, -94);
        ViewSetxy(eShip4[3], 193, -94);
    } else if (counter3 == 16 * SpawnTime) {
        eShip3Health[5] = level + 2;
        eShip6Health[2] = level + 2;
        ViewSetxy(eShip3[5], 33, -94);
        ViewSetxy(eShip6[2], 193, -94);
    } else if (counter3 == 17 * SpawnTime) {
        eShip8Health[4] = level + 2;
        eShip5Health[3] = level + 2;
        eShip6Health[3] = level + 2;
        ViewSetxy(eShip8[4], 0, -94);
        ViewSetxy(eShip5[3], 113, -94);
        ViewSetxy(eShip6[3], 226, -94);
    } else if (counter3 == 18 * SpawnTime) {
        eShip7Health[4] = level + 2;
        ViewSetxy(eShip7[4], 113, -94);
    } else if (counter3 == 19 * SpawnTime) {
        eShip8Health[0] = level + 2;
        ViewSetxy(eShip8[0], 113, -94);
    } else if (counter3 == 20 * SpawnTime) {
        eShip5Health[4] = level + 2;
        eShip6Health[4] = level + 2;
        ViewSetxy(eShip5[4], 33, -94);
        ViewSetxy(eShip6[4], 193, -94);
    } else if (counter3 == 21 * SpawnTime) {
        eShip8Health[1] = level + 2;
        eShip6Health[0] = level + 2;
        eShip7Health[0] = level + 2;
        ViewSetxy(eShip8[1], 0, -94);
        ViewSetxy(eShip6[0], 113, -94);
        ViewSetxy(eShip7[0], 226, -94);
    } else if (counter3 == 22 * SpawnTime) {
        eShip2Health[3] = level + 2;
        eShip4Health[4] = level + 2;
        eShip3Health[6] = level + 2;
        ViewSetxy(eShip2[3], 0, -94);
        ViewSetxy(eShip4[4], 113, -94);
        ViewSetxy(eShip3[6], 226, -94);
    } else if (counter3 == 23 * SpawnTime) {
        eShip6Health[1] = level + 2;
        eShip2Health[4] = level + 2;
        eShip5Health[0] = level + 2;
        ViewSetxy(eShip6[1], 0, -94);
        ViewSetxy(eShip2[4], 113, -94);
        ViewSetxy(eShip5[0], 226, -94);
    } else if (counter3 == 24 * SpawnTime) {
        eShip8Health[2] = level + 2;
        eShip7Health[1] = level + 2;
        eShip6Health[2] = level + 2;
        ViewSetxy(eShip8[2], 0, -94);
        ViewSetxy(eShip7[1], 113, -94);
        ViewSetxy(eShip6[2], 226, -94);
    } else if (counter3 == 25 * SpawnTime) {
        eShip2Health[5] = level + 2;
        eShip7Health[2] = level + 2;
        eShip3Health[7] = level + 2;
        ViewSetxy(eShip2[5], 0, -94);
        ViewSetxy(eShip7[2], 113, -94);
        ViewSetxy(eShip3[7], 226, -94);
    } else if (counter3 == 26 * SpawnTime) {
        eShip8Health[3] = level + 2;
        eShip1Health[4] = level + 2;
        ViewSetxy(eShip8[3], 33, -94);
        ViewSetxy(eShip1[4], 193, -94);
    } else if (counter3 == 27 * SpawnTime) {
        eShip2Health[6] = level + 2;
        eShip5Health[1] = level + 2;
        eShip3Health[8] = level + 2;
        ViewSetxy(eShip2[6], 0, -94);
        ViewSetxy(eShip5[1], 113, -94);
        ViewSetxy(eShip3[8], 226, -94);
    } else if (counter3 == 28 * SpawnTime) {
        eShip7Health[3] = level + 2;
        eShip5Health[2] = level + 2;
        eShip6Health[3] = level + 2;
        ViewSetxy(eShip7[3], 0, -94);
        ViewSetxy(eShip5[2], 113, -94);
        ViewSetxy(eShip6[3], 226, -94);
    } else if (counter3 == 29 * SpawnTime) {
        eShip6Health[3] = level + 2;
        eShip8Health[4] = level + 2;
        ViewSetxy(eShip6[3], 33, -94);
        ViewSetxy(eShip8[4], 193, -94);
    } else if (counter3 == 30 * SpawnTime) {
        eShip10Health = level + 49;
        ViewSetxy(eShip10, 85, -240);
    }
}
void EnemyShipMove() {
    for (int i = 0; i < 10; i++) {
        //x cords
        eShipY1[i] = ViewGety(eShip1[i]);
        eShipY2[i] = ViewGety(eShip2[i]);
        eShipY3[i] = ViewGety(eShip3[i]);
        eShipY4[i] = ViewGety(eShip4[i]);
        //y cords
        eShipX1[i] = ViewGetx(eShip1[i]);
        eShipX2[i] = ViewGetx(eShip2[i]);
        eShipX3[i] = ViewGetx(eShip3[i]);
        eShipX4[i] = ViewGetx(eShip4[i]);
    }
    for (int i = 0; i < 5; i++) {
        //x cords
        eShipY5[i] = ViewGety(eShip5[i]);
        eShipY6[i] = ViewGety(eShip6[i]);
        eShipY7[i] = ViewGety(eShip7[i]);
        eShipY8[i] = ViewGety(eShip8[i]);
        //y cords
        eShipX5[i] = ViewGetx(eShip5[i]);
        eShipX6[i] = ViewGetx(eShip6[i]);
        eShipX7[i] = ViewGetx(eShip7[i]);
        eShipX8[i] = ViewGetx(eShip8[i]);
    }
    //x cords
    eShipX9 = ViewGetx(eShip9);
    //y cords
    eShipY9 = ViewGety(eShip9);
    //x cords
    eShipX10 = ViewGetx(eShip10);
    //y cords
    eShipY10 = ViewGety(eShip10);
    for (int i = 0; i < 10; i++) {
        if (eShipY1[i] < 600) {
            ViewSetxy(eShip1[i], eShipX1[i], eShipY1[i] + EnemyFlySpeed);
        }
        if (eShipY2[i] < 600) {
            ViewSetxy(eShip2[i], eShipX2[i], eShipY2[i] + EnemyFlySpeed);
        }
        if (eShipY3[i] < 600) {
            ViewSetxy(eShip3[i], eShipX3[i], eShipY3[i] + EnemyFlySpeed);
        }
        if (eShipY4[i] < 600) {
            ViewSetxy(eShip4[i], eShipX4[i], eShipY4[i] + EnemyFlySpeed);
        }
    }
    for (int i = 0; i < 5; i++) {
        if (eShipY5[i] < 600) {
            ViewSetxy(eShip5[i], eShipX5[i], eShipY5[i] + EnemyFlySpeed);
        }
        if (eShipY6[i] < 600) {
            ViewSetxy(eShip6[i], eShipX6[i], eShipY6[i] + EnemyFlySpeed);
        }
        if (eShipY7[i] < 600) {
            ViewSetxy(eShip7[i], eShipX7[i], eShipY7[i] + EnemyFlySpeed);
        }
        if (eShipY8[i] < 600) {
            ViewSetxy(eShip8[i], eShipX8[i], eShipY8[i] + EnemyFlySpeed);
        }
    }
    //ship 9
    if (eShipY9 < 40) {
        ViewSetxy(eShip9, eShipX9, eShipY9 + EnemyFlySpeed);
    } else if (eShipY9 >= 40 && eShipY9 < 600) {
        if (GoRight == false) {
            ViewSetxy(eShip9, eShipX9 - 1, eShipY9);
        } else if (GoRight == true) {
            ViewSetxy(eShip9, eShipX9 + 1, eShipY9);
        }
    }
    if (eShipX9 == 29) {
        GoRight = true;
    } else if (eShipX9 == 149) {
        GoRight = false;
    }
    //ship 10
    if (eShipY10 < 40) {
        ViewSetxy(eShip10, eShipX10, eShipY10 + EnemyFlySpeed);
    } else if (eShipY10 >= 40 && eShipY10 < 600) {
        if (GoRight == false) {
            ViewSetxy(eShip10, eShipX10 - 1, eShipY10);
        } else if (GoRight == true) {
            ViewSetxy(eShip10, eShipX10 + 1, eShipY10);
        }
    }
    if (eShipX10 == 25) {
        GoRight = true;
    } else if (eShipX10 == 145) {
        GoRight = false;
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
            counter3 = 0;
            level += 1;
            set = 1;
            break;
    }
}
void DoEnemyShipShoot() {
    int ex, ey, ex2, ey2, ex3, ey3;
    for (int i = 0; i < 5; i++) {
        if (counter4 == (i + 1) * EnemyShootCooldownSpeed) {
            //ship 1-4
            for (int j = 0; j < 10; j++) {
                ViewSetxy(e1Bullet1[10 * i + j], eShipX1[j] + e1BulletXOffset, eShipY1[j] + e1BulletYOffset);
                ViewSetxy(e2Bullet1[10 * i + j], eShipX2[j] + e2BulletXOffset, eShipY2[j] + e2BulletYOffset);
                ViewSetxy(e3Bullet1[10 * i + j], eShipX3[j] + e3BulletXOffset, eShipY3[j] + e3BulletYOffset);
                ViewSetxy(e4Bullet1[10 * i + j], eShipX4[j] + e4BulletXOffset, eShipY4[j] + e4BulletYOffset);
            }
            //ship 5-8
            for (int j = 0; j < 5; j++) {
                ViewSetxy(e5Bullet1[5 * i + j], eShipX5[j] + e5BulletXOffset, eShipY5[j] + e5BulletYOffset);
                ViewSetxy(e5Bullet3[5 * i + j], eShipX5[j] + e5BulletXOffset3, eShipY5[j] + e5BulletYOffset3);
                ViewSetxy(e6Bullet1[5 * i + j], eShipX6[j] + e6BulletXOffset, eShipY6[j] + e6BulletYOffset);
                ViewSetxy(e6Bullet3[5 * i + j], eShipX6[j] + e6BulletXOffset3, eShipY6[j] + e6BulletYOffset3);
                ViewSetxy(e7Bullet2[5 * i + j], eShipX7[j] + e7BulletXOffset2, eShipY7[j] + e7BulletYOffset2);
                ViewSetxy(e8Bullet1[5 * i + j], eShipX8[j] + e8BulletXOffset, eShipY8[j] + e8BulletYOffset);
                ViewSetxy(e8Bullet2[5 * i + j], eShipX8[j] + e8BulletXOffset2, eShipY8[j] + e8BulletYOffset2);
                ViewSetxy(e8Bullet3[5 * i + j], eShipX8[j] + e8BulletXOffset3, eShipY8[j] + e8BulletYOffset3);
            }
            //ship 9
            ViewSetxy(e9Bullet1[i], eShipX9 + e9BulletXOffset, eShipY9 + e9BulletYOffset);
            ViewSetxy(e9Bullet2[i], eShipX9 + e9BulletXOffset2, eShipY9 + e9BulletYOffset2);
            ViewSetxy(e9Bullet3[i], eShipX9 + e9BulletXOffset3, eShipY9 + e9BulletYOffset3);
            //ship 10
            ViewSetxy(e10Bullet1[i], eShipX10 + e10BulletXOffset, eShipY10 + e10BulletYOffset);
            ViewSetxy(e10Bullet2[i], eShipX10 + e10BulletXOffset2, eShipY10 + e10BulletYOffset2);
            ViewSetxy(e10Bullet3[i], eShipX10 + e10BulletXOffset3, eShipY10 + e10BulletYOffset3);
        }
    }
    if (counter4 >= 5 * EnemyShootCooldownSpeed) {
        counter4 = 0;
    }
    if (counter4 % EnemyShootCooldownSpeed != 0) {
        //1
        for (int i = 0; i < 50; i++) {
            ex = ViewGetx(e1Bullet1[i]);
            ey = ViewGety(e1Bullet1[i]);
            if (ey < 600) {
                ViewSetxy(e1Bullet1[i], ex, ey + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e1Bullet1[i], 600, 600);
            }
        }
        //2
        for (int i = 0; i < 50; i++) {
            ex = ViewGetx(e2Bullet1[i]);
            ey = ViewGety(e2Bullet1[i]);
            if (ey < 600) {
                ViewSetxy(e2Bullet1[i], ex, ey + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e2Bullet1[i], 600, 600);
            }
        }
        //3
        for (int i = 0; i < 50; i++) {
            ex = ViewGetx(e3Bullet1[i]);
            ey = ViewGety(e3Bullet1[i]);
            if (ey < 600) {
                ViewSetxy(e3Bullet1[i], ex, ey + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e3Bullet1[i], 600, 600);
            }
        }
        //4
        for (int i = 0; i < 50; i++) {
            ex = ViewGetx(e4Bullet1[i]);
            ey = ViewGety(e4Bullet1[i]);
            if (ey < 600) {
                ViewSetxy(e4Bullet1[i], ex, ey + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e4Bullet1[i], 600, 600);
            }
        }
        //5
        for (int i = 0; i < 25; i++) {
            ex = ViewGetx(e5Bullet1[i]);
            ey = ViewGety(e5Bullet1[i]);
            ex3 = ViewGetx(e5Bullet3[i]);
            ey3 = ViewGety(e5Bullet3[i]);
            if (ey < 600 || ey3 < 600) {
                ViewSetxy(e5Bullet1[i], ex, ey + EnemyBulletSpeed);
                ViewSetxy(e5Bullet3[i], ex3, ey3 + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e5Bullet1[i], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e5Bullet3[i], 600, 600);
            }
        }
        //6
        for (int i = 0; i < 25; i++) {
            ex = ViewGetx(e6Bullet1[i]);
            ey = ViewGety(e6Bullet1[i]);
            ex3 = ViewGetx(e6Bullet3[i]);
            ey3 = ViewGety(e6Bullet3[i]);
            if (ey < 600 || ey3 < 600) {
                ViewSetxy(e6Bullet1[i], ex, ey + EnemyBulletSpeed);
                ViewSetxy(e6Bullet3[i], ex3, ey3 + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e6Bullet1[i], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e6Bullet3[i], 600, 600);
            }
        }
        //7
        for (int i = 0; i < 25; i++) {
            ex2 = ViewGetx(e7Bullet2[i]);
            ey2 = ViewGety(e7Bullet2[i]);
            if (ey2 < 600) {
                ViewSetxy(e7Bullet2[i], ex2, ey2 + EnemyBulletSpeed);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                HealthUpdate = true;
                ViewSetxy(e7Bullet2[i], 600, 600);
            }
        }
        //8
        for (int i = 0; i < 25; i++) {
            ex = ViewGetx(e8Bullet1[i]);
            ey = ViewGety(e8Bullet1[i]);
            ex2 = ViewGetx(e8Bullet2[i]);
            ey2 = ViewGety(e8Bullet2[i]);
            ex3 = ViewGetx(e8Bullet3[i]);
            ey3 = ViewGety(e8Bullet3[i]);
            if (ey < 600 || ey2 < 600 || ey3 < 600) {
                ViewSetxy(e8Bullet1[i], ex, ey + EnemyBulletSpeed);
                ViewSetxy(e8Bullet2[i], ex2, ey2 + EnemyBulletSpeed);
                ViewSetxy(e8Bullet3[i], ex3, ey3 + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e8Bullet1[i], 600, 600);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                HealthUpdate = true;
                ViewSetxy(e8Bullet2[i], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e8Bullet3[i], 600, 600);
            }
        }
        //9
        for (int i = 0; i < 5; i++) {
            ex = ViewGetx(e9Bullet1[i]);
            ey = ViewGety(e9Bullet1[i]);
            ex2 = ViewGetx(e9Bullet2[i]);
            ey2 = ViewGety(e9Bullet2[i]);
            ex3 = ViewGetx(e9Bullet3[i]);
            ey3 = ViewGety(e9Bullet3[i]);
            if (ey < 600 || ey2 < 600 || ey3 < 600) {
                ViewSetxy(e9Bullet1[i], ex, ey + EnemyBulletSpeed);
                ViewSetxy(e9Bullet2[i], ex2, ey2 + EnemyBulletSpeed);
                ViewSetxy(e9Bullet3[i], ex3, ey3 + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e9Bullet1[i], 600, 600);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                HealthUpdate = true;
                ViewSetxy(e9Bullet2[i], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e9Bullet3[i], 600, 600);
            }
        }
        //10
        for (int i = 0; i < 5; i++) {
            ex = ViewGetx(e10Bullet1[i]);
            ey = ViewGety(e10Bullet1[i]);
            ex2 = ViewGetx(e10Bullet2[i]);
            ey2 = ViewGety(e10Bullet2[i]);
            ex3 = ViewGetx(e10Bullet3[i]);
            ey3 = ViewGety(e10Bullet3[i]);
            if (ey < 600 || ey2 < 600 || ey3 < 600) {
                ViewSetxy(e10Bullet1[i], ex, ey + EnemyBulletSpeed);
                ViewSetxy(e10Bullet2[i], ex2, ey2 + EnemyBulletSpeed);
                ViewSetxy(e10Bullet3[i], ex3, ey3 + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e10Bullet1[i], 600, 600);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                HealthUpdate = true;
                ViewSetxy(e10Bullet2[i], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e10Bullet3[i], 600, 600);
            }
        }
    }
}
bool ShipInAction(int ship) {
	bool ret = false;
	switch (ship) {
		case 1:
			ret = eShip1Health[counter10] <= 0 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 
				&& eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320;
			break;
		case 2:
			ret = eShip2Health[counter10] <= 0 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 
				&& eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320;
			break;
		case 3:
			ret = eShip3Health[counter10] <= 0 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 
				&& eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320;
			break;
		case 4:
			ret = eShip4Health[counter10] <= 0 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 
				&& eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320;
			break;
		case 5:
			ret = eShip5Health[counter10] <= 0 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 
				&& eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320;
			break;
		case 6:
			ret = eShip6Health[counter10] <= 0 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 
				&& eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320;
			break;
		case 7:
			ret = eShip7Health[counter10] <= 0 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 
				&& eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320;
			break;
		case 8:
			ret = eShip8Health[counter10] <= 0 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 
				&& eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320;
			break;
	}
	return ret;
}
int SetEnemyExplosion (int ship) {
	int explosion;;
	switch (ship) {
		case 1:
			explosion = (eShip1[counter10]);
			break;
		case 2:
			explosion = (eShip2[counter10]);
			break;
		case 3:
			explosion = (eShip3[counter10]);
			break;
		case 4:
			explosion = (eShip4[counter10]);
			break;
		case 5:
			explosion = (eShip5[counter10]);
			break;
		case 6:
			explosion = (eShip6[counter10]);
			break;
		case 7:
			explosion = (eShip7[counter10]);
			break;
		case 8:
			explosion = (eShip8[counter10]);
			break;
	}
	return explosion;
}
void EnemyDied() {
    //TODO: make this more concise
    int explosion, image;
	for (int i = 1; i <= 4; i++) {
		for (counter10 = 0; counter10 < 10; counter10++) {
			bool used = false;
			for (int j = 0; j <= 8; j++) {
				if (counter5[i - 1] == j && ShipInAction(i) && !used) {
					explosion = SetEnemyExplosion(i);
					char temp[] = "Images/Explosion_1.png";
					temp[17] = char(j + 1 + '0');
					image = ImageAdd(temp);
					ViewSetImage(explosion, image);
					counter5[i - 1] += 1;
					used = true;
				}
			}
			if (counter5[i - 1] == 9 && ShipInAction(i)) {
				explosion = SetEnemyExplosion(i);
				image = ImageAdd("Images/Explosion_10.png");
				ViewSetImage(explosion, image);
				counter5[i - 1] += 1;
			} else if (counter5[i - 1] == 10 && ShipInAction(i)) {
				explosion = SetEnemyExplosion(i);
				image = ImageAdd("Images/Explosion_11.png");
				ViewSetImage(explosion, image);
				counter5[i - 1] += 1;
			} else if (counter5[i - 1] == 11 && ShipInAction(i)) {
				explosion = SetEnemyExplosion(i);
				char tempShip[] = "Images/eShip_1.png";
				tempShip[13] = char(i + '0');
				image = ImageAdd(tempShip);
				ViewSetImage(explosion, image);
				if (i == 1) {
					ViewSetxy(eShip1[counter10], 600, 600);
				} else if (i == 2) {
					ViewSetxy(eShip2[counter10], 600, 600);
				} else if (i == 3) {
					ViewSetxy(eShip3[counter10], 600, 600);
				} else if (i == 4) {
					ViewSetxy(eShip4[counter10], 600, 600);
				}
				counter5[i - 1] = 0;
				xp += 1 * level;
			}
		}
	}
 
    for (counter10 = 0; counter10 < 5; counter10++) {
        if (eShip5Health[counter10] <= 0 && counter5[4] == 0 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_1.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 1 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_2.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 2 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_3.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 3 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_4.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 4 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_5.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 5 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_6.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 6 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_7.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 7 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_8.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 8 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_9.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 9 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_10.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 10 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/Explosion_11.png");
            ViewSetImage(explosion, image);
            counter5[4] += 1;
        } else if (eShip5Health[counter10] <= 0 && counter5[4] == 11 && eShipY5[counter10] >= 0 && eShipX5[counter10] < 600 && eShipY5[counter10] >= 0 && eShipX5[counter10] <= 320) {
            explosion = (eShip5[counter10]);
            image = ImageAdd("Images/eShip_5.png");
            ViewSetImage(explosion, image);
            ViewSetxy(eShip5[counter10], 600, 600);
            counter5[4] = 0;
            xp += level * 2;
        }
    }
    for (counter10 = 0; counter10 < 5; counter10++) {
        if (eShip6Health[counter10] <= 0 && counter5[5] == 0 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_1.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 1 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_2.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 2 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_3.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 3 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_4.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 4 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_5.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 5 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_6.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 6 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_7.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 7 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_8.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 8 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_9.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 9 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_10.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 10 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/Explosion_11.png");
            ViewSetImage(explosion, image);
            counter5[5] += 1;
        } else if (eShip6Health[counter10] <= 0 && counter5[5] == 11 && eShipY6[counter10] >= 0 && eShipX6[counter10] < 600 && eShipY6[counter10] >= 0 && eShipX6[counter10] <= 320) {
            explosion = (eShip6[counter10]);
            image = ImageAdd("Images/eShip_6.png");
            ViewSetImage(explosion, image);
            ViewSetxy(eShip6[counter10], 600, 600);
            counter5[5] = 0;
            xp += level * 2;
        }
    }
    for (counter10 = 0; counter10 < 5; counter10++) {
        if (eShip7Health[counter10] <= 0 && counter5[6] == 0 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_1.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 1 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_2.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 2 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_3.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 3 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_4.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 4 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_5.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 5 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_6.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 6 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_7.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 7 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_8.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 8 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_9.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 9 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_10.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 10 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/Explosion_11.png");
            ViewSetImage(explosion, image);
            counter5[6] += 1;
        } else if (eShip7Health[counter10] <= 0 && counter5[6] == 11 && eShipY7[counter10] >= 0 && eShipX7[counter10] < 600 && eShipY7[counter10] >= 0 && eShipX7[counter10] <= 320) {
            explosion = (eShip7[counter10]);
            image = ImageAdd("Images/eShip_7.png");
            ViewSetImage(explosion, image);
            ViewSetxy(eShip7[counter10], 600, 600);
            counter5[6] = 0;
            xp += level * 2;
        }
    }
    for (counter10 = 0; counter10 < 5; counter10++) {
        if (eShip8Health[counter10] <= 0 && counter5[7] == 0 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_1.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 1 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_2.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 2 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_3.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 3 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_4.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 4 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_5.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 5 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_6.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 6 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_7.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 7 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_8.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 8 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_9.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 9 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_10.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 10 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/Explosion_11.png");
            ViewSetImage(explosion, image);
            counter5[7] += 1;
        } else if (eShip8Health[counter10] <= 0 && counter5[7] == 11 && eShipY8[counter10] >= 0 && eShipX8[counter10] < 600 && eShipY8[counter10] >= 0 && eShipX8[counter10] <= 320) {
            explosion = (eShip8[counter10]);
            image = ImageAdd("Images/eShip_8.png");
            ViewSetImage(explosion, image);
            ViewSetxy(eShip8[counter10], 600, 600);
            counter5[7] = 0;
            xp += level * 3;
        }
    }
    if (eShip9Health <= 0 && counter5[8] == 0 && eShipY9 >= 0 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_1.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 1 && eShipY9 >= 1 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_2.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 2 && eShipY9 >= 2 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_3.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 3 && eShipY9 >= 3 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_4.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 4 && eShipY9 >= 4 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_5.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 5 && eShipY9 >= 5 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_6.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 6 && eShipY9 >= 6 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_7.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 7 && eShipY9 >= 7 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_8.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 8 && eShipY9 >= 8 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_9.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 9 && eShipY9 >= 9 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_10.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 10 && eShipY9 >= 10 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/BigExplosion_11.png");
        ViewSetImage(explosion, image);
        counter5[8] += 1;
    } else if (eShip9Health <= 0 && counter5[8] == 11 && eShipY9 >= 11 && eShipX9 < 600 && eShipY9 >= 0 && eShipX9 <= 320) {
        explosion = (eShip9);
        image = ImageAdd("Images/eMini-Boss.png");
        ViewSetImage(explosion, image);
        ViewSetxy(eShip9, 600, 600);
        counter5[8] = 0;
        xp += level * 5;
        if (CurrentScreen != ScreenStoryBattle4) {
            set += 1;
            counter3 = 0;
            health = PossibleHealth;
            HealthUpdate = true;
        } else if (CurrentScreen == ScreenStoryBattle4) {
            CurrentScreen = ScreenStory5a1;
            ScreenSwitch();
        }
    }
    if (eShip10Health <= 0 && counter5[9] == 0 && eShipY10 >= 0 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/BigExplosion_1.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 1 && eShipY10 >= 1 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/BigExplosion_2.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 2 && eShipY10 >= 2 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/BigExplosion_3.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 3 && eShipY10 >= 3 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/BigExplosion_4.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 4 && eShipY10 >= 4 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/BigExplosion_5.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 5 && eShipY10 >= 5 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/BigExplosion_6.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 6 && eShipY10 >= 6 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/BigExplosion_7.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 7 && eShipY10 >= 7 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/Explosion_8.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 8 && eShipY10 >= 8 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/BigExplosion_9.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 9 && eShipY10 >= 9 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/BigExplosion_10.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 10 && eShipY10 >= 10 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/BigExplosion_11.png");
        ViewSetImage(explosion, image);
        counter5[9] += 1;
    } else if (eShip10Health <= 0 && counter5[9] == 11 && eShipY10 >= 11 && eShipX10 < 600 && eShipY10 >= 0 && eShipX10 <= 320) {
        explosion = (eShip10);
        image = ImageAdd("Images/eBoss.png");
        ViewSetImage(explosion, image);
        ViewSetxy(eShip10, 600, 600);
        counter5[9] = 0;
        xp += level * 7;
        if (CurrentScreen != ScreenStoryBattle6) {
            set += 1;
            counter3 = 0;
            health = PossibleHealth;
            HealthUpdate = true;
        } else if (CurrentScreen == ScreenStoryBattle6) {
            CurrentScreen = ScreenStory7w1;
            ScreenSwitch();
        }
    }
}
void ShipCollision() {
    for (int i = 0; i < 10; i++) {
        //ship 1
        if (mX + width1 < eShipX1[i] + 76 && mX + width2 > eShipX1[i] + 18 && mY < eShipY1[i] + 94 && mY + 94 > eShipY1[i]) {
            if (eShip1Health[i] > 0) {
                eShip1Health[i] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 2
        if (mX + width1 < eShipX2[i] + 69 && mX + width2 > eShipX2[i] + 24 && mY < eShipY2[i] + 94 && mY + 94 > eShipY2[i]) {
            if (eShip2Health[i] > 0) {
                eShip2Health[i] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 3
        if (mX + width1 < eShipX3[i] + 66 && mX + width2 > eShipX3[i] + 27 && mY < eShipY3[i] + 94 && mY + 94 > eShipY3[i]) {
            if (eShip3Health[i] > 0) {
                eShip3Health[i] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 4
        if (mX + width1 < eShipX4[i] + 87 && mX + width2 > eShipX4[i] + 6 && mY < eShipY4[i] + 94 && mY + 94 > eShipY4[i]) {
            if (eShip4Health[i] > 0) {
                eShip4Health[i] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        //ship 5
        if (mX + width1 < eShipX5[i] + 71 && mX + width2 > eShipX5[i] + 22 && mY < eShipY5[i] + 94 && mY + 94 > eShipY5[i]) {
            if (eShip5Health[i] > 0) {
                eShip5Health[i] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 6
        if (mX + width1 < eShipX6[i] + 81 && mX + width2 > eShipX6[i] + 12 && mY < eShipY6[i] + 94 && mY + 94 > eShipY6[i]) {
            if (eShip6Health[i] > 0) {
                eShip6Health[i] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 7
        if (mX + width1 < eShipX7[i] + 86 && mX + width2 > eShipX7[i] + 7 && mY < eShipY7[i] + 94 && mY + 94 > eShipY7[i]) {
            if (eShip7Health[i] > 0) {
                eShip7Health[i] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 8
        if (mX + width1 < eShipX8[i] + 86 && mX + width2 > eShipX8[i] + 6 && mY < eShipY8[i] + 94 && mY + 94 > eShipY8[i]) {
            if (eShip8Health[i] > 0) {
                eShip8Health[i] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
    }
    //ship 9
    if (mX + width1 < eShipX9 + 142 && mX + width2 > eShipX9 && mY < eShipY9 + 240 && mY + 94 > eShipY9) {
        if (eShip9Health > 0) {
            eShip9Health -= 2 + level;
            health -= 2 + level;
            HealthUpdate = true;
        }
    }
    //ship 10
    if (mX + width1 < eShipX10 + 150 && mX + width2 > eShipX10 && mY < eShipY10 + 240 && mY + 94 > eShipY10) {
        if (eShip10Health > 0) {
            eShip10Health -= 2 + level;
            health -= 2 + level;
            HealthUpdate = true;
        }
    }
}
void Rank() {
    if (xp >= 0 && xp < 50) {
        rank = 1;
    } else if (xp >= 50 && xp < 150) {
        rank = 2;
    } else if (xp >= 150 && xp < 300) {
        rank = 3;
    } else if (xp >= 300 && xp < 500) {
        rank = 4;
    } else if (xp >= 500 && xp < 750) {
        rank = 5;
    } else if (xp >= 750 && xp < 1050) {
        rank = 6;
    } else if (xp >= 1050 && xp < 1400) {
        rank = 7;
    } else if (xp >= 1400 && xp < 1800) {
        rank = 8;
    } else if (xp >= 1800 && xp < 2250) {
        rank = 9;
    } else if (xp >= 2250 && xp < 2750) {
        rank = 10;
    } else if (xp >= 2750 && xp < 3300) {
        rank = 11;
    } else if (xp >= 3300 && xp < 3900) {
        rank = 12;
    } else if (xp >= 3900 && xp < 4550) {
        rank = 13;
    } else if (xp >= 4550 && xp < 5250) {
        rank = 14;
    } else if (xp >= 5250 && xp < 6000) {
        rank = 15;
    } else if (xp >= 6000 && xp < 6800) {
        rank = 16;
    } else if (xp >= 6800 && xp < 7650) {
        rank = 17;
    } else if (xp >= 7650 && xp < 8550) {
        rank = 18;
    } else if (xp >= 8550 && xp < 9500) {
        rank = 19;
    } else if (xp >= 9500) {
        rank = 20;
    }
}
void HealthRegen() {
    if (counter12 >= 150) {
        counter12 = 0;
        health += 1;
        HealthUpdate = true;
    }
}
bool CreateMove() {
    bool temp = CurrentScreen == ScreenEndless || CurrentScreen == ScreenStoryBattle1
                || CurrentScreen == ScreenStoryBattle2 || CurrentScreen == ScreenStoryBattle4
                || CurrentScreen == ScreenStoryBattle5 || CurrentScreen == ScreenStoryBattle6;
    return temp;
}
void OnTimer() {
//called 30 times per second - 1800=1min - 10000=5min 36sec
    Rank();
    SoundSwitch();
    DoUpdateHighscore();
    if (sound) {
        counter += 1;
    }
    if (!pause) {
        if (CreateMove()) {
            counter2 += 1;
            counter3 += 1; //ship move counter
            DoEnemyShipMove();
            counter4 += 1; //bullet move counter
            DoEnemyShipShoot();
            if (health < PossibleHealth / 2) {
                counter12 += 1; //health regen
            } else {
                counter12 = 0;
            }
            HealthRegen();
            BulletTime();
            HealthBar();
            mShipMove();
            EnemyDied();
            ShipCollision();
        } else if (CurrentScreen == ScreenStoryTorture && torture) {
            if (CounterTorture == 0) {
                ViewSetxy(ImageTorture, -1, -1);
            } else if (CounterTorture == 1) {
                ViewSetxy(ImageTorture, 0, 0);
            } else if (CounterTorture == 2) {
                ViewSetxy(ImageTorture, -2, -2);
            } else if (CounterTorture == 3) {
                ViewSetxy(ImageTorture, -1, -1);
            } else if (CounterTorture == 4) {
                ViewSetxy(ImageTorture, -2, 0);
            } else if (CounterTorture == 5) {
                ViewSetxy(ImageTorture, 0, -2);
            }
            HpCounterTorture -= 3;
            CounterTorture += 1;
            if (CounterTorture >= 6) {
                CounterTorture = 0;
            }
            TortureHealth();
        } else if (CurrentScreen == ScreenStoryTorture && !torture) {
            HpCounterTorture += 1;
            TortureHealth();
            TextSetText(TextTorture, "");
        }
    }
}
