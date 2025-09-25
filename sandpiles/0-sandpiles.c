#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 *@grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (y > 0)
				printf(" ");
			printf("%d", grid[x][y]);
		}
		printf("\n");
	}
}

/**
 *sandpiles_sum - function that computes the sum of two sandpiles
 *@grid1: array grid1
 *@grid2: array grid2
 *
 *Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	/* Addition des deux grilles */
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];

	/* Stabilisation avec affichage des étapes */
	while (!stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}

/**
 *stable - function verify stable sandpiles
 *@grid: grid sandpile
 *
 *Return: 1 if stable or 0 if not stable
 */

int stable(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - function topple
 * @grid:  grid sandpile to modify
 *
 * Return: always 0
 */

void topple(int grid[3][3])
{
	int x, y;
	int temp[3][3] = {0};

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] >= 4)
			{
				grid[x][y] -= 4;
				if (x > 0)
					temp[x - 1][y] += 1;
				if (x < 2)
					temp[x + 1][y] += 1;
				if (y > 0)
					temp[x][y - 1] += 1;
				if (y < 2)
					temp[x][y + 1] += 1;
			}
		}
	}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid[x][y] += temp[x][y];
		}
	}
}
