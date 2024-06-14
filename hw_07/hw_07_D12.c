// Given a monotonic sequence in which each natural number k occurs exactly k times:
//  1, 2, 2, 3, 3, 3, 4, 4, 4, 4,... 
// Print the first n terms of this sequence. Only one for loop.
// Input format:
// Natural number.
// (11)
// Output format:
// Sequence of integers.
// (1 2 2 3 3 3 4 4 4 4 5)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void rec_func(int, int);

int main(void)
{
	int a = 0;

	scanf("%d", &a);

	rec_func(a, 1);

	printf("\n");

	return 0;
}

void rec_func(int n, int i)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		for (int j = i; j != 0 && n != 0; j--, n--)
		{
			printf("%d ", i);
		}

		rec_func(n, i + 1);
	}

	return 0;
}