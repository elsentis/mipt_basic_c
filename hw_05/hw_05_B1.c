// ������ ����������� ����� ������� �������� � ���� ���� ����� �� 1 �� ����� �����.
// ����� �� ����������� 100.
// Input ���� ����� ����� �� ������������� 100 (3)
// Output ��� ������� �� ����� �� 1 �� ���������� ����� ���������� ������� ����� � ��� ���.
//  1 1 1
//  2 4 8
//  3 9 27

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, square = 0, cube = 0;

	scanf("%d", &a);

	for (int i = 1; i <= a; i++)
	{
		square = i * i;
		cube = i * i * i;

		printf("%d %d %d\n", i, square, cube);
	}

	return 0;
}