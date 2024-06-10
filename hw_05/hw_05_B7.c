// Ввести целое число и определить, верно ли, что в его записи есть 
// две одинаковые цифры, НЕ обязательно стоящие рядом.
// 
// Одно целое число (1234)
// Одно слово: YES или NO (NO)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, b = 0, current_digit = 0, previous_digit = 0, event_flag = 0;

	scanf("%d", &a);


	for (; a != 0; a /= 10)
	{
		if (event_flag)
		{
			break;
		}

		current_digit = a % 10;

		for (b = a / 10; b != 0; b /= 10)
		{
			if (current_digit == b % 10)
			{
				event_flag = 1;
				break;
			}
		}
	}


	event_flag ? printf("YES\n") : printf("NO\n");

	return 0;
}