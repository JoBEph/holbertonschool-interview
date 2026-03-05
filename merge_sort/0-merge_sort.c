#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * copy_merge - Copy merged elements back to original array
 * @array: The array to sort
 * @temp: Temporary array for merging
 * @left: Starting index
 * @right: Ending index
 */
void copy_merge(int *array, int *temp, size_t left, size_t right)
{
	size_t i;

	for (i = left; i <= right; i++)
		array[i] = temp[i];
}

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to sort
 * @temp: Temporary array for merging
 * @left: Starting index of left subarray
 * @mid: Ending index of left subarray
 * @right: Ending index of right subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= right)
		temp[k++] = array[j++];
	copy_merge(array, temp, left, right);
	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursively sorts
 * @array: The array to sort
 * @temp: Temporary array for merging
 * @left: Starting index
 * @right: Ending index
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left + 1) / 2 - 1;
		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid + 1, right);
		merge(array, temp, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers
 * @array: The array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}
