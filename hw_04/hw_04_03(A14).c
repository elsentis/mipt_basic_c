// Дано трехзначное число, напечатать макисмальную цифру
// Input Целое положительное трехзначное число (435)
// Output Одна цифра (5)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, max = 0, i = 0;

	scanf("%d", &a);

	for (i = 1; a / i > 9; i *= 10)
			(i == 1) ? (max = (a / i) % 10) : ((a / i) % 10 > max) ? (max = (a / i) % 10) : max;

	(a / i > max) ? max = a / i : max;

	printf("%d", max);

	return 0;
}