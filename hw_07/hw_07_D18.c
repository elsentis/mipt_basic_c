// Write a recursive function and use it to solve the problem.
// Print the digits of the entered natural number in sequence
// (from left to right) separated by a space.
// void print_digits(int n)
// Input format:
// Natural number
// (12345)
// Output format:
// Sequence of numbers from left to right separated by space
// (1 2 3 4 5)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print_digits(int n);

int main(void)
{
	int a;
	scanf("%d", &a);

	print_digits(a);

	printf("\n");

	return 0;
}

void print_digits(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		print_digits(n / 10);
		printf("%d ", n % 10);
	}

	return 0;
}