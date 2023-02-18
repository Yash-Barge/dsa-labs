#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "stack.h"

struct stack {
    struct linked_list *list;
};

struct stack *new_stack(void) {
    struct stack *s = malloc(sizeof(struct stack));
    s->list = new_list();
    return s;
}

void push(struct stack *s, int e) {
    ll_prepend(s->list, e);
    return;
}

int top(struct stack *s) {
    return s->list->head->data;
}

void pop(struct stack *s) {
    ll_remove_first(s->list);
    return;
}

bool is_empty(struct stack *s) {
    if (s->list->size) return true;
    return false;
}

void free_stack(struct stack *s) {
    struct node *temp = s->list->head;
    struct node *prev = NULL;

    for (int i = 0; i < s->list->size; i++) {
        prev = temp;
        temp = temp->next;
        free(prev);
    }

    free(s->list);
    free(s);
    return;
}
