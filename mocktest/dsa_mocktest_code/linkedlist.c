#include "linkedlist.h"
#include <stdio.h>

static node *create_node_for_list(process p);
// Check header files for documentation/ function description
process_linked_list *create_empty_process_linked_list() {
    // COMPLETE
    process_linked_list *l = malloc(sizeof(process_linked_list));

    if (l != NULL) {
        l->size = 0;
        l->head = NULL;
    }
    return l;
}

bool add_first_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, 0, p);
}

bool add_last_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, list->size, p);
}

bool add_at_index_linked_list(process_linked_list *list, size_t index, process p) {
   // COMPLETE
   if (index < 0 || index > list->size) return false;

    node *n = create_node_for_list(p);
    if (n == NULL) return false;

    if (!(list->size)) list->head = n;
    else if (!index) {
        n->next = list->head;
        list->head->previous = n;
        list->head = n;
    } else if (index == list->size) {
        node *temp = list->head;
        while (temp->next != NULL) temp = temp->next;
        
        temp->next = n;
        n->previous = temp;
    } else {
        node *temp = list->head;
        for (int i = 1; i < index; i++) temp = temp->next;

        n->next = temp->next->next;
        n->previous = temp;
        n->next->previous = n;
        temp->next = n;
    }

    (list->size)++;
    return true;
}

bool remove_first_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }
   // COMPLETE
    if (list->size == 1) {
        *p = *(list->head->process);
        free(list->head);
        list->head = NULL;
    } else {
        node *temp = list->head;

        list->head = list->head->next;
        list->head->previous = NULL;

        *p = *(temp->process);

        free(temp);
   }

    (list->size)--;

   return true;
}

bool remove_last_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }
   // COMPLETE
   if (list->size == 1) {
        *p = *(list->head->process);
        free(list->head);
    list->head = NULL;
    } else {
        node *temp = list->head;
        while (temp->next->next != NULL) temp = temp->next;

        *p = *(temp->next->process);

        free(temp->next);
        temp->next = NULL;
    }

    (list->size)--;

    return true;
}

size_t get_size_linked_list(process_linked_list *list) {
    return list->size;
}

void print_linked_list(process_linked_list *list) {
    node *tracker = list->head;
    while (tracker != NULL) {
        printf("%d => ", tracker->process->pid);
        tracker = tracker->next;
    }
    printf("NULL\n");
}

static node *create_node_for_list(process p) {
    process *to_add_process = malloc(sizeof(process));
    if (!to_add_process) {
        return NULL;
    }
    *to_add_process = p;
    node *new_node = malloc(sizeof(node));
    if (!new_node) {
        return NULL;
    }
    new_node->process = to_add_process;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}


void destroy_linked_list(process_linked_list *list) {
    node *current = list->head->next;
    for (int i = 0; i < list->size; ++i) {
        node *next = current->next;
        free(current->process);
        current = next;
    }
    free(list->head);
    free(list);
}
