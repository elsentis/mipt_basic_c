// An integer array of 10 elements is given.
// It is necessary to determine the number of even and odd numbers.
// If the number of even numbers is greater than the number of odd numbers,
// replace each odd number with the product of the odd digits in its decimal notation.
// If the number of odd numbers is greater than or equal to the number of even numbers,
// replace each even number with the product of the even digits in its decimal notation.
// Input format
// 10 integers separated by space
// 48 31 20 61 97 12 18 100 200 123
// Output format 
// 10 integers separated by space
// 48 3 20 1 63 12 18 100 200 3


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 10

int string_to_int(void);
int odd_count(int size, int ar[]);
int even_count(int size, int ar[]);
void even_numbers_change(int size, int arr[]);
void odd_numbers_change(int size, int arr[]);
void printArray(int n, int arr[]);

int main(void)
{
	int arr[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = string_to_int();
	}

	//printf("%d %d", odd_count(SIZE, arr), even_count(SIZE, arr));

	if (odd_count(SIZE, arr) >= even_count(SIZE, arr))
	{
		even_numbers_change(SIZE, arr);
	}
	else
	{
		odd_numbers_change(SIZE, arr);
	}

	printArray(SIZE, arr);
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

int odd_count(int size, int ar[])
{
	int count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (ar[i] % 2 == 1)
		{
			count++;
		}
	}

	return count;
}

int even_count(int size, int ar[])
{
	int count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (ar[i] % 2 == 0)
		{
			count++;
		}
	 }

	return count;
}

void even_numbers_change(int size, int arr[])
{
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] % 2 == 0)
		{
			int n = arr[i];

			int even_digit_production = 1;

			int digit = 0;

			for (; n != 0; n /= 10)
			{
				digit = n % 10;

				if (digit % 2 == 0)
				{
					even_digit_production *= digit;
				}
			}

			arr[i] = even_digit_production;
		}
	}

	return 0;
}

void odd_numbers_change(int size, int arr[])
{
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] % 2 == 1)
		{
			int n = arr[i];

			int odd_digit_production = 1;

			int digit = 0;

			for (; n != 0; n /= 10)
			{
				digit = n % 10;

				if (digit % 2 == 1)
				{
					odd_digit_production *= digit;
				}
			}

			arr[i] = odd_digit_production;
		}
	}

	return 0;
}

void printArray(int n, int arr[])
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}