#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
//#include "cartes.h"

typedef struct{
	int valeur;
	int etat;
} Carte;

void retourner(Carte *c){
	c->etat=!(c->etat);
}

void initCarte(Carte *c, int val){
	c->valeur = val;
	c->etat = 0;
}

int getVal(Carte c){
	return c.valeur;
}

int getEtat(Carte c){
	return c.etat;
}

void initJeu(Carte j[], int nbPaires){
	int i = 0;
	while(i < 2*nbPaires + 1){
		if(i==0) initCarte(&j[0],0);
		else initCarte(&j[i],(int)(i/2));
		i++;
	}


	//for(int i = 0; i<2*nbPaires ; i++){
	//	printf("%d\n", j[i].valeur);	
	//}
	//printf("fin de fonction !\n");
	
}

void initJeuAleat(Carte j[], int nbPaires){
	initJeu(j, nbPaires);
	
	//printf("-------------\n");
	Carte c;
	int i = 0;
	int k = 0;
	int l = 0;
	
	while(i++<100){
		k = rand()%(2*nbPaires -1);
		l = rand()%(2*nbPaires -1);
		c = j[k];
		j[k] = j[l];
		j[l] = c;
	}
	//for(int i = 0; i<2*nbPaires; i++){
	//	printf("%d\n", j[i].valeur);
	//}
}

int main(int argc, char const *argv[]){

	int nbPaires=3;

	Carte jeu[2*nbPaires + 1];
	initJeu(jeu,nbPaires);

	for(int i=0; i<2*nbPaires; i++){
		retourner(&jeu[i]);
	}

	return EXIT_SUCCESS;
}
