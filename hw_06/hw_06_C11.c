// Construct a function that determines the greatest common divisor
//  of two natural numbers and give an example of its use.
// int nod(int a, int b)
// Input format:
// Two positive integers
// (14 21)
// Output format:
// One integer is the greatest common divisor.
// (7)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int nod(int a, int b);

int main(void)
{
	int a = 0, b = 0, result = 0;

	scanf("%d %d", &a, &b);

	result = nod(a, b);

	printf("%d\n", result);

	return 0;
}

int nod(int a, int b)
{
	int max = 0, min = 0, event_flag = 0;

	while (b) {
		while (a >= b)
			a -= b;
		if (!a)
		{
			return b;
			event_flag++;
			break;
		}
		do {
			b -= a;
		} while (b >= a);
	}

	if (event_flag == 0)
	{
		return a;
	}

	return 0;
}
