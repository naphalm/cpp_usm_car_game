#ifndef GAME_OBJECTS_HPP
#define GAME_OBJECTS_HPP

// Variabile externe folosite pentru enemy cars positions
struct Car {
    char model[4][4]; // Masina
    int position;     // pozitia masinii pe ecran
};

struct Enemy {
    int x[3];   // Array storing the x-coordinates of enemies.
    int y[3];   // Array storing the y-coordinates of enemies.
    int flag[3]; // Flags indicating the status of each enemy.
};

Car GenPlayerCar();

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
