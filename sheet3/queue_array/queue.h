#ifndef H_QUEUE
#define H_QUEUE

#include <stdbool.h>

struct queue;

struct queue *new_queue(void);
bool enqueue(struct queue *q, int data);
bool dequeue(struct queue *q);
int front(struct queue *q);
int size(struct queue *q);
bool is_empty(struct queue *q);
void free_queue(struct queue *q);

#endif
