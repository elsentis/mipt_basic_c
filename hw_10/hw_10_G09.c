// The input.txt file contains a string of small and capital English letters,
// punctuation marks and spaces.
// You need to remove duplicate characters and all spaces from it.
// Write the result to the file output.txt.
// Input format
// A string of small and capital English letters, punctuation marks and spaces.
// The line size is no more than 1000 characters.
// abc cde def
// Output format 
// A string of small and large English letters.
// abcdef

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int size_arr(char* str);
int duplicate_symbol(char ch, int count, char* arr); 

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

	char arr[SIZE];

	char ch = 0;
	
	int i = 0;

	for (; ((ch = getc(in)) != '\n') && (ch != EOF);i++)
	{
		arr[i] = ch;
	}

	arr[i] = '\0';

	int size = size_arr(arr);

	for (int i = 0; i <= size; i++)
	{
		if (duplicate_symbol(arr[i], i, arr) || (arr[i] == ' '))
		{
			continue;
		}
		else
		{
			putc(arr[i], out);
		}
	}

	fclose(in);
	fclose(out);

	return 0;
}

int size_arr(char* str)
{
	int size = 0;

	for (; str[size] != '\0'; size++);

	size--;

	return size;
}

int duplicate_symbol(char ch, int count, char* arr)
{

	for (count--; count >= 0; count--)
	{
		if (arr[count] == ch)
		{
			return 1;
		}
	}

	return 0;
}