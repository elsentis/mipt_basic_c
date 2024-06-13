// Given a natural number N. Calculate the sum of its digits.
//  You need to create a recursive function.
// int sum_digits(int n)
// Input format:
// One natural number
// (123)
// Output format:
// Integer - the sum of the digits of the entered number.
// (6)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int rec_func(int);

int main(void)
{
	int a = 0, result = 0;

	scanf("%d", &a);

	result = rec_func(a);

	printf("%d\n", result);

	return 0;
}

int rec_func(int n)
{
	int sum = 0; 

	if (n == 0)
	{
		return 0;
	}
	else
	{
		sum = n % 10 + rec_func(n / 10);
	}
	
	return sum;
}