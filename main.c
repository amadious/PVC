#include "ville.h"
#include "visite.h"
#include "graphique.h"
#include "fichier.h"
#include "algorithmique.h"
#include "test.h"

/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  09/04/2019                         */
/******************************************/

int main(int argc, char const *argv[]){
    FILE* fichier = NULL ;
    Ville* villes = NULL ;
    Dimensions d = {700 , 500} ;
    Parametre p ;
    int nb_ville,x2,x3;
    Visite *v = {NULL} ;
    int k = 128 ;
    int i ;

    srand(time(NULL));
    

    if(NULL == (fichier = fopen(argv[1],"r"))){
        printf("le fichier %s n'est pas reconnu dans le répertoire \n",argv[1]);
        return 0 ;
    }
    
    if (fscanf(fichier,"Nombre de villes est : %d",&nb_ville) 
                && (NULL != (villes = (Ville*)malloc(sizeof(Ville)*nb_ville))) 
                && lire_fichier_villes(villes,fichier,&nb_ville) ){
        
        do {
            printf("Le nombre de villes est  %d\n",nb_ville);
            printf("Entrez le nombre alpha :");
            x2 = scanf("%d",&p.alpha);
            printf("Entrez le nombre beta :");
            x3 = scanf("%d",&p.beta);
            p.gama = k - p.alpha - p.beta;
        }while(!tester_coord_valid(x3,x2,nb_ville) || p.gama <= 0);

        if ((NULL != (v = (Visite*)malloc(sizeof(Visite)*k))) ){
            for (i = 0 ;i < k; i++){
                v[i].visite = (Ville*)malloc(sizeof(Ville)*nb_ville);
            }        

            generer_visites(v,villes,nb_ville,k) ;
            MLV_create_window("PVC","TP6",d.width,d.height);

            if (generer_visite_prime(v,villes,p,nb_ville,k))
                tester_trie_visites(v,nb_ville,k);
            algo_glouton(villes,nb_ville); 
            printf("La distance avec glouton :%f \n",distance_complete_villes(villes,nb_ville));
        
            MLV_free_window();
        }
    }
    
    return 0;
}

