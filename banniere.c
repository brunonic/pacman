/*

Fichier : baniere.c

Auteur : Nicolle.B

Description : Affichage de la banniere d'accueil (PAC MAN)

Date : 01/10/2010

*/

#include "lib.h"


void affiche_banniere(){

        int espace;

        for(espace=0;espace<75;espace++){
            GREEN;
            printf("%c",blanc_b);
            }
        retour_c;
        for(espace=0;espace<75;espace++){
            LIGHTBLUE;
            printf("%c",bar_hor);
            }
        retour_c;
        YELLOW;
        printf("   _____");
        LIGHTRED;
        printf("   ______");
        LIGHTBLUE;
        printf("   ____");
        LIGHTGREEN;
        printf("         _   _");
        LIGHTCYAN;
        printf("  ______");
        YELLOW;
        printf("  __  __\n");
        YELLOW;
        printf("  /\\  _ `\\");
        LIGHTRED;
        printf("/\\  _  \\");
        LIGHTBLUE;
        printf("/\\  _ `\\");
        LIGHTGREEN;
        printf("      /'\\_/`\\");
        LIGHTCYAN;;
        printf("/\\  _  \\");
        YELLOW;
        printf("/\\ \\/\\ \\ \n");
        YELLOW;
        printf("  \\ \\ \\L\\ \\");
        LIGHTRED;
        printf(" \\ \\L\\ \\");
        LIGHTBLUE;
        printf(" \\ \\/\\_\\");
        LIGHTGREEN;
        printf("    /\\      \\");
        LIGHTCYAN;;
        printf(" \\ \\L\\ \\");
        YELLOW;
        printf(" \\ `\\\\ \\ \n");
        YELLOW;
        printf("   \\ \\ ,__/");
        LIGHTRED;
        printf("\\ \\  __ \\");
        LIGHTBLUE;
        printf(" \\ \\/_/_");
        LIGHTGREEN;
        printf("   \\ \\ \\__\\ \\");
        LIGHTCYAN;;
        printf(" \\  __ \\");
        YELLOW;
        printf(" \\ , ` \\  \n");
        YELLOW;
        printf("    \\ \\ \\/");
        LIGHTRED;
        printf("  \\ \\ \\/\\ \\");
        LIGHTBLUE;
        printf(" \\ \\L\\ \\");
        LIGHTGREEN;
        printf("   \\ \\ \\_/\\ \\");
        LIGHTCYAN;;
        printf(" \\ \\/\\ \\");
        YELLOW;
        printf(" \\ \\`\\ \\  \n");
        YELLOW;
        printf("     \\ \\_\\");
        LIGHTRED;
        printf("   \\ \\_\\ \\_\\");
        LIGHTBLUE;
        printf(" \\____/");
        LIGHTGREEN;
        printf("    \\ \\_\\\\ \\_\\");
        LIGHTCYAN;;
        printf(" \\_\\ \\_\\");
        YELLOW;
        printf(" \\_\\ \\_\\ \n");
        YELLOW;
        printf("      \\/_/");
        LIGHTRED;
        printf("    \\/_/\\/_/");
        LIGHTBLUE;
        printf("\\/___/");
        LIGHTGREEN;
        printf("      \\/_/ \\/_/");
        LIGHTCYAN;;
        printf("\\/_/\\/_/");
        YELLOW;
        printf("\\/_/\\/_/  \n");
        for(espace=0;espace<40;espace++){
            printf(" ");
            }
        DARKGRAY;
        printf("Projet-C by B.Nic%c\n",cop);
        for(espace=0;espace<75;espace++){
            LIGHTBLUE;
            printf("%c",bar_hor);
            }
        retour_c;
        for(espace=0;espace<75;espace++){
            GREEN;
            printf("%c",blanc_h);
            }
        retour_c;
}
