// Convert a natural number to the binary number system.
// It is necessary to implement a recursive function.
// Input format:
// Non-negative integer number in decimal number system
// (5)
// Output format:
// Integer in binary number system
// (101)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int dec_to_bin_rec_func(int, int);

int main(void)
{
	int a = 0, result = 0;

	scanf("%d", &a);

	result = dec_to_bin_rec_func(a, 0);

	printf("\n%d", result);

	return 0;
}

int dec_to_bin_rec_func(int dec, int bin)
{
	int bin_result = 0;

	if (dec < 2)
	{
		bin = dec;
	}
	else
	{
		bin = dec % 2  + dec_to_bin_rec_func(dec / 2, bin) * 10;
	}

	return bin;
}