// ¬вести п€ть чисел и найти наибольшее из них.
// Input format: ѕ€ть целых чисел разделенных пробелом (4    15    9    56    4)
// Output format: ќдно целое число (56)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b, c, d, e, max;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	max = a > b ? a : b;
	max = max > c ? max : c;
	max = max > d ? max : d;
	max = max > e ? max : e;

	printf("%d", max);

	return 0;
}