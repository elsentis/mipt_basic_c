// Create a function that returns the sum of elements in a given segment
// [from, to] for an array.
// Function prototype int sum_between_ab(int from, int to, int size, int a[])
// Input format 
// The function accepts the ends of the segment from and to,
// the size of the array, an array of integers
// (4 6 1 2 3 4 5 6 7 8 9 10)
// Output format 
// The function returns the sum of elements in the interval [from, to]
// (15)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*int main(void)
{
	int arr[] = { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10 };

	int result = sum_between_ab(4, 6, 10, arr);

	printf("%d\n", result);

	return 0;
}*/

int sum_between_ab(int from, int to, int size, int a[])
{
	int sum = 0;

	if (to < from)
	{
		int temp = from;
		from = to;
		to = temp;
	}

	for (int i = 0; i < size; i++)
	{
		if (a[i] >= from && a[i] <= to)
		{
			sum += a[i];
		}
	}

	return sum;
}