#include "DragonFireSDK.h"
#include "Ships.h"
#include "CustomMath.h"

const int ENEMY_BASE_HEALTH = 3;
const int ENEMY_INCREASE_HEALTH = 5;

const int ENEMY_9_BASE_HEALTH = 25;
const int ENEMY_10_BASE_HEALTH = 50;
const int ENEMY_BOSS_INCREASE_HEALTH = 3;

void Ship::setShip(int x, int y) {
    ViewSetxy(instance, x, y);
}

int Ship::getInstance() {
    return instance;
}

void Ship::setInstance(int instance) {
    Ship::instance = instance;
}

int Ship::getHealth() {
    return health;
}

void Ship::damage(int hpLossAmount) {
    health = (hpLossAmount >= health) ? (0) : (health - hpLossAmount);
}

void Ship::setXCoord(int x) {
    xCoord = x;
}

void Ship::setYCoord(int y) {
    yCoord = y;
}

int Ship::getXCoord() {
    return Ship::xCoord;
}

int Ship::getYCoord() {
    return Ship::yCoord;
}

void SingleShip::resetHealth(int level) {
    health = ENEMY_BASE_HEALTH + round(level / ENEMY_INCREASE_HEALTH);
}

void SingleShip::setBulletInstance(int index, int instance) {
    bullet[index] = instance;
}

void SingleShip::setBullet(int index, int x, int y) {
    ViewSetxy(SingleShip::bullet[index], x, y);
}

int SingleShip::getBullet(int index) {
    return bullet[index];
}

void DoubleShip::resetHealth(int level) {
    health = ENEMY_BASE_HEALTH + round(level / ENEMY_INCREASE_HEALTH);
}

void DoubleShip::setBulletOneInstance(int index, int instance) {
    bulletOne[index] = instance;
}

void DoubleShip::setBulletTwoInstance(int index, int instance) {
    bulletTwo[index] = instance;
}

void DoubleShip::setBulletOne(int index, int x, int y) {
    ViewSetxy(DoubleShip::bulletOne[index], x, y);
}

void DoubleShip::setBulletTwo(int index, int x, int y) {
    ViewSetxy(DoubleShip::bulletTwo[index], x, y);
}

int DoubleShip::getBulletOne(int index) {
    return bulletOne[index];
}

int DoubleShip::getBulletTwo(int index) {
    return bulletTwo[index];
}

void RocketShip::resetHealth(int level) {
    health = ENEMY_BASE_HEALTH + round(level / ENEMY_INCREASE_HEALTH);
}

void RocketShip::setRocketInstance(int index, int instance) {
    rocket[index] = instance;
}

void RocketShip::setRocket(int index, int x, int y) {
    ViewSetxy(RocketShip::rocket[index], x, y);
}

int RocketShip::getRocket(int index) {
    return rocket[index];
}

void TripleShip::setBulletOneInstance(int index, int instance) {
    bulletOne[index] = instance;
}

void TripleShip::setRocketInstance(int index, int instance) {
    rocket[index] = instance;
}

void TripleShip::setBulletTwoInstance(int index, int instance) {
    bulletTwo[index] = instance;
}

void TripleShip::setBulletOne(int index, int x, int y) {
    ViewSetxy(TripleShip::bulletOne[index], x, y);
}

void TripleShip::setRocket(int index, int x, int y) {
    ViewSetxy(TripleShip::rocket[index], x, y);
}

void TripleShip::setBulletTwo(int index, int x, int y) {
    ViewSetxy(TripleShip::bulletTwo[index], x, y);
}

int TripleShip::getBulletOne(int index) {
    return bulletOne[index];
}

int TripleShip::getRocket(int index) {
    return rocket[index];
}

int TripleShip::getBulletTwo(int index) {
    return bulletTwo[index];
}

void MasterShip::resetHealth(int level) {
    health = ENEMY_BASE_HEALTH + round(level / ENEMY_INCREASE_HEALTH);
}

void MiniBoss::resetHealth(int level) {
    health = ENEMY_9_BASE_HEALTH + round(level / ENEMY_BOSS_INCREASE_HEALTH);
}

void MasterBoss::resetHealth(int level) {
    health = ENEMY_10_BASE_HEALTH + round(level / ENEMY_BOSS_INCREASE_HEALTH);
}
