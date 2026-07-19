#include "main.h"

/**
 * print_chessboard - prints the chessboard matrix
 * @a: pointer to a 2D array of 8 characters representing the board
 *
 * Return: Nothing.
 */
void print_chessboard(char (*a)[8])
{
	int row;
	int col;

	/* Stream down through the 8 horizontal row segments */
	for (row = 0; row < 8; row++)
	{
		/* Slide across the 8 individual column blocks within the row */
		for (col = 0; col < 8; col++)
		{
			_putchar(a[row][col]);
		}

		_putchar('\n'); /* Drop down a line once the row printing is complete */
	}
}
