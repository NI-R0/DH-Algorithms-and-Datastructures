#include "List.h"

List createNode(int data, List l) {
    List h = malloc(sizeof(tNode));
    if (h != NULL) {
        h->value = data;
        h->next = l;
        return h;
    }
    else {
        printf("STORAGE ALLOCATION ERROR");
        return h;
    }
}

List appendNode(int data, List l) {
    if (l == NULL) {
        return createNode(data, l);
    }
    List temp = l;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(data, NULL);
    return l;
}

int printList(List l) {

    if (l == NULL) {
        printf("\nDie Liste ist leer!");
        return 0;
    }
    printf("\n");
    while (l != NULL) {
        printf("\n%d", l->value);
        l = l->next;
    }
    printf("\n\n");
    return 0;
}

int searchValue(int value, List l) {
    if (l == NULL) {
        printf("\nELEMENT NOT IN LIST\n");
        return 0;
    }
    else if (l->value == value) {
        printf("\nELEMENT FOUND\n");
        return 1;
    }
    else {
        return searchValue(value, l->next);
    }
}

List head(List l) {
    //printf("\nHead of list: %d\n", l->value);
    return createNode(l->value, NULL);
}

List tail(List l) {
    return l->next;
}

//Position count starts at 0!
List deleteNode(int pos, List l) {
    
    List o = l;
    int c = countNodes(o);

    if (o == NULL || pos > c || pos < 0) {
        printf("Node could not be deleted!");
        return l;
    }
    else {
        if (pos == 0) {
            printList(o);
            List temp = o;
            o = o->next;
            free(temp);
            printList(o);
            return l;
        }
        else {
            for (int i = 0; i < pos - 1; i++) {
                //Iterates to the position ONE PRIOR to the node which should be deleted
                o = o->next;
            }
            List temp = o->next;
            o->next = temp->next;
            free(temp);
            return l;
        }
    }
}

List deleteAllValues(int val, List l) {
    List o = l;
    if (o == NULL) {
        return o;
    }
    while (o->next != NULL) {
        List temp = o->next;
        if (temp->value == val) {
            o = deleteNode(1, o);
        }
        else {
            o = o->next;
        }
    }
    return l;
}

int countNodes(List l) {
    int count = 0;

    while (l != NULL) {
        count++;
        l = l->next;
    }

    return count;
}

List reverseList(List l) {
    if (l == NULL) {
        return l;
    }
    else {
        return appendNode(head(l)->value, reverseList(tail(l)));
    }
}