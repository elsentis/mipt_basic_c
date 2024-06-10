// Organize the input of a natural number from the keyboard. 
// The program must determine the smallest and largest digits 
// that are part of a given natural number.
// Input format: Non-negative integer (15)
// Output format: Two digits separated by a space. 
// First the smallest digit of the number, then the largest. (1 5)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, current_digit = 0, min = 0, max = 0;

	scanf("%d", &a);

	min = a % 10;
	max = a % 10;
	a /= 10;

	for (; a != 0; a /= 10)
	{
		current_digit = a % 10;


		if (current_digit > max)
		{
			max = current_digit;
		}

		if (current_digit < min)
		{
			min = current_digit;
		}
	}


	printf("%d %d\n", min, max);

	return 0;
}