#ifndef H_STACK
#define H_STACK

#include <stdbool.h>

#include "linked_list.h"

struct linked_list *new_stack(void);
void push(struct linked_list *s, int e);
int top(struct linked_list *s);
void pop(struct linked_list *s);
bool is_empty(struct linked_list *s);
void free_stack(struct linked_list *s);

#endif
