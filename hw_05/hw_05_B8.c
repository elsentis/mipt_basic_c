// ������ ����� ����� � ����������, ����� ��, ��� � �� ����� ���� ����� �9�.
// ���� ����� ����� (193)
// �����: YES ��� NO (YES)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main(void)
{
	int a = 0, event_flag = 0;

	scanf("%d", &a);


	for (; a != 0; a /= 10)
	{
		if (a % 10 == 9)
		{
			if (event_flag == 1)
			{
				event_flag++;
				break;
			}
			else
			{
				event_flag = 1;
			}
		}
	}


	(event_flag == 1) ? printf("YES\n") : printf("NO\n");

	return 0;
}