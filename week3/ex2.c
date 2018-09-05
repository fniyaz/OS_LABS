#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int len);

int main(){
	int n, *arr;
	scanf("%d", &n);
	arr = malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	bubble_sort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	
	return 0;
}

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int *arr, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n-i-1; j++){
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}
