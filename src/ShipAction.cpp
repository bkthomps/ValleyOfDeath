#include "DragonFireSDK.h"
#include "Globals.h"
#include "ShipAction.h"
#include "EnemyShipSpawning.h"
#include "CustomMath.h"
#include "StateToggle.h"

void doEnemyShipMove() {
    enemyShipMove();
    switch (set) {
        case 1:
            setOne();
            break;
        case 2:
            setTwo();
            break;
        case 3:
            setThree();
            break;
        case 4:
            setFour();
            break;
        case 5:
            setFive();
            break;
        case 6:
            counter.shipMove = 0;
            level += 1;
            set = 1;
            break;
    }
}

void enemyShipMove() {
    for (int i = 0; i < 10; i++) {
        //y cords
        one[i].setYCoord(ViewGety(one[i].getInstance()));
        two[i].setYCoord(ViewGety(two[i].getInstance()));
        three[i].setYCoord(ViewGety(three[i].getInstance()));
        four[i].setYCoord(ViewGety(four[i].getInstance()));
        //x cords
        one[i].setXCoord(ViewGetx(one[i].getInstance()));
        two[i].setXCoord(ViewGetx(two[i].getInstance()));
        three[i].setXCoord(ViewGetx(three[i].getInstance()));
        four[i].setXCoord(ViewGetx(four[i].getInstance()));
    }
    for (int i = 0; i < 5; i++) {
        //y cords
        five[i].setYCoord(ViewGety(five[i].getInstance()));
        six[i].setYCoord(ViewGety(six[i].getInstance()));
        seven[i].setYCoord(ViewGety(seven[i].getInstance()));
        eight[i].setYCoord(ViewGety(eight[i].getInstance()));
        //x cords
        five[i].setXCoord(ViewGetx(five[i].getInstance()));
        six[i].setXCoord(ViewGetx(six[i].getInstance()));
        seven[i].setXCoord(ViewGetx(seven[i].getInstance()));
        eight[i].setXCoord(ViewGetx(eight[i].getInstance()));
    }
    //x cords
    nine.setXCoord(ViewGetx(nine.getInstance()));
    //y cords
    nine.setYCoord(ViewGety(nine.getInstance()));
    //x cords
    ten.setXCoord(ViewGetx(ten.getInstance()));
    //y cords
    ten.setYCoord(ViewGety(ten.getInstance()));
    for (int i = 0; i < 10; i++) {
        if (one[i].getYCoord() < 600) {
            ViewSetxy(one[i].getInstance(), one[i].getXCoord(), one[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (two[i].getYCoord() < 600) {
            ViewSetxy(two[i].getInstance(), two[i].getXCoord(), two[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (three[i].getYCoord() < 600) {
            ViewSetxy(three[i].getInstance(), three[i].getXCoord(), three[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (four[i].getYCoord() < 600) {
            ViewSetxy(four[i].getInstance(), four[i].getXCoord(), four[i].getYCoord() + ENEMY_FLY_SPEED);
        }
    }
    for (int i = 0; i < 5; i++) {
        if (five[i].getYCoord() < 600) {
            ViewSetxy(five[i].getInstance(), five[i].getXCoord(), five[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (six[i].getYCoord() < 600) {
            ViewSetxy(six[i].getInstance(), six[i].getXCoord(), six[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (seven[i].getYCoord() < 600) {
            ViewSetxy(seven[i].getInstance(), seven[i].getXCoord(), seven[i].getYCoord() + ENEMY_FLY_SPEED);
        }
        if (eight[i].getYCoord() < 600) {
            ViewSetxy(eight[i].getInstance(), eight[i].getXCoord(), eight[i].getYCoord() + ENEMY_FLY_SPEED);
        }
    }
    
    static bool goRight = false;
    //ship 9
    if (nine.getYCoord() < 40) {
        ViewSetxy(nine.getInstance(), nine.getXCoord(), nine.getYCoord() + ENEMY_FLY_SPEED);
    } else if (nine.getYCoord() >= 40 && nine.getYCoord() < 600) {
        const int FACTOR = (goRight) ? (1) : (-1);
        ViewSetxy(nine.getInstance(), nine.getXCoord() + FACTOR, nine.getYCoord());
    }
    if (nine.getXCoord() == 29) {
        goRight = true;
    } else if (nine.getXCoord() == 149) {
        goRight = false;
    }
    //ship 10
    if (ten.getYCoord() < 40) {
        ViewSetxy(ten.getInstance(), ten.getXCoord(), ten.getYCoord() + ENEMY_FLY_SPEED);
    } else if (ten.getYCoord() >= 40 && ten.getYCoord() < 600) {
        const int FACTOR = (goRight) ? (1) : (-1);
        ViewSetxy(ten.getInstance(), ten.getXCoord() + FACTOR, ten.getYCoord());
    }
    if (ten.getXCoord() == 25) {
        goRight = true;
    } else if (ten.getXCoord() == 145) {
        goRight = false;
    }
}

bool shipInAction(int ship) {
    const int i = counter.shipAction;
    bool ret = false;
    switch (ship) {
        case 1:
            ret = one[i].getHealth() <= 0 && one[i].getYCoord() >= 0 && one[i].getXCoord() < 600 
                && one[i].getYCoord() >= 0 && one[i].getXCoord() <= 320;
            break;
        case 2:
            ret = two[i].getHealth() <= 0 && two[i].getYCoord() >= 0 && two[i].getXCoord() < 600 
                && two[i].getYCoord() >= 0 && two[i].getXCoord() <= 320;
            break;
        case 3:
            ret = three[i].getHealth() <= 0 && three[i].getYCoord() >= 0 && three[i].getXCoord() < 600 
                && three[i].getYCoord() >= 0 && three[i].getXCoord() <= 320;
            break;
        case 4:
            ret = four[i].getHealth() <= 0 && four[i].getYCoord() >= 0 && four[i].getXCoord() < 600 
                && four[i].getYCoord() >= 0 && four[i].getXCoord() <= 320;
            break;
        case 5:
            ret = five[i].getHealth() <= 0 && five[i].getYCoord() >= 0 && five[i].getXCoord() < 600 
                && five[i].getYCoord() >= 0 && five[i].getXCoord() <= 320;
            break;
        case 6:
            ret = six[i].getHealth() <= 0 && six[i].getYCoord() >= 0 && six[i].getXCoord() < 600 
                && six[i].getYCoord() >= 0 && six[i].getXCoord() <= 320;
            break;
        case 7:
            ret = seven[i].getHealth() <= 0 && seven[i].getYCoord() >= 0 && seven[i].getXCoord() < 600 
                && seven[i].getYCoord() >= 0 && seven[i].getXCoord() <= 320;
            break;
        case 8:
            ret = eight[i].getHealth() <= 0 && eight[i].getYCoord() >= 0 && eight[i].getXCoord() < 600 
                && eight[i].getYCoord() >= 0 && eight[i].getXCoord() <= 320;
            break;
        case 9:
            ret = nine.getHealth() <= 0 && nine.getYCoord() >= 0 && nine.getXCoord() < 600 
                && nine.getYCoord() >= 0 && nine.getXCoord() <= 320;
            break;
        case 10:
            ret = ten.getHealth() <= 0 && ten.getYCoord() >= 0 && ten.getXCoord() < 600 
                && ten.getYCoord() >= 0 && ten.getXCoord() <= 320;
            break;
    }
    return ret;
}

void doEnemyShipShoot() {
    for (int i = 0; i < 5; i++) {
        if (counter.bulletMove == (i + 1) * ENEMY_BULLET_COOLDOWN_SPEED) {
            //ship 1-4
            for (int j = 0; j < 10; j++) {
                one[j].setBullet(i, one[j].getXCoord() + 43, one[j].getYCoord() + 83);
                two[j].setBullet(i, two[j].getXCoord() + 43, two[j].getYCoord() + 94);
                three[j].setBullet(i, three[j].getXCoord() + 43, three[j].getYCoord() + 88);
                four[j].setBullet(i, four[j].getXCoord() + 43, four[j].getYCoord() + 94);
            }
            //ship 5-8
            for (int j = 0; j < 5; j++) {
                five[j].setBulletOne(i, five[j].getXCoord() + 31, five[j].getYCoord() + 71);
                five[j].setBulletTwo(i, five[j].getXCoord() + 54, five[j].getYCoord() + 71);
                six[j].setBulletOne(i, six[j].getXCoord() + 15, six[j].getYCoord() + 53);
                six[j].setBulletTwo(i, six[j].getXCoord() + 68, six[j].getYCoord() + 53);
                seven[j].setRocket(i, seven[j].getXCoord() + 42, seven[j].getYCoord() + 83);
                eight[j].setBulletOne(i, eight[j].getXCoord() + 12, eight[j].getYCoord() + 54);
                eight[j].setRocket(i, eight[j].getXCoord() + 42, eight[j].getYCoord() + 92);
                eight[j].setBulletTwo(i, eight[j].getXCoord() + 74, eight[j].getYCoord() + 54);
            }
            //ship 9
            nine.setBulletOne(i, nine.getXCoord() + 3, nine.getYCoord() + 83);
            nine.setRocket(i, nine.getXCoord() + 66, nine.getYCoord() + 230);
            nine.setBulletTwo(i, nine.getXCoord() + 130, nine.getYCoord() + 83);
            //ship 10
            ten.setBulletOne(i, ten.getXCoord() + 13, ten.getYCoord() + 83);
            ten.setRocket(i, ten.getXCoord() + 69, ten.getYCoord() + 233);
            ten.setBulletTwo(i, ten.getXCoord() + 129, ten.getYCoord() + 83);
        }
    }
    if (counter.bulletMove >= 5 * ENEMY_BULLET_COOLDOWN_SPEED) {
        counter.bulletMove = 0;
    }
    if (counter.bulletMove % ENEMY_BULLET_COOLDOWN_SPEED != 0) {
        //1
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoord = ViewGetx(one[i].getBullet(j));
                const int yCoord = ViewGety(one[i].getBullet(j));
                if (yCoord < 600) {
                    one[i].setBullet(j, xCoord, yCoord + ENEMY_BULLET_SPEED);
                }
                if (yCoord > player.currentYCoord && yCoord < player.currentYCoord + 94 && xCoord > player.currentXCoord + player.widthOne && xCoord < player.currentXCoord + player.widthTwo) {
                    player.health -= 1;
                    isHealthUpdate = true;
                    one[i].setBullet(j, 600, 600);
                }
            }
        }
        //2
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoord = ViewGetx(two[i].getBullet(j));
                const int yCoord = ViewGety(two[i].getBullet(j));
                if (yCoord < 600) {
                    two[i].setBullet(j, xCoord, yCoord + ENEMY_BULLET_SPEED);
                }
                if (yCoord > player.currentYCoord && yCoord < player.currentYCoord + 94 && xCoord > player.currentXCoord + player.widthOne && xCoord < player.currentXCoord + player.widthTwo) {
                    player.health -= 1;
                    isHealthUpdate = true;
                    two[i].setBullet(j, 600, 600);
                }
            }
        }
        //3
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoord = ViewGetx(three[i].getBullet(j));
                const int yCoord = ViewGety(three[i].getBullet(j));
                if (yCoord < 600) {
                    three[i].setBullet(j, xCoord, yCoord + ENEMY_BULLET_SPEED);
                }
                if (yCoord > player.currentYCoord && yCoord < player.currentYCoord + 94 && xCoord > player.currentXCoord + player.widthOne && xCoord < player.currentXCoord + player.widthTwo) {
                    player.health -= 1;
                    isHealthUpdate = true;
                    three[i].setBullet(j, 600, 600);
                }
            }
        }
        //4
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoord = ViewGetx(four[i].getBullet(j));
                const int yCoord = ViewGety(four[i].getBullet(j));
                if (yCoord < 600) {
                    four[i].setBullet(j, xCoord, yCoord + ENEMY_BULLET_SPEED);
                }
                if (yCoord > player.currentYCoord && yCoord < player.currentYCoord + 94 && xCoord > player.currentXCoord + player.widthOne && xCoord < player.currentXCoord + player.widthTwo) {
                    player.health -= 1;
                    isHealthUpdate = true;
                    four[i].setBullet(j, 600, 600);
                }
            }
        }
        //5
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoordOne = ViewGetx(five[i].getBulletOne(j));
                const int yCoordOne = ViewGety(five[i].getBulletOne(j));
                const int xCoordThree = ViewGetx(five[i].getBulletTwo(j));
                const int yCoordThree = ViewGety(five[i].getBulletTwo(j));
                if (yCoordOne < 600 || yCoordThree < 600) {
                    five[i].setBulletOne(j, xCoordOne, yCoordOne + ENEMY_BULLET_SPEED);
                    five[i].setBulletTwo(j, xCoordThree, yCoordThree + ENEMY_BULLET_SPEED);
                }
                if (yCoordOne > player.currentYCoord && yCoordOne < player.currentYCoord + 94 && xCoordOne > player.currentXCoord + player.widthOne && xCoordOne < player.currentXCoord + player.widthTwo) {
                    player.health -= 1;
                    isHealthUpdate = true;
                    five[i].setBulletOne(j, 600, 600);
                }
                if (yCoordThree > player.currentYCoord && yCoordThree < player.currentYCoord + 94 && xCoordThree > player.currentXCoord + player.widthOne && xCoordThree < player.currentXCoord + player.widthTwo) {
                    player.health -= 1;
                    isHealthUpdate = true;
                    five[i].setBulletTwo(j, 600, 600);
                }
            }
        }
        //6
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoordOne = ViewGetx(six[i].getBulletOne(j));
                const int yCoordOne = ViewGety(six[i].getBulletOne(j));
                const int xCoordThree = ViewGetx(six[i].getBulletTwo(j));
                const int yCoordThree = ViewGety(six[i].getBulletTwo(j));
                if (yCoordOne < 600 || yCoordThree < 600) {
                    six[i].setBulletOne(j, xCoordOne, yCoordOne + ENEMY_BULLET_SPEED);
                    six[i].setBulletTwo(j, xCoordThree, yCoordThree + ENEMY_BULLET_SPEED);
                }
                if (yCoordOne > player.currentYCoord && yCoordOne < player.currentYCoord + 94 && xCoordOne > player.currentXCoord + player.widthOne && xCoordOne < player.currentXCoord + player.widthTwo) {
                    player.health -= 1;
                    isHealthUpdate = true;
                    six[i].setBulletOne(j, 600, 600);
                }
                if (yCoordThree > player.currentYCoord && yCoordThree < player.currentYCoord + 94 && xCoordThree > player.currentXCoord + player.widthOne && xCoordThree < player.currentXCoord + player.widthTwo) {
                    player.health -= 1;
                    isHealthUpdate = true;
                    six[i].setBulletTwo(j, 600, 600);
                }
            }
        }
        //7
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoordTwo = ViewGetx(seven[i].getRocket(j));
                const int yCoordTwo = ViewGety(seven[i].getRocket(j));
                if (yCoordTwo < 600) {
                    seven[i].setRocket(j, xCoordTwo, yCoordTwo + ENEMY_BULLET_SPEED);
                }
                if (yCoordTwo > player.currentYCoord && yCoordTwo < player.currentYCoord + 94 && xCoordTwo > player.currentXCoord + player.widthOne && xCoordTwo < player.currentXCoord + player.widthTwo) {
                    player.health -= 3;
                    isHealthUpdate = true;
                    seven[i].setRocket(j, 600, 600);
                }
            }
        }
        //8
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                const int xCoordOne = ViewGetx(eight[i].getBulletOne(j));
                const int yCoordOne = ViewGety(eight[i].getBulletOne(j));
                const int xCoordTwo = ViewGetx(eight[i].getRocket(j));
                const int yCoordTwo = ViewGety(eight[i].getRocket(j));
                const int xCoordThree = ViewGetx(eight[i].getBulletTwo(j));
                const int yCoordThree = ViewGety(eight[i].getBulletTwo(j));
                if (yCoordOne < 600 || yCoordTwo < 600 || yCoordThree < 600) {
                    eight[i].setBulletOne(j, xCoordOne, yCoordOne + ENEMY_BULLET_SPEED);
                    eight[i].setRocket(j, xCoordTwo, yCoordTwo + ENEMY_BULLET_SPEED);
                    eight[i].setBulletTwo(j, xCoordThree, yCoordThree + ENEMY_BULLET_SPEED);
                }
                if (yCoordOne > player.currentYCoord && yCoordOne < player.currentYCoord + 94 && xCoordOne > player.currentXCoord + player.widthOne && xCoordOne < player.currentXCoord + player.widthTwo) {
                    player.health -= 1;
                    isHealthUpdate = true;
                    eight[i].setBulletOne(j, 600, 600);
                }
                if (yCoordTwo > player.currentYCoord && yCoordTwo < player.currentYCoord + 94 && xCoordTwo > player.currentXCoord + player.widthOne && xCoordTwo < player.currentXCoord + player.widthTwo) {
                    player.health -= 3;
                    isHealthUpdate = true;
                    eight[i].setRocket(j, 600, 600);
                }
                if (yCoordThree > player.currentYCoord && yCoordThree < player.currentYCoord + 94 && xCoordThree > player.currentXCoord + player.widthOne && xCoordThree < player.currentXCoord + player.widthTwo) {
                    player.health -= 1;
                    isHealthUpdate = true;
                    eight[i].setBulletTwo(j, 600, 600);
                }
            }
        }
        //9
        for (int j = 0; j < 5; j++) {
            const int xCoordOne = ViewGetx(nine.getBulletOne(j));
            const int yCoordOne = ViewGety(nine.getBulletOne(j));
            const int xCoordTwo = ViewGetx(nine.getRocket(j));
            const int yCoordTwo = ViewGety(nine.getRocket(j));
            const int xCoordThree = ViewGetx(nine.getBulletTwo(j));
            const int yCoordThree = ViewGety(nine.getBulletTwo(j));
            if (yCoordOne < 600 || yCoordTwo < 600 || yCoordThree < 600) {
                nine.setBulletOne(j, xCoordOne, yCoordOne + ENEMY_BULLET_SPEED);
                nine.setRocket(j, xCoordTwo, yCoordTwo + ENEMY_BULLET_SPEED);
                nine.setBulletTwo(j, xCoordThree, yCoordThree + ENEMY_BULLET_SPEED);
            }
            if (yCoordOne > player.currentYCoord && yCoordOne < player.currentYCoord + 94 && xCoordOne > player.currentXCoord + player.widthOne && xCoordOne < player.currentXCoord + player.widthTwo) {
                player.health -= 1;
                isHealthUpdate = true;
                nine.setBulletOne(j, 600, 600);
            }
            if (yCoordTwo > player.currentYCoord && yCoordTwo < player.currentYCoord + 94 && xCoordTwo > player.currentXCoord + player.widthOne && xCoordTwo < player.currentXCoord + player.widthTwo) {
                player.health -= 3;
                isHealthUpdate = true;
                nine.setRocket(j, 600, 600);
            }
            if (yCoordThree > player.currentYCoord && yCoordThree < player.currentYCoord + 94 && xCoordThree > player.currentXCoord + player.widthOne && xCoordThree < player.currentXCoord + player.widthTwo) {
                player.health -= 1;
                isHealthUpdate = true;
                nine.setBulletTwo(j, 600, 600);
            }
        }
        //10
        for (int j = 0; j < 5; j++) {
            const int xCoordOne = ViewGetx(ten.getBulletOne(j));
            const int yCoordOne = ViewGety(ten.getBulletOne(j));
            const int xCoordTwo = ViewGetx(ten.getRocket(j));
            const int yCoordTwo = ViewGety(ten.getRocket(j));
            const int xCoordThree = ViewGetx(ten.getBulletTwo(j));
            const int yCoordThree = ViewGety(ten.getBulletTwo(j));
            if (yCoordOne < 600 || yCoordTwo < 600 || yCoordThree < 600) {
                ten.setBulletOne(j, xCoordOne, yCoordOne + ENEMY_BULLET_SPEED);
                ten.setRocket(j, xCoordTwo, yCoordTwo + ENEMY_BULLET_SPEED);
                ten.setBulletTwo(j, xCoordThree, yCoordThree + ENEMY_BULLET_SPEED);
            }
            if (yCoordOne > player.currentYCoord && yCoordOne < player.currentYCoord + 94 && xCoordOne > player.currentXCoord + player.widthOne && xCoordOne < player.currentXCoord + player.widthTwo) {
                player.health -= 1;
                isHealthUpdate = true;
                ten.setBulletOne(j, 600, 600);
            }
            if (yCoordTwo > player.currentYCoord && yCoordTwo < player.currentYCoord + 94 && xCoordTwo > player.currentXCoord + player.widthOne && xCoordTwo < player.currentXCoord + player.widthTwo) {
                player.health -= 3;
                isHealthUpdate = true;
                ten.setRocket(j, 600, 600);
            }
            if (yCoordThree > player.currentYCoord && yCoordThree < player.currentYCoord + 94 && xCoordThree > player.currentXCoord + player.widthOne && xCoordThree < player.currentXCoord + player.widthTwo) {
                player.health -= 1;
                isHealthUpdate = true;
                ten.setBulletTwo(j, 600, 600);
            }
        }
    }
}

void shipCollision() {
    for (int i = 0; i < 10; i++) {
        //ship 1
        if (player.currentXCoord + player.widthOne < one[i].getXCoord() + 76 && player.currentXCoord + player.widthTwo > one[i].getXCoord() + 18 
            && player.currentYCoord < one[i].getYCoord() + 94 && player.currentYCoord + 94 > one[i].getYCoord()) {
            if (one[i].getHealth() > 0) {
                one[i].damage(3);
                player.health -= 3;
                isHealthUpdate = true;
            }
        }
        //ship 2
        if (player.currentXCoord + player.widthOne < two[i].getXCoord() + 69 && player.currentXCoord + player.widthTwo > two[i].getXCoord() + 24 
            && player.currentYCoord < two[i].getYCoord() + 94 && player.currentYCoord + 94 > two[i].getYCoord()) {
            if (two[i].getHealth() > 0) {
                two[i].damage(3);
                player.health -= 3;
                isHealthUpdate = true;
            }
        }
        //ship 3
        if (player.currentXCoord + player.widthOne < three[i].getXCoord() + 66 && player.currentXCoord + player.widthTwo > three[i].getXCoord() + 27 
            && player.currentYCoord < three[i].getYCoord() + 94 && player.currentYCoord + 94 > three[i].getYCoord()) {
            if (three[i].getHealth() > 0) {
                three[i].damage(3);
                player.health -= 3;
                isHealthUpdate = true;
            }
        }
        //ship 4
        if (player.currentXCoord + player.widthOne < four[i].getXCoord() + 87 && player.currentXCoord + player.widthTwo > four[i].getXCoord() + 6 
            && player.currentYCoord < four[i].getYCoord() + 94 && player.currentYCoord + 94 > four[i].getYCoord()) {
            if (four[i].getHealth() > 0) {
                four[i].damage(3);
                player.health -= 3;
                isHealthUpdate = true;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        //ship 5
        if (player.currentXCoord + player.widthOne < five[i].getXCoord() + 71 && player.currentXCoord + player.widthTwo > five[i].getXCoord() + 22 
            && player.currentYCoord < five[i].getYCoord() + 94 && player.currentYCoord + 94 > five[i].getYCoord()) {
            if (five[i].getHealth() > 0) {
                five[i].damage(3);
                player.health -= 3;
                isHealthUpdate = true;
            }
        }
        //ship 6
        if (player.currentXCoord + player.widthOne < six[i].getXCoord() + 81 && player.currentXCoord + player.widthTwo > six[i].getXCoord() + 12 
            && player.currentYCoord < six[i].getYCoord() + 94 && player.currentYCoord + 94 > six[i].getYCoord()) {
            if (six[i].getHealth() > 0) {
                six[i].damage(3);
                player.health -= 3;
                isHealthUpdate = true;
            }
        }
        //ship 7
        if (player.currentXCoord + player.widthOne < seven[i].getXCoord() + 86 && player.currentXCoord + player.widthTwo > seven[i].getXCoord() + 7 
            && player.currentYCoord < seven[i].getYCoord() + 94 && player.currentYCoord + 94 > seven[i].getYCoord()) {
            if (seven[i].getHealth() > 0) {
                seven[i].damage(3);
                player.health -= 3;
                isHealthUpdate = true;
            }
        }
        //ship 8
        if (player.currentXCoord + player.widthOne < eight[i].getXCoord() + 86 && player.currentXCoord + player.widthTwo > eight[i].getXCoord() + 6 
            && player.currentYCoord < eight[i].getYCoord() + 94 && player.currentYCoord + 94 > eight[i].getYCoord()) {
            if (eight[i].getHealth() > 0) {
                eight[i].damage(3);
                player.health -= 3;
                isHealthUpdate = true;
            }
        }
    }
    //ship 9
    if (player.currentXCoord + player.widthOne < nine.getXCoord() + 142 && player.currentXCoord + player.widthTwo > nine.getXCoord() 
        && player.currentYCoord < nine.getYCoord() + 240 && player.currentYCoord + 94 > nine.getYCoord()) {
        if (nine.getHealth() > 0) {
            nine.damage(3);
            player.health = 0;
            isHealthUpdate = true;
        }
    }
    //ship 10
    if (player.currentXCoord + player.widthOne < ten.getXCoord() + 150 && player.currentXCoord + player.widthTwo > ten.getXCoord() 
        && player.currentYCoord < ten.getYCoord() + 240 && player.currentYCoord + 94 > ten.getYCoord()) {
        if (ten.getHealth() > 0) {
            ten.damage(3);
            player.health = 0;
            isHealthUpdate = true;
        }
    }
}

int setEnemyExplosion(int ship) {
    const int i = counter.shipAction;
    int explosion;
    switch (ship) {
        case 1:
            explosion = one[i].getInstance();
            break;
        case 2:
            explosion = two[i].getInstance();
            break;
        case 3:
            explosion = three[i].getInstance();
            break;
        case 4:
            explosion = four[i].getInstance();
            break;
        case 5:
            explosion = five[i].getInstance();
            break;
        case 6:
            explosion = six[i].getInstance();
            break;
        case 7:
            explosion = seven[i].getInstance();
            break;
        case 8:
            explosion = eight[i].getInstance();
            break;
    }
    return explosion;
}

void enemyDied() {
    int explosion, image;
    for (int i = 1; i <= 4; i++) {
        for (counter.shipAction = 0; counter.shipAction < 10; counter.shipAction++) {
            bool used = false;
            for (int j = 0; j <= 8; j++) {
                if (counter.enemyExplosion[i - 1] == j && shipInAction(i) && !used) {
                    explosion = setEnemyExplosion(i);
                    char temp[] = "Images/Explosion_1.png";
                    temp[17] = char(j + 1 + '0');
                    image = ImageAdd(temp);
                    ViewSetImage(explosion, image);
                    counter.enemyExplosion[i - 1] += 1;
                    used = true;
                }
            }
            if (counter.enemyExplosion[i - 1] == 9 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_10.png");
                ViewSetImage(explosion, image);
                counter.enemyExplosion[i - 1] += 1;
            } else if (counter.enemyExplosion[i - 1] == 10 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_11.png");
                ViewSetImage(explosion, image);
                counter.enemyExplosion[i - 1] += 1;
            } else if (counter.enemyExplosion[i - 1] == 11 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                char tempShip[] = "Images/eShip_1.png";
                tempShip[13] = char(i + '0');
                image = ImageAdd(tempShip);
                ViewSetImage(explosion, image);
                if (i == 1) {
                    ViewSetxy(one[counter.shipAction].getInstance(), 600, 600);
                } else if (i == 2) {
                    ViewSetxy(two[counter.shipAction].getInstance(), 600, 600);
                } else if (i == 3) {
                    ViewSetxy(three[counter.shipAction].getInstance(), 600, 600);
                } else if (i == 4) {
                    ViewSetxy(four[counter.shipAction].getInstance(), 600, 600);
                }
                counter.enemyExplosion[i - 1] = 0;
                xp += XP_SHIP_DESTROY_1_TO_4 + round(level / XP_INCREASE);
            }
        }
    }

    for (int i = 5; i <= 8; i++) {
        for (counter.shipAction = 0; counter.shipAction < 5; counter.shipAction++) {
            bool used = false;
            for (int j = 0; j <= 8; j++) {
                if (counter.enemyExplosion[i - 1] == j && shipInAction(i) && !used) {
                    explosion = setEnemyExplosion(i);
                    char temp[] = "Images/Explosion_1.png";
                    temp[17] = char(j + 1 + '0');
                    image = ImageAdd(temp);
                    ViewSetImage(explosion, image);
                    counter.enemyExplosion[i - 1] += 1;
                    used = true;
                }
            }
            if (counter.enemyExplosion[i - 1] == 9 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_10.png");
                ViewSetImage(explosion, image);
                counter.enemyExplosion[i - 1] += 1;
            } else if (counter.enemyExplosion[i - 1] == 10 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                image = ImageAdd("Images/Explosion_11.png");
                ViewSetImage(explosion, image);
                counter.enemyExplosion[i - 1] += 1;
            } else if (counter.enemyExplosion[i - 1] == 11 && shipInAction(i)) {
                explosion = setEnemyExplosion(i);
                char tempShip[] = "Images/eShip_1.png";
                tempShip[13] = char(i + '0');
                image = ImageAdd(tempShip);
                ViewSetImage(explosion, image);
                if (i == 5) {
                    ViewSetxy(five[counter.shipAction].getInstance(), 600, 600);
                } else if (i == 6) {
                    ViewSetxy(six[counter.shipAction].getInstance(), 600, 600);
                } else if (i == 7) {
                    ViewSetxy(seven[counter.shipAction].getInstance(), 600, 600);
                } else if (i == 8) {
                    ViewSetxy(eight[counter.shipAction].getInstance(), 600, 600);
                }
                counter.enemyExplosion[i - 1] = 0;
                xp += XP_SHIP_DESTROY_5_TO_8 + round(level / XP_INCREASE);
            }
        }
    }

    bool used = false;
    for (int j = 0; j <= 8; j++) {
        if (counter.enemyExplosion[8] == j && shipInAction(9) && !used) {
            explosion = nine.getInstance();
            char temp[] = "Images/BigExplosion_1.png";
            temp[20] = char(j + 1 + '0');
            image = ImageAdd(temp);
            ViewSetImage(explosion, image);
            counter.enemyExplosion[8] += 1;
            used = true;
        }
    }
    if (counter.enemyExplosion[8] == 9 && shipInAction(9)) {
        explosion = nine.getInstance();
        image = ImageAdd("Images/BigExplosion_10.png");
        ViewSetImage(explosion, image);
        counter.enemyExplosion[8] += 1;
    } else if (counter.enemyExplosion[8] == 10 && shipInAction(9)) {
        explosion = nine.getInstance();
        image = ImageAdd("Images/BigExplosion_11.png");
        ViewSetImage(explosion, image);
        counter.enemyExplosion[8] += 1;
    } else if (counter.enemyExplosion[8] == 11 && shipInAction(9)) {
        explosion = nine.getInstance();
        image = ImageAdd("Images/eMini-Boss.png");
        ViewSetImage(explosion, image);
        ViewSetxy(nine.getInstance(), 600, 600);
        counter.enemyExplosion[8] = 0;
        xp += XP_SHIP_DESTROY_9 + round(2 * level / XP_INCREASE);
        if (currentScreen != SCREEN_STORY_BATTLE_4) {
            set += 1;
            counter.shipMove = 0;
            player.health = player.possibleHealth;
            isHealthUpdate = true;
        } else if (currentScreen == SCREEN_STORY_BATTLE_4) {
            currentScreen = SCREEN_STORY_5A1;
            screenSwitch();
        }
    }

    used = false;
    for (int j = 0; j <= 8; j++) {
        if (counter.enemyExplosion[9] == j && shipInAction(10) && !used) {
            explosion = ten.getInstance();
            char temp[] = "Images/BigExplosion_1.png";
            temp[20] = char(j + 1 + '0');
            image = ImageAdd(temp);
            ViewSetImage(explosion, image);
            counter.enemyExplosion[9] += 1;
            used = true;
        }
    }
    if (counter.enemyExplosion[9] == 9 && shipInAction(10)) {
        explosion = ten.getInstance();
        image = ImageAdd("Images/BigExplosion_10.png");
        ViewSetImage(explosion, image);
        counter.enemyExplosion[9] += 1;
    } else if (counter.enemyExplosion[9] == 10 && shipInAction(10)) {
        explosion = ten.getInstance();
        image = ImageAdd("Images/BigExplosion_11.png");
        ViewSetImage(explosion, image);
        counter.enemyExplosion[9] += 1;
    } else if (counter.enemyExplosion[9] == 11 && shipInAction(10)) {
        explosion = ten.getInstance();
        image = ImageAdd("Images/eBoss.png");
        ViewSetImage(explosion, image);
        ViewSetxy(ten.getInstance(), 600, 600);
        counter.enemyExplosion[9] = 0;
        xp += XP_SHIP_DESTROY_10 + round(2 * level / XP_INCREASE);
        if (currentScreen != SCREEN_STORY_BATTLE_6) {
            set += 1;
            counter.shipMove = 0;
            player.health = player.possibleHealth;
            isHealthUpdate = true;
        } else if (currentScreen == SCREEN_STORY_BATTLE_6) {
            currentScreen = SCREEN_STORY_7W1;
            screenSwitch();
        }
    }
}
