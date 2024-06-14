// Given a sequence of space-separated integers ending with the number 0.
// Print all odd numbers from this sequence, preserving their order.
// Create a recursive function.
// Input format:
// A sequence of non-zero integers. At the end the number is 0.
// (12 13 173 28 19 0)
// Output format:
// The entered sequence, except even numbers in the same order.
// Do not display the number 0.
// (13 173 19)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void rec_func(int);

int main(void)
{
	int a;
	scanf("%d", &a);

	rec_func(a);

	return 0;
}

void rec_func(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n % 2 != 0)
	{
		n % 2 != 0;
		printf("%d ", n);
		scanf("%d", &n);
		rec_func(n);
	}
	else
	{
		scanf("%d", &n);
		rec_func(n);
	}
}