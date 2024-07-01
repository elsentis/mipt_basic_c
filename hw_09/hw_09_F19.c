// Determine the number of positive elements of a square matrix
// that exceed the arithmetic mean of all elements of the main diagonal.
// Implement the arithmetic mean function of the main diagonal.
// Input format
// 5 lines of 5 integers separated by spaces
// 1 1 1 1 1
// 2 2 2 2 2
// 3 3 3 3 3
// 4 4 4 4 4
// 5 5 5 5 5
// Output format
// One integer
// 10

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 5

int string_to_int();
int main_diagonal_arthmetic_mean(int size, int arr[SIZE][SIZE]);

int main(void)
{
	int arr[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = string_to_int();
		}
	}

	int ar_mean_main_diagonal = main_diagonal_arthmetic_mean(SIZE, arr);

	int count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] > ar_mean_main_diagonal)
			{
				count++;
			}
		}
	}

	printf("%d\n", count);

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

int main_diagonal_arthmetic_mean(int size, int arr[SIZE][SIZE])
{
	int sum = 0, count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j)
			{
				sum += arr[i][j];
				count++;
			}
		}
	}

	return sum / count;
}