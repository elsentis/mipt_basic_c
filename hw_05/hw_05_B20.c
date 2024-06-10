// Check the number for simplicity.
// Input format:
// One natural number
// (10)
// Output format:
// If the number is prime print YES, otherwise NO
// (NO)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, event_flag = 0;

	scanf("%d", &a);

	if (a == 1)
	{
		event_flag = 1;
	}

	for (int i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			event_flag = 1;
			break;
		}
	}

	event_flag ? printf("NO\n") : printf("YES\n");
	
	return 0;
}