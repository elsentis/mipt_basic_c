// Given a sequence of non - zero integers, at the end of the sequence the number 0. 
// Count the number of even numbers.
// Input format:
// A sequence of non-zero integers. At the end of the sequence the number is zero.
// (15 22 2 4 1 6 0)
// Output format:
// One integer is the number of even numbers.
// (4)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, even_numbers_counter = 0;

	scanf("%d", &a);

	for (; a != 0; scanf("%d", &a))
	{
		if (a % 2 == 0)
		{
			even_numbers_counter++;
		}
	}

	printf("%d\n", even_numbers_counter);

	return 0;
}