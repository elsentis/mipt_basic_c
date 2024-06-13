// Create a recursive function that prints all numbers from N to 1.
// Input format:
// One natural number
// (5)
// Output format:
// A sequence of integers from the entered number to 1,
//  separated by a space.
// (5 4 3 2 1)



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
	if (n == 0)
	{
		return 0;
	}
	else
	{
		printf("%d ", n);
		rec_func(n - 1);
	}

	return 0;
}