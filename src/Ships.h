#ifndef SHIPS_H
#define SHIPS_H

const int PLAYER_BULLETS_PER_BULLET_TYPE = 15;
const int ENEMY_BULLETS_PER_BULLET_TYPE = 5;

struct PlayerShip {
    int typeOfShip;
    int instance;
    int speed;
    int health;
    int possibleHealth;

    int widthOne, widthTwo;

    int currentXCoord, currentYCoord;
    int newXCoord, newYCoord;

    int bulletOneOffsetXCoord, bulletOneOffsetYCoord;
    int rocketOffsetXCoord, rocketOffsetYCoord;
    int bulletTwoOffsetXCoord, bulletTwoOffsetYCoord;

    int bulletOne[PLAYER_BULLETS_PER_BULLET_TYPE];
    int rocket[PLAYER_BULLETS_PER_BULLET_TYPE];
    int bulletTwo[PLAYER_BULLETS_PER_BULLET_TYPE];
};

class Ship {
public:
    void setShip(int x, int y);
    int getInstance();
    void setInstance(int instance);
    void damage(int hpLossAmount);
    int getHealth();
    void setXCoord(int x);
    void setYCoord(int y);
    int getXCoord();
    int getYCoord();
protected:
    int instance;
    int health;
    int xCoord;
    int yCoord;
};

class SingleShip : public Ship {
public:
    void resetHealth(int level);
    void setBulletInstance(int index, int instance);
    void setBullet(int index, int x, int y);
    int getBullet(int index);
private:
    int bullet[ENEMY_BULLETS_PER_BULLET_TYPE];
};

class DoubleShip : public Ship {
public:
    void resetHealth(int level);
    void setBulletOneInstance(int index, int instance);
    void setBulletTwoInstance(int index, int instance);
    void setBulletOne(int index, int x, int y);
    void setBulletTwo(int index, int x, int y);
    int getBulletOne(int index);
    int getBulletTwo(int index);
private:
    int bulletOne[ENEMY_BULLETS_PER_BULLET_TYPE];
    int bulletTwo[ENEMY_BULLETS_PER_BULLET_TYPE];
};

class RocketShip : public Ship {
public:
    void resetHealth(int level);
    void setRocketInstance(int index, int instance);
    void setRocket(int index, int x, int y);
    int getRocket(int index);
private:
    int rocket[ENEMY_BULLETS_PER_BULLET_TYPE];
};

class TripleShip : public Ship {
public:
    void setBulletOneInstance(int index, int instance);
    void setRocketInstance(int index, int instance);
    void setBulletTwoInstance(int index, int instance);
    void setBulletOne(int index, int x, int y);
    void setRocket(int index, int x, int y);
    void setBulletTwo(int index, int x, int y);
    int getBulletOne(int index);
    int getRocket(int index);
    int getBulletTwo(int index);
private:
    int bulletOne[ENEMY_BULLETS_PER_BULLET_TYPE];
    int rocket[ENEMY_BULLETS_PER_BULLET_TYPE];
    int bulletTwo[ENEMY_BULLETS_PER_BULLET_TYPE];
};

class MasterShip : public TripleShip {
public:
    void resetHealth(int level);
};

class MiniBoss : public TripleShip {
public:
    void resetHealth(int level);
};

class MasterBoss : public TripleShip {
public:
    void resetHealth(int level);
};

#endif /* SHIPS_H */
