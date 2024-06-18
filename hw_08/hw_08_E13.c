// Read an array of 10 elements and select into another array
// all numbers whose second digit from the end (the number of tens) is zero.
// Input format:
// 10 integers separated by spaces.
// (40 105 203 1 14 1000 22 33 44 55)
// Output format:
// Space-separated integers whose second-to-last digit is zero
// (105 203 1 1000)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);
int extractTenDigit(int n);

int main(void)
{
	int arr[SIZE];
	int count = 0;

	inputArray(SIZE, arr);

	for (int i = 0; i < SIZE; i++)
	{
		if (extractTenDigit(arr[i]) == 0)
		{
			count++;
		}
	}

	int* result_arr = malloc(count * sizeof(int));

	for (int i = 0, j = 0; i < SIZE; i++)
	{
		if (extractTenDigit(arr[i]) == 0)
		{
			result_arr[j] = arr[i];
			j++;
		}
	}

	printArray(count, result_arr);

	free(result_arr);

	return 0;
}

int extractTenDigit(int n)
{
	return ((n % 100) / 10);
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