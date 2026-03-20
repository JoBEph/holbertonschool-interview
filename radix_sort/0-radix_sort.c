#include "sort.h"
#include <stdlib.h>

/**
 * radix_counting_sort - Stable counting sort for one radix digit
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Current significant digit exponent (1, 10, 100, ...)
 * @output: Temporary output buffer
 */
static void radix_counting_sort(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};
	size_t i;
	int digit;

	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		output[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order using LSD radix
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *output;
	int max;
	int exp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		radix_counting_sort(array, size, exp, output);
		print_array(array, size);
	}

	free(output);
}
