// ������ ����� ������ � ������� �������� ������� ����.
// Input format: ����� ����� �� 1 �� 12 - ����� ������. (4)
// Output format: ����� ���� �� ����������: winter, spring, summer, autumn (spring)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a;

	scanf("%d", &a);

	((a == 12) || (a >= 1 && a <= 2)) ? printf("winter") : (a >= 3 && a <= 5) ? printf("spring") :
		(a >= 6 && a <= 8) ? printf("summer") : (a >= 9 && a <= 11) ? printf("autumn") : a;

	return 0;
}