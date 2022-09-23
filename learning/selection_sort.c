#include <stdio.h>
#include <stdlib.h>

int find_smallest(int *arr, int size)
{
	int smallest = arr[0];
	int smallest_index = 0;

	for (int i=1; i < size; i++){
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			smallest_index = i;
		}
	}
	return (smallest_index);
}

int	*selection_sort(int *arr, int size)
{
	int *new_arr = malloc(sizeof(int *) * size);
	int smallest_index;

	for (int i=0; i<size; i++){
		smallest_index = find_smallest(arr, size);
		new_arr[i] = arr[smallest_index];
		arr[smallest_index] = __INT_MAX__;
	}
	return (new_arr);
}

int main(void)
{
	int arr[] = {5, 3, 6, 2, 10}; 
	int size = sizeof(arr) / sizeof(arr[0]);
	int *arr_sorted = selection_sort(arr, size);
	for (int i=0; i<size; i++)
	{
		printf("%d ", arr_sorted[i]);
	}
	printf("\n");
	free(arr_sorted);
	return (0);
}
