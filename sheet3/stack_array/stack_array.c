#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

#define STACK_SIZE 1000

struct stack {
    int size;
    int data[STACK_SIZE];
};

struct stack *new_stack(void) {
    struct stack *s = malloc(sizeof(struct stack));
    if (s != NULL) s->size = 0;
    return s;
}

bool push(struct stack *s, int e) {
    if (s->size == STACK_SIZE) return false;
    s->data[s->size++] = e;
    return true;
}

int top(struct stack *s) {
    if (!(s->size)) return -1;
    return s->data[s->size - 1];
}

bool pop(struct stack *s) {
    if (!(s->size)) return false;
    s->size--;
    return true;
}

bool is_empty(struct stack *s) {
    if (s->size) return true;
    return false;
}

void free_stack(struct stack *s) {
    free(s);
    return;
}
