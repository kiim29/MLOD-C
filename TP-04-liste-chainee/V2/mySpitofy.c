#include "linkedList.h"
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

Musique* creerUneMusique(char* line) {
    Musique *mus = malloc(sizeof(Musique));
    mus->Name = strdup(strsep(&line, ","));
    mus->Artist = strdup(strsep(&line, ","));
    mus->Album = strdup(strsep(&line, ","));
    mus->Genre = strdup(strsep(&line, ","));
    mus->DiscNum = atoi(strsep(&line, ","));
    mus->TrackNum = atoi(strsep(&line, ","));
    mus->Year = atoi(strsep(&line, ","));
    return mus;
}

Liste creerLaListeDesMusiques(FILE* f) {
    char buffer[1024];
    Musique* mus;
    Liste l = malloc(sizeof(Liste));
    while(fgets(buffer,1024,f) != NULL) {
        mus = creerUneMusique(buffer);
        ajoutFin_i(mus,l);
    }
    return(l);
}

int main(void){
    //Ouverture du fichier
    char fileName[] = "music.csv";
    FILE* f;
    f = fopen(fileName,"r");

    //Gestion des erreurs
    if(f==NULL) {
        printf ("Code de l'erreur : %d\n", errno);
        if (errno == ENOENT)
            printf ("Le fichier n'existe pas !\n");
        else
            printf ("Erreur inconnue\n");
        return EXIT_FAILURE;
    }

    //Liste de musiques depuis le fichier
    Liste l = creerLaListeDesMusiques(f); 
    afficheListe_i(l);

    detruire_r(l);
    fclose(f);
    return EXIT_SUCCESS;
}