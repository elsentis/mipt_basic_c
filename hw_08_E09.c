// Read an array of 10 elements and rotate RIGHT by 1.
// Input format:
// 10 integers separated by space
// (4   -5   3  10  -4  -6  8  -10  1  0)
// Output format:
// 10 space separated integers shifted
// to the right by 1 element cyclically
// (0   4   -5   3  10  -4  -6  8  -10  1)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int Input(int n, int arr[]);
void printArray(int n, int arr[]);
void rotateArray(int, int, int*);

int main(void)
{
	int arr[SIZE];

	Input(SIZE, arr);

	rotateArray(SIZE, 1, arr);

	printArray(SIZE, arr);

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

void rotateArray(int array_size, int shift_step, int* arr)
{
	int* temp_arr = malloc(array_size * sizeof(int));

	for (int i = array_size - shift_step, j = 0; j < array_size; i++, j++)
	{
		if (i >= array_size)
		{
			i = 0;
		}

		temp_arr[j] = arr[i];
	}

	for (int i = 0; i < array_size; i++)
	{
		arr[i] = temp_arr[i];
	}

	free(temp_arr);

	return 0;
}
