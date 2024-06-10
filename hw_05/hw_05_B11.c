// Enter an integer and “reverse” it so that the first digit becomes the last, etc.
// Input format: Non-negative integer (1234)
// Output format: A non-negative integer is the opposite (4321)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0,  b = 0;

	scanf("%d", &a);

	for (int i = 1; a != 0; a /= 10, i *= 10)
	{
		b = b * 10 + (a % 10);
	}


	printf("%d\n", b);

	return 0;
}