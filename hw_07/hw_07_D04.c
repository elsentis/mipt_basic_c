// Given a natural number N. Print all its digits one by one,
// in direct order, separating them with spaces or new lines.
// It is necessary to implement a recursive function.
// void print_num(int num)
// Create a recursive function.
// Input format:
// One non-negative integer
// (15)
// Output format:
// All digits of the number are separated by spaces in direct order.
// (1 5)



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
	if (n / 10 > 0)
	{
		rec_func(n / 10);
	}

	printf("%d ", n % 10);

	return 0;
}