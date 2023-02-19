#include <stdlib.h>

#include "linked_list.h"

struct linked_list *new_list(void) {
    struct linked_list *l = malloc(sizeof(struct linked_list));
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;

    return l;
}

struct node *new_node(int data) {
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;

    return n;
}

void ll_prepend(struct linked_list *l, int data) {
    struct node *n = new_node(data);
    
    if (l->size++) n->next = l->head;
    else l->tail = n;

    l->head = n;

    return;
}

void ll_remove_first(struct linked_list *l) {
    if (!(l->size)) return;

    struct node *temp = l->head;
    l->head = l->head->next;
    if (l->size == 1) l->tail = NULL;
    free(temp);
    l->size--;

    return;
}

void ll_append(struct linked_list *l, int data) {
    struct node *n = new_node(data);

    if (!(l->size++)) {
        l->head = n;
        l->tail = n;
        return;
    }

    l->tail = l->tail->next = n;

    return;
}
