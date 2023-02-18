#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data) {
    struct node *n = malloc(sizeof(struct node));

    n->data = data;
    n->next = NULL;

    return n;
}

void append_node(struct node *n, struct node *head) {
    if (head == NULL) {
        head = n;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = n;

    return;
}

void print_list(struct node *n) {
    struct node *temp = n;

    printf("[HEAD] -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("[NULL]\n");

    return;
}

int has_cycle(struct node *list) {
    struct node *tortoise = list;
    struct node *hare = list;
    int flag = 0;

    while (!flag) {
        if (tortoise == NULL || hare == NULL || hare->next == NULL) break;

        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare) flag = 1;
    }

    return flag;
}

int main(void) {
    struct node *list_acyclic = create_node(1);
    append_node(create_node(2), list_acyclic);
    append_node(create_node(3), list_acyclic);
    print_list(list_acyclic);
    printf("list_acyclic has_cycle(): %d\n", has_cycle(list_acyclic));

    struct node *temp = create_node(3);
    struct node *prev = create_node(2);

    struct node *list_cyclic = create_node(1);
    append_node(prev, list_cyclic);
    append_node(temp, list_cyclic);
    temp->next = prev;
    // print_list(list_cyclic);
    printf("list_cyclic has_cycle(): %d\n", has_cycle(list_cyclic));

    temp = create_node(3);
    struct node *list_circular = create_node(1);
    append_node(create_node(2), list_circular);
    append_node(temp, list_circular);
    temp->next = list_circular;
    // print_list(list_circular);
    printf("list_circular has_cycle(): %d\n", has_cycle(list_circular));

    return 0;
}
