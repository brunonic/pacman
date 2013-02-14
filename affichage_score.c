/*

Fichier : affichage_score.c

Auteur : Nicolle.B

Description : Afficher le fichier score.txt

Date : 25/12/2010

*/

#include "lib.h"

void affichage_score(){

    char retour;

    system("CLS");          /* On rafraichi la page */
    LIGHTRED;
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";

    fichier = fopen("score.txt", "r");

    if (fichier != NULL)    /* Si le fichier score.txt existe */
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) /* On lit le fichier tant qu'il y a un caractère */
        {
            printf("%s", chaine); /* On affiche le caractère lu */
        }
        fclose(fichier);          /* On ferme le fichier */
    }

    retour = _getch();
    if(retour == 'R'){            /* Si le joueur appuie  sur R */
        if(MessageBox(0,"Vous allez être redirigé vers le menu principal","PAC-MAN",MB_OKANNULER|MB_ICONINFORMATION)== IDOK){
            system("CLS");        /* Rafraichissement de la page */
            main();               /* Si le joueur appuie sur OK on revien au menu principal */
        }
        if(MessageBox(0,"Vous allez être redirigé vers le menu principal","PAC-MAN",MB_OKANNULER|MB_ICONINFORMATION)== IDANNULER){
            affichage_score();    /* Si le joueur appuie sur ANNULER on reste sur la page score */
        }
    }
}
