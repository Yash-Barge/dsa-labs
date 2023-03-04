#include "merge_sort.h"

void merge_sort(int *arr, int size) {
    if (size < 2) return;

    int mid = size / 2;

    merge_sort(arr, mid);
    merge_sort(arr + mid, size - mid);

    int i = 0, j = mid, index = 0;
    int temp[size];

    while (i < mid && j < size) {
        if (arr[i] > arr[j]) temp[index++] = arr[j++];
        else temp[index++] = arr[i++];
    }

    while (i < mid) temp[index++] = arr[i++];
    while (j < size) temp[index++] = arr[j++];

    for (index = 0; index < size; index++) arr[index] = temp[index];

    return;
}
