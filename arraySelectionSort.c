#include <stdio.h>
#include <stdlib.h>


int main() {
    int length;
    printf("Enter the length of the list: (number please): \n");
    scanf("%d", &length);

    int *arr = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++) {
        printf("Enter element #%d: ", i);
        int el;
        scanf("%d", &el);
        arr[i] = el;
    }

    for (int i = 0; i < length; i++) {
        int min_index = i;
        
        for (int j = i+1; j < length; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        int c = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = c;
    }
    
    for (int k = 0; k < length; k++) {
        printf("%d ", arr[k]);
    }
}

