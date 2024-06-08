// Напечатать сумму максимума и минимума.
// Input Пять целых чисел через пробел (4    15    9    56    4)
// Output Одно целое число - сумма максимума и минимума (60)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 5 

int main(void)
{
	int min, max;

	int arr[SIZE];

	for (int i = 0; i < SIZE; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < SIZE; i++)
	{
		(i == 0) ? (min = arr[i]) : (arr[i] < min) ? (min = arr[i]) : min;
		(i == 0) ? (max = arr[i]) : (arr[i] > max) ? (max = arr[i]) : max;
	}

	printf("%d", min + max);

	return 0;
}