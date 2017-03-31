/*
 * Provides functionality for setting which screen is visible. Also provides functionality for changing the ship, and
 * the attributes that belong to the respective ship.
 */

#include "DragonFireSDK.h"
#include "Globals.h"
#include "StateToggle.h"
#include "CustomMath.h"

void reset() {
    counter.bulletTime = 0;
    counter.shipMove = 0;
    player.currentXCoord = 113;
    player.currentYCoord = 380;
    player.newXCoord = 113;
    player.newYCoord = 380;
    for (int i = 0; i < PLAYER_BULLETS_PER_BULLET_TYPE; i++) {
        ViewSetxy(player.bulletOne[i], -10, -10);
        ViewSetxy(player.rocket[i], -20, -20);
        ViewSetxy(player.bulletTwo[i], -10, -10);
    }
    for (int i = 0; i < ENEMY_BULLETS_PER_BULLET_TYPE; i++) {
        for (int j = 0; j < AMOUNT_OF_SHIPS_TYPE_1_TO_4; j++) {
            one[j].setBullet(i, 600, 600);
            two[j].setBullet(i, 600, 600);
            three[j].setBullet(i, 600, 600);
            four[j].setBullet(i, 600, 600);
        }
        for (int j = 0; j < AMOUNT_OF_SHIPS_TYPE_5_TO_8; j++) {
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
    for (int i = 0; i < AMOUNT_OF_SHIPS_TYPE_1_TO_4; i++) {
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
    for (int i = 0; i < AMOUNT_OF_SHIPS_TYPE_5_TO_8; i++) {
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
    player.health = player.possibleHealth;
    isHealthUpdate = true;
    isPaused = false;
}

void screenSwitch() {
    ContainerSetVisible(container.pause, 0);
    ContainerSetVisible(container.menu, 0);
    ContainerSetVisible(container.endless, 0);
    ContainerSetVisible(container.highscore, 0);
    ContainerSetVisible(container.died, 0);
    ContainerSetVisible(container.story1a1, 0);
    ContainerSetVisible(container.story1a2, 0);
    ContainerSetVisible(container.story1s3, 0);
    ContainerSetVisible(container.story1p3, 0);
    ContainerSetVisible(container.story1a4, 0);
    ContainerSetVisible(container.story1r5, 0);
    ContainerSetVisible(container.story1e5, 0);
    ContainerSetVisible(container.story2a1, 0);
    ContainerSetVisible(container.story2a2, 0);
    ContainerSetVisible(container.story2a3, 0);
    ContainerSetVisible(container.story2b4, 0);
    ContainerSetVisible(container.story2a5, 0);
    ContainerSetVisible(container.story2a6, 0);
    ContainerSetVisible(container.story2e7, 0);
    ContainerSetVisible(container.story2a7, 0);
    ContainerSetVisible(container.story3a1, 0);
    ContainerSetVisible(container.story3b2, 0);
    ContainerSetVisible(container.story3a3, 0);
    ContainerSetVisible(container.story3a4, 0);
    ContainerSetVisible(container.story3a5, 0);
    ContainerSetVisible(container.story3a6, 0);
    ContainerSetVisible(container.story3a7, 0);
    ContainerSetVisible(container.story3a8, 0);
    ContainerSetVisible(container.storyTorture, 0);
    ContainerSetVisible(container.story4a1, 0);
    ContainerSetVisible(container.story4a2, 0);
    ContainerSetVisible(container.story4a3, 0);
    ContainerSetVisible(container.story4a4, 0);
    ContainerSetVisible(container.story4b5, 0);
    ContainerSetVisible(container.story4a6, 0);
    ContainerSetVisible(container.story4a7, 0);
    ContainerSetVisible(container.story4b7, 0);
    ContainerSetVisible(container.story4a8, 0);
    ContainerSetVisible(container.story5a1, 0);
    ContainerSetVisible(container.story5a2, 0);
    ContainerSetVisible(container.story5a3, 0);
    ContainerSetVisible(container.story5b4, 0);
    ContainerSetVisible(container.story5a5, 0);
    ContainerSetVisible(container.story5a6, 0);
    ContainerSetVisible(container.story5b6, 0);
    ContainerSetVisible(container.story6a1, 0);
    ContainerSetVisible(container.story6a2, 0);
    ContainerSetVisible(container.story6a3, 0);
    ContainerSetVisible(container.story6b3, 0);
    ContainerSetVisible(container.story7w1, 0);
    ContainerSetVisible(container.story7l1, 0);
    ContainerSetVisible(container.story7a2, 0);
    ContainerSetVisible(container.story7b2, 0);
    ContainerSetVisible(container.unlocks, 0);
    ContainerSetVisible(container.options, 0);
    ContainerSetVisible(container.deleteCheckOne, 0);
    ContainerSetVisible(container.deleteCheckTwo, 0);
    switch (currentScreen) {
        case SCREEN_PAUSE:
            ContainerSetVisible(container.pause, 1);
            break;
        case SCREEN_MENU:
            ContainerSetVisible(container.menu, 1);
            break;
        case SCREEN_HIGHSCORE:
            ContainerSetVisible(container.highscore, 1);
            break;
        case SCREEN_DIED:
            ContainerSetVisible(container.died, 1);
            break;
        case SCREEN_ENDLESS:
            ContainerSetVisible(container.endless, 1);
            break;
        case SCREEN_STORY_1A1:
            ContainerSetVisible(container.story1a1, 1);
            break;
        case SCREEN_STORY_1A2:
            ContainerSetVisible(container.story1a2, 1);
            break;
        case SCREEN_STORY_1S3:
            ContainerSetVisible(container.story1s3, 1);
            break;
        case SCREEN_STORY_1P3:
            ContainerSetVisible(container.story1p3, 1);
            break;
        case SCREEN_STORY_1A4:
            ContainerSetVisible(container.story1a4, 1);
            break;
        case SCREEN_STORY_1R5:
            ContainerSetVisible(container.story1r5, 1);
            break;
        case SCREEN_STORY_1E5:
            ContainerSetVisible(container.story1e5, 1);
            break;
        case SCREEN_STORY_BATTLE_1:
            ContainerSetVisible(container.endless, 1);
            break;
        case SCREEN_STORY_2A1:
            ContainerSetVisible(container.story2a1, 1);
            break;
        case SCREEN_STORY_2A2:
            ContainerSetVisible(container.story2a2, 1);
            break;
        case SCREEN_STORY_2A3:
            ContainerSetVisible(container.story2a3, 1);
            break;
        case SCREEN_STORY_2B4:
            ContainerSetVisible(container.story2b4, 1);
            break;
        case SCREEN_STORY_2A5:
            ContainerSetVisible(container.story2a5, 1);
            break;
        case SCREEN_STORY_2A6:
            ContainerSetVisible(container.story2a6, 1);
            break;
        case SCREEN_STORY_2E7:
            ContainerSetVisible(container.story2e7, 1);
            break;
        case SCREEN_STORY_2A7:
            ContainerSetVisible(container.story2a7, 1);
            break;
        case SCREEN_STORY_BATTLE_2:
            ContainerSetVisible(container.endless, 1);
            break;
        case SCREEN_STORY_3A1:
            ContainerSetVisible(container.story3a1, 1);
            break;
        case SCREEN_STORY_3B2:
            ContainerSetVisible(container.story3b2, 1);
            break;
        case SCREEN_STORY_3A3:
            ContainerSetVisible(container.story3a3, 1);
            break;
        case SCREEN_STORY_3A4:
            ContainerSetVisible(container.story3a4, 1);
            break;
        case SCREEN_STORY_3A5:
            ContainerSetVisible(container.story3a5, 1);
            break;
        case SCREEN_STORY_3A6:
            ContainerSetVisible(container.story3a6, 1);
            break;
        case SCREEN_STORY_3A7:
            ContainerSetVisible(container.story3a7, 1);
            break;
        case SCREEN_STORY_3A8:
            ContainerSetVisible(container.story3a8, 1);
            break;
        case SCREEN_STORY_TORTURE:
            int imageTorturing;
            imageTorturing = ImageAdd("Images/20HP.png");
            ViewSetImage(hpTorture, imageTorturing);
            counter.hpTorture = 2000;
            counter.torture = 0;
            ContainerSetVisible(container.storyTorture, 1);
            break;
        case SCREEN_STORY_4A1:
            ContainerSetVisible(container.story4a1, 1);
            break;
        case SCREEN_STORY_4A2:
            ContainerSetVisible(container.story4a2, 1);
            break;
        case SCREEN_STORY_4A3:
            ContainerSetVisible(container.story4a3, 1);
            break;
        case SCREEN_STORY_4A4:
            ContainerSetVisible(container.story4a4, 1);
            break;
        case SCREEN_STORY_4B5:
            ContainerSetVisible(container.story4b5, 1);
            break;
        case SCREEN_STORY_4A6:
            ContainerSetVisible(container.story4a6, 1);
            break;
        case SCREEN_STORY_4A7:
            ContainerSetVisible(container.story4a7, 1);
            break;
        case SCREEN_STORY_4B7:
            ContainerSetVisible(container.story4b7, 1);
            break;
        case SCREEN_STORY_4A8:
            ContainerSetVisible(container.story4a8, 1);
            break;
        case SCREEN_STORY_BATTLE_4:
            ContainerSetVisible(container.endless, 1);
            break;
        case SCREEN_STORY_5A1:
            ContainerSetVisible(container.story5a1, 1);
            break;
        case SCREEN_STORY_5A2:
            ContainerSetVisible(container.story5a2, 1);
            break;
        case SCREEN_STORY_5A3:
            ContainerSetVisible(container.story5a3, 1);
            break;
        case SCREEN_STORY_5B4:
            ContainerSetVisible(container.story5b4, 1);
            break;
        case SCREEN_STORY_5A5:
            ContainerSetVisible(container.story5a5, 1);
            break;
        case SCREEN_STORY_5A6:
            ContainerSetVisible(container.story5a6, 1);
            break;
        case SCREEN_STORY_5B6:
            ContainerSetVisible(container.story5b6, 1);
            break;
        case SCREEN_STORY_BATTLE_5:
            ContainerSetVisible(container.endless, 1);
            break;
        case SCREEN_STORY_6A1:
            ContainerSetVisible(container.story6a1, 1);
            break;
        case SCREEN_STORY_6A2:
            ContainerSetVisible(container.story6a2, 1);
            break;
        case SCREEN_STORY_6A3:
            ContainerSetVisible(container.story6a3, 1);
            break;
        case SCREEN_STORY_6B3:
            ContainerSetVisible(container.story6b3, 1);
            break;
        case SCREEN_STORY_BATTLE_6:
            ContainerSetVisible(container.endless, 1);
            break;
        case SCREEN_STORY_7W1:
            ContainerSetVisible(container.story7w1, 1);
            break;
        case SCREEN_STORY_7L1:
            ContainerSetVisible(container.story7l1, 1);
            break;
        case SCREEN_STORY_7A2:
            ContainerSetVisible(container.story7a2, 1);
            break;
        case SCREEN_STORY_7B2:
            ContainerSetVisible(container.story7b2, 1);
            break;
        case SCREEN_UNLOCKS:
            ContainerSetVisible(container.unlocks, 1);
            break;
        case SCREEN_OPTIONS:
            ContainerSetVisible(container.options, 1);
            break;
        case SCREEN_DELETE_CHECK_ONE:
            ContainerSetVisible(container.deleteCheckOne, 1);
            break;
        case SCREEN_DELETE_CHECK_TWO:
            ContainerSetVisible(container.deleteCheckTwo, 1);
            break;
    }
}

void shipType() {
    const int LIFT = 10;
    ViewSetxy(player.instance, -200, -200);
    player.possibleHealth = round((18 + 2 * player.typeOfShip) * PLAYER_HEALTH_RATIO / 10);
    switch (player.typeOfShip) {
        case 1:
            player.instance = ViewAdd(container.endless, "Images/Ship_1.png", -200, -200);
            player.bulletOneOffsetXCoord = 43;
            player.bulletOneOffsetYCoord = 11 - LIFT;
            player.speed = round(7 * PLAYER_FLY_SPEED_RATIO / 10);
            player.widthOne = 9;
            player.widthTwo = 76;
            break;
        case 2:
            player.instance = ViewAdd(container.endless, "Images/Ship_2.png", -200, -200);
            player.bulletOneOffsetXCoord = 43;
            player.bulletOneOffsetYCoord = 0 - LIFT;
            player.speed = round(7 * PLAYER_FLY_SPEED_RATIO / 10);
            player.widthOne = 15;
            player.widthTwo = 69;
            break;
        case 3:
            player.instance = ViewAdd(container.endless, "Images/Ship_3.png", -200, -200);
            player.bulletOneOffsetXCoord = 43;
            player.bulletOneOffsetYCoord = 6 - LIFT;
            player.speed = round(7 * PLAYER_FLY_SPEED_RATIO / 10);
            player.widthOne = 18;
            player.widthTwo = 66;
            break;
        case 4:
            player.instance = ViewAdd(container.endless, "Images/Ship_4.png", -200, -200);
            player.bulletOneOffsetXCoord = 43;
            player.bulletOneOffsetYCoord = 0 - LIFT;
            player.speed = round(7 * PLAYER_FLY_SPEED_RATIO / 10);
            player.widthOne = -3;
            player.widthTwo = 87;
            break;
        case 5:
            player.instance = ViewAdd(container.endless, "Images/Ship_5.png", -200, -200);
            player.bulletOneOffsetXCoord = 31;
            player.bulletOneOffsetYCoord = 23 - LIFT;
            player.bulletTwoOffsetXCoord = 54;
            player.bulletTwoOffsetYCoord = 23 - LIFT;
            player.speed = round(6 * PLAYER_FLY_SPEED_RATIO / 10);
            player.widthOne = 13;
            player.widthTwo = 71;
            break;
        case 6:
            player.instance = ViewAdd(container.endless, "Images/Ship_6.png", -200, -200);
            player.bulletOneOffsetXCoord = 15;
            player.bulletOneOffsetYCoord = 41 - LIFT;
            player.bulletTwoOffsetXCoord = 68;
            player.bulletTwoOffsetYCoord = 41 - LIFT;
            player.speed = round(6 * PLAYER_FLY_SPEED_RATIO / 10);
            player.widthOne = 3;
            player.widthTwo = 81;
            break;
        case 7:
            player.instance = ViewAdd(container.endless, "Images/Ship_7.png", -200, -200);
            player.rocketOffsetXCoord = 42;
            player.rocketOffsetYCoord = 11 - LIFT;
            player.speed = round(5 * PLAYER_FLY_SPEED_RATIO / 10);
            player.widthOne = -2;
            player.widthTwo = 86;
            break;
        case 8:
            player.instance = ViewAdd(container.endless, "Images/Ship_8.png", -200, -200);
            player.bulletOneOffsetXCoord = 12;
            player.bulletOneOffsetYCoord = 40 - LIFT;
            player.rocketOffsetXCoord = 42;
            player.rocketOffsetYCoord = 2 - LIFT;
            player.bulletTwoOffsetXCoord = 74;
            player.bulletTwoOffsetYCoord = 40 - LIFT;
            player.speed = round(4 * PLAYER_FLY_SPEED_RATIO / 10);
            player.widthOne = -3;
            player.widthTwo = 86;
            break;
    }
}
