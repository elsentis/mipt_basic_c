// The file input.txt contains a character string of no more than 1000 characters.
// It is necessary to replace all the letters "a" with the letters "b" and vice versa,
// both uppercase and lowercase. 
// Write the result to output.txt.
// Input format 
// A string of small and large English letters, punctuation marks and spaces.
// aabbccddABCD
// Output format 
// A string of small and large English letters, punctuation marks and spaces.
// bbaaccddBACD


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	FILE* in, * out;

	if ((in = fopen("input.txt", "r")) == NULL)
	{
		printf("Can't open file %s\n", "input.txt");
		exit(EXIT_FAILURE);
	}

	if ((out = fopen("output.txt", "w")) == NULL)
	{
		printf("Can't open file %s\n", "output.txt");
		exit(EXIT_FAILURE);
	}

	char ch = 0;

	for (; ((ch = getc(in)) != '\n') && (ch != EOF); )
	{
		if (ch == 'A' || ch == 'a')
		{
			putc(ch + 1, out);
		}
		else if (ch == 'B' || ch == 'b')
		{
			putc(ch - 1, out);
		}
		else
		{
			putc(ch, out);
		}
	}

	fclose(in);
	fclose(out);

	return 0;
}