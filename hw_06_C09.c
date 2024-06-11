// Create a function to calculate N!. Use it when calculating factorial
// int factorial(int n)
// Input format:
// Positive integer not greater than 20
// (5)
// Output format:
// One integer
// (120)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int factorial(int);

int main(void)
{
	int a = 0, result = 0;

	scanf("%d", &a);

	result = factorial(a);

	printf("%d\n", result);

	return 0;
}

int factorial(int n)
{
	int result = 1;

	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}

	return result;
}
