// Read an array of 10 elements and allocate into another array all the numbers
// that appear more than once.
// These numbers should not be repeated in the resulting array.
// Input format:
// 10 integers separated by space
// (4 1 2 1 11 2 34 8 9 10)
// Output format:
// Space-separated integers that appear more than once in the source array.
// (1 2)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);



int main(void)
{
	int arr[SIZE];
	int count = 0;

	inputArray(SIZE, arr);

	int temp_array[SIZE];

	for (int i = 0, j = 0; i < SIZE; i++)
	{
		for (int j = i + 1, previous_repeat_flag = 0; j < SIZE; j++)
		{
			if (arr[i] == arr[j])
			{
				for (int k = 0; k < i; k++)
				{
					if (arr[k] == arr[i])
					{
						previous_repeat_flag = 1;
						break;
					}
				}

				if (previous_repeat_flag)
				{
					previous_repeat_flag = 0;
					break;
				}
				else
				{
					temp_array[count] = arr[i];
					count++;
					previous_repeat_flag = 0;
					break;
				}
			}
		}
	}

	int* result_arr = malloc(count * sizeof(int));

	for (int i = 0; i < count; i++)
	{
		result_arr[i] = temp_array[i];
	}

	printArray(count, result_arr);

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