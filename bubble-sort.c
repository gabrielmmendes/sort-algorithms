#include <stdio.h>

// BUBBLE SORT
// Worst case: O(n²)
// Medium case: O(n²)
// Best case: O(n²) 

void sort(int arr[], int n, int isAsc) {
    if (isAsc) {
        int i, j;
        int swap;
        for (i = 0; i < n - 1; i++) {
            swap = 0;
            for (j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int aux = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = aux;
                    swap = 1;
                }
            }

            if (swap == 0)
                break;
        }
    } else {
        int i, j;
        int swap;
        for (i = 0; i < n - 1; i++) {
            swap = 0;
            for (j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    int aux = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = aux;
                    swap = 1;
                }
            }

            if (swap == 0)
                break;
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
