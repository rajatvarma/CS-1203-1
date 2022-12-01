#include <stdio.h>
#include <stdlib.h>
#include "createLinkedList.h"

struct node* getLastElementOfLinkedList(struct node* HEAD) {
    struct node* CURRENT = HEAD;
    while (CURRENT) {
        if (CURRENT->next == NULL) {
            return CURRENT;
        }       
        CURRENT = CURRENT->next;
    }
}

struct node* partition(struct node* LEFT, struct node* RIGHT) {
    struct node* PIVOT = RIGHT;
    struct node* CURRENT = LEFT;
    while (CURRENT) {
        if (CURRENT->element <= PIVOT->element) {
            PIVOT = LEFT;
            int c = LEFT->element;
            LEFT->element = CURRENT->element;
            CURRENT->element = c;
            LEFT = LEFT->next;
        }
        CURRENT = CURRENT->next;
    }
    int c = LEFT->element;
    LEFT->element = RIGHT->element;
    RIGHT->element = c;
    return PIVOT;
}

void quickSortLinkedList(struct node* LEFT, struct node* RIGHT) {
    if (LEFT == RIGHT) {
        return;
    } 
    struct node* PIVOT = partition(LEFT, RIGHT);
    if (PIVOT != NULL && PIVOT->next != NULL) {
        quickSortLinkedList(PIVOT->next, RIGHT);
    }

    if (PIVOT != NULL && LEFT!=NULL) {
        quickSortLinkedList(LEFT, PIVOT);
    }
}


int main() {
    struct node* HEAD = createLinkedList();
    struct node* TAIL = getLastElementOfLinkedList(HEAD);
    quickSortLinkedList(HEAD, TAIL);
    while (HEAD) {
        printf("%d ", HEAD->element);
        HEAD = HEAD->next;
    }   
}