#include <stdio.h>
#include <stdlib.h>

char *inputString(void) {
    size_t size = 16;

    char *string = malloc(sizeof(*string) * size);
    if (!string) {
        printf("Memory allocation failed! Exiting...\n");
        exit(1);
    }

    int flag = 1;
    size_t length = 0;

    while (flag) {
        char input = getchar();

        if (length == size - 1) {
            size += 16;
            string = realloc(string, sizeof(*string) * size);
            if (!string) {
                printf("Memory allocation failed! Exiting...\n");
                exit(1);
            }
        }

        if (input == '\n') {
            string[length] = '\0';
            flag = 0;
        }
        else {
            string[length] = input;
            length++;
        }
    }

    return string;
}

int main(void) {
    printf("Enter initial length of array: ");
    int size;
    scanf("%d%*c", &size);

    char **strings = malloc(sizeof(*strings) * size);

    for (int i = 0; i < size; i++) {
        printf("Enter string: ");
        strings[i] = inputString();
    }
    printf("\n");

    int flag = 1;
    while (flag) {
        char input;

        printf("a) Add a string to the end of the array\n");
        printf("b) Add a string to the beginning of the array\n");
        printf("c) Delete the element at index 'x' of the array\n");
        printf("d) Display length of the array\n");
        printf("e) Display all the elements of the array in sequence\n");
        printf("f) Terminate the program\n\n");

        input = inputString()[0];

        switch(input) {
            case 'a':
                size++;
                strings = realloc(strings, sizeof(*strings) * size);
                printf("\nEnter string: ");
                strings[size - 1] = inputString();
                printf("\n");
                break;
            case 'b':
                size++;
                strings = realloc(strings, sizeof(*strings) * size);
                for (int i = size - 1; i > 0; i--) strings[i] = strings[i - 1];
                printf("\nEnter string: ");
                strings[0] = inputString();
                printf("\n");
                break;
            case 'c':
                size_t x;
                printf("\nInput x (index of string you want deleted: ");
                scanf("%zu", &x);
                inputString(); // eat the newline
                if (x < 0 || x >= size) printf("\nInvalid index.\n\n");
                else {
                    free(strings[x]);
                    for (int i = x; i < size - 1; i++) strings[i] = strings[i + 1];
                    size--;
                    strings = realloc(strings, sizeof(*strings) * size);
                    printf("\n");
                }
                break;
            case 'd':
                printf("\nLength of the array is %d\n\n", size);
                break;
            case 'e':
                printf("\n");
                for (int i = 0; i < size; i++) {
                    printf("%d) %s\n", i + 1, strings[i]);
                }
                printf("\n");
                break;
            case 'f':
                printf("\nTerminating program...\n\n");
                flag = 0;
                break;
            default:
                printf("Invalid input. Please enter a letter from a to f\n\n");
        }
    }

    return 0;
}