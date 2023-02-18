#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "stack.h"

struct linked_list *new_stack(void) {
    return new_list();
}

void push(struct linked_list *s, int e) {
    ll_prepend(s, e);
    return;
}

int top(struct linked_list *s) {
    return s->head->data;
}

void pop(struct linked_list *s) {
    ll_remove_first(s);
    return;
}

bool is_empty(struct linked_list *s) {
    if (s->size) return true;
    return false;
}

void free_stack(struct linked_list *s) {
    struct node *temp = s->head;
    struct node *prev = NULL;

    for (int i = 0; i < s->size; i++) {
        prev = temp;
        temp = temp->next;
        free(prev);
    }

    free(s);
    return;
}
