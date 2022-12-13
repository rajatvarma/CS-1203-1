#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
    int height;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}


int getNodeHeight(struct node* a) {
    if (a == NULL) {
        return 0;
    } else {
        return a->height;
    }
}

struct node* leftRotateTree(struct node* root) {
    struct node* rightNode = root->right;
    struct node* rightNodeLeft = rightNode->left;
    rightNode->left = root;
    root->right = rightNodeLeft;
    root->height = 1 + (getNodeHeight(root->left) > getNodeHeight(root->right) ? getNodeHeight(root->left) : getNodeHeight(root->right));
    return rightNode;
}

struct node* rightRotateTree(struct node* root) {
    struct node* leftNode = root->left;
    struct node* leftNodeRight = leftNode->right;
    leftNode->right = root;
    root->left = leftNodeRight;
    root->height = 1 + (getNodeHeight(root->left) > getNodeHeight(root->right) ? getNodeHeight(root->left) : getNodeHeight(root->right));
    return leftNode;
}

struct node* insertNode(struct node* root, int val) {
    printf("Root Exists %d ", (root == NULL ? 0 : 1));
    if (root == NULL) {
        return createNode(val);        
    } else {
        printf("Hello ");
        printf("Root: %d, Value: %d->", root->value, val);
        printf("WHAT ");
        if (val < root->value) {
            printf("Going to the left subtree->");
            root->left = insertNode(root->left, val);
        } else if (val > root->value) {
            printf("Going to the right subtree->");
            root->right = insertNode(root->right, val);
        } else {
            printf("Equal return ");
            return root;
        }

        //printf("Node found and inserted->");
        //printf("LeftHeight: %d, RightHeight: %d->", getNodeHeight(root->left), getNodeHeight(root->right));

        root->height = 1 + ((getNodeHeight(root->left) > getNodeHeight(root->right)) ? getNodeHeight(root->left) : getNodeHeight(root->right));
        
        //printf("Height updated %d->", root->height);

        int balanceFactor = ((root != NULL) ? getNodeHeight(root->left) - getNodeHeight(root->right) : 0);

        //printf("Balance Factor: %d->", balanceFactor);
        
        if (balanceFactor > 1 && val < root->left->value) {
            //printf("left left case ");
            return rightRotateTree(root);
        } else if (balanceFactor > 1 && val > root->left->value) {
            //printf("left right case ");
            root->left = leftRotateTree(root->left);
            return rightRotateTree(root);
        } else if (balanceFactor < -1 && val < root->right->value) {
            //printf("right left case ");
            root->right = rightRotateTree(root->right);
            return leftRotateTree(root);
        } else if (balanceFactor < -1 && val > root->right->value) {
            //printf("right right case ");
            return leftRotateTree(root);
        }
        return root;
    }   
}

void printNodeAndChildren(struct node* root) {
    if (root) {
        printf("[%d->", root->value);
        printf("Left->");
        printNodeAndChildren(root->left);
        printf("Right->");
        printNodeAndChildren(root->right);
        printf("] ");
    }
}


int main() {
    int length = 5;
    // //printf("Enter the length of the list (please enter a number): \n");
    // scanf("%d", &length);

    // int *array = malloc(length * sizeof(int));

    // for (int i = 0; i < length; i++) {
    //     //printf("Enter element #%d: ", i);
    //     int el;
    //     scanf("%d", &el);
    //     array[i] = el;
    // }

    struct node *root = NULL;

    int a[5] = {10, 6, 8, 14, 3};

    for (int i = 0; i < length; i++) {
        printf("%d=> ", i);
        root = insertNode(root, a[i]);
        printf("Done!\n");
    }
    printNodeAndChildren(root);
}