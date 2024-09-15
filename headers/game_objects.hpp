#ifndef GAME_OBJECTS_HPP
#define GAME_OBJECTS_HPP

// Variabile externe folosite pentru enemy cars positions
extern int enemyY[3];
extern int enemyX[3];
extern int enemyFlag[3];
extern char car[4][4];
extern int carPos;

// Genereaza enemy la pozitie random
void GenEnemy(int ind);

// Draw enemy pe ecran care are indexul(ind) specificat.
void DrawEnemy(int ind);

// Sterge enemy cu indexul specificat
void EraseEnemy(int ind);

// Reseteaza pozitia la enemy 
void ResetEnemy(int ind);

// Draw la Masina jucatorului
void DrawCar();

// Sterge masina jucatorului
void EraseCar();

#endif
