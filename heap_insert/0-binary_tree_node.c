#include "binary_trees.h"
#include <stdlib.h>

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	if (!parent)
		return (NULL);

	binary_tree_t *node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
