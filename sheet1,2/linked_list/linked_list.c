#include <stdio.h>
#include <stdlib.h>

struct node {
	int ele;
	struct node *next;
};

struct linked_list {
	int count;
	struct node *head;
};

struct linked_list *create_new_list(void) {
	struct linked_list *list;

	list = malloc(sizeof (struct linked_list));
	list->count = 0;
	list->head = NULL;
	
	return list;
}

struct node *create_new_node(int value) {
	struct node *my_node;

	my_node = malloc(sizeof(struct node));
	my_node->ele = value;
	my_node->next = NULL;

	return my_node;
}

void insert_after(int element, struct node *n, struct linked_list *l) {
	if (l->head == NULL) {
		l->head = n;
		l->count++;
	} else {
		struct node *temp = l->head;
		struct node *prev = NULL;

		while (temp != NULL) {
			if (temp->ele == element) break;
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL) printf("Element not found\n");
		else {
			prev = temp;
			temp = temp->next;
			prev->next = n;
			n->next = temp;
			l->count++;
		}
	}

	return;
}

void print_list(struct linked_list *l) {
	struct node *temp = l->head;
	
	printf("[HEAD] -> ");
	while (temp != NULL) {
		printf("%d -> ", temp->ele);
		temp=temp->next;
	}
	printf("[NULL]\n");

	return;
}

void delete_at(int index, struct linked_list *l) {
	if (index < 0 || index >= l->count) {
		printf("Index out of bounds.\n");
		return;
	}

	struct node *temp = l->head;
	struct node *prev = l->head;
	
	for (int i = 0; i < index; i++) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == l->head) {
		struct node *next = temp->next;
		free(temp);
		l->head = next;

		return;
	}

	struct node *next = temp->next;
	free(temp);
	prev->next = next;

	return;
}

void insert_first(struct node *n, struct linked_list *l) {
	struct node *temp = l->head;
	l->head = n;
	n->next = temp;

	return;
}

void delete_first(struct linked_list *l) {
	delete_at(0, l);
	return;
}

int search(int data, struct linked_list *l) {
	struct node *temp = l->head;
	int index = 0;

	while (temp != NULL) {
		if (temp->ele == data) break;
		temp = temp->next;
		index++;
	}

	if (temp == NULL) return -1;
	
	return index;
}

int main(void) {
	struct linked_list *my_list = create_new_list();

	insert_after(0, create_new_node(1), my_list);
	insert_after(1, create_new_node(3), my_list);
	insert_after(1, create_new_node(2), my_list);
	insert_after(3, create_new_node(4), my_list);

	print_list(my_list);

	delete_at(4, my_list);
	print_list(my_list);

	delete_at(3, my_list);
	print_list(my_list);

	delete_at(0, my_list);
	print_list(my_list);

	insert_first(create_new_node(1), my_list);
	print_list(my_list);

	insert_first(create_new_node(0), my_list);
	print_list(my_list);

	delete_first(my_list);
	print_list(my_list);

	printf("index of 1: %d\n", search(1, my_list));
	printf("index of 2: %d\n", search(2, my_list));
	printf("index of 3: %d\n", search(3, my_list));

	return 0;
}
