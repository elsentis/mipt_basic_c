// Read an array of 10 elements and sort the first half
// in ascending order and the second half in descending order.
// Input format:
// 10 integers separated by space
// (14  25  13  30  76  58  32  11  41  97)
// Output format:
// Source array. The first part is sorted in ascending order,
// the second half in descending order.
// (13  14  25  30  76  97  58  41  32  11)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 10

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);
void sortAscendingRangeArray(int first_position, int last_position, int* arr);
void sortDescendingRangeArray(int first_position, int last_position, int* arr);


int main(void)
{
	int arr[SIZE];

	inputArray(SIZE, arr);

	sortAscendingRangeArray(0, SIZE / 2, arr);

	sortDescendingRangeArray(SIZE / 2, SIZE, arr);

	printArray(SIZE, arr);

	return 0;
}

int inputArray(int n, int arr[])
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	return i;
}

void printArray(int n, int arr[])
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}


void sortAscendingRangeArray(int first_position, int last_position, int* arr)
{
	int temp = 0, no_swap = 0;

	for (int i = last_position - 1; i >= 0; i--)
	{
		no_swap = 1;
		for (int j = first_position; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				no_swap = 0;
			}
		}

		if (no_swap == 1)
		{
			break;
		}
	}
}

void sortDescendingRangeArray(int first_position, int last_position, int* arr)
{
	int temp = 0, no_swap = 0;

	for (int i = last_position - 1; i >= 0; i--)
	{
		no_swap = 1;
		for (int j = first_position; j < i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				no_swap = 0;
			}
		}

		if (no_swap == 1)
		{
			break;
		}
	}
}


