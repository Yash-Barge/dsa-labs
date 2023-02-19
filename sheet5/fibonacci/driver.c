#include <stdio.h>

#include "fibonacci.h"

int main(void) {
    printf("%lld\n", fibonacci_recursive(10));
    printf("%lld\n", fibonacci_iterative(10));

    return 0;
}
