// Write only one function that sorts the array in ascending order.
// You only need to implement one function, you don’t need to compose the entire program.
// Strictly according to the prototype.The function name and all arguments must be :
// void sort_array(int size, int a[]).
// There is no need to load the entire program, just this one function.
// You can simply comment out the text of the entire program, except for this function.
// Input format:
// The function takes as input the first argument - the size of the array,
// the second argument - the address of the zero element.
// (20 19 4 3 2 1 18 17 13 12 11 16 15 14 10 9 8 7 6 5)
// Output format:
// The function does not return anything. Sorts the array passed to it in ascending order.
// (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 5

/*int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);
void sort_array(int size, int a[]);

int main(void)
{
	int arr[SIZE];

	inputArray(SIZE, arr);

	sort_array(SIZE, arr);

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

void sort_array(int n, int a[])
{
	for (int i = 0, no_swap = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				no_swap = 0;
			}
		}

		if (no_swap)
		{
			break;
		}
	}
}