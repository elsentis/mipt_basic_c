// The file input.txt is given a string of words separated by spaces.
// Find the longest word and output it to the output.txt file.
// The case where there may be several longest words should not be processed.
// Input format
// A string of English letters and spaces.
// No more than 1000 characters.
// Hello beautiful world
// Output format
// One word from English letters.
// beautiful


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
	int max = 0, letter_in_word_counter = 0, max_length_word_index = 0;

	for (int i = 0; ((ch = getc(in)) != '\n') && (ch != EOF); i++)
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			letter_in_word_counter++;
			i++;

			for (ch = getc(in); ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ch = getc(in))
			{
				letter_in_word_counter++;
				i++;
			}
		}

		if (letter_in_word_counter > max)
		{
			max = letter_in_word_counter;
			max_length_word_index = i - max;
		}

		letter_in_word_counter = 0;

		if ((ch == '\n') && (ch == EOF))
		{
			break;
		}
	}

	fseek(in, max_length_word_index, SEEK_SET); 

	for (int i = 0; i <= max; i++)
	{
		putc(getc(in), out);
	}

	fclose(in);
	fclose(out);

	return 0;
}


