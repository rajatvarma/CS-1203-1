#include <stdio.h>
#include <stdlib.h>

struct node {
    int element;
    struct node* next;
};

int main() {
    struct node* HEAD = malloc(sizeof(struct node));
    HEAD->element = 4;
    HEAD->next = NULL;
    struct node* C;
    C = HEAD;

    printf("%d %d", HEAD, C);
}
