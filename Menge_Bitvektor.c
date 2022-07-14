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
			if (!isInSet(s, v)) {
				int dist = v - s->min;
				s->set += 1 << dist;
				return s;
			}
			else {
				return s;
			}
		}
		else {
			printf("3");
			abort();
		}
	}
}

Set removeValue(Set s, int v) {
	if (isEmpty(s)) {
		printf("4");
		abort();
	}
	else {
		if (isInRange(s, v)) {
			if (isInSet(s, v)) {
				int dist = v - s->min;
				s->set -= (int)pow((double)2, (double)dist);
				return s;
			}
			else {
				return s;
			}
		}
		else {
			return s;
		}
	}
}

void printSet(Set s){

	printf("\nSet = {");
	for (int i = 0; i < 32; i++) {
		if (CHECK_BIT(s->set, i)) {
			printf("%d, ", s->min + i);
		}
	}
	printf("}");
	printf("\nSet as binary: ");
	for (int i = 0; i < 32; i++) {
		if (CHECK_BIT(s->set, i)) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n\n");
	return;
}

Set combine(Set s1, Set s2) {
	Set t = createSet();
	if (s1->min == s2->min) {
		t->min = s1->min;
		t->max = s1->max;
		t->set = (s1->set | s2->set);
		return t;
	}
	else {
		printf("5");
		abort();
	}
}

Set average(Set s1, Set s2) {
	Set t = createSet();
	if (s1->min == s2->min) {
		t->min = s1->min;
		t->max = s1->max;
		t->set = (s1->set & s2->set);
		return t;
	}
	else {
		printf("5");
		abort();
	}
}

int isInSet(Set s, int v) {
	v -= s->min;

	if (isEmpty(s)) {
		return 0;
	}
	else {
		if (CHECK_BIT(s->set, v)) {
			return 1;
		}
		return 0;
	}

	return 0;
}