// A suggestion is given in the input.txt file.
// You need to determine how many words end with the letter 'a'.
// Write the answer to the file output.txt.
// Input format
// A string of English letters and spaces of no more than 1000 characters. 
// Mama mila ramu
// Output format
// One integer
// 2


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
	int a_enging_word_counter = 0;

	if (((prev = getc(in)) == '\n') || (ch == EOF))
	{
		printf("empty input file\n");
		exit(EXIT_FAILURE);
	}

	for (; ((ch = getc(in)) != '\n') && (ch != EOF);)
	{
		if ((prev == 'a') && (!(is_letter(ch))))
		{
			a_enging_word_counter++;
		}

		prev = ch;
	}

	if (prev == 'a')
	{
		a_enging_word_counter++;
	}

	fprintf(out, "%d", a_enging_word_counter);

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