#include <stdio.h>

// MERGE SORT
// Worst case: O(n*log(n))
// Medium case: O(n*log(n))
// Best case: O(n*log(n)) 

void merge(int arr[], int l, int m, int r, int isAsc) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    if (isAsc) {
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
    
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    } else {
        while (i < n1 && j < n2) {
            if (L[i] >= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
    
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
}

void sort(int arr[], int l, int r, int isAsc) {
    
    if (l < r) {
        int m = l + (r - l) / 2;

        sort(arr, l, m, isAsc);
        sort(arr, m + 1, r, isAsc);

        merge(arr, l, m, r, isAsc);
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
