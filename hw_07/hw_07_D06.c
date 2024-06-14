// Given a string ending with a dot '.'
//  Print the line backwards.
//  Implement a recursive function that reads and prints a string in reverse.
// void reverse_string()
// Input format:
// A string of English letters and punctuation marks.
//  At the end of the line there is a dot symbol.
// (Hello world!.)
// Output format:
// The original line is backwards.
// (!dlrow olleH)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void rec_func(char);

int main(void)
{

	rec_func(getchar());
}

void rec_func(char c)
{
	if (c== '.')
	{
		return 0;
	}
	else
	{
		rec_func(getchar());
		printf("%c", c);
	}

	return 0;
}