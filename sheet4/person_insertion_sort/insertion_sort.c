#include "person.h"
#include "insertion_sort.h"

void insert(struct person *arr, int n, struct person p) {
    int i = n-2;
    while (arr[i].height > p.height) {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = p;
}

void insertion_sort(struct person *arr, int n) {
    for (int i = 1; i < n; i++) insert(arr, i+1, arr[i]);
}
