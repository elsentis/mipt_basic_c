// Print in order the digits included in the decimal
// notation of the natural number N.
// Input format:
// One natural number N
// (54412)
// Output format:
// Numbers separated by spaces
// (5 4 4 1 2)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);

int main(void)
{
	int n = 0, count = 0;
	int arr[SIZE];

	scanf("%d", &n);


	for (int i = 0; n != 0; n /= 10, i++)
	{
		arr[i] = n % 10;
		count++;
	}

	int* result_arr = malloc(count * sizeof(int));

	for (int i = count - 1, j = 0; i >= 0; i--, j++)
	{
		result_arr[j] = arr[i];
	}

	printArray(count, result_arr);

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