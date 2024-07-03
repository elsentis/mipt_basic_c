// The input.txt file contains the full address of the file (possibly without an extension).
// You need to change its extension to ".html" and write the result to the output.txt file.
// Input format
// A string consisting of characters: a-z, A-Z, 0-9, /
// /DOC.TXT/qqq
// Output format 
// The original string with the extension changed.
// /DOC.TXT/qqq.html

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int path_character(char ch);

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

	 int extension_flag = 0;
	 int point_counter = 0;

	for (int i = 0; ((ch = getc(in)) != '\n') && (ch != EOF); i++)
	{
		if (ch == '.')
		{
			extension_flag = 1;
			point_counter++;
		}

		if (extension_flag && (ch == '/'))
		{
			extension_flag = 0;
		}
	}

	rewind(in);

	for (int i = 0, temp_point_counter = 0; ((ch = getc(in)) != '\n') && (ch != EOF); i++)
	{
		if (path_character(ch))
		{
			putc(ch, out);
		}
		else if (ch == '.')
		{
			temp_point_counter++;
			if (extension_flag && (temp_point_counter >= point_counter))
			{
				break;
			}
			else
			{
				putc(ch, out);
			}
		}
	}

	fprintf(out, ".html");

	fclose(in);
	fclose(out);

	return 0;
}

int path_character(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
		|| (ch >= '0' && ch <= '9') || ch == '/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}