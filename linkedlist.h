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

