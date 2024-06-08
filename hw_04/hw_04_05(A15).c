// ���������� ��������� ������ �� ����������� ���� �����. ��������� ���� y=k*x+b
// ������ ����� ����� ����� ������. ���������� X1 Y1 X2 Y2 (6 9 -1 3)
// ��� ����� K,B � ������� "%.2f %.2f" (0.86 3.86)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	int x1, y1, x2, y2;
	
	double k, b;

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	k = (double)(y2 - y1) / (x2 - x1); 

	b = (double)(x2 * y1 - y2 * x1) / (x2 - x1);

	printf("%.2f %.2f", k, b);

	return 0;
}