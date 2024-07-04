// Develop a function given a string of small English letters.
// Construct a palindrome of maximum length from symbols.
// When composing a palindrome, the letters in the palindrome must be arranged
// in lexicographical order. Write the response to the output.txt file.
// Input format
// A string of small English letters. No more than 1000 characters.
// kazaki
// Output format
// A string of small English letters.
// akika

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

void palindrome(FILE* in, FILE* out);
void str_to_letter_numbers(int arr[], FILE* in);
void left_part_palindrome(int* arr, FILE* out);
void center_part_palindrome(int* arr, FILE* out);
void right_part_palindrome(int* arr, FILE* out);
int is_letter(char ch);

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

	palindrome(in, out);

	fclose(in);
	fclose(out);

	return 0;
}

void palindrome(FILE* in, FILE* out)
{
	int array_letter_numbers[ALPHABET_SIZE] = { 0 };

	str_to_letter_numbers(array_letter_numbers, in);

	left_part_palindrome(array_letter_numbers, out);

	center_part_palindrome(array_letter_numbers, out);

	right_part_palindrome(array_letter_numbers, out);

}

void str_to_letter_numbers(int arr[], FILE* in)
{
	char ch = 0;

	for (ch = getc(in); is_letter(ch); ch = getc(in))
	{
		arr[ch - 'a']++;
	}
}

void left_part_palindrome(int* arr, FILE * out)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (arr[i] == 0)
		{
			int i = 1;
			continue;
		}
		else if (arr[i] % 2 == 0)
		{
			int half_letter_count = arr[i] / 2;

			for (int j = arr[i]; j > half_letter_count; j--)
			{
				putc(i + 'a', out);
			}
		}
		else
		{
			

			for (int half_letter_count = arr[i] / 2; half_letter_count > 0; half_letter_count--)
			{
				putc(i + 'a', out);
			}
		}
	}
}

void center_part_palindrome(int* arr, FILE* out)
{ 
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			if ((arr[i] % 2) != 0)
			{
				putc(i + 'a', out);
				//arr[i]--;
				break;
			}
		}
}

void right_part_palindrome(int* arr, FILE* out)
{
	for (int i = ALPHABET_SIZE - 1; i >= 0; i--)
	{
		if (arr[i] == 0)
		{
			continue;
		}
		else if (arr[i] % 2 == 0)
		{
			int half_letter_count = arr[i] / 2;

			for (int half_letter_count = arr[i] / 2; half_letter_count > 0; half_letter_count--)
			{
				putc(i + 'a', out);
			}
		}
		else
		{
			int half_letter_count = arr[i] / 2;

			for (int half_letter_count = arr[i] / 2; half_letter_count > 0; half_letter_count--)
			{
				putc(i + 'a', out);
			}
		}
	}
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