// The input.txt file contains characters.
// It is necessary to develop a function
// that swaps pairs of adjacent characters
// without paying attention to space characters.
// If the number of characters is odd (we do not count spaces),
// then we do not change the last character. Write the result to the file output.txt.
// Input format
// A string of English letters, spaces and punctuation marks.
// No more than 1000 characters.
// Hello world!
// Output format 
// A string of English letters, spaces and punctuation marks.
// eHllw orodl!

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int getsymbol(char* ch, FILE* in, FILE* out);

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

	char ch1 = 0, ch2 = 0;

	int input_flag_ch1 = getsymbol(&ch1, in, out);
	
	int space_flag = 0;

	for (; ch1 == ' '; )
	{
		putc(ch1, out);
		input_flag_ch1 = getsymbol(&ch1, in, out);
	}

	int input_flag_ch2 = getsymbol(&ch2, in, out);

	for (; ch2 == ' '; )
	{
		space_flag++;
		input_flag_ch2 = getsymbol(&ch2, in, out);
	}

	for (; input_flag_ch1 && input_flag_ch2;)
	{
		putc(ch2, out);

		for (; space_flag; space_flag--)
		{
			putc(' ', out);
		}

		putc(ch1, out);

		input_flag_ch1 = getsymbol(&ch1, in, out);
		

		for (; ch1 == ' '; )
		{
			putc(ch1, out);
			input_flag_ch1 = getsymbol(&ch1, in, out);
		}

		input_flag_ch2 = getsymbol(&ch2, in, out);

		for (; ch2 == ' '; )
		{
			space_flag++;
			input_flag_ch2 = getsymbol(&ch2, in, out);
		}
	}

	if (input_flag_ch1)
	{
		putc(ch1, out);
	}

	fclose(in);
	fclose(out);

	return 0;
}

int getsymbol(char* ch, FILE* in, FILE * out)
{
	*ch = getc(in);

	/*for (; *ch == ' '; *ch = getc(in))
	{
		putc(*ch, out);
	}*/

	char temp = *ch;

	if ((temp == '\n') || (temp == EOF))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}