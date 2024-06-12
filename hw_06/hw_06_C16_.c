// Construct a logical function that determines whether a number is prime.
//  Use the function to solve the problem.
// int is_prime(int n)
// Input format:
// One non-negative integer
// (13)
// Output format:
// Answer YES or NO
// (YES)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int is_prime(int a);

int main(void)
{
	int a = 0;

	scanf("%d", &a);

	is_prime(a) ? printf("YES\n") : printf("NO\n");

	return 0;
}

int is_prime(int a)
{
	int event_flag = 1;

	if (a == 1)
	{
		event_flag = 0;
		return event_flag;
	}

	for (int i = 2; i * i < a; i++)
	{
		if (a % i == 0 )
		{
			event_flag = 0;
			break;
		}
	}

	return event_flag;
}
