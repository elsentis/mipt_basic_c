// The file input.txt contains a string of 1000 characters.
// Show the numbers of characters matching the last character of the string.
// Write the result to the file output.txt
// Input format
// Line no more than 1000 characters
// aabbcdb
// Output format
// Integers separated by spaces
// are the numbers of the character
// that matches the last character of the line.
// 2 3

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

	fseek(in, -2L, SEEK_END);

	int in_size = ftell(in);
	char last_char = getc(in);

	rewind(in);

	char ch = 0;
	int counter_same = 0;

	for (int i = 0; ((ch = getc(in)) != '\n') && (ch != EOF) && i < in_size;i++)
	{
		if (ch == last_char)
		{
			//fprintf(out, "%d", i);
			//putc(' ', out);
			counter_same++;
		}
	}

	rewind(in);

	int i = 0; 
	int n = 0;
	for (int counter = 0; (counter < counter_same - 1) && i < in_size;i++)
	{
		if ((ch = getc(in)) == last_char)
		{
			fprintf(out, "%d", i);
			putc(' ', out);
			counter++;
		}
		i = i;
		//ch = getc(in);

	}

	if (counter_same > 0)
	{
		for ((ch = getc(in));ch != EOF && ch != '\n'; ch = getc(in), i++)
		{
			if (ch == last_char)
			{
				fprintf(out, "%d", i);
				break;
			}
		}
	}
	

	fclose(in);
	fclose(out);

	return 0;
}
