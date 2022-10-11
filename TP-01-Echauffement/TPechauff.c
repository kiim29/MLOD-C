#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool estParfait(int k) {
    int sommeDivis = 0;
    int i;
    for (i=1; i<=k/2; i++)
        if (k%i == 0)
            sommeDivis += i;
    return sommeDivis == k;
}

void afficheLesParfaits(int N) {
    int i;
    for (i=0; i<N; i++)
        if (estParfait(i)) {
            printf("%i\n", i);
        }
}

int main(void) {
    int Nbre = 8;
    afficheLesParfaits(Nbre);
    return EXIT_SUCCESS;
}