#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct linked_list {
    struct node *head;
    struct node *tail;
};

struct node *new_node(int data) {
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;

    return n;
}

struct linked_list *new_linked_list(void) {
    struct linked_list *l = malloc(sizeof(struct linked_list));
    l->head = NULL;
    l->tail = NULL;

    return l;
}

void append(struct node *n, struct linked_list *l) {
    if (l->head == NULL) l->head = l->tail = n;
    else l->tail = l->tail->next = n;

    return;
}

void print_linked_list(struct linked_list *l) {
    struct node *temp = l->head;

    printf("[HEAD] -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("[NULL]\n");

    return;
}

void rotate_list(struct linked_list *l, int k) {
    if (k < 0) {
        printf("Please enter valid number of steps.\n");
        return;
    }

    l->tail->next = l->head;

    for (int i = 0; i < k; i++) {
        l->head = l->head->next;
        l->tail = l->tail->next;
    }

    l->tail->next = NULL;

    return;
}

int main(void) {
    struct linked_list *list = new_linked_list();

    append(new_node(1), list);
    append(new_node(2), list);
    append(new_node(3), list);
    append(new_node(4), list);
    append(new_node(5), list);
    append(new_node(6), list);
    print_linked_list(list);

    printf("Rotating list by 3 steps...\n");
    rotate_list(list, 3);
    print_linked_list(list);

    return 0;
}
