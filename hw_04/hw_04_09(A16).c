// ¬вести три числа и определить, верно ли, что они вводились в пор€дке возрастани€.
// Input format: “ри целых числа (4 5 17)
// Output format: ќдно слово YES или NO (YES)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	a >= b ? printf("NO") : b >= c ? printf("NO") : printf("YES");

	return 0;
}