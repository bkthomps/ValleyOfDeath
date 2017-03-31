/*
 * Functions related to ship actions.
 */

#ifndef SHIP_ACTION
#define SHIP_ACTION

void doEnemyShipMove();
void enemyShipMove();
bool shipInAction(int ship);

void doEnemyShipShoot();
void bulletFirstShot();
void bulletHit();
bool isBulletHit(int xCoord, int yCoord);

void shipCollision();
bool isCollisionOne(int i);
bool isCollisionTwo(int i);
bool isCollisionThree(int i);
bool isCollisionFour(int i);
bool isCollisionFive(int i);
bool isCollisionSix(int i);
bool isCollisionSeven(int i);
bool isCollisionEight(int i);
bool isCollisionNine();
bool isCollisionTen();

int setEnemyExplosion(int ship);
void enemyDied();

#endif /* SHIP_ACTION */
