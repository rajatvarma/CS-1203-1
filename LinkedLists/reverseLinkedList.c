#include <stdio.h>
#include <stdlib.h>

struct node {
  int element;
  struct node *next;
};

void outputTheList(struct node *item) {
  while (item != NULL) {
    printf("%d ", item->element);
    item = item->next;
  }
  printf("\n");
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

  struct node *HEAD = malloc(sizeof(struct node));
  HEAD->element = array[0];
  struct node *PREV = HEAD;

  // CREATE THE LIST
  for (int i = 1; i < length; i++) {
    struct node *NEXT = malloc(sizeof(struct node));
    NEXT->next = NULL;
    NEXT->element = array[i];
    PREV->next = NEXT;
    PREV = NEXT;
  }

  printf("Creating and printing the linked list:\n");
  outputTheList(HEAD);

  PREV = NULL;
  struct node *CURRENT = HEAD;

  // REVERSE  THE LIST
  while (CURRENT != NULL) {
    struct node *NEXT = CURRENT->next;
    CURRENT->next = PREV;
    PREV = CURRENT;
    CURRENT = NEXT;
  }
  printf("\nReversing and printing the same linked list:\n");
  outputTheList(PREV);
}