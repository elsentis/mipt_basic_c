// Ввести целое число и определить, верно ли, что в его записи есть 
// две одинаковые цифры, стоящие рядом.
// Одно целое число (1232)
// Единственное слов: YES или NO (NO)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, current_digit = 0, previous_digit = 0, event_flag = 0;

	scanf("%d", &a);

	previous_digit = a % 10;
	a /= 10;

	for (; a != 0; a /= 10)
	{
		current_digit = a % 10;

		if (previous_digit == current_digit)
		{
			event_flag = 1;
			break;
		}

		previous_digit = current_digit;
	}

	event_flag ? printf("YES\n") : printf("NO\n");

	return 0;
}