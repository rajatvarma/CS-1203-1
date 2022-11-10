#include <stdio.h>
#include <stdlib.h>
#include "createLinkedList.h"


int main() {
    struct node *hareCurrent = createLinkedList();
    struct node *tortoiseCurrent = hareCurrent;

    printf("Printing half the list:\n");
    while (hareCurrent) {
        printf("%d ", tortoiseCurrent->element);
        struct node *hareNext = hareCurrent->next;
        struct node *tortoiseNext = tortoiseCurrent->next;
        struct node *hareNextNext = hareNext->next;
        tortoiseCurrent = tortoiseNext;
        hareCurrent = hareNextNext;
    }
}