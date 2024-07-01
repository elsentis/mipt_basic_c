// Create a function that determines in an array consisting
// of positive and negative numbers how many elements exceed
// the maximum element in absolute value.
// Function prototype int count_bigger_abs(int n, int a[]);
// For example, on the segment[4, 6] in the array 1 2 3 4 5 6 7 8 9 10
// the function will return 3 values
// Input format
// The function gets the size of the array and an array of integers
// (1 -20 3 4 -50 6 7 8 9 10)
// Output format
// The function returns an integer equal to the number of elements
// exceeding the maximum element in absolute value.
// (2)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int count_bigger_abs(int n, int a[]);
int find_max_array(int size, int a[]);

/*int main(void)
{
	int arr[] = { 1, -20, 3, 4, -50, 6, 7, 8, 9, 10 };

	int result = count_bigger_abs(sizeof(arr) / sizeof(int), arr);

	printf("%d", result);

	return 0;
}*/

int count_bigger_abs(int n, int a[])
{
	int max = find_max_array(n, a);

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			if (a[i] * (-1) > max)
			{
				count++;
			}
		}
		else if (a[i] > max)
		{
			count++;
		}
	}

	return count;
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