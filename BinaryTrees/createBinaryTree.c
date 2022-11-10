#include "binaryTrees.h"
#include <stdbool.h>


void pushNodes(struct node *parent, int L, int* arr, int i) {
    if (2*i+1 < L) {
        struct node *left = insertNode(parent, arr[2*i+1], 0);
        pushNodes(left, L, arr, 2*i+1);
    }        
    if (2*i+2 < L) {
        struct node *right = insertNode(parent, arr[2*i+2], 1);
        pushNodes(right, L, arr, 2*i+2);
    }
}

void printNodeandChildren(struct node* n) {
    printf("%d", n->data);
    if(n->leftChild){
        printNodeandChildren(n->leftChild);
    }
    if(n->rightChild){
        printNodeandChildren(n->rightChild);
    }
}

int main() {
    int length;
    printf("Enter the length of the list (please enter a number): \n");
    scanf("%d", &length);

    int *array = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++) {
        printf("Enter element #%d: ", i);
        int el;
        scanf("%d", &el);
        array[i] = el;
    }

    struct node *root = createNode(array[0]);
    struct node *parent = root;

    int i = 0;
    
    pushNodes(root, length, array, i);

    printf("[ ");
    printNodeandChildren(root);
    printf(" ]\n");
    
}


