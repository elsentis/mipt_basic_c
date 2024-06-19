// Rearrange the digits in the number to get the maximum number.
// Input format:
// One non-negative integer
// (1229)
// Output format:
// Non-negative integer
// 9221

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//#include <stdlib.h>

#define SIZE 10

void sortDescendingRangeArray(int first_position, int last_position, int* arr);

int main(void)
{
	int n = 0;

	scanf("%d", &n);

	int count = 0;
	int arr[SIZE];

	for (int i = 0; n != 0; n /= 10, i++)
	{
		arr[i] = n % 10;
		count++;
	}

	sortDescendingRangeArray(0, count - 1, arr);

	int result = 0;

	for (int i = 0; i < count; i++)
	{
		if (i == 0)
		{
			result = arr[i];
			continue;
		}
		else
		{
			result = result * 10 + arr[i];
		}

	}

	printf("%d\n", result);
}

void sortDescendingRangeArray(int first_position, int last_position, int* arr)
{
	int temp = 0, no_swap = 0;

	for (int i = last_position; i >= 0; i--)
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


