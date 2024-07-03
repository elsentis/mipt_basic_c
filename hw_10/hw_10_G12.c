// One integer The file input.txt contains a sentence that needs to be parsed into separate words.
// Print each word on a separate line into the output.txt file.
// Input format
// One line of English letters and spaces of no more than 1000 characters.
// Mama mila ramu
// Output format
// Each word on a separate line
// Mama
// mila
// ramu


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int is_letter(char ch);

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

	char ch = 0, prev = 0;

	if (((prev = getc(in)) == '\n') || (ch == EOF))
	{
		printf("empty input file\n");
		exit(EXIT_FAILURE);
	}

	for (; ((ch = getc(in)) != '\n') && (ch != EOF);)
	{
		if (is_letter(prev))
		{
			putc(prev, out);

			if (!(is_letter(ch)))
			{
				if (ch == '\n' || ch == EOF)
				{
					break;
				}
				else
				{
					putc('\n', out);
				}
			}
		}

		prev = ch;
	}

	if (is_letter(prev))
	{
		putc(prev, out);
	}

	fclose(in);
	fclose(out);

	return 0;
}

int is_letter(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}