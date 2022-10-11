#include <stdio.h>

enum MesMois {
    Janvier,
    Février,
    Mars,
    Avril,
    Mai,
    Juin,
    Juillet,
    Août,
    Septembre,
    Octobre,
    Novembre,
    Décembre
};

typedef enum MesMois Mois;

struct Date {
    int Annee;
    Mois Mois;
    int Jour;
};

int main(void) {
    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);
}