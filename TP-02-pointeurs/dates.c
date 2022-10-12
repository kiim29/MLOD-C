#include <stdio.h>

enum mois {
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

typedef enum mois Mois;

struct date {
    int Annee;
    Mois Mois;
    int Jour;
};

typedef struct date Date;

int main(void) {
    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);
}