/*

Fichier : deplace_niv_1.c

Auteur : Nicolle.B

Description : Gestion du deplacement du personnage et de la boucle mode FACILE

Date : 01/10/2010

*/

#include "lib.h"


void boucle_niv_1(arene table, int x, int y, char nom_j[50], char go){

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
    int nb_point_max = 0;/*<-------Nombre de points présents dans le jeux au démarrage */
    int nb_point = 0; /*<----------Nombre de points restants dans le jeux en cours */
    int i,j;

    while(i!=60){ /* On compte le nombre de points présents dans l'arène */
        for(i=0; i<60; i++){
            for(j=0; j<20; j++){
                if(table[j][i] == '.'){
                    nb_point_max++;
                }
            }
        }
    }

    nb_point = nb_point_max + 5; /* On ajoute 5 (Personnage + 4 fantômes qui cachent les points en début de jeux */

    while (1){

        if(nb_point == 0){
            game_over(nom_j,score);
        }

        affichage_foot(nom_j,score,nb_point);

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

        table[y][x] = perso;           /* Positionnement du perso */
        table[yfant1][xfant1] = fant1; /* Positionnement des fantômes 1,2,3 et 4 */
        table[yfant2][xfant2] = fant2;
        table[yfant3][xfant3] = fant3;
        table[yfant4][xfant4] = fant4;
        table[ybonus_1][xbonus_1] = bonus_1; /* Positionnement des bonus 1 et 2 */
        table[ybonus_2][xbonus_2] = bonus_2;

        /* Fin du Jeux si le perso rencontre un fantôme avec enregistrement du score dans le fichier score.txt */
        if(table[y][x] == table[yfant1][xfant1] || table[y][x] == table[yfant2][xfant2] || table[y][x] == table[yfant3][xfant3] || table[y][x] == table[yfant4][xfant4]){
            enregistrement_du_score(nom_j,score,go,t,nb_point);
            game_over(nom_j,score);
        }

        system("CLS"); /* Rafraichissement de la page */
        affiche(table);

  } /* End of while */
  return 0;
}
