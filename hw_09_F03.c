// Write a function and a program demonstrating the operation of this function.
// Print in ascending order the digits included in the decimal notation of the natural number N,
// no more than 1000 digits. A digit is the number of times a given digit appears in a number.
// Input format:
// Natural number no more than 1000 digits
// (54321)
// Output format:
// The numbers included in the number are separated by spaces in ascending order.
// From the lowest digit to the highest and the number.
// (1 1
// 2 1
// 3 1
// 4 1
// 5 1)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>

#define SIZE 10

int inputArray(int n, int arr[]);
void printArray(int n, int arr[]);
void setOfNumbers();

int main(void)
{
	
	setOfNumbers();

	return 0;
}


void setOfNumbers()
{
	int arr[SIZE] = { 0 };
	
	for (char ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
	{
		arr[ch - '0']++;
	}

	for (int i = 0; i < SIZE; i++)
	{
		if(arr[i] == 0)
		{
			continue;
		}
		else
		{
			printf("%d %d\n", i, arr[i]);
		}
	}
}


