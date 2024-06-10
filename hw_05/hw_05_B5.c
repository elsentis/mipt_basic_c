// ¬вести целое число и найти сумму его цифр.
// ќдно целое число большее или равное нулю (1234)
// ќдно число - сумма цифр (10)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, sum = 0;

	scanf("%d", &a);

	if (a / 10 == 0)
	{
		(sum = a);
	}
	else
	{
		for (; a != 0; sum += (a % 10), a /= 10);
	}

	printf("%d", sum);

	return 0;
}