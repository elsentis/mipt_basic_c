// Write a logical recursive function and use it to determine
//  whether the entered natural number is an exact power of two.
// int is2pow(int n)
// Input format:
// One natural number.
// (8)
// Output format:
// YES или NO
// (YES)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int is2pow(int n);

int main(void)
{
	int a;
	scanf("%d", &a);

	is2pow(a) ? printf("YES\n") : printf("NO\n");

	return 0;
}

int is2pow(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n % 2 != 0)
	{
		return 0;
	}
	else if (n % 2 == 0)
	{
		is2pow(n / 2);
	}
	else
	{
		return 0;
	}
}