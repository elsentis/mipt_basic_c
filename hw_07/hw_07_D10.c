// Given a natural number n >= 1. Check whether it is prime.
//  The program should print YES if the number is prime or NO otherwise.
//  You need to create a recursive function and use it.
// int is_prime(int n, int delitel)
// Input format:
// Natural number
// (11)
// Output format:
// YES или NO
// (YES)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int is_prime(int n, int delitel);

int main(void)
{
	int a = 0;

	scanf("%d", &a);

	is_prime(a, 2) ? printf("YES\n") : printf("NO\n");

	return 0;
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