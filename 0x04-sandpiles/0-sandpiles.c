#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: grid representation of a sandpile
 * @grid2: grid representation of a sandpile
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int r, c;
	int grid3[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (r = 0; r < 3; r++)
		for (c = 0; c < 3; c++)
			grid1[r][c] = grid1[r][c] + grid2[r][c];

	while (is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		for (r = 0; r < 3; r++)
		{
			for (c = 0; c < 3; c++)
			{
				if (grid1[r][c] > 3)
				{
					grid1[r][c] = grid1[r][c] - 4;
					if (r - 1 >= 0)
						grid3[r - 1][c]++;
					if (c - 1 >= 0)
						grid3[r][c - 1]++;
					if (r + 1 <= 2)
						grid3[r + 1][c]++;
					if (c + 1 <= 2)
						grid3[r][c + 1]++;
				}
			}
		}
		for (r = 0; r < 3; r++)
			for (c = 0; c < 3; c++)
			{
				grid1[r][c] = grid1[r][c] + grid3[r][c];
				grid3[r][c] = 0;
			}
	}
}

/**
 * is_stable - tells if sandpile is stable
 * @grid: grid representation of a sandpile
 *
 * Return: 0 if stable 1 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j, f = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				f = 1;
	return (f);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
	printf("\n");
	}
}
