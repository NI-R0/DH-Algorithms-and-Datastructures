#include <stdio.h>
#include <stdlib.h>

#include "Menge_Bitvektor.h"

int main(int argc, char* argv[]) {
	/*int i = 10;
	i += 1 << 0;
	printf("%d", i);*/

	Set s = createSet();

	s = add(s, 5);

	s = add(s, 8);
	
	return 0;
}