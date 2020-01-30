#include "ville.h"


/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  14/05/2019                         */
/******************************************/





int generer_villes_alea(int nb_ville, Ville *villes,Dimensions dimension){
    
    int i = 0;
    int j = 0;


    assert(nb_ville >= 1);
    assert(villes != NULL);

    for (i = 0; i < nb_ville; i++){
        villes[i].coord.x = rand()%dimension.width;
        villes[i].coord.y = rand()%dimension.height;

        strcpy(villes[i].nom,"ville_");

        
        for (j = 0; j < i; j++){
            if (villes[i].coord.x == villes[j].coord.x && 
                villes[i].coord.y == villes[j].coord.y){
                
                villes[i].coord.x = rand()%dimension.width;
                
                villes[i].coord.y = rand()%dimension.height;
                
            j = 0 ;
            }
        }
    }
 return 1;
}


