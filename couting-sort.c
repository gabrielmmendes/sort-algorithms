#include <stdio.h>

// Counting Sort
// the elements to be sorted are “small” integers, that is, x ∈ N | x ∈ O(n);
void sort(int array[], int size, int isAsc) {
	int output[10];

	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}

	int count[10];

	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		count[array[i]]++;
	}

	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

    if (isAsc) {
        for (int i = size - 1; i >= 0; i--) {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }
    } else {
        for (int i = 0; i < size; i++) {
		    output[size - count[array[i]]] = array[i];
		    count[array[i]]--;
	    }
    }
	
	for (int i = 0; i < size; i++) {
		array[i] = output[i];
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
