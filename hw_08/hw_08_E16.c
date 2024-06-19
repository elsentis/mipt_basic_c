// Given an array of 10 elements.
// Determine which number occurs most often in the array.
// It is guaranteed that this number is exactly 1.
// Input format:
// 10 integers separated by spaces.
// (4  1  2  1  11  2  34  11  0  11)
// Output format:
// One number that appears more often than others.
// (11)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);
int mostOccurNumberArray(int , int arr[]);

int main(void)
{
	int arr[SIZE];

	inputArray(SIZE, arr);

	int result = mostOccurNumberArray(SIZE, arr);
	
	printf("%d\n", result);

	return 0;
}

int mostOccurNumberArray(int array_size, int arr[])
{
	int current_match_count = 0, max_match_count = 0;
	int previous_number_flag = 0, result = arr[0]; 

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == arr[i])
			{
				previous_number_flag = 1;
				break;
			}
		}

		if (previous_number_flag)
		{
			previous_number_flag = 0; 
			continue;
		}
		else
		{
			for (int j = i + 1; j < SIZE; j++)
			{
				if (arr[i] == arr[j])
				{
					current_match_count++;
				}
			}

			if (current_match_count > max_match_count)
			{
				max_match_count = current_match_count;
				result = arr[i];
				current_match_count = 0;
			}
		}
	}

	return result;
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