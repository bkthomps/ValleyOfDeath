/**
 * Bailey Thompson
 * Valley Of Death (1.1.8)
 * 1 January 2017
 */
#include "DragonFireSDK.h"
//essential save variables
bool sound, UpdateHighscore;
int xp, ship, highscore;
int counter;
//possible save variables
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
//don't save these variables
int FileSound, FileUpdateHighscore;
int FileXp, FileShip, FileHighscore;
int FileCounter;
char FileBuffer[5];
bool BoolTempNum;
int IntTempNum;
//Screen CurrentScreen, PreviousScreen;
int Mp3Handle;
char font, FontTorture;
int width1, width2, HP, text1, text2, text3;
bool torture;
int CounterTorture, ImageTorture, HpTorture, TextTorture;
int counter6, counter7, counter8, counter9, counter10, counter11, counter12;
int r, s2, s3, s4, s5, s6, s7, s8, music;
int PossibleHealth, ShipSpeed, SaveRon, rank;
int BulletXOffset, BulletYOffset, BulletXOffset2, BulletYOffset2, BulletXOffset3, BulletYOffset3;
int e1BulletXOffset = 43, e1BulletYOffset = 83;
int e2BulletXOffset = 43, e2BulletYOffset = 94;
int e3BulletXOffset = 43, e3BulletYOffset = 88;
int e4BulletXOffset = 43, e4BulletYOffset = 94;
int e5BulletXOffset = 31, e5BulletYOffset = 71, e5BulletXOffset3 = 54, e5BulletYOffset3 = 71;
int e6BulletXOffset = 15, e6BulletYOffset = 53, e6BulletXOffset3 = 68, e6BulletYOffset3 = 53;
int e7BulletXOffset2 = 42, e7BulletYOffset2 = 83;
int e8BulletXOffset = 12, e8BulletYOffset = 54, e8BulletXOffset2 = 42, e8BulletYOffset2 = 92, e8BulletXOffset3 = 74, e8BulletYOffset3 = 54;
int e9BulletXOffset = 3, e9BulletYOffset = 83, e9BulletXOffset2 = 66, e9BulletYOffset2 = 230, e9BulletXOffset3 = 130, e9BulletYOffset3 = 83;
int e10BulletXOffset = 13, e10BulletYOffset = 83, e10BulletXOffset2 = 69, e10BulletYOffset2 = 233, e10BulletXOffset3 = 129, e10BulletYOffset3 = 83;
int speed = 15, time = 15;
int SpawnTime = 100, EnemyBaseHealth = 3, EnemyIncreaseHealth = 1, EnemyShootCooldownSpeed = 45, EnemyFlySpeed = 3, EnemyBulletSpeed = 8;
bool HealthUpdate, GoRight;
//end variables
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
    for (counter9 = 0; counter9 < 15; counter9++) {
        ViewSetxy(mBullet1[counter9], -10, -10);
		ViewSetxy(mBullet2[counter9], -20, -20);
		ViewSetxy(mBullet3[counter9], -10, -10);
    }
    for (counter9 = 0; counter9 < 50; counter9++) {
        ViewSetxy(e1Bullet1[counter9], 600, 600);
		ViewSetxy(e2Bullet1[counter9], 600, 600);
		ViewSetxy(e3Bullet1[counter9], 600, 600);
		ViewSetxy(e4Bullet1[counter9], 600, 600);
    }
    for (counter9 = 0; counter9 < 25; counter9++) {
        ViewSetxy(e5Bullet1[counter9], 600, 600);
        ViewSetxy(e5Bullet3[counter9], 600, 600);
		ViewSetxy(e6Bullet1[counter9], 600, 600);
        ViewSetxy(e6Bullet3[counter9], 600, 600);
		ViewSetxy(e7Bullet2[counter9], 600, 600);
		ViewSetxy(e8Bullet1[counter9], 600, 600);
        ViewSetxy(e8Bullet2[counter9], 600, 600);
        ViewSetxy(e8Bullet3[counter9], 600, 600);
    }
    for (counter9 = 0; counter9 < 5; counter9++) {
        ViewSetxy(e9Bullet1[counter9], 600, 600);
        ViewSetxy(e9Bullet2[counter9], 600, 600);
        ViewSetxy(e9Bullet3[counter9], 600, 600);
		ViewSetxy(e10Bullet1[counter9], 600, 600);
        ViewSetxy(e10Bullet2[counter9], 600, 600);
        ViewSetxy(e10Bullet3[counter9], 600, 600);
    }
    for (counter9 = 0; counter9 < 10; counter9++) {
        ViewSetxy(eShip1[counter9], 600, 600);
        ship = (eShip1[counter9]);
        picture = ImageAdd("Images/eShip_1.png");
        ViewSetImage(ship, picture);
		ViewSetxy(eShip2[counter9], 600, 600);
        ship = (eShip2[counter9]);
        picture = ImageAdd("Images/eShip_2.png");
        ViewSetImage(ship, picture);
		ViewSetxy(eShip3[counter9], 600, 600);
        ship = (eShip3[counter9]);
        picture = ImageAdd("Images/eShip_3.png");
        ViewSetImage(ship, picture);
		ViewSetxy(eShip4[counter9], 600, 600);
        ship = (eShip4[counter9]);
        picture = ImageAdd("Images/eShip_4.png");
        ViewSetImage(ship, picture);
    }
    for (counter9 = 0; counter9 < 5; counter9++) {
        ViewSetxy(eShip5[counter9], 600, 600);
        ship = (eShip5[counter9]);
        picture = ImageAdd("Images/eShip_5.png");
        ViewSetImage(ship, picture);
		ViewSetxy(eShip6[counter9], 600, 600);
        ship = (eShip6[counter9]);
        picture = ImageAdd("Images/eShip_6.png");
        ViewSetImage(ship, picture);
        ViewSetxy(eShip7[counter9], 600, 600);
        ship = (eShip7[counter9]);
        picture = ImageAdd("Images/eShip_7.png");
        ViewSetImage(ship, picture);
        ViewSetxy(eShip8[counter9], 600, 600);
        ship = (eShip8[counter9]);
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
    for (counter9 = 0; counter9 < 15; counter9++) {
        mBullet1[counter9] = ViewAdd(ContainerEndless, "Images/Bullet.png", -10, -10);
		mBullet2[counter9] = ViewAdd(ContainerEndless, "Images/Rocket.png", -20, -20);
        mBullet3[counter9] = ViewAdd(ContainerEndless, "Images/Bullet.png", -10, -10);
    }
	//TODO: why is the following line needed?
    mBullet1[0] = ViewAdd(ContainerEndless, "Images/Bullet.png", -10, -10);
    //enemy bullets
    for (counter9 = 0; counter9 < 50; counter9++) {
        e1Bullet1[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e2Bullet1[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e3Bullet1[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e4Bullet1[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
    }
    for (counter9 = 0; counter9 < 25; counter9++) {
        e5Bullet1[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e5Bullet3[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e6Bullet1[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e6Bullet3[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e7Bullet2[counter9] = ViewAdd(ContainerEndless, "Images/eRocket.png", 600, 600);
        e8Bullet1[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e8Bullet2[counter9] = ViewAdd(ContainerEndless, "Images/eRocket.png", 600, 600);
        e8Bullet3[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
    }
    for (counter9 = 0; counter9 < 5; counter9++) {
        e9Bullet1[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e9Bullet2[counter9] = ViewAdd(ContainerEndless, "Images/eRocket.png", 600, 600);
        e9Bullet3[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e10Bullet1[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
        e10Bullet2[counter9] = ViewAdd(ContainerEndless, "Images/eRocket.png", 600, 600);
        e10Bullet3[counter9] = ViewAdd(ContainerEndless, "Images/eBullet.png", 600, 600);
    }
    //ships
    for (counter9 = 0; counter9 < 10; counter9++) {
        eShip1[counter9] = ViewAdd(ContainerEndless, "Images/eShip_1.png", 600, 600);
        eShip2[counter9] = ViewAdd(ContainerEndless, "Images/eShip_2.png", 600, 600);
        eShip3[counter9] = ViewAdd(ContainerEndless, "Images/eShip_3.png", 600, 600);
        eShip4[counter9] = ViewAdd(ContainerEndless, "Images/eShip_4.png", 600, 600);
    }
    for (counter9 = 0; counter9 < 5; counter9++) {
        eShip5[counter9] = ViewAdd(ContainerEndless, "Images/eShip_5.png", 600, 600);
        eShip6[counter9] = ViewAdd(ContainerEndless, "Images/eShip_6.png", 600, 600);
        eShip7[counter9] = ViewAdd(ContainerEndless, "Images/eShip_7.png", 600, 600);
        eShip8[counter9] = ViewAdd(ContainerEndless, "Images/eShip_8.png", 600, 600);
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

void IntGameToFile() {\
	FileBuffer[0] = char(IntTempNum / 10000 + '0');
    IntTempNum -= (int) FileBuffer[0] - '0';
    FileBuffer[1] = char(IntTempNum / 1000 + '0');
    IntTempNum -= (int) FileBuffer[1] - '0';
    FileBuffer[2] = char(IntTempNum / 100 + '0');
    IntTempNum -= (int) FileBuffer[2] - '0';
    FileBuffer[3] = char(IntTempNum / 10 + '0');
    IntTempNum -= (int) FileBuffer[3] - '0';
    FileBuffer[4] = char(IntTempNum + '0');
    IntTempNum -= (int) FileBuffer[4] - '0';
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
		&& CurrentScreen != ScreenStoryBattle5  && CurrentScreen != ScreenStoryBattle6 
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
    if (counter2 == 1 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[0], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[0], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[0], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[0], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[0], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[0], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[0], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 2 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[1], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[1], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[1], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[1], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[1], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[1], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[1], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 3 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[2], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[2], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[2], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[2], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[2], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[2], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[2], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 4 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[3], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[3], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[3], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[3], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[3], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[3], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[3], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 5 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[4], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[4], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[4], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[4], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[4], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[4], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[4], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 6 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[5], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[5], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[5], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[5], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[5], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[5], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[5], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 7 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[6], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[6], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[6], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[6], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[6], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[6], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[6], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 8 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[7], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[7], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[7], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[7], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[7], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[7], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[7], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 9 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[8], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[8], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[8], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[8], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[8], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[8], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[8], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 10 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[9], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[9], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[9], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[9], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[9], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[9], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[9], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 11 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[10], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[10], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[10], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[10], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[10], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[10], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[10], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 12 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[11], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[11], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[11], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[11], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[11], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[11], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[11], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 13 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[12], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[12], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[12], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[12], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[12], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[12], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[12], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 14 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[13], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[13], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[13], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[13], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[13], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[13], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[13], mX + BulletXOffset, mY + BulletYOffset);
        }
    } else if (counter2 == 15 * time) {
        if (ship == 8) {
            ViewSetxy(mBullet1[14], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet2[14], mX + BulletXOffset2, mY + BulletYOffset2);
            ViewSetxy(mBullet3[14], mX + BulletXOffset3, mY + BulletYOffset3);
        } else if (ship == 7) {
            ViewSetxy(mBullet2[14], mX + BulletXOffset2, mY + BulletYOffset2);
        } else if (ship == 6 || ship == 5) {
            ViewSetxy(mBullet1[14], mX + BulletXOffset, mY + BulletYOffset);
            ViewSetxy(mBullet3[14], mX + BulletXOffset3, mY + BulletYOffset3);
        } else {
            ViewSetxy(mBullet1[14], mX + BulletXOffset, mY + BulletYOffset);
        }
        counter2 = 0;
    } else {
        //0
        x = ViewGetx(mBullet1[0]);
        y = ViewGety(mBullet1[0]);
        x2 = ViewGetx(mBullet2[0]);
        y2 = ViewGety(mBullet2[0]);
        x3 = ViewGetx(mBullet3[0]);
        y3 = ViewGety(mBullet3[0]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[0], x, y - speed);
            ViewSetxy(mBullet2[0], x2, y2 - speed);
            ViewSetxy(mBullet3[0], x3, y3 - speed);
        }
        counter10 = 0;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 94 && x > eShipX9 && x < eShipX9 + 240) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 94 && x2 > eShipX9 && x2 < eShipX9 + 240) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 94 && x3 > eShipX9 && x3 < eShipX9 + 240) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 94 && x > eShipX10 && x < eShipX10 + 240) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 94 && x2 > eShipX10 && x2 < eShipX10 + 240) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 94 && x3 > eShipX10 && x3 < eShipX10 + 240) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //1
        x = ViewGetx(mBullet1[1]);
        y = ViewGety(mBullet1[1]);
        x2 = ViewGetx(mBullet2[1]);
        y2 = ViewGety(mBullet2[1]);
        x3 = ViewGetx(mBullet3[1]);
        y3 = ViewGety(mBullet3[1]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[1], x, y - speed);
            ViewSetxy(mBullet2[1], x2, y2 - speed);
            ViewSetxy(mBullet3[1], x3, y3 - speed);
        }
        counter10 = 1;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //2
        x = ViewGetx(mBullet1[2]);
        y = ViewGety(mBullet1[2]);
        x2 = ViewGetx(mBullet2[2]);
        y2 = ViewGety(mBullet2[2]);
        x3 = ViewGetx(mBullet3[2]);
        y3 = ViewGety(mBullet3[2]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[2], x, y - speed);
            ViewSetxy(mBullet2[2], x2, y2 - speed);
            ViewSetxy(mBullet3[2], x3, y3 - speed);
        }
        counter10 = 2;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }

        //3
        x = ViewGetx(mBullet1[3]);
        y = ViewGety(mBullet1[3]);
        x2 = ViewGetx(mBullet2[3]);
        y2 = ViewGety(mBullet2[3]);
        x3 = ViewGetx(mBullet3[3]);
        y3 = ViewGety(mBullet3[3]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[3], x, y - speed);
            ViewSetxy(mBullet2[3], x2, y2 - speed);
            ViewSetxy(mBullet3[3], x3, y3 - speed);
        }
        counter10 = 3;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //4
        x = ViewGetx(mBullet1[4]);
        y = ViewGety(mBullet1[4]);
        x2 = ViewGetx(mBullet2[4]);
        y2 = ViewGety(mBullet2[4]);
        x3 = ViewGetx(mBullet3[4]);
        y3 = ViewGety(mBullet3[4]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[4], x, y - speed);
            ViewSetxy(mBullet2[4], x2, y2 - speed);
            ViewSetxy(mBullet3[4], x3, y3 - speed);
        }
        counter10 = 4;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //5
        x = ViewGetx(mBullet1[5]);
        y = ViewGety(mBullet1[5]);
        x2 = ViewGetx(mBullet2[5]);
        y2 = ViewGety(mBullet2[5]);
        x3 = ViewGetx(mBullet3[5]);
        y3 = ViewGety(mBullet3[5]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[5], x, y - speed);
            ViewSetxy(mBullet2[5], x2, y2 - speed);
            ViewSetxy(mBullet3[5], x3, y3 - speed);
        }
        counter10 = 5;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //6
        x = ViewGetx(mBullet1[6]);
        y = ViewGety(mBullet1[6]);
        x2 = ViewGetx(mBullet2[6]);
        y2 = ViewGety(mBullet2[6]);
        x3 = ViewGetx(mBullet3[6]);
        y3 = ViewGety(mBullet3[6]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[6], x, y - speed);
            ViewSetxy(mBullet2[6], x2, y2 - speed);
            ViewSetxy(mBullet3[6], x3, y3 - speed);
        }
        counter10 = 6;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //7
        x = ViewGetx(mBullet1[7]);
        y = ViewGety(mBullet1[7]);
        x2 = ViewGetx(mBullet2[7]);
        y2 = ViewGety(mBullet2[7]);
        x3 = ViewGetx(mBullet3[7]);
        y3 = ViewGety(mBullet3[7]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[7], x, y - speed);
            ViewSetxy(mBullet2[7], x2, y2 - speed);
            ViewSetxy(mBullet3[7], x3, y3 - speed);
        }
        counter10 = 7;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //8
        x = ViewGetx(mBullet1[8]);
        y = ViewGety(mBullet1[8]);
        x2 = ViewGetx(mBullet2[8]);
        y2 = ViewGety(mBullet2[8]);
        x3 = ViewGetx(mBullet3[8]);
        y3 = ViewGety(mBullet3[8]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[8], x, y - speed);
            ViewSetxy(mBullet2[8], x2, y2 - speed);
            ViewSetxy(mBullet3[8], x3, y3 - speed);
        }
        counter10 = 8;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //9
        x = ViewGetx(mBullet1[9]);
        y = ViewGety(mBullet1[9]);
        x2 = ViewGetx(mBullet2[9]);
        y2 = ViewGety(mBullet2[9]);
        x3 = ViewGetx(mBullet3[9]);
        y3 = ViewGety(mBullet3[9]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[9], x, y - speed);
            ViewSetxy(mBullet2[9], x2, y2 - speed);
            ViewSetxy(mBullet3[9], x3, y3 - speed);
        }
        counter10 = 9;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //10
        x = ViewGetx(mBullet1[10]);
        y = ViewGety(mBullet1[10]);
        x2 = ViewGetx(mBullet2[10]);
        y2 = ViewGety(mBullet2[10]);
        x3 = ViewGetx(mBullet3[10]);
        y3 = ViewGety(mBullet3[10]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[10], x, y - speed);
            ViewSetxy(mBullet2[10], x2, y2 - speed);
            ViewSetxy(mBullet3[10], x3, y3 - speed);
        }
        counter10 = 10;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //11
        x = ViewGetx(mBullet1[11]);
        y = ViewGety(mBullet1[11]);
        x2 = ViewGetx(mBullet2[11]);
        y2 = ViewGety(mBullet2[11]);
        x3 = ViewGetx(mBullet3[11]);
        y3 = ViewGety(mBullet3[11]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[11], x, y - speed);
            ViewSetxy(mBullet2[11], x2, y2 - speed);
            ViewSetxy(mBullet3[11], x3, y3 - speed);
        }
        counter10 = 11;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //12
        x = ViewGetx(mBullet1[12]);
        y = ViewGety(mBullet1[12]);
        x2 = ViewGetx(mBullet2[12]);
        y2 = ViewGety(mBullet2[12]);
        x3 = ViewGetx(mBullet3[12]);
        y3 = ViewGety(mBullet3[12]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[12], x, y - speed);
            ViewSetxy(mBullet2[12], x2, y2 - speed);
            ViewSetxy(mBullet3[12], x3, y3 - speed);
        }
        counter10 = 12;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //13
        x = ViewGetx(mBullet1[13]);
        y = ViewGety(mBullet1[13]);
        x2 = ViewGetx(mBullet2[13]);
        y2 = ViewGety(mBullet2[13]);
        x3 = ViewGetx(mBullet3[13]);
        y3 = ViewGety(mBullet3[13]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[13], x, y - speed);
            ViewSetxy(mBullet2[13], x2, y2 - speed);
            ViewSetxy(mBullet3[13], x3, y3 - speed);
        }
        counter10 = 13;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
        //14
        x = ViewGetx(mBullet1[14]);
        y = ViewGety(mBullet1[14]);
        x2 = ViewGetx(mBullet2[14]);
        y2 = ViewGety(mBullet2[14]);
        x3 = ViewGetx(mBullet3[14]);
        y3 = ViewGety(mBullet3[14]);
        if (y > -20 || y2 > -20 || y3 > -20) {
            ViewSetxy(mBullet1[14], x, y - speed);
            ViewSetxy(mBullet2[14], x2, y2 - speed);
            ViewSetxy(mBullet3[14], x3, y3 - speed);
        }
        counter10 = 14;
        for (counter8 = 0; counter8 < 10; counter8++) {
            //ship 1
            if (y > eShipY1[counter8] && y < eShipY1[counter8] + 94 && x > eShipX1[counter8] + 9 && x < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            if (y2 > eShipY1[counter8] && y2 < eShipY1[counter8] + 94 && x2 > eShipX1[counter8] + 9 && x2 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip1Health[counter8] -= 3;
            }
            if (y3 > eShipY1[counter8] && y3 < eShipY1[counter8] + 94 && x3 > eShipX1[counter8] + 9 && x3 < eShipX1[counter8] + 76) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip1Health[counter8] -= 1;
            }
            //ship 2
            if (y > eShipY2[counter8] && y < eShipY2[counter8] + 94 && x > eShipX2[counter8] + 15 && x < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 15 && x2 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY2[counter8] && y3 < eShipY2[counter8] + 94 && x3 > eShipX2[counter8] + 15 && x3 < eShipX2[counter8] + 69) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip2Health[counter8] -= 1;
            }
            //ship 3
            if (y > eShipY3[counter8] && y < eShipY3[counter8] + 94 && x > eShipX3[counter8] + 18 && x < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            if (y2 > eShipY3[counter8] && y2 < eShipY3[counter8] + 94 && x2 > eShipX3[counter8] + 18 && x2 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip3Health[counter8] -= 3;
            }
            if (y3 > eShipY3[counter8] && y3 < eShipY3[counter8] + 94 && x3 > eShipX3[counter8] + 18 && x3 < eShipX3[counter8] + 66) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip3Health[counter8] -= 1;
            }
            //ship 4
            if (y > eShipY4[counter8] && y < eShipY4[counter8] + 94 && x > eShipX4[counter8] - 3 && x < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
            if (y2 > eShipY4[counter8] && y2 < eShipY4[counter8] + 94 && x2 > eShipX4[counter8] - 3 && x2 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip4Health[counter8] -= 3;
            }
            if (y3 > eShipY4[counter8] && y3 < eShipY4[counter8] + 94 && x3 > eShipX4[counter8] - 3 && x3 < eShipX4[counter8] + 87) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip4Health[counter8] -= 1;
            }
        }
        for (counter8 = 0; counter8 < 5; counter8++) {
            //ship 5
            if (y > eShipY5[counter8] && y < eShipY5[counter8] + 94 && x > eShipX5[counter8] + 13 && x < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            if (y2 > eShipY5[counter8] && y2 < eShipY5[counter8] + 94 && x2 > eShipX5[counter8] + 13 && x2 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip5Health[counter8] -= 3;
            }
            if (y3 > eShipY5[counter8] && y3 < eShipY5[counter8] + 94 && x3 > eShipX5[counter8] + 13 && x3 < eShipX5[counter8] + 71) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip5Health[counter8] -= 1;
            }
            //ship 6
            if (y > eShipY6[counter8] && y < eShipY6[counter8] + 94 && x > eShipX6[counter8] + 3 && x < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            if (y2 > eShipY2[counter8] && y2 < eShipY2[counter8] + 94 && x2 > eShipX2[counter8] + 3 && x2 < eShipX2[counter8] + 81) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip2Health[counter8] -= 3;
            }
            if (y3 > eShipY6[counter8] && y3 < eShipY6[counter8] + 94 && x3 > eShipX6[counter8] + 3 && x3 < eShipX6[counter8] + 81) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip6Health[counter8] -= 1;
            }
            //ship 7
            if (y > eShipY7[counter8] && y < eShipY7[counter8] + 94 && x > eShipX7[counter8] - 2 && x < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            if (y2 > eShipY7[counter8] && y2 < eShipY7[counter8] + 94 && x2 > eShipX7[counter8] - 2 && x2 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip7Health[counter8] -= 3;
            }
            if (y3 > eShipY7[counter8] && y3 < eShipY7[counter8] + 94 && x3 > eShipX7[counter8] - 2 && x3 < eShipX7[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip7Health[counter8] -= 1;
            }
            //ship 8
            if (y > eShipY8[counter8] && y < eShipY8[counter8] + 94 && x > eShipX8[counter8] - 3 && x < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet1[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
            if (y2 > eShipY8[counter8] && y2 < eShipY8[counter8] + 94 && x2 > eShipX8[counter8] - 3 && x2 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet2[counter10], -20, -20);
                eShip8Health[counter8] -= 3;
            }
            if (y3 > eShipY8[counter8] && y3 < eShipY8[counter8] + 94 && x3 > eShipX8[counter8] - 3 && x3 < eShipX8[counter8] + 86) {
                ViewSetxy(mBullet3[counter10], -10, -10);
                eShip8Health[counter8] -= 1;
            }
        }
        //ship 9
        if (y > eShipY9 && y < eShipY9 + 240 && x > eShipX9 && x < eShipX9 + 142) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip9Health -= 1;
        }
        if (y2 > eShipY9 && y2 < eShipY9 + 240 && x2 > eShipX9 && x2 < eShipX9 + 142) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip9Health -= 3;
        }
        if (y3 > eShipY9 && y3 < eShipY9 + 240 && x3 > eShipX9 && x3 < eShipX9 + 142) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip9Health -= 1;
        }
        //ship 10
        if (y > eShipY10 && y < eShipY10 + 240 && x > eShipX10 && x < eShipX10 + 150) {
            ViewSetxy(mBullet1[counter10], -10, -10);
            eShip10Health -= 1;
        }
        if (y2 > eShipY10 && y2 < eShipY10 + 240 && x2 > eShipX10 && x2 < eShipX10 + 150) {
            ViewSetxy(mBullet2[counter10], -20, -20);
            eShip10Health -= 3;
        }
        if (y3 > eShipY10 && y3 < eShipY10 + 240 && x3 > eShipX10 && x3 < eShipX10 + 150) {
            ViewSetxy(mBullet3[counter10], -10, -10);
            eShip10Health -= 1;
        }
    }
}
void DoHighscore() {
    switch (highscore) {
        case 0:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 0");
            break;
        case 1:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 1");
            break;
        case 2:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 2");
            break;
        case 3:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 3");
            break;
        case 4:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 4");
            break;
        case 5:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 5");
            break;
        case 6:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 6");
            break;
        case 7:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 7");
            break;
        case 8:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 8");
            break;
        case 9:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 9");
            break;
        case 10:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 10");
            break;
        case 11:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 11");
            break;
        case 12:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 12");
            break;
        case 13:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 13");
            break;
        case 14:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 14");
            break;
        case 15:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 15");
            break;
        case 16:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 16");
            break;
        case 17:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 17");
            break;
        case 18:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 18");
            break;
        case 19:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 19");
            break;
        case 20:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 20");
            break;
        case 21:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 21");
            break;
        case 22:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 22");
            break;
        case 23:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 23");
            break;
        case 24:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 24");
            break;
        case 25:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 25");
            break;
        case 26:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 26");
            break;
        case 27:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 27");
            break;
        case 28:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 28");
            break;
        case 29:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 29");
            break;
        case 30:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 30");
            break;
        case 31:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 31");
            break;
        case 32:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 32");
            break;
        case 33:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 33");
            break;
        case 34:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 34");
            break;
        case 35:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 35");
            break;
        case 36:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 36");
            break;
        case 37:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 37");
            break;
        case 38:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 38");
            break;
        case 39:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 39");
            break;
        case 40:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 40");
            break;
        case 41:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 41");
            break;
        case 42:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 42");
            break;
        case 43:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 43");
            break;
        case 44:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 44");
            break;
        case 45:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 45");
            break;
        case 46:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 46");
            break;
        case 47:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 47");
            break;
        case 48:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 48");
            break;
        case 49:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 49");
            break;
        case 50:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 50");
            break;
        case 51:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 51");
            break;
        case 52:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 52");
            break;
        case 53:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 53");
            break;
        case 54:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 54");
            break;
        case 55:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 55");
            break;
        case 56:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 56");
            break;
        case 57:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 57");
            break;
        case 58:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 58");
            break;
        case 59:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 59");
            break;
        case 60:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 60");
            break;
        case 61:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 61");
            break;
        case 62:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 62");
            break;
        case 63:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 63");
            break;
        case 64:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 64");
            break;
        case 65:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 65");
            break;
        case 66:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 66");
            break;
        case 67:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 67");
            break;
        case 68:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 68");
            break;
        case 69:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 69");
            break;
        case 70:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 70");
            break;
        case 71:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 71");
            break;
        case 72:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 72");
            break;
        case 73:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 73");
            break;
        case 74:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 74");
            break;
        case 75:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 75");
            break;
        case 76:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 76");
            break;
        case 77:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 77");
            break;
        case 78:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 78");
            break;
        case 79:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 79");
            break;
        case 80:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 80");
            break;
        case 81:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 81");
            break;
        case 82:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 82");
            break;
        case 83:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 83");
            break;
        case 84:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 84");
            break;
        case 85:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 85");
            break;
        case 86:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 86");
            break;
        case 87:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 87");
            break;
        case 88:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 88");
            break;
        case 89:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 89");
            break;
        case 90:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 90");
            break;
        case 91:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 91");
            break;
        case 92:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 92");
            break;
        case 93:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 93");
            break;
        case 94:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 94");
            break;
        case 95:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 95");
            break;
        case 96:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 96");
            break;
        case 97:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 97");
            break;
        case 98:
            TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 98");
            break;
    }
    if (highscore >= 99) {
        TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nHighest Level: 99+");
    }
}
void DoUpdateHighscore() {
    if (UpdateHighscore == true) {
        //populate ContainerHighscore to score
        switch (level) {
            case 0:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 0");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 0");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 0");
                } else {
                    DoHighscore();
                }
                break;
            case 1:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 1");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 1");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 1");
                } else {
                    DoHighscore();
                }
                break;
            case 2:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 2");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 2");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 2");
                } else {
                    DoHighscore();
                }
                break;
            case 3:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 3");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 3");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 3");
                } else {
                    DoHighscore();
                }
                break;
            case 4:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 4");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 4");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 4");
                } else {
                    DoHighscore();
                }
                break;
            case 5:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 5");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 5");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 5");
                } else {
                    DoHighscore();
                }
                break;
            case 6:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 6");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 6");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 6");
                } else {
                    DoHighscore();
                }
                break;
            case 7:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 7");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 7");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 7");
                } else {
                    DoHighscore();
                }
                break;
            case 8:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 8");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 8");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 8");
                } else {
                    DoHighscore();
                }
                break;
            case 9:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 9");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 9");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 9");
                } else {
                    DoHighscore();
                }
                break;
            case 10:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 10");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 10");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 10");
                } else {
                    DoHighscore();
                }
                break;
            case 11:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 11");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 11");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 11");
                } else {
                    DoHighscore();
                }
                break;
            case 12:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 12");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 12");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 12");
                } else {
                    DoHighscore();
                }
                break;
            case 13:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 13");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 13");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 13");
                } else {
                    DoHighscore();
                }
                break;
            case 14:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 14");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 14");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 14");
                } else {
                    DoHighscore();
                }
                break;
            case 15:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 15");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 15");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 15");
                } else {
                    DoHighscore();
                }
                break;
            case 16:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 16");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 16");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 16");
                } else {
                    DoHighscore();
                }
                break;
            case 17:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 17");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 17");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 17");
                } else {
                    DoHighscore();
                }
                break;
            case 18:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 18");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 18");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 18");
                } else {
                    DoHighscore();
                }
                break;
            case 19:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 19");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 19");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 19");
                } else {
                    DoHighscore();
                }
                break;
            case 20:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 20");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 20");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 20");
                } else {
                    DoHighscore();
                }
                break;
            case 21:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 21");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 21");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 21");
                } else {
                    DoHighscore();
                }
                break;
            case 22:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 22");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 22");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 22");
                } else {
                    DoHighscore();
                }
                break;
            case 23:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 23");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 23");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 23");
                } else {
                    DoHighscore();
                }
                break;
            case 24:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 24");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 24");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 24");
                } else {
                    DoHighscore();
                }
                break;
            case 25:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 25");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 25");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 25");
                } else {
                    DoHighscore();
                }
                break;
            case 26:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 26");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 26");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 26");
                } else {
                    DoHighscore();
                }
                break;
            case 27:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 27");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 27");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 27");
                } else {
                    DoHighscore();
                }
                break;
            case 28:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 28");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 28");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 28");
                } else {
                    DoHighscore();
                }
                break;
            case 29:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 29");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 29");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 29");
                } else {
                    DoHighscore();
                }
                break;
            case 30:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 30");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 30");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 30");
                } else {
                    DoHighscore();
                }
                break;
            case 31:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 31");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 31");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 31");
                } else {
                    DoHighscore();
                }
                break;
            case 32:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 32");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 32");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 32");
                } else {
                    DoHighscore();
                }
                break;
            case 33:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 33");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 33");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 33");
                } else {
                    DoHighscore();
                }
                break;
            case 34:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 34");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 34");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 34");
                } else {
                    DoHighscore();
                }
                break;
            case 35:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 35");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 35");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 35");
                } else {
                    DoHighscore();
                }
                break;
            case 36:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 36");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 36");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 36");
                } else {
                    DoHighscore();
                }
                break;
            case 37:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 37");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 37");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 37");
                } else {
                    DoHighscore();
                }
                break;
            case 38:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 38");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 38");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 38");
                } else {
                    DoHighscore();
                }
                break;
            case 39:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 39");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 39");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 39");
                } else {
                    DoHighscore();
                }
                break;
            case 40:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 40");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 40");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 40");
                } else {
                    DoHighscore();
                }
                break;
            case 41:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 41");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 41");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 41");
                } else {
                    DoHighscore();
                }
                break;
            case 42:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 42");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 42");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 42");
                } else {
                    DoHighscore();
                }
                break;
            case 43:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 43");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 43");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 43");
                } else {
                    DoHighscore();
                }
                break;
            case 44:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 44");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 44");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 44");
                } else {
                    DoHighscore();
                }
                break;
            case 45:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 45");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 45");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 45");
                } else {
                    DoHighscore();
                }
                break;
            case 46:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 46");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 46");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 46");
                } else {
                    DoHighscore();
                }
                break;
            case 47:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 47");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 47");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 47");
                } else {
                    DoHighscore();
                }
                break;
            case 48:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 48");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 48");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 48");
                } else {
                    DoHighscore();
                }
                break;
            case 49:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 49");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 49");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 49");
                } else {
                    DoHighscore();
                }
                break;
            case 50:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 50");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 50");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 50");
                } else {
                    DoHighscore();
                }
                break;
            case 51:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 51");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 51");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 51");
                } else {
                    DoHighscore();
                }
                break;
            case 52:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 52");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 52");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 52");
                } else {
                    DoHighscore();
                }
                break;
            case 53:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 53");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 53");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 53");
                } else {
                    DoHighscore();
                }
                break;
            case 54:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 54");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 54");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 54");
                } else {
                    DoHighscore();
                }
                break;
            case 55:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 55");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 55");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 55");
                } else {
                    DoHighscore();
                }
                break;
            case 56:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 56");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 56");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 56");
                } else {
                    DoHighscore();
                }
                break;
            case 57:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 57");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 57");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 57");
                } else {
                    DoHighscore();
                }
                break;
            case 58:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 58");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 58");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 58");
                } else {
                    DoHighscore();
                }
                break;
            case 59:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 59");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 59");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 59");
                } else {
                    DoHighscore();
                }
                break;
            case 60:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 60");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 60");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 60");
                } else {
                    DoHighscore();
                }
                break;
            case 61:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 61");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 61");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 61");
                } else {
                    DoHighscore();
                }
                break;
            case 62:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 62");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 62");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 62");
                } else {
                    DoHighscore();
                }
                break;
            case 63:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 63");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 63");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 63");
                } else {
                    DoHighscore();
                }
                break;
            case 64:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 64");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 64");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 64");
                } else {
                    DoHighscore();
                }
                break;
            case 65:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 65");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 65");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 65");
                } else {
                    DoHighscore();
                }
                break;
            case 66:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 66");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 66");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 66");
                } else {
                    DoHighscore();
                }
                break;
            case 67:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 67");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 67");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 67");
                } else {
                    DoHighscore();
                }
                break;
            case 68:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 68");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 68");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 68");
                } else {
                    DoHighscore();
                }
                break;
            case 69:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 69");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 69");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 69");
                } else {
                    DoHighscore();
                }
                break;
            case 70:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 70");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 70");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 70");
                } else {
                    DoHighscore();
                }
                break;
            case 71:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 71");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 71");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 71");
                } else {
                    DoHighscore();
                }
                break;
            case 72:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 72");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 72");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 72");
                } else {
                    DoHighscore();
                }
                break;
            case 73:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 73");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 73");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 73");
                } else {
                    DoHighscore();
                }
                break;
            case 74:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 74");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 74");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 74");
                } else {
                    DoHighscore();
                }
                break;
            case 75:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 75");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 75");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 75");
                } else {
                    DoHighscore();
                }
                break;
            case 76:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 76");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 76");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 76");
                } else {
                    DoHighscore();
                }
                break;
            case 77:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 77");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 77");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 77");
                } else {
                    DoHighscore();
                }
                break;
            case 78:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 78");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 78");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 78");
                } else {
                    DoHighscore();
                }
                break;
            case 79:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 79");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 79");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 79");
                } else {
                    DoHighscore();
                }
                break;
            case 80:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 80");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 80");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 80");
                } else {
                    DoHighscore();
                }
                break;
            case 81:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 81");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 81");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 81");
                } else {
                    DoHighscore();
                }
                break;
            case 82:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 82");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 82");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 82");
                } else {
                    DoHighscore();
                }
                break;
            case 83:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 83");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 83");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 83");
                } else {
                    DoHighscore();
                }
                break;
            case 84:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 84");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 84");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 84");
                } else {
                    DoHighscore();
                }
                break;
            case 85:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 85");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 85");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 85");
                } else {
                    DoHighscore();
                }
                break;
            case 86:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 86");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 86");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 86");
                } else {
                    DoHighscore();
                }
                break;
            case 87:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 87");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 87");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 87");
                } else {
                    DoHighscore();
                }
                break;
            case 88:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 88");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 88");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 88");
                } else {
                    DoHighscore();
                }
                break;
            case 89:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 89");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 89");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 89");
                } else {
                    DoHighscore();
                }
                break;
            case 90:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 90");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 90");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 90");
                } else {
                    DoHighscore();
                }
                break;
            case 91:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 91");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 91");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 91");
                } else {
                    DoHighscore();
                }
                break;
            case 92:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 92");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 92");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 92");
                } else {
                    DoHighscore();
                }
                break;
            case 93:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 93");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 93");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 93");
                } else {
                    DoHighscore();
                }
                break;
            case 94:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 94");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 94");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 94");
                } else {
                    DoHighscore();
                }
                break;
            case 95:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 95");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 95");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 95");
                } else {
                    DoHighscore();
                }
                break;
            case 96:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 96");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 96");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 96");
                } else {
                    DoHighscore();
                }
                break;
            case 97:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 97");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 97");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 97");
                } else {
                    DoHighscore();
                }
                break;
            case 98:
                if (health <= 0) {
                    TextSetText(text1, "\n\nYou Died.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 98");
                } else {
                    TextSetText(text1, "\n\nYou Left.");
                    TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 98");
                }
                if (highscore < level) {
                    highscore = level;
                    TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 98");
                } else {
                    DoHighscore();
                }
                break;
        }
        if (level >= 99) {
            if (health <= 0) {
                TextSetText(text1, "\n\nYou Died.");
                TextSetText(text2, "\n\n\n\n\n\nYou Survived To Level 99+");
            } else {
                TextSetText(text1, "\n\nYou Left.");
                TextSetText(text2, "\n\n\n\n\n\nYou Left At Level 99+");
            }
            if (highscore < level) {
                highscore = level;
                TextSetText(text3, "\n\n\n\n\n\n\n\n\n\nNew Highest Level: 99+");
            } else {
                DoHighscore();
            }
        }
        Reset();
        UpdateHighscore = false;
    }
}
void TortureHealth() {
    int ImageTorturing, number = 100;
    if (HpCounterTorture > number * 20 && torture == true) {
        HpCounterTorture = number * 20;
    } else if (HpCounterTorture > number * 40 && torture == false) {
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
    if (HealthUpdate == true) {
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
                case 6:
                    Image = ImageAdd("Images/6HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 5:
                    Image = ImageAdd("Images/5HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 4:
                    Image = ImageAdd("Images/4HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 3:
                    Image = ImageAdd("Images/3HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 2:
                    Image = ImageAdd("Images/2HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 1:
                    Image = ImageAdd("Images/1HP.png");
                    ViewSetImage(HP, Image);
                    break;
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
                case 8:
                    Image = ImageAdd("Images/8HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 7:
                    Image = ImageAdd("Images/7HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 6:
                    Image = ImageAdd("Images/6HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 5:
                    Image = ImageAdd("Images/5HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 4:
                    Image = ImageAdd("Images/4HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 3:
                    Image = ImageAdd("Images/3HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 2:
                    Image = ImageAdd("Images/2HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 1:
                    Image = ImageAdd("Images/1HP.png");
                    ViewSetImage(HP, Image);
                    break;
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
                case 10:
                    Image = ImageAdd("Images/10HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 9:
                    Image = ImageAdd("Images/9HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 8:
                    Image = ImageAdd("Images/8HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 7:
                    Image = ImageAdd("Images/7HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 6:
                    Image = ImageAdd("Images/6HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 5:
                    Image = ImageAdd("Images/5HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 4:
                    Image = ImageAdd("Images/4HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 3:
                    Image = ImageAdd("Images/3HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 2:
                    Image = ImageAdd("Images/2HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 1:
                    Image = ImageAdd("Images/1HP.png");
                    ViewSetImage(HP, Image);
                    break;
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
                case 12:
                    Image = ImageAdd("Images/12HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 11:
                    Image = ImageAdd("Images/11HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 10:
                    Image = ImageAdd("Images/10HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 9:
                    Image = ImageAdd("Images/9HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 8:
                    Image = ImageAdd("Images/8HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 7:
                    Image = ImageAdd("Images/7HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 6:
                    Image = ImageAdd("Images/6HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 5:
                    Image = ImageAdd("Images/5HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 4:
                    Image = ImageAdd("Images/4HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 3:
                    Image = ImageAdd("Images/3HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 2:
                    Image = ImageAdd("Images/2HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 1:
                    Image = ImageAdd("Images/1HP.png");
                    ViewSetImage(HP, Image);
                    break;
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
                case 14:
                    Image = ImageAdd("Images/14HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 13:
                    Image = ImageAdd("Images/13HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 12:
                    Image = ImageAdd("Images/12HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 11:
                    Image = ImageAdd("Images/11HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 10:
                    Image = ImageAdd("Images/10HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 9:
                    Image = ImageAdd("Images/9HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 8:
                    Image = ImageAdd("Images/8HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 7:
                    Image = ImageAdd("Images/7HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 6:
                    Image = ImageAdd("Images/6HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 5:
                    Image = ImageAdd("Images/5HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 4:
                    Image = ImageAdd("Images/4HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 3:
                    Image = ImageAdd("Images/3HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 2:
                    Image = ImageAdd("Images/2HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 1:
                    Image = ImageAdd("Images/1HP.png");
                    ViewSetImage(HP, Image);
                    break;
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
                case 16:
                    Image = ImageAdd("Images/16HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 15:
                    Image = ImageAdd("Images/15HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 14:
                    Image = ImageAdd("Images/14HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 13:
                    Image = ImageAdd("Images/13HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 12:
                    Image = ImageAdd("Images/12HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 11:
                    Image = ImageAdd("Images/11HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 10:
                    Image = ImageAdd("Images/10HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 9:
                    Image = ImageAdd("Images/9HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 8:
                    Image = ImageAdd("Images/8HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 7:
                    Image = ImageAdd("Images/7HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 6:
                    Image = ImageAdd("Images/6HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 5:
                    Image = ImageAdd("Images/5HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 4:
                    Image = ImageAdd("Images/4HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 3:
                    Image = ImageAdd("Images/3HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 2:
                    Image = ImageAdd("Images/2HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 1:
                    Image = ImageAdd("Images/1HP.png");
                    ViewSetImage(HP, Image);
                    break;
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
                case 18:
                    Image = ImageAdd("Images/18HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 17:
                    Image = ImageAdd("Images/17HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 16:
                    Image = ImageAdd("Images/16HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 15:
                    Image = ImageAdd("Images/15HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 14:
                    Image = ImageAdd("Images/14HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 13:
                    Image = ImageAdd("Images/13HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 12:
                    Image = ImageAdd("Images/12HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 11:
                    Image = ImageAdd("Images/11HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 10:
                    Image = ImageAdd("Images/10HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 9:
                    Image = ImageAdd("Images/9HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 8:
                    Image = ImageAdd("Images/8HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 7:
                    Image = ImageAdd("Images/7HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 6:
                    Image = ImageAdd("Images/6HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 5:
                    Image = ImageAdd("Images/5HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 4:
                    Image = ImageAdd("Images/4HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 3:
                    Image = ImageAdd("Images/3HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 2:
                    Image = ImageAdd("Images/2HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 1:
                    Image = ImageAdd("Images/1HP.png");
                    ViewSetImage(HP, Image);
                    break;
            }
        } else if (ship == 1) {
            switch (health) {
                case 20:
                    Image = ImageAdd("Images/20HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 19:
                    Image = ImageAdd("Images/19HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 18:
                    Image = ImageAdd("Images/18HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 17:
                    Image = ImageAdd("Images/17HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 16:
                    Image = ImageAdd("Images/16HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 15:
                    Image = ImageAdd("Images/15HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 14:
                    Image = ImageAdd("Images/14HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 13:
                    Image = ImageAdd("Images/13HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 12:
                    Image = ImageAdd("Images/12HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 11:
                    Image = ImageAdd("Images/11HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 10:
                    Image = ImageAdd("Images/10HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 9:
                    Image = ImageAdd("Images/9HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 8:
                    Image = ImageAdd("Images/8HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 7:
                    Image = ImageAdd("Images/7HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 6:
                    Image = ImageAdd("Images/6HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 5:
                    Image = ImageAdd("Images/5HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 4:
                    Image = ImageAdd("Images/4HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 3:
                    Image = ImageAdd("Images/3HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 2:
                    Image = ImageAdd("Images/2HP.png");
                    ViewSetImage(HP, Image);
                    break;
                case 1:
                    Image = ImageAdd("Images/1HP.png");
                    ViewSetImage(HP, Image);
                    break;
            }
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
    for (counter6 = 0; counter6 < 10; counter6++) {
        //x cords
        eShipY1[counter6] = ViewGety(eShip1[counter6]);
        eShipY2[counter6] = ViewGety(eShip2[counter6]);
        eShipY3[counter6] = ViewGety(eShip3[counter6]);
        eShipY4[counter6] = ViewGety(eShip4[counter6]);
        //y cords
        eShipX1[counter6] = ViewGetx(eShip1[counter6]);
        eShipX2[counter6] = ViewGetx(eShip2[counter6]);
        eShipX3[counter6] = ViewGetx(eShip3[counter6]);
        eShipX4[counter6] = ViewGetx(eShip4[counter6]);
    }
    for (counter6 = 0; counter6 < 5; counter6++) {
        //x cords
        eShipY5[counter6] = ViewGety(eShip5[counter6]);
        eShipY6[counter6] = ViewGety(eShip6[counter6]);
        eShipY7[counter6] = ViewGety(eShip7[counter6]);
        eShipY8[counter6] = ViewGety(eShip8[counter6]);
        //y cords
        eShipX5[counter6] = ViewGetx(eShip5[counter6]);
        eShipX6[counter6] = ViewGetx(eShip6[counter6]);
        eShipX7[counter6] = ViewGetx(eShip7[counter6]);
        eShipX8[counter6] = ViewGetx(eShip8[counter6]);
    }
    //x cords
    eShipX9 = ViewGetx(eShip9);
    //y cords
    eShipY9 = ViewGety(eShip9);
    //x cords
    eShipX10 = ViewGetx(eShip10);
    //y cords
    eShipY10 = ViewGety(eShip10);
    for (counter6 = 0; counter6 < 10; counter6++) {
        if (eShipY1[counter6] < 600) {
            ViewSetxy(eShip1[counter6], eShipX1[counter6], eShipY1[counter6] + EnemyFlySpeed);
        }
        if (eShipY2[counter6] < 600) {
            ViewSetxy(eShip2[counter6], eShipX2[counter6], eShipY2[counter6] + EnemyFlySpeed);
        }
        if (eShipY3[counter6] < 600) {
            ViewSetxy(eShip3[counter6], eShipX3[counter6], eShipY3[counter6] + EnemyFlySpeed);
        }
        if (eShipY4[counter6] < 600) {
            ViewSetxy(eShip4[counter6], eShipX4[counter6], eShipY4[counter6] + EnemyFlySpeed);
        }
    }
    for (counter6 = 0; counter6 < 5; counter6++) {
        if (eShipY5[counter6] < 600) {
            ViewSetxy(eShip5[counter6], eShipX5[counter6], eShipY5[counter6] + EnemyFlySpeed);
        }
        if (eShipY6[counter6] < 600) {
            ViewSetxy(eShip6[counter6], eShipX6[counter6], eShipY6[counter6] + EnemyFlySpeed);
        }
        if (eShipY7[counter6] < 600) {
            ViewSetxy(eShip7[counter6], eShipX7[counter6], eShipY7[counter6] + EnemyFlySpeed);
        }
        if (eShipY8[counter6] < 600) {
            ViewSetxy(eShip8[counter6], eShipX8[counter6], eShipY8[counter6] + EnemyFlySpeed);
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
    if (set == 1) {
        SetOne();
    } else if (set == 2) {
        SetTwo();
    } else if (set == 3) {
        SetThree();
    } else if (set == 4) {
        SetFour();
    } else if (set == 5) {
        SetFive();
    } else if (set == 6) {
        counter3 = 0;
        level += 1;
        set = 1;
    }
}
void DoEnemyShipShoot() {
    int ex, ey, ex2, ey2, ex3, ey3;
    if (counter4 == 1 * EnemyShootCooldownSpeed) {
        //ship 1
        ViewSetxy(e1Bullet1[0], eShipX1[0] + e1BulletXOffset, eShipY1[0] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[1], eShipX1[1] + e1BulletXOffset, eShipY1[1] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[2], eShipX1[2] + e1BulletXOffset, eShipY1[2] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[3], eShipX1[3] + e1BulletXOffset, eShipY1[3] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[4], eShipX1[4] + e1BulletXOffset, eShipY1[4] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[5], eShipX1[5] + e1BulletXOffset, eShipY1[5] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[6], eShipX1[6] + e1BulletXOffset, eShipY1[6] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[7], eShipX1[7] + e1BulletXOffset, eShipY1[7] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[8], eShipX1[8] + e1BulletXOffset, eShipY1[8] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[9], eShipX1[9] + e1BulletXOffset, eShipY1[9] + e1BulletYOffset);
        //ship 2
        ViewSetxy(e2Bullet1[0], eShipX2[0] + e2BulletXOffset, eShipY2[0] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[1], eShipX2[1] + e2BulletXOffset, eShipY2[1] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[2], eShipX2[2] + e2BulletXOffset, eShipY2[2] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[3], eShipX2[3] + e2BulletXOffset, eShipY2[3] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[4], eShipX2[4] + e2BulletXOffset, eShipY2[4] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[5], eShipX2[5] + e2BulletXOffset, eShipY2[5] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[6], eShipX2[6] + e2BulletXOffset, eShipY2[6] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[7], eShipX2[7] + e2BulletXOffset, eShipY2[7] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[8], eShipX2[8] + e2BulletXOffset, eShipY2[8] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[9], eShipX2[9] + e2BulletXOffset, eShipY2[9] + e2BulletYOffset);
        //ship 3
        ViewSetxy(e3Bullet1[0], eShipX3[0] + e3BulletXOffset, eShipY3[0] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[1], eShipX3[1] + e3BulletXOffset, eShipY3[1] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[2], eShipX3[2] + e3BulletXOffset, eShipY3[2] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[3], eShipX3[3] + e3BulletXOffset, eShipY3[3] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[4], eShipX3[4] + e3BulletXOffset, eShipY3[4] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[5], eShipX3[5] + e3BulletXOffset, eShipY3[5] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[6], eShipX3[6] + e3BulletXOffset, eShipY3[6] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[7], eShipX3[7] + e3BulletXOffset, eShipY3[7] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[8], eShipX3[8] + e3BulletXOffset, eShipY3[8] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[9], eShipX3[9] + e3BulletXOffset, eShipY3[9] + e3BulletYOffset);
        //ship 4
        ViewSetxy(e4Bullet1[0], eShipX4[0] + e4BulletXOffset, eShipY4[0] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[1], eShipX4[1] + e4BulletXOffset, eShipY4[1] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[2], eShipX4[2] + e4BulletXOffset, eShipY4[2] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[3], eShipX4[3] + e4BulletXOffset, eShipY4[3] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[4], eShipX4[4] + e4BulletXOffset, eShipY4[4] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[5], eShipX4[5] + e4BulletXOffset, eShipY4[5] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[6], eShipX4[6] + e4BulletXOffset, eShipY4[6] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[7], eShipX4[7] + e4BulletXOffset, eShipY4[7] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[8], eShipX4[8] + e4BulletXOffset, eShipY4[8] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[9], eShipX4[9] + e4BulletXOffset, eShipY4[9] + e4BulletYOffset);
        //ship 5
        ViewSetxy(e5Bullet1[0], eShipX5[0] + e5BulletXOffset, eShipY5[0] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[0], eShipX5[0] + e5BulletXOffset3, eShipY5[0] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[1], eShipX5[1] + e5BulletXOffset, eShipY5[1] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[1], eShipX5[1] + e5BulletXOffset3, eShipY5[1] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[2], eShipX5[2] + e5BulletXOffset, eShipY5[2] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[2], eShipX5[2] + e5BulletXOffset3, eShipY5[2] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[3], eShipX5[3] + e5BulletXOffset, eShipY5[3] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[3], eShipX5[3] + e5BulletXOffset3, eShipY5[3] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[4], eShipX5[4] + e5BulletXOffset, eShipY5[4] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[4], eShipX5[4] + e5BulletXOffset3, eShipY5[4] + e5BulletYOffset3);
        //ship 6
        ViewSetxy(e6Bullet1[0], eShipX6[0] + e6BulletXOffset, eShipY6[0] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[0], eShipX6[0] + e6BulletXOffset3, eShipY6[0] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[1], eShipX6[1] + e6BulletXOffset, eShipY6[1] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[1], eShipX6[1] + e6BulletXOffset3, eShipY6[1] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[2], eShipX6[2] + e6BulletXOffset, eShipY6[2] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[2], eShipX6[2] + e6BulletXOffset3, eShipY6[2] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[3], eShipX6[3] + e6BulletXOffset, eShipY6[3] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[3], eShipX6[3] + e6BulletXOffset3, eShipY6[3] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[4], eShipX6[4] + e6BulletXOffset, eShipY6[4] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[4], eShipX6[4] + e6BulletXOffset3, eShipY6[4] + e6BulletYOffset3);
        //ship 7
        ViewSetxy(e7Bullet2[0], eShipX7[0] + e7BulletXOffset2, eShipY7[0] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[1], eShipX7[1] + e7BulletXOffset2, eShipY7[1] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[2], eShipX7[2] + e7BulletXOffset2, eShipY7[2] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[3], eShipX7[3] + e7BulletXOffset2, eShipY7[3] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[4], eShipX7[4] + e7BulletXOffset2, eShipY7[4] + e7BulletYOffset2);
        //ship 8
        ViewSetxy(e8Bullet1[0], eShipX8[0] + e8BulletXOffset, eShipY8[0] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[0], eShipX8[0] + e8BulletXOffset2, eShipY8[0] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[0], eShipX8[0] + e8BulletXOffset3, eShipY8[0] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[1], eShipX8[1] + e8BulletXOffset, eShipY8[1] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[1], eShipX8[1] + e8BulletXOffset2, eShipY8[1] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[1], eShipX8[1] + e8BulletXOffset3, eShipY8[1] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[2], eShipX8[2] + e8BulletXOffset, eShipY8[2] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[2], eShipX8[2] + e8BulletXOffset2, eShipY8[2] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[2], eShipX8[2] + e8BulletXOffset3, eShipY8[2] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[3], eShipX8[3] + e8BulletXOffset, eShipY8[3] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[3], eShipX8[3] + e8BulletXOffset2, eShipY8[3] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[3], eShipX8[3] + e8BulletXOffset3, eShipY8[3] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[4], eShipX8[4] + e8BulletXOffset, eShipY8[4] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[4], eShipX8[4] + e8BulletXOffset2, eShipY8[4] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[4], eShipX8[4] + e8BulletXOffset3, eShipY8[4] + e8BulletYOffset3);
        //ship 9
        ViewSetxy(e9Bullet1[0], eShipX9 + e9BulletXOffset, eShipY9 + e9BulletYOffset);
        ViewSetxy(e9Bullet2[0], eShipX9 + e9BulletXOffset2, eShipY9 + e9BulletYOffset2);
        ViewSetxy(e9Bullet3[0], eShipX9 + e9BulletXOffset3, eShipY9 + e9BulletYOffset3);
        //ship 10
        ViewSetxy(e10Bullet1[0], eShipX10 + e10BulletXOffset, eShipY10 + e10BulletYOffset);
        ViewSetxy(e10Bullet2[0], eShipX10 + e10BulletXOffset2, eShipY10 + e10BulletYOffset2);
        ViewSetxy(e10Bullet3[0], eShipX10 + e10BulletXOffset3, eShipY10 + e10BulletYOffset3);
    } else if (counter4 == 2 * EnemyShootCooldownSpeed) {
        //ship 1
        ViewSetxy(e1Bullet1[10], eShipX1[0] + e1BulletXOffset, eShipY1[0] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[11], eShipX1[1] + e1BulletXOffset, eShipY1[1] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[12], eShipX1[2] + e1BulletXOffset, eShipY1[2] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[13], eShipX1[3] + e1BulletXOffset, eShipY1[3] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[14], eShipX1[4] + e1BulletXOffset, eShipY1[4] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[15], eShipX1[5] + e1BulletXOffset, eShipY1[5] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[16], eShipX1[6] + e1BulletXOffset, eShipY1[6] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[17], eShipX1[7] + e1BulletXOffset, eShipY1[7] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[18], eShipX1[8] + e1BulletXOffset, eShipY1[8] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[19], eShipX1[9] + e1BulletXOffset, eShipY1[9] + e1BulletYOffset);
        //ship 2
        ViewSetxy(e2Bullet1[10], eShipX2[0] + e2BulletXOffset, eShipY2[0] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[11], eShipX2[1] + e2BulletXOffset, eShipY2[1] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[12], eShipX2[2] + e2BulletXOffset, eShipY2[2] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[13], eShipX2[3] + e2BulletXOffset, eShipY2[3] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[14], eShipX2[4] + e2BulletXOffset, eShipY2[4] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[15], eShipX2[5] + e2BulletXOffset, eShipY2[5] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[16], eShipX2[6] + e2BulletXOffset, eShipY2[6] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[17], eShipX2[7] + e2BulletXOffset, eShipY2[7] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[18], eShipX2[8] + e2BulletXOffset, eShipY2[8] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[19], eShipX2[9] + e2BulletXOffset, eShipY2[9] + e2BulletYOffset);
        //ship 3
        ViewSetxy(e3Bullet1[10], eShipX3[0] + e3BulletXOffset, eShipY3[0] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[11], eShipX3[1] + e3BulletXOffset, eShipY3[1] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[12], eShipX3[2] + e3BulletXOffset, eShipY3[2] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[13], eShipX3[3] + e3BulletXOffset, eShipY3[3] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[14], eShipX3[4] + e3BulletXOffset, eShipY3[4] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[15], eShipX3[5] + e3BulletXOffset, eShipY3[5] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[16], eShipX3[6] + e3BulletXOffset, eShipY3[6] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[17], eShipX3[7] + e3BulletXOffset, eShipY3[7] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[18], eShipX3[8] + e3BulletXOffset, eShipY3[8] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[19], eShipX3[9] + e3BulletXOffset, eShipY3[9] + e3BulletYOffset);
        //ship 4
        ViewSetxy(e4Bullet1[10], eShipX4[0] + e4BulletXOffset, eShipY4[0] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[11], eShipX4[1] + e4BulletXOffset, eShipY4[1] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[12], eShipX4[2] + e4BulletXOffset, eShipY4[2] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[13], eShipX4[3] + e4BulletXOffset, eShipY4[3] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[14], eShipX4[4] + e4BulletXOffset, eShipY4[4] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[15], eShipX4[5] + e4BulletXOffset, eShipY4[5] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[16], eShipX4[6] + e4BulletXOffset, eShipY4[6] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[17], eShipX4[7] + e4BulletXOffset, eShipY4[7] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[18], eShipX4[8] + e4BulletXOffset, eShipY4[8] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[19], eShipX4[9] + e4BulletXOffset, eShipY4[9] + e4BulletYOffset);
        //ship 5
        ViewSetxy(e5Bullet1[5], eShipX5[0] + e5BulletXOffset, eShipY5[0] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[5], eShipX5[0] + e5BulletXOffset3, eShipY5[0] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[6], eShipX5[1] + e5BulletXOffset, eShipY5[1] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[6], eShipX5[1] + e5BulletXOffset3, eShipY5[1] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[7], eShipX5[2] + e5BulletXOffset, eShipY5[2] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[7], eShipX5[2] + e5BulletXOffset3, eShipY5[2] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[8], eShipX5[3] + e5BulletXOffset, eShipY5[3] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[8], eShipX5[3] + e5BulletXOffset3, eShipY5[3] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[9], eShipX5[4] + e5BulletXOffset, eShipY5[4] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[9], eShipX5[4] + e5BulletXOffset3, eShipY5[4] + e5BulletYOffset3);
        //ship 6
        ViewSetxy(e6Bullet1[5], eShipX6[0] + e6BulletXOffset, eShipY6[0] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[5], eShipX6[0] + e6BulletXOffset3, eShipY6[0] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[6], eShipX6[1] + e6BulletXOffset, eShipY6[1] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[6], eShipX6[1] + e6BulletXOffset3, eShipY6[1] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[7], eShipX6[2] + e6BulletXOffset, eShipY6[2] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[7], eShipX6[2] + e6BulletXOffset3, eShipY6[2] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[8], eShipX6[3] + e6BulletXOffset, eShipY6[3] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[8], eShipX6[3] + e6BulletXOffset3, eShipY6[3] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[9], eShipX6[4] + e6BulletXOffset, eShipY6[4] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[9], eShipX6[4] + e6BulletXOffset3, eShipY6[4] + e6BulletYOffset3);
        //ship 7
        ViewSetxy(e7Bullet2[5], eShipX7[0] + e7BulletXOffset2, eShipY7[0] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[6], eShipX7[1] + e7BulletXOffset2, eShipY7[1] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[7], eShipX7[2] + e7BulletXOffset2, eShipY7[2] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[8], eShipX7[3] + e7BulletXOffset2, eShipY7[3] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[9], eShipX7[4] + e7BulletXOffset2, eShipY7[4] + e7BulletYOffset2);
        //ship 8
        ViewSetxy(e8Bullet1[5], eShipX8[0] + e8BulletXOffset, eShipY8[0] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[5], eShipX8[0] + e8BulletXOffset2, eShipY8[0] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[5], eShipX8[0] + e8BulletXOffset3, eShipY8[0] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[6], eShipX8[1] + e8BulletXOffset, eShipY8[1] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[6], eShipX8[1] + e8BulletXOffset2, eShipY8[1] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[6], eShipX8[1] + e8BulletXOffset3, eShipY8[1] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[7], eShipX8[2] + e8BulletXOffset, eShipY8[2] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[7], eShipX8[2] + e8BulletXOffset2, eShipY8[2] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[7], eShipX8[2] + e8BulletXOffset3, eShipY8[2] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[8], eShipX8[3] + e8BulletXOffset, eShipY8[3] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[8], eShipX8[3] + e8BulletXOffset2, eShipY8[3] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[8], eShipX8[3] + e8BulletXOffset3, eShipY8[3] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[9], eShipX8[4] + e8BulletXOffset, eShipY8[4] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[9], eShipX8[4] + e8BulletXOffset2, eShipY8[4] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[9], eShipX8[4] + e8BulletXOffset3, eShipY8[4] + e8BulletYOffset3);
        //ship 9
        ViewSetxy(e9Bullet1[1], eShipX9 + e9BulletXOffset, eShipY9 + e9BulletYOffset);
        ViewSetxy(e9Bullet2[1], eShipX9 + e9BulletXOffset2, eShipY9 + e9BulletYOffset2);
        ViewSetxy(e9Bullet3[1], eShipX9 + e9BulletXOffset3, eShipY9 + e9BulletYOffset3);
        //ship 10
        ViewSetxy(e10Bullet1[1], eShipX10 + e10BulletXOffset, eShipY10 + e10BulletYOffset);
        ViewSetxy(e10Bullet2[1], eShipX10 + e10BulletXOffset2, eShipY10 + e10BulletYOffset2);
        ViewSetxy(e10Bullet3[1], eShipX10 + e10BulletXOffset3, eShipY10 + e10BulletYOffset3);
    } else if (counter4 == 3 * EnemyShootCooldownSpeed) {
        //ship 1
        ViewSetxy(e1Bullet1[20], eShipX1[0] + e1BulletXOffset, eShipY1[0] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[21], eShipX1[1] + e1BulletXOffset, eShipY1[1] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[22], eShipX1[2] + e1BulletXOffset, eShipY1[2] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[23], eShipX1[3] + e1BulletXOffset, eShipY1[3] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[24], eShipX1[4] + e1BulletXOffset, eShipY1[4] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[25], eShipX1[5] + e1BulletXOffset, eShipY1[5] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[26], eShipX1[6] + e1BulletXOffset, eShipY1[6] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[27], eShipX1[7] + e1BulletXOffset, eShipY1[7] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[28], eShipX1[8] + e1BulletXOffset, eShipY1[8] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[29], eShipX1[9] + e1BulletXOffset, eShipY1[9] + e1BulletYOffset);
        //ship 2
        ViewSetxy(e2Bullet1[20], eShipX2[0] + e2BulletXOffset, eShipY2[0] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[21], eShipX2[1] + e2BulletXOffset, eShipY2[1] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[22], eShipX2[2] + e2BulletXOffset, eShipY2[2] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[23], eShipX2[3] + e2BulletXOffset, eShipY2[3] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[24], eShipX2[4] + e2BulletXOffset, eShipY2[4] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[25], eShipX2[5] + e2BulletXOffset, eShipY2[5] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[26], eShipX2[6] + e2BulletXOffset, eShipY2[6] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[27], eShipX2[7] + e2BulletXOffset, eShipY2[7] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[28], eShipX2[8] + e2BulletXOffset, eShipY2[8] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[29], eShipX2[9] + e2BulletXOffset, eShipY2[9] + e2BulletYOffset);
        //ship 3
        ViewSetxy(e3Bullet1[20], eShipX3[0] + e3BulletXOffset, eShipY3[0] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[21], eShipX3[1] + e3BulletXOffset, eShipY3[1] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[22], eShipX3[2] + e3BulletXOffset, eShipY3[2] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[23], eShipX3[3] + e3BulletXOffset, eShipY3[3] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[24], eShipX3[4] + e3BulletXOffset, eShipY3[4] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[25], eShipX3[5] + e3BulletXOffset, eShipY3[5] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[26], eShipX3[6] + e3BulletXOffset, eShipY3[6] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[27], eShipX3[7] + e3BulletXOffset, eShipY3[7] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[28], eShipX3[8] + e3BulletXOffset, eShipY3[8] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[29], eShipX3[9] + e3BulletXOffset, eShipY3[9] + e3BulletYOffset);
        //ship 4
        ViewSetxy(e4Bullet1[20], eShipX4[0] + e4BulletXOffset, eShipY4[0] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[21], eShipX4[1] + e4BulletXOffset, eShipY4[1] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[22], eShipX4[2] + e4BulletXOffset, eShipY4[2] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[23], eShipX4[3] + e4BulletXOffset, eShipY4[3] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[24], eShipX4[4] + e4BulletXOffset, eShipY4[4] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[25], eShipX4[5] + e4BulletXOffset, eShipY4[5] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[26], eShipX4[6] + e4BulletXOffset, eShipY4[6] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[27], eShipX4[7] + e4BulletXOffset, eShipY4[7] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[28], eShipX4[8] + e4BulletXOffset, eShipY4[8] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[29], eShipX4[9] + e4BulletXOffset, eShipY4[9] + e4BulletYOffset);
        //ship 5
        ViewSetxy(e5Bullet1[10], eShipX5[0] + e5BulletXOffset, eShipY5[0] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[10], eShipX5[0] + e5BulletXOffset3, eShipY5[0] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[11], eShipX5[1] + e5BulletXOffset, eShipY5[1] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[11], eShipX5[1] + e5BulletXOffset3, eShipY5[1] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[12], eShipX5[2] + e5BulletXOffset, eShipY5[2] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[12], eShipX5[2] + e5BulletXOffset3, eShipY5[2] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[13], eShipX5[3] + e5BulletXOffset, eShipY5[3] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[13], eShipX5[3] + e5BulletXOffset3, eShipY5[3] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[14], eShipX5[4] + e5BulletXOffset, eShipY5[4] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[14], eShipX5[4] + e5BulletXOffset3, eShipY5[4] + e5BulletYOffset3);
        //ship 6
        ViewSetxy(e6Bullet1[10], eShipX6[0] + e6BulletXOffset, eShipY6[0] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[10], eShipX6[0] + e6BulletXOffset3, eShipY6[0] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[11], eShipX6[1] + e6BulletXOffset, eShipY6[1] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[11], eShipX6[1] + e6BulletXOffset3, eShipY6[1] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[12], eShipX6[2] + e6BulletXOffset, eShipY6[2] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[12], eShipX6[2] + e6BulletXOffset3, eShipY6[2] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[13], eShipX6[3] + e6BulletXOffset, eShipY6[3] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[13], eShipX6[3] + e6BulletXOffset3, eShipY6[3] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[14], eShipX6[4] + e6BulletXOffset, eShipY6[4] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[14], eShipX6[4] + e6BulletXOffset3, eShipY6[4] + e6BulletYOffset3);
        //ship 7
        ViewSetxy(e7Bullet2[10], eShipX7[0] + e7BulletXOffset2, eShipY7[0] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[11], eShipX7[1] + e7BulletXOffset2, eShipY7[1] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[12], eShipX7[2] + e7BulletXOffset2, eShipY7[2] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[13], eShipX7[3] + e7BulletXOffset2, eShipY7[3] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[14], eShipX7[4] + e7BulletXOffset2, eShipY7[4] + e7BulletYOffset2);
        //ship 8
        ViewSetxy(e8Bullet1[10], eShipX8[0] + e8BulletXOffset, eShipY8[0] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[10], eShipX8[0] + e8BulletXOffset2, eShipY8[0] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[10], eShipX8[0] + e8BulletXOffset3, eShipY8[0] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[11], eShipX8[1] + e8BulletXOffset, eShipY8[1] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[11], eShipX8[1] + e8BulletXOffset2, eShipY8[1] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[11], eShipX8[1] + e8BulletXOffset3, eShipY8[1] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[12], eShipX8[2] + e8BulletXOffset, eShipY8[2] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[12], eShipX8[2] + e8BulletXOffset2, eShipY8[2] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[12], eShipX8[2] + e8BulletXOffset3, eShipY8[2] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[13], eShipX8[3] + e8BulletXOffset, eShipY8[3] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[13], eShipX8[3] + e8BulletXOffset2, eShipY8[3] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[13], eShipX8[3] + e8BulletXOffset3, eShipY8[3] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[14], eShipX8[4] + e8BulletXOffset, eShipY8[4] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[14], eShipX8[4] + e8BulletXOffset2, eShipY8[4] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[14], eShipX8[4] + e8BulletXOffset3, eShipY8[4] + e8BulletYOffset3);
        //ship 9
        ViewSetxy(e9Bullet1[2], eShipX9 + e9BulletXOffset, eShipY9 + e9BulletYOffset);
        ViewSetxy(e9Bullet2[2], eShipX9 + e9BulletXOffset2, eShipY9 + e9BulletYOffset2);
        ViewSetxy(e9Bullet3[2], eShipX9 + e9BulletXOffset3, eShipY9 + e9BulletYOffset3);
        //ship 10
        ViewSetxy(e10Bullet1[2], eShipX10 + e10BulletXOffset, eShipY10 + e10BulletYOffset);
        ViewSetxy(e10Bullet2[2], eShipX10 + e10BulletXOffset2, eShipY10 + e10BulletYOffset2);
        ViewSetxy(e10Bullet3[2], eShipX10 + e10BulletXOffset3, eShipY10 + e10BulletYOffset3);
    } else if (counter4 == 4 * EnemyShootCooldownSpeed) {
        //ship 1
        ViewSetxy(e1Bullet1[30], eShipX1[0] + e1BulletXOffset, eShipY1[0] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[31], eShipX1[1] + e1BulletXOffset, eShipY1[1] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[32], eShipX1[2] + e1BulletXOffset, eShipY1[2] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[33], eShipX1[3] + e1BulletXOffset, eShipY1[3] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[34], eShipX1[4] + e1BulletXOffset, eShipY1[4] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[35], eShipX1[5] + e1BulletXOffset, eShipY1[5] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[36], eShipX1[6] + e1BulletXOffset, eShipY1[6] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[37], eShipX1[7] + e1BulletXOffset, eShipY1[7] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[38], eShipX1[8] + e1BulletXOffset, eShipY1[8] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[39], eShipX1[9] + e1BulletXOffset, eShipY1[9] + e1BulletYOffset);
        //ship 2
        ViewSetxy(e2Bullet1[30], eShipX2[0] + e2BulletXOffset, eShipY2[0] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[31], eShipX2[1] + e2BulletXOffset, eShipY2[1] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[32], eShipX2[2] + e2BulletXOffset, eShipY2[2] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[33], eShipX2[3] + e2BulletXOffset, eShipY2[3] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[34], eShipX2[4] + e2BulletXOffset, eShipY2[4] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[35], eShipX2[5] + e2BulletXOffset, eShipY2[5] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[36], eShipX2[6] + e2BulletXOffset, eShipY2[6] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[37], eShipX2[7] + e2BulletXOffset, eShipY2[7] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[38], eShipX2[8] + e2BulletXOffset, eShipY2[8] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[39], eShipX2[9] + e2BulletXOffset, eShipY2[9] + e2BulletYOffset);
        //ship 3
        ViewSetxy(e3Bullet1[30], eShipX3[0] + e3BulletXOffset, eShipY3[0] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[31], eShipX3[1] + e3BulletXOffset, eShipY3[1] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[32], eShipX3[2] + e3BulletXOffset, eShipY3[2] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[33], eShipX3[3] + e3BulletXOffset, eShipY3[3] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[34], eShipX3[4] + e3BulletXOffset, eShipY3[4] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[35], eShipX3[5] + e3BulletXOffset, eShipY3[5] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[36], eShipX3[6] + e3BulletXOffset, eShipY3[6] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[37], eShipX3[7] + e3BulletXOffset, eShipY3[7] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[38], eShipX3[8] + e3BulletXOffset, eShipY3[8] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[39], eShipX3[9] + e3BulletXOffset, eShipY3[9] + e3BulletYOffset);
        //ship 4
        ViewSetxy(e4Bullet1[30], eShipX4[0] + e4BulletXOffset, eShipY4[0] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[31], eShipX4[1] + e4BulletXOffset, eShipY4[1] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[32], eShipX4[2] + e4BulletXOffset, eShipY4[2] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[33], eShipX4[3] + e4BulletXOffset, eShipY4[3] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[34], eShipX4[4] + e4BulletXOffset, eShipY4[4] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[35], eShipX4[5] + e4BulletXOffset, eShipY4[5] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[36], eShipX4[6] + e4BulletXOffset, eShipY4[6] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[37], eShipX4[7] + e4BulletXOffset, eShipY4[7] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[38], eShipX4[8] + e4BulletXOffset, eShipY4[8] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[39], eShipX4[9] + e4BulletXOffset, eShipY4[9] + e4BulletYOffset);
        //ship 5
        ViewSetxy(e5Bullet1[15], eShipX5[0] + e5BulletXOffset, eShipY5[0] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[15], eShipX5[0] + e5BulletXOffset3, eShipY5[0] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[16], eShipX5[1] + e5BulletXOffset, eShipY5[1] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[16], eShipX5[1] + e5BulletXOffset3, eShipY5[1] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[17], eShipX5[2] + e5BulletXOffset, eShipY5[2] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[17], eShipX5[2] + e5BulletXOffset3, eShipY5[2] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[18], eShipX5[3] + e5BulletXOffset, eShipY5[3] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[18], eShipX5[3] + e5BulletXOffset3, eShipY5[3] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[19], eShipX5[4] + e5BulletXOffset, eShipY5[4] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[19], eShipX5[4] + e5BulletXOffset3, eShipY5[4] + e5BulletYOffset3);
        //ship 6
        ViewSetxy(e6Bullet1[15], eShipX6[0] + e6BulletXOffset, eShipY6[0] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[15], eShipX6[0] + e6BulletXOffset3, eShipY6[0] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[16], eShipX6[1] + e6BulletXOffset, eShipY6[1] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[16], eShipX6[1] + e6BulletXOffset3, eShipY6[1] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[17], eShipX6[2] + e6BulletXOffset, eShipY6[2] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[17], eShipX6[2] + e6BulletXOffset3, eShipY6[2] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[18], eShipX6[3] + e6BulletXOffset, eShipY6[3] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[18], eShipX6[3] + e6BulletXOffset3, eShipY6[3] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[19], eShipX6[4] + e6BulletXOffset, eShipY6[4] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[19], eShipX6[4] + e6BulletXOffset3, eShipY6[4] + e6BulletYOffset3);
        //ship 7
        ViewSetxy(e7Bullet2[15], eShipX7[0] + e7BulletXOffset2, eShipY7[0] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[16], eShipX7[1] + e7BulletXOffset2, eShipY7[1] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[17], eShipX7[2] + e7BulletXOffset2, eShipY7[2] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[18], eShipX7[3] + e7BulletXOffset2, eShipY7[3] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[19], eShipX7[4] + e7BulletXOffset2, eShipY7[4] + e7BulletYOffset2);
        //ship 8
        ViewSetxy(e8Bullet1[15], eShipX8[0] + e8BulletXOffset, eShipY8[0] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[15], eShipX8[0] + e8BulletXOffset2, eShipY8[0] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[15], eShipX8[0] + e8BulletXOffset3, eShipY8[0] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[16], eShipX8[1] + e8BulletXOffset, eShipY8[1] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[16], eShipX8[1] + e8BulletXOffset2, eShipY8[1] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[16], eShipX8[1] + e8BulletXOffset3, eShipY8[1] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[17], eShipX8[2] + e8BulletXOffset, eShipY8[2] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[17], eShipX8[2] + e8BulletXOffset2, eShipY8[2] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[17], eShipX8[2] + e8BulletXOffset3, eShipY8[2] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[18], eShipX8[3] + e8BulletXOffset, eShipY8[3] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[18], eShipX8[3] + e8BulletXOffset2, eShipY8[3] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[18], eShipX8[3] + e8BulletXOffset3, eShipY8[3] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[19], eShipX8[4] + e8BulletXOffset, eShipY8[4] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[19], eShipX8[4] + e8BulletXOffset2, eShipY8[4] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[19], eShipX8[4] + e8BulletXOffset3, eShipY8[4] + e8BulletYOffset3);
        //ship 9
        ViewSetxy(e9Bullet1[3], eShipX9 + e9BulletXOffset, eShipY9 + e9BulletYOffset);
        ViewSetxy(e9Bullet2[3], eShipX9 + e9BulletXOffset2, eShipY9 + e9BulletYOffset2);
        ViewSetxy(e9Bullet3[3], eShipX9 + e9BulletXOffset3, eShipY9 + e9BulletYOffset3);
        //ship 10
        ViewSetxy(e10Bullet1[3], eShipX10 + e10BulletXOffset, eShipY10 + e10BulletYOffset);
        ViewSetxy(e10Bullet2[3], eShipX10 + e10BulletXOffset2, eShipY10 + e10BulletYOffset2);
        ViewSetxy(e10Bullet3[3], eShipX10 + e10BulletXOffset3, eShipY10 + e10BulletYOffset3);
    } else if (counter4 == 5 * EnemyShootCooldownSpeed) {
        //ship 1
        ViewSetxy(e1Bullet1[40], eShipX1[0] + e1BulletXOffset, eShipY1[0] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[41], eShipX1[1] + e1BulletXOffset, eShipY1[1] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[42], eShipX1[2] + e1BulletXOffset, eShipY1[2] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[43], eShipX1[3] + e1BulletXOffset, eShipY1[3] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[44], eShipX1[4] + e1BulletXOffset, eShipY1[4] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[45], eShipX1[5] + e1BulletXOffset, eShipY1[5] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[46], eShipX1[6] + e1BulletXOffset, eShipY1[6] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[47], eShipX1[7] + e1BulletXOffset, eShipY1[7] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[48], eShipX1[8] + e1BulletXOffset, eShipY1[8] + e1BulletYOffset);
        ViewSetxy(e1Bullet1[49], eShipX1[9] + e1BulletXOffset, eShipY1[9] + e1BulletYOffset);
        //ship 2
        ViewSetxy(e2Bullet1[40], eShipX2[0] + e2BulletXOffset, eShipY2[0] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[41], eShipX2[1] + e2BulletXOffset, eShipY2[1] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[42], eShipX2[2] + e2BulletXOffset, eShipY2[2] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[43], eShipX2[3] + e2BulletXOffset, eShipY2[3] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[44], eShipX2[4] + e2BulletXOffset, eShipY2[4] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[45], eShipX2[5] + e2BulletXOffset, eShipY2[5] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[46], eShipX2[6] + e2BulletXOffset, eShipY2[6] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[47], eShipX2[7] + e2BulletXOffset, eShipY2[7] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[48], eShipX2[8] + e2BulletXOffset, eShipY2[8] + e2BulletYOffset);
        ViewSetxy(e2Bullet1[49], eShipX2[9] + e2BulletXOffset, eShipY2[9] + e2BulletYOffset);
        //ship 3
        ViewSetxy(e3Bullet1[40], eShipX3[0] + e3BulletXOffset, eShipY3[0] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[41], eShipX3[1] + e3BulletXOffset, eShipY3[1] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[42], eShipX3[2] + e3BulletXOffset, eShipY3[2] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[43], eShipX3[3] + e3BulletXOffset, eShipY3[3] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[44], eShipX3[4] + e3BulletXOffset, eShipY3[4] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[45], eShipX3[5] + e3BulletXOffset, eShipY3[5] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[46], eShipX3[6] + e3BulletXOffset, eShipY3[6] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[47], eShipX3[7] + e3BulletXOffset, eShipY3[7] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[48], eShipX3[8] + e3BulletXOffset, eShipY3[8] + e3BulletYOffset);
        ViewSetxy(e3Bullet1[49], eShipX3[9] + e3BulletXOffset, eShipY3[9] + e3BulletYOffset);
        //ship 4
        ViewSetxy(e4Bullet1[40], eShipX4[0] + e4BulletXOffset, eShipY4[0] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[41], eShipX4[1] + e4BulletXOffset, eShipY4[1] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[42], eShipX4[2] + e4BulletXOffset, eShipY4[2] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[43], eShipX4[3] + e4BulletXOffset, eShipY4[3] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[44], eShipX4[4] + e4BulletXOffset, eShipY4[4] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[45], eShipX4[5] + e4BulletXOffset, eShipY4[5] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[46], eShipX4[6] + e4BulletXOffset, eShipY4[6] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[47], eShipX4[7] + e4BulletXOffset, eShipY4[7] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[48], eShipX4[8] + e4BulletXOffset, eShipY4[8] + e4BulletYOffset);
        ViewSetxy(e4Bullet1[49], eShipX4[9] + e4BulletXOffset, eShipY4[9] + e4BulletYOffset);
        //ship 5
        ViewSetxy(e5Bullet1[20], eShipX5[0] + e5BulletXOffset, eShipY5[0] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[20], eShipX5[0] + e5BulletXOffset3, eShipY5[0] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[21], eShipX5[1] + e5BulletXOffset, eShipY5[1] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[21], eShipX5[1] + e5BulletXOffset3, eShipY5[1] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[22], eShipX5[2] + e5BulletXOffset, eShipY5[2] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[22], eShipX5[2] + e5BulletXOffset3, eShipY5[2] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[23], eShipX5[3] + e5BulletXOffset, eShipY5[3] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[23], eShipX5[3] + e5BulletXOffset3, eShipY5[3] + e5BulletYOffset3);
        ViewSetxy(e5Bullet1[24], eShipX5[4] + e5BulletXOffset, eShipY5[4] + e5BulletYOffset);
        ViewSetxy(e5Bullet3[24], eShipX5[4] + e5BulletXOffset3, eShipY5[4] + e5BulletYOffset3);
        //ship 6
        ViewSetxy(e6Bullet1[20], eShipX6[0] + e6BulletXOffset, eShipY6[0] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[20], eShipX6[0] + e6BulletXOffset3, eShipY6[0] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[21], eShipX6[1] + e6BulletXOffset, eShipY6[1] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[21], eShipX6[1] + e6BulletXOffset3, eShipY6[1] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[22], eShipX6[2] + e6BulletXOffset, eShipY6[2] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[22], eShipX6[2] + e6BulletXOffset3, eShipY6[2] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[23], eShipX6[3] + e6BulletXOffset, eShipY6[3] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[23], eShipX6[3] + e6BulletXOffset3, eShipY6[3] + e6BulletYOffset3);
        ViewSetxy(e6Bullet1[24], eShipX6[4] + e6BulletXOffset, eShipY6[4] + e6BulletYOffset);
        ViewSetxy(e6Bullet3[24], eShipX6[4] + e6BulletXOffset3, eShipY6[4] + e6BulletYOffset3);
        //ship 7
        ViewSetxy(e7Bullet2[20], eShipX7[0] + e7BulletXOffset2, eShipY7[0] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[21], eShipX7[1] + e7BulletXOffset2, eShipY7[1] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[22], eShipX7[2] + e7BulletXOffset2, eShipY7[2] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[23], eShipX7[3] + e7BulletXOffset2, eShipY7[3] + e7BulletYOffset2);
        ViewSetxy(e7Bullet2[24], eShipX7[4] + e7BulletXOffset2, eShipY7[4] + e7BulletYOffset2);
        //ship 8
        ViewSetxy(e8Bullet1[20], eShipX8[0] + e8BulletXOffset, eShipY8[0] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[20], eShipX8[0] + e8BulletXOffset2, eShipY8[0] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[20], eShipX8[0] + e8BulletXOffset3, eShipY8[0] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[21], eShipX8[1] + e8BulletXOffset, eShipY8[1] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[21], eShipX8[1] + e8BulletXOffset2, eShipY8[1] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[21], eShipX8[1] + e8BulletXOffset3, eShipY8[1] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[22], eShipX8[2] + e8BulletXOffset, eShipY8[2] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[22], eShipX8[2] + e8BulletXOffset2, eShipY8[2] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[22], eShipX8[2] + e8BulletXOffset3, eShipY8[2] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[23], eShipX8[3] + e8BulletXOffset, eShipY8[3] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[23], eShipX8[3] + e8BulletXOffset2, eShipY8[3] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[23], eShipX8[3] + e8BulletXOffset3, eShipY8[3] + e8BulletYOffset3);
        ViewSetxy(e8Bullet1[24], eShipX8[4] + e8BulletXOffset, eShipY8[4] + e8BulletYOffset);
        ViewSetxy(e8Bullet2[24], eShipX8[4] + e8BulletXOffset2, eShipY8[4] + e8BulletYOffset2);
        ViewSetxy(e8Bullet3[24], eShipX8[4] + e8BulletXOffset3, eShipY8[4] + e8BulletYOffset3);
        //ship 9
        ViewSetxy(e9Bullet1[4], eShipX9 + e9BulletXOffset, eShipY9 + e9BulletYOffset);
        ViewSetxy(e9Bullet2[4], eShipX9 + e9BulletXOffset2, eShipY9 + e9BulletYOffset2);
        ViewSetxy(e9Bullet3[4], eShipX9 + e9BulletXOffset3, eShipY9 + e9BulletYOffset3);
        //ship 10
        ViewSetxy(e10Bullet1[4], eShipX10 + e10BulletXOffset, eShipY10 + e10BulletYOffset);
        ViewSetxy(e10Bullet2[4], eShipX10 + e10BulletXOffset2, eShipY10 + e10BulletYOffset2);
        ViewSetxy(e10Bullet3[4], eShipX10 + e10BulletXOffset3, eShipY10 + e10BulletYOffset3);
        //reset
        counter4 = 0;
    } else {
        //1
        for (counter7 = 0; counter7 < 50; counter7++) {
            ex = ViewGetx(e1Bullet1[counter7]);
            ey = ViewGety(e1Bullet1[counter7]);
            if (ey < 600) {
                ViewSetxy(e1Bullet1[counter7], ex, ey + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e1Bullet1[counter7], 600, 600);
            }
        }
        //2
        for (counter7 = 0; counter7 < 50; counter7++) {
            ex = ViewGetx(e2Bullet1[counter7]);
            ey = ViewGety(e2Bullet1[counter7]);
            if (ey < 600) {
                ViewSetxy(e2Bullet1[counter7], ex, ey + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e2Bullet1[counter7], 600, 600);
            }
        }
        //3
        for (counter7 = 0; counter7 < 50; counter7++) {
            ex = ViewGetx(e3Bullet1[counter7]);
            ey = ViewGety(e3Bullet1[counter7]);
            if (ey < 600) {
                ViewSetxy(e3Bullet1[counter7], ex, ey + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e3Bullet1[counter7], 600, 600);
            }
        }
        //4
        for (counter7 = 0; counter7 < 50; counter7++) {
            ex = ViewGetx(e4Bullet1[counter7]);
            ey = ViewGety(e4Bullet1[counter7]);
            if (ey < 600) {
                ViewSetxy(e4Bullet1[counter7], ex, ey + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e4Bullet1[counter7], 600, 600);
            }
        }
        //5
        for (counter7 = 0; counter7 < 25; counter7++) {
            ex = ViewGetx(e5Bullet1[counter7]);
            ey = ViewGety(e5Bullet1[counter7]);
            ex3 = ViewGetx(e5Bullet3[counter7]);
            ey3 = ViewGety(e5Bullet3[counter7]);
            if (ey < 600 || ey3 < 600) {
                ViewSetxy(e5Bullet1[counter7], ex, ey + EnemyBulletSpeed);
                ViewSetxy(e5Bullet3[counter7], ex3, ey3 + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e5Bullet1[counter7], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e5Bullet3[counter7], 600, 600);
            }
        }
        //6
        for (counter7 = 0; counter7 < 25; counter7++) {
            ex = ViewGetx(e6Bullet1[counter7]);
            ey = ViewGety(e6Bullet1[counter7]);
            ex3 = ViewGetx(e6Bullet3[counter7]);
            ey3 = ViewGety(e6Bullet3[counter7]);
            if (ey < 600 || ey3 < 600) {
                ViewSetxy(e6Bullet1[counter7], ex, ey + EnemyBulletSpeed);
                ViewSetxy(e6Bullet3[counter7], ex3, ey3 + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e6Bullet1[counter7], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e6Bullet3[counter7], 600, 600);
            }
        }
        //7
        for (counter7 = 0; counter7 < 25; counter7++) {
            ex2 = ViewGetx(e7Bullet2[counter7]);
            ey2 = ViewGety(e7Bullet2[counter7]);
            if (ey2 < 600) {
                ViewSetxy(e7Bullet2[counter7], ex2, ey2 + EnemyBulletSpeed);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                HealthUpdate = true;
                ViewSetxy(e7Bullet2[counter7], 600, 600);
            }
        }
        //8
        for (counter7 = 0; counter7 < 25; counter7++) {
            ex = ViewGetx(e8Bullet1[counter7]);
            ey = ViewGety(e8Bullet1[counter7]);
            ex2 = ViewGetx(e8Bullet2[counter7]);
            ey2 = ViewGety(e8Bullet2[counter7]);
            ex3 = ViewGetx(e8Bullet3[counter7]);
            ey3 = ViewGety(e8Bullet3[counter7]);
            if (ey < 600 || ey2 < 600 || ey3 < 600) {
                ViewSetxy(e8Bullet1[counter7], ex, ey + EnemyBulletSpeed);
                ViewSetxy(e8Bullet2[counter7], ex2, ey2 + EnemyBulletSpeed);
                ViewSetxy(e8Bullet3[counter7], ex3, ey3 + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e8Bullet1[counter7], 600, 600);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                HealthUpdate = true;
                ViewSetxy(e8Bullet2[counter7], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e8Bullet3[counter7], 600, 600);
            }
        }
        //9
        for (counter7 = 0; counter7 < 5; counter7++) {
            ex = ViewGetx(e9Bullet1[counter7]);
            ey = ViewGety(e9Bullet1[counter7]);
            ex2 = ViewGetx(e9Bullet2[counter7]);
            ey2 = ViewGety(e9Bullet2[counter7]);
            ex3 = ViewGetx(e9Bullet3[counter7]);
            ey3 = ViewGety(e9Bullet3[counter7]);
            if (ey < 600 || ey2 < 600 || ey3 < 600) {
                ViewSetxy(e9Bullet1[counter7], ex, ey + EnemyBulletSpeed);
                ViewSetxy(e9Bullet2[counter7], ex2, ey2 + EnemyBulletSpeed);
                ViewSetxy(e9Bullet3[counter7], ex3, ey3 + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e9Bullet1[counter7], 600, 600);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                HealthUpdate = true;
                ViewSetxy(e9Bullet2[counter7], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e9Bullet3[counter7], 600, 600);
            }
        }
        //10
        for (counter7 = 0; counter7 < 5; counter7++) {
            ex = ViewGetx(e10Bullet1[counter7]);
            ey = ViewGety(e10Bullet1[counter7]);
            ex2 = ViewGetx(e10Bullet2[counter7]);
            ey2 = ViewGety(e10Bullet2[counter7]);
            ex3 = ViewGetx(e10Bullet3[counter7]);
            ey3 = ViewGety(e10Bullet3[counter7]);
            if (ey < 600 || ey2 < 600 || ey3 < 600) {
                ViewSetxy(e10Bullet1[counter7], ex, ey + EnemyBulletSpeed);
                ViewSetxy(e10Bullet2[counter7], ex2, ey2 + EnemyBulletSpeed);
                ViewSetxy(e10Bullet3[counter7], ex3, ey3 + EnemyBulletSpeed);
            }
            if (ey > mY && ey < mY + 94 && ex > mX + width1 && ex < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e10Bullet1[counter7], 600, 600);
            }
            if (ey2 > mY && ey2 < mY + 94 && ex2 > mX + width1 && ex2 < mX + width2) {
                health -= 3;
                HealthUpdate = true;
                ViewSetxy(e10Bullet2[counter7], 600, 600);
            }
            if (ey3 > mY && ey3 < mY + 94 && ex3 > mX + width1 && ex3 < mX + width2) {
                health -= 1;
                HealthUpdate = true;
                ViewSetxy(e10Bullet3[counter7], 600, 600);
            }
        }
    }
}
void EnemyDied() {
    int explosion, image;
    for (counter10 = 0; counter10 < 10; counter10++) {
        if (eShip1Health[counter10] <= 0 && counter5[0] == 0 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_1.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 1 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_2.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 2 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_3.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 3 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_4.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 4 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_5.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 5 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_6.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 6 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_7.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 7 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_8.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 8 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_9.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 9 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_10.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 10 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/Explosion_11.png");
            ViewSetImage(explosion, image);
            counter5[0] += 1;
        } else if (eShip1Health[counter10] <= 0 && counter5[0] == 11 && eShipY1[counter10] >= 0 && eShipX1[counter10] < 600 && eShipY1[counter10] >= 0 && eShipX1[counter10] <= 320) {
            explosion = (eShip1[counter10]);
            image = ImageAdd("Images/eShip_1.png");
            ViewSetImage(explosion, image);
            ViewSetxy(eShip1[counter10], 600, 600);
            counter5[0] = 0;
            xp += level * 1;
        }
    }
    for (counter10 = 0; counter10 < 10; counter10++) {
        if (eShip2Health[counter10] <= 0 && counter5[1] == 0 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_1.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 1 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_2.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 2 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_3.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 3 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_4.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 4 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_5.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 5 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_6.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 6 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_7.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 7 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_8.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 8 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_9.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 9 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_10.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 10 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/Explosion_11.png");
            ViewSetImage(explosion, image);
            counter5[1] += 1;
        } else if (eShip2Health[counter10] <= 0 && counter5[1] == 11 && eShipY2[counter10] >= 0 && eShipX2[counter10] < 600 && eShipY2[counter10] >= 0 && eShipX2[counter10] <= 320) {
            explosion = (eShip2[counter10]);
            image = ImageAdd("Images/eShip_2.png");
            ViewSetImage(explosion, image);
            ViewSetxy(eShip2[counter10], 600, 600);
            counter5[1] = 0;
            xp += level * 1;
        }
    }
    for (counter10 = 0; counter10 < 10; counter10++) {
        if (eShip3Health[counter10] <= 0 && counter5[2] == 0 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_1.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 1 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_2.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 2 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_3.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 3 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_4.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 4 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_5.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 5 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_6.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 6 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_7.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 7 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_8.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 8 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_9.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 9 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_10.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 10 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/Explosion_11.png");
            ViewSetImage(explosion, image);
            counter5[2] += 1;
        } else if (eShip3Health[counter10] <= 0 && counter5[2] == 11 && eShipY3[counter10] >= 0 && eShipX3[counter10] < 600 && eShipY3[counter10] >= 0 && eShipX3[counter10] <= 320) {
            explosion = (eShip3[counter10]);
            image = ImageAdd("Images/eShip_3.png");
            ViewSetImage(explosion, image);
            ViewSetxy(eShip3[counter10], 600, 600);
            counter5[2] = 0;
            xp += level * 1;
        }
    }
    for (counter10 = 0; counter10 < 10; counter10++) {
        if (eShip4Health[counter10] <= 0 && counter5[3] == 0 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_1.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 1 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_2.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 2 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_3.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 3 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_4.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 4 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_5.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 5 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_6.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 6 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_7.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 7 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_8.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 8 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_9.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 9 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_10.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 10 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/Explosion_11.png");
            ViewSetImage(explosion, image);
            counter5[3] += 1;
        } else if (eShip4Health[counter10] <= 0 && counter5[3] == 11 && eShipY4[counter10] >= 0 && eShipX4[counter10] < 600 && eShipY4[counter10] >= 0 && eShipX4[counter10] <= 320) {
            explosion = (eShip4[counter10]);
            image = ImageAdd("Images/eShip_4.png");
            ViewSetImage(explosion, image);
            ViewSetxy(eShip4[counter10], 600, 600);
            counter5[3] = 0;
            xp += level * 1;
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
    for (counter11 = 0; counter11 < 10; counter11++) {
        //ship 1
        if (mX + width1 < eShipX1[counter11] + 76 && mX + width2 > eShipX1[counter11] + 18 && mY < eShipY1[counter11] + 94 && mY + 94 > eShipY1[counter11]) {
            if (eShip1Health[counter11] > 0) {
                eShip1Health[counter11] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 2
        if (mX + width1 < eShipX2[counter11] + 69 && mX + width2 > eShipX2[counter11] + 24 && mY < eShipY2[counter11] + 94 && mY + 94 > eShipY2[counter11]) {
            if (eShip2Health[counter11] > 0) {
                eShip2Health[counter11] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 3
        if (mX + width1 < eShipX3[counter11] + 66 && mX + width2 > eShipX3[counter11] + 27 && mY < eShipY3[counter11] + 94 && mY + 94 > eShipY3[counter11]) {
            if (eShip3Health[counter11] > 0) {
                eShip3Health[counter11] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 4
        if (mX + width1 < eShipX4[counter11] + 87 && mX + width2 > eShipX4[counter11] + 6 && mY < eShipY4[counter11] + 94 && mY + 94 > eShipY4[counter11]) {
            if (eShip4Health[counter11] > 0) {
                eShip4Health[counter11] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
    }
    for (counter11 = 0; counter11 < 5; counter11++) {
        //ship 5
        if (mX + width1 < eShipX5[counter11] + 71 && mX + width2 > eShipX5[counter11] + 22 && mY < eShipY5[counter11] + 94 && mY + 94 > eShipY5[counter11]) {
            if (eShip5Health[counter11] > 0) {
                eShip5Health[counter11] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 6
        if (mX + width1 < eShipX6[counter11] + 81 && mX + width2 > eShipX6[counter11] + 12 && mY < eShipY6[counter11] + 94 && mY + 94 > eShipY6[counter11]) {
            if (eShip6Health[counter11] > 0) {
                eShip6Health[counter11] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 7
        if (mX + width1 < eShipX7[counter11] + 86 && mX + width2 > eShipX7[counter11] + 7 && mY < eShipY7[counter11] + 94 && mY + 94 > eShipY7[counter11]) {
            if (eShip7Health[counter11] > 0) {
                eShip7Health[counter11] -= 2 + level;
                health -= 2 + level;
                HealthUpdate = true;
            }
        }
        //ship 8
        if (mX + width1 < eShipX8[counter11] + 86 && mX + width2 > eShipX8[counter11] + 6 && mY < eShipY8[counter11] + 94 && mY + 94 > eShipY8[counter11]) {
            if (eShip8Health[counter11] > 0) {
                eShip8Health[counter11] -= 2 + level;
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
void OnTimer() {
//called 30 times per second - 1800=1min - 10000=5min 36sec
    Rank();
    SoundSwitch();
    DoUpdateHighscore();
    if (sound == true) {
        counter += 1;
    }
    if (pause == false) {
        if (CurrentScreen == ScreenEndless || CurrentScreen == ScreenStoryBattle1 || CurrentScreen == ScreenStoryBattle2 || CurrentScreen == ScreenStoryBattle4 || CurrentScreen == ScreenStoryBattle5 || CurrentScreen == ScreenStoryBattle6) {
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
        } else if (CurrentScreen == ScreenStoryTorture && torture == true) {
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
        } else if (CurrentScreen == ScreenStoryTorture && torture == false) {
            HpCounterTorture += 1;
            TortureHealth();
            TextSetText(TextTorture, "");
        }
    }
}
