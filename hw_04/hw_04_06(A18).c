// ������ ��� �����. ���� ������ ����� ������ �������, �� ��������� �������� ����� Above. 
// ���� ������ ����� ������ �������, �� ��������� �������� ����� Less. 
// � ���� ����� �����, ��������� ���������� ��������� Equal.
// Input format: ��� ����� ����� (24 24)
// Output format: ���� ������������ �����: Above, Less, Equal (Equal)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void)
{
	int a, b;

	scanf("%d %d", &a, &b);

	(a > b) ? printf("Above") : (a < b) ? printf("Less") : printf("Equal");

	return 0;
}