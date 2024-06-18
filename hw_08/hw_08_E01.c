// Enter an array of 5 elements from the keyboard,
// find the arithmetic mean of all elements of the array.
// Input format:
// 5 non-zero integers separated by spaces
// (4 15 3 10 14)
// Output format:
// Full number in the format "%.3f"
// (9.200)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 5

int Input(int n, int arr[]);
float Average(int n, int arr[]);

int main(void)
{
	int arr[SIZE];

	Input(SIZE, arr);

	printf("%.3f\n", Average(SIZE, arr));

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

float Average(int n, int arr[])
{
	float sum = 0, result = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	result = sum / n;

	return result;
}