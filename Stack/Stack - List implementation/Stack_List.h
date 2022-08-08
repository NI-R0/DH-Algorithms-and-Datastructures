#pragma once
#ifndef STACK_LIST_H
#define STACK_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct tBase* Stack;

typedef struct tBase {
	int value;
	Stack next;
} tBase;

int top(Stack);

int empty(Stack);

Stack create();

Stack push(int, Stack);

Stack pop(Stack);


#endif