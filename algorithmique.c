#include "algorithmique.h"



/******************************************/
/* TP 6 :PVC                               */
/* OUKSILI et SAKHO (Binome)               */
/* Dernière modification (OUKSILI SMAIL)   
    Le  14/05/2019                         */
/******************************************/


int rencontre(Intervalle a, Intervalle b){

	if(a.inf <= b.inf &&  b.inf <= a.sup)
		return 1;
	
	if(b.inf <= a.inf && a.inf <= b.sup)
		return 1;

	return 0;
}


int creer_mutation(Visite v, int nb_ville){
    Ville tmp;
    int  a;
    int l ;
    float lmax = nb_ville/2;
    Intervalle i ;
    Intervalle j ;

    assert(NULL != v.visite);
    assert(nb_ville >= 2);

    l = MLV_get_random_integer(1, floor(lmax));
    
    i.inf = MLV_get_random_integer(1, nb_ville);
    i.sup = i.inf + l - 1;
    j.inf = MLV_get_random_integer(1, nb_ville);
    j.sup = j.inf + l - 1;
    
    
    
    while ((rencontre(i, j) == 0) && (i.inf != i.sup) && (j.inf != j.sup) && (i.sup < nb_ville) && (j.sup < nb_ville)){
        l = MLV_get_random_integer(2, floor(lmax));
        i.inf = MLV_get_random_integer(1, nb_ville);
        i.sup = i.inf + l - 1;
        j.inf = MLV_get_random_integer(1, nb_ville);
        j.sup = j.inf + l - 1;
    }        

    for(a = 0; a < l; a++){
        tmp = v.visite[i.inf + a];
        v.visite[i.inf + a] = v.visite[j.inf + a];
        v.visite[j.inf + a] = tmp ;
    }
    v.longueur = distance_complete_villes(v.visite,nb_ville);                
    return 1;
}

int generer_visite_prime(Visite *v,const Ville *ville, Parametre p, int nb_ville,int k){    
    MLV_Keyboard_button touche;
    Visite *v2 = {NULL};
    Visite *v3 = {NULL};
    Visite vprec = v[0];
    int  i, j, l,cpt;

    assert(v != NULL);
    assert( NULL != ville);
    assert( nb_ville > 0);
    assert(k > 0) ;    
    
    cpt = 0 ;

    vprec = v[0];

    if ((NULL != (v3 = (Visite*)malloc(sizeof(Visite)*k))) 
           && (NULL != (v2 = (Visite*)malloc(sizeof(Visite)*k))) ){
        for (i = 0 ;i < k; i++){
            v3[i].visite = (Ville*)malloc(sizeof(Ville)*nb_ville);
            v3[i].longueur = 0 ;
            v2[i].visite = (Ville*)malloc(sizeof(Ville)*nb_ville);
            v2[i].longueur = 0 ;
        }
    }

    MLV_get_event (&touche, NULL, NULL,NULL, NULL,NULL, NULL, NULL,NULL);
    while (touche != MLV_KEYBOARD_z){
		MLV_get_event (&touche, NULL, NULL,NULL, NULL,NULL, NULL, NULL,NULL);
		MLV_wait_milliseconds(50);


        for(j = 1; j < p.beta; j++){
            v2[j] = v[j];
        }

        for(i = 0; i < p.alpha; i++){
            creer_mutation(v[i], nb_ville);
            v2[i + p.beta] = v[i];
        }
  
        for(l = 0; l < p.gama; l++){
            if (generer_visites(v3, ville, nb_ville,k))
                v2[l + p.alpha + p.beta] = v3[0];
        }

        for (i = 1 ;i  < k ; i++)
            v[i] = v2[i] ;

        trie(v,k); 

        if ((int)vprec.longueur == (int)v[0].longueur){
            cpt ++ ;
            for (i=0;i < nb_ville ; i++){   
                v[0].visite[i].coord.x = vprec.visite[i].coord.x ;
                v[0].visite[i].coord.y = vprec.visite[i].coord.y ;
                strcpy(v[0].visite[i].nom,vprec.visite[i].nom) ;
                v[0].longueur = vprec.longueur ;
            }
        }

        else {
            cpt = 0 ;
           for (i=0;i < nb_ville ; i++){
                vprec.visite[i].coord.x = v[0].visite[i].coord.x ;
                vprec.visite[i].coord.y = v[0].visite[i].coord.y ;
                strcpy(vprec.visite[i].nom,v[0].visite[i].nom) ;
                vprec.longueur = v[0].longueur ;
            }
        }


        afficher_carte(v[0].visite,ville,nb_ville);
        if (cpt == 300)
            touche = MLV_KEYBOARD_z ;
    }
    printf("La distance avec l'algo du TP %f\n",distance_complete_villes(v[0].visite,nb_ville));
    if (creer_fichier_visite(fopen("visites.pcv","w+"),v,nb_ville,k))
        afficher_carte(vprec.visite,ville,nb_ville);
    MLV_wait_seconds(10);
    
    
    return 1;   
}


void algo_glouton(Ville *villes ,int nb_villes){
    int i ;
    int j ;
    Ville tmp ;
    
    assert(NULL != villes);
    assert(nb_villes >= 0);

    for(i = 0 ; i < nb_villes ; i++){
        for(j = i+1 ; j < nb_villes-i-1 ; j++){
            if (distance_deux_villes(villes[i],villes[i+1]) > distance_deux_villes(villes[i],villes[j])){
                tmp = villes[i+1];
                villes[i+1] = villes[j];
                villes[j]= tmp ;
            }
        }
    }

}
