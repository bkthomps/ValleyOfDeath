/*
 * Functions which dictate what happens when the user causes an event to occur.
 */

#ifndef USER_EVENT_H
#define USER_EVENT_H

int onPause(int id, int event, int x, int y);
int onResume(int id, int event, int x, int y);
int onReturnToMenu(int id, int event, int x, int y);
int onDied(int id, int event, int x, int y);
int onTorture(int id, int event, int x, int y);

int onHighscore(int id, int event, int x, int y);
void doHighscore();
void doUpdateHighscore();

int onOptionsMenuTouch(int id, int event, int x, int y);
int options(int id, int event, int x, int y);

int onUnlocksMenuTouch(int id, int event, int x, int y);
int unlocks(int id, int event, int x, int y);

int onUnlocksMenuTouch(int id, int event, int x, int y);
int unlocks(int id, int event, int x, int y);
bool isShipUnlocked(int id);

int onEndlessMenuTouch(int id, int event, int x, int y);
int onBattleTouch(int id, int event, int x, int y);

#endif /* USER_EVENT_H */
