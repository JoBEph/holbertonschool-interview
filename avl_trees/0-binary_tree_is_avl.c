#include "binary_trees.h"
#include <limits.h>

/**
 * avl_height - Validate AVL constraints and return subtree height
 * @tree: Current node
 * @min: Lower bound (exclusive) for BST validation
 * @max: Upper bound (exclusive) for BST validation
 *
 * Return: Height if valid, -1 if invalid AVL/BST subtree
 */
static int avl_height(const binary_tree_t *tree, long min, long max)
{
	int left_h;
	int right_h;
	int diff;

	if (tree == NULL)
		return (0);

	if ((long)tree->n <= min || (long)tree->n >= max)
		return (-1);

	left_h = avl_height(tree->left, min, tree->n);
	if (left_h == -1)
		return (-1);

	right_h = avl_height(tree->right, tree->n, max);
	if (right_h == -1)
		return (-1);

	diff = left_h - right_h;
	if (diff < -1 || diff > 1)
		return (-1);

	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node
 *
 * Return: 1 if tree is valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (avl_height(tree, LONG_MIN, LONG_MAX) != -1);
}
