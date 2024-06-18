// Read an array of 12 elements
// and perform an inversion for every third of the array.
// Input format:
// 12 integers separated by space
// (4 -5 3 10 -4 -6 8 -10 1 0 5 7)
// Output format:
// 12 integers separated by space
// (10 3 -5 4 -10 8 -6 -4 7 5 0 1)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 12

int Input(int n, int arr[]);
void printArray(int n, int arr[]);
void rangeInversion(int, int, int*);

int main(void)
{
	int arr[SIZE];

	Input(SIZE, arr);

	rangeInversion(0, SIZE / 3, &arr);

	rangeInversion(SIZE / 3, (SIZE / 3) * 2, &arr);

	rangeInversion((SIZE / 3) * 2, SIZE, &arr);

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


void rangeInversion(int first_position, int last_position, int* arr)
{
	int i = first_position, j = 0;
	int range = last_position - first_position;
	int* temp_arr = malloc(range * sizeof(int));

	for (; j < range; i++, j++)
	{
		temp_arr[j] = arr[i];
	}

	for (i = first_position, j--; j >= 0; i++, j--)
	{
		arr[i] = temp_arr[j];
	}

	free(temp_arr);

	return 0;
}

