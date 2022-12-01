#include <stdio.h>
#include <stdlib.h>
#include "createLinkedList.h"

int main() {
    struct node * HEAD = createLinkedList();
    struct node *ITER_HEAD = HEAD;
    struct node *PREV = NULL;

    while (ITER_HEAD) {
        struct node *CURRENT = ITER_HEAD->next;
        struct node *MIN = ITER_HEAD;
        while (CURRENT) {
            if (CURRENT->element < MIN->element) {
                MIN = CURRENT;
            }
            CURRENT = CURRENT->next;
        }
        
        int temp = ITER_HEAD->element;
        ITER_HEAD->element = MIN->element;
        MIN->element = temp;

        ITER_HEAD = ITER_HEAD->next;
    }

    while (HEAD) {
        printf("%d->", HEAD->element);
        HEAD = HEAD->next;
    }
}