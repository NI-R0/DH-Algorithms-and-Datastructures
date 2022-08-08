#include "Stack_Array.h"

Stack create(int max) {
    Stack s = malloc(sizeof(tBase));
    if (s != NULL) {
        s->data = malloc(sizeof(int) * max);
        if (s->data != NULL) {
            s->topIndex = -1;
            s->max = max;
            return s;
        }
        else {
            printf("Speicher voll!");
            abort();
        }
    }
    else {
        printf("Speicher voll!");
        abort();
    }
}


int isEmpty(Stack s) {
    return (s->topIndex == -1);
}


Stack push(Stack s, int data) {
    
    if(s->topIndex < s->max) {
        s->topIndex += 1;
        s->data[s->topIndex] = data;
        return s;
    }
    else {
        printf("STACK IS FULL");
        abort();
    }
}


int top(Stack s) {
    if (isEmpty(s)) {
        printf("STACK IS EMPTY");
        abort();
    }
    return s->data[s->topIndex];
}


Stack pop(Stack s){
    if (isEmpty(s)) {
        printf("STACK IS EMPTY");
        abort();
    }
    else {
        s->data[s->topIndex] = NULL;
        s->topIndex -= 1;
        return s;
    }
}