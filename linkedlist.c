#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "linkedlist.h"

int mainx() {
    struct linkedlist *l = newll(stringcmp);
    char *a = "abc", *b = "def", *c = "ghi", *d = "jkl";
    
    addtoll(l, (void *) d);
    addtoll(l, (void *) a);
    addtoll(l, (void *) c);
    addtoll(l, (void *) b);
    
    struct node *curr = l->first;
    while (curr != NULL) {
        printf("Node[%s]\n", (char *)(curr->value));
        curr = curr->next;
   }
    
    utilizell(l);
    
    return 0;
}

struct linkedlist * newll(int (*cmp)(void *, void *)) {
    struct linkedlist *l = (struct linkedlist *) malloc(sizeof(struct linkedlist));
    l->first = NULL;
    l->cmp = cmp;

    return l;
}

struct node * addtoll(struct linkedlist *l, void *value) {
    struct node *elem;

    elem = (struct node *) malloc(sizeof(*elem));
    elem->value = value;
    // (*elem).value = value;
    elem->next = NULL;
    
    if (l->first == NULL) {
        l->first = elem;
    } else {
        struct node *lastelem = l->first;
        while (lastelem->next != NULL) {
            lastelem = lastelem->next;
        }

        lastelem->next = elem;
    }
    
    return elem;      
}

void utilizell(struct linkedlist *l) {
    struct node *curr = l->first;
    struct node *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(l);
}

int intcmp(void *a, void *b) {
    int ai = *((int *) a);
    int bi = *((int *) b);

    return ai > bi ? -1 : (ai < bi ? 1 : 0);
}

int stringcmp(void *a, void *b) {
    char *ai = (char *) a;
    char *bi = (char *) b;

    return strcmp(ai, bi);
}

