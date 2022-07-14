#include <stdio.h>
#include <stdlib.h>

#include "Menge_Bitvektor.h"

int main(int argc, char* argv[]) {
	/*int i = 10;
	i += 1 << 0;
	printf("%d", i);*/

	Set s = createSet();
	Set t = createSet();

	s = add(s, 5);
	t = add(t, 5);

	s = add(s, 8);
	t = add(t, 15);

	s = add(s, 32);

	t = average(s, t);

	printSet(t);


	
	return 0;
}