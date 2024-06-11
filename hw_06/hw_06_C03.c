// Write a function that returns the arithmetic mean of two arguments (parameters) passed to it.
// int middle(int a, int b)
// Input format:
// Two non-negative integers
// (5 7)
// Output format:
// One integer
// (6)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int middle(int, int);

int main(void)
{
	int a = 0, b = 0, result = 0;

	scanf("%d %d", &a, &b);

	result = middle(a, b);

	printf("%d\n", result);

	return 0;
}

int middle(int a, int b)
{
	int result = (a + b) / 2;

	return result;
}