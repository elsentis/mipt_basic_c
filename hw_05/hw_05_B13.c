// Count the number of even and odd digits of a number.
// Input format: Non-negative integer (1234)
// Output format: Two numbers separated by a space. 
// The number of even and odd digits in a number. (2 2)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, even_digit_count = 0, odd_digit_count = 0;

	scanf("%d", &a);

	for (; a != 0; a /= 10)
	{
		((a % 10) % 2 == 0) ? even_digit_count++ : odd_digit_count++;
	}


	printf("%d %d\n", even_digit_count, odd_digit_count);

	return 0;
}