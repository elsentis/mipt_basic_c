// Count 10 numbers in the range from -500 to 500
// and decompose them into two arrays:
// put only positive ones in one, and only negative ones in the second.
// Ignore numbers equal to zero. Display all elements of both arrays.
// Input format:
// 10 integers separated by spaces.
// (5 -4 0 1 4 -3 -3 3 0 2)
// Output format:
// First positive numbers, then negative numbers, separated by a space.
// (5 1 4 3 2 -4 -3 -3)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);

int main(void)
{
	int arr[SIZE];
	int count_positive = 0;

	inputArray(SIZE, arr);

	int temp_arr[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > 0)
		{
			temp_arr[count_positive] = arr[i];
			count_positive++;
		}
	}

	int* result_arr_positive = malloc(count_positive * sizeof(int));

	for (int i = 0; i < count_positive; i++)
	{
		result_arr_positive[i] = temp_arr[i];
	}
		
	int count_negative = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] < 0)
		{
			temp_arr[count_negative] = arr[i];
			count_negative++;
		}
	}

	int* result_arr_negative = malloc(count_negative * sizeof(int));

	for (int i = 0; i < count_negative; i++)
	{
		result_arr_negative[i] = temp_arr[i];
	}

	printArray(count_positive, result_arr_positive);
	printArray(count_negative, result_arr_negative);
	printf("\n");

	free(result_arr_positive);
	free(result_arr_negative);

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

	//printf("\n");

	return 0;
}