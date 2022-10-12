#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//pour size qui change : structure Matrix avec numlines, numcolumns et int **values
//les valeurs sont dans un tableau de pointeurs (values)

#define SIZE 5

void matrix_mult(int64_t mRes[SIZE][SIZE], int64_t m1[][SIZE], int64_t m2[][SIZE]) {
    int i, j, k;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            int64_t sum = 0;
            for (k=0; k<SIZE; k++) {
                sum += m1[i][k] * m2[k][j];
            }
            mRes[i][j] = sum;
        }
    }
}

void matrix_print(int64_t M[SIZE][SIZE]) {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            printf("%li\t", M[i][j]);
        }
        printf("\n");
    }
}

int main(void) {

    //matrices en ligne * colonne

    int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[SIZE][SIZE];

    matrix_mult(matriceResultat,matrice1,matrice2);
    matrix_print(matriceResultat);

    return EXIT_SUCCESS;
}

//Ce programme n'est pas très réutilisable pour d'autres tailles que SIZE
//Passer la SIZE en paramètres des fonctions pourrait être une solution