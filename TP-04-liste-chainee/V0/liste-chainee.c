#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l=malloc(sizeof(Cellule));
	if(l!=NULL) {
		l->val = v;
		l->suiv = NULL;
	}
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste newListe = creer(v);
	newListe->val = v;
	newListe->suiv = l;
	return newListe;
}

void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	printf("[ ");
	while (!estVide(l)) {
		afficheElement(l->val);
		l = l->suiv;
	}
	printf("]\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if (estVide(l)) {
		printf("\n");
	}
	else {
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
}

void detruireElement(Element e) {} //Rien à faire tant que les éléments sont des int

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste suivant, courant = l;
	while (!estVide(courant)) {
		suivant=courant->suiv;
		detruireElement(courant->val);
		free(courant);
		courant = suivant;
	}
}

// version récursive
void detruire_r(Liste l) {
	if (!estVide(l)) {
		detruireElement(l->val);
		detruire_r(l->suiv);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	if (estVide(l)) {
		return creer(v);
	}
	Liste newListe = l;
	while (!estVide(newListe->suiv)) {
		newListe = newListe->suiv;
	}
	newListe->suiv = creer(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l)) {
		return creer(v);
	}
	else {
		l->suiv = ajoutFin_r(v, l->suiv);
		return(l);
	}
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while ((!estVide(l)) && (!equalsElement(v, l->val))){
		l = l->suiv;
	}
	return l;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (estVide(l)) {
		return NULL;
	}
	else {
		if(l->val == v) {
			return l;
		}
		else {
			return cherche_r(v, l->suiv);
		}
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste listeDeRech = cherche_i(v, l);
	if(listeDeRech != NULL) {
		if(l->val == v) {
			return l->suiv;
		}
		else {
			Liste newL = l;
			while (!equalsElement(v, newL->suiv->val)){
				newL = newL->suiv;
			}
			newL->suiv = listeDeRech->suiv;
			return(l);
		}
	}
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (!estVide(l)) {
		if (l->val == v) {
			return l->suiv;
		}
		else {
			l->suiv = retirePremier_r(v, l->suiv);
			return l;
		}
	}
}

void afficheEnvers_r(Liste l) {
	if (!estVide(l)) {
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}

void afficheEnversAvecSautDeLigne_r(Liste l) {
	afficheEnvers_r(l);
	printf("\n");
}


