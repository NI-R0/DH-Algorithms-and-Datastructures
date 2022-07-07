#pragma once
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include<stdio.h>
#include<stdlib.h>

typedef struct tBase* Stack;

typedef struct tBase {
    int* data;
    int topIndex;
    int max;
} tBase;

int isEmpty(Stack);

int top(Stack);

Stack create(int);

Stack push(Stack, int);

Stack pop(Stack);

#endif
