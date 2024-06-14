// Given a sequence of non-zero integers ending with the number 0.
// Zero is not included in the sequence.
// Determine the largest number in this sequence.
// To solve the problem, you need to write a recursive function of the form:
// int max_find(int max)
// Input format:
// A sequence of non-zero integers. At the end of the sequence the number 0.
// (1 12 2 5 8 0)
// Output format:
// One number. Maximum consistency.
// (12)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int max_find(int max);

int main(void)
{
	int a, result = 0;
	scanf("%d", &a);

	result = max_find(a);

	printf("%d\n", result);

	return 0;
}

int max_find(int max)
{
	int n = 0;
	scanf("%d", &n);

	if (n == 0)
	{
		return max;
	}
	else if (n > max)
	{
		return max_find(n);
	}
	else
	{
		return max_find(max);
	}
}