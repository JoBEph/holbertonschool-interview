#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *current;
	heap_t *queue[1024];
	int front = 0, rear = 0;
	int temp;
	
	if (!root)
		return (NULL);
	
	/* Create new node */
	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);
	
	/* Handle empty heap */
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}
	
	/* Find insertion point using level-order traversal */
	queue[rear++] = *root;
	
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
	
	/* Heapify up to maintain max heap property */
	current = new_node;
	while (current->parent && current->n > current->parent->n)
	{
		/* Swap values with parent */
		temp = current->n;
		current->n = current->parent->n;
		current->parent->n = temp;
		current = current->parent;
	}
	
	return (new_node);
}