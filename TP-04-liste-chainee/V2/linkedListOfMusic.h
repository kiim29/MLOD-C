// Comment compiler : gcc -W -Wall linkedList.c linkedListOfMusic.c mySpitofy.c -o mySpitofy


#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct {
	char *Name;
	char *Artist;
	char *Album;
	char *Genre;
	unsigned int DiscNum;
	unsigned int TrackNum;
	unsigned int Year;
} Musique;

Musique* creerUneMusique(char*);

Liste creerLaListeDesMusiques(FILE* f);

// void creerLaListeDesMusiques(FILE* f, Liste l);

// typedef Element Musique;