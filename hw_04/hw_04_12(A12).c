// �� ���� �������� ������������ ����������� �����, �������� ����� ����
// Input ����������� ����� ������������� ����� (435)
// Output ���� ����� ����� (12)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, sum = 0, i = 0;

	scanf("%d", &a);

	for (i = 1; a / i > 9; i *= 10)
		sum += (a / i) % 10;

	sum += a / i;

	printf("%d", sum);

	return 0;
}