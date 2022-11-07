#include <stdio.h>

int somme(int t[], int nbElem) { //Calcule la somme des éléments du tableau t (qui a nbElem éléments)
    int res = 0;
    for (int i=0; i<nbElem; i++) {
        res += t[i];
    }
}

void repeat(int tab1[], int nbElem1, int tab2[], int nbElem2, int tRes[]) { //Fonction repeat
    int sommeTab1 = somme(tab1, nbElem1);
    int indiceCourant = 0;
    for (int i=0; i<nbElem1; i++) {
        for (int j=0; j<tab1[i]; j++) {
            tRes[indiceCourant] = tab2[i];
            indiceCourant += 1;
        }
    }
}

int main(void) { //Fonction main

    //Initialisation des tableaux
    int nbElemT1 = 3;
    int t1[] = {1,2,4};
    int nbElemT2 = 3;
    int t2[] = {10,3,8};

    //Calcul et affichage du résultat
    int SIZE = somme(t1, nbElemT1);
    int tRes[SIZE];
    repeat(t1, nbElemT1, t2, nbElemT2, tRes);
    for (int j=0; j<SIZE; j++) {
        printf("%i\t", tRes[j]);
    }
}