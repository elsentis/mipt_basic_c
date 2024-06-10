// ¬вести целое число и определить, верно ли, что все его цифры четные.
// ќдно целое число (2684)
// YES или NO (YES)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, event_flag = 0;

	scanf("%d", &a);


	for (; a != 0; a /= 10)
	{
		if ((a % 10) % 2 != 0)
		{
			event_flag = 1;
			break;
		}
	}


	(event_flag == 0) ? printf("YES\n") : printf("NO\n");

	return 0;
}