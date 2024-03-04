#include "list.h"
#include <stdlib.h>

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: A pointer to the head of the linked list
 * @str: The string to copy into the new node
 * Return: If an error occurs, return NULL. Otherwise, return a pointer to the
*/
List *add_node_end(List **list, char *str)
{
	List *node;

	if (list == NULL)
		return (NULL);
	node = malloc(sizeof(List));
	if (node == NULL)
		return (NULL);
	node->str = str;
	if (*list == NULL)
	{
		node->next = node;
		node->prev = node;
		*list = node;
	}
	else
	{
		node->next = *list;
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
	}
	return (node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular linked
 * @list: A pointer to the head of the linked list
 * @str: The string to copy into the new node
 * Return: If an error occurs, return NULL. Otherwise, return a pointer to the
*/
List *add_node_begin(List **list, char *str)
{
	List *node;

	if (list == NULL)
		return (NULL);
	node = malloc(sizeof(List));
	if (node == NULL)
		return (NULL);
	node->str = str;
	if (*list == NULL)
	{
		node->next = node;
		node->prev = node;
		*list = node;
	}
	else
	{
		node->next = *list;
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
		*list = node;
	}
	return (node);
}
