#ifndef H_STACK
#define H_STACK

#include <stdbool.h>

#include "linked_list.h"

struct stack;

struct stack *new_stack(void);
void push(struct stack *s, int e);
int top(struct stack *s);
void pop(struct stack *s);
bool is_empty(struct stack *s);
void free_stack(struct stack *s);

#endif
