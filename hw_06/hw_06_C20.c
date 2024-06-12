// Check the string consisting of brackets "(" and ")" for correctness.
// Input format:
// The input is a string consisting of the characters '(', ')' and ending with the character '.'.
// The line size is no more than 1000 characters.
// ((()()).)
// Output format:
// You must print the word YES if the parentheses are placed correctly and NO otherwise.
// (YES)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int parenthes_correct();

int main(void)
{
	parenthes_correct() ? printf("YES\n") : printf("NO\n");

	return 0;
}

int parenthes_correct()
{
	int counter_opening_parenthesis = 0, counter_closing_parenthesis = 0;
	char c;

	c = getchar();

	for (; c != '.'; c = getchar())
	{
		if (c == '(')
		{
			counter_opening_parenthesis++;
		}
		else if (c == ')')
		{
			counter_closing_parenthesis++;
		}
		else
		{
			continue;
		}

		if (counter_opening_parenthesis < counter_closing_parenthesis)
		{
			break;
		}
	}

	if (counter_opening_parenthesis != counter_closing_parenthesis)
	{
		return 0;
	}

	return 1;
}