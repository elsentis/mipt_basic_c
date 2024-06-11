// Create a function that raises the number N to the power P. int power(n, p)
//  and give an example of its use.
// Input format:
// Two integers: N modulo not exceeding 1000 and P >= 0
// (8 3)
// Output format:
// One integer
// (512)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int power (int, int);

int main(void)
{
	int a = 0, p = 0, result;

	scanf("%d %d", &a, &p);

	result = power(a, p);

	printf("%d\n", result);

	return 0;
}

int power(int a, int p)
{
	int result = 1;

	for (int i = 0; i < p; i++)
	{
		result *= a;
	}

	return result;
}