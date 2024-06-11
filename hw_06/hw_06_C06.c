// When the creator of chess, the ancient Indian sage and mathematician Sissa bin Dahir,
//  showed his invention to the Ruler of the country,
//  he liked the game so much that he allowed the inventor the right to choose the reward himself.
//  The sage asked the Lord to pay him one grain of rice for the first square of the chessboard, 
// two for the second, four for the third, etc.,
//  doubling the number of grains on each subsequent square.
// Help the overlord count how many grains are on which cell.
// It is necessary to create a function that determines how many grains the inventor of chess
//  asked to put on the Nth square
// (on the 1st - 1 grain, on the 2nd - 2 grains, on the 3rd - 4 grains, ...)
// Input format:
// Integer number from 1 to 64
// (3)
// Output format:
// One integer. The number of grains on a given cell.
// (4)



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <inttypes.h>

uint64_t grains_in_n_square(int);

int main(void)
{
	int a = 0;
	uint64_t result = 0;

	scanf("%d", &a);

	result = grains_in_n_square(a);

	printf("%"PRIu64"\n", result);

	return 0;
}

uint64_t grains_in_n_square(int n)
{
	uint64_t result = 1;

	for (int i = 0; i < n - 1; i++)
	{
		result *= 2;
	}

	return result;
}