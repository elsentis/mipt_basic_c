// Construct a logical function that determines whether it is true
//  that in a given number all digits are in ascending order.
//  Use this function to solve the problem.
// int grow_up(int n)
// Input format:
// One non-negative integer
// (258)
// Output format:
// Answer YES or NO
// (YES)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int ascending_order_digits(int a);

int main(void)
{
	int a = 0, result = 0;

	scanf("%d", &a);

	ascending_order_digits(a) ? printf("YES\n") : printf("NO\n");

	return 0;
}

int ascending_order_digits (int a)
{
	int event_flag = 1, previous_digit = 0, current_digit = 0;

	previous_digit = a % 10;
	a /= 10;

	for (; a != 0; a /= 10)
	{
		current_digit = a % 10; 

		if (previous_digit <= current_digit)
		{
			event_flag = 0;
			break;
		}

		previous_digit = current_digit;
	}

	return event_flag;
}
