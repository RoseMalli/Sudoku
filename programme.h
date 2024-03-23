#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

const int TAILLE;
int random_lc();
int random_nombre();
void generateur(int puzzle_vide[TAILLE][TAILLE]);
void affichage(int puzzle[TAILLE][TAILLE]);
bool cases_vides(int puzzle[TAILLE][TAILLE], int* ligne, int* colonne);
bool verification_ligne(int puzzle[TAILLE][TAILLE], int ligne, int nombre);
bool verification_colonne(int puzzle[TAILLE][TAILLE], int colonne, int nombre);
bool verification_cadre(int puzzle[TAILLE][TAILLE], int ligne_cadre, int colonne_cadre, int nombre);
bool backtracking(int puzzle[TAILLE][TAILLE]);
void solution(int puzzle[TAILLE][TAILLE]);