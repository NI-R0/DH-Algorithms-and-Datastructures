#pragma once
#ifndef MENGE_BITVEKTOR_H
#define MENGE_BITVEKTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tBase_32* Set;

typedef struct tBase_32 {
	int set;
	int min;
	int max;
} tBase_32;

Set createSet();

int isEmpty(Set);

int isInRange(Set, int);

Set add(Set, int);

Set removeValue(Set, int);

void printSet(Set);

Set combine(Set, Set);

Set average(Set, Set);

int isInSet(Set, int);




#endif