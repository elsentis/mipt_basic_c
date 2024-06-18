// Read an array of 10 elements
// and find the maximum and minimum elements and their numbers.
// Input format:
// 10 integers separated by space
// (4 -5 3 10 -4 -6 8 -10 1 0)
// Output format:
// 4 integers separated by a space:
// maximum number, maximum, minimum number, minimum.
// (4 10 8 -10)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 10

int Input(int n, int arr[]);
int maxArray(int n, int arr[]);
int maxArrayIndex(int n, int arr[]);
int minArray(int n, int arr[]);
int minArrayIndex(int n, int arr[]);

int main(void)
{
	int arr[SIZE];

	Input(SIZE, arr);

	printf("%d ", maxArrayIndex(SIZE, arr));
	printf("%d ", maxArray(SIZE, arr));
	printf("%d ", minArrayIndex(SIZE, arr));
	printf("%d ", minArray(SIZE, arr));
	
	printf("\n");

	return 0;
}

int Input(int n, int arr[])
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	return i;
}

int maxArray(int n, int arr[])
{
	int max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

int maxArrayIndex(int n, int arr[])
{
	int max_index = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[max_index])
		{
			max_index = i;
		}
	}

	return max_index + 1;
}

int minArray(int n, int arr[])
{
	int min = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

int minArrayIndex(int n, int arr[])
{
	int min_index = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[min_index])
		{
			min_index = i;
		}
	}

	return min_index + 1;
}
