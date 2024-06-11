// Describe the calculation function f(x) using the formula:
// f(x) = x * x for - 2 <= x < 2;
// x* x + 4x + 5 for x >= 2;
// 4 for x < -2.
// Using this function for n given numbers, calculate f(x).
// Find the largest among the calculated values.
// Input format:
// A sequence of non-zero integers, at the end of the sequence the number 0.
// (8 3 -3 10 0)
// Output format:
// One integer
// (145)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int func(int);

int main(void)
{
	int a = 0, max = 0;

	scanf("%d", &a);

	max = func(a);

	for (int temp = 0; a != 0; scanf("%d", &a))
	{
		temp = func(a);

		if (temp > max)
		{
			max = temp;
		}
	}

	printf("%d\n", max);

	return 0;
}

int func(int x)
{
	int y = 0;

	if (x >= 2)
	{
		y = x * x + 4 * x + 5;
	}
	else if (x < -2)
	{
		y = 4;
	}
	else
	{
		y = x * x;
	}

	return y;
}