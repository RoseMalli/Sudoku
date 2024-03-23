#include "programme.h"

const int TAILLE = 9;

int main(int argc, char * argv[]) {
    int puzzle_vide[TAILLE][TAILLE];
    int puzzle[TAILLE][TAILLE]; 
    memset(puzzle_vide, 0, sizeof(puzzle_vide));

    if(argc == 1) {
        printf("Résolution d'un puzzle de Sudoku\n\n");
        printf("Voici le puzzle aléatoire\n");
        generateur(puzzle_vide);
        solution(puzzle_vide);
    }

    if(argc == 2 && strcmp(argv[1], "-saisi") == 0) {
        printf("Résolution d'un puzzle de Sudoku\n\n");
        printf("Saisissez votre puzzle\n\n");
        for(int ligne = 0; ligne < TAILLE; ligne++) {
            for(int colonne = 0; colonne < TAILLE; colonne++) {
                scanf("%d", &puzzle[ligne][colonne]);
            }
        }
        printf("\nVoici le puzzle que vous avez saisi\n");
        solution(puzzle);
    }

    if(argc == 2 && strcmp(argv[1], "-saisi") != 0 || argc >= 3) {
        printf("Erreur de saisi.\n");
    }
    
    return 0;
}