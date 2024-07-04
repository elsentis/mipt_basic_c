// Read a sentence from the file input.txt and determine whether
// it is possible to obtain one word - a palindrome
// - from the English letters of the sentence written in the file.
// Print the answer to the standard output stream.
// You need to implement a logical function and apply it.
// is_palindrome(string)
// Input format 
// A string of small English letters and spaces.
// No more than 1000 characters.
// kak za
// Output format
// YES или NO
// YES

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26
#define SIZE 1000

int file_to_string(FILE* in, char str[]);
void is_palindrome(char str[]);
int is_letter(char ch);


int main(void)
{
	FILE* in, * out;

	if ((in = fopen("input.txt", "r")) == NULL)
	{
		printf("Can't open file %s\n", "input.txt");
		exit(EXIT_FAILURE);
	}

	char str[SIZE];

	file_to_string(in, str);

	is_palindrome(str);

	fclose(in);


	return 0;
}

void is_palindrome(char str[])
{
	int letter_count[ALPHABET_SIZE] = { 0 };

	for (int i = 0; (str[i] != '\0') && (i < SIZE); i++)
	{
		if (!(is_letter(str[i])))
		{
			continue;
		}

		letter_count[str[i] - 'a']++;
	}

	int odd_counter = 0;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (letter_count[i] % 2 != 0)
		{
			odd_counter++;
		}
	}

	if (odd_counter <= 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	



	return 0;
}

int file_to_string(FILE* in, char str[])
{
	char ch = 0;
	int i = 0;

	for (; (i < SIZE) && ((ch = getc(in)) != 'EOF') && (ch != '\n'); i++)
	{
		str[i] = ch;
	}

	return i;
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
