/*

Fichier : record_score.c

Auteur : Nicolle.B

Description : Enregistre le score en fin de partie dans un fichier score.txt

Date : 22/12/2010

*/

#include "lib.h"


void enregistrement_du_score(char nom_j[50], int score, char go, time_t t, int nb_point){

    FILE* fichier;
    fichier = fopen("score.txt", "a");              /* Ouverture du fichier score.txt */
    if (fichier != NULL){                           /* Si le fichier existe */
        fprintf(fichier, "  Joueur: %s", nom_j);    /* On écrit les différentes informations */
        fprintf(fichier, "  Score: %d\n", score);
        if(go == '1'){                              /* Si le joueur selectionne le niveau 1 */
            fprintf(fichier, "  Mode: FACILE\n");
            }
        if(go == '2'){                              /* Si le joueur selectionne le niveau 2 */
            fprintf(fichier, "  Mode: MOYEN\n");
            }
        if(go == '3'){                              /* Si le joueur selectionne le niveau 3 */
            fprintf(fichier, "  Mode: DIFFICILE\n");
            }
        fprintf(fichier, "  Nombre de points restants: %d\n", nb_point);
        fprintf(fichier, "  Le: %s\n", ctime(&t));
        fprintf(fichier, "-------------\n\n");
        fclose(fichier);                            /* Puis on ferme le fichier */
    }
}
