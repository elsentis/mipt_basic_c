// In the input.txt file, the character string is no more than 1000 characters.
// You need to check if it is a palindrome (the palindrome reads the same in both directions).
// Implement the logical function is_palindrom(str) and write the response to the output.txt file.
// Input format
// A string of capital English letters
// ABCDEF
// Output format
// NO

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int is_palindrome(char *str);

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

	if (fscanf(in, "%s", arr) == 0)
	{
		printf("error with fcanf\n");
		exit(EXIT_FAILURE);
	}

	if (is_palindrome(arr))
	{
		fprintf(out, "YES");
	}
	else
	{
		fprintf(out, "NO");
	}


	fclose(in);
	fclose(out);

	return 0;

}

int is_palindrome(char* str)
{
	int size = 0;

	for (; str[size] != '\0'; size++);

	size--;

	for (int i = 0; i < size; i++, size--)
	{
		if (str[i] != str[size])
		{
			return 0;
		}
	}

	return 1;
}