// ������ ��� ����� � ����������, ����� ��, ��� ��� ��������� � ������� �����������.
// Input format: ��� ����� ����� (4 5 17)
// Output format: ���� ����� YES ��� NO (YES)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	a >= b ? printf("NO") : b >= c ? printf("NO") : printf("YES");

	return 0;
}