#include "Menge_Bitvektor.h"

Set createSet() {
	Set s = malloc(sizeof(tBase_32));
	if (s != NULL) {
		s->min, s->set = 0;
		s->max = 31;
		return s;
	}
	printf("1");
	abort();
	
}

int isEmpty(Set s) {
	if (s->set == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int isInRange(Set s, int v) {
	if (v >= s->min && v <= s->max) {
		return 1;
	}
	printf("2");
	abort();
}

Set add(Set s, int v) {
	if (isEmpty(s)) {
		s->set += 1 << 0;
		s->max += v;
		s->min = v;
		return s;
	}
	else {
		if (isInRange(s, v)) {
			int dist = v - s->min;
			s->set += 1 << dist;
			return s;
		}
		else {
			printf("3");
			abort();
		}
	}
}

Set removeValue(Set s, int v) {
	return s;
}

void printSet(Set s){}

Set combine(Set s1, Set s2) {
	return s1;
}

Set average(Set s1, Set s2) {
	return s1;
}

int isInSet(Set s1, int v) {
	return 0;
}