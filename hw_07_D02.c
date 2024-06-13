// Construct a recursive function that determines the sum of all numbers from 1 to N
// Input format:
// One natural number
// (5)
// Output format:
// Sum of numbers from 1 to the entered number
// (15)



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

	if (n != 0)
	{
		sum = n + rec_func(n - 1);
	}

	return sum;
}