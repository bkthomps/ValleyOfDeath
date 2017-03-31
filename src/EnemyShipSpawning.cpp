/*
 * Dictates what ships will spawn in each level. There are five levels, each level has 30 rounds of ship spawning. At
 * the end of each level, there is a boss battle.
 */

#include "DragonFireSDK.h"
#include "Globals.h"
#include "EnemyShipSpawning.h"
#include "StateToggle.h"

void setOne() {
    switch (counter.shipMove) {
        case 1 * ENEMY_SPAWN_TIME:
            one[0].resetHealth(level);
            ViewSetxy(one[0].getInstance(), 113, -94);
            break;
        case 2 * ENEMY_SPAWN_TIME:
            one[1].resetHealth(level);
            two[0].resetHealth(level);
            ViewSetxy(one[1].getInstance(), 33, -94);
            ViewSetxy(two[0].getInstance(), 193, -94);
            break;
        case 3 * ENEMY_SPAWN_TIME:
            two[1].resetHealth(level);
            ViewSetxy(two[1].getInstance(), 113, -94);
            break;
        case 4 * ENEMY_SPAWN_TIME:
            two[2].resetHealth(level);
            one[2].resetHealth(level);
            ViewSetxy(two[2].getInstance(), 33, -94);
            ViewSetxy(one[2].getInstance(), 193, -94);
            break;
        case 5 * ENEMY_SPAWN_TIME:
            one[3].resetHealth(level);
            three[0].resetHealth(level);
            two[3].resetHealth(level);
            ViewSetxy(one[3].getInstance(), 0, -94);
            ViewSetxy(three[0].getInstance(), 113, -94);
            ViewSetxy(two[3].getInstance(), 226, -94);
            break;
        case 6 * ENEMY_SPAWN_TIME:
            three[1].resetHealth(level);
            two[4].resetHealth(level);
            three[2].resetHealth(level);
            ViewSetxy(three[1].getInstance(), 0, -94);
            ViewSetxy(two[4].getInstance(), 113, -94);
            ViewSetxy(three[2].getInstance(), 226, -94);
            break;
        case 7 * ENEMY_SPAWN_TIME:
            one[4].resetHealth(level);
            one[5].resetHealth(level);
            two[5].resetHealth(level);
            ViewSetxy(one[4].getInstance(), 0, -94);
            ViewSetxy(one[5].getInstance(), 113, -94);
            ViewSetxy(two[5].getInstance(), 226, -94);
            break;
        case 8 * ENEMY_SPAWN_TIME:
            three[3].resetHealth(level);
            one[6].resetHealth(level);
            one[7].resetHealth(level);
            ViewSetxy(three[3].getInstance(), 0, -94);
            ViewSetxy(one[6].getInstance(), 113, -94);
            ViewSetxy(one[7].getInstance(), 226, -94);
            break;
        case 9 * ENEMY_SPAWN_TIME:
            two[6].resetHealth(level);
            three[4].resetHealth(level);
            ViewSetxy(two[6].getInstance(), 33, -94);
            ViewSetxy(three[4].getInstance(), 193, -94);
            break;
        case 10 * ENEMY_SPAWN_TIME:
            four[0].resetHealth(level);
            ViewSetxy(four[0].getInstance(), 113, -94);
            break;
        case 11 * ENEMY_SPAWN_TIME:
            three[5].resetHealth(level);
            four[1].resetHealth(level);
            ViewSetxy(three[5].getInstance(), 33, -94);
            ViewSetxy(four[1].getInstance(), 193, -94);
            break;
        case 12 * ENEMY_SPAWN_TIME:
            one[8].resetHealth(level);
            two[7].resetHealth(level);
            one[9].resetHealth(level);
            ViewSetxy(one[8].getInstance(), 0, -94);
            ViewSetxy(two[7].getInstance(), 113, -94);
            ViewSetxy(one[9].getInstance(), 226, -94);
            break;
        case 13 * ENEMY_SPAWN_TIME:
            four[2].resetHealth(level);
            one[0].resetHealth(level);
            three[6].resetHealth(level);
            ViewSetxy(four[2].getInstance(), 0, -94);
            ViewSetxy(one[0].getInstance(), 113, -94);
            ViewSetxy(three[6].getInstance(), 226, -94);
            break;
        case 14 * ENEMY_SPAWN_TIME:
            two[8].resetHealth(level);
            four[3].resetHealth(level);
            three[7].resetHealth(level);
            ViewSetxy(two[8].getInstance(), 0, -94);
            ViewSetxy(four[3].getInstance(), 113, -94);
            ViewSetxy(three[7].getInstance(), 226, -94);
            break;
        case 15 * ENEMY_SPAWN_TIME:
            four[4].resetHealth(level);
            four[5].resetHealth(level);
            ViewSetxy(four[4].getInstance(), 33, -94);
            ViewSetxy(four[5].getInstance(), 193, -94);
            break;
        case 16 * ENEMY_SPAWN_TIME:
            two[9].resetHealth(level);
            two[0].resetHealth(level);
            three[8].resetHealth(level);
            ViewSetxy(two[9].getInstance(), 0, -94);
            ViewSetxy(two[0].getInstance(), 113, -94);
            ViewSetxy(three[8].getInstance(), 226, -94);
            break;
        case 17 * ENEMY_SPAWN_TIME:
            three[9].resetHealth(level);
            one[2].resetHealth(level);
            two[1].resetHealth(level);
            ViewSetxy(three[9].getInstance(), 0, -94);
            ViewSetxy(one[2].getInstance(), 113, -94);
            ViewSetxy(two[1].getInstance(), 226, -94);
            break;
        case 18 * ENEMY_SPAWN_TIME:
            four[6].resetHealth(level);
            two[2].resetHealth(level);
            ViewSetxy(four[6].getInstance(), 33, -94);
            ViewSetxy(two[2].getInstance(), 193, -94);
            break;
        case 19 * ENEMY_SPAWN_TIME:
            five[0].resetHealth(level);
            ViewSetxy(five[0].getInstance(), 113, -94);
            break;
        case 20 * ENEMY_SPAWN_TIME:
            two[3].resetHealth(level);
            four[7].resetHealth(level);
            ViewSetxy(two[3].getInstance(), 33, -94);
            ViewSetxy(four[7].getInstance(), 193, -94);
            break;
        case 21 * ENEMY_SPAWN_TIME:
            one[1].resetHealth(level);
            five[1].resetHealth(level);
            one[2].resetHealth(level);
            ViewSetxy(one[1].getInstance(), 0, -94);
            ViewSetxy(five[1].getInstance(), 113, -94);
            ViewSetxy(one[2].getInstance(), 226, -94);
            break;
        case 22 * ENEMY_SPAWN_TIME:
            four[8].resetHealth(level);
            two[4].resetHealth(level);
            four[9].resetHealth(level);
            ViewSetxy(four[8].getInstance(), 0, -94);
            ViewSetxy(two[4].getInstance(), 113, -94);
            ViewSetxy(four[9].getInstance(), 226, -94);
            break;
        case 23 * ENEMY_SPAWN_TIME:
            five[2].resetHealth(level);
            five[3].resetHealth(level);
            ViewSetxy(five[2].getInstance(), 33, -94);
            ViewSetxy(five[3].getInstance(), 193, -94);
            break;
        case 24 * ENEMY_SPAWN_TIME:
            four[0].resetHealth(level);
            five[4].resetHealth(level);
            four[1].resetHealth(level);
            ViewSetxy(four[0].getInstance(), 0, -94);
            ViewSetxy(five[4].getInstance(), 113, -94);
            ViewSetxy(four[1].getInstance(), 226, -94);
            break;
        case 25 * ENEMY_SPAWN_TIME:
            five[0].resetHealth(level);
            one[3].resetHealth(level);
            three[0].resetHealth(level);
            ViewSetxy(five[0].getInstance(), 0, -94);
            ViewSetxy(one[3].getInstance(), 113, -94);
            ViewSetxy(three[0].getInstance(), 226, -94);
            break;
        case 26 * ENEMY_SPAWN_TIME:
            five[1].resetHealth(level);
            five[2].resetHealth(level);
            ViewSetxy(five[1].getInstance(), 33, -94);
            ViewSetxy(five[2].getInstance(), 193, -94);
            break;
        case 27 * ENEMY_SPAWN_TIME:
            one[4].resetHealth(level);
            three[1].resetHealth(level);
            one[1].resetHealth(level);
            ViewSetxy(one[4].getInstance(), 0, -94);
            ViewSetxy(three[1].getInstance(), 113, -94);
            ViewSetxy(one[1].getInstance(), 226, -94);
            break;
        case 28 * ENEMY_SPAWN_TIME:
            four[2].resetHealth(level);
            five[3].resetHealth(level);
            two[5].resetHealth(level);
            ViewSetxy(four[2].getInstance(), 0, -94);
            ViewSetxy(five[3].getInstance(), 113, -94);
            ViewSetxy(two[5].getInstance(), 226, -94);
            break;
        case 29 * ENEMY_SPAWN_TIME:
            one[2].resetHealth(level);
            one[3].resetHealth(level);
            ViewSetxy(one[2].getInstance(), 33, -94);
            ViewSetxy(one[3].getInstance(), 193, -94);
            break;
        case 30 * ENEMY_SPAWN_TIME:
            if (currentScreen != SCREEN_STORY_BATTLE_1) {
                nine.resetHealth(level);
                ViewSetxy(nine.getInstance(), 89, -240);
            }
            break;
        case 31 * ENEMY_SPAWN_TIME:
            if (currentScreen == SCREEN_STORY_BATTLE_1) {
                currentScreen = SCREEN_STORY_2A1;
                screenSwitch();
            }
            break;
    }
}

void setTwo() {
    switch (counter.shipMove) {
        case 1 * ENEMY_SPAWN_TIME:
            one[0].resetHealth(level);
            two[0].resetHealth(level);
            ViewSetxy(one[0].getInstance(), 33, -94);
            ViewSetxy(two[0].getInstance(), 193, -94);
            break;
        case 2 * ENEMY_SPAWN_TIME:
            four[0].resetHealth(level);
            three[0].resetHealth(level);
            ViewSetxy(four[0].getInstance(), 33, -94);
            ViewSetxy(three[0].getInstance(), 193, -94);
            break;
        case 3 * ENEMY_SPAWN_TIME:
            five[0].resetHealth(level);
            ViewSetxy(five[0].getInstance(), 113, -94);
            break;
        case 4 * ENEMY_SPAWN_TIME:
            three[1].resetHealth(level);
            two[1].resetHealth(level);
            ViewSetxy(three[1].getInstance(), 33, -94);
            ViewSetxy(two[1].getInstance(), 193, -94);
            break;
        case 5 * ENEMY_SPAWN_TIME:
            three[2].resetHealth(level);
            four[1].resetHealth(level);
            three[3].resetHealth(level);
            ViewSetxy(three[2].getInstance(), 0, -94);
            ViewSetxy(four[1].getInstance(), 113, -94);
            ViewSetxy(three[3].getInstance(), 226, -94);
            break;
        case 6 * ENEMY_SPAWN_TIME:
            one[1].resetHealth(level);
            two[2].resetHealth(level);
            two[3].resetHealth(level);
            ViewSetxy(one[1].getInstance(), 0, -94);
            ViewSetxy(two[2].getInstance(), 113, -94);
            ViewSetxy(two[3].getInstance(), 226, -94);
            break;
        case 7 * ENEMY_SPAWN_TIME:
            four[2].resetHealth(level);
            two[4].resetHealth(level);
            three[4].resetHealth(level);
            ViewSetxy(four[2].getInstance(), 0, -94);
            ViewSetxy(two[4].getInstance(), 113, -94);
            ViewSetxy(three[4].getInstance(), 226, -94);
            break;
        case 8 * ENEMY_SPAWN_TIME:
            two[5].resetHealth(level);
            one[2].resetHealth(level);
            one[3].resetHealth(level);
            ViewSetxy(two[5].getInstance(), 0, -94);
            ViewSetxy(one[2].getInstance(), 113, -94);
            ViewSetxy(one[3].getInstance(), 226, -94);
            break;
        case 9 * ENEMY_SPAWN_TIME:
            four[3].resetHealth(level);
            three[5].resetHealth(level);
            ViewSetxy(four[3].getInstance(), 33, -94);
            ViewSetxy(three[5].getInstance(), 193, -94);
            break;
        case 10 * ENEMY_SPAWN_TIME:
            five[1].resetHealth(level);
            five[2].resetHealth(level);
            ViewSetxy(five[1].getInstance(), 33, -94);
            ViewSetxy(five[2].getInstance(), 193, -94);
            break;
        case 11 * ENEMY_SPAWN_TIME:
            four[4].resetHealth(level);
            ViewSetxy(four[4].getInstance(), 113, -94);
            break;
        case 12 * ENEMY_SPAWN_TIME:
            five[3].resetHealth(level);
            two[6].resetHealth(level);
            ViewSetxy(five[3].getInstance(), 33, -94);
            ViewSetxy(two[6].getInstance(), 193, -94);
            break;
        case 13 * ENEMY_SPAWN_TIME:
            three[6].resetHealth(level);
            two[7].resetHealth(level);
            two[8].resetHealth(level);
            ViewSetxy(three[6].getInstance(), 0, -94);
            ViewSetxy(two[7].getInstance(), 113, -94);
            ViewSetxy(two[8].getInstance(), 226, -94);
            break;
        case 14 * ENEMY_SPAWN_TIME:
            two[9].resetHealth(level);
            five[4].resetHealth(level);
            one[4].resetHealth(level);
            ViewSetxy(two[9].getInstance(), 0, -94);
            ViewSetxy(five[4].getInstance(), 113, -94);
            ViewSetxy(four[4].getInstance(), 226, -94);
            break;
        case 15 * ENEMY_SPAWN_TIME:
            five[0].resetHealth(level);
            one[5].resetHealth(level);
            four[5].resetHealth(level);
            ViewSetxy(five[0].getInstance(), 0, -94);
            ViewSetxy(one[5].getInstance(), 113, -94);
            ViewSetxy(four[5].getInstance(), 226, -94);
            break;
        case 16 * ENEMY_SPAWN_TIME:
            one[6].resetHealth(level);
            three[7].resetHealth(level);
            ViewSetxy(one[6].getInstance(), 33, -94);
            ViewSetxy(three[7].getInstance(), 193, -94);
            break;
        case 17 * ENEMY_SPAWN_TIME:
            four[6].resetHealth(level);
            five[1].resetHealth(level);
            ViewSetxy(four[6].getInstance(), 33, -94);
            ViewSetxy(five[1].getInstance(), 193, -94);
            break;
        case 18 * ENEMY_SPAWN_TIME:
            one[7].resetHealth(level);
            five[2].resetHealth(level);
            one[8].resetHealth(level);
            ViewSetxy(one[7].getInstance(), 0, -94);
            ViewSetxy(five[2].getInstance(), 113, -94);
            ViewSetxy(one[8].getInstance(), 226, -94);
            break;
        case 19 * ENEMY_SPAWN_TIME:
            one[9].resetHealth(level);
            three[8].resetHealth(level);
            ViewSetxy(one[9].getInstance(), 33, -94);
            ViewSetxy(three[8].getInstance(), 193, -94);
            break;
        case 20 * ENEMY_SPAWN_TIME:
            six[0].resetHealth(level);
            ViewSetxy(six[0].getInstance(), 113, -94);
            break;
        case 21 * ENEMY_SPAWN_TIME:
            three[9].resetHealth(level);
            ViewSetxy(three[9].getInstance(), 113, -94);
            break;
        case 22 * ENEMY_SPAWN_TIME:
            two[0].resetHealth(level);
            one[0].resetHealth(level);
            ViewSetxy(two[0].getInstance(), 33, -94);
            ViewSetxy(one[0].getInstance(), 193, -94);
            break;
        case 23 * ENEMY_SPAWN_TIME:
            three[0].resetHealth(level);
            five[3].resetHealth(level);
            ViewSetxy(three[0].getInstance(), 33, -94);
            ViewSetxy(five[3].getInstance(), 193, -94);
            break;
        case 24 * ENEMY_SPAWN_TIME:
            six[1].resetHealth(level);
            four[7].resetHealth(level);
            six[2].resetHealth(level);
            ViewSetxy(six[1].getInstance(), 0, -94);
            ViewSetxy(four[7].getInstance(), 113, -94);
            ViewSetxy(six[2].getInstance(), 226, -94);
            break;
        case 25 * ENEMY_SPAWN_TIME:
            four[8].resetHealth(level);
            five[4].resetHealth(level);
            one[2].resetHealth(level);
            ViewSetxy(four[8].getInstance(), 0, -94);
            ViewSetxy(five[4].getInstance(), 113, -94);
            ViewSetxy(one[2].getInstance(), 226, -94);
            break;
        case 26 * ENEMY_SPAWN_TIME:
            six[3].resetHealth(level);
            four[9].resetHealth(level);
            six[4].resetHealth(level);
            ViewSetxy(six[3].getInstance(), 0, -94);
            ViewSetxy(four[9].getInstance(), 113, -94);
            ViewSetxy(six[4].getInstance(), 226, -94);
            break;
        case 27 * ENEMY_SPAWN_TIME:
            four[0].resetHealth(level);
            five[0].resetHealth(level);
            ViewSetxy(four[0].getInstance(), 33, -94);
            ViewSetxy(five[0].getInstance(), 193, -94);
            break;
        case 28 * ENEMY_SPAWN_TIME:
            one[2].resetHealth(level);
            six[0].resetHealth(level);
            ViewSetxy(one[2].getInstance(), 33, -94);
            ViewSetxy(six[0].getInstance(), 193, -94);
            break;
        case 29 * ENEMY_SPAWN_TIME:
            five[1].resetHealth(level);
            three[1].resetHealth(level);
            ViewSetxy(five[1].getInstance(), 33, -94);
            ViewSetxy(three[1].getInstance(), 193, -94);
            break;
        case 30 * ENEMY_SPAWN_TIME:
            if (currentScreen != SCREEN_STORY_BATTLE_2) {
                nine.resetHealth(level);
                ViewSetxy(nine.getInstance(), 89, -240);
            }
            break;
        case 31 * ENEMY_SPAWN_TIME:
            if (currentScreen == SCREEN_STORY_BATTLE_2) {
                currentScreen = SCREEN_STORY_3A1;
                screenSwitch();
            }
            break;
    }
}

void setThree() {
    switch (counter.shipMove) {
        case 1 * ENEMY_SPAWN_TIME:
            six[0].resetHealth(level);
            two[0].resetHealth(level);
            ViewSetxy(six[0].getInstance(), 33, -94);
            ViewSetxy(two[0].getInstance(), 193, -94);
            break;
        case 2 * ENEMY_SPAWN_TIME:
            three[0].resetHealth(level);
            five[0].resetHealth(level);
            ViewSetxy(three[0].getInstance(), 33, -94);
            ViewSetxy(five[0].getInstance(), 193, -94);
            break;
        case 3 * ENEMY_SPAWN_TIME:
            one[0].resetHealth(level);
            four[0].resetHealth(level);
            four[1].resetHealth(level);
            ViewSetxy(one[0].getInstance(), 0, -94);
            ViewSetxy(four[0].getInstance(), 113, -94);
            ViewSetxy(four[1].getInstance(), 226, -94);
            break;
        case 4 * ENEMY_SPAWN_TIME:
            one[1].resetHealth(level);
            three[1].resetHealth(level);
            four[2].resetHealth(level);
            ViewSetxy(one[1].getInstance(), 0, -94);
            ViewSetxy(three[1].getInstance(), 113, -94);
            ViewSetxy(four[2].getInstance(), 226, -94);
            break;
        case 5 * ENEMY_SPAWN_TIME:
            six[1].resetHealth(level);
            ViewSetxy(six[1].getInstance(), 113, -94);
            break;
        case 6 * ENEMY_SPAWN_TIME:
            three[2].resetHealth(level);
            one[2].resetHealth(level);
            ViewSetxy(three[2].getInstance(), 33, -94);
            ViewSetxy(one[2].getInstance(), 193, -94);
            break;
        case 7 * ENEMY_SPAWN_TIME:
            two[1].resetHealth(level);
            five[1].resetHealth(level);
            ViewSetxy(two[1].getInstance(), 33, -94);
            ViewSetxy(five[1].getInstance(), 193, -94);
            break;
        case 8 * ENEMY_SPAWN_TIME:
            six[2].resetHealth(level);
            two[2].resetHealth(level);
            five[2].resetHealth(level);
            ViewSetxy(six[2].getInstance(), 0, -94);
            ViewSetxy(two[2].getInstance(), 113, -94);
            ViewSetxy(five[2].getInstance(), 226, -94);
            break;
        case 9 * ENEMY_SPAWN_TIME:
            one[3].resetHealth(level);
            four[3].resetHealth(level);
            two[3].resetHealth(level);
            ViewSetxy(one[3].getInstance(), 0, -94);
            ViewSetxy(four[3].getInstance(), 113, -94);
            ViewSetxy(two[3].getInstance(), 226, -94);
            break;
        case 10 * ENEMY_SPAWN_TIME:
            three[3].resetHealth(level);
            one[4].resetHealth(level);
            five[3].resetHealth(level);
            ViewSetxy(three[3].getInstance(), 0, -94);
            ViewSetxy(one[4].getInstance(), 113, -94);
            ViewSetxy(five[3].getInstance(), 226, -94);
            break;
        case 11 * ENEMY_SPAWN_TIME:
            five[4].resetHealth(level);
            two[4].resetHealth(level);
            four[4].resetHealth(level);
            ViewSetxy(five[4].getInstance(), 0, -94);
            ViewSetxy(two[4].getInstance(), 113, -94);
            ViewSetxy(four[4].getInstance(), 226, -94);
            break;
        case 12 * ENEMY_SPAWN_TIME:
            six[3].resetHealth(level);
            three[4].resetHealth(level);
            ViewSetxy(six[3].getInstance(), 33, -94);
            ViewSetxy(three[4].getInstance(), 193, -94);
            break;
        case 13 * ENEMY_SPAWN_TIME:
            one[5].resetHealth(level);
            three[5].resetHealth(level);
            ViewSetxy(one[5].getInstance(), 33, -94);
            ViewSetxy(three[5].getInstance(), 193, -94);
            break;
        case 14 * ENEMY_SPAWN_TIME:
            five[0].resetHealth(level);
            six[4].resetHealth(level);
            five[1].resetHealth(level);
            ViewSetxy(five[0].getInstance(), 0, -94);
            ViewSetxy(six[4].getInstance(), 113, -94);
            ViewSetxy(five[1].getInstance(), 226, -94);
            break;
        case 15 * ENEMY_SPAWN_TIME:
            three[6].resetHealth(level);
            four[5].resetHealth(level);
            two[5].resetHealth(level);
            ViewSetxy(three[6].getInstance(), 0, -94);
            ViewSetxy(four[5].getInstance(), 113, -94);
            ViewSetxy(two[5].getInstance(), 226, -94);
            break;
        case 16 * ENEMY_SPAWN_TIME:
            six[0].resetHealth(level);
            four[6].resetHealth(level);
            six[1].resetHealth(level);
            ViewSetxy(six[0].getInstance(), 0, -94);
            ViewSetxy(four[6].getInstance(), 113, -94);
            ViewSetxy(six[1].getInstance(), 226, -94);
            break;
        case 17 * ENEMY_SPAWN_TIME:
            seven[0].resetHealth(level);
            ViewSetxy(seven[0].getInstance(), 113, -94);
            break;
        case 18 * ENEMY_SPAWN_TIME:
            seven[1].resetHealth(level);
            seven[2].resetHealth(level);
            ViewSetxy(seven[1].getInstance(), 33, -94);
            ViewSetxy(seven[2].getInstance(), 193, -94);
            break;
        case 19 * ENEMY_SPAWN_TIME:
            five[2].resetHealth(level);
            seven[3].resetHealth(level);
            four[7].resetHealth(level);
            ViewSetxy(five[2].getInstance(), 0, -94);
            ViewSetxy(seven[3].getInstance(), 113, -94);
            ViewSetxy(four[7].getInstance(), 226, -94);
            break;
        case 20 * ENEMY_SPAWN_TIME:
            three[7].resetHealth(level);
            five[3].resetHealth(level);
            two[6].resetHealth(level);
            ViewSetxy(three[7].getInstance(), 0, -94);
            ViewSetxy(five[3].getInstance(), 113, -94);
            ViewSetxy(two[6].getInstance(), 226, -94);
            break;
        case 21 * ENEMY_SPAWN_TIME:
            five[4].resetHealth(level);
            seven[4].resetHealth(level);
            four[8].resetHealth(level);
            ViewSetxy(five[4].getInstance(), 0, -94);
            ViewSetxy(seven[4].getInstance(), 113, -94);
            ViewSetxy(four[8].getInstance(), 226, -94);
            break;
        case 22 * ENEMY_SPAWN_TIME:
            six[3].resetHealth(level);
            one[6].resetHealth(level);
            three[8].resetHealth(level);
            ViewSetxy(six[3].getInstance(), 0, -94);
            ViewSetxy(one[6].getInstance(), 113, -94);
            ViewSetxy(three[8].getInstance(), 226, -94);
            break;
        case 23 * ENEMY_SPAWN_TIME:
            three[9].resetHealth(level);
            four[9].resetHealth(level);
            ViewSetxy(three[9].getInstance(), 33, -94);
            ViewSetxy(four[9].getInstance(), 193, -94);
            break;
        case 24 * ENEMY_SPAWN_TIME:
            seven[0].resetHealth(level);
            six[4].resetHealth(level);
            ViewSetxy(seven[0].getInstance(), 33, -94);
            ViewSetxy(six[4].getInstance(), 193, -94);
            break;
        case 25 * ENEMY_SPAWN_TIME:
            six[0].resetHealth(level);
            ViewSetxy(six[0].getInstance(), 113, -94);
            break;
        case 26 * ENEMY_SPAWN_TIME:
            two[7].resetHealth(level);
            one[7].resetHealth(level);
            ViewSetxy(two[7].getInstance(), 33, -94);
            ViewSetxy(one[7].getInstance(), 193, -94);
            break;
        case 27 * ENEMY_SPAWN_TIME:
            six[1].resetHealth(level);
            seven[1].resetHealth(level);
            ViewSetxy(six[1].getInstance(), 33, -94);
            ViewSetxy(seven[1].getInstance(), 193, -94);
            break;
        case 28 * ENEMY_SPAWN_TIME:
            three[1].resetHealth(level);
            one[8].resetHealth(level);
            two[8].resetHealth(level);
            ViewSetxy(three[1].getInstance(), 0, -94);
            ViewSetxy(one[8].getInstance(), 113, -94);
            ViewSetxy(two[8].getInstance(), 226, -94);
            break;
        case 29 * ENEMY_SPAWN_TIME:
            five[0].resetHealth(level);
            seven[2].resetHealth(level);
            ViewSetxy(five[0].getInstance(), 33, -94);
            ViewSetxy(seven[2].getInstance(), 193, -94);
            break;
        case 30 * ENEMY_SPAWN_TIME:
            nine.resetHealth(level);
            ViewSetxy(nine.getInstance(), 89, -240);
            break;
    }
}

void setFour() {
    switch (counter.shipMove) {
        case 1 * ENEMY_SPAWN_TIME:
            one[0].resetHealth(level);
            two[0].resetHealth(level);
            ViewSetxy(one[0].getInstance(), 33, -94);
            ViewSetxy(two[0].getInstance(), 193, -94);
            break;
        case 2 * ENEMY_SPAWN_TIME:
            six[0].resetHealth(level);
            three[0].resetHealth(level);
            ViewSetxy(six[0].getInstance(), 33, -94);
            ViewSetxy(three[0].getInstance(), 193, -94);
            break;
        case 3 * ENEMY_SPAWN_TIME:
            four[0].resetHealth(level);
            five[0].resetHealth(level);
            four[1].resetHealth(level);
            ViewSetxy(four[0].getInstance(), 0, -94);
            ViewSetxy(five[0].getInstance(), 113, -94);
            ViewSetxy(four[1].getInstance(), 226, -94);
            break;
        case 4 * ENEMY_SPAWN_TIME:
            one[1].resetHealth(level);
            seven[0].resetHealth(level);
            two[1].resetHealth(level);
            ViewSetxy(one[1].getInstance(), 0, -94);
            ViewSetxy(seven[0].getInstance(), 113, -94);
            ViewSetxy(two[1].getInstance(), 226, -94);
            break;
        case 5 * ENEMY_SPAWN_TIME:
            five[1].resetHealth(level);
            three[1].resetHealth(level);
            four[2].resetHealth(level);
            ViewSetxy(five[1].getInstance(), 0, -94);
            ViewSetxy(three[1].getInstance(), 113, -94);
            ViewSetxy(four[2].getInstance(), 226, -94);
            break;
        case 6 * ENEMY_SPAWN_TIME:
            six[1].resetHealth(level);
            seven[1].resetHealth(level);
            ViewSetxy(six[1].getInstance(), 33, -94);
            ViewSetxy(seven[1].getInstance(), 193, -94);
            break;
        case 7 * ENEMY_SPAWN_TIME:
            six[2].resetHealth(level);
            ViewSetxy(six[2].getInstance(), 113, -94);
            break;
        case 8 * ENEMY_SPAWN_TIME:
            seven[2].resetHealth(level);
            ViewSetxy(seven[2].getInstance(), 113, -94);
            break;
        case 9 * ENEMY_SPAWN_TIME:
            two[2].resetHealth(level);
            one[2].resetHealth(level);
            ViewSetxy(two[2].getInstance(), 33, -94);
            ViewSetxy(one[2].getInstance(), 193, -94);
            break;
        case 10 * ENEMY_SPAWN_TIME:
            three[2].resetHealth(level);
            five[2].resetHealth(level);
            ViewSetxy(three[2].getInstance(), 33, -94);
            ViewSetxy(five[2].getInstance(), 193, -94);
            break;
        case 11 * ENEMY_SPAWN_TIME:
            six[3].resetHealth(level);
            one[3].resetHealth(level);
            seven[3].resetHealth(level);
            ViewSetxy(six[3].getInstance(), 0, -94);
            ViewSetxy(one[3].getInstance(), 113, -94);
            ViewSetxy(seven[3].getInstance(), 226, -94);
            break;
        case 12 * ENEMY_SPAWN_TIME:
            four[3].resetHealth(level);
            seven[4].resetHealth(level);
            three[3].resetHealth(level);
            ViewSetxy(four[3].getInstance(), 0, -94);
            ViewSetxy(seven[4].getInstance(), 113, -94);
            ViewSetxy(three[3].getInstance(), 226, -94);
            break;
        case 13 * ENEMY_SPAWN_TIME:
            one[4].resetHealth(level);
            six[4].resetHealth(level);
            two[3].resetHealth(level);
            ViewSetxy(one[4].getInstance(), 0, -94);
            ViewSetxy(six[4].getInstance(), 113, -94);
            ViewSetxy(two[3].getInstance(), 226, -94);
            break;
        case 14 * ENEMY_SPAWN_TIME:
            seven[0].resetHealth(level);
            ViewSetxy(seven[0].getInstance(), 113, -94);
            break;
        case 15 * ENEMY_SPAWN_TIME:
            four[4].resetHealth(level);
            three[4].resetHealth(level);
            ViewSetxy(four[4].getInstance(), 33, -94);
            ViewSetxy(three[4].getInstance(), 193, -94);
            break;
        case 16 * ENEMY_SPAWN_TIME:
            one[5].resetHealth(level);
            two[4].resetHealth(level);
            ViewSetxy(one[5].getInstance(), 33, -94);
            ViewSetxy(two[4].getInstance(), 193, -94);
            break;
        case 17 * ENEMY_SPAWN_TIME:
            five[3].resetHealth(level);
            six[0].resetHealth(level);
            five[4].resetHealth(level);
            ViewSetxy(five[3].getInstance(), 0, -94);
            ViewSetxy(six[0].getInstance(), 113, -94);
            ViewSetxy(five[4].getInstance(), 226, -94);
            break;
        case 18 * ENEMY_SPAWN_TIME:
            six[1].resetHealth(level);
            seven[1].resetHealth(level);
            three[5].resetHealth(level);
            ViewSetxy(six[1].getInstance(), 0, -94);
            ViewSetxy(seven[1].getInstance(), 113, -94);
            ViewSetxy(three[5].getInstance(), 226, -94);
            break;
        case 19 * ENEMY_SPAWN_TIME:
            one[6].resetHealth(level);
            five[0].resetHealth(level);
            two[5].resetHealth(level);
            ViewSetxy(one[6].getInstance(), 0, -94);
            ViewSetxy(five[0].getInstance(), 113, -94);
            ViewSetxy(two[5].getInstance(), 226, -94);
            break;
        case 20 * ENEMY_SPAWN_TIME:
            seven[2].resetHealth(level);
            four[5].resetHealth(level);
            five[1].resetHealth(level);
            ViewSetxy(seven[2].getInstance(), 0, -94);
            ViewSetxy(four[5].getInstance(), 113, -94);
            ViewSetxy(five[1].getInstance(), 226, -94);
            break;
        case 21 * ENEMY_SPAWN_TIME:
            eight[0].resetHealth(level);
            ViewSetxy(eight[0].getInstance(), 113, -94);
            break;
        case 22 * ENEMY_SPAWN_TIME:
            seven[3].resetHealth(level);
            eight[1].resetHealth(level);
            ViewSetxy(seven[3].getInstance(), 33, -94);
            ViewSetxy(eight[1].getInstance(), 193, -94);
            break;
        case 23 * ENEMY_SPAWN_TIME:
            one[7].resetHealth(level);
            two[6].resetHealth(level);
            ViewSetxy(one[7].getInstance(), 33, -94);
            ViewSetxy(two[6].getInstance(), 193, -94);
            break;
        case 24 * ENEMY_SPAWN_TIME:
            four[6].resetHealth(level);
            three[6].resetHealth(level);
            ViewSetxy(four[6].getInstance(), 33, -94);
            ViewSetxy(three[6].getInstance(), 193, -94);
            break;
        case 25 * ENEMY_SPAWN_TIME:
            seven[4].resetHealth(level);
            eight[2].resetHealth(level);
            four[7].resetHealth(level);
            ViewSetxy(seven[4].getInstance(), 0, -94);
            ViewSetxy(eight[2].getInstance(), 113, -94);
            ViewSetxy(four[7].getInstance(), 226, -94);
            break;
        case 26 * ENEMY_SPAWN_TIME:
            six[2].resetHealth(level);
            two[7].resetHealth(level);
            six[3].resetHealth(level);
            ViewSetxy(six[2].getInstance(), 0, -94);
            ViewSetxy(two[7].getInstance(), 113, -94);
            ViewSetxy(six[3].getInstance(), 226, -94);
            break;
        case 27 * ENEMY_SPAWN_TIME:
            one[8].resetHealth(level);
            five[2].resetHealth(level);
            one[9].resetHealth(level);
            ViewSetxy(one[8].getInstance(), 0, -94);
            ViewSetxy(five[2].getInstance(), 113, -94);
            ViewSetxy(one[9].getInstance(), 226, -94);
            break;
        case 28 * ENEMY_SPAWN_TIME:
            eight[3].resetHealth(level);
            three[7].resetHealth(level);
            eight[4].resetHealth(level);
            ViewSetxy(eight[3].getInstance(), 0, -94);
            ViewSetxy(three[7].getInstance(), 113, -94);
            ViewSetxy(eight[4].getInstance(), 226, -94);
            break;
        case 29 * ENEMY_SPAWN_TIME:
            five[3].resetHealth(level);
            two[8].resetHealth(level);
            ViewSetxy(five[3].getInstance(), 33, -94);
            ViewSetxy(two[8].getInstance(), 193, -94);
            break;
        case 30 * ENEMY_SPAWN_TIME:
            if (currentScreen != SCREEN_STORY_BATTLE_5) {
                nine.resetHealth(level);
                ViewSetxy(nine.getInstance(), 89, -240);
            }
            break;
        case 31 * ENEMY_SPAWN_TIME:
            if (currentScreen == SCREEN_STORY_BATTLE_5) {
                currentScreen = SCREEN_STORY_6A1;
                screenSwitch();
            }
            break;
    }
}

void setFive() {
    switch (counter.shipMove) {
        case 1 * ENEMY_SPAWN_TIME:
            six[0].resetHealth(level);
            ViewSetxy(six[0].getInstance(), 113, -94);
            break;
        case 2 * ENEMY_SPAWN_TIME:
            seven[0].resetHealth(level);
            two[0].resetHealth(level);
            ViewSetxy(seven[0].getInstance(), 33, -94);
            ViewSetxy(two[0].getInstance(), 193, -94);
            break;
        case 3 * ENEMY_SPAWN_TIME:
            one[0].resetHealth(level);
            eight[0].resetHealth(level);
            ViewSetxy(one[0].getInstance(), 33, -94);
            ViewSetxy(eight[0].getInstance(), 193, -94);
            break;
        case 4 * ENEMY_SPAWN_TIME:
            five[0].resetHealth(level);
            six[1].resetHealth(level);
            four[0].resetHealth(level);
            ViewSetxy(five[0].getInstance(), 0, -94);
            ViewSetxy(six[1].getInstance(), 113, -94);
            ViewSetxy(four[0].getInstance(), 226, -94);
            break;
        case 5 * ENEMY_SPAWN_TIME:
            three[0].resetHealth(level);
            one[1].resetHealth(level);
            seven[1].resetHealth(level);
            ViewSetxy(three[0].getInstance(), 0, -94);
            ViewSetxy(one[1].getInstance(), 113, -94);
            ViewSetxy(seven[1].getInstance(), 226, -94);
            break;
        case 6 * ENEMY_SPAWN_TIME:
            seven[2].resetHealth(level);
            eight[1].resetHealth(level);
            six[2].resetHealth(level);
            ViewSetxy(seven[2].getInstance(), 0, -94);
            ViewSetxy(eight[1].getInstance(), 113, -94);
            ViewSetxy(six[2].getInstance(), 226, -94);
            break;
        case 7 * ENEMY_SPAWN_TIME:
            three[1].resetHealth(level);
            one[2].resetHealth(level);
            four[1].resetHealth(level);
            ViewSetxy(three[1].getInstance(), 0, -94);
            ViewSetxy(one[2].getInstance(), 113, -94);
            ViewSetxy(four[1].getInstance(), 226, -94);
            break;
        case 8 * ENEMY_SPAWN_TIME:
            two[1].resetHealth(level);
            seven[3].resetHealth(level);
            ViewSetxy(two[1].getInstance(), 33, -94);
            ViewSetxy(seven[3].getInstance(), 193, -94);
            break;
        case 9 * ENEMY_SPAWN_TIME:
            six[3].resetHealth(level);
            three[2].resetHealth(level);
            ViewSetxy(six[3].getInstance(), 33, -94);
            ViewSetxy(three[2].getInstance(), 193, -94);
            break;
        case 10 * ENEMY_SPAWN_TIME:
            six[4].resetHealth(level);
            ViewSetxy(six[4].getInstance(), 113, -94);
            break;
        case 11 * ENEMY_SPAWN_TIME:
            eight[2].resetHealth(level);
            ViewSetxy(eight[2].getInstance(), 113, -94);
            break;
        case 12 * ENEMY_SPAWN_TIME:
            five[1].resetHealth(level);
            one[3].resetHealth(level);
            six[0].resetHealth(level);
            ViewSetxy(five[1].getInstance(), 0, -94);
            ViewSetxy(one[3].getInstance(), 113, -94);
            ViewSetxy(six[0].getInstance(), 226, -94);
            break;
        case 13 * ENEMY_SPAWN_TIME:
            four[2].resetHealth(level);
            three[3].resetHealth(level);
            five[2].resetHealth(level);
            ViewSetxy(four[2].getInstance(), 0, -94);
            ViewSetxy(three[3].getInstance(), 113, -94);
            ViewSetxy(five[2].getInstance(), 226, -94);
            break;
        case 14 * ENEMY_SPAWN_TIME:
            two[2].resetHealth(level);
            six[1].resetHealth(level);
            three[4].resetHealth(level);
            ViewSetxy(two[2].getInstance(), 0, -94);
            ViewSetxy(six[1].getInstance(), 113, -94);
            ViewSetxy(three[4].getInstance(), 226, -94);
            break;
        case 15 * ENEMY_SPAWN_TIME:
            eight[3].resetHealth(level);
            four[3].resetHealth(level);
            ViewSetxy(eight[3].getInstance(), 33, -94);
            ViewSetxy(four[3].getInstance(), 193, -94);
            break;
        case 16 * ENEMY_SPAWN_TIME:
            three[5].resetHealth(level);
            six[2].resetHealth(level);
            ViewSetxy(three[5].getInstance(), 33, -94);
            ViewSetxy(six[2].getInstance(), 193, -94);
            break;
        case 17 * ENEMY_SPAWN_TIME:
            eight[4].resetHealth(level);
            five[3].resetHealth(level);
            six[3].resetHealth(level);
            ViewSetxy(eight[4].getInstance(), 0, -94);
            ViewSetxy(five[3].getInstance(), 113, -94);
            ViewSetxy(six[3].getInstance(), 226, -94);
            break;
        case 18 * ENEMY_SPAWN_TIME:
            seven[4].resetHealth(level);
            ViewSetxy(seven[4].getInstance(), 113, -94);
            break;
        case 19 * ENEMY_SPAWN_TIME:
            eight[0].resetHealth(level);
            ViewSetxy(eight[0].getInstance(), 113, -94);
            break;
        case 20 * ENEMY_SPAWN_TIME:
            five[4].resetHealth(level);
            six[4].resetHealth(level);
            ViewSetxy(five[4].getInstance(), 33, -94);
            ViewSetxy(six[4].getInstance(), 193, -94);
            break;
        case 21 * ENEMY_SPAWN_TIME:
            eight[1].resetHealth(level);
            six[0].resetHealth(level);
            seven[0].resetHealth(level);
            ViewSetxy(eight[1].getInstance(), 0, -94);
            ViewSetxy(six[0].getInstance(), 113, -94);
            ViewSetxy(seven[0].getInstance(), 226, -94);
            break;
        case 22 * ENEMY_SPAWN_TIME:
            two[3].resetHealth(level);
            four[4].resetHealth(level);
            three[6].resetHealth(level);
            ViewSetxy(two[3].getInstance(), 0, -94);
            ViewSetxy(four[4].getInstance(), 113, -94);
            ViewSetxy(three[6].getInstance(), 226, -94);
            break;
        case 23 * ENEMY_SPAWN_TIME:
            six[1].resetHealth(level);
            two[4].resetHealth(level);
            five[0].resetHealth(level);
            ViewSetxy(six[1].getInstance(), 0, -94);
            ViewSetxy(two[4].getInstance(), 113, -94);
            ViewSetxy(five[0].getInstance(), 226, -94);
            break;
        case 24 * ENEMY_SPAWN_TIME:
            eight[2].resetHealth(level);
            seven[1].resetHealth(level);
            six[2].resetHealth(level);
            ViewSetxy(eight[2].getInstance(), 0, -94);
            ViewSetxy(seven[1].getInstance(), 113, -94);
            ViewSetxy(six[2].getInstance(), 226, -94);
            break;
        case 25 * ENEMY_SPAWN_TIME:
            two[5].resetHealth(level);
            seven[2].resetHealth(level);
            three[7].resetHealth(level);
            ViewSetxy(two[5].getInstance(), 0, -94);
            ViewSetxy(seven[2].getInstance(), 113, -94);
            ViewSetxy(three[7].getInstance(), 226, -94);
            break;
        case 26 * ENEMY_SPAWN_TIME:
            eight[3].resetHealth(level);
            one[4].resetHealth(level);
            ViewSetxy(eight[3].getInstance(), 33, -94);
            ViewSetxy(one[4].getInstance(), 193, -94);
            break;
        case 27 * ENEMY_SPAWN_TIME:
            two[6].resetHealth(level);
            five[1].resetHealth(level);
            three[8].resetHealth(level);
            ViewSetxy(two[6].getInstance(), 0, -94);
            ViewSetxy(five[1].getInstance(), 113, -94);
            ViewSetxy(three[8].getInstance(), 226, -94);
            break;
        case 28 * ENEMY_SPAWN_TIME:
            seven[3].resetHealth(level);
            five[2].resetHealth(level);
            six[3].resetHealth(level);
            ViewSetxy(seven[3].getInstance(), 0, -94);
            ViewSetxy(five[2].getInstance(), 113, -94);
            ViewSetxy(six[3].getInstance(), 226, -94);
            break;
        case 29 * ENEMY_SPAWN_TIME:
            six[3].resetHealth(level);
            eight[4].resetHealth(level);
            ViewSetxy(six[3].getInstance(), 33, -94);
            ViewSetxy(eight[4].getInstance(), 193, -94);
            break;
        case 30 * ENEMY_SPAWN_TIME:
            ten.resetHealth(level);
            ViewSetxy(ten.getInstance(), 85, -240);
            break;
    }
}
