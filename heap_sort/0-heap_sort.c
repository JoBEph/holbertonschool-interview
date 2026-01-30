#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Maintains heap property by sifting down
 * @array: Array to sort
 * @size: Size of the array
 * @root: Root index
 * @heap_size: Size of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t heap_size)
{
	size_t max = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;
	int temp;

	if (left < heap_size && array[left] > array[max])
		max = left;

	if (right < heap_size && array[right] > array[max])
		max = right;

	if (max != root)
	{
		temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		sift_down(array, size, max, heap_size);
	}
}

/**
 * heap_sort - Sorts an array using heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
