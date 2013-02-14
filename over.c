/*

Fichier : over.c

Auteur : Nicolle.B

Description : Page de fin, Game Over

Date : 01/10/2010

*/

#include "lib.h"


void game_over(char nom_j[50], int score){

    int espace;
    char quit;

    system("CLS"); /* Rafraichissement de la page */
    retour_c;
    LIGHTBLUE;     /* Création de la bannière Game Over */
    for(espace=0;espace<75;espace++){printf("%c",bar_hor);}
    retour_c;
    YELLOW;
    printf("\t  ________");
    LIGHTRED;
    printf("    _____");
    LIGHTCYAN;
    printf("      _____");
    LIGHTMAGENTA;
    printf("  ___________  \n");
    YELLOW;
    printf("\t /  _____/");
    LIGHTRED;
    printf("   /  _  \\");
    LIGHTCYAN;
    printf("    /     \\");
    LIGHTMAGENTA;
    printf(" \\_   _____/  \n");
    YELLOW;
    printf("\t/   \\  ___");
    LIGHTRED;
    printf("  /  /_\\  \\");
    LIGHTCYAN;
    printf("  /  \\ /  \\");
    LIGHTMAGENTA;
    printf(" |    __)_   \n");
    YELLOW;
    printf("\t\\    \\_\\  \\");
    LIGHTRED;
    printf("/    |    \\");
    LIGHTCYAN;
    printf("/    Y    \\");
    LIGHTMAGENTA;
    printf("|        \\  \n");
    YELLOW;
    printf("\t \\______  /");
    LIGHTRED;
    printf("\\____|__  /");
    LIGHTCYAN;
    printf("\\____|__  /");
    LIGHTMAGENTA;
    printf("_______  /  \n");
    YELLOW;
    printf("\t        \\/         ");
    LIGHTRED;
    printf("\\/         ");
    LIGHTCYAN;
    printf("\\/        ");
    LIGHTMAGENTA;
    printf("\\/   \n");
    LIGHTMAGENTA;
    printf("\t________");
    LIGHTCYAN;
    printf("____   ____");
    LIGHTRED;
    printf("___________");
    YELLOW;
    printf("__________  ");
    LIGHTGREEN;
    printf("._.  \n");
    LIGHTMAGENTA;
    printf("\t\\_____  ");
    LIGHTCYAN;
    printf("\\   \\ /   /");
    LIGHTRED;
    printf("\\_   _____/");
    YELLOW;
    printf("\\______   \\ ");
    LIGHTGREEN;
    printf("| |  \n");
    LIGHTMAGENTA;
    printf("\t /   |   ");
    LIGHTCYAN;
    printf("\\   Y   /  ");
    LIGHTRED;
    printf("|    __)_  ");
    YELLOW;
    printf("|       _/ ");
    LIGHTGREEN;
    printf("| |  \n");
    LIGHTMAGENTA;
    printf("\t/    |    ");
    LIGHTCYAN;
    printf("\\     /   ");
    LIGHTRED;
    printf("|        \\ ");
    YELLOW;
    printf("|    |   \\  ");
    LIGHTGREEN;
    printf("\\|  \n");
    LIGHTMAGENTA;
    printf("\t\\_______  /");
    LIGHTCYAN;
    printf("\\___/   ");
    LIGHTRED;
    printf("/_______  / ");
    YELLOW;
    printf("|____|_  /  ");
    LIGHTGREEN;
    printf("__  \n");
    LIGHTMAGENTA;
    printf("\t        \\/                 ");
    LIGHTRED;
    printf("\\/         ");
    YELLOW;
    printf("\\/   ");
    LIGHTGREEN;
    printf("\\/  \n");
    LIGHTBLUE;
    for(espace=0;espace<75;espace++){printf("%c",bar_hor);}
    LIGHTCYAN;
    retour_c;
    retour_c;
    printf("\tBien jou%c ", acc_aig);
    LIGHTRED;
    printf("%s\n", nom_j);
    LIGHTCYAN;
    printf("\tVous avez fait un score de ");
    LIGHTRED;
    printf("%d ", score);
    LIGHTCYAN;
    printf("!!!\n\n");
    LIGHTCYAN;
    printf("\tTry Again... (Appuyez sur une touche pour continuer)");

    quit = _getch();
    if(quit >= '0' && quit <= 'z'){  /* Si le joueur appuie sur n'importe quelle touche de son clavier */
        if(MessageBox(0,"Retentez votre chance","PAC-MAN",MB_OK|MB_ICONINFORMATION)== IDOK){
            system("CLS");           /* Rafraichissement de la page */
            main();                  /* Alors on retourne sur la page principale */
        }
    }

    system("PAUSE");
    return 0;
}
