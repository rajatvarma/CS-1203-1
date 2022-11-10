#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *createNode(int x) {
    struct node *N = (struct node*)malloc(sizeof(struct node));
    N->data = x;
    N->leftChild = NULL;
    N->rightChild = NULL;
    return N;
}

struct node *insertNode(struct node *parent, int val, int side) {
    struct node *newNode = createNode(val);
    if (side == 0) {
        parent->leftChild = newNode;
        return parent->leftChild;
    } else if (side == 1) {
        parent->rightChild = newNode;
        return parent->rightChild;
    }
    else {
        return NULL;
    }
}