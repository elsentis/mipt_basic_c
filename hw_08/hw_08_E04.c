// Read an array of 10 elements
// and find the two maximum elements in it and print their sum.
// Input format:
// 10 integers separated by spaces.
// (4 -5 3 10 -4 -6 8 -10 1 0)
// Output format:
// The sum of two maximum elements.
// (18)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 10

int Input(int n, int arr[]);
int maxArray(int n, int arr[]);
int s_maxArray(int n, int arr[], int max);

int main(void)
{
	int arr[SIZE];

	Input(SIZE, arr);

	int max = maxArray(SIZE, arr);
	int s_max = s_maxArray(SIZE, arr, max);

	printf("%d\n", max + s_max);

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

int maxArray(int n, int arr[])
{
	int max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

int s_maxArray(int n, int arr[], int max)
{
	int s_max = 0;
	int i = 0, max_flag = 0;
	for (; i < n; i++)
	{
		if (arr[i] == max && max_flag == 0)
		{
			max_flag = 1;
			continue;
		}
		else
		{
			s_max = arr[i];
			break;
		}
	}

	for (; i < n; i++)
	{
		if (arr[i] == max && max_flag == 0)
		{
			max_flag = 1;
			continue;
		}
		else if (arr[i] > s_max)
		{
			s_max = arr[i];
		}
	}

	return s_max;
}