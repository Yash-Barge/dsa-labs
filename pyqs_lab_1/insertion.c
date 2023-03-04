#include<stdio.h>

#include "node.h"

extern int * Arr[N];
extern int Num_Elements[N];

void InsertionSort_GM(int *row, int size) {
    for (int i = 1; i < size; i++) {
        if (!IsLower_GM(row[i-1], row[i])) {
            int j = i;
            int temp = row[j];

            while ((j > 1) && !IsLower_GM(row[j-1], row[j])) {
                row[j] = row[j-1];
                j--;
            }

            row[j] = temp;
        }
    }

    return;
} 

void InsertionSort_Arr() {
    for (int i = 0; i < N; i++) InsertionSort_GM(Arr[i], Num_Elements[i]);

    return;
}


