/*

Fichier : Arene.c

Auteur : Nicolle.B

Description : Gestion de l'arene (Création de chaque partie de la matrice)

Date : 01/10/2010

*/

#include "lib.h"

void affiche (char A [20][60]){ /* Affiche toute la partie du jeux (Partie Gauche et Droite) */

    int  i , j;
    char color;

    for(i=0;i<20;i++){
		for(j=0;j<60;j++){
		    color = A[i][j];

            switch (color) {
                case perso:     /* Couleur du pacman */
                    YELLOW;
                    break;
                case '.':       /* Couleur des points */
                    WHITE;
                    break;
                case coin_bd:   /* Couleur de l'arene */
                case coin_bg:
                case coin_hd:
                case coin_hg:
                case bar_hor:
                case bar_ver:
                case T_gauche:
                case T_droit:
                case T_bas:
                case T_haut:
                    LIGHTBLUE;
                    break;
                case fant1:     /* Couleur de tous les phantômes */
                    LIGHTRED;
                    break;
                case 0x3:       /* Couleur du bonus (coeur) */
                case 0x6:       /* Couleur du bonus (pique) */
                    LIGHTMAGENTA;
                    break;
                case blanc:     /* Couleur du phantôme (dessin de droite) */
                case blanc_b:
                case blanc_h:
                    LIGHTMAGENTA;
                    break;
                case blanc_p:
                    WHITE;
                    break;
                case blanc_p2:
                    LIGHTCYAN;
                    break;
                case arrow_b:    /* Couleur des lettres et console (fleches) */
                case arrow_l:
                case arrow_r:
                case arrow_t:
                case losange:
                case 'Q':
                case 'A':
                case 'F':
                case 'C':
                case 'I':
                case 'L':
                case 'E':
                case 'D':
                case 'M':
                case 'O':
                case 'Y':
                case 'N':
                case 'P':
                case 'H':
                case 'T':
                case 'S':
                case '4':
                case '8':
                case '1':
                case '2':
                    LIGHTRED;
                    break;
                case '(':
                case ')':
                case 'q':
                case 'd':
                case 'z':
                case 's':
                case 'u':
                case 'i':
                case 't':
                case 'e':
                case 'r':
                case ':':
                case 'B':
                case 'o':
                case 'n':
                case 'a':
                    LIGHTGREEN;
                    break;
                default:        /* Couleur par défaut (donc du reste) */
                    BLACK;
            }
			printf("%c", color);
		}
		retour_c;
	}
}

void construction_arene (char table [20][60], int x, int y, char go){ /* Construction de la partie du jeux (Partie Gauche et Droite) */

    int i, j;

/* Init de l'arene vide */

    for (i=0;i<20;i++){
        for (j=0;j<60;j++){
            table[i][j] = ' ';
        }
    }

/* Bord du haut Arene */

	for (j=2;j<19;j++){
		table[0][j] = bar_hor;
	}
	table[0][19] = T_haut;
	for (j=20;j<38;j++){
		table[0][j] = bar_hor;
	}

/* Bord du haut partie droite */

    for (j=39;j<59;j++){
		table[0][j] = bar_hor;
	}

/* Bord du bas Arene */

    table[19][2]  = bar_hor;
    table[19][3]  = T_bas;
	for (j=4;j<13;j++){
		table[19][j] = bar_hor;
	}
    table[19][13]  = T_bas;
    for (j=14;j<25;j++){
		table[19][j] = bar_hor;
	}
	table[19][25]  = T_bas;
    for (j=26;j<36;j++){
		table[19][j] = bar_hor;
	}
	table[19][36]  = T_bas;
	table[19][37]  = bar_hor;

/* Bord du bas partie de droite */

    for (j=39;j<59;j++){
		table[19][j] = bar_hor;
	}

/* Bord gauche Arene */

	for (i=1;i<6;i++){
		for (j=1;j<2;j++){
            table[i][j] = bar_ver;
		}
	}
	table[6][1]  = T_droit;
	table[7][1]  = T_droit;
	table[8][1]  = bar_ver;
	table[9][1]  = T_droit;
	table[10][1] = bar_ver;
	table[11][1] = T_droit;
	for (i=12;i<15;i++){
		for (j=1;j<2;j++){
            table[i][j] = bar_ver;
		}
	}
	table[15][1] = T_droit;
	for (i=16;i<19;i++){
		for (j=1;j<2;j++){
            table[i][j] = bar_ver;
		}
	}

/* Bord de droite Arene */

	for (i=1;i<6;i++){
		table[i][38] = bar_ver;
	}
    table[6][38]  = T_gauche;
	table[7][38]  = T_gauche;
	table[8][38]  = bar_ver;
	table[9][38]  = T_gauche;
	table[10][38] = bar_ver;
	table[11][38] = T_gauche;
	for (i=12;i<13;i++){
        table[i][38] = bar_ver;
	}
	table[13][38] = T_gauche;
	table[14][38] = bar_ver;
	table[15][38] = T_gauche;
	for (i=16;i<19;i++){
        table[i][38] = bar_ver;
	}

/* Bord de droite partie de droite */

    for (i=0;i<19;i++){
        table[i][59] = bar_ver;
	}

/* Coin des bords de l'arene et de la partie de droite*/

    table[0][1]   = coin_hg;
    table[19][1]  = coin_bg;
    table[19][59] = coin_bd;
    table[0][38]  = T_haut;
    table[0][59]  = coin_hd;
    table[19][38] = T_bas;

 /* Interieur : Remplissage de petits points */

	for (i=1;i<19;i++){
		for (j=2;j<38;j++){
			table[i][j] = '.';

            /* Décor intérieur (Arene de jeux) */

			/* Ligne 1 */
			table[1][19] = bar_ver;

			/* Ligne 2 */
			table[2][3]  = coin_hg;     table[2][4]  = bar_hor;     table[2][5]  = bar_hor;     table[2][6]  = bar_hor;     table[2][7]  = bar_hor;     table[2][8]  = coin_hd;
			table[2][10] = coin_hg;     table[2][11] = bar_hor;     table[2][12] = bar_hor;     table[2][13] = bar_hor;     table[2][14] = bar_hor;     table[2][15] = bar_hor;
			table[2][16] = bar_hor;     table[2][17] = coin_hd;     table[2][19] = bar_ver;     table[2][21] = coin_hg;     table[2][22] = bar_hor;     table[2][23] = bar_hor;
			table[2][24] = bar_hor;     table[2][25] = bar_hor;     table[2][26] = bar_hor;     table[2][27] = bar_hor;     table[2][28] = coin_hd;     table[2][30] = coin_hg;
			table[2][31] = bar_hor;     table[2][32] = bar_hor;     table[2][33] = bar_hor;     table[2][34] = bar_hor;     table[2][35] = bar_hor;     table[2][36] = coin_hd;

			/* Ligne 3 */
			table[3][3]  = bar_ver;     table[3][4]  = ' ';         table[3][5]  = ' ';         table[3][6]  = ' ';         table[3][7]  = ' ';         table[3][8]  = bar_ver;
			table[3][10] = bar_ver;     table[3][11] = ' ';         table[3][12] = ' ';         table[3][13] = ' ';         table[3][14] = ' ';         table[3][15] =  ' ';
			table[3][16] = ' ';         table[3][17] = bar_ver;     table[3][19] = bar_ver;     table[3][21] = bar_ver;     table[3][22] = ' ';         table[3][23] = ' ';
			table[3][24] = ' ';         table[3][25] = ' ';         table[3][26] = ' ';         table[3][27] = ' ';         table[3][28] = bar_ver;     table[3][30] = bar_ver;
			table[3][31] = ' ';         table[3][32] = ' ';         table[3][33] = ' ';         table[3][34] = ' ';         table[3][35] = ' ';         table[3][36] = bar_ver;

			/* Ligne 4 */
			table[4][3]  = coin_bg;     table[4][4]  = bar_hor;     table[4][5]  = bar_hor;     table[4][6]  = bar_hor;     table[4][7]  = bar_hor;     table[4][8]  = coin_bd;
			table[4][10] = coin_bg;     table[4][11] = bar_hor;     table[4][12] = bar_hor;     table[4][13] = bar_hor;     table[4][14] = bar_hor;     table[4][15] = bar_hor;
			table[4][16] = bar_hor;     table[4][17] = coin_bd;     table[4][19] = bar_ver;     table[4][21] = coin_bg;     table[4][22] = bar_hor;     table[4][23] = bar_hor;
			table[4][24] = bar_hor;     table[4][25] = bar_hor;     table[4][26] = bar_hor;     table[4][27] = bar_hor;     table[4][28] = coin_bd;     table[4][30] = coin_bg;
			table[4][31] = bar_hor;     table[4][32] = bar_hor;     table[4][33] = bar_hor;     table[4][34] = bar_hor;     table[4][35] = bar_hor;     table[4][36] = coin_bd;

			/* Ligne 6 */
			table[6][2]  = bar_hor;     table[6][3]  = bar_hor;     table[6][4]  = bar_hor;     table[6][5]  = bar_hor;     table[6][6]  = bar_hor;     table[6][7]  = bar_hor;
			table[6][8]  = coin_hd;     table[6][10] = bar_ver;     table[6][12] = bar_hor;     table[6][13] = bar_hor;     table[6][14] = bar_hor;     table[6][15] = bar_hor;
			table[6][16] = bar_hor;     table[6][17] = bar_hor;     table[6][18] = bar_hor;     table[6][19] = T_haut;      table[6][20] = bar_hor;     table[6][21] = bar_hor;
			table[6][22] = bar_hor;     table[6][23] = bar_hor;     table[6][24] = bar_hor;     table[6][25] = bar_hor;     table[6][26] = bar_hor;     table[6][28] = bar_ver;
			table[6][30] = coin_hg;     table[6][31] = bar_hor;     table[6][32] = bar_hor;     table[6][33] = bar_hor;     table[6][34] = bar_hor;     table[6][35] = bar_hor;
			table[6][36] = bar_hor;     table[6][37] = bar_hor;

			/* Ligne 7 */
			table[7][2]  = bar_hor;     table[7][3]  = bar_hor;     table[7][4]  = bar_hor;     table[7][5]  = bar_hor;     table[7][6]  = bar_hor;     table[7][7]  = bar_hor;
			table[7][8]  = coin_bd;     table[7][10] = bar_ver;     table[7][19] = bar_ver;     table[7][28] = bar_ver;     table[7][30] = coin_bg;     table[7][31] = bar_hor;
			table[7][32] = bar_hor;     table[7][33] = bar_hor;     table[7][34] = bar_hor;     table[7][35] = bar_hor;     table[7][36] = bar_hor;     table[7][37] = bar_hor;

			/* Ligne 8 */
			table[8][10] = T_droit;     table[8][11] = bar_hor;     table[8][11] = bar_hor;     table[8][12] = bar_hor;     table[8][13] = bar_hor;     table[8][14] = bar_hor;
			table[8][15] = bar_hor;     table[8][16] = bar_hor;     table[8][17] = bar_hor;     table[8][19] = bar_ver;     table[8][21] = bar_hor;     table[8][22] = bar_hor;
			table[8][23] = bar_hor;     table[8][24] = bar_hor;     table[8][25] = bar_hor;     table[8][26] = bar_hor;     table[8][27] = bar_hor;     table[8][28] = T_gauche;

			/* Ligne 9 */
			table[9][2]  = bar_hor;     table[9][3]  = bar_hor;     table[9][4]  = bar_hor;     table[9][5]  = bar_hor;     table[9][6]  = bar_hor;     table[9][7]  = bar_hor;
			table[9][8]  = coin_hd;     table[9][10] = bar_ver;     table[9][19] = bar_ver;     table[9][28] = bar_ver;     table[9][30] = coin_hg;     table[9][31] = bar_hor;
			table[9][32] = bar_hor;     table[9][33] = bar_hor;     table[9][34] = bar_hor;     table[9][35] = bar_hor;     table[9][36] = bar_hor;     table[9][37] = bar_hor;

			/* Ligne 10 */
			table[10][2]  = ' ';        table[10][3]  = ' ';        table[10][4]  = ' ';        table[10][5]  = ' ';        table[10][6]  = ' ';        table[10][7]  = ' ';
			table[10][8]  = bar_ver;    table[10][12] = bar_hor;    table[10][13] = bar_hor;    table[10][14] = bar_hor;    table[10][15] = bar_hor;    table[10][16] = bar_hor;
			table[10][17] = bar_hor;    table[10][18] = bar_hor;    table[10][19] = T_bas;      table[10][20] = bar_hor;    table[10][21] = bar_hor;    table[10][22] = bar_hor;
			table[10][23] = bar_hor;    table[10][24] = bar_hor;    table[10][25] = bar_hor;    table[10][26] = bar_hor;    table[10][30] = bar_ver;    table[10][31] = ' ';
			table[10][32] = ' ';        table[10][33] = ' ';        table[10][34] = ' ';        table[10][35] = ' ';        table[10][36] = ' ';        table[10][37] = ' ';

			/* Ligne 11 */
			table[11][2]  = bar_hor;    table[11][3]  = bar_hor;    table[11][4]  = bar_hor;    table[11][5]  = bar_hor;    table[11][6]  = bar_hor;    table[11][7]  = bar_hor;
			table[11][8]  = coin_bd;    table[11][10] = bar_ver;    table[11][28] = bar_ver;    table[11][30] = coin_bg;    table[11][31] = bar_hor;    table[11][32] = bar_hor;
			table[11][33] = bar_hor;    table[11][34] = bar_hor;    table[11][35] = bar_hor;    table[11][36] = bar_hor;    table[11][37] = bar_hor;

			/* Ligne 12 */
			table[12][10] = bar_ver;    table[12][12] = coin_hg;    table[12][13] = coin_hd;    table[12][15] = coin_hg;    table[12][16] = bar_hor;    table[12][17] = bar_hor;
            table[12][18] = bar_hor;    table[12][20] = bar_hor;    table[12][21] = bar_hor;    table[12][22] = bar_hor;    table[12][23] = coin_hd;    table[12][25] = coin_hg;
            table[12][26] = coin_hd;    table[12][28] = bar_ver;

			/* Ligne 13 */
			table[13][3]  = bar_hor;    table[13][4]  = bar_hor;    table[13][5]  = bar_hor;    table[13][6]  = coin_hd;    table[13][8]  = bar_hor;    table[13][9]  = bar_hor;
			table[13][10] = coin_bd;    table[13][12] = coin_bg;    table[13][13] = coin_bd;    table[13][15] = bar_ver;    table[13][23] = bar_ver;    table[13][25] = coin_bg;
			table[13][26] = coin_bd;    table[13][28] = bar_ver;    table[13][30] = bar_hor;    table[13][31] = bar_hor;    table[13][32] = bar_hor;    table[13][33] = bar_hor;
			table[13][34] = bar_hor;    table[13][35] = bar_hor;    table[13][36] = bar_hor;    table[13][37] = bar_hor;

			/* ligne 14 */
			table[14][6]  = bar_ver;    table[14][15] = coin_bg;    table[14][16] = bar_hor;    table[14][17] = bar_hor;    table[14][19] = bar_hor;    table[14][20] = bar_hor;
			table[14][21] = bar_hor;    table[14][22] = bar_hor;    table[14][23] = coin_bd;

			/* Ligne 15 */
			table[15][2]  = bar_hor;    table[15][3]  = bar_hor;    table[15][4]  = bar_hor;    table[15][6]  = bar_ver;    table[15][8]  = coin_hg;    table[15][9]  = bar_hor;
			table[15][10] = bar_hor;    table[15][11] = bar_hor;    table[15][12] = bar_hor;    table[15][13] = bar_hor;    table[15][25] = bar_hor;    table[15][26] = bar_hor;
			table[15][27] = bar_hor;    table[15][28] = bar_hor;    table[15][29] = bar_hor;    table[15][30] = bar_hor;    table[15][31] = coin_hd;    table[15][33] = bar_hor;
			table[15][34] = bar_hor;    table[15][35] = bar_hor;    table[15][36] = bar_hor;    table[15][37] = bar_hor;

			/* Ligne 16 */
			table[16][8]  = bar_ver;    table[16][15] = coin_hg;    table[16][16] = bar_hor;    table[16][17] = bar_hor;    table[16][18] = bar_hor;    table[16][19] = bar_hor;
			table[16][20] = bar_hor;    table[16][21] = bar_hor;    table[16][22] = bar_hor;    table[16][23] = coin_hd;    table[16][31] = bar_ver;

			/* Ligne 17 */
			table[17][3]  = coin_hg;    table[17][4]  = bar_hor;    table[17][5]  = bar_hor;    table[17][6]  = bar_hor;    table[17][7]  = bar_hor;    table[17][8]  = T_bas;
			table[17][9]  = bar_hor;    table[17][10] = bar_hor;    table[17][11] = bar_hor;    table[17][12] = bar_hor;    table[17][13] = coin_hd;    table[17][15] = coin_bg;
			table[17][16] = bar_hor;    table[17][17] = bar_hor;    table[17][18] = bar_hor;    table[17][19] = bar_hor;    table[17][20] = bar_hor;    table[17][21] = bar_hor;
			table[17][22] = bar_hor;    table[17][23] = coin_bd;    table[17][25] = coin_hg;    table[17][26] = bar_hor;    table[17][27] = bar_hor;    table[17][28] = bar_hor;
			table[17][28] = bar_hor;    table[17][29] = bar_hor;    table[17][30] = bar_hor;    table[17][31] = T_bas;      table[17][32] = bar_hor;    table[17][33] = bar_hor;
			table[17][34] = bar_hor;    table[17][35] = bar_hor;    table[17][36] = coin_hd;

			/* Ligne 18 */
			table[18][3]  = bar_ver;    table[18][4]  = ' ';        table[18][5]  = ' ';        table[18][6]  = ' ';        table[18][7]  = ' ';        table[18][8]  = ' ';
			table[18][9]  = ' ';        table[18][10] = ' ';        table[18][11] = ' ';        table[18][12] = ' ';        table[18][13] = bar_ver;    table[18][25] = bar_ver;
			table[18][26] = ' ';        table[18][27] = ' ';        table[18][28] = ' ';        table[18][29] = ' ';        table[18][30] = ' ';        table[18][31] = ' ';
			table[18][32] = ' ';        table[18][33] = ' ';        table[18][34] = ' ';        table[18][35] = ' ';        table[18][36] = bar_ver;

/* *******************PARTIE DROITE DU JEUX (MENU,DESSIN,CONSOLE)**************************** */

            /* Options */

			 /* Ligne 1 - Bonus */
            table[1][51]  = 'B';       table[1][52]  = 'o';       table[1][53]  = 'n';       table[1][54]  = 'u';       table[1][55]  = 's';
            table[1][56]  = ':';       table[1][57]  = 0x3;       table[1][58]  = 0x6;

            /* Dessin Phantôme */

			/* Ligne 4 */
            table[4][47]  = blanc_b;   table[4][48]  = blanc_b;   table[4][49]  = blanc;     table[4][50]  = blanc;     table[4][51]  = blanc;
            table[4][52]  = blanc_b;   table[4][53]  = blanc_b;

			/* Ligne 5 */
            table[5][45]  = blanc_b;   table[5][46]  = blanc;     table[5][47]  = blanc;     table[5][48]  = blanc;     table[5][49]  = blanc;
            table[5][50]  = blanc;     table[5][51]  = blanc;     table[5][52]  = blanc;     table[5][53]  = blanc;     table[5][54]  = blanc_b;

			/* Ligne 6 */
            table[6][45]  = blanc;     table[6][46]  = blanc_p;   table[6][47]  = blanc_p;   table[6][48]  = blanc_p;   table[6][49]  = blanc;
            table[6][50]  = blanc;     table[6][51]  = blanc_p;   table[6][52]  = blanc_p;   table[6][53]  = blanc_p;   table[6][54]  = blanc;

			/* Ligne 7 */
            table[7][45]  = blanc;     table[7][46]  = blanc_p;   table[7][47]  = blanc_p;   table[7][48]  = blanc_p2;  table[7][49]  = blanc;
            table[7][50]  = blanc;     table[7][51]  = blanc_p;   table[7][52]  = blanc_p;   table[7][53]  = blanc_p2;  table[7][54]  = blanc;

			/* Ligne 8 */
            table[8][44]  = blanc;     table[8][45]  = blanc;     table[8][46]  = blanc;     table[8][47]  = blanc;     table[8][48]  = blanc;
            table[8][49]  = blanc;     table[8][50]  = blanc;     table[8][51]  = blanc;     table[8][52]  = blanc;     table[8][53]  = blanc;
            table[8][54]  = blanc;

			/* Ligne 9 */
            table[9][43]  = blanc;     table[9][44]  = blanc;     table[9][45]  = blanc;     table[9][46]  = blanc;     table[9][47]  = blanc;
            table[9][48]  = blanc;     table[9][49]  = blanc;     table[9][50]  = blanc;     table[9][51]  = blanc;     table[9][52]  = blanc;
            table[9][53]  = blanc;     table[9][54]  = blanc;     table[9][55]  = blanc;

			/* Ligne 10 */
            table[10][43] = blanc;     table[10][44] = blanc_h;   table[10][46] = blanc_h;   table[10][47] = blanc;     table[10][48] = blanc;
            table[10][50] = blanc;     table[10][51] = blanc;     table[10][52] = blanc_h;   table[10][54] = blanc_h;   table[10][55] = blanc;

            /* Affichage de la console */

			/* Ligne 12 */
            table[12][49]  = 'z';

			/* ligne 13 */
			table[13][48]  = '(';      table[13][49]  = arrow_t;   table[13][50]  = ')';

			/* Ligne 14 */
            table[14][45]  = 'q';      table[14][46]  = '(';       table[14][47]  = arrow_l;  table[14][48]  = ')';      table[14][49]  = losange;
            table[14][50]  = '(';      table[14][51]  = arrow_r;   table[14][52]  = ')';      table[14][53]  = ')d';

			/* Ligne 15 */
			table[15][48]  = '(';      table[15][49]  = arrow_b;   table[15][50]  = ')';

			/* Ligne 16 */
			table[16][49]  = 's';

            /* Ligne 18 - Quitter */
            table[18][39]  = 'a';       table[18][40]  = 'i';       table[18][41]  = 'd';       table[18][42]  = 'e';    table[18][43]  = ':';
            table[18][44]  = 'A';

            /* Ligne 18 - Quitter */
            table[18][50]  = 'q';       table[18][51]  = 'u';       table[18][52]  = 'i';       table[18][53]  = 't';       table[18][54]  = 't';
            table[18][55]  = 'e';       table[18][56]  = 'r';       table[18][57]  = ':';       table[18][58]  = 'Q';

/* ****************************************************************************************** */
		}
	}

    /* Affichage du niveau selectionné dans le module de droite ainsi que le nombre de phantômes */
    if(go == '1'){
        table[1][39] = 'F'; table[1][40] = 'A'; table[1][41] = 'C'; table[1][42] = 'I'; table[1][43] = 'L'; table[1][44] = 'E';
        table[2][39] = '4'; table[2][40] = 0xF;
    }
    if(go == '2'){
        table[1][39] = 'M'; table[1][40] = 'O'; table[1][41] = 'Y'; table[1][42] = 'E'; table[1][43] = 'N';
        table[2][39] = '8'; table[2][40] = 0xF;
    }
    if(go == '3'){
        table[1][39] = 'D'; table[1][40] = 'I'; table[1][41] = 'F'; table[1][42] = 'F'; table[1][43] = 'I'; table[1][44] = 'C';
        table[1][45] = 'I'; table[1][46] = 'L'; table[1][47] = 'E';
        table[2][39] = '1'; table[2][40] = '2'; table[2][41] = 0xF;
    }
}
