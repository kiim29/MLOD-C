
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void afficheElement(Element e) {
    printf("%s\t", e);
};

void detruireElement(Element e) {
};

bool equalsElement(Element e1, Element e2) {
    return (strcmp(e1,e2)==0);
};

int main(void) {
    Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete('t',l);
	l = ajoutTete('k',l);
	l = ajoutTete('tranquille',l);
	l = ajoutTete('t',l);
	l = ajoutTete('weee',l);
	l = ajoutTete('weEe',l);
	l = ajoutTete('travail',l);
	l = ajoutTete('t',l);
	l = ajoutTete('travail',l);

	afficheListe_i(l);

	ajoutFin_i('incrrrrr',l);
	afficheListe_i(l);

	ajoutFin_r('terrrrrr',l);
	afficheListe_i(l);

	p = cherche_i('leu',l);
	printf("cherche_i(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i('t',l);
	if(estVide(p))
		printf("cherche_i(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r('f',l);
	printf("cherche_r(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r('t',l);
	if(estVide(p))
		printf("cherche_r(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i('t')   : ");
	l = retirePremier_i('t',l);
	afficheListe_r(l);

	printf("retirePremier_i('t')   : ");
	l = retirePremier_i('t',l);
	afficheListe_r(l);

	printf("retirePremier_i('incrrrrr') : ");
	l = retirePremier_i('incrrrrr',l);
	afficheListe_r(l);

	printf("retirePremier_r('travail')   : ");
	l = retirePremier_r('travail',l);
	afficheListe_r(l);

	printf("retirePremier_r('travail')   : ");
	l = retirePremier_r('travail',l);
	afficheListe_r(l);

	printf("retirePremier_r('terrrrrr')  : ");
	l = retirePremier_r('terrrrrr',l);
	afficheListe_r(l);

	afficheEnversAvecSautDeLigne_r(l);

	detruire_r(l);

	return EXIT_SUCCESS;
};