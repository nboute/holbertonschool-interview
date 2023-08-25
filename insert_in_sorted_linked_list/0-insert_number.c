#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - Adds node to end of linked list
 * @head: Address of head of linked list
 * @n: Value for n of new node
 * Return: Pointer to new node, or NULL if error
 */
listint_t *insert_node(listint_t **head, int number);
{
	listint_t	*node, *ptr;

	if (!head)
		return (NULL);
	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = number;
	node->next = NULL;
	if (!*head)
		*head = node;
	else
	{
		ptr = *head;
		while (ptr->next && ptr->next->n < number)
			ptr = ptr->next;
		ptr->next = node;
	}
	return (node);
}
