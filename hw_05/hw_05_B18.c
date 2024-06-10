// Display a series of Fibonacci numbers consisting of n elements.
// Fibonacci numbers are the elements of the number sequence
//  1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ..., 
// in which each subsequent number is equal to the sum of the previous two.
// Create a program to calculate GCD using the Euclidean algorithm.
// Input format:
// One natural number
// (5)
// Output format:
// Series of Fibonacci numbers separated by space
// (1 1 2 3 5)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int n, i, f1, f2, m;
	scanf("%d", &n);
	f1 = 1;
	f2 = 1;
	if (n == 1)
		printf("1");
	else
		if (n != 0) 
		{
			printf("1 1 ");
			for (i = 2; i < n; ++i) 
			{
				m = f1 + f2;
				f1 = f2;
				f2 = m;
				printf("%d ", f2);
			}
		}

	return 0;
}