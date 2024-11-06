#include <stdio.h>

// INSERTION SORT
// Worst case: O(n²)
// Medium case: O(n²)
// Best case: O(n) if already sorted 

void sort(int arr[], int n, int isAsc) {
    if (isAsc) {
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        } 
    } else {
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        } 
    }
    
}

int main() {
    
    int n = 10;
    int arr[] = {4, 1, 3, 6, 7, 8, 2, 9, 0, 5};

    
    sort(arr, n, 1);
    
    printf("Asc:\n");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    
    sort(arr, n, 0);
    
    printf("\nDesc:\n");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    
    return 0;
}
