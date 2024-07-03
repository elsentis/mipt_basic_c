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
#include <string.h>

#define STRING_FOR_DELETE "Cao"
#define BUFFER_SIZE strlen(STRING_FOR_DELETE)
#define STRING_FOR_REPLACE "Ling"

int is_letter(char ch);
int name_flag(char* arr, int size);
void change_string(char* str, FILE* f);
void renew_buffer_(char ch, char* buffer, int buffer_size);
int name_flag_check(FILE* in, int size);
int renew_buffer_all(FILE* f, char* buffer, int buffer_size);



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

	int buffer_size = (int)strlen(STRING_FOR_DELETE);
	char* buffer = malloc(sizeof(char) * buffer_size);

	int renew_buffer_fail_flag = 0;

	char ch = 0;

	int i = 0;

	for ( ; (i < buffer_size) && (((ch = getc) != '\n') && (ch != EOF)); i++)
	{
		*(buffer + i) = getc(in);
	}

	if (i < buffer_size)
	{
		fprintf(out,"%s", buffer);
		return 0;
	}

	if (name_flag(buffer, buffer_size))
	{
		fprintf(out,"%s", STRING_FOR_REPLACE);
		(renew_buffer_fail_flag = (renew_buffer_all(in, buffer, buffer_size)));

		if (renew_buffer_fail_flag != buffer_size)
		{
			for (int i = 0; i < renew_buffer_fail_flag; i++)
			{
				putc(buffer[i], out);
			}

				free(buffer);

				fclose(in);
				fclose(out);

				return 0;
		}
	}

		for (int i = 0; (ch != '\n') && (ch != EOF); i++)
		{
			if (i != 0)
			{
				renew_buffer_(ch, buffer, buffer_size);
			}
			

 			if (name_flag(buffer, buffer_size) && name_flag_check(in, buffer_size))
			{
				fprintf(out, STRING_FOR_REPLACE);
				if ((renew_buffer_fail_flag = (renew_buffer_all(in, buffer, buffer_size))) != buffer_size)
				{
					for (int i = 0; i < renew_buffer_fail_flag; i++)
					{
						putc(buffer[i], out);
					}

					free(buffer);

					fclose(in);
					fclose(out);

					return 0;
				}
				fprintf(out, "%c", buffer[0]);
				ch = getc(in);
				continue;
			}
			else
			{
				ch = getc(in);
				fprintf(out, "%c", buffer[0]);
			}	

			
		}


		for (int i = 1; i < buffer_size; i++)
		{
			putc(buffer[i], out);
		}


	free(buffer);

	fclose(in);
	fclose(out);

	return 0;
}

void change_string(char* str, FILE* f)
{
	fseek(f, -4, SEEK_CUR);
	fprintf(f, STRING_FOR_REPLACE);
	putc(str[4], f);
}

int name_flag(char* str, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (str[i] != STRING_FOR_DELETE[i])
		{
			return 0;
		}
	}

	return 1;
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

void renew_buffer_(char ch, char* buffer, int buffer_size)
{
	for (int i = 0; i < buffer_size - 1; i++)
	{
		buffer[i] = buffer[i + 1];
	}
	buffer[buffer_size - 1] = ch;
}

int name_flag_check(FILE* in, int size)
{
	char ch1 = 0, ch2 = 0;
	
	int f_tell = ftell(in);

	if (f_tell < size)
	{
		ch1 = ' ';
	}
	else
	{
		fseek(in, -(size+1), SEEK_CUR);

		ch1 = getc(in);
	}

	fseek(in, +(size), SEEK_CUR);

	ch2 = getc(in);
	fseek(in, f_tell, SEEK_SET);

	if (!(is_letter(ch1)) && !(is_letter(ch2)))
	{
		return 1;
	}
	else
	{
		return 1;
	}
}

int renew_buffer_all(FILE* f, char* buffer, int buffer_size)
{
	char ch = 0;
	int i = 0;

	for (; (i < buffer_size) && ((ch = getc(f)) != '\n') && (ch != EOF); i++)
	{
		buffer[i] = ch;
	}

	if (i < buffer_size)
	{
		buffer[i] = ch;
		return i + 1;
	}
	else
	{
		return i;
	}
}
