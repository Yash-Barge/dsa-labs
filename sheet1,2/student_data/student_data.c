#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct student {
    float cgpa;
    char id[14];
};

struct node {
    struct student *s;
    struct node *next;
};

struct node *new_node(struct student *s) {
    struct node *n = malloc(sizeof(struct node));
    n->s = s;
    n->next = NULL;

    return n;
}

void print_list(struct node *n) {
    struct node *temp = n;

    while (temp != NULL) {
        printf("ID: %s\nCGPA: %f\n\n", temp->s->id, temp->s->cgpa);
        temp = temp->next;
    }

    return;
}

int main(void) {
    FILE *fp = fopen("data.txt", "r");

    struct student *buffer = malloc(sizeof(struct student));

    struct timeval t1, t2;
    double time_taken;

    gettimeofday(&t1, NULL);

    struct student *s_array = malloc(sizeof(struct student) * 10000);
    int size_array = 0;

    while (fscanf(fp, "%[^,],%f\n", buffer->id, &buffer->cgpa) != EOF) {
        s_array[size_array++] = *buffer;
        buffer = malloc(sizeof(struct student));
    }

    gettimeofday(&t2, NULL);

    fclose(fp);

    time_taken = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)*1e-6;
    printf("Time taken by dynamic array: %lf seconds\n", time_taken);

    fp = fopen("data.txt", "r");

    gettimeofday(&t1, NULL);

    struct node *list = NULL;
    struct node *prev = NULL;

    while (fscanf(fp, "%[^,],%f\n", buffer->id, &buffer->cgpa) != EOF) {
        struct node *temp = new_node(buffer);

        if (list == NULL) list = temp;
        else if (prev == NULL) list->next = prev = temp;
        else prev = prev->next = temp;

        buffer = malloc(sizeof(struct student));
    }

    gettimeofday(&t2, NULL);

    fclose(fp);

    time_taken = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)*1e-6;
    printf("Time taken by linked list: %lf seconds\n", time_taken);

    printf("Enter ten entries:\n");

    char input_id[10][14];
    float cgpa[10];
    int indices[10];

    for (int i = 0; i < 10; i++) {
        printf("Enter ID: ");
        scanf("%s", &input_id[i]);
        printf("Enter CGPA: ");
        scanf("%f", &cgpa[i]);
        printf("Enter index: ");
        scanf("%d", &indices[i]);
    }

    gettimeofday(&t1, NULL);

    // why must I do this

    gettimeofday(&t2, NULL);

    time_taken = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)*1e-6;
    printf("Time taken for insertion by dynamic array: %lf seconds\n", time_taken);

    return 0;
}
