#include <stdio.h>
#include "echangeContenu.h"
#include "echangeContenu.c"

int main(void)
{
	int a=4,b=14;

	printf ("a = %d\tb = %d\n", a, b);

	// TODO
	echangeContenu(&a, &b);

	printf ("a et b echanges \n");
	printf ("a = %d\tb = %d\n", a, b);

	return 0;
}

