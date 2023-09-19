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
	char *str;
	size_t len;
	size_t i;
	listint_t *ptr;

	if (!head || !*head)
		return (1);
	len = list_len(*head);
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	ptr = *head;
	i = 0;
	while (ptr)
	{
		str[i++] = ptr->n;
		ptr = ptr->next;
	}
	while (i < len)
	{
		if (str[i] != str[len - 1])
			return (0);
		i++;
		len--;
	}
	return (1);
}
