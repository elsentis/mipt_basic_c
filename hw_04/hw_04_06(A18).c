// Ввести два числа. Если первое число больше второго, то программа печатает слово Above. 
// Если первое число меньше второго, то программа печатает слово Less. 
// А если числа равны, программа напечатает сообщение Equal.
// Input format: Два целых числа (24 24)
// Output format: Одно единственное слово: Above, Less, Equal (Equal)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void)
{
	int a, b;

	scanf("%d %d", &a, &b);

	(a > b) ? printf("Above") : (a < b) ? printf("Less") : printf("Equal");

	return 0;
}