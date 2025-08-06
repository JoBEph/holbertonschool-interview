#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * find_insertion_point - finds where to insert the new node in heap
 * @root: pointer to the root of the heap
 * @new_node: the new node to insert
 * Return: void
 */
void find_insertion_point(heap_t *root, heap_t *new_node)
{
	heap_t *current;
	heap_t *queue[1024];
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear)
	{
		current = queue[front++];

		if (!current->left)
		{
			current->left = new_node;
			new_node->parent = current;
			break;
		}
		else if (!current->right)
		{
			current->right = new_node;
			new_node->parent = current;
			break;
		}
		else
		{
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}
}

/**
 * heapify - maintains max heap property
 * @node: pointer to the node
 * Return: current
 */
heap_t *heapify(heap_t *node)
{
	heap_t *current = node;
	int temp;

	while (current->parent && current->n > current->parent->n)
	{
		temp = current->n;
		current->n = current->parent->n;
		current->parent->n = temp;
		current = current->parent;
	}

	return (current);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node
 * @value: value to store in the node
 * Return: new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	find_insertion_point(*root, new_node);
	return (heapify(new_node));
}
