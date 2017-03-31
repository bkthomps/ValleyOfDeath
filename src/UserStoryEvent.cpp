/*
 * Dictates which screens will be visible based on user decision when in story mode.
 */

#include "DragonFireSDK.h"
#include "Globals.h"
#include "UserStoryEvent.h"
#include "StateToggle.h"

int onStoryMenuTouch(int id, int event, int x, int y) {
    if (event == 3) {
        currentScreen = SCREEN_STORY_1A1;
        screenSwitch();
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

int onStoryLevelTwo(int id, int event, int x, int y) {
    if (event == 3) {
        switch (id) {
            case 1:
                currentScreen = SCREEN_STORY_2A2;
                break;
            case 3:
                isStoryDate = true;
                currentScreen = SCREEN_STORY_2A3;
                break;
            case 4:
                isStoryDate = false;
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

int onStoryLevelFive(int id, int event, int x, int y) {
    if (event == 3) {
        switch (id) {
            case 1:
                currentScreen = (isStoryDate) ? SCREEN_STORY_5A2 : SCREEN_STORY_5A3;
                break;
            case 2:
                isStoryMarry = true;
                currentScreen = SCREEN_STORY_5A3;
                break;
            case 3:
                currentScreen = SCREEN_STORY_5B4;
                break;
            case 4:
                currentScreen = SCREEN_STORY_5A5;
                break;
            case 5:
                currentScreen = SCREEN_STORY_5A6;
                break;
            case 6:
                currentScreen = SCREEN_STORY_5B6;
                break;
            case 7:
                currentScreen = SCREEN_STORY_BATTLE_5;
                screenSwitch();
                reset();
                set = 4;
                level = 1;
                break;
            case 8:
                isStoryMarry = false;
                currentScreen = SCREEN_STORY_5A3;
                break;
        }
        if (id != 7) {
            screenSwitch();
        }
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

int onStoryLevelSeven(int id, int event, int x, int y) {
    if (event == 3) {
        if (id == 1) {
            currentScreen = SCREEN_STORY_7A2;
        } else if (id == 2) {
            const int SAVE_RON = TextAdd(container.story7b2, 0, 0, "", font);
            if (isStoryDate && !isStoryMarry) {
                TextSetText(SAVE_RON, "\n\nRon: \nThe world will know of your \ngreatness. I will be sure to \ntell "
                        "your girlfriend that you \nwere a great man.");
            } else if (isStoryDate && isStoryMarry) {
                TextSetText(SAVE_RON, "\n\nRon: \nThe world will know of your \ngreatness. I will be sure to \ntell "
                        "your wife that you were a \ngreat man.");
            } else if (!isStoryDate && !isStoryMarry) {
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
