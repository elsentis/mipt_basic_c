#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, b = 0, c = 0;

	//printf("enter a three numbers\n");

	scanf("%d %d %d", &a, &b, &c);

	printf("%.2f", (a + b + c) / 3.0);

	return 0;
}