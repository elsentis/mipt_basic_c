// Ввести два числа и вывести их в порядке возрастания
// Формат входных данных: Два целых числа (15 9)
// Формат результата: Два целых числа (9 15)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, b = 0;

	//printf("enter a two numbers\n");

	scanf("%d %d", &a, &b);

	if (a > b)
		printf("%d %d", b, a);
	else
		printf("%d %d", a, b);

	return 0;
}