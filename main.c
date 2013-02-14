/*

Fichier : main.c

Auteur : Nicolle.B

Description : Page de démarage

Date : 01/10/2010

*/

#include "lib.h"


int main ( int argc, char *argv[]){

    char go; /*<--------------Lancement de partie */
	char nom_j[N]; /*<--------Nom du joueur */
    char table [20][60]; /*<--La Zone de jeu est de 20 en horizontale et 40 en vertical ( + 20 pour la partie droite ) */
    int  x = 3; /*<-----------Position d'origine du personnage en x */
    int  y = 1; /*<-----------Position d'origine du personnage en y */
    int  nom_ok = 0; /*<------Confirmation nom entré */

	affiche_banniere();

    /*Selection nom du joueur*/

    LIGHTCYAN;
    printf("\t\t\tJOUEUR : ");
    do{
        LIGHTRED;
        fgets(nom_j, sizeof nom_j, stdin); /* Scanf ne suffit pas car ne prend pas en compte espace et les "retour chariot" */
        if(nom_j[0]== '\n' || nom_j[0]== ' '){
            MessageBox(0,"Vous devez entrer votre nom de joueur\nErreur: nom absent ou invalide\nLe nom doit commencer par une lettre ou un chiffre","PAC-MAN Erreur",MB_OK|MB_ICONINFORMATION);
            nom_ok = 0;
            LIGHTRED;
            printf("\t\t\t\t%c ", arrow_r);
        }
        else{
            nom_ok = 1;
        }
    }while(nom_ok == 0);
    retour_c;

    /*Selection de la difficulté ou d'une option (Aide, quitter, score) */

    LIGHTCYAN;
    printf("\t 1 %c ", arrow_r);
    LIGHTRED;
    printf("FACILE\t\t\t"); /* Mode Facile */
    LIGHTCYAN;
    printf("S %c ",arrow_r);
    LIGHTRED;
    printf("Scores\n");     /* Option Afficher Score */
    LIGHTCYAN;
    printf("\t 2 %c ",arrow_r);
    LIGHTRED;
    printf("MOYEN \t\t\t"); /* Mode Moyen */
    LIGHTCYAN;
    printf("A %c ",arrow_r);
    LIGHTRED;
    printf("Aide\n");       /* Option Aide */
    LIGHTCYAN;
    printf("\t 3 %c ",arrow_r);
    LIGHTRED;
    printf("DIFFICILE \t\t\t"); /* Mode Difficile */
    LIGHTCYAN;
    printf("Q %c ",arrow_r);
    LIGHTRED;
    printf("Quitter\n");    /* Option Quitter */
    retour_c;
    LIGHTCYAN;
    printf("  S%clectionnez la difficult%c puis appuyez sur Entrer...\n",acc_aig,acc_aig);

    while (go != '1' || go != '2' || go != '3'){
        go = _getch();      /* Selection sans avoir besoin d'un appuie sur "Entrer" */

        if ((go >= '1') && (go <='3')){
            retour_c;
            if(go == '1'){  /* Si le joueur appuie sur 1 on affiche le mode choisi */
                printf("  Mode choisi %c ",arrow_r);
                LIGHTRED;
                printf("FACILE\n");}
            if(go == '2'){  /* Si le joueur appuie sur 2 on affiche le mode choisi */
                printf("  Mode choisi %c ",arrow_r);
                LIGHTRED;
                printf("MOYEN\n");}
            if(go == '3'){  /* Si le joueur appuie sur 3 on affiche le mode choisi */
                printf("  Mode choisi %c ", arrow_r);
                LIGHTRED;
                printf("DIFFICILE\n");}
        }
        else{               /* Si le joueur rentre un autre caractère que les choix 1, 2 ou 3 */
            if(go == 'Q'){  /* Si on appuie sur Q, on lance la message box*/
                if(MessageBox(0,"Etes vous sur de vouloir quitter le jeu?","PAC-MAN",MB_OUINON|MB_ICONSTOP)== IDOUI){
                    return 0; /* Si le joueur clic sur YES on renvoie IDYES donc on quitte */
                }
                else{         /* Autrement on rafraichissement de la page et on revien au début du jeu */
                    continue;
                }
                LIGHTCYAN;
            }
            if(go == 'A'){ /* Si on appuie sur A, on active l'aide la message box Aide s'affiche */
                if(MessageBox(0,"Vous devez selectionner le niveau de difficulté.\n\n   Tapez 1 pour le mode Facile : 4 fantômes\n   Tapez 2 pour le mode Moyen : 8 fantômes\n   Tapez 3 pour le mode Difficile : 12 fantômes\n   Tapez S afficher les scores\n   Tapez Q pour quitter le jeu","PAC-MAN Aide",MB_OK|MB_ICONQUESTION) == IDOK){
                    continue;
                }
            }
            if(go == 'S'){ /* Si on appuie sur S, on active l'affichage des scores alors on lance la page score */
                affichage_score();
            }
            else{          /* Si on appuie sur une touche autre que 1,2,3,x,A,Q ou S alors on doit recommencer */
                LIGHTCYAN;
                retour_c;
                printf("S%clection erron%ce, recommencez svp...\n",acc_aig,acc_aig);
            }
        }
        construction_arene(table,x,y,go);
        if(go == '1'){boucle_niv_1(table,x,y,nom_j,go);} /* Lancement du jeux niveau 1 (Facile) si le joueur a appuyé sur 1 */
        if(go == '2'){boucle_niv_2(table,x,y,nom_j,go);} /* Lancement du jeux niveau 2 (Moyen) si le joueur a appuyé sur 2 */
        if(go == '3'){boucle_niv_3(table,x,y,nom_j,go);} /* Lancement du jeux niveau 3 (Difficile) si le joueur a appuyé sur 3 */

    }
}
