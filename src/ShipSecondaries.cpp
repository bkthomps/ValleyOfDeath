#include "DragonFireSDK.h"
#include "Globals.h"
#include "ShipSecondaries.h"
#include "CustomMath.h"
#include "StateToggle.h"
#include "UserEvent.h"

void healthBar() {
    if (player.health < 0) {
        player.health = 0;
    }
    if (isHealthUpdate) {
        const int FRAC_HEALTH = round(20 * player.health / player.possibleHealth);
        const int image = ImageAdd(concatHealth(FRAC_HEALTH));
        ViewSetImage(healthImage, image);
        if (player.health <= 0) {
            switch (currentScreen) {
                case SCREEN_ENDLESS:
                    currentScreen = SCREEN_HIGHSCORE;
                    doUpdateHighscore();
                    break;
                case SCREEN_STORY_BATTLE_1:
                    currentScreen = SCREEN_STORY_2A1;
                    reset();
                    break;
                case SCREEN_STORY_BATTLE_6:
                    currentScreen = SCREEN_STORY_7L1;
                    reset();
                    break;
                default:
                    currentScreen = SCREEN_DIED;
                    reset();
                    break;
            }
            screenSwitch();
        }
        isHealthUpdate = false;
        counter.healthRegen = 0;
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

void tortureHealth() {
    int imageTorturing, number = 100;
    if (counter.hpTorture > number * 20 && isTorture) {
        counter.hpTorture = number * 20;
    } else if (counter.hpTorture > number * 40 && !isTorture) {
        currentScreen = SCREEN_DIED;
        screenSwitch();
    } else if (counter.hpTorture <= number * 20 && counter.hpTorture > number * 19) {
        imageTorturing = ImageAdd("Images/20HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= number * 19 && counter.hpTorture > number * 18) {
        imageTorturing = ImageAdd("Images/19HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nStop This Madness!");
    } else if (counter.hpTorture <= number * 18 && counter.hpTorture > number * 17) {
        imageTorturing = ImageAdd("Images/18HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= number * 17 && counter.hpTorture > number * 16) {
        imageTorturing = ImageAdd("Images/17HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nDon't Do It!");
    } else if (counter.hpTorture <= number * 16 && counter.hpTorture > number * 15) {
        imageTorturing = ImageAdd("Images/16HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= number * 15 && counter.hpTorture > number * 14) {
        imageTorturing = ImageAdd("Images/15HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nI Beg Of You!");
    } else if (counter.hpTorture <= number * 14 && counter.hpTorture > number * 13) {
        imageTorturing = ImageAdd("Images/14HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= number * 13 && counter.hpTorture > number * 12) {
        imageTorturing = ImageAdd("Images/13HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nPlease Don't!");
    } else if (counter.hpTorture <= number * 12 && counter.hpTorture > number * 11) {
        imageTorturing = ImageAdd("Images/12HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= number * 11 && counter.hpTorture > number * 10) {
        imageTorturing = ImageAdd("Images/11HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nI Order You To Stop!");
    } else if (counter.hpTorture <= number * 10 && counter.hpTorture > number * 9) {
        imageTorturing = ImageAdd("Images/10HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= number * 9 && counter.hpTorture > number * 8) {
        imageTorturing = ImageAdd("Images/9HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nI Have A Family!");
    } else if (counter.hpTorture <= number * 8 && counter.hpTorture > number * 7) {
        imageTorturing = ImageAdd("Images/8HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= number * 7 && counter.hpTorture > number * 6) {
        imageTorturing = ImageAdd("Images/7HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nDon't Do This!");
    } else if (counter.hpTorture <= number * 6 && counter.hpTorture > number * 5) {
        imageTorturing = ImageAdd("Images/6HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= number * 5 && counter.hpTorture > number * 4) {
        imageTorturing = ImageAdd("Images/5HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nWhy Are You \nDoing This!");
    } else if (counter.hpTorture <= number * 4 && counter.hpTorture > number * 3) {
        imageTorturing = ImageAdd("Images/4HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= number * 3 && counter.hpTorture > number * 2) {
        imageTorturing = ImageAdd("Images/3HP.png");
        ViewSetImage(hpTorture, imageTorturing);
        TextSetText(textTorture, "\n\n\n\n\n\nYou Will Burn!");
    } else if (counter.hpTorture <= number * 2 && counter.hpTorture > number * 1) {
        imageTorturing = ImageAdd("Images/2HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= number * 1 && counter.hpTorture > 0) {
        imageTorturing = ImageAdd("Images/1HP.png");
        ViewSetImage(hpTorture, imageTorturing);
    } else if (counter.hpTorture <= 0) {
        isPaused = false;
        currentScreen = SCREEN_STORY_4A1;
        screenSwitch();
    }
}

void bulletTime() {
    int x, y, x2, y2, x3, y3;
    bool used = false;
    for (int i = 1; i <= 15; i++) {
        if (counter.bulletTime == i * PLAYER_BULLET_COOLDOWN_SPEED) {
            used = true;
            if (player.typeOfShip == 8) {
                ViewSetxy(player.bulletOne[i - 1], player.currentXCoord + player.bulletOneOffsetXCoord, 
                    player.currentYCoord + player.bulletOneOffsetYCoord);
                ViewSetxy(player.rocket[i - 1], player.currentXCoord + player.rocketOffsetXCoord, 
                    player.currentYCoord + player.rocketOffsetYCoord);
                ViewSetxy(player.bulletTwo[i - 1], player.currentXCoord + player.bulletTwoOffsetXCoord, 
                    player.currentYCoord + player.bulletTwoOffsetYCoord);
            } else if (player.typeOfShip == 7) {
                ViewSetxy(player.rocket[i - 1], player.currentXCoord + player.rocketOffsetXCoord, 
                    player.currentYCoord + player.rocketOffsetYCoord);
            } else if (player.typeOfShip == 6 || player.typeOfShip == 5) {
                ViewSetxy(player.bulletOne[i - 1], player.currentXCoord + player.bulletOneOffsetXCoord, 
                    player.currentYCoord + player.bulletOneOffsetYCoord);
                ViewSetxy(player.bulletTwo[i - 1], player.currentXCoord + player.bulletTwoOffsetXCoord, 
                    player.currentYCoord + player.bulletTwoOffsetYCoord);
            } else {
                ViewSetxy(player.bulletOne[i - 1], player.currentXCoord + player.bulletOneOffsetXCoord, 
                    player.currentYCoord + player.bulletOneOffsetYCoord);
            }
        }
    }
    if (counter.bulletTime >= 15 * PLAYER_BULLET_COOLDOWN_SPEED) {
        counter.bulletTime = 0;
    }
    if (!used) {
        for (int i = 0; i < 15; i++) {
            x = ViewGetx(player.bulletOne[i]);
            y = ViewGety(player.bulletOne[i]);
            x2 = ViewGetx(player.rocket[i]);
            y2 = ViewGety(player.rocket[i]);
            x3 = ViewGetx(player.bulletTwo[i]);
            y3 = ViewGety(player.bulletTwo[i]);
            if (y > -20 || y2 > -20 || y3 > -20) {
                ViewSetxy(player.bulletOne[i], x, y - PLAYER_BULLET_SPEED);
                ViewSetxy(player.rocket[i], x2, y2 - PLAYER_BULLET_SPEED);
                ViewSetxy(player.bulletTwo[i], x3, y3 - PLAYER_BULLET_SPEED);
            }
            for (int j = 0; j < 10; j++) {
                //ship 1
                const int enemy1x = one[j].getXCoord();
                const int enemy1y = one[j].getYCoord();
                if (y > enemy1y && y < enemy1y + 94 && x > enemy1x + 9 && x < enemy1x + 76) {
                    ViewSetxy(player.bulletOne[i], -10, -10);
                    one[j].damage(1);
                }
                if (y2 > enemy1y && y2 < enemy1y + 94 && x2 > enemy1x + 9 && x2 < enemy1x + 76) {
                    ViewSetxy(player.rocket[i], -20, -20);
                    one[j].damage(3);
                }
                if (y3 > enemy1y && y3 < enemy1y + 94 && x3 > enemy1x + 9 && x3 < enemy1x + 76) {
                    ViewSetxy(player.bulletTwo[i], -10, -10);
                    one[j].damage(1);
                }
                //ship 2
                const int enemy2x = two[j].getXCoord();
                const int enemy2y = two[j].getYCoord();
                if (y > enemy2y && y < enemy2y + 94 && x > enemy2x + 15 && x < enemy2x + 69) {
                    ViewSetxy(player.bulletOne[i], -10, -10);
                    two[j].damage(1);
                }
                if (y2 > enemy2y && y2 < enemy2y + 94 && x2 > enemy2x + 15 && x2 < enemy2x + 69) {
                    ViewSetxy(player.rocket[i], -20, -20);
                    two[j].damage(3);
                }
                if (y3 > enemy2y && y3 < enemy2y + 94 && x3 > enemy2x + 15 && x3 < enemy2x + 69) {
                    ViewSetxy(player.bulletTwo[i], -10, -10);
                    two[j].damage(1);
                }
                //ship 3
                const int enemy3x = three[j].getXCoord();
                const int enemy3y = three[j].getYCoord();
                if (y > enemy3y && y < enemy3y + 94 && x > enemy3x + 18 && x < enemy3x + 66) {
                    ViewSetxy(player.bulletOne[i], -10, -10);
                    three[j].damage(1);
                }
                if (y2 > enemy3y && y2 < enemy3y + 94 && x2 > enemy3x + 18 && x2 < enemy3x + 66) {
                    ViewSetxy(player.rocket[i], -20, -20);
                    three[j].damage(3);
                }
                if (y3 > enemy3y && y3 < enemy3y + 94 && x3 > enemy3x + 18 && x3 < enemy3x + 66) {
                    ViewSetxy(player.bulletTwo[i], -10, -10);
                    three[j].damage(1);
                }
                //ship 4
                const int enemy4x = four[j].getXCoord();
                const int enemy4y = four[j].getYCoord();
                if (y > enemy4y && y < enemy4y + 94 && x > enemy4x - 3 && x < enemy4x + 87) {
                    ViewSetxy(player.bulletOne[i], -10, -10);
                    four[j].damage(1);
                }
                if (y2 > enemy4y && y2 < enemy4y + 94 && x2 > enemy4x - 3 && x2 < enemy4x + 87) {
                    ViewSetxy(player.rocket[i], -20, -20);
                    four[j].damage(3);
                }
                if (y3 > enemy4y && y3 < enemy4y + 94 && x3 > enemy4x - 3 && x3 < enemy4x + 87) {
                    ViewSetxy(player.bulletTwo[i], -10, -10);
                    four[j].damage(1);
                }
            }
            for (int j = 0; j < 5; j++) {
                //ship 5
                const int enemy5x = five[j].getXCoord();
                const int enemy5y = five[j].getYCoord();
                if (y > enemy5y && y < enemy5y + 94 && x > enemy5x + 13 && x < enemy5x + 71) {
                    ViewSetxy(player.bulletOne[i], -10, -10);
                    five[j].damage(1);
                }
                if (y2 > enemy5y && y2 < enemy5y + 94 && x2 > enemy5x + 13 && x2 < enemy5x + 71) {
                    ViewSetxy(player.rocket[i], -20, -20);
                    five[j].damage(3);
                }
                if (y3 > enemy5y && y3 < enemy5y + 94 && x3 > enemy5x + 13 && x3 < enemy5x + 71) {
                    ViewSetxy(player.bulletTwo[i], -10, -10);
                    five[j].damage(1);
                }
                //ship 6
                const int enemy6x = six[j].getXCoord();
                const int enemy6y = six[j].getYCoord();
                if (y > enemy6y && y < enemy6y + 94 && x > enemy6x + 3 && x < enemy6x + 81) {
                    ViewSetxy(player.bulletOne[i], -10, -10);
                    six[j].damage(1);
                }
                if (y2 > enemy6y && y2 < enemy6y + 94 && x2 > enemy6x + 3 && x2 < enemy6x + 81) {
                    ViewSetxy(player.rocket[i], -20, -20);
                    six[j].damage(3);
                }
                if (y3 > enemy6y && y3 < enemy6y + 94 && x3 > enemy6x + 3 && x3 < enemy6x + 81) {
                    ViewSetxy(player.bulletTwo[i], -10, -10);
                    six[j].damage(1);
                }
                //ship 7
                const int enemy7x = seven[j].getXCoord();
                const int enemy7y = seven[j].getYCoord();
                if (y > enemy7y && y < enemy7y + 94 && x > enemy7x - 2 && x < enemy7x + 86) {
                    ViewSetxy(player.bulletOne[i], -10, -10);
                    seven[j].damage(1);
                }
                if (y2 > enemy7y && y2 < enemy7y + 94 && x2 > enemy7x - 2 && x2 < enemy7x + 86) {
                    ViewSetxy(player.rocket[i], -20, -20);
                    seven[j].damage(3);
                }
                if (y3 > enemy7y && y3 < enemy7y + 94 && x3 > enemy7x - 2 && x3 < enemy7x + 86) {
                    ViewSetxy(player.bulletTwo[i], -10, -10);
                    seven[j].damage(1);
                }
                //ship 8
                const int enemy8x = eight[j].getXCoord();
                const int enemy8y = eight[j].getYCoord();
                if (y > enemy8y && y < enemy8y + 94 && x > enemy8x - 3 && x < enemy8x + 86) {
                    ViewSetxy(player.bulletOne[i], -10, -10);
                    eight[j].damage(1);
                }
                if (y2 > enemy8y && y2 < enemy8y + 94 && x2 > enemy8x - 3 && x2 < enemy8x + 86) {
                    ViewSetxy(player.rocket[i], -20, -20);
                    eight[j].damage(3);
                }
                if (y3 > enemy8y && y3 < enemy8y + 94 && x3 > enemy8x - 3 && x3 < enemy8x + 86) {
                    ViewSetxy(player.bulletTwo[i], -10, -10);
                    eight[j].damage(1);
                }
            }
            //ship 9
            const int enemy9x = nine.getXCoord();
            const int enemy9y = nine.getYCoord();
            if (y > enemy9y && y < enemy9y + 94 && x > enemy9x && x < enemy9x + 240) {
                ViewSetxy(player.bulletOne[i], -10, -10);
                nine.damage(1);
            }
            if (y2 > enemy9y && y2 < enemy9y + 94 && x2 > enemy9x && x2 < enemy9x + 240) {
                ViewSetxy(player.rocket[i], -20, -20);
                nine.damage(3);
            }
            if (y3 > enemy9y && y3 < enemy9y + 94 && x3 > enemy9x && x3 < enemy9x + 240) {
                ViewSetxy(player.bulletTwo[i], -10, -10);
                nine.damage(1);
            }
            //ship 10
            const int enemy10x = ten.getXCoord();
            const int enemy10y = ten.getYCoord();
            if (y > enemy10y && y < enemy10y + 94 && x > enemy10x && x < enemy10x + 240) {
                ViewSetxy(player.bulletOne[i], -10, -10);
                ten.damage(1);
            }
            if (y2 > enemy10y && y2 < enemy10y + 94 && x2 > enemy10x && x2 < enemy10x + 240) {
                ViewSetxy(player.rocket[i], -20, -20);
                ten.damage(3);
            }
            if (y3 > enemy10y && y3 < enemy10y + 94 && x3 > enemy10x && x3 < enemy10x + 240) {
                ViewSetxy(player.bulletTwo[i], -10, -10);
                ten.damage(1);
            }
        }
    }
}

void playerShipMove() {
    //move x
    if (player.newXCoord > player.currentXCoord + player.speed / 2) {
        player.currentXCoord += player.speed;
    } else if (player.newXCoord + player.speed / 2 < player.currentXCoord) {
        player.currentXCoord -= player.speed;
    }
    //move y
    if (player.newYCoord > player.currentYCoord + player.speed / 2) {
        player.currentYCoord += player.speed;
    } else if (player.newYCoord + player.speed / 2 < player.currentYCoord) {
        player.currentYCoord -= player.speed;
    }
    //stop x
    if (player.currentXCoord < 0) {
        player.currentXCoord = 0;
    } else if (player.currentXCoord > 226) {
        player.currentXCoord = 226;
    }
    //stop y
    if (player.currentYCoord < 50) {
        player.currentYCoord = 50;
    } else if (player.currentYCoord > 386) {
        player.currentYCoord = 386;
    }
    //set ship view
    ViewSetxy(player.instance, player.currentXCoord, player.currentYCoord);
}
