// Construct a recursive function, printing all numbers from 1 to N
// Input format:
// One natural number
// (5)
// Output format:
// Sequence of numbers from 1 to the entered number
// (1 2 3 4 5)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void rec_func(int);

int main(void)
{
	int a = 0;

	scanf("%d", &a);

	rec_func(a);

	printf("\n");

	return 0;
}

void rec_func(int n)
{
	if (n != 1)
	{
		rec_func(n - 1);
	}

	printf("%d ", n);

	return 0;
}