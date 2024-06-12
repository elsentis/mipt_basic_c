// Construct a logical function that determines
//  that the current character is a digit.
//  Write a program to count the number of digits in a text.
// int is_digit(char c)
// Input format:
// Text from English letters and punctuation marks.
//  At the end of the text there is a dot symbol.
// (1Hello 36world.)
// Output format:
// One integer - the number of digits in the text.
// (3)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int is_digit(char c);

int main(void)
{
	char c;
	int digit_count = 0;

	c = getchar();

	for (; c != '.'; c = getchar())
	{
		if (is_digit(c))
		{
			digit_count++;
		}
	}

	printf("%d\n", digit_count);

	return 0;
}

int is_digit(char c)
{
	if (c >= 48 && c <= 57)
	{
		return 1;
	}

	return 0;
}
