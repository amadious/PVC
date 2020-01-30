#ifndef __TEST__
#define __TEST__

#include "ville.h"
#include "visite.h"
#include "fichier.h"
#include "graphique.h"

/*Une fonction qui prend en paramètre un tableau de visite `v`,
un entier `nb_villes` qui est la taille d'une visite et un
autre un K qui est la taille du tableau de visite .*/
void tester_trie_visites(Visite *v,int nb_villes,int k);

/*Une fonction qui prend en paramètre trois entier qui teste 
si ils sont bien valides pour être paramètres de l'algorithme
utilisé .Elle renvoie si tout marche comme il faut ,0 sinon . */
int tester_coord_valid(int x1 ,int x2 ,int x3) ;


#endif 