// Given an integer array of 30 elements.
// Array elements can take arbitrary integer values ??that fit into int.
// You need to create a function that finds and displays,
// in ascending order, the numbers of two array elements whose sum is minimal.
// Input format
// Sequence of 30 space separated integers
// (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30)
// Output format 
// (0 1)

#define _CRT_SECURE_NO_WARNINGS

#define SIZE 30

#include <stdio.h>

int inputArray(int n, int arr[]);

int main()
{
	int arr[SIZE];

	inputArray(SIZE, arr);

	int min1, min2;
	int min1_index, min2_index, i;

	for (i = 0, min1 = arr[i], min1_index = i; i < SIZE; i++)
	{
		if (arr[i] < min1)
		{
			min1 = arr[i];
			min1_index = i;
		}
	}

	if (min1_index == 0)
	{
		min2 = arr[1];
		min2_index = 1;
		i = 1;
	}
	else
	{
		min2 = arr[0];
		min2_index = 0;
		i = 0;
	}
	for (; i < SIZE; i++)
	{
		if (i == min1_index)
		{
			continue;
		}
		else
		{
			if (arr[i] < min2)
			{
				min2 = arr[i];
				min2_index = i;
			}
		}
	}

	if (min1_index < min2_index)
	{
		printf("%d %d\n", min1_index, min2_index);
	}
	else
	{
		printf("%d %d\n", min2_index, min1_index);
	}


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