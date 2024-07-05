// Cia really loves equilateral triangles.
// He makes them out of stones all the time.
// Ling gave Cia the stones and asked him to make such a triangle if possible.
// Help Cia make a triangle using all the stones or type the words NO
// if this is not possible. Example of triangles that Cia makes:
//  *
//  **
//_
// *
// **
// ***
//_
// *
// **
// ***
// ****
// The input file input.txt contains a number of* characters(stones).
// It is necessary to construct an equilateral triangle
// using all the symbols* and the space symbol,
// write the answer to the output file output.txt.
// There is strictly one space between adjacent* characters.
// If a triangle cannot be formed using all the stones,
// then you need to write the single word NO in the output.txt file.
// Input format
// The text file consists of various characters and *.
// ***
// Output format
// An equilateral triangle made up of the characters *,
// space characters and line breaks or the word NO.


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int file_to_asterisk_symbol_count(FILE* f);
int triangle_possibility(int n);
void asterisk_triangle_from_file(FILE* in, FILE* out);
void print_asterisk_triangle_to_output(int n, FILE* out);

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

	asterisk_triangle_from_file(in, out);

	fclose(in);
	fclose(out);

	return 0;
}

int file_to_asterisk_symbol_count(FILE* f)
{
	int count = 0; 

	for (char ch = 0; ((ch = getc(f)) != 'EOF') && (ch != 'ÿ');)
	{
		if (ch == '*')
		{
			count++;
		}
	}

	fseek(f, 0, SEEK_SET);

	return count;
}

int triangle_possibility(int n)
{
	if (n == 0)
	{
		return 0;
	}

	int i = 1;

	for (; n > 1;i++)
	{
		n -= i;
	}

	if (n == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void asterisk_triangle_from_file(FILE* in, FILE* out)
{
	if (triangle_possibility(file_to_asterisk_symbol_count(in)))
	{
		print_asterisk_triangle_to_output(file_to_asterisk_symbol_count(in), out);
	}
	else
	{
		fprintf(out, "NO");
	}
}

void print_asterisk_triangle_to_output(int n, FILE* out)
{
	int i = 0, string_count = 0;

	for (; n > 1; )
	{
		i++;
		n -= i;
	}

	int j = 1;

	for (; i > 0; i--, j++)
	{
		for (int space_counter = i - 1; space_counter > 0; space_counter--)
		{
			putc(' ', out);
		}

		for (int asterics_counter = j; asterics_counter > 0; asterics_counter--)
		{
			putc('*', out);

			if (i == 1 && asterics_counter == 1)
			{
				continue;
			}
			putc(' ', out);
			
		}

		if (i > 1)
		{
			putc('\n', out);
		}
	}
}