#include <stdio.h>
#include "menger.h"

/**
 * is_hole - Determine whether the cell at (x, y) is part of a hole
 * @x: column index
 * @y: row index
 *
 * Return: 1 if the cell is a hole (should be space), 0 if filled (should be '#')
 *
 * The function checks base-3 digits of x and y. If at any level both digits
 * are 1 (the center of a 3x3 block), the cell is a hole.
 */
static int is_hole(int x, int y)
{
    while (x > 0 || y > 0)
    {
        if ((x % 3) == 1 && (y % 3) == 1)
            return (1);
        x /= 3;
        y /= 3;
    }
    return (0);
}

/**
 * menger - Draws a 2D Menger sponge of given level to stdout
 * @level: level of the Menger sponge
 *
 * If level is less than 0 the function does nothing.
 */
void menger(int level)
{
    int size;
    int row, col;

    if (level < 0)
        return;

    /* compute size = 3^level */
    size = 1;
    while (level-- > 0)
        size *= 3;

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (is_hole(col, row))
                putchar(' ');
            else
                putchar('#');
        }
        putchar('\n');
    }
}
