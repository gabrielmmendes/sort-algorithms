#include <stdio.h>

// QUICK SORT
// Worst case: O(n²)
// Medium case: O(n*log(n))
// Best case: O(n*log(n)) 

int partition(int arr[], int low, int high, int isAsc) {
    if (isAsc) {
        int pivot = arr[high];

        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }

        int aux = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = aux;

        return i + 1;
    } else {
        int pivot = arr[high];

        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] > pivot) {
                i++;
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }

        int aux = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = aux;

        return i + 1;
    }
}

void sort(int arr[], int low, int high, int isAsc) {
    if (low < high) {
        
        int pi = partition(arr, low, high, isAsc);

        sort(arr, low, pi - 1, isAsc);
        sort(arr, pi + 1, high, isAsc);
    }
}

int main() {
    
    int n = 10;
    int arr[] = {4, 1, 3, 6, 7, 8, 2, 9, 0, 5};

    
    sort(arr, 0, n-1, 1);
    
    printf("Asc:\n");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    
    sort(arr, 0, n-1, 0);
    
    printf("\nDesc:\n");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    
    return 0;
}
