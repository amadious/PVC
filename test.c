#include "test.h"

/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  14/05/2019                         */
/******************************************/


void tester_trie_visites(Visite *v,int nb_villes,int k){
    int i = 0 ;
    
    assert(nb_villes >= 0);
    assert(v != NULL);

    for(i = 0;i+1 < k;i++){
        if (v[i].longueur > v[i].longueur){
            printf("erreur :la liste des visites n'est pas triée \n");
            return;
        }
    }
    printf("réussi:la liste des visites est pas triée \n");
}


int tester_coord_valid(int x1 ,int x2 ,int x3){
    if( x1 <= 0 || x2 <= 0 || x3 <= 0 ){
        printf("erreur : valeurs entrées sont invalides \n");
        return 0;
    }
    return 1;
}