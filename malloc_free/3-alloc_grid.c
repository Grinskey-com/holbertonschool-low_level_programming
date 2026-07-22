#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Returns a pointer to a 2D array of integers
 * @width: Width of the grid
 * @height: Height of the grid
 *
 * Return: Pointer to 2D array, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int h, w, i;

	/* 1. NULL check */
	if (width <= 0 || height <= 0)
		return (NULL);

	/* 2. Allocate array of row pointers */
	grid = malloc(sizeof(int *) * height);
		if (grid == NULL)
			return (NULL);

	/* 3. Allocate each row and initialise elements to 0 */
	for (h = 0; h < height; h++)
	{
		grid[h] = malloc(sizeof(int) * width);
		if (grid[h] == NULL)
		{
			/* Clean up previously allocated rows if malloc fails */
			for (i = 0; i < h; i++)
				free(grid[i]);
			free(grid);
			return (NULL);
		}

		for (w = 0; w < width; w++)
		{
			grid[h][w] = 0;
		}
	}

	return (grid);
}
