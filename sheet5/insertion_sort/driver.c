#include <stdio.h>

#include "insertion_sort.h"

int main(void) {
    int arr1[] = {6, 4, 2, 7, 5, 3, 1, 0, 9, 8};
    int arr2[] = {6, 4, 2, 7, 5, 3, 1, 0, 9, 8};

    insertion_sort_recursive(arr1, 10);
    for (int i = 0; i < 10; i++) printf("%d ", arr1[i]);
    printf("\n");

    insertion_sort_iterative(arr2, 10);
    for (int i = 0; i < 10; i++) printf("%d ", arr2[i]);
    printf("\n");
    
    return 0;
}
