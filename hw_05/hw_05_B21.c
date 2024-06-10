// Given a text consisting of English letters and numbers, ending with the symbol “.” 
// Convert all capital English letters to lowercase.
// Input format:
// Text of small, large English letters and spaces. At the end of the text there is a dot symbol.
// (HELLO wORld.)
// Output format:
// Text from small English letters.
// (hello world)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char a;

	scanf("%c", &a);

	for (; a != '.'; scanf("%c", &a))
	{
		if (a >= 65 && a <= 90)
		{
			a = a + 32;
		}

		printf("%c", a);
	}

	printf("\n");

	return 0;
}