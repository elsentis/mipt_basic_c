// Read the number N from the input.txt file.
// Generate a string of N characters.
// N is an even number not exceeding 26.
// Even positions must contain even numbers in ascending order, except 0;
// odd positions must contain capital letters in the order
// in which they appear in the English alphabet.
// Write the result to the file output.txt
// Input format 
// Even N <= 26
// 10
// Output format
// A string of English letters and numbers
// A2B4C6D8E2

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *in, *out;

	if ((in = fopen("input.txt", "r")) == NULL)
	{
		printf("Can't open file %s\n", "input.txt");
		exit(EXIT_FAILURE);
	}

	int n = 0;
	fscanf(in, "%d", &n);

	fclose(in);

	if ((out = fopen("output.txt", "w")) == NULL)
	{
		printf("Can't open file %s\n", "output.txt");
		exit(EXIT_FAILURE);
	}

	char letter = 'A';
	char number = '2';

	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
		{
			putc(number, out);

			if (number >= '8')
			{
				number = '2';
			}
			else
			{
				number += 2;
			}
		}
		else
		{
			putc(letter++, out);
		}
	}

	fclose(out);

	return 0;
}