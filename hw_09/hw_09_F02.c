// Write only one function that puts all even elements at the beginning of the array,
// and all odd ones at the end. Do not violate the order of the numbers among themselves.
// Strictly according to the prototype:.
// void sort_even_odd(int n, int a[])
// Input format:
// Function accepts integers as input
// (20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1)
// Output format:
// Sorted source array
// (20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 20

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);
void sort_even_odd(int n, int a[]);

/*int main(void)
{
	int arr[SIZE];

	inputArray(SIZE, arr);

	sort_even_odd(SIZE, arr);

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
*/

void sort_even_odd(int n, int a[])
{
	for (int i = 0, no_swap = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] % 2 != 0)
			{
				if (a[j + 1] % 2 == 0)
				{
					int temp = a[j + 1];
					a[j + 1] = a[j];
					a[j] = temp;
					no_swap = 0;
				}
				
			}
		}

		if (no_swap)
		{
			break;
		}
	}
}