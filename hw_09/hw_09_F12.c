// Create a function that swaps the minimum and maximum elements in an array.
// Function prototype void change_max_min(int size, int a[])
// Input format
// The function takes as input the size of the array
// and an array of numbers of type int
// (1 2 3 4 5 6 7 8 9 10)
// Ouptut format 
// The function does not return a value;
// the changed array is saved in place of the original one.
// (10 2 3 4 5 6 7 8 9 1)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int find_max_array(int size, int a[]);
void printArray(int n, int arr[]);
void change_max_min(int size, int a[]);

/*int main(void)
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	change_max_min(sizeof(arr) / sizeof(int), arr);

	printArray(sizeof(arr) / sizeof(int), arr);
}*/

void change_max_min(int size, int a[])
{
	int max = find_max_array(size, a);
	int min = find_min_array(size, a);

	int max_index, min_index;

	for (int i = 0; i < size; i++)
	{
		if (a[i] == max)
		{
			max_index = i;
		}
		else if (a[i] == min)
		{
			min_index = i;
		}
	}

	int temp = a[max_index];
	a[max_index] = a[min_index];
	a[min_index] = temp;

	return 0;
}

int find_max_array(int size, int a[])
{
	int max = a[0];

	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	return max;
}

int find_min_array(int size, int a[])
{
	int min = a[0];

	for (int i = 1; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	return min;
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