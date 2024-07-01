// Given an integer square matrix 10 x 10.
// Implement an algorithm for calculating the sum of the maximum elements
// from each row.
// Print the value of this amount.
// It is assumed that there is only one such element in each line.
// Implement a function to find the maximum in a string of 10 elements
// Input format 
// 10 lines consisting of 10 integers separated by spaces.
// 61 75 55 2 35 34 77 93 28 49
// 11 34 22 78 19 14 67 67 11 0
// 72 39 23 53 92 51 60 34 71 63
// 14 27 72 6 0 79 98 56 30 15
// 31 16 3 4 95 59 25 17 11 20
// 5 93 21 61 96 30 79 38 73 40
// 89 4 66 19 36 99 67 67 92 36
// 87 54 7 35 40 43 44 46 4 69
// 98 57 20 75 9 66 85 9 39 31
// 8 90 94 25 12 30 18 10 23 15
// Output format 
// 930

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 10

int string_to_int(void);

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

	int max = 0, sum = 0;

	for (int i = 0; i < SIZE; i++)
	{
		max = arr[i][0];

		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}

		sum += max;
	}

	printf("%d\n", sum);

	return 0;
}

int string_to_int()
{

	char c;
	int n;

	for (c = getchar(); ((c < '0') || (c > '9')) && (c != '-'); c = getchar())
	{
		if (c == '\n' || c == '\t' || c == ' ')
		{
			continue;
		}
	}

	if (c == '-')
	{
		c = getchar();
		n = (c - '0') * (-1);
	}
	else
	{
		n = c - '0';
	}

	for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
	{
		n = n * 10 + (c - '0');
	}

	return n;
}