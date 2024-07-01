// It is known that the chessboard has a dimension of 8x8
// and consists of cells of 2 colors, for example, black and white (see figure).
// Each cell has a coordinate consisting of a letter and a number.
// The horizontal location of the cell is determined by the letter from A to H,
// and the vertical location is determined by the number from 1 to 8.
// Note that the cell with coordinate A1 is black.
// It is required to determine the color of the cell using a given coordinate.
// Input format
// The only line of the input file contains the coordinate
// of a cell on the chessboard :
// only two characters - a letter and a number(without spaces).
// (C3)
// Output format 
// The output file should output “WHITE” if the specified cell is white
// and “BLACK” if it is black.
// (BLACK)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char letter = getchar();
	char number = getchar();

	int flag = 0;

	if (letter % 2 == 1)
	{
		if (number % 2 == 1)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}
	else
	{
		if (number % 2 == 1)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}

	if (flag)
	{
		printf("BLACK\n");
	}
	else
	{
		printf("WHITE\n");
	}

	return 0;
}