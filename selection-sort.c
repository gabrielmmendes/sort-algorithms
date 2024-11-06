#include <stdio.h>

// SELECTION SORT
// Worst case: O(n²)
// Medium case: O(n²)
// Best case: O(n²)

void sort(int arr[], int n, int isAsc) {
    if (isAsc) {
        for (int i = 0; i < n - 1; i++) {
      
            int minor_element = i;
            
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minor_element]) {
                    minor_element = j;
                }
            }
            
            int aux = arr[i];
            arr[i] = arr[minor_element];
            arr[minor_element] = aux;
        }
    } else {
        for (int i = 0; i < n - 1; i++) {
      
            int minor_element = i;
            
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[minor_element]) {
                    minor_element = j;
                }
            }
            
            int aux = arr[i];
            arr[i] = arr[minor_element];
            arr[minor_element] = aux;
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
