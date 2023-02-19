#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

#define QUEUE_SIZE 1000

struct queue {
    int size, l, r;
    int data[QUEUE_SIZE];
};

struct queue *new_queue(void) {
    struct queue *q = malloc(sizeof(struct queue));

    if (q != NULL) q->r = q->l = q->size = 0;

    return q;
}

bool enqueue(struct queue *q, int data) {
    if (q->size == QUEUE_SIZE) return false;

    q->data[q->r] = data;
    q->size++;
    q->r = (q->r+1)%QUEUE_SIZE;
    return true;
}

bool dequeue(struct queue *q) {
    if (!(q->size)) return false;

    q->size--;
    q->l = (q->l+1)%QUEUE_SIZE;
    return true;
}

int front(struct queue *q) {
    if (!(q->size)) return -1;

    return q->data[q->l];
}

int size(struct queue *q) {
    return q->size;
}

bool is_empty(struct queue *q) {
    if (q->size) return true;
    return false;
}

void free_queue(struct queue *q) {
    free(q);
    return;
}
