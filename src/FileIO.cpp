#include "DragonFireSDK.h"
#include "Globals.h"
#include "FileIO.h"

int intFileToGame(char *buffer) {
    int ret = 0;
    ret += ((int) buffer[0] - '0') * 10000;
    ret += ((int) buffer[1] - '0') * 1000;
    ret += ((int) buffer[2] - '0') * 100;
    ret += ((int) buffer[3] - '0') * 10;
    ret += (int) buffer[4] - '0';
    return ret;
}

bool boolFileToGame(char *buffer) {
    return buffer[0] == 't';
}

void intGameToFile(int num, char *buffer) {
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

void boolGameToFile(bool num, char *buffer) {
    buffer[0] = (num) ? ('t') : ('f');
}

void loadGame() {
    loadSoundStatus();
    loadXp();
    loadShip();
    loadHighscore();
    loadSoundCounter();
}

void loadSoundStatus() {
    int fileSound = FileOpen("Sound.txt");
    if (!fileSound) {
        fileSound = FileCreate("Sound.txt");
        isSoundEnabled = true;
    } else {
        char fileBuffer[5];
        FileRead(fileSound, fileBuffer, 1);
        isSoundEnabled = boolFileToGame(fileBuffer);
    }
    FileClose(fileSound);
}

void loadXp() {
    int fileXp = FileOpen("Xp.txt");
    if (!fileXp) {
        fileXp = FileCreate("Xp.txt");
    } else {
        char fileBuffer[5];
        FileRead(fileXp, fileBuffer, 5);
        xp = intFileToGame(fileBuffer);
    }
    FileClose(fileXp);
}

void loadShip() {
    int fileShip = FileOpen("Ship.txt");
    if (!fileShip) {
        fileShip = FileCreate("Ship.txt");
        player.typeOfShip = 1;
    } else {
        char fileBuffer[5];
        FileRead(fileShip, fileBuffer, 5);
        player.typeOfShip = intFileToGame(fileBuffer);
    }
    FileClose(fileShip);
}

void loadHighscore() {
    int fileHighscore = FileOpen("Highscore.txt");
    if (!fileHighscore) {
        fileHighscore = FileCreate("Highscore.txt");
    } else {
        char fileBuffer[5];
        FileRead(fileHighscore, fileBuffer, 5);
        highscore = intFileToGame(fileBuffer);
    }
    FileClose(fileHighscore);
}

void loadSoundCounter() {
    int fileCounter = FileOpen("Counter.txt");
    if (!fileCounter) {
        fileCounter = FileCreate("Counter.txt");
    } else {
        char fileBuffer[5];
        FileRead(fileCounter, fileBuffer, 5);
        counter.sound = intFileToGame(fileBuffer);
    }
    FileClose(fileCounter);
}
