// The input.txt file contains a string of no more than 1000 characters,
// containing letters, integers and other symbols.
// It is required to place all the numbers that appear in the string
// into a separate integer array.
// For example, if the string “data 48 call 9 read13 blank0a” is given,
// then the numbers in the array are 48, 9, 13 and 0.
// Output the array in ascending order to the file output.txt.
// Input format
// A string of English letters, numbers and punctuation marks
// data 48 call 9 read13 blank0a
// Output format
// Sequence of integers sorted in ascending order
// 0 9 13 48

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int str_to_int(char first, FILE* f);
void sortAscendingRangeArray(int first_position, int last_position, int* arr);

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

	int arr[SIZE] = { 0 };
	char ch = 0;
	int number_count = 0;

	for (; ((ch = getc(in)) != '\n') && (ch != EOF); )
	{
		if (ch >= '0' && ch <= '9')
		{
			arr[number_count] = str_to_int(ch, in);
			number_count++;
		}
	}


	sortAscendingRangeArray(0, number_count, arr);

	int i = 0;

	for (; i < number_count - 1; i++)
	{
		fprintf(out, "%d ", arr[i]);
	}

	if (number_count > 0)
	{
		fprintf(out, "%d", arr[i]);
	}
	

	fclose(in);
	fclose(out);

	return 0;

}

int str_to_int(char first, FILE *f)
{
	int n = first - '0';

	for (char ch = getc(f); ch >= '0' && ch <= '9'; ch = getc(f))
	{
		n = (n * 10) + (ch - '0');
	}

	return n;
}

void sortAscendingRangeArray(int first_position, int last_position, int* arr)
{
	int temp = 0, no_swap = 0;

	for (int i = last_position - 1; i >= 0; i--)
	{
		no_swap = 1;
		for (int j = first_position; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				no_swap = 0;
			}
		}

		if (no_swap == 1)
		{
			break;
		}
	}
}
