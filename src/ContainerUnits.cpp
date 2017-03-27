#include "DragonFireSDK.h"
#include "Globals.h"
#include "ContainerUnits.h"
#include "UserEvent.h"
#include "UserStoryEvent.h"

void declareContainers() {
    container.pause = ContainerAdd(0, 0, 0);
    container.menu = ContainerAdd(0, 0, 0);
    container.highscore = ContainerAdd(0, 0, 0);
    container.endless = ContainerAdd(0, 0, 0);
    container.died = ContainerAdd(0, 0, 0);
    container.story1a1 = ContainerAdd(0, 0, 0);
    container.story1a2 = ContainerAdd(0, 0, 0);
    container.story1s3 = ContainerAdd(0, 0, 0);
    container.story1p3 = ContainerAdd(0, 0, 0);
    container.story1a4 = ContainerAdd(0, 0, 0);
    container.story1r5 = ContainerAdd(0, 0, 0);
    container.story1e5 = ContainerAdd(0, 0, 0);
    container.story2a1 = ContainerAdd(0, 0, 0);
    container.story2a2 = ContainerAdd(0, 0, 0);
    container.story2a3 = ContainerAdd(0, 0, 0);
    container.story2b4 = ContainerAdd(0, 0, 0);
    container.story2a5 = ContainerAdd(0, 0, 0);
    container.story2a6 = ContainerAdd(0, 0, 0);
    container.story2e7 = ContainerAdd(0, 0, 0);
    container.story2a7 = ContainerAdd(0, 0, 0);
    container.story3a1 = ContainerAdd(0, 0, 0);
    container.story3b2 = ContainerAdd(0, 0, 0);
    container.story3a3 = ContainerAdd(0, 0, 0);
    container.story3a4 = ContainerAdd(0, 0, 0);
    container.story3a5 = ContainerAdd(0, 0, 0);
    container.story3a6 = ContainerAdd(0, 0, 0);
    container.story3a7 = ContainerAdd(0, 0, 0);
    container.story3a8 = ContainerAdd(0, 0, 0);
    container.storyTorture = ContainerAdd(0, 0, 0);
    container.story4a1 = ContainerAdd(0, 0, 0);
    container.story4a2 = ContainerAdd(0, 0, 0);
    container.story4a3 = ContainerAdd(0, 0, 0);
    container.story4a4 = ContainerAdd(0, 0, 0);
    container.story4b5 = ContainerAdd(0, 0, 0);
    container.story4a6 = ContainerAdd(0, 0, 0);
    container.story4a7 = ContainerAdd(0, 0, 0);
    container.story4b7 = ContainerAdd(0, 0, 0);
    container.story4a8 = ContainerAdd(0, 0, 0);
    container.story5a1 = ContainerAdd(0, 0, 0);
    container.story5a2 = ContainerAdd(0, 0, 0);
    container.story5a3 = ContainerAdd(0, 0, 0);
    container.story5b4 = ContainerAdd(0, 0, 0);
    container.story5a5 = ContainerAdd(0, 0, 0);
    container.story5a6 = ContainerAdd(0, 0, 0);
    container.story5b6 = ContainerAdd(0, 0, 0);
    container.story6a1 = ContainerAdd(0, 0, 0);
    container.story6a2 = ContainerAdd(0, 0, 0);
    container.story6a3 = ContainerAdd(0, 0, 0);
    container.story6b3 = ContainerAdd(0, 0, 0);
    container.story7w1 = ContainerAdd(0, 0, 0);
    container.story7l1 = ContainerAdd(0, 0, 0);
    container.story7a2 = ContainerAdd(0, 0, 0);
    container.story7b2 = ContainerAdd(0, 0, 0);
    container.unlocks = ContainerAdd(0, 0, 0);
    container.options = ContainerAdd(0, 0, 0);
    container.deleteCheckOne = ContainerAdd(0, 0, 0);
    container.deleteCheckTwo = ContainerAdd(0, 0, 0);
}

void containerOne() {
    //populate container.highscore
    ViewAdd(container.highscore, "Images/MenuPause.png", 0, 0);
    ViewAdd(container.highscore, "Images/btnOkBig.png", 20, 380, onHighscore, 1);
    text1 = TextAdd(container.highscore, 20, 0, "", font);
    text2 = TextAdd(container.highscore, 20, 0, "", font);
    text3 = TextAdd(container.highscore, 20, 0, "", font);
    //populate container.pause
    ViewAdd(container.pause, "Images/MenuPause.png", 0, 0);
    ViewAdd(container.pause, "Images/ReturnToMenu.png", 20, 120, onReturnToMenu, 1);
    ViewAdd(container.pause, "Images/Resume.png", 20, 210, onResume, 1);
    //populate container.endless
    ViewAdd(container.endless, "Images/Background.png", 0, 0, onBattleTouch, 1);
    healthImage = ViewAdd(container.endless, "Images/20HP.png", 20, 20);
    ViewAdd(container.endless, "Images/Pause.png", 270, 20, onPause, 1);
    //player bullets
    for (int i = 0; i < 15; i++) {
        player.bulletOne[i] = ViewAdd(container.endless, "Images/Bullet.png", -10, -10);
        player.rocket[i] = ViewAdd(container.endless, "Images/Rocket.png", -20, -20);
        player.bulletTwo[i] = ViewAdd(container.endless, "Images/Bullet.png", -10, -10);
    }
    //enemy bullets
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            one[j].setBulletInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
            two[j].setBulletInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
            three[j].setBulletInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
            four[j].setBulletInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
        }
        for (int j = 0; j < 5; j++) {
            five[j].setBulletOneInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
            five[j].setBulletTwoInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
            six[j].setBulletOneInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
            six[j].setBulletTwoInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
            seven[j].setRocketInstance(i, ViewAdd(container.endless, "Images/eRocket.png", 600, 600));
            eight[j].setBulletOneInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
            eight[j].setRocketInstance(i, ViewAdd(container.endless, "Images/eRocket.png", 600, 600));
            eight[j].setBulletTwoInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
        }
        nine.setBulletOneInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
        nine.setRocketInstance(i, ViewAdd(container.endless, "Images/eRocket.png", 600, 600));
        nine.setBulletTwoInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
        ten.setBulletOneInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
        ten.setRocketInstance(i, ViewAdd(container.endless, "Images/eRocket.png", 600, 600));
        ten.setBulletTwoInstance(i, ViewAdd(container.endless, "Images/eBullet.png", 600, 600));
    }
    //ships
    for (int i = 0; i < 10; i++) {
        one[i].setInstance(ViewAdd(container.endless, "Images/eShip_1.png", 600, 600));
        two[i].setInstance(ViewAdd(container.endless, "Images/eShip_2.png", 600, 600));
        three[i].setInstance(ViewAdd(container.endless, "Images/eShip_3.png", 600, 600));
        four[i].setInstance(ViewAdd(container.endless, "Images/eShip_4.png", 600, 600));
    }
    for (int i = 0; i < 5; i++) {
        five[i].setInstance(ViewAdd(container.endless, "Images/eShip_5.png", 600, 600));
        six[i].setInstance(ViewAdd(container.endless, "Images/eShip_6.png", 600, 600));
        seven[i].setInstance(ViewAdd(container.endless, "Images/eShip_7.png", 600, 600));
        eight[i].setInstance(ViewAdd(container.endless, "Images/eShip_8.png", 600, 600));
    }
    nine.setInstance(ViewAdd(container.endless, "Images/eMini-Boss.png", 600, 600));
    ten.setInstance(ViewAdd(container.endless, "Images/eBoss.png", 600, 600));
    //populate container.menu
    ViewAdd(container.menu, "Images/Background.png", 0, 0);
    ViewAdd(container.menu, "Images/btnStory.png", 20, 40, onStoryMenuTouch, 1);
    ViewAdd(container.menu, "Images/btnEndless.png", 20, 150, onEndlessMenuTouch, 1);
    ViewAdd(container.menu, "Images/btnUnlocks.png", 20, 260, onUnlocksMenuTouch, 1);
    ViewAdd(container.menu, "Images/btnOptions.png", 20, 370, onOptionsMenuTouch, 1);
    //populate container.died
    ViewAdd(container.died, "Images/Background.png", 0, 0);
    ViewAdd(container.died, "Images/btnOkBig.png", 20, 380, onDied, 1);
    TextAdd(container.died, 0, 0, "\n\nYou died without completing \nyour journey or leaving \nyourself a legacy. "
        "You left no", font);
    TextAdd(container.died, 0, 0, "\n\n\n\n\nimprint on the world and \nnobody will ever remember \nyou.", font);
    //populate CointainerStory1a1
    ViewAdd(container.story1a1, "Images/Background.png", 0, 0);
    ViewAdd(container.story1a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story1a1, "Images/btnOkBig.png", 20, 380, onStoryLevelOne, 1);
    TextAdd(container.story1a1, 0, 0, "\n\nRon: \nAlex, are you ready for the \nbig test? Remember: We \nadopted the "
        "new cycle", font);
    TextAdd(container.story1a1, 0, 0, "\n\n\n\n\n\nsystem 93 cycles ago. If we \nstill used the old Earth \nmethod, "
        "it would currently be", font);
    TextAdd(container.story1a1, 0, 0, "\n\n\n\n\n\n\n\n\nyear 2433.", font);
    //populate container.story1a2
    ViewAdd(container.story1a2, "Images/Background.png", 0, 0);
    ViewAdd(container.story1a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story1a2, "Images/btnStudy.png", 20, 380, onStoryLevelOne, 3);
    ViewAdd(container.story1a2, "Images/btnParty.png", 170, 380, onStoryLevelOne, 4);
    TextAdd(container.story1a2, 0, 0, "\n\nRon: \nAlso, you can either \nstudy for the big test \ntomorrow, or go to "
        "a party", font);
    TextAdd(container.story1a2, 0, 0, "\n\n\n\n\n\nwith the cool guys and I. Just \ntell them Ron invited you.", font);
    //populate container.story1s3
    ViewAdd(container.story1s3, "Images/Background.png", 0, 0);
    ViewAdd(container.story1s3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story1s3, "Images/btnSleep.png", 20, 380, onStoryLevelOne, 5);
    TextAdd(container.story1s3, 0, 0, "\n\nBook: \nEverybody must listen to \nhigher command at all times. \nAlso, "
        "ship pilots must never", font);
    TextAdd(container.story1s3, 0, 0, "\n\n\n\n\n\nabandon their ship.", font);
    //populate container.story1p3
    ViewAdd(container.story1p3, "Images/Background.png", 0, 0);
    ViewAdd(container.story1p3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story1p3, "Images/btnSleep.png", 20, 380, onStoryLevelOne, 5);
    TextAdd(container.story1p3, 0, 0, "\n\nRon: \nHave a great night.", font);
    //populate container.story1a4
    ViewAdd(container.story1a4, "Images/Background.png", 0, 0);
    ViewAdd(container.story1a4, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story1a4, "Images/btnRescue.png", 20, 380, onStoryLevelOne, 6);
    ViewAdd(container.story1a4, "Images/btnEscape.png", 170, 380, onStoryLevelOne, 7);
    TextAdd(container.story1a4, 0, 0, "\n\nTeacher: \nThe Kobayashi ship is \ntrapped behind enemy \nlines. What do "
        "you do?", font);
    //populate container.story1r5
    ViewAdd(container.story1r5, "Images/Background.png", 0, 0);
    ViewAdd(container.story1r5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story1r5, "Images/btnOkBig.png", 20, 380, onStoryLevelOne, 8);
    TextAdd(container.story1r5, 0, 0, "\n\nLieutenant: \nThey ambushed us!", font);
    //populate container.story1e5
    ViewAdd(container.story1e5, "Images/Background.png", 0, 0);
    ViewAdd(container.story1e5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story1e5, "Images/btnOkBig.png", 20, 380, onStoryLevelOne, 8);
    TextAdd(container.story1e5, 0, 0, "\n\nLieutenant: \nThey followed us and are \nattacking!", font);
}

void containerTwo() {
    //populate container.story2a1
    ViewAdd(container.story2a1, "Images/Background.png", 0, 0);
    ViewAdd(container.story2a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story2a1, "Images/btnOkSmall.png", 20, 380, onStoryLevelTwo, 1);
    ViewAdd(container.story2a1, "Images/btnThanks.png", 170, 380, onStoryLevelTwo, 1);
    TextAdd(container.story2a1, 0, 0, "\n\nTeacher: \nThis test was designed to \ndetermine how well cadets \nwould "
        "respond to stressful", font);
    TextAdd(container.story2a1, 0, 0, "\n\n\n\n\n\nsituations. You passed and \nhave been deemed fit for \nduty.", 
        font);
    //populate container.story2a2
    ViewAdd(container.story2a2, "Images/Background.png", 0, 0);
    ViewAdd(container.story2a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story2a2, "Images/btnSure.png", 20, 380, onStoryLevelTwo, 3);
    ViewAdd(container.story2a2, "Images/btnNo.png", 170, 380, onStoryLevelTwo, 4);
    TextAdd(container.story2a2, 0, 0, "\n\nBecca: \nI heard you're the new soldier \nin town. Do you want to go \nout "
        "to town with me?", font);
    //populate container.story2a3
    ViewAdd(container.story2a3, "Images/Background.png", 0, 0);
    ViewAdd(container.story2a3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story2a3, "Images/btnYes.png", 20, 380, onStoryLevelTwo, 5);
    ViewAdd(container.story2a3, "Images/btnNo.png", 170, 380, onStoryLevelTwo, 6);
    TextAdd(container.story2a3, 0, 0, "\n\nCaptain: \nSon, you have a bright future. \nWould you like to join me on "
        "\nmy voyages?", font);
    //populate container.story2b4
    ViewAdd(container.story2b4, "Images/Background.png", 0, 0);
    ViewAdd(container.story2b4, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story2b4, "Images/btnOkSmall.png", 20, 380, onStoryLevelTwo, 7);
    ViewAdd(container.story2b4, "Images/btnSorry.png", 170, 380, onStoryLevelTwo, 7);
    TextAdd(container.story2b4, 0, 0, "\n\nCaptain: \nFederation orders, you have \nto do it.", font);
    //populate container.story2a5
    ViewAdd(container.story2a5, "Images/Background.png", 0, 0);
    ViewAdd(container.story2a5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story2a5, "Images/btnOkBig.png", 20, 380, onStoryLevelTwo, 8);
    TextAdd(container.story2a5, 0, 0, "\n\nCaptain: \nPrepare your items, we are \nleaving tomorrow.", font);
    //populate container.story2a6
    ViewAdd(container.story2a6, "Images/Background.png", 0, 0);
    ViewAdd(container.story2a6, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story2a6, "Images/btnEngage.png", 20, 380, onStoryLevelTwo, 9);
    ViewAdd(container.story2a6, "Images/btnAround.png", 170, 380, onStoryLevelTwo, 10);
    TextAdd(container.story2a6, 0, 0, "\n\nCaptain: \nThere's ships up ahead. \nShould we engage or go \naround?", 
        font);
    //populate container.story2e7
    ViewAdd(container.story2e7, "Images/Background.png", 0, 0);
    ViewAdd(container.story2e7, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story2e7, "Images/btnOkBig.png", 20, 380, onStoryLevelTwo, 11);
    TextAdd(container.story2e7, 0, 0, "\n\nCaptain: \nHave fun shooting!", font);
    //populate container.story2a7
    ViewAdd(container.story2a7, "Images/Background.png", 0, 0);
    ViewAdd(container.story2a7, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story2a7, "Images/btnOkBig.png", 20, 380, onStoryLevelTwo, 11);
    TextAdd(container.story2a7, 0, 0, "\n\nCaptain: \nThe ships noticed us and are \nattacking!", font);
}

void containerThree() {
    //populate container.story3a1
    ViewAdd(container.story3a1, "Images/Background.png", 0, 0);
    ViewAdd(container.story3a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story3a1, "Images/btnOkSmall.png", 20, 380, onStoryLevelThree, 2);
    ViewAdd(container.story3a1, "Images/btnNo.png", 170, 380, onStoryLevelThree, 1);
    TextAdd(container.story3a1, 0, 0, "\n\nCaptain: \nWe should check the \nwreckage.", font);
    //populate container.story3b2
    ViewAdd(container.story3b2, "Images/Background.png", 0, 0);
    ViewAdd(container.story3b2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story3b2, "Images/btnSorry.png", 20, 380, onStoryLevelThree, 2);
    ViewAdd(container.story3b2, "Images/btnOkSmall.png", 170, 380, onStoryLevelThree, 2);
    TextAdd(container.story3b2, 0, 0, "\n\nCaptain: \nI'm captain and I say we will, \nso we will.", font);
    //populate container.story3a3
    ViewAdd(container.story3a3, "Images/Background.png", 0, 0);
    ViewAdd(container.story3a3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story3a3, "Images/btnOkSmall.png", 20, 380, onStoryLevelThree, 3);
    ViewAdd(container.story3a3, "Images/btnNever.png", 170, 380, onStoryLevelThree, 3);
    TextAdd(container.story3a3, 0, 0, "\n\nEnemy: \nHands up!", font);
    //populate container.story3a4
    ViewAdd(container.story3a4, "Images/Background.png", 0, 0);
    ViewAdd(container.story3a4, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story3a4, "Images/btnWhereAreWe.png", 20, 380, onStoryLevelThree, 4);
    ViewAdd(container.story3a4, "Images/btnWhereCaptain.png", 170, 380, onStoryLevelThree, 4);
    TextAdd(container.story3a4, 0, 0, "\n\nEnemy: \nSorry for knocking you out, it \nwas the only way to bring \nyou "
        "here.", font);
    //populate container.story3a5
    ViewAdd(container.story3a5, "Images/Background.png", 0, 0);
    ViewAdd(container.story3a5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story3a5, "Images/btnYes.png", 20, 380, onStoryLevelThree, 5);
    ViewAdd(container.story3a5, "Images/btnNo.png", 170, 380, onStoryLevelThree, 5);
    TextAdd(container.story3a5, 0, 0, "\n\nEnemy: \nAre you familiar with torture?", font);
    //populate container.story3a6
    ViewAdd(container.story3a6, "Images/Background.png", 0, 0);
    ViewAdd(container.story3a6, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story3a6, "Images/btnOkSmall.png", 20, 380, onStoryLevelThree, 6);
    ViewAdd(container.story3a6, "Images/btnSo.png", 170, 380, onStoryLevelThree, 6);
    TextAdd(container.story3a6, 0, 0, "\n\nEnemy: \nTorture is what caused world \nwar 3 on your home planet: "
        "\nEarth.", font);
    //populate container.story3a7
    ViewAdd(container.story3a7, "Images/Background.png", 0, 0);
    ViewAdd(container.story3a7, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story3a7, "Images/btnNo!.png", 20, 380, onStoryLevelThree, 7);
    ViewAdd(container.story3a7, "Images/btnOkSmall.png", 170, 380, onStoryLevelThree, 7);
    TextAdd(container.story3a7, 0, 0, "\n\nEnemy: \nI will force you to torture your \ncaptain, hopefully "
        "causing a \nwar in the process.", font);
    //populate container.story3a8
    ViewAdd(container.story3a8, "Images/Background.png", 0, 0);
    ViewAdd(container.story3a8, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story3a8, "Images/btnNo!.png", 20, 380, onStoryLevelThree, 8);
    ViewAdd(container.story3a8, "Images/btnOkSmall.png", 170, 380, onStoryLevelThree, 8);
    TextAdd(container.story3a8, 0, 0, "\n\nEnemy: \nI will wait for you to torture \nhim until you do. There's "
        "\nnothing you can do about it.", font);
    //populate container.storyTorture
    TouchAdd(container.storyTorture, 0, 0, 320, 568, onTorture, 1);
    imageTorture = ViewAdd(container.storyTorture, "Images/TortureModeOne.png", -2, -2);
    ViewAdd(container.storyTorture, "Images/Pause.png", 270, 20, onPause, 1);
    hpTorture = ViewAdd(container.storyTorture, "Images/20HP.png", 20, 20);
    textTorture = TextAdd(container.storyTorture, 70, 0, "", FontAdd("Arial", "Regular", 24, 0xDF0101));
}

void containerFour() {
    //populate container.story4a1
    ViewAdd(container.story4a1, "Images/Background.png", 0, 0);
    ViewAdd(container.story4a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story4a1, "Images/btnTakeGun.png", 20, 380, onStoryLevelFour, 2);
    ViewAdd(container.story4a1, "Images/btnDoNothing.png", 170, 380, onStoryLevelFour, 1);
    TextAdd(container.story4a1, 0, 0, "\n\nEnemy: \nNow to torture you too.", font);
    //populate container.story4a2
    ViewAdd(container.story4a2, "Images/Background.png", 0, 0);
    ViewAdd(container.story4a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story4a2, "Images/btnShoot.png", 20, 380, onStoryLevelFour, 3);
    ViewAdd(container.story4a2, "Images/btnDoNothing.png", 170, 380, onStoryLevelFour, 1);
    TextAdd(container.story4a2, 0, 0, "\n\nEnemy: \nYou wouldn't dare shoot!", font);
    //populate container.story4a3
    ViewAdd(container.story4a3, "Images/Background.png", 0, 0);
    ViewAdd(container.story4a3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story4a3, "Images/btnOkBig.png", 20, 380, onStoryLevelFour, 4);
    TextAdd(container.story4a3, 0, 0, "\n\nAlex: \nHe escaped with an escape \npod!", font);
    //populate container.story4a4
    ViewAdd(container.story4a4, "Images/Background.png", 0, 0);
    ViewAdd(container.story4a4, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story4a4, "Images/btnEnemy.png", 20, 380, onStoryLevelFour, 5);
    ViewAdd(container.story4a4, "Images/btnMine.png", 170, 380, onStoryLevelFour, 6);
    TextAdd(container.story4a4, 0, 0, "\n\nAlly: \nYou need to get back. Luckily, \nmy radio signal reaches you. "
        "\nYou can either take the", font);
    TextAdd(container.story4a4, 0, 0, "\n\n\n\n\n\nenemy ship or try to get back to yours. Also, if you make it back", 
        font);
    TextAdd(container.story4a4, 0, 0, "\n\n\n\n\n\n\nto your ship, you'll be in \ntemporary command.", font);
    //populate container.story4b5
    ViewAdd(container.story4b5, "Images/Background.png", 0, 0);
    ViewAdd(container.story4b5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story4b5, "Images/btnOkBig.png", 20, 380, onStoryLevelFour, 6);
    TextAdd(container.story4b5, 0, 0, "\n\nLieutenant Dan: \nThe enemy ship you were \nflying broke down. Luckily,", 
        font);
    TextAdd(container.story4b5, 0, 0, "\n\n\n\n\nthe crew and I came to save \nyou.", font);
    //populate container.story4a6
    ViewAdd(container.story4a6, "Images/Background.png", 0, 0);
    ViewAdd(container.story4a6, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story4a6, "Images/btnContact.png", 20, 380, onStoryLevelFour, 7);
    ViewAdd(container.story4a6, "Images/btnShoot.png", 170, 380, onStoryLevelFour, 8);
    TextAdd(container.story4a6, 0, 0, "\n\nLieutenant Dan: \nYou are in temporary \ncommand. There's ships up "
        "\nahead; do you contact it to", font);
    TextAdd(container.story4a6, 0, 0, "\n\n\n\n\n\nsee if it's friendly or do you \nshoot at it? There's no way "
        "\naround.", font);
    //populate container.story4a7
    ViewAdd(container.story4a7, "Images/Background.png", 0, 0);
    ViewAdd(container.story4a7, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story4a7, "Images/btnOkBig.png", 20, 380, onStoryLevelFour, 9);
    TextAdd(container.story4a7, 0, 0, "\n\nLieutenant Dan: \nThe ships say they are \nfriendly, so we went around "
        "\nthem.", font);
    //populate container.story4b7
    ViewAdd(container.story4b7, "Images/Background.png", 0, 0);
    ViewAdd(container.story4b7, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story4b7, "Images/btnOkBig.png", 20, 380, onStoryLevelFour, 10);
    TextAdd(container.story4b7, 0, 0, "\n\nLieutenant Dan: \nYou shoot at the ships.", font);
    //populate container.story4a8
    ViewAdd(container.story4a8, "Images/Background.png", 0, 0);
    ViewAdd(container.story4a8, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story4a8, "Images/btnOkBig.png", 20, 380, onStoryLevelFour, 10);
    TextAdd(container.story4a8, 0, 0, "\n\nLieutenant Dan: \nThe ships followed you and \nattack.", font);
}

void containerFive() {
    //populate container.story5a1
    ViewAdd(container.story5a1, "Images/Background.png", 0, 0);
    ViewAdd(container.story5a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story5a1, "Images/btnOkSmall.png", 20, 380, onStoryLevelFive, 1);
    ViewAdd(container.story5a1, "Images/btnThanks.png", 170, 380, onStoryLevelFive, 1);
    TextAdd(container.story5a1, 0, 0, "\n\nCommodore Bailey: \nCongratulations on your way \nback. For your great "
        "action", font);
    TextAdd(container.story5a1, 0, 0, "\n\n\n\n\nout there, you have become \npilot of your own ship named \nICC "
        "Kepler.", font);
    //populate container.story5a2
    ViewAdd(container.story5a2, "Images/Background.png", 0, 0);
    ViewAdd(container.story5a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story5a2, "Images/btnYes.png", 20, 380, onStoryLevelFive, 2);
    ViewAdd(container.story5a2, "Images/btnNo.png", 170, 380, onStoryLevelFive, 8);
    TextAdd(container.story5a2, 0, 0, "\n\nBecca: \nWill you isStoryMarry me?", font);
    //populate container.story5a3
    ViewAdd(container.story5a3, "Images/Background.png", 0, 0);
    ViewAdd(container.story5a3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story5a3, "Images/btnNo.png", 20, 380, onStoryLevelFive, 3);
    ViewAdd(container.story5a3, "Images/btnOkSmall.png", 170, 380, onStoryLevelFive, 4);
    TextAdd(container.story5a3, 0, 0, "\n\nRon: \nWe located the escaped \nenemy. He is an admiral so \nhe is well "
        "guarded, killing him", font);
    TextAdd(container.story5a3, 0, 0, "\n\n\n\n\n\nwill be no easy feat. I will \ncome with you since I myself \nknow "
        "where the enemy \nadmiral is.", font);
    //populate container.story5b4
    ViewAdd(container.story5b4, "Images/Background.png", 0, 0);
    ViewAdd(container.story5b4, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story5b4, "Images/btnOkSmall.png", 20, 380, onStoryLevelFive, 4);
    ViewAdd(container.story5b4, "Images/btnSorry.png", 170, 380, onStoryLevelFive, 4);
    TextAdd(container.story5b4, 0, 0, "\n\nRon: \nFederation orders, sorry \nmate.", font);
    //populate container.story5a5
    ViewAdd(container.story5a5, "Images/Background.png", 0, 0);
    ViewAdd(container.story5a5, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story5a5, "Images/btnAround.png", 20, 380, onStoryLevelFive, 5);
    ViewAdd(container.story5a5, "Images/btnAttack.png", 170, 380, onStoryLevelFive, 6);
    TextAdd(container.story5a5, 0, 0, "\n\nRon: \nThere's a whole platoon of \nships. Do you go around and \ntry to "
        "avoid them, or do you", font);
    TextAdd(container.story5a5, 0, 0, "\n\n\n\n\n\nattack?", font);
    //populate container.story5a6
    ViewAdd(container.story5a6, "Images/Background.png", 0, 0);
    ViewAdd(container.story5a6, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story5a6, "Images/btnOkBig.png", 20, 380, onStoryLevelFive, 7);
    TextAdd(container.story5a6, 0, 0, "\n\nRon: \nThe ships see you before you \nare even able to go around \nand "
        "attack.", font);
    //populate container.story5b6
    ViewAdd(container.story5b6, "Images/Background.png", 0, 0);
    ViewAdd(container.story5b6, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story5b6, "Images/btnOkBig.png", 20, 380, onStoryLevelFive, 7);
    TextAdd(container.story5b6, 0, 0, "\n\nRon: \nAttacking the ships.", font);
}

void containerSixSeven() {
    //populate container.story6a1
    ViewAdd(container.story6a1, "Images/Background.png", 0, 0);
    ViewAdd(container.story6a1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story6a1, "Images/btnOkBig.png", 20, 380, onStoryLevelSix, 1);
    TextAdd(container.story6a1, 0, 0, "\n\nRon: \nGreat work, now go kill the \nenemy admiral!", font);
    //populate container.story6a2
    ViewAdd(container.story6a2, "Images/Background.png", 0, 0);
    ViewAdd(container.story6a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story6a2, "Images/btnLaugh.png", 20, 380, onStoryLevelSix, 2);
    ViewAdd(container.story6a2, "Images/btnSo.png", 170, 380, onStoryLevelSix, 3);
    TextAdd(container.story6a2, 0, 0, "\n\nAdmiral Skerbowh: \nYou will never be able to \ndefeat me. I am simply", 
        font);
    TextAdd(container.story6a2, 0, 0, "\n\n\n\n\nsmarter, stronger, faster, and \nmore powerful than you.", font);
    //populate container.story6a3
    ViewAdd(container.story6a3, "Images/Background.png", 0, 0);
    ViewAdd(container.story6a3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story6a3, "Images/btnOkSmall.png", 20, 380, onStoryLevelSix, 4);
    ViewAdd(container.story6a3, "Images/btnLaugh.png", 170, 380, onStoryLevelSix, 4);
    TextAdd(container.story6a3, 0, 0, "\n\nAdmiral Skerbowh: \nYou laugh in the face of \ndeath? I laugh at your", 
        font);
    TextAdd(container.story6a3, 0, 0, "\n\n\n\n\nconfidence; however, you \ntruly cannot believe that you \nmay "
        "emerge victorious.", font);
    //populate container.story6b3
    ViewAdd(container.story6b3, "Images/Background.png", 0, 0);
    ViewAdd(container.story6b3, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story6b3, "Images/btnOkSmall.png", 20, 380, onStoryLevelSix, 4);
    ViewAdd(container.story6b3, "Images/btnLaugh.png", 170, 380, onStoryLevelSix, 4);
    TextAdd(container.story6b3, 0, 0, "\n\nAdmiral Skerbowh: \nSo... You aren't intelligent \nenough to comprehend "
        "your", font);
    TextAdd(container.story6b3, 0, 0, "\n\n\n\n\ncertain and eventual death.", font);
    //populate container.story7w1
    ViewAdd(container.story7w1, "Images/Background.png", 0, 0);
    ViewAdd(container.story7w1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story7w1, "Images/btnOkBig.png", 20, 380, onStoryLevelSeven, 3);
    TextAdd(container.story7w1, 0, 0, "\n\nRon: \nYou defeated the enemy \nadmiral. The world will know \nof your "
        "greatness.", font);
    //populate container.story7l1
    ViewAdd(container.story7l1, "Images/Background.png", 0, 0);
    ViewAdd(container.story7l1, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story7l1, "Images/btnMyself.png", 20, 380, onStoryLevelSeven, 1);
    ViewAdd(container.story7l1, "Images/btnRon.png", 170, 380, onStoryLevelSeven, 2);
    TextAdd(container.story7l1, 0, 0, "\n\nAlex: \nMy ship has sustained critical \ndamage. Every single escape \npod "
        "other than one has been", font);
    TextAdd(container.story7l1, 0, 0, "\n\n\n\n\n\ntaken or destroyed. Should I \nsave myself or Ron?", font);
    //populate container.story7a2
    ViewAdd(container.story7a2, "Images/Background.png", 0, 0);
    ViewAdd(container.story7a2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story7a2, "Images/btnOkBig.png", 20, 380, onStoryLevelSeven, 3);
    TextAdd(container.story7a2, 0, 0, "\n\nExecutioner: \nYou are being executed for \ntreason since you abandoned "
        "\nyour ship and crew to die.", font);
    //populate container.story7b2
    ViewAdd(container.story7b2, "Images/Background.png", 0, 0);
    ViewAdd(container.story7b2, "Images/Pause.png", 270, 20, onPause, 1);
    ViewAdd(container.story7b2, "Images/btnOkBig.png", 20, 380, onStoryLevelSeven, 3);
}

