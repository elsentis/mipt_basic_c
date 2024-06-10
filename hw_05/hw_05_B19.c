// Enter a natural number and determine 
// whether it is true that the sum of its digits is 10.
// Input format:
// One natural number
// (1234)
// Output format:
// YES или NO
// (1233)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, sum = 0;

	scanf("%d", &a);

	for (; a != 0; a /= 10)
	{
		sum += a % 10;
	}

	(sum == 10) ? printf("YES\n") : printf("NO\n");

	return 0;
}