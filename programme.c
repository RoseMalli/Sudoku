#include "programme.h"

int random_lc() {
    int lc = rand() % 9;
    return lc;
}

int random_nombre() {
    int nombre = (rand() % 9) + 1;
    return nombre;
}

void generateur(int puzzle_vide[TAILLE][TAILLE]) {
    int ligne, colonne, nombre, compteur = 0;
    srand(time(NULL));
    do {
        ligne = random_lc();
        colonne = random_lc();
        nombre = random_nombre();
        if(!verification_ligne(puzzle_vide, ligne, nombre) && !verification_colonne(puzzle_vide, colonne, nombre) && !verification_cadre(puzzle_vide, (ligne - ligne%3), (colonne - colonne%3), nombre)) {
            puzzle_vide[ligne][colonne] = nombre;
            compteur++;
        }
    } while(compteur < 21);
}

void affichage(int puzzle[TAILLE][TAILLE]) {
    int ligne, colonne;
    for(ligne = 0; ligne < TAILLE; ligne++) {
        printf("-------------------------------------");
        printf("\n");
        printf("|");
        for(colonne = 0; colonne < TAILLE; colonne++) {
            printf(" %d |", puzzle[ligne][colonne]);
        }
        printf("\n");
    }
    printf("-------------------------------------");
} 

bool cases_vides(int puzzle[TAILLE][TAILLE], int* ligne, int* colonne) {
    for((*ligne) = 0; (*ligne) < TAILLE; (*ligne)++) {
        for((*colonne) = 0; (*colonne) < TAILLE; (*colonne)++) {
            if(puzzle[(*ligne)][(*colonne)] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool verification_ligne(int puzzle[TAILLE][TAILLE], int ligne, int nombre) {
    for(int colonne = 0; colonne < TAILLE; colonne++) {
        if(puzzle[ligne][colonne] == nombre) {
            return true;
        }
    }
    return false;
}

bool verification_colonne(int puzzle[TAILLE][TAILLE], int colonne, int nombre) {
    for(int ligne = 0; ligne < TAILLE; ligne++) {
        if(puzzle[ligne][colonne] == nombre) {
            return true;
        }
    }
    return false;
}

bool verification_cadre(int puzzle[TAILLE][TAILLE], int ligne_cadre, int colonne_cadre, int nombre) {
    for(int ligne = 0; ligne < 3; ligne++) {
        for(int colonne = 0; colonne < 3; colonne++) {
            if(puzzle[ligne + ligne_cadre][colonne + colonne_cadre] == nombre) {
                return true;
            }
        }
    }
    return false;
}

bool backtracking(int puzzle[TAILLE][TAILLE]) {
    int ligne, colonne;
    if(!cases_vides(puzzle, &ligne, &colonne)) {
        return true;
    }
    for(int nombre = 1; nombre <= TAILLE; nombre++) {
        if(!verification_ligne(puzzle, ligne, nombre) && !verification_colonne(puzzle, colonne, nombre) && !verification_cadre(puzzle, (ligne - ligne%3), (colonne - colonne%3), nombre)) {
            puzzle[ligne][colonne] = nombre;
            if(backtracking(puzzle)) {
                return true;
            }
            puzzle[ligne][colonne] = 0;
        }
    }
    return false;
}

void solution(int puzzle[TAILLE][TAILLE]) {
    affichage(puzzle);
    if(backtracking(puzzle)) {
        printf("\n\nVoici le puzzle résolu\n");
        affichage(puzzle);
        printf("\n");
    }
    else {
        printf("\nErreur! Pas de solution\n");
    }
}