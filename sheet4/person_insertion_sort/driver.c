#include <stdio.h>

#include "person.h"
#include "insertion_sort.h"

int main(void) {
    struct person arr[5];

    arr[0].id = 1;
    arr[0].name[0] = 'S';
    arr[0].name[1] = 'o';
    arr[0].name[2] = 'k';
    arr[0].name[3] = 'k';
    arr[0].name[4] = 'a';
    arr[0].name[5] = '\0';
    arr[0].age = 15;
    arr[0].height = 150;
    arr[0].weight = 45;

    arr[1].id = 2;
    arr[1].name[0] = 'A';
    arr[1].name[1] = 'a';
    arr[1].name[2] = 'n';
    arr[1].name[3] = 'g';
    arr[1].name[4] = '\0';
    arr[1].age = 112;
    arr[1].height = 137;
    arr[1].weight = 35;

    arr[2].id = 3;
    arr[2].name[0] = 'Z';
    arr[2].name[1] = 'u';
    arr[2].name[2] = 'k';
    arr[2].name[3] = 'o';
    arr[2].name[4] = '\0';
    arr[2].age = 16;
    arr[2].height = 160;
    arr[2].weight = 50;

    arr[3].id = 4;
    arr[3].name[0] = 'K';
    arr[3].name[1] = 'a';
    arr[3].name[2] = 't';
    arr[3].name[3] = 'a';
    arr[3].name[4] = 'r';
    arr[3].name[5] = 'a';
    arr[3].name[6] = '\0';
    arr[3].age = 14;
    arr[3].height = 145;
    arr[3].weight = 38;

    arr[4].id = 5;
    arr[4].name[0] = 'T';
    arr[4].name[1] = 'o';
    arr[4].name[2] = 'p';
    arr[4].name[3] = 'h';
    arr[4].name[4] = '\0';
    arr[4].age = 12;
    arr[4].height = 113;
    arr[4].weight = 30;

    insertion_sort(arr, 5);

    printf("id name age height weight\n");
    for (int i = 0; i < 5; i++) {
        printf("%d %s %d %d %d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }
}
