// ¬вести целое число и определить, верно ли, что в нЄм ровно 3 цифры.
// ÷елое положительное число (123)
// ќдно слов: YES или NO (YES)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, count = 0;

	scanf("%d", &a);

	for (; a != 0; a /= 10, count++);

	(count == 3) ? printf("YES") : printf("NO");

	return 0;
}