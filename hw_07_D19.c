// Given a string of English characters, spaces and punctuation marks.
// At the end of the line there is a dot symbol.
// It is necessary to implement a recursive function
// that reads the given line from the standard input stream and returns an integer
// - the number of 'a' characters in the given line.
// int account(void)
// Use this function to solve the problem.
// Input format:
// A string consisting of English letters, spaces and punctuation marks.
// At the end of the line is the symbol '.'
// (abcd a.)
// Output format:
// One integer.
// (2)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int account(void);

int main(void)
{
	int result = 0;

	result = account();

	printf("%d\n", result);

	return 0;
}

int account(void)
{
	char ch = getchar();

	if (ch == '.')
	{
		return 0;
	}
	else if (ch == 'a')
	{
		return 1 + account();
	}
	else
	{
		return account();
	}
}