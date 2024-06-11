// Compose a function, a number module and give an example of its use.
// Input format:
// Integer
// (-100)
// Output format:
// Non-negative integer
// (100)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int abs(int);

int main(void)
{
	int a = 0;

	scanf("%d", &a);

	a = abs(a);

	printf("%d\n", a);

	return 0;
}

int abs(int a)
{
	if (a < 0)
	{
		a = a * (-1);
	}

	return a;
}