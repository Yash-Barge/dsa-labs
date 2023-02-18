#ifndef H_STACK
#define H_STACK

#include <stdbool.h>

struct stack;

struct stack *new_stack(void);
bool push(struct stack *s, int e);
int top(struct stack *s);
bool pop(struct stack *s);
bool is_empty(struct stack *s);
void free_stack(struct stack *s);

#endif
