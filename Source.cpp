#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];

	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)				// If current element is smaller than the pivot 
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);

	return (i + 1);
}

// The main function that implements QuickSort.  low --> Starting index, high --> Ending index 

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);				// pi is partitioning index, arr[pi] is now at right place

		quickSort(arr, low, pi - 1);					// Separately sort elements before partition and after partition 
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int arr[20], n;
	printf("How many elements ? ");
	scanf("%d", &n);
	printf("enter elements : \n");
	for (int i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	quickSort(arr, 0, n - 1);
	printf(" Sorted array: \n");
	printArray(arr, n);
	_getch();
}