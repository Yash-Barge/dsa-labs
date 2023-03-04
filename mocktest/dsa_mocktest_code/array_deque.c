#include <stdio.h>

#include "array_deque.h"

// Use these functions if you find them helpful or define other static helper functions that might assist you.
// One possible implementation:
// Assume that next_first decrements (or moves left) and rolls back from the other end of the array.
// Assume that next_last increments (or moves right).
// So at any instant, during add_first the element is added to next-first position and next_first is updated accordingly
// Or an element is added at next_last which is then updated accordingly


static unsigned int get_first_index(array_deque *ad);

static unsigned int get_last_index(array_deque *ad);

static unsigned int decrement_index(array_deque *d, size_t index);

static unsigned int increment_index(array_deque *d, size_t index);

static void resize_if_needed(array_deque *d);

static process *create_process(process p);

array_deque *create_empty_process_array_deque() {
    // COMPLETE
    array_deque *ad = malloc(sizeof(array_deque));
    ad->processes = calloc(INITIAL_SIZE_ARRAY_DEQUE, sizeof(process*));
    ad->first = 0;
    ad->last = 1;
    ad->size = 0;
    ad->capacity = INITIAL_SIZE_ARRAY_DEQUE;

    return ad;
}

static unsigned int decrement_index(array_deque *ad, size_t index) {
    index = index - 1;
    if (index == -1) {
        index = ad->capacity - 1;
    }
    return index;
}

static unsigned int increment_index(array_deque *d, size_t index) {
    return (index + 1) % d->capacity;
}

static unsigned int get_first_index(array_deque *ad) {
    return increment_index(ad, ad->first);
}

static unsigned int get_last_index(array_deque *ad) {
    return decrement_index(ad, ad->last);
}

bool add_first_array_deque(array_deque *ad, process p) {
    // COMPLETE
    process *temp = create_process(p);
    if (temp == NULL) return false;

    if (!(ad->size)) ad->last = increment_index(ad, ad->first);
    else ad->first = decrement_index(ad, ad->first);

    *(ad->processes + ad->first) = temp;
    (ad->size)++;

    resize_if_needed(ad);

    return true;
}

static process *create_process(process p) {
    process *pro = malloc(sizeof(process));
    if (!pro) return NULL;
    *pro = p;
    return pro;
}

bool add_last_array_deque(array_deque *ad, process p) {
    // COMPLETE
    process *temp = create_process(p);
    if (temp == NULL) return false;

    if (!(ad->size)) {
        *(ad->processes + ad->first) = temp;
        ad->last = increment_index(ad, ad->first);
        
    } else {
        *(ad->processes + ad->last) = temp;
        ad->last = increment_index(ad, ad->last);
    }

    (ad->size)++;

    resize_if_needed(ad);

    return true;
}

bool remove_first_array_deque(array_deque *ad, process *p) {
    // COMPLETE
    if (!(ad->size)) return false;

    *p = **(ad->processes + ad->first);
    free(*(ad->processes + ad->first));
    *(ad->processes + ad->first) = NULL;

    if (ad->size != 1) ad->first = increment_index(ad, ad->first);
    (ad->size)--;

    // resize_if_needed(ad);

    return true;
}

bool remove_last_array_deque(array_deque *ad, process *p) {
    // COMPLETE
    if (!(ad->size)) return false;

    ad->last = decrement_index(ad, ad->last);

    *p = **(ad->processes + ad->last);
    free(*(ad->processes + ad->last));
    *(ad->processes + ad->last) = NULL;

    if (ad->size == 1) ad->last = increment_index(ad, ad->last);
    (ad->size--);

    // resize_if_needed(ad);

    return true;
}

size_t get_size_array_deque(array_deque *ad) {
    return ad->size;
}

static void resize_if_needed(array_deque *ad) {
    if (ad->size < ad->capacity) {
        return;
    }
    // COMPLETE
    process **new_arr = calloc((ad->capacity) * 2, sizeof(process*));

    int j = ad->first;
    for (int i = 0; i < ad->size; i++) {
        *(new_arr + i) = *(ad->processes + j);
        j = increment_index(ad, j);
    }

    free(ad->processes);
    ad->processes = new_arr;
    ad->capacity = (ad->capacity) * 2;
    ad->first = 0;
    ad->last = ad->size;

    return;
}

void print_array_deque(array_deque *ad) {
    if (!(ad->size)) return;

    printf("%d ", (*(ad->processes + ad->first))->pid);
    for (int i = increment_index(ad, ad->first); i != ad->last; i = increment_index(ad, i)) printf("%d ", (*(ad->processes + i))->pid);
    printf("\n");

    return;
}
