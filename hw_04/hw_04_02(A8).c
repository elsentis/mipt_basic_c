// Ввести три числа и найти наибольшее из них
// Формат входных данных: Три целых числа через пробел (4 15 9)
// Формат результата: Одно наибольшее целое число (15)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, b = 0, c = 0, max = 0;

	scanf("%d %d %d", &a, &b, &c);

	if (a > b)
		max = a;
	else
		max = b;

	if (c > max)
		max = c;

	printf("%d", max);

	return 0;
}