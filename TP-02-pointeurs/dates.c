#include <stdio.h>
#include <stdlib.h>

enum mois {
    Janvier,
    Fevrier,
    Mars,
    Avril,
    Mai,
    Juin,
    Juillet,
    Aout,
    Septembre,
    Octobre,
    Novembre,
    Decembre
};

typedef enum mois Mois;

struct date {
    int Annee;
    Mois Mois;
    int Jour;
};

typedef struct date Date;

void initialiseDate(Date *p) {
    printf("Saisir l'année :");
    scanf("%i", &(p->Annee));
    printf("Saisir le num du mois :");
    scanf("%i", (int *)&(p->Mois));
    printf("Saisir le jour :");
    scanf("%i", &(p->Jour));
}

void afficheDate(Date *p) {
    printf("La date (jj/mm/aaaa) est :\n");
    printf("%i", p->Jour);
    printf("/");
    printf("%i", p->Mois);
    printf("/");
    printf("%i", p->Annee);
    printf("\n");
}

int main(void) {
    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);
}