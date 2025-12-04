#include "binary_tree.h"
#include <stdlib.h>

/**
 * build_avl_helper - Helper function to build AVL tree recursively
 * @array: Pointer to the first element of the array
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: pointer root or NULL
 */
avl_t *build_avl_helper(int *array, int start, int end, avl_t *parent)
{
	avl_t *node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = array[mid];
	node->parent = parent;
	node->left = build_avl_helper(array, start, mid - 1, node);
	node->right = build_avl_helper(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl_helper(array, 0, size - 1, NULL));
}