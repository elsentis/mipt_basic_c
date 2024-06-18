// Read an array of 10 elements
// and count the sum of the positive elements of the array.
// Input format:
// 10 integers separated by spaces.
// (4 -5 3 10 -4 -6 8 -10 1 0)
// Output format:
// One integer is the sum of the positive elements of the array
// (26)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 10

int Input(int n, int arr[]);
int s_positiveArray(int n, int arr[]);

int main(void)
{
	int arr[SIZE];

	Input(SIZE, arr);

	int result = s_positiveArray(SIZE, arr);

	printf("%d\n", result);

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

int s_positiveArray(int n, int arr[])
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= 0)
		{
			sum += arr[i];
		}
	}

	return sum;
}

