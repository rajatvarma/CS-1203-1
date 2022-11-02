int partition(int* a, int start, int stop) {
    int pivot = a[start];
    int i = start+1;
    int j = stop;
    while(i <= j) {
        if (a[i] > pivot) {
            swap(a, i, j);
            j = j-1;
        } else {
            i = i+1;
        }
    }
}

void quicksort(int* a, int start, int stop){
    if (start >= stop || !a) {
        return;
    }
    int p = partition(a, start, stop);
    quicksort(a, start, p-1);
    quicksort(a, p+1, stop);
}