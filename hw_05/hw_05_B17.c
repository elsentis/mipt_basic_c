// Enter a natural number and print all numbers from 10 to the entered number
//  - for which the sum of the digits is equal to the product of the digits 
// Input format:
// One natural number greater than 10
// (200)
// Output format:
// Numbers in which the sum of the digits is equal to the product of the digits
//  separated by a space in ascending order. Not exceeding the entered number.
// (22 123 132)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0;

	scanf("%d", &a);

	for (int i = 10; i <= a; i++)
	{
		int temp = i;
		int sum = 0;
		int mult = 1;

		for (; temp != 0; temp /= 10)
		{
			int current_digit = temp % 10;
			sum += current_digit;
			mult *= current_digit;
		}

		if (sum == mult)
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	return 0;
}