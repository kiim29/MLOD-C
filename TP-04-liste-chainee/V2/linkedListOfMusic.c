
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct {
	char *Name;
	char *Artist;
	char *Album;
	char *Genre;
	unsigned int DiscNum;
	unsigned int TrackNum;
	unsigned int Year;
} Musique;

void afficheElement(Element e) {
    printf("%s - ", ((Musique *)e)->Name);
    printf("%s - ", ((Musique *)e)->Artist);
    printf("%s - ", ((Musique *)e)->Album);
    printf("%s - ", ((Musique *)e)->Genre);
    printf("%i - ", ((Musique *)e)->DiscNum);
    printf("%i - ", ((Musique *)e)->TrackNum);
    printf("%i", ((Musique *)e)->Year);
};

void detruireElement(Element e) {
    free((Musique *)e);
};

bool equalsElement(Element e1, Element e2) {
    return (
        strcmp(((Musique *)e1)->Name,((Musique *)e2)->Name)==0 &&
        strcmp(((Musique *)e1)->Artist,((Musique *)e2)->Artist)==0 && 
        strcmp(((Musique *)e1)->Album,((Musique *)e2)->Album)==0 &&
        strcmp(((Musique *)e1)->Genre,((Musique *)e2)->Genre)==0 &&
        (((Musique *)e1)->DiscNum == ((Musique *)e2)->DiscNum) &&
        (((Musique *)e1)->TrackNum == ((Musique *)e2)->TrackNum) &&
        (((Musique *)e1)->Year == ((Musique *)e2)->Year)
    );
};