#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// typedef short TypeEntier;
typedef unsigned long long TypeEntier;

TypeEntier factorielle (TypeEntier n) {
    if (n==0) 
        return 1;
    else {
        return n*factorielle(n-1);
    }
}

int main(void) {
    int i;
    for (i=0; i<=15; i++)
        printf("%i\n", factorielle(i));
    return EXIT_SUCCESS;
}