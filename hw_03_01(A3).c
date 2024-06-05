#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, b = 0, c = 0;

	//printf("enter a three numbers\n");

	scanf("%d %d %d", &a, &b, &c);

	printf("%d+%d+%d=%d", a, b, c, a + b + c);

	return 0; 
}