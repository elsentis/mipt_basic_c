#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, b = 0;

	//printf("enter a two numbers\n");

	scanf("%d %d", &a, &b);

	printf("%d", a - b);

	return 0;
}
