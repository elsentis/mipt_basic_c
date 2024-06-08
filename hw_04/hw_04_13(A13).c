// На вход подается произвольное трехзначное число, напечать произведение цифр
// Input Трехзначное целое положительное число (435)
// Output Одно целое число (60)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, mult = 1, i = 0;

	scanf("%d", &a);

	for (i = 1; a / i > 9; i *= 10)
		mult *= (a / i) % 10;

	mult *= a / i;

	printf("%d", mult);

	return 0;
}