#ifndef FILE_IO_H
#define FILE_IO_H

int intFileToGame(char* buffer);
bool boolFileToGame(char* buffer);

void intGameToFile(int num, char* buffer);
void boolGameToFile(bool num, char* buffer);

void loadGame();
void loadSoundStatus();
void loadXp();
void loadShip();
void loadHighscore();
void loadSoundCounter();

#endif /* FILE_IO_H */
