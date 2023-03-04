#include <stdio.h>

#include "count_sort.h"

int main(void) {
    char input[1025] = {0};
    fgets(input, 1025, stdin);

    char output[1025] = {0};
    count_sort(input, output, 1024);

    printf("%s\n", output);

    return 0;
}
