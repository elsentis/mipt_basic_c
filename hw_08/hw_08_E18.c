// In the range of natural numbers from 2 to N,
// determine how many of them are multiples
// of any of the numbers in the range from 2 to 9.
// Input format:
// One integer N greater than 2 and not exceeding 10000
// (99)
// Output format:
// First positive numbers, then negative numbers, separated by a space.
// All numbers from 2 to 9 in the format:
// 2 number of multiples of 2
// 3 number of multiples of 3
// 4 number of multiples of 4
// 5 number of multiples of 5
// 6 number of multiples of 6
// 7 number of multiples of 7
// 8 number of multiples of 8
// 9 number of multiples of 9
//(2  49
//3  33
//4  24
//5  19
//6  16
//
//7  14
//8  12
//9  11)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//#include <stdlib.h>

#define SIZE 8

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);

int main(void)
{
	int arr[SIZE] = { 0 };
	int n = 0;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0, divider = 2; j < SIZE; j++, divider++)
		{
			if (i % divider == 0)
			{
				arr[j]++;
			}
		}
	}

	for (int i = 0, divider = 2; i < SIZE; i++, divider++)
	{
		printf("%d  %d\n", divider, arr[i]);
	}

	return 0;
}


int inputArray(int n, int arr[])
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	return i;
}

void printArray(int n, int arr[])
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	//printf("\n");

	//return 0;
}