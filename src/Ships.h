#ifndef SHIPS_H
#define SHIPS_H

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
    int bullet[5];
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
    int bulletOne[5];
    int bulletTwo[5];
};

class RocketShip : public Ship {
public:
    void resetHealth(int level);
    void setRocketInstance(int index, int instance);
    void setRocket(int index, int x, int y);
    int getRocket(int index);
private:
    int rocket[5];
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
    int bulletOne[5];
    int rocket[5];
    int bulletTwo[5];
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
