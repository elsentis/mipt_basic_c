// Given a non-negative integer N. Print all its digits one at a time,
// in reverse order, separating them with spaces or new lines.
// Create a recursive function.
// Input format:
// One non-negative integer
// (15)
// Output format:
// Sequence of digits of the entered number 
// in reverse order separated by a space
// (5 1)



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
	printf("%d ", n % 10);

	if (n / 10 > 0)
	{
		rec_func(n / 10);
	}

	return 0;
}