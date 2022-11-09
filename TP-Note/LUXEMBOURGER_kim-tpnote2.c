
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE_MAX 5


// QUESTION 1

typedef struct {
    void* next;
    unsigned int chunkSize;
    char* chunk;
} Chunk;

typedef Chunk* String;


// QUESTION 2

void ajouterNCaracteresAPartirDe(char* chaine, int indice, int nbCharAAjouter, char* chunk) {
    for (int k=0; k<nbCharAAjouter; k++) {
        chunk[k] = chaine[indice + k];
    }
}

String string_new(char* chaine) {
    int size = strlen(chaine);
    int chunkSizeDuDernier = size % 5;
    String s = malloc(sizeof(Chunk));
    String precedent = malloc(sizeof(Chunk));
    int i;
    if (chunkSizeDuDernier != 0) {
        ajouterNCaracteresAPartirDe(chaine, size-chunkSizeDuDernier-1, chunkSizeDuDernier, s->chunk);
        s->chunkSize = chunkSizeDuDernier;
        s->next = NULL;
    }
    for (i=size-chunkSizeDuDernier-1; i>=0; i-=5) {
        precedent->next = s;
        precedent->chunkSize = 5;
        ajouterNCaracteresAPartirDe(chaine, i, 5, precedent->chunk);
        s = precedent;
    }
    free(precedent);
    return s;
}


// QUESTION 3
// Il manque la fonction d'affichage : si on ne peut pas afficher les String, on ne peut rien tester.



int main(void) {
    String s = string_new("Hello !");
}