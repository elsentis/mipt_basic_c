// Read an array of 12 elements
// and calculate the arithmetic mean of the array elements.
// Input format:
// 12 integers separated by space
// (4 -5 3 10 -4 -6 8 -10 1 0 5 7)
// Output format:
// Arithmetic mean in the format "%.2f"
// (1.08)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 12

int Input(int n, int arr[]);
float Average(int n, int arr[]);

int main(void)
{
	int arr[SIZE];

	Input(SIZE, arr);

	float result = Average(SIZE, arr);

	printf("%.2f\n", result);

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

