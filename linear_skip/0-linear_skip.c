#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located, or NULL on failure
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp;

	if (!list)
		return (NULL);
	if (list->express && list->express->n < value)
	{
		printf("Value checked at index [%llu] = [%d]\n",
		       list->express->index, list->express->n);
		return (linear_skip(list->express, value));
	}
	if (list->express)
	{
		printf("Value checked at index [%llu] = [%d]\n",
			list->express->index, list->express->n);
		printf("Value found between indexes [%llu] and [%llu]\n",
		       list->index, list->express->index);
	}
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		printf("Value found between indexes [%llu] and [%llu]\n",
		       list->index, tmp->index);
	}
	while (list)
	{
		printf("Value checked at index [%llu] = [%d]\n",
		       list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}
