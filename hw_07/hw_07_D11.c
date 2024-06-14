// Convert a natural number to the binary number system.
// Given a natural number N.
// Count the number of “1s” in the binary notation of the number.
// Create a recursive function.
// Input format:
// Natural number
// (5)
// Output format:
// Integer - the number of ones in the binary notation of a number.
// (2)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int rec_func(int, int);
int unit_count = 0;


int main(void)
{
	int a = 0, result = 0;

	scanf("%d", &a);

	result = dec_to_bin_rec_func(a, 0);

	printf("%d\n", unit_count);

	return 0;
}

int dec_to_bin_rec_func(int dec, int bin)
{

	if (dec < 2)
	{
		if (dec == 1)
		{
			unit_count++;
		}

		bin = dec;
	}
	else
	{
		bin = dec % 2 + dec_to_bin_rec_func(dec / 2, bin) * 10;

		if (dec % 2 == 1)
		{
			unit_count++;
		}
	}

	return bin;
}