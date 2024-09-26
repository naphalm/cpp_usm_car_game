#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

// Variabila externa pentru scor
extern int score;

// Checks collision dintre Masina jucatorului si Enemy 
bool Collision();

// Sfarsitul jocului
void GameOver();

// Update si afisarea scorului nou
void UpdateScore();

// Afiseaza instructiile pe ecran
void Instructions();

// Game Loop
void Play();

#endif
