/*

Fichier : foot.c

Auteur : Nicolle.B

Description : Affichage du pied de console (temps de jeux, score, nom du joueur et nombre de point restant à "manger")

Date : 22/12/2010

*/

#include "lib.h"


void affichage_foot(char nom_j[50], int  score, int nb_point){

    clock_t temps; /* Chrono */

    srand(time(NULL));
    temps = clock();
    retour_c;
    LIGHTCYAN;
    printf("  Temps de jeu: ");
    LIGHTRED;
    printf("%0.fs ",(double)temps / CLOCKS_PER_SEC); /* Affichage du Chrono */
    LIGHTCYAN;
    printf(" Score: ");
    LIGHTRED;
    printf("%d ", score);    /* Affichage du Score */
    LIGHTCYAN;
    printf("  Points: ");
    LIGHTRED;
    printf("%d ", nb_point); /* Affichage du nombre de points restants */
    LIGHTCYAN;
    printf(" Joueur: ");
    LIGHTRED;
    printf("%s", nom_j);     /* Affichage du Nom du joueur, N caractères sont pris en comptes */

}
