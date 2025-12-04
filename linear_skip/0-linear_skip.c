#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *express;

	if (list == NULL)
		return (NULL);
	express = list;
	while (express->express != NULL && express->express->n < value)
	{
		express = express->express;
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
	}
	if (express->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			express->express->index, express->express->n);
		current = express;
		printf("Value found between indexes [%lu] and [%lu]\n",
			current->index, express->express->index);
	}
	else
	{
		current = express;
		while (express->next != NULL)
			express = express->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			current->index, express->index);
	}
	while (current != NULL && current->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}

