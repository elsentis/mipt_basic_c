// ������ ���� ����� � �����  ���������� �� ���.
// Input format: ���� ����� ����� (4    15    9    56    4)
// Output format: ���� ����� ����� (4)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b, c, d, e, min;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	min = a < b ? a : b;
	min = min < c ? min : c;
	min = min < d ? min : d;
	min = min < e ? min : e;

	printf("%d", min);

	return 0;
}