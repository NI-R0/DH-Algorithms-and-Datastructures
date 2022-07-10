#include "Menge_Array.h"

Menge create(int size) {
	Menge m = malloc(sizeof(tBase));
	if (m != NULL && size > 0) {
		m->set = malloc(sizeof(int) * size);
		m->size = size;
		m->min = 0;

		if (m->set != NULL) {
			for (int i = 0; i < m->size; i++) {
				m->set[i] = 0;
			}
		}

		return m;
	}
	else {
		printf("1");
		abort();
	}
}

int isEmpty(Menge m) {
	for (int i = 0; i < m->size; i++) {
		if (m->set[i] != 0) {
			return 0;
		}
	}
	return 1;
}

int isInRange(int val, Menge m) {
	if (val >= m->min && val <= (m->min + (m->size - 1))) {
		return 1;
	}
	return 0; //abort?
}

Menge add(Menge m, int val) {
	if (isEmpty(m)) {
		m->set[0] = 1;
		m->min = val;
		return m;
	}
	else {
		if (isInRange(val, m)) {
			m->set[(val - m->min)] = 1;
			return m;
		}
		else {
			printf("2");
			abort();
		}
	}
}

Menge removeItem(int val, Menge m) {
	if (isEmpty(m)) {
		printf("");
		abort();
	}
	else {
		if (isInRange(val, m)) {
			m->set[(val - m->min)] = 0;
			return m;
		}
		else {
			printf("3");
			abort();
		}
	}
}

void printMenge(Menge m) {
	if (isEmpty(m)) {
		printf("Die Menge ist leer!");
		return;
	}
	else {
		printf("\n{");
		for (int i = m->min; i < (m->min + m->size); i++) {
			if (m->set[(i - m->min)] == 1) {
				printf("%d; ", i);
			}
		}
		printf("}\n");
		return;
	}
}

Menge combine(Menge m1, Menge m2) {
	int max = 0;
	int size = 0;
	int min = 0;
	((m1->size + m1->min) >= (m2->size + m2->min)) ? (max = m1->size + m1->min) : (max = m2->size + m2->min);
	(m1->min >= m2->min) ? (min = m2->min) : (min = m1->min);

	size = (max - min);

	Menge n = create(size);

	for (int i = 0; i < m1->size; i++) {
		if (m1->set[i] == 1) {
			n = add(n, (i + m1->min));
		}
	}

	for (int i = 0; i < m2->size; i++) {
		if (m2->set[i] == 1) {
			n = add(n, (i + m2->min));
		}
	}

	return n;
}

Menge average(Menge m1, Menge m2) {
	int max = 0;
	int size = 0;
	int min = 0;
	((m1->size + m1->min) >= (m2->size + m2->min)) ? (max = m1->size + m1->min) : (max = m2->size + m2->min);
	(m1->min >= m2->min) ? (min = m2->min) : (min = m1->min);

	size = (max - min);

	Menge avg = create(size);

	for (int i = 0; i < m1->size; i++) {
		if (m1->set[i] == 1 && isInMenge(m2, i+m1->min)) {
			avg = add(avg, (i + m1->min));
		}
	}

	/*for (int i = 0; i < m2->size; i++) {
		if (m2->set[i] == 1 && isInMenge(m1, i + m2->min)) {
			avg = add(avg, (i + m2->min));
		}
	}*/

	return avg;
}

int isInMenge(Menge m, int val) {
	if (isInRange(val, m)) {
		if (m->set[val - m->min] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}