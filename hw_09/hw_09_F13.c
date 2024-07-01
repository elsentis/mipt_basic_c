// Create a function that returns the number of elements in a given segment
// [from, to] for an array.
// Function prototype
// int count_between(int from, int to, int size, int a[])
// For example, on the segment [4, 6] in the array 1 2 3 4 5 6 7 8 9 10
// the function will return 3 values
// Input format
// The function takes the values of the ends of the segment from and to,
// the size of the array, and an array of integers.
// (4 6 1 2 3 4 5 6 7 8 9 10)
// Output format
// The function returns an integer - the number of numbers in the interval [from, to]
// (3)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*int main(void)
{
	int arr[] = { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10 };

	int result = count_between(4, 6, 10, arr);

	printf("%d", result);

	return 0;
}*/

int count_between(int from, int to, int size, int a[])
{
	int from_index, to_index, count = 0;

	for (int i = 0; i < size; i++)
	{
		if (a[i] >= from && a[i] <= to)
		{
			count++;
		}
	}

	return count;
}