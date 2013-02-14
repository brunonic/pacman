#ifndef SYMBOL_H_INCLUDED
#define SYMBOL_H_INCLUDED

/* Divers caractère */

#define cop     (char)0xB8 /* Copyright */
#define blanc_b (char)0xDC /* Demi bloc moitiée basse */
#define blanc_h (char)0xDF /* Demi bloc moitiée haute */
#define arrow_r (char)0x10 /* Fleche droite */
#define arrow_l (char)0x11 /* Fleche gauche */
#define arrow_t (char)0x1E /* Fleche haut */
#define arrow_b (char)0x1F /* Fleche bas */
#define losange (char)0x4  /* Fleche bas */
#define coin_hg (char)0xC9 /* Labyrinthe coin haut gauche */
#define coin_hd (char)0xBB /* Labyrinthe coin haut droit */
#define coin_bg (char)0xC8 /* Labyrinthe coin bas  gauche */
#define coin_bd (char)0xBC /* Labyrinthe coin bas  droit */
#define bar_hor (char)0xCD /* Labyrinthe barre  horizontale */
#define bar_ver (char)0xBA /* Labyrinthe barre  verticale */
#define T_gauche (char)0xB9/* T vers la  gauche */
#define T_droit (char)0xCC /* T vers la  droite */
#define T_bas   (char)0xCA /* T vers le  haut */
#define T_haut  (char)0xCB /* T vers le  bas */
#define blanc   (char)0xDB /* Bloc plein */
#define blanc_p (char)0xB2 /* Bloc plein pointillé */
#define blanc_p2 (char)0xB1/* Bloc plein pointillé */

/* Perso + fantômes */

#define perso  0x2  /* Représentation du personnage par une tête */
#define fant1  0xF  /* Représentation du fantome 1 */
#define fant2  0xF  /* Représentation du fantome 2 */
#define fant3  0xF  /* Représentation du fantome 3 */
#define fant4  0xF  /* Représentation du fantome 4 */
#define fant5  0xF  /* Représentation du fantome 5 */
#define fant6  0xF  /* Représentation du fantome 6 */
#define fant7  0xF  /* Représentation du fantome 7 */
#define fant8  0xF  /* Représentation du fantome 8 */
#define fant9  0xF  /* Représentation du fantome 9 */
#define fant10 0xF  /* Représentation du fantome 10 */
#define fant11 0xF  /* Représentation du fantome 11 */
#define fant12 0xF  /* Représentation du fantome 12 */
#define N_lvl1 4    /* Nombre de fantômes au niveau facile (Changer que si l'on rajoute des phantômes */
#define N_lvl2 8    /* Nombre de fantômes au niveau moyen (Changer que si l'on rajoute des phantômes */
#define N_lvl3 12   /* Nombre de fantômes au niveau difficile (Changer que si l'on rajoute des phantômes */

/* Divers options de jeux */

#define N_bonus  1000 /* Nombre de points bonus */
#define ybonus_1 18   /* Position verticale du bonus 1 */
#define xbonus_1 2    /* Position horizontale du bonus 1 */
#define ybonus_2 18   /* Position verticale du bonus 2 */
#define xbonus_2 37   /* Position horizontale du bonus 2v */
#define vide     0xB0 /* Bunus mangé = vide */

/* Traitement de texte */

#define N           10            /* Nombre de caractères pris en comptes pour saisie du nom */
#define retour_c    putchar('\n') /* Racourci retour chariot */
#define acc_aig     0x82          /* Caractère "é" */
#define acc_gra     0x8A          /* Caractère "è" */

/* Message Box en FR d'après winuser.h*/

#define MB_OKANNULER 1 /* #define MB_OKCANCEL 1 */
#define MB_OUINON 4 /* #define MB_YESNO 4 */
#define IDOUI 6     /* #define IDYES 6 */
#define IDNON 7     /* #define IDNO 7 */
#define IDANNULER 2 /* #define IDCANCEL 2 */


/* Couleur */

#define BLACK        textcolor(0)
#define BLUE         textcolor(1)
#define GREEN        textcolor(2)
#define CYAN         textcolor(3)
#define RED          textcolor(4)
#define MAGENTA      textcolor(5)
#define BROWN        textcolor(6)
#define LIGHTGRAY    textcolor(7)
#define DARKGRAY     textcolor(8)
#define LIGHTBLUE    textcolor(9)
#define LIGHTGREEN   textcolor(10)
#define LIGHTCYAN    textcolor(11)
#define LIGHTRED     textcolor(12)
#define LIGHTMAGENTA textcolor(13)
#define YELLOW       textcolor(14)
#define WHITE        textcolor(15)


#endif /* SYMBOL_H_INCLUDED */
