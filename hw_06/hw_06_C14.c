// Construct a logical function that determines whether the sum of its digits
//  is an even number. Using this function solve the problem.
// Input format:
// One non-negative integer
// (136)
// Output format:
// Answer YES or NO
// (YES)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int even_digits_sum(int a);

int main(void)
{
	int a = 0, result = 0;

	scanf("%d", &a);

	result = even_digits_sum(a);

	result ? printf("YES\n") : printf("NO\n");

	return 0;
}

int even_digits_sum(int a)
{
	int event_flag = 0, sum = 0;

	for (; a != 0; a /= 10)
	{
		sum += a % 10;
	}

	if (sum % 2 == 0)
	{
		event_flag = 1;
	}

	return event_flag;
}
