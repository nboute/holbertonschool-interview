#include "lists.h"

/**
 * list_len - returns the number of elements in a linked listint_t list
 * @ptr: pointer to listint_t
 * Return: number of elements in a linked listint_t list
*/
size_t list_len(listint_t *ptr)
{
	size_t len = 0;

	while (ptr)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	size_t len;
	size_t i;
	size_t j;
	listint_t *current, *end;

	if (!head || !*head)
		return (1);
	len = list_len(*head);
	current = *head;
	for (i = 0; i < len; i++)
	{
		end = current;
		for (j = 0; j < len - 1; j++)
			end = end->next;
		if (current->n != end->n)
			return (0);
		len -= 2;
		current = current->next;
	}
	return (1);
}
