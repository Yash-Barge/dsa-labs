#include <stdlib.h>

#include "count_sort.h"

void count_sort(char *input, char *output, int size) {
    int count[26] = {0};

    for (int i = 0; i < size; i++) count[*(input+i) - 'a']++;

    for (int i = 1; i < 26; i++) count[i] += count[i-1];

    for (int i = size-1; i >= 0; i--) *(output + count[*(input+i) - 'a']-- - 1) = *(input + i);

    return;
}
