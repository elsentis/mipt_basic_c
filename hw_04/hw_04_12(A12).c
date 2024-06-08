// На вход подается произвольное трехзначное число, напечать сумму цифр
// Input Трехзначное целое положительное число (435)
// Output Одно целое число (12)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, sum = 0, i = 0;

	scanf("%d", &a);

	for (i = 1; a / i > 9; i *= 10)
		sum += (a / i) % 10;

	sum += a / i;

	printf("%d", sum);

	return 0;
}