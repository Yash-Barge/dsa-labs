#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "queue.h"

struct queue {
    struct linked_list *list;
};

struct queue *new_queue(void) {
    struct queue *q = malloc(sizeof(struct queue));
    q->list = new_list();

    return q;
}

void enqueue(struct queue *q, int data) {
    ll_append(q->list, data);
    return;
}

void dequeue(struct queue *q) {
    ll_remove_first(q->list);
    return;
}

int front(struct queue *q) {
    return q->list->head->data;
}

int size(struct queue *q) {
    return q->list->size;
}

bool is_empty(struct queue *q) {
    if (size(q)) return true;
    return false;
}

void free_queue(struct queue *q) {
    struct node *temp = q->list->head;
    struct node *prev = NULL;

    for (int i = 0; i < q->list->size; i++) {
        prev = temp;
        temp = temp->next;
        free(prev);
    }

    free(q->list);
    free(q);
    return;
}
