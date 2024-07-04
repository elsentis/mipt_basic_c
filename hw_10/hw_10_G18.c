// In the input.txt file, you need to remove all extra spaces
// (at the beginning of a sentence and double spaces).
// To solve the problem, develop a function.
// Write the result to output.txt.
// Input format
// A string of English letters, punctuation marks and spaces.
// No more than 1000 characters.
//     Hello     world!
// Output format
// A string of English letters, punctuation marks and spaces.
// Hello world!

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_copy_without_extra_spaces(FILE* in, FILE* out);
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

	file_copy_without_extra_spaces(in, out);

	fclose(in);
	fclose(out);

	return 0;
}

void file_copy_without_extra_spaces(FILE* in, FILE* out)
{
	int string_beginning_flag = 1;

	char ch, prev;

	prev = getc(in);

	// check for spaces in beginning of string
	for (; !(is_letter(prev)) && (prev != 'EOF') && (prev != '\n'); prev = getc(in));

	for (; (prev != 'EOF') && (prev != '\n') && (prev != 'ÿ'); )
	{
		ch = getc(in);

		if (prev == ch && ch == ' ')
		{
			continue;
		}
		else
		{
			putc(prev, out);
			prev = ch;
		}
	}
}

int is_letter(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '!' && ch <= '/'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}