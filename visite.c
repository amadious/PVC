#include "visite.h"


/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  14/05/2019                         */
/******************************************/




float distance_deux_villes(Ville v1 ,Ville v2){
    float res=sqrt(pow((v1.coord.x-v2.coord.x), 2) + pow((v1.coord.y-v2.coord.y), 2));
    return res;
}

float distance_complete_villes(const Ville *villes,int nb_villes){
    int d = 0;
    int i ;

    assert(villes != NULL);
    assert(nb_villes >= 0);

    for(i = 0; i < nb_villes-1; i++)
        d+=distance_deux_villes(villes[i],villes[i+1]);
    return d; 
}


int compare(const void* a, const void* b) {
    assert(a != NULL);
    assert(b != NULL);
    
    const Visite* p = (const Visite*) a;
    const Visite* q = (const Visite*) b;
    if( p->longueur < q->longueur )
        return -1;
    else if(p->longueur > q->longueur)
        return 1;
    else
        return 0; 
}


void trie(Visite *v,int k){
    
    assert(NULL != v);

    qsort(v, k, sizeof(Visite), compare);
}

int generer_visites(Visite *v,const Ville *ville, int nb_ville,int k){
    int i = 0;
    int j = 0;
    int nb_alea = 0;
    Ville tmp ;
    int ii ;
    int jj ;

    assert(ville != NULL);
    assert(v != NULL);
    assert(nb_ville >= 0);

    for(ii = 0; ii < k;ii++){
        for(jj = 0; jj < nb_ville;jj++){
            v[ii].visite[jj] = ville[jj];    
        }
    }
   for(i = 0; i < k; i++){
        for (j = 0; j < nb_ville; j++) {
            nb_alea = rand()%nb_ville ;
                while(nb_alea == j){
                    nb_alea = rand()%nb_ville ;
                }
                tmp = v[i].visite[j] ; 
                v[i].visite[j] = v[i].visite[nb_alea];
                v[i].visite[nb_alea] = tmp ;
            }
            v[i].longueur = distance_complete_villes(v[i].visite,nb_ville);           
        }
    trie(v,k);
    return 1;
}