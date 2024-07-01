// Write a function that finds the trace of a matrix in a two-dimensional array.
// Show an example of its work on a matrix of 5 by 5 elements.
// The trace of the matrix is the sum of the elements on the main diagonal.
// Input format 
// 25 integers separated by spaces.
// 1 1 1 1 1
// 2 2 2 2 2
// 3 3 3 3 3
// 4 4 4 4 4
// 5 5 5 5 5
// Output format
// One integer.
// 15

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 5 

int main(void)
{
	int arr[SIZE][SIZE];

	char c;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = string_to_int();
		}
	}

	int result = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j)
			{
				result += arr[i][j];
			}
		}
	}

	printf("%d", result);
}

int string_to_int()
{

	char c;
	int n;

	for (c = getchar(); c <= '-' && c >= '9'; c = getchar());

	if (c == '-')
	{
		c = getchar();
		n = (c - '0') * (-1);
	}
	else
	{
		n = c - '0';
	}

	for (c = getchar(); c >= '-' && c <= '9'; c = getchar())
	{
		n = n * 10 + (c - '0');
	}

	return n;
}
