#include <stdio.h>

#include "merge_sort.h"

int main(void) {
    int arr[] = {5,4,3,2,1};
    merge_sort(arr, 5);

    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
