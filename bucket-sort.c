#include <stdio.h>
#include<limits.h>

// BUCKET SORT
// for a few elements between 0 and 1
// Big O(n)

int max_element(int array[], int size) {  
    int max = INT_MIN;  
    for (int i = 0; i < size; i++) {
        if (array[i] > max)  
            max = array[i];  
    }
    return max;  
}
 
void sort(int array[], int size, int isAsc) {  
    int max = max_element(array, size); 
 
    int bucket[max+1];  
 
    for (int i = 0; i <= max; i++)  
        bucket[i] = 0;  
 
    for (int i = 0; i < size; i++)  
        bucket[array[i]]++;
 
    int j=0;
    if (isAsc) {
        for (int i = 0; i <= max; i++)  { 
            while (bucket[i] > 0)  {  
                array[j++] = i;  
                bucket[i]--;   
            }  
        }
    } else {
        for (int i = max; i >= 0; i--)  { 
            while (bucket[i] > 0)  {  
                array[j++] = i;  
                bucket[i]--;   
            }  
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
