#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

#include "ville.h"
#include "visite.h"
#include <MLV/MLV_all.h>


/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  14/05/2019                         */
/******************************************/


/*Une fonction qui prend en argument un tableau de villes
`v` et la taille de ce dernier `nb_villes` et affiche 
un chemin qui lie ces villes à l'aide de la bibliothèque MLV*/
void afficher_chemins(const Ville *v,int nb_villes);

/*Une fonction qui prend en argument un tableau de villes
`v` et la taille de ce dernier `nb_villes` et affiche 
ces villes en forme de cercles à l'aide de la bibliothèque MLV*/
void afficher_ville(const Ville ville[],int nb_ville);

/*Une fonction qui prend en argument un tableau 
de villes `visite`,un autre `ville` et la taille de 
ces derniers fait appel au deux fonction précedentes
pour afficher une carte de villes ainsi qu'un chemin qui lie
ces dernieres à l'aide de la bibliothèque MLV*/
void afficher_carte(const Ville *visite,const Ville *ville,int nb_villes);


#endif