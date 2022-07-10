#include <stdio.h>
#include <stdlib.h>

#include "Menge_Array.h"

int main(int argc, char* argv[]) {
	
	Menge m = create(2);

	Menge n = create(5);

	m = add(m, 4);
	m = add(m, 5);

	printMenge(m);

	n = add(n, 1);
	n = add(n, 2);
	n = add(n, 4);
	n = add(n, 3);
	n = add(n, 5);

	printMenge(n);

	Menge z = average(m, n);

	printMenge(z);
	
	return 0;
}