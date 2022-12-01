#include <stdio.h>
#include <stdlib.h>


int partition(int* a, int left, int right) {
    int pivot = right;
    int s = left-1;
    for (int i = left; i < right; i++) {
        if (a[i] <= a[pivot]) {
            s++;
            int temp = a[i];
            a[i] = a[s];
            a[s] = temp;
        }
    }
    int temp = a[right];
    a[right] = a[s+1];
    a[s+1] = temp;
    return s+1;
}

void quickSort(int* array, int left, int right) {
    if (left < right) {
        int pivot = partition(array, left, right);
        quickSort(array, left, pivot-1);
        quickSort(array, pivot+1, right);
    }
}



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
    printf("Unsorted: ");
    for (int k = 0; k < length; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
    quickSort(arr, 0, length-1);
    printf("Sorted: ");
    for (int k = 0; k < length; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}