// In the input.txt file, read a character string, no more than 10,000 characters.
// Count the number of lowercase (small) and uppercase (capital) letters in the entered string.
// Only count English letters. Write the result to the file output.txt.
// Input format 
// A string consisting of English letters, numbers, spaces and punctuation marks.
// aabbAB
// Output format 
// Two integers. The number of lowercase letters and the number of capital letters.
// 4 2

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

	int lowercase = 0, uppercase = 0;

	for (; ((ch = getc(in)) != '\n') && (ch != EOF); )
	{
		if (ch >= 'a' && ch <= 'z')
		{
			lowercase++;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			uppercase++;
		}
	}

	fprintf(out, "%d", lowercase);
	putc(' ', out);
	fprintf(out, "%d", uppercase);

	fclose(in);
	fclose(out);

	return 0;
}
