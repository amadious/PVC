#ifndef __ALGORITHMIQUE__
#define __ALGORITHMIQUE__


#include "ville.h"
#include "visite.h"
#include "graphique.h"
#include "fichier.h"


/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  14/05/2019                         */
/******************************************/



typedef struct {
	int inf,sup;
}Intervalle;

typedef struct {
  int alpha;
  int beta;
  int gama;
}Parametre;


/*prend 2 intervalles en argument et renvoie
  1 s'il se rencontrent et 0 sinon */
int rencontre(Intervalle a, Intervalle b);

/*prend en argument une visite , le nombre de villes,
 effectue ensuite la mutation comme expliquer dans 
 l'algo de la consigne*/ 
int creer_mutation(Visite v, int nb_ville);

/*prend en argument le tableau de visite (v1) generer aleatoirement au debut, le tableau
  de ville generer aleatoirement egalement au debut, le nombre de ville et un parametre
  p contenant les variable alpha, beta et gama qui vont nous aider pour l'algo. 
  Applique l'algo de l'enoncer sur le tableau de visite, qui consistent a copier
  les beta meilleurs visites de (v1) dans (v2), puis appliquer la mutation sur les alpha
  meilleur visites de le tableau puis copier le contenu a la suite dans le tableau annexe (v2),
  generer un autre tableau de visites aleatoire (v3) de la taille gama restante de (v1)
  et placer (v3) a la suite de (v2). Copier ensuite (v2) dans (v1), trier (v1) et repeter l'algo
  tant que l'on n'interompt pas le programme.  */
int generer_visite_prime(Visite *v, const Ville *ville, Parametre p, int nb_vill,int k);

/*Une fonction qui prend en argument un tableau de villes
`villes` et sa taille `nb_villes` et trie ce dernier à l'aide
de l'algorithme glouton .n*/
void algo_glouton(Ville *villes ,int nb_villes);



#endif