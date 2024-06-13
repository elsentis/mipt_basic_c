// Construct a recursive function. Print all numbers from A to B inclusive,
//  in ascending order if A < B, or in descending order otherwise.
// Input format:
// Two integers separated by a space.
// (5 2)
// Output format:
// Последовательность целых чисел.
// (5 4 3 2)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void rec_func(int, int);

int main(void)
{
	int a = 0, b = 0;

	scanf("%d %d", &a, &b);

	rec_func(a, b);

	printf("\n");

	return 0;
}

void rec_func(int a, int b)
{
	if (a == b)
	{
		printf("%d ", a);
		return 0;
	}
	else if (a > b)
	{
		printf("%d ", a);
		rec_func(a - 1, b);
		
	}
	else
	{
		printf("%d ", a);
		rec_func(a + 1, b);
	}


	return 0;
}