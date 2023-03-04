#include <stdio.h>
#include <stdlib.h>

#include "node.h"

int *Arr[N];
int Num_Elements[N];

void ConvertListstoArray(Locality *start) {
    Locality *tracker = start;

    for (int i = 0; i < N; i++) {
        Num_Elements[i] = tracker->count;

        Arr[i] = malloc(sizeof(int*) * Num_Elements[i]);
        Member *temp = tracker->first;

        for (int j = 0; j < Num_Elements[i]; j++) {
            *(Arr[i] + j) = temp->id;
            temp = temp->next;
        }
        
        tracker = tracker->next;
    }

    return;
}
