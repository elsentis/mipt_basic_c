// Write a function that converts the current digit character into a number.
//  Write a program that calculates the sum of numbers in a text.
// int digit_to_num(char c)
// Input format:
// A string consisting of English letters, spaces, and punctuation marks.
// At the end of the line there is a dot symbol.
// (1Hello 36world.)
// Output format:
// Integer - the sum of the digits in the text
// (10)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int digit_to_num(char c);
int is_digit(char c);

int main(void)
{
	char c;
	int sum = 0;

	c = getchar();

	for (; c != '.'; c = getchar())
	{
		if (is_digit(c))
		{
			sum += digit_to_num(c);
		}
	}

	printf("%d\n", sum);

	return 0;
}

int digit_to_num(char c)
{
	return (int)(c - '0');
}

int is_digit(char c)
{
	if (c >= 48 && c <= 57)
	{
		return 1;
	}

	return 0;
}

