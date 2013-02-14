/*

Fichier : deplace_niv_3.c

Auteur : Nicolle.B

Description : Gestion du deplacement du personnage et de la boucle mode DIFFICILE

Date : 01/10/2010

*/

#include "lib.h"


void boucle_niv_3(arene table, int x, int y, char nom_j[50], char go){

    time_t t = time(NULL);
    char temp; /*<-----------------Permet de garder une valeur temporairement */
    char orientation_perso ; /*<---Orientation du personnage en x,y */
    char bonus_1 = 0x3; /*<--------Bonus 1 de N_bonus points */
    char bonus_2 = 0x6; /*<--------Bonus 2 de N_bonus points */
    int score = 0 ; /*<------------Score du Joueur */
    int s;  /*<--------------------Rand de s pour le déplacement "Aléatoir" du(des) fantôme(s) */
    int ok; /*<--------------------ok=1 le fantôme bouge */
    int yfant1 = 9;  /*<-----------Postion verticale   du fantôme 1 */
    int xfant1 = 13; /*<-----------Postion horizontale du fantôme 1 */
    int yfant2 = 5;  /*<-----------Postion verticale   du fantôme 2 */
    int xfant2 = 18; /*<-----------Postion horizontale du fantôme 2 */
    int yfant3 = 14; /*<-----------Postion verticale   du fantôme 3 */
    int xfant3 = 36; /*<-----------Postion horizontale du fantôme 3 */
    int yfant4 = 13; /*<-----------Postion verticale   du fantôme 4 */
    int xfant4 = 20; /*<-----------Postion horizontale du fantôme 4 */
    int yfant5 = 18; /*<-----------Postion verticale   du fantôme 5 */
    int xfant5 = 2;  /*<-----------Postion horizontale du fantôme 5 */
    int yfant6 = 9;  /*<-----------Postion verticale   du fantôme 6 */
    int xfant6 = 25; /*<-----------Postion horizontale du fantôme 6 */
    int yfant7 = 8;  /*<-----------Postion verticale   du fantôme 7 */
    int xfant7 = 5;  /*<-----------Postion horizontale du fantôme 7 */
    int yfant8 = 2;  /*<-----------Postion verticale   du fantôme 8 */
    int xfant8 = 37; /*<-----------Postion horizontale du fantôme 8 */
    int yfant9 = 8;  /*<-----------Postion verticale   du fantôme 9 */
    int xfant9 = 37; /*<-----------Postion horizontale du fantôme 9 */
    int yfant10 = 12;/*<-----------Postion verticale   du fantôme 10 */
    int xfant10 = 3; /*<-----------Postion horizontale du fantôme 10 */
    int yfant11 = 18;/*<-----------Postion verticale   du fantôme 11 */
    int xfant11 = 24;/*<-----------Postion horizontale du fantôme 11 */
    int yfant12 = 18;/*<-----------Postion verticale   du fantôme 12 */
    int xfant12 = 14;/*<-----------Postion horizontale du fantôme 12 */
    int nb_point_max = 0;/*<-------Nombre de points présents dans le jeux au démarrage */
    int nb_point = 0; /*<----------Nombre de points restants dans le jeux en cours */
    int i,j;

    while(i!=60){   /* On compte le nombre de points présent dans l'arène en début de jeu */
        for(i=0; i<60; i++){
            for(j=0; j<20; j++){
                if(table[j][i] == '.'){
                    nb_point_max++;
                }
            }
        }
    }

    nb_point = nb_point_max + 13; /* On ajoute 9 (Personnage + 8 fantômes qui cachent les points en début de jeux */

    while (1){

        if(nb_point == 0){        /* Si il ne reste plus de point donc nb_point vaut 0, alors on termine le jeu et on lance la page de fin */
            game_over(nom_j,score);
        }

        affichage_foot(nom_j,score,nb_point);   /* On affiche le pied de page */

        orientation_perso = _getch(); /* Selection de l'orientation sans appuyer sur "Entrer" */

        switch (orientation_perso){   /* Switch qui gère le déplacement du personnage (haut, bas, gauche et droite) */

            case 's' :      /* Deplacement vers le bas */
                if(table[y+1][x] == '.' || table[y+1][x] == ' ' || table[y+1][x] == 0x6 || table[y+1][x] == 0x3){ /* Si le prochain char est un point, un vide ou un bonus */
                    y++;    /* Alors on avance */
                    if(table[y][x] == '.'){
                        score = score + 10; /* Et on augmente le score si on mange un point */
                        nb_point--;         /* On diminue de 1 le nombre de points restants */
                    }
                    if(table[y][x] == ' '){
                        score = score - 5;  /* Puis on diminue le score si on ne mange pas de point (bond dans le vide */
                    }
                    if(table[y][x] == bonus_1){
                        score = score + N_bonus; bonus_1 = vide;        /* Puis on augmente le score si on mange un bonus 1, le bonus lui, disparait et devient un vide */
                        if(table[1][57] == 0x3 && table[1][58] == 0x6){ /* Si le bonus pique est encore là, on enlève le bonus coeur en haut à droite et on met le pique a sa place */
                             table[1][57] = 0x6;
                             table[1][58] = ' ';
                        }
                        if(table[1][57] == 0x3 && table[1][58] == ' '){ /* Si le bonus pique n'est plus là, on enlève juste le bonus coeur en haut à droite */
                             table[1][57] = ' ';
                        }
                    }
                    if(table[y][x] == 0x6){
                        score = score + N_bonus; bonus_2 = vide; /* Puis on augmente le score si on mange un bonus 2, le bonus lui, disparait et devient un vide */
                        if(table[1][58] == 0x6){ /* On enlève juste le bonus pique en haut à droite */
                             table[1][58] = ' ';
                        }
                        if(table[y][x] == ' '){
                        score = score - 5;       /* Et on diminue le score si on mange pas de point */
                        }
                    }
                    table[y-1][x] = ' ';
                    if(table[7][46] == blanc_p){ /* On fait bouger l'oeil gauche du phantôme (de droite à gauche) */
                        table[7][46]  = blanc_p2;
                        table[7][48]  = blanc_p;}
                    if(table[7][51] == blanc_p){ /* On fait bouger l'oeil droit du phantôme (de droite à gauche) */
                        table[7][51]  = blanc_p2;
                        table[7][53]  = blanc_p;}
                }
                break;

            case 'z' :   /* Deplacment vers le haut */
                if(table[y-1][x] == '.' || table[y-1][x] == ' '){
                    y--; /* Alors on avance */
                    if(table[y][x] == '.'){
                        score = score + 10;
                        nb_point--;
                    }
                    if(table[y][x] == ' '){
                        score = score - 5;  /* Et on diminue le score si on mange pas de point */
                    }
                    table[y+1][x] = ' ';
                    if(table[7][46] == blanc_p2){ /* On fait bouger l'oeil gauche du fantôme (de gauche à droite) */
                        table[7][46]  = blanc_p;
                        table[7][48]  = blanc_p2;}
                    if(table[7][51] == blanc_p2){ /* On fait bouger l'oeil droit du fantôme (de gauche à droite) */
                        table[7][51]  = blanc_p;
                        table[7][53]  = blanc_p2;}
                }
                break;

            case 'q' :   /* Deplacmeent vers la gauche */
                if(table[y][x-1] == '.' || table[y][x-1] == ' '){
                    x--; /* Alors on avance */
                    if(table[y][x] == '.'){
                        score = score + 10; /* Et on augmente le score si on mange un point */
                        nb_point--;
                    }
                    if(table[y][x] == ' '){
                        score = score - 5;  /* Et on diminue le score si on mange pas de point */
                    }
                    table[y][x+1] = ' ';
                    if(table[7][46] == blanc_p){ /* On fait bouger l'oeil gauche du fantôme (de droite à gauche) */
                        table[7][46]  = blanc_p2;
                        table[7][48]  = blanc_p;}
                    if(table[7][51] == blanc_p){ /* On fait bouger l'oeil droit du fantôme (de droite à gauche) */
                        table[7][51]  = blanc_p2;
                        table[7][53]  = blanc_p;}
                }
                break;

            case 'd' :   /* Deplacement vers la droite */
                if(table[y][x+1] == '.' || table[y][x+1] == ' '){
                    x++; /* Alors on avance */
                    if(table[y][x] == '.'){
                        score = score + 10; /* Et on augmente le score si on mange un point */
                        nb_point--;
                    }
                    if(table[y][x] == ' '){
                        score = score - 5;  /* Et on diminue le score si on mange pas de point */
                    }
                    table[y][x-1] = ' ';
                    if(table[7][46] == blanc_p2){ /* On fait bouger l'oeil gauche du fantôme (de gauche à droite) */
                        table[7][46]  = blanc_p;
                        table[7][48]  = blanc_p2;}
                    if(table[7][51] == blanc_p2){ /* On fait bouger l'oeil droit du fantôme (de gauche à droite) */
                        table[7][51]  = blanc_p;
                        table[7][53]  = blanc_p2;}
                }
                break;

            case 'Q' : /* Changer de difficulter ou quitter */
                return 0;
                break;

            case 'A' : /* Aide */
                MessageBox(0,"Touches : \n\n   - Avancer : 'z'\n   - Reculer : 's'\n   - Aller à gauche : 'q'\n   - Aller à droite : 'd'\n\nRègles du jeux :\n\n   - Vous devez \"manger\" les points en vous déplaçant tout en évitant\n      les fantômes. Le but étant d'obtenir le score le plus élevé possible.\n   - 1 point attrapé vaut 10 points.\n   - 1 mouvement dans le vide retire 5 points.","PAC-MAN Aide",MB_OK|MB_ICONQUESTION);
                break;

            default : /* Erreur */
                printf("Erreur de selection\n" );
                break;
        }   /* End of Switch */

        do{ /* Deplacement Aléatoir du fantôme 1 */
            s=rand()%4; /* Random de le résultat entre 0 et 3 */
            switch (s){
                case 0: /* deplacement vers la droite */    /* Si la case suivant vaut un point, un vide ou le personnage */
                    if(table[yfant1][xfant1+1] == '.' || table[yfant1][xfant1+1] == ' ' || table[yfant1][xfant1+1] == 0xF){
                        temp = table[yfant1][xfant1+1];     /* On met la valeur de la case suivante dans une variable temporaire (temp) */
                        xfant1++;                           /* Puis le fantôme ce déplace */
                        if(temp == 0xF){
                            table[yfant1][xfant1-1] = '.';
                        }
                        else{
                            table[yfant1][xfant1-1] = temp; /* Si la case suivante valait un vide alors, on remet le vide, si c'était un point, on remet le point... */
                        }
                        ok=1;                               /* Alors ok=1 donc on sort de la boucle */
                    }
                    else{
                        ok=0;                               /* Si ok=0 alors on reste dans la boucle et on relance un rand jusqu'à ce que le fantôme bouge */
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant1][xfant1-1] == '.' || table[yfant1][xfant1-1] == ' ' || table[yfant1][xfant1-1] == 0xF){
                        temp = table[yfant1][xfant1-1];
                        xfant1--;
                        if(temp == 0xF){
                            table[yfant1][xfant1+1] = '.';
                        }
                        else{
                            table[yfant1][xfant1+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant1+1][xfant1] == '.' || table[yfant1+1][xfant1] == ' ' || table[yfant1+1][xfant1] == 0xF){
                        temp = table[yfant1+1][xfant1];
                        yfant1++;
                        if(temp == 0xF){
                            table[yfant1-1][xfant1] = '.';
                        }
                        else{
                            table[yfant1-1][xfant1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant1-1][xfant1] == '.' || table[yfant1-1][xfant1] == ' ' || table[yfant1-1][xfant1] == 0xF){
                        temp = table[yfant1-1][xfant1];
                        yfant1--;
                        if(temp == 0xF){
                            table[yfant1+1][xfant1] = '.';
                        }
                        else{
                            table[yfant1+1][xfant1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        do{ /* Deplacement Aléatoir du fantôme 2 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant2][xfant2+1] == '.' || table[yfant2][xfant2+1] == ' ' || table[yfant2][xfant2+1] == 0xF){
                        temp = table[yfant2][xfant2+1];
                        xfant2++;
                        if(temp == 0xF){
                            table[yfant2][xfant2-1] = '.';
                        }
                        else{
                            table[yfant2][xfant2-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant2][xfant2-1] == '.' || table[yfant2][xfant2-1] == ' ' || table[yfant2][xfant2-1] == 0xF){
                        temp = table[yfant2][xfant2-1];
                        xfant2--;
                        if(temp == 0xF){
                            table[yfant2][xfant2+1] = '.';
                        }
                        else{
                            table[yfant2][xfant2+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant2+1][xfant2] == '.' || table[yfant2+1][xfant2] == ' ' || table[yfant2+1][xfant2] == 0xF){
                        temp = table[yfant2+1][xfant2];
                        yfant2++;
                        if(temp == 0xF){
                            table[yfant2-1][xfant2] = '.';
                        }
                        else{
                            table[yfant2-1][xfant2] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant2-1][xfant2] == '.' || table[yfant2-1][xfant2] == ' ' || table[yfant2-1][xfant2] == 0xF){
                        temp = table[yfant2-1][xfant2];
                        yfant2--;
                        if(temp == 0xF){
                            table[yfant2+1][xfant2] = '.';
                        }
                        else{
                            table[yfant2+1][xfant2] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        do{ /* Deplacement Aléatoir du fantôme 3 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant3][xfant3+1] == '.' || table[yfant3][xfant3+1] == ' ' || table[yfant3][xfant3+1] == 0xF){
                        temp = table[yfant3][xfant3+1];
                        xfant3++;
                        if(temp == 0xF){
                            table[yfant3][xfant3-1] = '.';
                        }
                        else{
                            table[yfant3][xfant3-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant3][xfant3-1] == '.' || table[yfant3][xfant3-1] == ' ' || table[yfant3][xfant3-1] == 0xF){
                        temp = table[yfant3][xfant3-1];
                        xfant3--;
                        if(temp == 0xF){
                            table[yfant3][xfant3+1] = '.';
                        }
                        else{
                            table[yfant3][xfant3+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant3+1][xfant3] == '.' || table[yfant3+1][xfant3] == ' ' || table[yfant3+1][xfant3] == 0xF){
                        temp = table[yfant3+1][xfant3];
                        yfant3++;
                        if(temp == 0xF){
                            table[yfant3-1][xfant3] = '.';
                        }
                        else{
                            table[yfant3-1][xfant3] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant3-1][xfant3] == '.' || table[yfant3-1][xfant3] == ' ' || table[yfant3-1][xfant3] == 0xF){
                        temp = table[yfant3-1][xfant3];
                        yfant3--;
                        if(temp == 0xF){
                            table[yfant3+1][xfant3] = '.';
                        }
                        else{
                            table[yfant3+1][xfant3] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        do{ /* Deplacement Aléatoir du fantôme 4 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant4][xfant4+1] == '.' || table[yfant4][xfant4+1] == ' ' || table[yfant4][xfant4+1] == 0xF){
                        temp = table[yfant4][xfant4+1];
                        xfant4++;
                        if(temp == 0xF){
                            table[yfant4][xfant4-1] = '.';
                        }
                        else{
                            table[yfant4][xfant4-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant4][xfant4-1] == '.' || table[yfant4][xfant4-1] == ' ' || table[yfant4][xfant4-1] == 0xF){
                        temp = table[yfant4][xfant4-1];
                        xfant4--;
                        if(temp == 0xF){
                            table[yfant4][xfant4+1] = '.';
                        }
                        else{
                            table[yfant4][xfant4+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant4+1][xfant4] == '.' || table[yfant4+1][xfant4] == ' ' || table[yfant4+1][xfant4] == 0xF){
                        temp = table[yfant4+1][xfant4];
                        yfant4++;
                        if(temp == 0xF){
                            table[yfant4-1][xfant4] = '.';
                        }
                        else{
                            table[yfant4-1][xfant4] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant4-1][xfant4] == '.' || table[yfant4-1][xfant4] == ' ' || table[yfant4-1][xfant4] == 0xF){
                        temp = table[yfant4-1][xfant4];
                        yfant4--;
                        if(temp == 0xF){
                            table[yfant4+1][xfant4] = '.';
                        }
                        else{
                            table[yfant4+1][xfant4] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        do{ /* Deplacement Aléatoir du fantôme 5 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant5][xfant5+1] == '.' || table[yfant5][xfant5+1] == ' ' || table[yfant5][xfant5+1] == 0xF){
                        temp = table[yfant5][xfant5+1];
                        xfant5++;
                        if(temp == 0xF){
                            table[yfant5][xfant5-1] = '.';
                        }
                        else{
                            table[yfant5][xfant5-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant5][xfant5-1] == '.' || table[yfant5][xfant5-1] == ' ' || table[yfant5][xfant5-1] == 0xF){
                        temp = table[yfant5][xfant5-1];
                        xfant5--;
                        if(temp == 0xF){
                            table[yfant5][xfant5+1] = '.';
                        }
                        else{
                            table[yfant5][xfant5+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant5+1][xfant5] == '.' || table[yfant5+1][xfant5] == ' ' || table[yfant5+1][xfant5] == 0xF){
                        temp = table[yfant5+1][xfant5];
                        yfant5++;
                        if(temp == 0xF){
                            table[yfant5-1][xfant5] = '.';
                        }
                        else{
                            table[yfant5-1][xfant5] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant5-1][xfant5] == '.' || table[yfant5-1][xfant5] == ' ' || table[yfant5-1][xfant5] == 0xF){
                        temp = table[yfant5-1][xfant5];
                        yfant5--;
                        if(temp == 0xF){
                            table[yfant5+1][xfant5] = '.';
                        }
                        else{
                            table[yfant5+1][xfant5] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        do{ /* Deplacement Aléatoir du fantôme 6 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant6][xfant6+1] == '.' || table[yfant6][xfant6+1] == ' ' || table[yfant6][xfant6+1] == 0xF){
                        temp = table[yfant6][xfant6+1];
                        xfant6++;
                        if(temp == 0xF){
                            table[yfant6][xfant6-1] = '.';
                        }
                        else{
                            table[yfant6][xfant6-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant6][xfant6-1] == '.' || table[yfant6][xfant6-1] == ' ' || table[yfant6][xfant6-1] == 0xF){
                        temp = table[yfant6][xfant6-1];
                        xfant6--;
                        if(temp == 0xF){
                            table[yfant6][xfant6+1] = '.';
                        }
                        else{
                            table[yfant6][xfant6+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant6+1][xfant6] == '.' || table[yfant6+1][xfant6] == ' ' || table[yfant6+1][xfant6] == 0xF){
                        temp = table[yfant6+1][xfant6];
                        yfant6++;
                        if(temp == 0xF){
                            table[yfant6-1][xfant6] = '.';
                        }
                        else{
                            table[yfant6-1][xfant6] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant6-1][xfant6] == '.' || table[yfant6-1][xfant6] == ' ' || table[yfant6-1][xfant6] == 0xF){
                        temp = table[yfant6-1][xfant6];
                        yfant6--;
                        if(temp == 0xF){
                            table[yfant6+1][xfant6] = '.';
                        }
                        else{
                            table[yfant6+1][xfant6] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        do{ /* Deplacement Aléatoir du fantôme 7 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant7][xfant7+1] == '.' || table[yfant7][xfant7+1] == ' ' || table[yfant7][xfant7+1] == 0xF){
                        temp = table[yfant7][xfant7+1];
                        xfant7++;
                        if(temp == 0xF){
                            table[yfant7][xfant7-1] = '.';
                        }
                        else{
                            table[yfant7][xfant7-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant7][xfant7-1] == '.' || table[yfant7][xfant7-1] == ' ' || table[yfant7][xfant7-1] == 0xF){
                        temp = table[yfant7][xfant7-1];
                        xfant7--;
                        if(temp == 0xF){
                            table[yfant7][xfant7+1] = '.';
                        }
                        else{
                            table[yfant7][xfant7+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant7+1][xfant7] == '.' || table[yfant7+1][xfant7] == ' ' || table[yfant7+1][xfant7] == 0xF){
                        temp = table[yfant7+1][xfant7];
                        yfant7++;
                        if(temp == 0xF){
                            table[yfant7-1][xfant7] = '.';
                        }
                        else{
                            table[yfant7-1][xfant7] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant7-1][xfant7] == '.' || table[yfant7-1][xfant7] == ' ' || table[yfant7-1][xfant7] == 0xF){
                        temp = table[yfant7-1][xfant7];
                        yfant7--;
                        if(temp == 0xF){
                            table[yfant7+1][xfant7] = '.';
                        }
                        else{
                            table[yfant7+1][xfant7] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        do{ /* Deplacement Aléatoir du fantôme 8 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant8][xfant8+1] == '.' || table[yfant8][xfant8+1] == ' ' || table[yfant8][xfant8+1] == 0xF){
                        temp = table[yfant8][xfant8+1];
                        xfant8++;
                        if(temp == 0xF){
                            table[yfant8][xfant8-1] = '.';
                        }
                        else{
                            table[yfant8][xfant8-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant8][xfant8-1] == '.' || table[yfant8][xfant8-1] == ' ' || table[yfant8][xfant8-1] == 0xF){
                        temp = table[yfant8][xfant8-1];
                        xfant8--;
                        if(temp == 0xF){
                            table[yfant8][xfant8+1] = '.';
                        }
                        else{
                            table[yfant8][xfant8+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant8+1][xfant8] == '.' || table[yfant8+1][xfant8] == ' ' || table[yfant8+1][xfant8] == 0xF){
                        temp = table[yfant8+1][xfant8];
                        yfant8++;
                        if(temp == 0xF){
                            table[yfant8-1][xfant8] = '.';
                        }
                        else{
                            table[yfant8-1][xfant8] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant8-1][xfant8] == '.' || table[yfant8-1][xfant8] == ' ' || table[yfant8-1][xfant8] == 0xF){
                        temp = table[yfant8-1][xfant8];
                        yfant8--;
                        if(temp == 0xF){
                            table[yfant8+1][xfant8] = '.';
                        }
                        else{
                            table[yfant8+1][xfant8] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);


        do{ /* Deplacement Aléatoir du fantôme 9 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant9][xfant9+1] == '.' || table[yfant9][xfant9+1] == ' ' || table[yfant9][xfant9+1] == 0xF){
                        temp = table[yfant9][xfant9+1];
                        xfant9++;
                        if(temp == 0xF){
                            table[yfant9][xfant9-1] = '.';
                        }
                        else{
                            table[yfant9][xfant9-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant9][xfant9-1] == '.' || table[yfant9][xfant9-1] == ' ' || table[yfant9][xfant9-1] == 0xF){
                        temp = table[yfant9][xfant9-1];
                        xfant9--;
                        if(temp == 0xF){
                            table[yfant9][xfant9+1] = '.';
                        }
                        else{
                            table[yfant9][xfant9+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant9+1][xfant9] == '.' || table[yfant9+1][xfant9] == ' ' || table[yfant9+1][xfant9] == 0xF){
                        temp = table[yfant9+1][xfant9];
                        yfant9++;
                        if(temp == 0xF){
                            table[yfant9-1][xfant9] = '.';
                        }
                        else{
                            table[yfant9-1][xfant9] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant9-1][xfant9] == '.' || table[yfant9-1][xfant9] == ' ' || table[yfant9-1][xfant9] == 0xF){
                        temp = table[yfant9-1][xfant9];
                        yfant9--;
                        if(temp == 0xF){
                            table[yfant9+1][xfant9] = '.';
                        }
                        else{
                            table[yfant9+1][xfant9] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        do{ /* Deplacement Aléatoir du fantôme 10 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant10][xfant10+1] == '.' || table[yfant10][xfant10+1] == ' ' || table[yfant10][xfant10+1] == 0xF){
                        temp = table[yfant10][xfant10+1];
                        xfant10++;
                        if(temp == 0xF){
                            table[yfant10][xfant10-1] = '.';
                        }
                        else{
                            table[yfant10][xfant10-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant10][xfant10-1] == '.' || table[yfant10][xfant10-1] == ' ' || table[yfant10][xfant10-1] == 0xF){
                        temp = table[yfant10][xfant10-1];
                        xfant10--;
                        if(temp == 0xF){
                            table[yfant10][xfant10+1] = '.';
                        }
                        else{
                            table[yfant10][xfant10+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant10+1][xfant10] == '.' || table[yfant10+1][xfant10] == ' ' || table[yfant10+1][xfant10] == 0xF){
                        temp = table[yfant10+1][xfant10];
                        yfant10++;
                        if(temp == 0xF){
                            table[yfant10-1][xfant10] = '.';
                        }
                        else{
                            table[yfant10-1][xfant10] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant10-1][xfant10] == '.' || table[yfant10-1][xfant10] == ' ' || table[yfant10-1][xfant10] == 0xF){
                        temp = table[yfant10-1][xfant10];
                        yfant10--;
                        if(temp == 0xF){
                            table[yfant10+1][xfant10] = '.';
                        }
                        else{
                            table[yfant10+1][xfant10] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        do{ /* Deplacement Aléatoir du fantôme 11 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant11][xfant11+1] == '.' || table[yfant11][xfant11+1] == ' ' || table[yfant11][xfant11+1] == 0xF){
                        temp = table[yfant11][xfant11+1];
                        xfant11++;
                        if(temp == 0xF){
                            table[yfant11][xfant11-1] = '.';
                        }
                        else{
                            table[yfant11][xfant11-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant11][xfant11-1] == '.' || table[yfant11][xfant11-1] == ' ' || table[yfant11][xfant11-1] == 0xF){
                        temp = table[yfant11][xfant11-1];
                        xfant11--;
                        if(temp == 0xF){
                            table[yfant11][xfant11+1] = '.';
                        }
                        else{
                            table[yfant11][xfant11+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant11+1][xfant11] == '.' || table[yfant11+1][xfant11] == ' ' || table[yfant11+1][xfant11] == 0xF){
                        temp = table[yfant11+1][xfant11];
                        yfant11++;
                        if(temp == 0xF){
                            table[yfant11-1][xfant11] = '.';
                        }
                        else{
                            table[yfant11-1][xfant11] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant11-1][xfant11] == '.' || table[yfant11-1][xfant11] == ' ' || table[yfant11-1][xfant11] == 0xF){
                        temp = table[yfant11-1][xfant11];
                        yfant11--;
                        if(temp == 0xF){
                            table[yfant11+1][xfant11] = '.';
                        }
                        else{
                            table[yfant11+1][xfant11] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        do{ /* Deplacement Aléatoir du fantôme 12 */
            s=rand()%4;
            switch (s){
                case 0: /* deplacement vers la droite */
                    if(table[yfant12][xfant12+1] == '.' || table[yfant12][xfant12+1] == ' ' || table[yfant12][xfant12+1] == 0xF){
                        temp = table[yfant12][xfant12+1];
                        xfant12++;
                        if(temp == 0xF){
                            table[yfant12][xfant12-1] = '.';
                        }
                        else{
                            table[yfant12][xfant12-1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 1: /* deplacement vers la gauche */
                    if(table[yfant12][xfant12-1] == '.' || table[yfant12][xfant12-1] == ' ' || table[yfant12][xfant12-1] == 0xF){
                        temp = table[yfant12][xfant12-1];
                        xfant12--;
                        if(temp == 0xF){
                            table[yfant12][xfant12+1] = '.';
                        }
                        else{
                            table[yfant12][xfant12+1] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 2: /* deplacement vers le bas */
                    if(table[yfant12+1][xfant12] == '.' || table[yfant12+1][xfant12] == ' ' || table[yfant12+1][xfant12] == 0xF){
                        temp = table[yfant12+1][xfant12];
                        yfant12++;
                        if(temp == 0xF){
                            table[yfant12-1][xfant12] = '.';
                        }
                        else{
                            table[yfant12-1][xfant12] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
                case 3: /* deplacement vers le haut */
                    if(table[yfant12-1][xfant12] == '.' || table[yfant12-1][xfant12] == ' ' || table[yfant12-1][xfant12] == 0xF){
                        temp = table[yfant12-1][xfant12];
                        yfant12--;
                        if(temp == 0xF){
                            table[yfant12+1][xfant12] = '.';
                        }
                        else{
                            table[yfant12+1][xfant12] = temp;
                        }
                        ok=1;
                    }
                    else{
                        ok=0;
                    }
                    break;
            } /* End of switch */
        }while(ok!=1);

        table[y][x] = perso;           /* Positionnement du perso */
        table[yfant1][xfant1] = fant1; /* Positionnement des fantômes 1,2,3,4,5,6,7,8,9,10,11 et 12 */
        table[yfant2][xfant2] = fant2;
        table[yfant3][xfant3] = fant3;
        table[yfant4][xfant4] = fant4;
        table[yfant5][xfant5] = fant5;
        table[yfant6][xfant6] = fant6;
        table[yfant7][xfant7] = fant7;
        table[yfant8][xfant8] = fant8;
        table[yfant9][xfant9] = fant9;
        table[yfant10][xfant10] = fant10;
        table[yfant11][xfant11] = fant11;
        table[yfant12][xfant12] = fant12;
        table[ybonus_1][xbonus_1] = bonus_1; /* Positionnement des bonus 1 et 2*/
        table[ybonus_2][xbonus_2] = bonus_2;

        /* Fin du Jeux si le perso rencontre un fantôme avec enregistrement du score dans le fichier score.txt */
        if(table[y][x] == table[yfant1][xfant1] || table[y][x] == table[yfant2][xfant2] || table[y][x] == table[yfant3][xfant3] || table[y][x] == table[yfant4][xfant4] || table[y][x] == table[yfant5][xfant5] || table[y][x] == table[yfant6][xfant6] || table[y][x] == table[yfant7][xfant7] || table[y][x] == table[yfant8][xfant8] || table[y][x] == table[yfant9][xfant9] || table[y][x] == table[yfant10][xfant10] || table[y][x] == table[yfant11][xfant11] || table[y][x] == table[yfant12][xfant12]){
            enregistrement_du_score(nom_j,score,go,t,nb_point);
            game_over(nom_j,score);
        }

        system("CLS"); /* Rafraichissement de la page */
        affiche(table);

  } /* End of while */
  return 0;
}
