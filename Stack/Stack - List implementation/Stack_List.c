#include "Stack_List.h"

Stack create() {
    return NULL;
}

Stack push(int data, Stack s) {
    
    Stack n = malloc(sizeof(tBase));
    if (n != NULL) {
        n->value = data;
        n->next = s;
        return n;
    }
    else {
        printf("STORAGE ALLOCATION ERROR");
        abort();
    }
}

Stack pop(Stack s) {
    if (empty(s)) {
        abort();
    }
    Stack temp = s;
    s = s->next;
    free(temp);
    return s;
}

int top(Stack s) {
    if (empty(s)) {
        abort();
    }
    return s->value;
}

int empty(Stack s) {
    return (s == NULL);
}