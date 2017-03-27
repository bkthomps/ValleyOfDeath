#include "DragonFireSDK.h"
#include "Globals.h"
#include "Sound.h"

void startupMusic() {
    if (isSoundEnabled) {
        if (counter.sound > 1 && counter.sound < 7000) {
            counter.sound = 7000;
        } else if (counter.sound > 7000 && counter.sound < 13000) {
            counter.sound = 13000;
        } else if (counter.sound > 13000 && counter.sound < 19000) {
            counter.sound = 19000;
        } else if (counter.sound > 19000 && counter.sound < 27000) {
            counter.sound = 27000;
        } else if (counter.sound > 27000 && counter.sound < 34000) {
            counter.sound = 34000;
        } else if (counter.sound > 34000 && counter.sound < 42000) {
            counter.sound = 42000;
        } else if (counter.sound > 42000 && counter.sound < 49000) {
            counter.sound = 49000;
        } else if (counter.sound > 49000 && counter.sound < 55000) {
            counter.sound = 55000;
        } else if (counter.sound > 55000 && counter.sound < 61000) {
            counter.sound = 61000;
        } else if (counter.sound > 61000 && counter.sound < 67000) {
            counter.sound = 67000;
        } else if (counter.sound > 67000 && counter.sound < 73000) {
            counter.sound = 73000;
        } else if (counter.sound > 73000 && counter.sound < 79000) {
            counter.sound = 79000;
        } else if (counter.sound > 79000) {
            counter.sound = 1;
        }
        if (counter.sound > 1 && counter.sound < 7000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/1.mp3"));
        } else if (counter.sound > 7000 && counter.sound < 13000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/2.mp3"));
        } else if (counter.sound > 13000 && counter.sound < 19000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/3.mp3"));
        } else if (counter.sound > 19000 && counter.sound < 27000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/5.mp3"));
        } else if (counter.sound > 27000 && counter.sound < 34000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/7.mp3"));
        } else if (counter.sound > 34000 && counter.sound < 42000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/8.mp3"));
        } else if (counter.sound > 42000 && counter.sound < 49000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/9.mp3"));
        } else if (counter.sound > 49000 && counter.sound < 55000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/11.mp3"));
        } else if (counter.sound > 55000 && counter.sound < 61000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/12.mp3"));
        } else if (counter.sound > 61000 && counter.sound < 67000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/13.mp3"));
        } else if (counter.sound > 67000 && counter.sound < 73000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/14.mp3"));
        } else if (counter.sound > 73000 && counter.sound < 79000) {
            Mp3Stop();
            Mp3Loop(Mp3Add("Sounds/15.mp3"));
        }
    } else {
        Mp3Stop();
    }
}

void soundSwitch() {
    if (isSoundEnabled) {
        if (counter.sound == 1) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/1.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 7000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/2.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 13000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/3.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 19000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/5.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 27000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/7.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 34000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/8.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 42000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/9.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 49000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/11.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 55000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/12.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 61000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/13.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 67000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/14.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound == 73000) {
            if (isNotActive()) {
                Mp3Stop();
                Mp3Loop(Mp3Add("Sounds/15.mp3"));
            } else {
                counter.sound--;
            }
        } else if (counter.sound >= 79000) {
            counter.sound = 0;
        }
    } else {
        Mp3Stop();
    }
}

bool isNotActive() {
    return currentScreen != SCREEN_ENDLESS && currentScreen != SCREEN_STORY_BATTLE_1
               && currentScreen != SCREEN_STORY_BATTLE_2 && currentScreen != SCREEN_STORY_BATTLE_4
               && currentScreen != SCREEN_STORY_BATTLE_5 && currentScreen != SCREEN_STORY_BATTLE_6
               && currentScreen != SCREEN_DIED && currentScreen != SCREEN_HIGHSCORE;
}
