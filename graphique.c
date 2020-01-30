#include "graphique.h"


/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  14/05/2019                         */
/******************************************/



void afficher_chemins(const Ville *v,int nb_villes){
    int i ;
    
    assert(v != NULL);
    assert(nb_villes >= 0);
    
    for(i = 0 ;i < nb_villes-1 ;i++){
        MLV_draw_line(v[i].coord.x,v[i].coord.y,v[i+1].coord.x,v[i+1].coord.y,MLV_COLOR_RED);
    }
}


void afficher_ville(const Ville ville[],int nb_ville){
    int i ;
    
    assert(ville != NULL);

    assert(nb_ville >= 1);
   
    for(i = 0 ;i < nb_ville ; i++){
        MLV_draw_filled_circle( ville[i].coord.x, ville[i].coord.y,1, MLV_COLOR_GREEN );
    }
}


void afficher_carte(const Ville *visite,const Ville *ville,int nb_villes){
        assert(ville != NULL);
        assert(visite != NULL);
        assert(nb_villes >= 2);

        afficher_ville(ville,nb_villes);
        afficher_chemins(visite,nb_villes);   
        MLV_actualise_window();

        MLV_clear_window(MLV_COLOR_BLACK);
}



