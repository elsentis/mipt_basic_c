// A suggestion is given in the input.txt file.
// You need to replace all the names "Cao" with "Ling" and write the result to the file output.txt.
// Input format
// A string of English letters, punctuation marks and spaces. No more than 1000 characters.
// Cao, Cao, Cao and Cao!!!
// Output format 
// A string of English letters, punctuation marks and spaces.
// Ling, Ling, Ling and Ling!!!

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


#define BUFFER_SIZE 5
#define STRING_FOR_DELETE "Cao"
#define STRING_FOR_REPLACE "Ling"

int is_letter(char ch);
int name_flag(char* arr);
void change_string(char* str, FILE* f);



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

	char buffer[BUFFER_SIZE] = { 0 };

	char ch = 0;

	for (int i = 0; (((ch = getc(in)) != '\n') && (ch != EOF)) && (i < BUFFER_SIZE);i++)
	{
		buffer[i] = ch;
	}

	char first_check[BUFFER_SIZE] = { ' ', buffer[0], buffer[1], buffer[2], buffer[3] };

	if (name_flag(first_check))
	{
		fprintf(out, STRING_FOR_REPLACE);
	}



	for (; ((ch = getc(in)) != '\n') && (ch != EOF);)
	{
		for (int i = 0; i < BUFFER_SIZE - 1; i++)
		{
			buffer[i] = buffer[i + 1];
		}
		buffer[BUFFER_SIZE - 1] = ch;

		if (name_flag(buffer))
		{
			change_string(buffer, out);
		}
		else
		{
			putc(ch, out);
		}
	}

	//printf("%d\n", name_flag(" Cao,"));

	fclose(in);
	fclose(out);

	return 0;
}

void change_string(char * str, FILE * f)
{
	fseek(f, -4, SEEK_CUR);
	fprintf(f, STRING_FOR_REPLACE);
	putc(str[4], f);
}

int name_flag(char* arr)
{
	if ((!(is_letter(arr[0])) && (!(is_letter(arr[4])))))
	{
		if (arr[1] == 'c' || arr[1] == 'C')
		{
			if (arr[2] == 'a' && arr[3] == 'o')
			{
				return 1;
			}
		}
	}

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