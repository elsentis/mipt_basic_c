// Given an array of 10 elements.
// In the array, find the elements
// that appear in it only once and display them on the screen.
// Input format:
// 10 integers separated by spaces.
// (5   -4   0  1   4  -3  -3  3  0  2)
// Output format:
// Elements that occur only once separated by a space
// (5  -4  1  4  3  2)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);

int main(void)
{
	int arr[SIZE];
	int count_unique_numbers = 0;

	inputArray(SIZE, arr);

	int temp_arr[SIZE];

	for (int i = 0, repeat_flag = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (j == i)
			{
				continue;
			}
			else if (arr[j] == arr[i])
			{
				repeat_flag = 1;
			}
		}

		if (repeat_flag == 0)
		{
			temp_arr[count_unique_numbers] = arr[i];
			count_unique_numbers++;
		}

		repeat_flag = 0; 
	}

	int* result_arr = malloc(count_unique_numbers * sizeof(int));

	for (int i = 0; i < count_unique_numbers; i++)
	{
		result_arr[i] = temp_arr[i];
	}


	printArray(count_unique_numbers, result_arr);

	free(result_arr);

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