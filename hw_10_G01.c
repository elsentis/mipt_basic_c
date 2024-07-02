// The input.txt file contains a string.
// Output it to the file output.txt three times
// separated by commas and show the number of characters in it.
// Input format 
// A string of English letters and spaces.
// No more than 100 characters.
// There may be minor line breaks at the end.
// input.txt
// aab
//Output format 
// The original line 3 times in a row, separated by a comma,
// a space and the number of characters in it.
// aab, aab, aab 3

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *in, *out;

	char ch = 0;

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

	int temp_count = 0, count = 0;

	for (int i = 0; i < 3; i++)
	{
		for (; ((ch = getc(in)) != '\n') && (ch != EOF); )
		{
			putc(ch, out);
			temp_count++; 
		}

		if (i == 2)
		{
			break;
		}

		putc(',', out);
		putc(' ', out);
		rewind(in);

		if (i == 0)
		{
			count = temp_count;
		}
	}

	putc(' ', out);
	fprintf(out, "%d", count);
	
	fclose(in);
	fclose(out);

	return 0;
}
