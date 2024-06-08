// Даны стороны треугольника a, b, c. Определить существует ли такой треугольник.
// Input format: Три целых числа. Стороны треугольника a, b, c. (3 2 4)
// Output format: YES или NO (YES)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a + b > c && a + c > b && b + c > a)
		printf("YES");
	else printf("NO");

	return 0;
}