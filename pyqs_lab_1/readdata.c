#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Member *new_member(int data) {
    Member *m = malloc(sizeof(Member));

    if (m != NULL) {
        m->id = data;
        m->next = NULL;
    }

    return m;
}

Locality *new_locality(int data) {
    Locality *l = malloc(sizeof(Locality));
    l->count = data;
    l->first = NULL;
    l->next = NULL;

    return l;
}

void insert_into_locality(Locality *l, int data) {
    if (l->first == NULL) l->first = new_member(data);
    else {
        Member *temp = l->first;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new_member(data);
    }

    return;
}

void append_locality(Locality *parent, Locality *child) {
    if (parent->next == NULL) parent->next = child;
    else {
        Locality *temp = parent->next;
        while (temp->next != NULL) temp = temp->next;
        temp->next = child;
    }

    return;
}

Locality *ReadFileintoLists(char *filename) {
    FILE *file = fopen(filename, "r");

    int count_buffer;

    fscanf(file, "%d", &count_buffer);
    Locality *parent = new_locality(count_buffer);
    for (int i = 0; i < count_buffer; i++) {
        int temp;
        fscanf(file, ",%d", &temp);
        insert_into_locality(parent, temp);
    }

    while (fscanf(file, "%d", &count_buffer) != EOF) {
        Locality *l = new_locality(count_buffer);
        for (int i = 0; i < count_buffer; i++) {
            int temp;
            fscanf(file, ",%d", &temp);
            insert_into_locality(l, temp);
        }
        append_locality(parent, l);
    }

    fclose(file);

    return parent;
}

void PrintLists(Locality *start) {
    Locality *temp = start;
    while (temp != NULL) {
        printf("%d", temp->count);
        Member *m_temp = temp->first;
        while (m_temp != NULL) {
            printf(" %d", m_temp->id);
            m_temp = m_temp->next;
        }
        printf("\n");
        temp = temp->next;
    }
    printf("\n");

    return;
}
