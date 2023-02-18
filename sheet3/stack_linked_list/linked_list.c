#include <stdlib.h>

#include "linked_list.h"

struct linked_list *new_list(void) {
    struct linked_list *l = malloc(sizeof(struct linked_list));
    l->size = 0;
    l->head = NULL;

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
    l->head = n;

    return;
}

void ll_remove_first(struct linked_list *l) {
    if (!(l->size)) return;

    struct node *temp = l->head;
    l->head = l->head->next;
    free(temp);
    l->size--;

    return;
}

void ll_append(struct linked_list *l, int data) {
    struct node *n = new_node(data);

    if (!(l->size++)) {
        l->head = n;
        return;
    }

    struct node *temp = l->head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = n;

    return;
}
