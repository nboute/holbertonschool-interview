#include "lists.h"
#include <stdlib.h>

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
	int tab[4096];
	size_t len;
	size_t i;
	listint_t *ptr;

	if (!head || !*head)
		return (1);
	len = list_len(*head);
	ptr = *head;
	i = 0;
	while (ptr)
	{
		tab[i++] = ptr->n;
		ptr = ptr->next;
	}
	for (i = 0; i < len; i++)
	{
		len--;
		if (tab[i] != tab[len])
			return (0);
	}
	return (1);
}
