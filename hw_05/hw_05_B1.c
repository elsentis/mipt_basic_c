// Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа.
// Число не превосходит 100.
// Input Одно целое число не превосходящее 100 (3)
// Output Для каждого из чисел от 1 до введенного числа напечатать квадрат числа и его куб.
//  1 1 1
//  2 4 8
//  3 9 27

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, square = 0, cube = 0;

	scanf("%d", &a);

	for (int i = 1; i <= a; i++)
	{
		square = i * i;
		cube = i * i * i;

		printf("%d %d %d\n", i, square, cube);
	}

	return 0;
}