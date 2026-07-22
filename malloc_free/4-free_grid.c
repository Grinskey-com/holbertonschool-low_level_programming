#include "main.h"
#include <stdlib.h>
/**
 * free_grid - Free a 2 dimensional grid created by alloc_grid
 * @grid: The 2D grid to free
 * @height: Height of the grid
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int  i;

	/* Guard for invalid inputs*/
	if (grid == NULL || height <= 0)
		return;

	/* Free each row in the array */

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	/* Free the array of pointers */
	free(grid);

}
