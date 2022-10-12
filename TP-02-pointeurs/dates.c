#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum mois {
    Janvier = 1,
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
    unsigned int Annee;
    Mois Mois;
    unsigned int Jour;
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

Date creerDateParCopie() {
    Date d;
    initialiseDate(&d);
    return(d);
}

Date *newDate() {
    Date *d;
    d=malloc(sizeof(Date));
    initialiseDate(d);
    return(d);
}

bool estBissextile(unsigned int an) {
    return ((an%4==0 && an%100!=0) || (an%400==0));
}

unsigned int nbreJours(Mois mo, unsigned int an) {
    switch(mo) {
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10 :
        case 12 :
            return 31;
            break;
        case 4 :
        case 6 :
        case 9 :
        case 11 :
            return 30;
            break;
        case 2 :
            if(estBissextile(an)){return 29;}
            else {return 28;}
        default :
            printf("erreur : mois non valide");
            return(0);
    }
}

bool dateValide(Date uneDate){
    return ((uneDate.Annee>0 && uneDate.Annee<9000) &&
            (uneDate.Jour>0 && uneDate.Jour<=nbreJours(uneDate.Mois, uneDate.Annee)));
}

int main(void) {
    // Date d;
    // initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    // afficheDate(&d);
    // Date d;
    // d = creerDateParCopie();
    // afficheDate(&d);
    // Date *date;
    // date = newDate();
    // afficheDate(date);
    // //...
    // free(date);
    Date d;
    initialiseDate(&d);
    if (dateValide(d)) {
        printf("Merci, cette date est valide \n");
        afficheDate(&d);
    }
    else {
        printf("Cette date n'est pas valide ! \n");
    }
    
    return(0);
}