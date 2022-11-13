#include <stdio.h>
#include <stdlib.h>

int main() {
    int length;
    printf("Enter the length of the list: (number pls): \n");
    scanf("%d", &length);

    int *arr = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++) {
        printf("Enter element #%d: ", i);
        int el;
        scanf("%d", &el);
        arr[i] = el;
    }

    for (int i = 1; i < length; i++) {
        int j = i-1;

        while (j >= 0 && arr[i] < arr[j]) {
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = i;
    }

    for (int k = 0; k < length; k++) {
        printf("%d ", arr[k]);
    }
}