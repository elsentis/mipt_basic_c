// In the input.txt file, the last name, first name and patronymic are in one line.
// Generate a greeting file output.txt, where the first and last name will remain
// Input format
// A string consisting of English letters and spaces of no more than 100 characters.
// Format: Last Name First Name Patronymic
// Pupkin Vasiliy Ivanovich
// Output format 
// A string consisting of English letters and spaces
//Hello, Vasiliy Pupkin!

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


#define SIZE 100

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

	char person[3][SIZE]; // 3 str with surname[0], name[1],patronymic[3]

	for (int i = 0; fscanf(in, "%s", person[i]) == 1; i++);

	fprintf(out, "Hello, %s %s!", person[1], person[0]);

	fclose(in);
	fclose(out);

	return 0;
}
