// Construct a logical function that determines whether it is true 
// that in a given number the sum of the digits is equal to the product.
// int is_happy_number(int n)
// Input format:
// One non-negative integer
// (123)
// Output format:
// Answer YES or NO
// (YES)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int is_happy_number(int n);

int main(void)
{
	int a = 0;

	scanf("%d", &a);

	is_happy_number(a) ? printf("YES\n") : printf("NO\n");

	return 0;
}

int is_happy_number(int a)
{
	int event_flag = 0, current_digit = 0, sum_of_digits = 0, product_of_digits = 1;

	for (; a != 0; a /= 10)
	{
		current_digit = a % 10;
		sum_of_digits += current_digit;
		product_of_digits *= current_digit;
	}

	if (sum_of_digits == product_of_digits)
	{
		event_flag = 1;
	}

	return event_flag;
}
