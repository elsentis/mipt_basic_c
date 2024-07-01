// Given a string consisting of small Latin letters 'a'..'z'.
// There is a period at the end of the line.
// It is necessary to replace repeated letters with <letter><number of repetitions>
// Input format
// Input string consisting of the letters 'a'-'z' not exceeding 1000 characters.
// At the end of the line there is a '.'
// (aaaaabbbc.)
// Output format
// The result consists of letters and numbers, without spaces
// (a5b3c1)

#include <stdio.h>

int main(void)
{
	char c, prev;

	prev = getchar();
	c = getchar();

	int count = 1;

	for (; c != '.'; c = getchar())
	{
		if (c == prev)
		{
			count++;
		}
		else
		{
			printf("%c%d", prev, count);
			prev = c;
			count = 1;
		}
	}

	printf("%c%d", prev, count);
	printf("\n");

	return 0;
}