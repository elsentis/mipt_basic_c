// ¬вести два целых числа a и b (a <= b) и вывести сумму квадратов всех чисел от a до b.
// ƒва целых числа по модулю не больше 100 (4 10)
// —умма квадратов от первого введенного числа до второго (371)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, b = 0, sum = 0;

	scanf("%d %d", &a, &b);

	for (int i = a; i <= b; i++)
	{
		sum += i * i;
	}

	printf("%d\n", sum);

	return 0;
}