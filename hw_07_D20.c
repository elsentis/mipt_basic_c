// Write a recursive function for raising an integer n to the power p.
// int recurs_power(int n, int p)
// Using this function, solve the problem.
// Input format:
// Two integers -100 <= n <= 100 and 0 <= p <= 100
// (2 3)
// Output format:
// One integer n to the power of p
// (8)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int recurs_power(int n, int p);

int main(void)
{
	int a = 0, b = 0, result = 0;
	scanf("%d %d", &a, &b);

	result = recurs_power(a, b);

	printf("%d\n", result);

	return 0;
}

int recurs_power(int n, int p)
{
	if (p == 0)
	{
		return 1;
	}
	else if (p == 1)
	{
		return n;
	}
	else
	{
		return n * recurs_power(n, p - 1);
	}

	return 0;
}