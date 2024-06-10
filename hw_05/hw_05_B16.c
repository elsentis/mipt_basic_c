// Create a program to calculate GCD using the Euclidean algorithm. 
// Two natural numbers are given. Find the greatest common divisor.
// Input format:
// Two non-negative integers
// (14 21)
// Output format:
// One integer greatest common divisor
// (7)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 0, b = 0, max = 0, min = 0, event_flag = 0;

	scanf("%d %d", &a, &b);

	while (b) {
		while (a >= b)
			a -= b;
		if (!a)
		{
			printf("%d\n", b);
			event_flag++;
			break;
		}
		do {
			b -= a;
		} while (b >= a);
	}

	if (event_flag == 0)
	{
		printf("%d\n", a);
	}

	return 0;
}