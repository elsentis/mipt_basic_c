// The input.txt file contains two words of no more than 100 characters each,
// separated by one space.
// Find only those word symbols that appear only once in both words.
// Print them separated by spaces into the output.txt file in lexicographical order.
// Input format 
// Two words of small English letters separated by a space.
// The length of each word is no more than 100 characters.
// Output format 
// Small English letters separated by spaces.


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

	int arr1[26] = { 0 };
	int arr2[26] = { 0 };

	int word_number = 0;

	for (; ((ch = getc(in)) != '\n') && (ch != EOF); )
	{
		if (ch >= 'a' && ch <= 'z')
		{
			if (word_number)
			{
				arr2[ch - 'a']++;
			}
			else
			{
				arr1[ch - 'a']++;
			}
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			if (word_number)
			{
				arr2[ch - 'A']++;
			}
			else
			{
				arr1[ch - 'A']++;
			}
		}
		else if (ch == ' ')
		{
			word_number++;
		}
	}

	/*for (int i = 0; i < 26; i++)
	{
		printf("%d %d %d\n", i, arr1[i], arr2[i]);
	}*/

	int counter = 0;

	for (int i = 0; i < 26; i++)
	{
		if (arr1[i] == arr2[i] && arr1[i] == 1)
		{
			counter++;
		}
	}

	int i = 0;

	for (; i < 26 && counter > 1; i++)
	{
		if (arr1[i] == arr2[i] && arr1[i] == 1 && counter > 1)
		{
			putc(i + 'a', out);
			putc(' ', out);
			counter--;
		}
	}

	for (; i < 26; i++)
	{
		if (arr1[i] == arr2[i] && arr1[i] == 1 && counter > 0)
		{
			putc(i + 'a', out);
			counter--;
		}
	}

	fclose(in);
	fclose(out);

	return 0;
}