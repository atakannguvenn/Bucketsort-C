#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int getMax(int arr[], int size){
	int i, m = arr[0];
	for(i = 1; i < size; i++){
		if(arr[i] > m) {
			m = arr[i];
		}
	}
	return m;
}

void insertionSort(int arr[][12], int bucket, int n)
{
   int i, key, j, z;
   for (z = 0; z < bucket; z++)
   {
        for (i = 1; i < n; i++)
        {
            if(arr[z][i] == NULL)
                continue;
            key = arr[z][i];
            j = i-1;
            while (j >= 0 && arr[z][j] > key)
            {
                arr[z][j+1] = arr[z][j];
                j = j-1;
            }
            arr[z][j+1] = key;
        }
   }
}

void bucketSort(int arr[], int size){
	int max, bucket = 10, divider, i, j, k, n, b;
    float div, mx, buc;
	int B[bucket][size];

	for (i = 0; i < bucket; i++){
        for (b = 0; b < size; b++)
            B[i][b] = NULL;
	}
	max = getMax(arr, size);
    div = divider;
	buc = bucket;
	div = (max + 1) / buc;

	printf("\nAfter Building the Bucket\nDivider is %.2f\n", div);
	for(i = 0; i < size; i++){
        n = 0;
		j = arr[i] / div;
		while (B[j][n]!= NULL)
            n++;
		B[j][n] = arr[i];
		printf("B[%d][%d] = %d\n", j, n, B[j][n]);
	}
	printf("\n");
    insertionSort(B, 10, 12);
	k = 0;
	for(i = 0; i < bucket; i++){
		for(j = 0; j < size; j++){
            if (B[i][j] == NULL)
                continue;
			arr[k++] = B[i][j];
		}
	}
}

int main(void) {
	int arr[] = {22,45,12,8,10,6,72,81,33,18,50,14};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Original Array\n");
	display(arr, n);
	bucketSort(arr, n);
	printf("After Bucket Sort\n");
	display(arr, n);
	return 0;
}
