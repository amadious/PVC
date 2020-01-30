#ifndef __VILLE__
#define __VILLE__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <time.h>


/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  14/05/2019                         */
/******************************************/



typedef struct {
    int x ;
    int y ;
}Coordonne ;

typedef struct {
    char nom[10] ;
    Coordonne coord ;
}Ville ;

typedef struct {
    int width ;
    int height ;
}Dimensions ;


/*Une fonction qui s'occuppe de génerer une tableau de ville
d'une manière aléatoire elle prend en paramètre un entier `nb_ville`
qui fait reférence au nombre de ville qu'on veut générer , un 
tableau de Ville `villes` à remplir et des Dimensions `dimension` 
pour les dimensions de la fenêtre. Elle renvoie 1 si on a réussi 
à génrer les villes,0 sinon . */
int generer_villes_alea(int nb_ville, Ville *villes,Dimensions dimension);

/*Une fonction qui s'occuppe de génerer un tableau de villes
d'une manière avec des coordonnées chosies avec avec le clic gauche de 
la souris elle prend en paramètre un entier `nb_ville` qui fait 
reférence au nombre de ville qu'on veut générer et un tableau de Ville
`villes` à remplir. Elle renvoie 1 si on a réussi à génrer les villes,
0 sinon . */
int creer_villes(int nb_ville,Ville *villes);

#endif