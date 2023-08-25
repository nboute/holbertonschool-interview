#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - Adds node to end of linked list
 * @head: Address of head of linked list
 * @n: Value for n of new node
 * Return: Pointer to new node, or NULL if error
 */
listint_t	*add_nodeint_end(listint_t **head, const int n)
{
	listint_t	*node, *ptr;

	if (!head)
		return (NULL);
	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	if (!*head)
		*head = node;
	else
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = node;
	}
	return (node);
}
