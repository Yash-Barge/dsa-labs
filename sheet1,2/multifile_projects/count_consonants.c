#include "count.h"

int isConsonant(char c) {
    int val = 0;

    if (c > 97 && c < 123 && c != 'e' && c !='i' && c != 'o' && c != 'u') val = 1;

    return val;
}

int count(char *string) {
    int count = 0;

    for (int i = 0; i < strlen(string); i++) if (isConsonant(tolower(string[i]))) count++;

    return count;
}
