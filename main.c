#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAXHAUT 18
#define MAXLARG 24
#define JOUEUR1 0
#define JOUEUR2 1
#define NB_CORVETTE 1
#define CORVETTE_TAILLE 1
#define CORVETTE_ID 1
#define NB_DESTROYER 2
#define DESTROYER_TAILLE 3
#define DESTROYER_ID 2
#define NB_CROISEUR 2
#define CROISEUR_TAILLE 4
#define CROISEUR_ID 3
#define NB_PORTEAVION 1
#define PORTEAVION_TAILLE 6
#define PORTEAVION_ID 4

void Color(int couleurDuTexte,int couleurDeFond){
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void affichemap(int map[MAXHAUT][MAXLARG][2], int joueur){
int i=0;
int j=0;

for (i=0;i<MAXHAUT;i++){
    for (j=0;j<MAXLARG;j++){
            if(map[i][j][joueur]==0){
            Color(3,3);
            }
            printf("%2d", map[i][j][joueur]);
            Color(7,0);
                }printf("\n");}
}

void waitFor (unsigned int secs){
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);}
}

void bateau(int map[MAXHAUT][MAXLARG][2], int joueur, int tailleBateau, int idBateau, int x, int y, int vieBateau){
   int i;

        for(i=0;i<tailleBateau; i++){

            if(x+i<MAXHAUT && x+i>=0 && map[x+i][y][joueur] == 0){
                map[x+i][y][joueur] = idBateau;
            }
    }vieBateau == tailleBateau;
}

void PlacerRand(int map[MAXHAUT][MAXLARG][2], int joueur, int tailleBateau, int idBateau, int x, int y){
   int vieBateau;
    x = doRand(0,MAXHAUT-1);
    y = doRand(0,MAXLARG-1);
    bateau(map, joueur, tailleBateau, idBateau, x, y, vieBateau);
}

void PlacerBateauIA(int map[MAXHAUT][MAXLARG][2], int joueur){
    int i;
    int x;
    int y;

   // while pour pas que ça dépasse et que ça se superpose

    for(i=0;i<NB_CORVETTE;i++){
        PlacerRand(map, joueur, CORVETTE_TAILLE, CORVETTE_ID, x, y);
    }
    for(i=0;i<NB_DESTROYER;i++){
        PlacerRand(map,joueur,DESTROYER_TAILLE,DESTROYER_ID, x, y);
    }
    for(i=0;i<NB_CROISEUR;i++){
        PlacerRand(map,joueur,CROISEUR_TAILLE,CROISEUR_ID, x, y);
    }
    for(i=0;i<NB_PORTEAVION;i++){
        PlacerRand(map,joueur,PORTEAVION_TAILLE,PORTEAVION_ID, x, y);
    }
}

void attaqueIA1(int map[MAXHAUT][MAXLARG][2], int joueur){
    int x = 0;
    int y = 0;
    int vieBateau;
    int idBateau;

    x = doRand(0,MAXHAUT-1);
    y = doRand(0,MAXLARG-1);

    while(vieBateau !=0){

        while(map[x][y][joueur]!=0 && map[x][y][joueur]!=9){
        map[x][y][joueur]==9;
            if(map[x][y][joueur]==9){
            Color(0,12);
            }
        printf("%d", map[x][y][joueur]);
        if(map[x][y][joueur]==1 || map[x][y][joueur]==2 || map[x][y][joueur]==3 || map[x][y][joueur]==4){
        printf("\nTouche!\n");
        vieBateau=vieBateau-1;
        affichemap(map, joueur);
        }else{
        printf("\nLoupé...\n");}
        }
        if (vieBateau==0){
            printf("Vous avez coulé le bateau %d\n", &idBateau);
            affichemap(map, joueur);
        }
    }
}

int main()
{
    int map[MAXHAUT][MAXLARG][2]={0};
    int joueur=0;

    int ii=0;
    int jj=0;
    int x=0;
    int y=0;

    printf("Bataille navale\n");
    printf("IA contre IA\n");
    printf("\nPlacement bateaux\n");

    printf("\nBateaux joueur 1\n");
     PlacerBateauIA(map, JOUEUR1);

     affichemap(map, JOUEUR1);
     printf("\n");

    printf("\nBateaux joueur 2\n");
     PlacerBateauIA(map, JOUEUR2);
     affichemap(map, JOUEUR2);
     printf("\n");

    //while(map[x][y][JOUEUR1]!=0 || map[x][y][JOUEUR2]!=0){
    printf("\nA l'attaque!\n");
    attaqueIA1(map,JOUEUR1);
    affichemap(map, JOUEUR1);
    printf("\n");

    attaqueIA1(map,JOUEUR2);
    affichemap(map, JOUEUR2);
    printf("\n");
   // }
    return 0;
}

/*

    while(map[x][y][JOUEUR1]!=0 || map[x][y][JOUEUR2]!=0){
    printf("\nA l'attaque!\n");
    attaque(map,JOUEUR1);
    affichemap(map, JOUEUR1);
    attaque(map,JOUEUR2);
    affichemap(map, JOUEUR2);
    }

    Joueur contre IA
    printf("\nVous placez une corvette: placement vertical (Entre 0 et 24)\n");
    scanf("%d\n", x);
    printf("\nVous placez une corvette: placement horizontal (Entre 0 et 17)\n");
    scanf("%d\n", y);
    printf("\nVous placez un destroyer: de quelle valeur voulez faire partir votre bateau? (Entre 0 et 24)\n");
    scanf("%d\n",x);
    printf("\nVous placez un destroyer: \n");
    scanf("%d\n",x);
    bateau(map, JOUEUR1, DESTROYER1, x, y);
*/


/*
void placementcorvette(int map[XM][YM][2], int joueur){
    int x = 0;
    int y = 0;

    x = doRand(0,17);
    y = doRand(0,23);

        if(map[x][y][joueur] == 0){
        map[x][y][joueur] = CORVETTE;
        }

}
void placementdestroyer1(int map[XM][YM][2], int joueur){
    int x = 0;
    int y = 0;

    x = doRand(0,17);
    y = doRand(0,23);

        if(map[x][y][joueur] == 0 && map[x+1][y][joueur]==0 && map[x+2][y][joueur]==0){
        map[x][y][joueur]=DESTROYER1;
        map[x+1][y][joueur]=DESTROYER1;
        map[x+2][y][joueur]=DESTROYER1;
        printf("%d", map[x][y][joueur]);}

}



void placementdestroyer2(int map[XM][YM][2], int joueur){
    int x = 0;
    int y = 0;

    x = doRand(0,17);
    y = doRand(0,23);

        if(map[x][y][joueur] == 0 && map[x][y+1][joueur]==0 && map[x][y+2][joueur]==0){
        map[x][y][joueur]=DESTROYER2;
        map[x][y+1][joueur]=DESTROYER2;
        map[x][y+2][joueur]=DESTROYER2;
        printf("%d", map[x][y][joueur]);}

}
void placementcroiseur1(int map[XM][YM][2], int joueur){
    int x = 0;
    int y = 0;

    x = doRand(0,17);
    y = doRand(0,23);

        if(map[x][y][joueur] == 0 && map[x+1][y][joueur]==0 && map[x+2][y][joueur]==0 && map[x+3][y][joueur]==0){
        map[x][y][joueur]= CROISEUR1;
        map[x+1][y][joueur]=CROISEUR1;
        map[x+2][y][joueur]=CROISEUR1;
        map[x+3][y][joueur]=CROISEUR1;
        printf("%d", map[x][y][joueur]);}

}
void placementcroiseur2(int map[XM][YM][2], int joueur){
    int x = 0;
    int y = 0;

    x = doRand(0,17);
    y = doRand(0,23);

        if(map[x][y][joueur] == 0 && map[x][y+1][joueur]==0 && map[x][y+2][joueur]==0 && map[x][y+3][joueur]==0){
        map[x][y][joueur]= CROISEUR2;
        map[x][y+1][joueur]=CROISEUR2;
        map[x][y+2][joueur]=CROISEUR2;
        map[x][y+3][joueur]=CROISEUR2;

        printf("%d", map[x][y][joueur]);}

}
void placementporteavion(int map[XM][YM][2], int joueur){
    int x = 0;
    int y = 0;

    x = doRand(0,17);
    y = doRand(0,23);

        if(map[x][y][joueur] == 0 && map[x+1][y][joueur]==0 && map[x+2][y][joueur]==0 && map[x+3][y][joueur]==0 && map[x+4][y][joueur]==0 && map[x+5][y][joueur]==0){
        map[x][y][joueur]=PORTEAVION;
        map[x+1][y][joueur]=PORTEAVION;
        map[x+2][y][joueur]=PORTEAVION;
        map[x+3][y][joueur]=PORTEAVION;
        map[x+4][y][joueur]=PORTEAVION;
        map[x+5][y][joueur]=PORTEAVION;
        printf("%d", map[x][y][joueur]);}
}
*/
