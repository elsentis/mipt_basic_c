// Create a recursive function that prints all the prime factors of a number.
// Input format:
// Natural number
// (12)
// Output format:
// Sequence of all prime divisors of a number separated by space
// (223)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int rec_func(int, int);
int is_prime(int n, int delitel);

int main(void)
{
	int a = 0;

	scanf("%d", &a);

	rec_func(a, a);

	printf("\n");

	return 0;
}

int rec_func(int n, int i)
{
	

	if (i == 1)
	{
		return 0;
	}
	else if	(n % i == 0
			&& is_prime(i, 2))
	{
		rec_func(n / i, i);
		printf("%d ", i);
		return 1;
	}
	else 
	{
		rec_func(n, i - 1);
	}
}

int is_prime(int n, int delitel)
{
	if (n == 1 || n == 0)
	{
		return 0;
	}

	if (delitel == n)
	{
		return 1;
	}
	else if (n % delitel != 0 && is_prime(n, delitel + 1) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}


	return 0;
}