#include "search.h"

/**
 * linear_skip - searches a sorted skip list for a value
 * @list: a sorted skip list
 * @value: value being searched for
 * Return: a pointer to the node with the value or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *next;

	if (!list)
		return (NULL);
	if (list->express)
	{
		next = list->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       next->index, next->n);
		if (next->n <= value && next->express)
			return (linear_skip(next, value));
		if (!next->express && next->n <= value)
		{
			while (next->next)
				next = next->next;
			list = list->express;
		}
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       list->index, next->index);
	while (list)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}
