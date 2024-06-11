// Create a function that determines the sum of all numbers from 1 to N
//  and give an example of its use.
// Input format:
// One positive integer N
// (100)
// Output format:
// Integer - the sum of numbers from 1 to N
// (5050)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int summ_from_1_to_n(int);

int main(void)
{
	int a = 0, result = 0;

	scanf("%d", &a);

	result = summ_from_1_to_n(a);

	printf("%d\n", result);

	return 0;
}

int summ_from_1_to_n(int n)
{
	int result = 0;

	for (int i = 0; i <= n; i++)
	{
		result += i;
	}

	return result;
}