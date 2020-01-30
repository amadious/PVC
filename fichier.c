#include "fichier.h"


int creer_fichier_villes(const Ville *v,int nb_villes,FILE* out){
    int i = 0 ;

    assert(out != NULL);
    assert(nb_villes > 1);
    assert(v != NULL);

    if (!fprintf(out,"Nombre de villes est : %d\n",nb_villes))
        return 0 ;

    while(fprintf(out,"ville_%d : (%d,%d)\n",i,v[i].coord.x,v[i].coord.y) && i < nb_villes-1){      
        i++;
    }
    return 1 ;
}



int lire_fichier_villes(Ville *v,FILE* in ,int *nb_villes){
    int i = 0;

    assert(v != NULL);
    assert(in != NULL);
    
    rewind(in);
    
    if (fscanf(in,"Nombre de villes est : %d",nb_villes) == 0 )
        return 0;
    while(fscanf(in,"%s : (%d,%d)",v[i].nom,&(v[i].coord.x ),&(v[i].coord.y)) && i < *nb_villes-1){      
        i++;
    }

    return i ;
}


int creer_fichier_visite(FILE * fichier ,const Visite *v, int nb_ville,int K){
    int i, j;
    assert(v != NULL);
    assert(nb_ville >= 0);

    for(i = 0; i < K; i++){
        for(j = 0; j < nb_ville; j++){
            if(!fprintf(fichier,"%s ",v[i].visite[j].nom))
                return 0 ;
        }
        if (!fprintf(fichier,"%2f \n ",v[i].longueur))
            return 0 ;
        }
    return 1;
}