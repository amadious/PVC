#ifndef __VISITE__
#define __VISITE__

#include "ville.h"


/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  14/05/2019                         */
/******************************************/



typedef struct{
    Ville *visite;
    float longueur; 
}Visite;

typedef struct {
    Ville ville1 ;
    Ville ville2 ;
    int distance;
}Chemin ;





/*Une fonction comparaison dont l'adresse est passée
comme argument dans la fonction `qsort`  .*/
int compare(const void* a, const void* b);

/*Une fonction por trier un tableau de visites `v` 
passé comme argument avec un entier `K` .*/
void trie(Visite *v,int k);

/*Une fonction pour calculer la distance entre deux
villes passées en argument `v1` et `v2`, elle 
renvoie un flottant ( la distance une fois calculée ).*/
float distance_deux_villes(Ville v1 ,Ville v2);

/*Une fonction pour calculer la distance entre les villes
d'une même visite,en passant en argument un tableau de villes.
Elle renvoie un flottant ( la distance une fois calculée ).*/
float distance_complete_villes(const Ville *villes,int nb_villes);

/*Une fonction qui s'occuppe de génerer un tableau de visites
d'une manière aléatoire elle prend en paramètre un entier `nb_ville`
qui fait reférence au nombre de ville qu'on veut générer , un 
tableau de Visite `v` à remplir , Dimensions `dimension` 
pour les dimensions de la fenêtre et tableau de ville `ville`. 
Elle renvoie 1 si on a réussi à génrer les villes,0 sinon . */
int generer_visites (Visite *v,const Ville *ville,
                    int nb_ville,int k);

#endif