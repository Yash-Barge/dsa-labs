#include <stdio.h>
#include "stack.h"

int main(void) {
    struct stack *s = new_stack();

    if(is_empty(s)) printf("Stack is empty\n");
    
    push(s, 1);
    int value = top(s);
    printf("Top of stack is %d\n", value);

    push(s, 2);
    value = top(s);
    printf("Top of stack is %d\n", value);

    value = top(s);
    printf("Top of stack is %d\n", value);
    
    pop(s);

    value = top(s);
    printf("Top of stack is %d\n", value);
    printf("Pop returned %s\n", pop(s) ? "true" : "false");

    printf("Trying to pop an empty stack\n");
    printf("Pop returned %s\n", pop(s) ? "true" : "false");

    free_stack(s);
    return 0;
}
