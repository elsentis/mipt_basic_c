// Given a sequence of non-zero integers, at the end of the sequence the number 0. 
// Count the number of numbers. 
// Input format:
// Non-zero integers. There is a zero at the end of the sequence. Zero is not included in the sequence.
// (15 22 2 4 1 6 0)
// Output format:
// One integer is the number of numbers in the sequence.
// (6)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a = 0, counter = 0;

	scanf("%d", &a);

	for (; a != 0; scanf("%d", &a), counter++);

	printf("%d\n", counter);

	return 0;
}