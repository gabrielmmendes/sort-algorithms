#include <stdio.h>

// Radix Sort
// the elements to be sorted are numbers
// integers of constant maximum length, that is,
// independent of n;
// Big O(n)
void sort(int array[], int n, int isAsc) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    int maxElement = max;
    for (int place = 1; maxElement / place > 0; place *= 10) {
        int output[n];
        int count[10] = {0};
    
        for (int i = 0; i < n; i++) {
            int index = (array[i] / place) % 10;
            count[index]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        if (isAsc) {
            for (int i = n - 1; i >= 0; i--) {
                int index = (array[i] / place) % 10;
                output[count[index] - 1] = array[i];
                count[index]--;
            }
        } else {
            for (int i = 0; i < n; i++) {
    		    int index = (array[i] / place) % 10;
                output[n - count[index]] = array[i];
                count[index]--;
    	    }
        }
        
        for (int i = 0; i < n; i++) {
            array[i] = output[i];
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
