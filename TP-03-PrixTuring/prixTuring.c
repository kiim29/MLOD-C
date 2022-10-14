/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine() {
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}
	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

typedef struct {
	unsigned int Annee;
	char *Nom;
	char *Raison;
} Winner;

void readUnWinner(Winner *t, int index){
	t[index].Annee = scanLineAsInt();
	t[index].Nom = scanLine();
	t[index].Raison = scanLine();
}

void readWinners(Winner *t, unsigned int N){
	int i;
	for(i=0; i<N; i++) {
		readUnWinner(t, i);
	}
}

void printUnWinner(Winner w) {
	printf("%i\n", w.Annee);
	printf("%s\n", w.Nom);
	printf("%s\n", w.Raison);
}

void printWinners(Winner *t, unsigned int N){
	int i;
	for(i=0; i<N; i++) {
		printUnWinner(t[i]);
	}
}

int main(void) {

	int nbGagnants = scanLineAsInt();
	printf("nbGagnants = %i\n",nbGagnants);

	Winner *t;
	t = (Winner *) calloc(nbGagnants, sizeof(Winner));
	readWinners(t, nbGagnants);
	printWinners(t, nbGagnants);
	free(t);

	return EXIT_SUCCESS;
}
