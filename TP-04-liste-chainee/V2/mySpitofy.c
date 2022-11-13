#include "linkedList.h"
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

//Ce fichier crée des segmentation faults mais je n'ai pas trouvé pourquoi.

Musique* creerUneMusique(char* line) {
    Musique *mus = malloc(sizeof(Musique));
    char* tmp1 = strsep(&line, ",");
    if (tmp1 != NULL) {
        mus->Name = strdup(tmp1);
    } else {
        mus->Name = "Nom non renseigné";
    }
    // mus->Name = strdup(strsep(&line, ","));
    char* tmp2 = strsep(&line, ",");
    if (tmp2 != NULL) {
        mus->Artist = strdup(tmp2);
    } else {
        mus->Artist = "Artiste non renseigné.e";
    }
    // mus->Artist = strdup(strsep(&line, ","));
    char* tmp3 = strsep(&line, ",");
    if (tmp3 != NULL) {
        mus->Album = strdup(tmp3);
    } else {
        mus->Album = "Album non renseigné";
    }
    // mus->Album = strdup(strsep(&line, ","));
    char* tmp4 = strsep(&line, ",");
    if (tmp4 != NULL) {
        mus->Genre = strdup(tmp4);
    } else {
        mus->Genre = "Genre non renseigné";
    }
    // mus->Genre = strdup(strsep(&line, ","));
    char* tmp5 = strsep(&line, ",");
    if (tmp5 != NULL) {
        mus->DiscNum = atoi(tmp5);
    } else {
        mus->DiscNum = 0;
    }
    // mus->DiscNum = atoi(strsep(&line, ","));
    char* tmp6 = strsep(&line, ",");
    if (tmp6 != NULL) {
        mus->TrackNum = atoi(tmp6);
    } else {
        mus->TrackNum = 0;
    }
    // mus->TrackNum = atoi(strsep(&line, ","));
    char* tmp7 = strsep(&line, ",");
    if (tmp7 != NULL) {
        mus->Year = atoi(tmp7);
    } else {
        mus->Year = 0;
    }
    // mus->Year = atoi(strsep(&line, ","));

    // printf("%u\n", mus->Year);
    return mus;
}

Liste creerLaListeDesMusiques(FILE* f) {
    char buffer[1024];
    Musique* mus;
    Liste l = malloc(sizeof(Liste));
    while(fgets(buffer,1024,f) != NULL) {
        mus = creerUneMusique(buffer);
        ajoutFin_i(mus,l);
        // ajoutTete(mus,l);
        // printf("%s\n", "passeLeAjoutFin");
    }
    printf("%s\n", "sort du while");
    return(l);
}

// void creerLaListeDesMusiques(FILE* f, Liste l) {
//     char buffer[1024];
//     Musique* mus;
//     // Liste l = malloc(sizeof(Liste));
//     while(fgets(buffer,1024,f) != NULL) {
//         mus = creerUneMusique(buffer);
//         ajoutFin_i(mus,l);
//         printf("%s\n", "passe le AjoutFin");
//     }
//     // return(l);
// }

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
    printf("%s\n", "normalement la liste est créée là");

    printf("%d\n", estVide(l));



    // //Tests sur un élément
    // Musique musTest;
    // musTest.Album = "nomAlbum";
    // musTest.Artist = "blues sisteers";
    // musTest.DiscNum = 21;
    // musTest.Genre = "nomdu genre pop";
    // musTest.Name = "la chanson de la tartine";
    // // musTest.TrackNum = 8;
    // musTest.Year = 1999;

    // Liste lBis = malloc(sizeof(Liste));
    // printf("normalement la liste BIS\n");
    // lBis = creer(&musTest);
    // printf("normalement la liste BIS\n");
    // afficheListe_i(lBis);





    // Liste l = malloc(sizeof(Liste));
    // creerLaListeDesMusiques(f,l);

    afficheListe_i(l);
    // afficheListe_r(l);

    // detruire_r(l);
    // detruire_i(l);

    //TODO : c'est le afficheListe_i, le afficheListe_r, le detruire_i et le detruire_r qui font des erreurs de segmentation, le reste ça va
    fclose(f);
    return EXIT_SUCCESS;
}