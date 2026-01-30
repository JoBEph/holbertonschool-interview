#include <stdlib.h>
#include "binary_trees.h"

/**
 * get_heap_size - Counts the number of nodes in a binary tree
 * @root: Pointer to the root node
 *
 * Return: Number of nodes in the tree
 */
size_t get_heap_size(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + get_heap_size(root->left) + get_heap_size(root->right));
}

/**
 * get_last_node - Gets the last node in level-order traversal
 * @root: Pointer to the root node
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;
	heap_t *last = NULL;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		last = queue[front++];

		if (last->left)
			queue[rear++] = last->left;
		if (last->right)
			queue[rear++] = last->right;
	}

	return (last);
}

/**
 * heapify_down - Restores the max heap property after extraction
 * @root: Pointer to the root node
 *
 * Return: void
 */
void heapify_down(heap_t *root)
{
	heap_t *largest, *current;
	int temp;

	current = root;

	while (current)
	{
		largest = current;

		if (current->left && current->left->n > largest->n)
			largest = current->left;

		if (current->right && current->right->n > largest->n)
			largest = current->right;

		if (largest == current)
			break;

		/* Swap values */
		temp = current->n;
		current->n = largest->n;
		largest->n = temp;

		current = largest;
	}
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *last_node, *heap_root;
	size_t size;

	if (!root || !*root)
		return (0);

	heap_root = *root;
	extracted_value = heap_root->n;
	size = get_heap_size(heap_root);

	if (size == 1)
	{
		free(heap_root);
		*root = NULL;
		return (extracted_value);
	}

	/* Get the last node in level-order */
	last_node = get_last_node(heap_root);

	/* Replace root value with last node value */
	heap_root->n = last_node->n;

	/* Remove the last node */
	if (last_node->parent)
	{
		if (last_node->parent->right == last_node)
			last_node->parent->right = NULL;
		else
			last_node->parent->left = NULL;
	}

	free(last_node);

	/* Restore heap property */
	heapify_down(heap_root);

	return (extracted_value);
}
