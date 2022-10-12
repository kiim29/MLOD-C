#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    // int i;
    // // we pass the addresses of variables to scanf
    // printf("entrer un nb: ");
    // scanf("%d",&i);
    // printf("%i\n",i);
    char s[2]; /* ATTENTION 2 caractères au plus dont le \0 terminal */
    scanf("%s",s);
    printf("[%lu] >%s<\n",strlen(s),s);
}