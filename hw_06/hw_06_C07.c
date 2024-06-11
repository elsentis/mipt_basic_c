// Create a function that converts the number N from the decimal number system to the P-ary number system.
// Input format:
// Two integers. N >= 0 and 2 >= P >= 9
// (25 5)
// Output format:
// One integer
// (100)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int convert_in_base(int, int);

int main(void)
{
	int a = 0, p = 0, result = 0;

	scanf("%d %d", &a, &p);

	result = convert_in_base(a, p);

	printf("%d\n", result);

	return 0;
}

int convert_in_base(int n, int p)
{
	int result = 0;

	for (int i = 1; n > 0; i *= 10)
	{
		result += (n % p) * i;
		n /= p;
	}

	return result;
}
