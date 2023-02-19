#include "insertion_sort.h"

void insert_into_array(int *arr, int n, int data) {
    int i;
    for (i = n-2; i >= 0; i--) {
        if (arr[i] <= data) break;
        arr[i+1] = arr[i];
    }
    arr[i+1] = data;
}

void insertion_sort_recursive(int *arr, int n) {
    if (n == 1) return;

    insertion_sort_recursive(arr, n-1);

    insert_into_array(arr, n, arr[n-1]);

    return;
}

void insertion_sort_iterative(int *arr, int n) {
    for (int i = 1; i < n; i++) insert_into_array(arr, i+1, arr[i]);
    return;
}
