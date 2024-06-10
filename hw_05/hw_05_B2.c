// ¬вести два целых числа a и b (a <= b) и вывести квадраты всех чисел от a до b.
// ƒва целых числа по модулю не больше 100 (4 5)
// Output  вадраты чисел от a до b. (16 25)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, b = 0, square = 0;

	scanf("%d %d", &a, &b);

	for (int i = a; i <= b; i++)
	{
		square = i * i;

		printf("%d ", square);
	}

	printf("\n");

	return 0;
}