// Compose a function that prints all the prime factors of a number. Use it to print all the prime factors of a number.
// void print_simple(int n)
// Input format:
// Positive integer
// (12)
// Output format:
// The sequence of all prime factors of a given number in ascending order.
// (2 2 3)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print_simple(int);
int prime_number(int);

int main(void)
{
	int a = 0, result = 0;

	scanf("%d", &a);

	print_simple(a);

	printf("\n");

	return 0;
}

void print_simple(int n)
{
	int result = 1;

	for (int i = 2; n >= i; i++)
	{
		if ((n % i == 0) && (prime_number(i)))
		{
			n = n / i;
			printf("%d ", i);
			i--;
		}
	}

	return 0;
}

int prime_number(int n)
{
	int prime_flag = 1;

	for (int i = 2; i < n; i++)
	{
		if (i % n == 0)
		{
			prime_flag = 0;
			break;
		}
	}

	return prime_flag;
}
