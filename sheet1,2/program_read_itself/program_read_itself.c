#include <stdio.h>

int main(void) {
    FILE *file = fopen(__FILE__, "r");

    if (file == NULL) {
        printf("Can't read file! Exiting program...\n");
        return 1;
    }

    while (1) {
        char buffer[1024];
        if (fgets(buffer, 1024, file) == NULL) break;
        printf("%s", buffer);
    }

    fclose(file);

    return 0;
}
