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

  //CHUNK REVERSING THE LIST
  
  int k;
  printf("Enter chunk size: ");
  scanf("%d", &k);

  if (k <= 0) {
    return 0;
  }

  struct node* CURRENT = HEAD;
  PREV = NULL;

  struct node* CHUNK_START = NULL;
  struct node* PREV_CHUNK_END = NULL;
  
  int CURRENT_INDEX = 0;

  while (CURRENT) {
    struct node *NEXT = CURRENT->next;
    
    if (CURRENT_INDEX % k == 0) {
      PREV_CHUNK_END = CHUNK_START;
      CHUNK_START = CURRENT;
      PREV = NULL;
    } else if (k - CURRENT_INDEX == 1 || !NEXT) {
      if (CURRENT_INDEX / k == 0) {
        HEAD = CURRENT;
      }
      if (PREV_CHUNK_END) {
        PREV_CHUNK_END->next = CURRENT;
      } else {
        CHUNK_START->next = NEXT;
      }
    }

    CURRENT->next = PREV;
    PREV = CURRENT;
    CURRENT = NEXT;
    CURRENT_INDEX  = CURRENT_INDEX+1;


    
  }
  outputTheList(HEAD);
}
