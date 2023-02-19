#include <stdio.h>

#include "queue.h"

int main(void) {
    struct queue *q = new_queue();
    if(is_empty(q)) printf("Queue is empty\n");
    
    enqueue(q, 1);
    int value = front(q);
    printf("Front of queue is %d\n", value);

    enqueue(q, 2);
    value = front(q);
    printf("Front of queue is %d\n", value);

    value = front(q);
    printf("Front of queue is %d\n", value);
    
    dequeue(q);

    value = front(q);
    printf("Front of queue is %d\n", value);
    printf("Dequeue returned %s\n", dequeue(q) ? "true" : "false");

    printf("Trying to dequeue an empty queue\n");
    printf("Dequeue returned %s\n", dequeue(q) ? "true" : "false");

    free_queue(q);
    return 0;
}
