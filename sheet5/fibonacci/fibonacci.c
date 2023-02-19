#include "fibonacci.h"

long long int fibonacci_recursive(int n) {
    if (n < 1) return -1;
    if (n < 3) return 1;

    return (fibonacci_recursive(n-1) + fibonacci_recursive(n-2));
}

long long int fibonacci_iterative(int n) {
    if (n < 1) return -1;

    long long int prev = 1;
    long long int current = 1;

    for (int i = 3; i <= n; i++) {
        long long int temp = current;
        current += prev;
        prev = temp;
    }

    return current;
}
