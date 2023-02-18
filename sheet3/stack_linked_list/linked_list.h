#ifndef H_LINKED_LIST
#define H_LINKED_LIST

struct node {
    int data;
    struct node *next;
};

struct linked_list {
    int size;
    struct node *head;
};

struct linked_list *new_list(void);
struct node *new_node(int data);
void ll_prepend(struct linked_list *l, int data);
void ll_remove_first(struct linked_list *l);
void ll_append(struct linked_list *l, int data);

#endif
