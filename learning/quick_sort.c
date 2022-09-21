#include <stdio.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low -1);

	for (int j = low; j <= high -1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int arr[], int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot -1);
		quick_sort(arr, pivot + 1, high);
	}
}

void	print_array(int arr[], int size)
{
	for (int i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int arr[] = {10, 7, 8 , 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quick_sort(arr, 0, n-1);
	printf("Sorted array: \n");
	print_array(arr, n);
	return (0);
}
