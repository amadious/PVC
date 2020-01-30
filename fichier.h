#ifndef __FICHIER__
#define __FICHIER__

#include "ville.h"
#include "visite.h"


/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  14/05/2019                         */
/******************************************/


/* Une fonction qui prend en paramètre un tableau de
Ville `v` rempli , un entier `nb_villes` et un 
pointure sur un fichier `out` à remplir avec la 
liste des villes. Elle renvoie 1 si tout s'est bien
déroulé ,0 sinon .  */
int creer_fichier_villes(const Ville *v,int nb_villes ,FILE* out);

/* Une fonction qui prend en paramètre un tableau de
Ville `v` rempli  et un pointure sur un fichier `in` 
à remplir avec la liste des villes. Elle renvoie le 
nombre de villes lues si tout s'est bien déroulé ,0 sinon .*/
int lire_fichier_villes(Ville *v,FILE* in,int *nb_villes);

/*Une fonction pour créer un fichier de visites ,elle
prend en argument un fichier `fichier` à remplir ,un tableau
de visites `v` , un entier `nb_ville` qui fait référence 
à la taille d'une visite et un entier `k` pour le nombre 
de visites .*/
int creer_fichier_visite(FILE * fichier ,const Visite *v, int nb_ville,int k);

#endif