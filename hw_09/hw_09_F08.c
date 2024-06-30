// The sequence contains integers from M to N
// (M less than N, M greater than or equal to 1)
// in random order, but one of the numbers is missing 
// (the rest appear exactly once). N does not exceed 1000. 
// The sequence ends with the number 0. Determine the missing number.
// Input format:
// A sequence of integers from M to N. M, N does not exceed 1000.
// (Input
// (2   3   1   4   7   6   9   8  10   0)
// Output format:
// One integer
// (5)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000


int inputArray(int n, int arr[]);
int find_max_array(int size, int a[]);
int find_min_array(int size, int a[]);
int containArray(int size, int a[], int n);

int main(void)
{
	int temp_arr[SIZE];

	int ar_size = inputArray(SIZE, temp_arr);

	int* arr = malloc(sizeof(int) * ar_size);

	for (int i = 0; i < ar_size; i++)
	{
		arr[i] = temp_arr[i];
	}

	int max = find_max_array(ar_size, arr);
	int min = find_min_array(ar_size, arr);

	int missing_number = 0;

	for (int i = min; i < max; i++)
	{
		if (!(containArray(ar_size, arr, i)))
		{
			missing_number = i;
			break;
		}
	}

	printf("%d\n", missing_number);

	return 0;
}

int containArray(int size, int a[], int n)
{
	int event_flag = 0;

	for (int i = 0; i < size; i++)
	{
		if (a[i] == n)
		{
			event_flag = 1;
			break;
		}
	}

	return event_flag;
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

int inputArray(int n, int arr[])
{
	int i = 0;

	for (char c = getchar(), prev = ' '; c != '\n'; c = getchar())
	{
		if (c >= '0' && c <= '9')
		{
			if (prev >= '0' && prev <= '9')
			{
				arr[i] = arr[i] * 10 + (c - '0');
			}
			else
			{
				arr[i] = c - '0';
			}
		}
		else if (prev >= '0' && prev <= '9')
		{
			i++;
		}

		prev = c;
		
	}

	return i;
}
