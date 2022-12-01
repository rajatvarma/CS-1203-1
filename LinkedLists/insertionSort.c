#include <stdio.h>
#include <stdlib.h>
#include "createLinkedList.h"

int main() {
    struct node *HEAD = createLinkedList();
    struct node *ITER_HEAD = HEAD->next;

    while (ITER_HEAD) {
        printf("ITER:%d\n", ITER_HEAD->element);
        struct node *CURRENT = HEAD;
        int minFound = 0;
        while (CURRENT && CURRENT->element != ITER_HEAD->element) {
            printf("Current:%d\n", CURRENT->element);
            if (CURRENT->next->element > ITER_HEAD->element) {
                minFound = 1;
                int temp = CURRENT->next->element;
                CURRENT->next->element = ITER_HEAD->element;
                ITER_HEAD->element = temp;
            }
            CURRENT = CURRENT->next;
        }
        if (!minFound) {
            int temp = ITER_HEAD->element;
            ITER_HEAD->element = HEAD->element;
            HEAD->element = temp;
        }
        struct node *thinghead = HEAD;
        while (thinghead) {
            printf("%d->", thinghead->element);
            thinghead = thinghead->next;
        }
        printf("\n");
        ITER_HEAD = ITER_HEAD->next;
    }
}