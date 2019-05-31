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
	while(i++ < 2*nbPaires + 1){
		initCarte(&j[i],i%nbPaires);
	}

}


int main(int argc, char const *argv[]){

	int nbPaires=3;
	time_t begin,end;
	int record;

	Carte jeu[2*nbPaires + 1];
	initJeu(jeu,nbPaires);


	for(int i=0; i<2*nbPaires; i++){
		retourner(&jeu[i]);
	}
	//Quand la partie commence
	begin = clock();

	//à la fin de la partie
	end = clock();

	record = (int) difftime(end,begin);

	return EXIT_SUCCESS;
}
