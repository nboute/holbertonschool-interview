#include <stdio.h>

/**
 * print_grid - prints a 3x3 grid
 * @grid: 3x3 grid
 *
 * Return: void
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)

		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - checks if a sandpile is stable
 * @grid: sandpile
 *
 * Return: 1 if stable, 0 otherwise
 */
unsigned char is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)

		{
			if (grid[i][j] > 3)
				return (0);
		}
	return (1);
}

/**
 * copy_grid - copies a grid
 * @dest: destination grid
 * @src: source grid
 * Return: void
 */
void copy_grid(int dest[3][3], int src[3][3])
{
	int i, j;

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)

		{
			dest[i][j] = src[i][j];
		}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int gridtmp[3][3];


	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)

		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			gridtmp[i][j] = grid1[i][j];
		}

	while (!is_stable(grid1))
	{
		print_grid(grid1);
		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				if (grid1[i][j] > 3)
				{
					gridtmp[i][j] -= 4;
					if (i > 0)
						gridtmp[i - 1][j] += 1;
					if (i < 2)
						gridtmp[i + 1][j] += 1;
					if (j > 0)
						gridtmp[i][j - 1] += 1;
					if (j < 2)
						gridtmp[i][j + 1] += 1;
				}
			}
		}
		copy_grid(grid1, gridtmp);
	}
}
