#pragma once
#ifndef LIST_H
#define LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct tNode* List;

typedef struct tNode {
    int value;
    List* next;
} tNode;

int printList(List);

int searchValue(int, List);

int countNodes(List);

List createNode(int, List);

List appendNode(int, List);

List head(List);

List tail(List);

List deleteNode(int, List);

List deleteAllValues(int, List);

List reverseList(List);

#endif