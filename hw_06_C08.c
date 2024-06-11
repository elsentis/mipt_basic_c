// Write a function that converts a lowercase letter to an uppercase one. And show an example of its use.
// Input format:
// A string consisting of English letters, spaces and commas. At the end of the line there is a dot symbol.
// (hello World!.)
// Output format:
// The original string in which small English letters are replaced by capital letters.
// (HELLO WORLD!)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char convert_in_up_letter(char);

int main(void)
{
	char c; 

	c = getchar(); 

	for (; c != '.'; c = getchar())
	{
		if (c >= 97 && c <= 122)
		{
			c = convert_in_up_letter(c);
		}
		
		printf("%c", c); 
	}

	printf("\n");

	return 0;
}

char convert_in_up_letter(char c)
{
	c = c - 32;

	return c;
}
