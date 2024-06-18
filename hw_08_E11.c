// Read an array of 10 elements and sort it by the last digit.
// Input format:
// 10 integers separated by space
// (14  25  13  30  76  58  32  11  41  97)
// Output format:
// The same array sorted by last digit
// (30  11  41  32  13  14  25  76  97  58)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);
void lastDigitSortingAscendingArray(int, int*);
int lastDigit(int a);

int main(void)
{
	int arr[SIZE];

	inputArray(SIZE, arr);

	lastDigitSortingAscendingArray(SIZE, arr);

	printArray(SIZE, arr);

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


int lastDigit(int a)
{
	int result = 0;

	if (a >= 0 && a <= 9)
	{
		result = a;
	}
	else
		result = a % 10;

	return result;
}

void lastDigitSortingAscendingArray(int array_size, int* arr)
{
	int temp = 0, no_swap = 0;

	for (int i = array_size - 1; i >= 0; i--)
	{
		no_swap = 1;
		for (int j = 0; j < i; j++)
		{
			if (lastDigit(arr[j]) > lastDigit(arr[j + 1]))
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

	return 0;
}


