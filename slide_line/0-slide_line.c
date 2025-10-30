#include "slide_line.h"

/**
 * compress_left - Move all non-zero values to the left preserving order
 * @line: array of integers
 * @size: number of elements in line
 */
static void compress_left(int *line, size_t size)
{
	size_t read = 0, write = 0;

	while (read < size)
	{
		if (line[read] != 0)
		{
			if (read != write)
			{
				line[write] = line[read];
				line[read] = 0;
			}
			write++;
		}
		read++;
	}
}

/**
 * compress_right - Move all non-zero values to the right preserving order
 * @line: array of integers
 * @size: number of elements in line
 */
static void compress_right(int *line, size_t size)
{
	size_t read = size;
	size_t write = size;

	while (read > 0)
	{
		read--;
		if (line[read] != 0)
		{
			write--;
			if (read != write)
			{
				line[write] = line[read];
				line[read] = 0;
			}
		}
	}
}

/**
 * merge_left - Merge equal adjacent tiles to the left (2048 rules)
 * @line: array of integers
 * @size: number of elements in line
 */
static void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i + 1 < size; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i++;
		}
	}
}

/**
 * merge_right - Merge equal adjacent tiles to the right (2048 rules)
 * @line: array of integers
 * @size: number of elements in line
 */
static void merge_right(int *line, size_t size)
{
	int i;

	if (size == 0)
		return;

	/* Use signed index to avoid underflow when decrementing */
	for (i = (int)size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
			/* skip the next element to prevent double merge */
			i--;
		}
	}
}

/**
 * slide_line - Slide and merge an array of integers to left or right
 * @line: pointer to array of integers
 * @size: size of the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success or 0
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		compress_left(line, size);
		merge_left(line, size);
		compress_left(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		compress_right(line, size);
		merge_right(line, size);
		compress_right(line, size);
		return (1);
	}
	return (0);
}
