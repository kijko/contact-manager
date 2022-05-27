#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node {
    void *value;
    struct node *next;
};

struct linkedlist {
    struct node *first;
    int (*cmp)(void *, void*);
};

struct linkedlist * newll(int (*cmp)(void *, void *));
struct node * addtoll(struct linkedlist *l, void *value);
void utilizell(struct linkedlist *l);
int intcmp(void *a, void *b);


int main() {
    struct linkedlist *l = newll(intcmp);
    int a = 4, b = 2, c = 3, d = 4;
    
    addtoll(l, (void *) &a);
    addtoll(l, (void *) &b);
    addtoll(l, (void *) &c);
    addtoll(l, (void *) &d);
    
    struct node *curr = l->first;
    while (curr != NULL) {
        printf("Node[%d]\n", *((int *)(curr->value)));
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
    int one = 2;
    printf("cmp: %d", (*(l->cmp))((void *) &one, value));

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
