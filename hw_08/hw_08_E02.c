// Enter an array of 5 elements from the keyboard
// and find the smallest of them.
// Input format:
// 5 integers separated by space
// (4 15 3 10 14)
// Output format:
// One single integer
// (3)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 5

int Input(int n, int arr[]);
int array_minimum(int n, int arr[]);

int main(void)
{
	int arr[SIZE];

	Input(SIZE, arr);

	printf("%d\n", array_minimum(SIZE, arr));

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

int array_minimum(int n, int arr[])
{
	int min = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}


	return min;
}