#ifndef SHIP_ACTION
#define SHIP_ACTION

void doEnemyShipMove();
void enemyShipMove();
bool shipInAction(int ship);
void doEnemyShipShoot();
void shipCollision();
int setEnemyExplosion(int ship);
void enemyDied();

#endif /* SHIP_ACTION */
