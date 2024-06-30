// Just create a function that finds the maximum negative element
// in an array and swaps it with the last element of the array.
// It is guaranteed that there is only one such element in the array
// or that there is no such element. If there are no negative elements,
// do not change the array.
// Function prototype :
// void swap_negmax_last(int size, int a[])
// Input format:
// The function takes as input the size of the array and a pointer
// to the 
// (1 -2 -3 -4 5 6 7 8 9 10)
// Output format:
// (1 10 -3 -4 5 6 7 8 9 -2)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000


int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);

void swap_negmax_last(int size, int a[])
{
		int max_negative_index = -1;

	for (int i = 0, max_negative = 0, negative_numbers_count = 0; i < size; i++)
	{
		if (a[i] < 0)
		{
			if (negative_numbers_count == 0)
			{
				max_negative = a[i];
				max_negative_index = i;
				negative_numbers_count++;
			}
			if (a[i] > max_negative)
			{
				max_negative = a[i];
				max_negative_index = i;
			}
		}
	}

	if (max_negative_index >= 0)
	{
		int temp = a[max_negative_index];
		a[max_negative_index] = a[size - 1];
		a[size - 1] = temp;
	}

	//printArray(size, a);

	return 0;
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
